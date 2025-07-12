//*****************************************************************************************************
// 🎓 Grade Calculator with Progress Bars
//
// This program helps calculate your final grade in a Computer Programming I class.
// You enter your scores for assignments, tests, exams, and participation,
// and it calculates your final percentage and letter grade.
//
// It also shows you visual progress bars to make things more fun and clear!
//*****************************************************************************************************

#include <iostream>
#include <iomanip>
using namespace std;

// Simple function to show a progress bar based on the percentage
void showProgressBar(float percent) {
    int bars = percent / 2; // The bar is 50 characters long, so scale it down
    cout << "[";
    for (int i = 0; i < 50; ++i) {
        if (i < bars)
            cout << "#";  // Filled part
        else
            cout << ".";  // Empty part
    }
    cout << "] " << fixed << setprecision(2) << percent << "%" << endl;
}

int main() {
    // Fixed weight for each component of the final grade
    const int ASSIGN_PERCENT = 15;
    const int TEST_PERCENT   = 50;
    const int EXAM_PERCENT   = 30;
    const int PARTIC_PERCENT = 5;

    // Variables to store user input and calculated weights
    float assignWeight, testWeight, examWeight, particWeight;
    float PercentOutOf100, sum_of_all_weights, avg;

    // Welcome message
    cout << "*************************************************************\n";
    cout << "             Grade Calculator - Computer Programming I\n";
    cout << "*************************************************************\n";

    // Show how much each part is worth
    cout << "\nHere's how much each part counts toward your final grade:\n"
         << "  📘 Programming Assignments: " << ASSIGN_PERCENT << "%\n"
         << "  📝 Chapter Tests:           " << TEST_PERCENT << "%\n"
         << "  📚 Final Exam:              " << EXAM_PERCENT << "%\n"
         << "  🙋 Class Participation:     " << PARTIC_PERCENT << "%\n";

    // Ask for user's grades
    cout << "\nNow, enter the scores you received (out of 100%)\n";

    cout << "\n📘 Programming Assignments: ";
    cin >> PercentOutOf100;
    assignWeight = PercentOutOf100 * ASSIGN_PERCENT;

    cout << "📝 Chapter Tests: ";
    cin >> PercentOutOf100;
    testWeight = PercentOutOf100 * TEST_PERCENT;

    cout << "📚 Final Exam: ";
    cin >> PercentOutOf100;
    examWeight = PercentOutOf100 * EXAM_PERCENT;

    cout << "🙋 Class Participation: ";
    cin >> PercentOutOf100;
    particWeight = PercentOutOf100 * PARTIC_PERCENT;

    // Total weight (should be 100, but good to keep flexible)
    sum_of_all_weights = ASSIGN_PERCENT + TEST_PERCENT + EXAM_PERCENT + PARTIC_PERCENT;

    // Calculate the final average
    avg = (assignWeight + testWeight + examWeight + particWeight) / sum_of_all_weights;

    // Print each part's contribution using a fun progress bar
    cout << "\n\n------------------ Your Grade Breakdown ------------------\n";
    cout << fixed << setprecision(2);

    cout << "\n📘 Programming Assignments:\n";
    showProgressBar(assignWeight / sum_of_all_weights);

    cout << "📝 Chapter Tests:\n";
    showProgressBar(testWeight / sum_of_all_weights);

    cout << "📚 Final Exam:\n";
    showProgressBar(examWeight / sum_of_all_weights);

    cout << "🙋 Class Participation:\n";
    showProgressBar(particWeight / sum_of_all_weights);

    // Show final score and letter grade
    cout << "\n-------------------------------------------------------------";
    cout << "\n🎯 Final Grade: " << avg << "%" << endl;

    cout << "📊 Final Letter Grade: ";

    // Decide the letter grade based on the final percentage
    if (avg >= 97 || avg == 100)
        cout << "A+";
    else if (avg >= 94 && avg <= 96)
        cout << "A";
    else if (avg >= 90 && avg <= 93)
        cout << "A-";
    else if (avg >= 87 && avg <= 89)
        cout << "B+";
    else if (avg >= 84 && avg <= 86)
        cout << "B";
    else if (avg >= 80 && avg <= 83)
        cout << "B-";
    else if (avg >= 77 && avg <= 79)
        cout << "C+";
    else if (avg >= 74 && avg <= 76)
        cout << "C";
    else if (avg >= 70 && avg <= 73)
        cout << "C-";
    else if (avg >= 60 && avg <= 69)
        cout << "D";
    else
        cout << "F";  // Sorry 😅

    // Closing message
    cout << "\n*************************************************************\n";
    cout << "        📌 Thanks for using this Grade Calculator!\n";
    cout << "*************************************************************\n";

    return 0;
}
