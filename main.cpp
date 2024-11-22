/*
 * Copyright (C) Tedlyn Joseph, 2024
 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

#include "main.h"

int main(void) {

    FILE* fp;
    int returnV; // return value 
    int readCount; // amount of inputs successfully read
    char Word[35]; // instruction string
    const char* filename = "on_duty_staff.txt";
    std::string tempInstructionFormat;
    std::string capitalizedInstruction;
    pINFORMATION workdayInfo;
    pWORKER newWorker;
    Scheduler scheduler;
    
    fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: cannot open file \"%s\"\n", filename);
        fprintf(stdout, "The program will now exit.");
        exit(1);
    }

    /* --  Initialize shift information -- */
    workdayInfo = new INFORMATION();
    
    /* --  Begin reading Worker shift details from input file -- */
    char lastName[40], firstName[40], startTime[10], finishTime[10];
    (void)fscanf(fp, "%*[^'\n']\n"); // Consumes the title line and skips over it
    (void)fscanf(fp, "%*[^'\n']\n"); // Consumes the borderline and skips over it
    
    while ((readCount = fscanf(fp, "%39[^,], %39[^ ] %9[^ ] / %9[^\n]\n", lastName, firstName, startTime, finishTime)) != EOF) {

        // Check if fscanf successfully read 4 inputs
        if (readCount != 4) {
            fprintf(stderr, "Error: The \"%s\" file is not properly formatted.\n", filename);
            fprintf(stdout, "\t\t<last name>, <first name> <start time> / <finish time>\n\n");
            // Handle the error (e.g., skip the line or exit the loop)
            fclose(fp);
            fprintf(stdout, "The program will now exit.");
            exit(1);
        }

        newWorker = new WORKER();
        if (newWorker == nullptr) {
            fprintf(stderr, "Error: could not allocate memory for new Worker.\n");
            fclose(fp);
            fprintf(stdout, "The program will now exit.");
            exit(1);
        }

        // Initialize newWorker fields
        newWorker->lastName = strdup(lastName);
        newWorker->firstName = strdup(firstName);
        newWorker->startTime = strdup(startTime);
        newWorker->finishTime = strdup(finishTime);

        // Add new Worker to Worker array
        workdayInfo->workers.push_back(newWorker);
        
    }

    fclose(fp);

    /*-- Parse Worker Info --*/ 
    scheduler.parseWorkerInfo(workdayInfo);
    
    /* ~ Valid Instruction List (3 in total) ~ ListWorkingTeam (L) | CreateSchedule (C) | InspectFloor (I) | Exit */

    while (1) {   

        returnV = nextInstruction(Word);

        if (returnV == 0) {
            fprintf(stderr, "Error: *Invalid instruction* \n\n");
            continue;
        }

        tempInstructionFormat = Word;
        capitalizedInstruction = capitalizeString(tempInstructionFormat);

        if (capitalizedInstruction == "EXIT") {
            return 0;
        }

        if (capitalizedInstruction == "LISTWORKINGTEAM" || capitalizedInstruction == "L") {
            pWORKER currentWorker;
            int numberOfMembers = workdayInfo->workers.size();
            printf("* Working Team * \n");
            for (int i = 0; i < numberOfMembers; i++) {
                currentWorker = workdayInfo->workers[i];
                printf("Employee %2d: %12s %12s | %7s - %7s\n", 
                    i+1, currentWorker->firstName, currentWorker->lastName, 
                    currentWorker->startTime, currentWorker->finishTime);
            }
            printf("\n");
            continue;
        }

        if (capitalizedInstruction == "CREATESCHEDULE" || capitalizedInstruction == "C") {
            
            //TODO
 
            
            continue;
        }
        
        if (capitalizedInstruction == "INSPECTFLOOR" || capitalizedInstruction == "I") {

            //TODO
 

            continue;
        }
 
    }
    
    return 0; // Program ends here; success exit code for main.
}