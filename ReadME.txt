Last Modified: 7/7/24 

// ------------- -------------  ReadME  ------------- ------------- //

This document is a technical guide for the concierge staff assignment program; 
covering usage instructions, configuration settings, and troubleshooting steps.

on_duty_staff.txt file structure:
On Duty Staff Members
-------------------------------
<last name>, <first name> <start time> / <finish time>
/* Example:
    On Duty Staff Members
    -------------------------------
   
*/
         
The 'on_duty_staff.txt' file is NOT case-sensitive but otherwise has to strictly 
follow the specified format. Any deviation will make program the immediately exit. 
Error codes will be displayed to indicate if any issue arises.

** The high level program logic is as follows, **

a) Fully staff the main desk then b) staff the South entrance. Afterwards, 
c) fully staff the info desk and d) then North Wow. If there are more staff 
members present, utilize them as greeters for the lobby.

~ Valid Instructions List (3 in total) 
    Stop
    GenerateSchedule
    DisplayWorkingTeam // (For debugging)

// ---------------------------  END  --------------------------- //