#include "util.h"

std::string capitalizeString(std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}

int nextInstruction(char* Word) {
    
    int readCount;
    fprintf(stdout, "Instructions: ListWorkingTeam (L) | CreateSchedule (C) | InspectFloor (I) | Exit \n\n");
    fprintf(stdout, "Enter an instruction (case-insensitive): ");
    readCount = fscanf(stdin, "%s", Word);
    fprintf(stdout, "\n");
    if (readCount != 1) {
        fprintf(stderr, "Error: A valid instruction consists of only one argument, %d arguments were inputted.\n" , readCount);
        return 0;
    }
    
    std::string instruction(Word); // converts C-String "Word" to std::string "instruction"
    std::string capitalizedInstruction = capitalizeString(instruction); // standardizes the input to upper case

    /* ~ Valid Words List (3 in total) ~ ListWorkingTeam (L) | CreateSchedule (C) | DisplayFloor (D) Exit */
    if (capitalizedInstruction == "EXIT") return 1;
    
    if (capitalizedInstruction == "LISTWORKINGTEAM") return 1;
    if (capitalizedInstruction == "L") return 1; // Keyboard shortcut for LISTWORKINGTEAM
    
    if (capitalizedInstruction == "CREATESCHEDULE") return 1;
    if (capitalizedInstruction == "C") return 1; // Keyboard shortcut for CREATESCHEDULE
    
    if (capitalizedInstruction == "INSPECTFLOOR") return 1;
    if (capitalizedInstruction == "I") return 1; // Keyboard shortcut for INSPECTFLOOR
    return 0;
}