#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class StudentDivision {
private:
    vector<int> marks;
    int totalMarks;
    double percentage;
    string division;
    
public:
    // Constructor
    StudentDivision() : totalMarks(0), percentage(0.0) {
        marks.resize(5, 0);
    }
    
    // Function to input marks with validation
    bool inputMarks() {
        cout << "Enter marks for 5 subjects (each out of 100):" << endl;
        
        for (int i = 0; i < 5; i++) {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
            
            // Input validation
            if (marks[i] < 0 || marks[i] > 100) {
                cout << "Error: Marks must be between 0 and 100. Please re-enter." << endl;
                i--; // Retry this subject
                continue;
            }
        }
        return true;
    }
    
    // Function to calculate total marks
    void calculateTotal() {
        totalMarks = 0;
        for (int mark : marks) {
            totalMarks += mark;
        }
    }
    
    // Function to calculate percentage
    void calculatePercentage() {
        percentage = (double)totalMarks / 5.0; // 5 subjects, each out of 100
    }
    
    // Function to determine division
    void determineDivision() {
        if (percentage >= 60) {
            division = "First Division";
        } else if (percentage >= 50 && percentage < 60) {
            division = "Second Division";
        } else if (percentage >= 40 && percentage < 50) {
            division = "Third Division";
        } else {
            division = "Fail";
        }
    }
    
    // Function to display results
    void displayResults() {
        cout << "\n" << string(50, '=') << endl;
        cout << "STUDENT RESULT ANALYSIS" << endl;
        cout << string(50, '=') << endl;
        
        cout << "\nMarks obtained:" << endl;
        for (int i = 0; i < 5; i++) {
            cout << "Subject " << (i + 1) << ": " << marks[i] << "/100" << endl;
        }
        
        cout << "\nTotal Marks: " << totalMarks << "/500" << endl;
        cout << fixed << setprecision(2);
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Division: " << division << endl;
        
        // Additional analysis
        cout << "\nAnalysis:" << endl;
        if (division == "First Division") {
            cout << "Excellent performance! Keep up the good work." << endl;
        } else if (division == "Second Division") {
            cout << "Good performance! There's room for improvement." << endl;
        } else if (division == "Third Division") {
            cout << "Average performance. Consider working harder." << endl;
        } else {
            cout << "Poor performance. Immediate attention required." << endl;
        }
    }
    
    // Function to run the complete process
    void run() {
        cout << "STUDENT DIVISION CALCULATOR" << endl;
        cout << "=========================" << endl;
        
        if (inputMarks()) {
            calculateTotal();
            calculatePercentage();
            determineDivision();
            displayResults();
        }
    }
    
    // Getter functions for testing
    double getPercentage() const { return percentage; }
    string getDivision() const { return division; }
    int getTotalMarks() const { return totalMarks; }
};

// Test function to demonstrate various scenarios
void runTestCases() {
    cout << "\n" << string(60, '=') << endl;
    cout << "TESTING VARIOUS SCENARIOS" << endl;
    cout << string(60, '=') << endl;
    
    // Test Case 1: First Division
    cout << "\nTest Case 1: First Division (>= 60%)" << endl;
    StudentDivision student1;
    student1.marks = {85, 92, 78, 88, 90};
    student1.calculateTotal();
    student1.calculatePercentage();
    student1.determineDivision();
    student1.displayResults();
    
    // Test Case 2: Second Division
    cout << "\nTest Case 2: Second Division (50-59%)" << endl;
    StudentDivision student2;
    student2.marks = {55, 58, 52, 56, 59};
    student2.calculateTotal();
    student2.calculatePercentage();
    student2.determineDivision();
    student2.displayResults();
    
    // Test Case 3: Third Division
    cout << "\nTest Case 3: Third Division (40-49%)" << endl;
    StudentDivision student3;
    student3.marks = {45, 42, 48, 44, 46};
    student3.calculateTotal();
    student3.calculatePercentage();
    student3.determineDivision();
    student3.displayResults();
    
    // Test Case 4: Fail
    cout << "\nTest Case 4: Fail (< 40%)" << endl;
    StudentDivision student4;
    student4.marks = {35, 38, 32, 36, 34};
    student4.calculateTotal();
    student4.calculatePercentage();
    student4.determineDivision();
    student4.displayResults();
    
    // Test Case 5: Edge case - exactly 60%
    cout << "\nTest Case 5: Edge Case - Exactly 60%" << endl;
    StudentDivision student5;
    student5.marks = {60, 60, 60, 60, 60};
    student5.calculateTotal();
    student5.calculatePercentage();
    student5.determineDivision();
    student5.displayResults();
    
    // Test Case 6: Edge case - exactly 50%
    cout << "\nTest Case 6: Edge Case - Exactly 50%" << endl;
    StudentDivision student6;
    student6.marks = {50, 50, 50, 50, 50};
    student6.calculateTotal();
    student6.calculatePercentage();
    student6.determineDivision();
    student6.displayResults();
    
    // Test Case 7: Edge case - exactly 40%
    cout << "\nTest Case 7: Edge Case - Exactly 40%" << endl;
    StudentDivision student7;
    student7.marks = {40, 40, 40, 40, 40};
    student7.calculateTotal();
    student7.calculatePercentage();
    student7.determineDivision();
    student7.displayResults();
    
    // Test Case 8: Mixed performance
    cout << "\nTest Case 8: Mixed Performance" << endl;
    StudentDivision student8;
    student8.marks = {95, 45, 88, 32, 76};
    student8.calculateTotal();
    student8.calculatePercentage();
    student8.determineDivision();
    student8.displayResults();
}

int main() {
    int choice;
    
    cout << "STUDENT DIVISION CALCULATOR" << endl;
    cout << "=========================" << endl;
    cout << "1. Enter marks manually" << endl;
    cout << "2. Run test cases" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice (1-3): ";
    
    cin >> choice;
    
    switch (choice) {
        case 1: {
            StudentDivision student;
            student.run();
            break;
        }
        case 2: {
            runTestCases();
            break;
        }
        case 3: {
            cout << "Thank you for using the Student Division Calculator!" << endl;
            break;
        }
        default: {
            cout << "Invalid choice. Please run the program again." << endl;
            break;
        }
    }
    
    return 0;
}
