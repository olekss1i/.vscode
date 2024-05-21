#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 5;

struct Student {
    string surname;
    int exam1;
    int exam2;
    int exam3;
    float average;
};

void findMaxAvgStud(const Student students[], int size, int& maxCount, int indices[]) {
    maxCount = 0;
    float maxAvg = 0.0;

    for (int i = 0; i < size; ++i) {
        if (students[i].average > maxAvg) {
            maxAvg = students[i].average;
            maxCount = 1;
        } else if (students[i].average == maxAvg) {
            maxCount++;
        }
    }

    int index = 0;
    for (int i = 0; i < size; ++i) {
        if (students[i].average == maxAvg) {
            indices[index++] = i;
        }
    }
}

int binarySearch(const Student students[], int size, float targetAvg) {
    int left = 0;
    int right = size - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].average == targetAvg) {
            result = mid;
            break;
        } else if (students[mid].average < targetAvg) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    Student students[MAX_STUDENTS] = {
        {"Smith", 80, 85, 90, 0},
        {"Johnson", 75, 85, 95, 0},
        {"Williams", 90, 95, 85, 0},
        {"Jones", 85, 80, 85, 0},
        {"Brown", 95, 90, 95, 0}
    };

    for (int i = 0; i < MAX_STUDENTS; ++i) {
        students[i].average = (students[i].exam1 + students[i].exam2 + students[i].exam3) / 3.0;
    }

    int maxCount;
    int maxIndices[MAX_STUDENTS];
    findMaxAvgStud(students, MAX_STUDENTS, maxCount, maxIndices);

    cout << "Number of students with maximum average score: " << maxCount << endl;
    cout << "Their indices: ";
    for (int i = 0; i < maxCount; ++i) {
        cout << maxIndices[i] << " ";
    }
    cout << endl;

    float targetAvg;
    cout << "Enter the average score to search: ";
    cin >> targetAvg;

    int resultIndex = binarySearch(students, MAX_STUDENTS, targetAvg);
    if (resultIndex != -1) {
        cout << "Student found: " << students[resultIndex].surname << endl;
    } else {
        cout << "Student with the specified average score not found." << endl;
    }

    return 0;
}
