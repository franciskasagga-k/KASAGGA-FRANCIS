#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Function to get current date formatted with ordinal suffix (e.g., 27th August 2026)
string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int day = ltm->tm_mday;
    int month = ltm->tm_mon;
    int year = 1900 + ltm->tm_year;

    // Ordinal suffix
    string suffix = "th";
    if (day % 10 == 1 && day != 11) suffix = "st";
    else if (day % 10 == 2 && day != 12) suffix = "nd";
    else if (day % 10 == 3 && day != 13) suffix = "rd";

    string months[] = {"January", "February", "March", "April", "May", "June", 
                       "July", "August", "September", "October", "November", "December"};

    return to_string(day) + suffix + " " + months[month] + " " + to_string(year);
}

int main() {
    string firstName, lastName, studyProgram, academicYear;

    // Prompt user for input
    cout << "Enter First Name: ";
    getline(cin, firstName);

    cout << "Enter Last Name: ";
    getline(cin, lastName);

    cout << "Enter Study Program: ";
    getline(cin, studyProgram);

    cout << "Enter Academic Year (e.g., 2027/2028): ";
    getline(cin, academicYear);

    cout << "\n--------------------------------------------------\n\n";

    // Output acceptance letter matching the example format
    cout << "Date: " << getCurrentDate() << "\n\n";
    cout << "To: " << firstName << " " << lastName << ",\n\n";
    cout << "Dear " << firstName << ",\n\n";
    cout << "CONGRATULATIONS! I am pleased to inform you that the Makerere University\n";
    cout << "Admissions Board has approved your application for admission to the\n";
    cout << academicYear << " academic year.\n\n";
    cout << "You have been offered a place for the following course:\n";
    cout << "PROGRAM: " << studyProgram << "\n\n";
    cout << "As a student of Makerere University, you will be part of a historic\n";
    cout << "institution dedicated to academic excellence and innovation. Please ensure\n";
    cout << "that you report to the Academic Registrar's office with your original\n";
    cout << "academic documents for verification during the orientation week.\n\n";
    cout << "We look forward to welcoming you to the Makerere University.\n\n";
    cout << "Yours sincerely,\n\n";
    cout << "John Doe\n";
    cout << "Registra\n";

    return 0;
}