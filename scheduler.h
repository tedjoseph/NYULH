#ifndef _scheduler_h
#define _scheduler_h 1

#include <utility>
#include "data_structures.h"

class Scheduler {
  
  public:
    std::pair<int,int> convertTime(pWORKER worker);
    void parseWorkerInfo(pINFORMATION workdayInfo);
    void populateEmployeeMatrix(pINFORMATION workdayInfo);
    Scheduler(){}; // Default constructor

  private:

};

#endif 