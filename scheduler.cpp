/*
 * Copyright (C) Tedlyn Joseph, 2024
 */

#include <unordered_map>
#include <cctype>
#include <iostream>
#include <cstring>
#include <cmath>

#include "scheduler.h"

std::pair<int, int> Scheduler::convertTime(pWORKER worker) {
    std::string startStr = worker->startTime;
    std::string finishStr = worker->finishTime;

    // Helper lambda function to convert individual time string to 24-hour format
    auto convertSingleTime = [](const std::string& timeStr) -> int {
        size_t pos = timeStr.find(':');
        int hour = std::stoi(timeStr.substr(0, pos));
        int minute = 0;
        if (pos != std::string::npos) { // Checks if colon was found.
            minute = std::stoi(timeStr.substr(pos + 1, 2));
        }

        if (timeStr.find("pm") != std::string::npos && hour != 12) {
            hour += 12;
        }
        if (timeStr.find("am") != std::string::npos && hour == 12) {
            hour = 0;
        }

        return hour * 100 + minute;
    };

    int startTime = convertSingleTime(startStr);
    int finishTime = convertSingleTime(finishStr);

    return std::make_pair(startTime, finishTime);
}

void Scheduler::parseWorkerInfo(pINFORMATION workdayInfo) {
    
    std::pair<int, int> shiftTimes;        
    for (int i = 0; i < workdayInfo->workers.size(); i++) {
        pEMPLOYEE newEmployee = new EMPLOYEE();
        if (newEmployee == nullptr) {
            fprintf(stderr, "Error: could not allocate memory for new employee.\n");
            exit(1);
        }
        newEmployee->firstName = workdayInfo->workers[i]->firstName;
        newEmployee->lastName = workdayInfo->workers[i]->lastName;
        shiftTimes = convertTime(workdayInfo->workers[i]);
        newEmployee->shiftStart = shiftTimes.first;
        newEmployee->shiftFinish = shiftTimes.second;

        // Convert start and finish times to minutes from midnight
        int startInMinutes = (newEmployee->shiftStart / 100) * 60 + (newEmployee->shiftStart % 100);
        int finishInMinutes = (newEmployee->shiftFinish / 100) * 60 + (newEmployee->shiftFinish % 100);

        // Calculate duration in minutes, accounting for crossing midnight
        int durationInMinutes;
        if (finishInMinutes < startInMinutes) {
            // Crossed midnight
            durationInMinutes = (1440 - startInMinutes) + finishInMinutes;
        } else {
            durationInMinutes = finishInMinutes - startInMinutes;
        }

        newEmployee->shiftDuration = durationInMinutes;
        newEmployee->entitledBreak = (newEmployee->shiftDuration / 120) * 15;

        workdayInfo->activeStaff[newEmployee->firstName + " " + newEmployee->lastName] = newEmployee;
    }
    
}

void Scheduler::populateEmployeeMatrix(pINFORMATION workdayInfo) {
    for (auto worker : workdayInfo->workers) {
        
        
    }
    
    // for (int i = 0; i < 24; i++) { // iterate through 24hours of the day

    // }
}