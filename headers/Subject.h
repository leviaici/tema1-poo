//
// Created by Adrian Leventiu on 23.10.2022.
//

#ifndef OOP_SUBJECT_H
#define OOP_SUBJECT_H

#include <iostream>
#include <vector>

class Subject {
private:
    std::string subject = "Unknown";
    std::vector<int> grades;
//    float bonusPoints = .0; // TBA
    float average = .0;
    bool passed = false;

public:
    Subject();

    Subject(const std::string& subject, const std::vector<int>& grades);

    Subject(const Subject& other);

    Subject& operator = (const Subject& other) {
        subject = other.subject;
        grades = other.grades;
        average = other.average;
        passed = other.passed;
        std::cout << "Subject Operator =\n";
        return *this;
    }

    ~Subject();

    void print();

    float calculateAverage();

    bool passedOrFailed();

    //void sortGrades();

    float get_average();
};


#endif //OOP_SUBJECT_H
