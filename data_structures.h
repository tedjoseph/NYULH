#ifndef _data_structures_h
#define _data_structures_h 1

#include <vector>
#include <string.h>
#include <unordered_map>

#include "util.h"

/* 
    Worker: Raw employee data extracted from a text file.
    Employee: Parsed employee data for program use.
*/

typedef struct TAG_WORKER {
    char* firstName;
    char* lastName;
    char* startTime;
    char* finishTime;
}WORKER;
typedef WORKER* pWORKER;

typedef struct TAG_EMPLOYEE {
    std::string firstName;
    std::string lastName;
    int shiftStart; // Based on 24hr clock
    int shiftFinish;
    int shiftDuration; // Unit: Minutes
    int entitledBreak; // Floor(15mins per 2hrs worked)
    std::vector<std::string> locations; // List of locations worked
}EMPLOYEE;
typedef EMPLOYEE* pEMPLOYEE;

typedef struct TAG_LOCATION {
    std::string name; // Post name
    int count; // Number of spots filled
}LOCATION;

typedef struct TAG_POSTS {
    LOCATION main;
    LOCATION info;
    LOCATION south;
    LOCATION wow;
    LOCATION greeter;
}POSTS;
typedef POSTS* pPOSTS;

typedef struct TAG_INFORMATION {
    
    // Raw worker information from text file.
    std::vector<pWORKER> workers;

    // Parsed worker information.
    std::unordered_map<std::string, pEMPLOYEE> activeStaff;

    // Employee pool/time matrix.
    std::unordered_map<int, std::vector<std::string>> employeePool;

    int currentTime = 0;
    POSTS stations;
}INFORMATION;
typedef INFORMATION* pINFORMATION;

#endif