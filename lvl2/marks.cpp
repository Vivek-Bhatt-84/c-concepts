#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// Method to generate random scores for students
vector<vector<int>> generateScores(int numStudents) {
    vector<vector<int>> scores(numStudents, vector<int>(3));
    srand(time(0));  // Seed for randomness

    for (int i = 0; i < numStudents; i++) {
        scores[i][0] = rand() % 41 + 60;  // Physics (60-100)
        scores[i][1] = rand() % 41 + 60;  // Chemistry (60-100)
        scores[i][2] = rand() % 41 + 60;  // Math (60-100)
    }
    return scores;
}

// Method to compute total, average, and percentage
vector<vector<double>> calculateStatistics(const vector<vector<int>>& scores) {
    vector<vector<double>> stats(scores.size(), vector<double>(3));

    for (size_t i = 0; i < scores.size(); i++) {
        int total = scores[i][0] + scores[i][1] + scores[i][2];
        double avg = total / 3.0;
        double percentage = (total / 300.0) * 100;

        stats[i][0] = total;
        stats[i][1] = round(avg * 100) / 100;  // Rounded to 2 decimal places
        stats[i][2] = round(percentage * 100) / 100;
    }
    return stats;
}

// Method to calculate grades
vector<string> assignGrades(const vector<vector<double>>& stats) {
    vector<string> grades(stats.size());

    for (int i = 0; i < stats.size(); i++) {
        double percentage = stats[i][2];

        if (percentage >= 90) grades[i] = "A+";
        else if (percentage >= 80) grades[i] = "A";
        else if (percentage >= 70) grades[i] = "B";
        else if (percentage >= 60) grades[i] = "C";
        else if (percentage >= 50) grades[i] = "D";
        else grades[i] = "F";
    }
    return grades;
}

// Method to display the final scorecard
void displayScorecard(const vector<vector<int>>& scores, const vector<vector<double>>& stats, const vector<string>& grades) {
    cout << setw(10) << "Student" << setw(10) << "Physics" << setw(10) << "Chemistry" << setw(10) << "Math"
         << setw(10) << "Total" << setw(10) << "Avg" << setw(12) << "Percentage" << setw(8) << "Grade" << endl;
    
    cout << string(80, '-') << endl;

    for (size_t i = 0; i < scores.size(); i++) {
        cout << setw(8) << i + 1
             << setw(10) << scores[i][0]
             << setw(10) << scores[i][1]
             << setw(10) << scores[i][2]
             << setw(10) << stats[i][0]
             << setw(10) << fixed << setprecision(2) << stats[i][1]
             << setw(10) << fixed << setprecision(2) << stats[i][2]
             << setw(8) << grades[i] << endl;
    }
}

int main() {
    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    vector<vector<int>> scores = generateScores(numStudents);
    vector<vector<double>> stats = calculateStatistics(scores);
    vector<string> grades = assignGrades(stats);

    cout << "\nStudent Scorecard:\n";
    displayScorecard(scores, stats, grades);

    return 0;
}
