#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <fstream>
#include <algorithm>

#include "Engineer.h"
#include "Student.h"
#include "CityComponent.h"

using namespace std;

// ================= REPORT =================

void generateReport(
    const vector<int>& sensorReadings,
    int pendingEvents,
    int emergencyAlerts)
{
    ofstream report("report.txt");

    if (!report)
    {
        cout << "Error creating report file.\n";
        return;
    }

    report << "=================================\n";
    report << "      NEOVERSE CITY REPORT\n";
    report << "=================================\n\n";

    report << "Power Grid Status : ONLINE\n";
    report << "Transport Status  : ONLINE\n";
    report << "Health Status     : ONLINE\n";
    report << "Security Status   : ONLINE\n\n";

    report << "Pending Events    : "
           << pendingEvents << "\n";

    report << "Emergency Alerts  : "
           << emergencyAlerts << "\n";

    report << "Highest Sensor Reading : "
           << sensorReadings.back() << "\n";

    report << "Lowest Sensor Reading  : "
           << sensorReadings.front() << "\n";

    report << "\nOverall Status : STABLE\n";

    report.close();

    cout << "\nReport successfully saved to report.txt\n";
}

// ================= STUDENT PORTAL =================

void studentPortal()
{
    cout << "\n=================================\n";
    cout << "         STUDENT PORTAL\n";
    cout << "=================================\n";

    cout << "\nCITY STATUS\n";
    cout << "Power Grid     : ONLINE\n";
    cout << "Transport      : ONLINE\n";
    cout << "Health System  : ONLINE\n";
    cout << "Security       : ONLINE\n";

    cout << "\nCurrent Report\n";
    cout << "City Status : STABLE\n";
    cout << "Traffic     : NORMAL\n";
    cout << "Power Usage : 95.5 MW\n\n";
}

// ================= STAFF PORTAL =================

void staffPortal()
{
    queue<string> eventQueue;
    stack<string> emergencyStack;

    // Event Queue
    eventQueue.push("Traffic Congestion");
    eventQueue.push("Network Failure");
    eventQueue.push("Water Supply Alert");

    // Emergency Stack
    emergencyStack.push("Security Breach");
    emergencyStack.push("Power Failure");

    // Sensor Readings
    vector<int> sensorReadings =
    {
        95,
        80,
        72,
        99,
        88
    };

    sort(sensorReadings.begin(),
         sensorReadings.end());

    PowerSystem power(101, 95.5);
    TransportSystem transport(202, 4);

    int choice;

    do
    {
        cout << "\n=================================\n";
        cout << "         STAFF PORTAL\n";
        cout << "=================================\n";

        cout << "1. Manage Power System\n";
        cout << "2. Manage Transport System\n";
        cout << "3. Process Event Queue\n";
        cout << "4. Emergency Override\n";
        cout << "5. View Sensor Readings\n";
        cout << "6. Generate Report\n";
        cout << "7. Logout\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:

                power.activate();
                power.supplyPower();
                power.processEvent();

                break;

            case 2:

                transport.activate();
                transport.manageTraffic();
                transport.processEvent();

                break;

            case 3:

                if(!eventQueue.empty())
                {
                    cout << "\nProcessing Event:\n";
                    cout << eventQueue.front() << endl;
                    eventQueue.pop();
                }
                else
                {
                    cout << "\nNo events remaining.\n";
                }

                break;

            case 4:

                if(!emergencyStack.empty())
                {
                    cout << "\nEmergency Override Activated:\n";
                    cout << emergencyStack.top() << endl;
                    emergencyStack.pop();
                }
                else
                {
                    cout << "\nNo emergency alerts.\n";
                }

                break;

            case 5:

                cout << "\nSensor Readings:\n";

                for(int reading : sensorReadings)
                {
                    cout << reading << " ";
                }

                cout << endl;

                cout << "\nLowest Reading : "
                     << sensorReadings.front()
                     << endl;

                cout << "Highest Reading: "
                     << sensorReadings.back()
                     << endl;

                break;

            case 6:

                cout << "\n========== SYSTEM REPORT ==========\n";
                cout << "Power Grid      : ONLINE\n";
                cout << "Transport       : ONLINE\n";
                cout << "Pending Events  : "
                     << eventQueue.size() << endl;

                cout << "Emergency Alerts: "
                     << emergencyStack.size() << endl;

                cout << "Lowest Reading  : "
                     << sensorReadings.front() << endl;

                cout << "Highest Reading : "
                     << sensorReadings.back() << endl;

                cout << "System Status   : STABLE\n";
                cout << "===================================\n";

                generateReport(
                    sensorReadings,
                    eventQueue.size(),
                    emergencyStack.size());

                break;

            case 7:

                cout << "\nLogging out...\n";
                break;

            default:

                cout << "\nInvalid Choice.\n";
        }

    }
    while(choice != 7);
}

// ================= MAIN =================

int main()
{
    vector<Engineer> engineers;
    vector<Student> students;

    AuthSystem::loadEngineers(
        engineers,
        "engineers.dat"
    );

    StudentSystem::loadStudents(
        students,
        "students.dat"
    );

    int option;

    do
    {
        cout << "\n=====================================\n";
        cout << "   NEOVERSE AI CITY SURVIVAL SYSTEM\n";
        cout << "=====================================\n";

        cout << "1. Student Login\n";
        cout << "2. Staff Login\n";
        cout << "3. Exit\n";

        cout << "\nSelect Option: ";
        cin >> option;

        switch(option)
        {
            case 1:

                if(StudentSystem::login(students))
                {
                    studentPortal();
                }

                break;

            case 2:

                if(AuthSystem::login(engineers))
                {
                    staffPortal();
                }

                break;

            case 3:

                cout << "\nSystem Closed.\n";
                break;

            default:

                cout << "\nInvalid Option.\n";
        }

    }
    while(option != 3);

    return 0;
}