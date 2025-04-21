This document is a technical guide for the hospital concierge staff assignment program, covering usage instructions, configuration settings, and troubleshooting steps.

Program Overview & Goal
The hospital operates 24/7, requiring around-the-clock staffing for concierge services. This program is designed to:

Randomize daily seating arrangements to keep employees engaged and familiar with different areas.

Prevent employees from remaining in one location for an entire shift, if avoidable.

Promote balanced movement while avoiding frivolous reassignments.

Aim for two distinct locations per worker. If multiple assignments are needed, three locations are preferred over just one.

Reduce managerial workload by automating scheduling, allowing quick adjustments if someone calls out before the workday starts.

on_duty_staff.txt File Structure:
On Duty Staff Members
-------------------------------
<last name>, <first name> <start time> / <finish time>

The on_duty_staff.txt file is not case-sensitive but must strictly follow the specified format. Any deviation will cause the program to immediately exit. If an issue arises, an error code will be displayed.

Program Logic & Assignment Rules
Location Capacities:
Main Desk: 2 workers (MANDATORY – Must always be staffed)

Info Desk: 2 workers (Optional)

South Entrance: 1 worker (Optional, but closed during extreme shortages)

North WOW: 1 worker (Optional)

Lobby Greeters: 1 worker (Optional, assigned if staff is available)

Assignment Order (Priority Staffing)
The program assigns staff in the following order:

Fully staff the Main Desk (2 employees). (This position must always be staffed.)

Assign an employee to the South Entrance (1 employee).

Fully staff the Info Desk (2 employees).

Assign an employee to North WOW (1 employee).

If additional staff members are available, assign them as Lobby Greeters (1 employee).

Extreme Staffing Shortage Protocol
If severe staffing shortages occur, the South Entrance post will be temporarily closed until adequate staffing resumes.

Under no circumstances should the Main Desk be left unstaffed.

The Info Desk, North WOW, and Lobby Greeter positions are optional and will only be staffed if enough employees are available.

Break Time Rules:
Breaks are awarded continuously throughout the shift.

Workers receive 15 minutes of break time for every 2 hours worked.

Example:

2 hours worked → 15-minute break

6 hours worked → 45-minute break

7 hours worked → 45-minute break

For shifts longer than 12 hours, break time is split across both shifts:

Example:

7 AM - 11 PM shift (16 hours total) → Two 1-hour breaks

12-hour shift → One 1-hour break and one 30-minute break

Valid Instructions (3 in Total):
Stop – Terminates the program.

GenerateSchedule – Generates the staff schedule based on availability and location capacities.

DisplayWorkingTeam – Displays the current working team (for debugging purposes).
