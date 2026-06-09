/*Attendance Management System
Features:
- Mark Attendance
- Display Attendance
- Search Student
- Absence Report
- Attendance Percentage
- Exit */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Attendance {
public:
    int studentID;
    string studentName;
    string date;
    string status;

    Attendance(int id, string name, string d, string s) {
        studentID = id;
        studentName = name;
        date = d;
        status = s;
    }
};
vector<Attendance> records;
void saveToFile() {
    ofstream file("attendance.txt");
    for (Attendance a : records) {
        file << a.studentID << ","
             << a.studentName << ","
             << a.date << ","
             << a.status << endl;
    }

    file.close();
}
void markAttendance() {
    int id;
    string name, date, status;

    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter Student Name: ";
    (cin, name);
    cout << "Enter Date (DD/MM/YYYY): ";
    (cin, date);
    cout << "Enter Status (Present/Absent): ";
    (cin, status);
    records.push_back(
        Attendance(id, name, date, status)
    );
    saveToFile();
    cout << "Attendance Recorded Successfully!\n";
}
void displayAttendance() {
    if (records.empty()) {
        cout << "No Attendance Records Found!\n";
        return;
    }

    cout << "===== ATTENDANCE REPORT =====\n";

    for (Attendance a : records) {
        cout << "ID: " << a.studentID
             << "Name: " << a.studentName
             << "Date: " << a.date
             << "Status: " << a.status
             << "---------------------\n";
    }
}
void searchStudent() {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;
    bool found = false;
    for (Attendance a : records) {
        if (a.studentID == id) {
            found = true;
            cout << "Name: " << a.studentName
                 << "Date: " << a.date
                 << "Status: " << a.status; 
        }
    }
    if (!found)
        cout << "Student Not Found!\n";
}
void absenceReport() {
    cout << "===== ABSENT STUDENTS =====\n";

    bool found = false;
    for (Attendance a : records) {
        if (a.status == "Absent" ||
            a.status == "absent") {
            found = true;
            cout << a.studentID
                 << " - "
                 << a.studentName
                 << " (" << a.date << ")"
                 << endl;
        }
    }
    if (!found)
        cout << "No Absent Students Found!\n";
}
void attendancePercentage() {
    int id;
    int present = 0;
    int total = 0;

    cout << "\nEnter Student ID: ";
    cin >> id;

    for (Attendance a : records) {
        if (a.studentID == id) {
            total++;
            if (a.status == "Present" ||
                a.status == "present")
                present++;
        }
    }
    if (total == 0) {
        cout << "Student Not Found!\n";
        return;
    }
    double percentage =
        (double)present / total * 100;

    cout << "Attendance Percentage = "
         << percentage << "%"
         << endl;

    if (percentage < 75)
        cout << "Warning: Low Attendance!\n";
}

int main() {
    int choice;

    do {
        cout << "==============================";
        cout << " ATTENDANCE MANAGEMENT SYSTEM";
        cout << "==============================";
        cout << "1. Mark Attendance";
        cout << "2. Display Attendance";
        cout << "3. Search Student";
        cout << "4. Absence Report";
        cout << "5. Attendance Percentage";
        cout << "6. Exit";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
        case 1:
            markAttendance();
            break;
        case 2:
            displayAttendance();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            absenceReport();
            break;
        case 5:
            attendancePercentage();
            break;
        case 6:
            cout << "Thank You!\n";
            break;
        default:
            cout << "Invalid Choice!\n";
        }
    } while(choice != 6);
    return 0;
} 
**//Sample OUTPUT//**
==============================
 ATTENDANCE MANAGEMENT SYSTEM
==============================
1. Mark Attendance
2. Display Attendance
3. Search Student
4. Absence Report
5. Attendance Percentage
6. Exit
Enter Choice: 1

Enter Student ID: 123
Enter Student Name: sara
Enter Date (DD/MM/YYYY): 09/10/2018
Enter Status (Present/Absent): present

Attendance Recorded Successfully!

==============================
 ATTENDANCE MANAGEMENT SYSTEM
==============================
1. Mark Attendance
2. Display Attendance
3. Search Student
4. Absence Report
5. Attendance Percentage
6. Exit
Enter Choice: 1

Enter Student ID: 321
Enter Student Name: sosi
Enter Date (DD/MM/YYYY): 09/10/2018
Enter Status (Present/Absent): absent

Attendance Recorded Successfully!

==============================
 ATTENDANCE MANAGEMENT SYSTEM
==============================
1. Mark Attendance
2. Display Attendance
3. Search Student
4. Absence Report
5. Attendance Percentage
6. Exit
Enter Choice: 2

===== ATTENDANCE REPORT =====

ID: 123
Name: sara
Date: 09/10/2018
Status: present
---------------------

ID: 321
Name: sosi
Date: 09/10/2018
Status: absent
---------------------

==============================
 ATTENDANCE MANAGEMENT SYSTEM
==============================
1. Mark Attendance
2. Display Attendance
3. Search Student
4. Absence Report
5. Attendance Percentage
6. Exit
Enter Choice: 3

Enter Student ID: 123

Name: sara
Date: 09/10/2018
Status: present
------------------

==============================
 ATTENDANCE MANAGEMENT SYSTEM
==============================
1. Mark Attendance
2. Display Attendance
3. Search Student
4. Absence Report
5. Attendance Percentage
6. Exit
Enter Choice: 4

===== ABSENT STUDENTS =====
321 - sosi (09/10/2018)

==============================
 ATTENDANCE MANAGEMENT SYSTEM
==============================
1. Mark Attendance
2. Display Attendance
3. Search Student
4. Absence Report
5. Attendance Percentage
6. Exit
Enter Choice: 5

Enter Student ID: 321

Attendance Percentage = 0%
Warning: Low Attendance!

==============================
 ATTENDANCE MANAGEMENT SYSTEM
==============================
1. Mark Attendance
2. Display Attendance
3. Search Student
4. Absence Report
5. Attendance Percentage
6. Exit
Enter Choice: 5

Enter Student ID: 123

Attendance Percentage = 100%

==============================
 ATTENDANCE MANAGEMENT SYSTEM
1. Mark Attendance
2. Display Attendance
3. Search Student
4. Absence Report
5. Attendance Percentage
6. Exit
Enter Choice: 6

Thank You!
PS C:\Users\Sara> 
               
