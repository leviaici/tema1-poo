//
// Created by Adrian Leventiu on 23.10.2022.
//

#ifndef OOP_GRADES_H
#define OOP_GRADES_H

#include <iostream>
#include <vector>

class Grades {
private:
    std::string subject = "Unknown";
    std::vector<int> grades;
//    float bonusPoints = .0; // TBA
    float average = .0;
    bool passed = false;

public:
    Grades();

    Grades(const std::string& subject, const std::vector<int>& grades);

    Grades(const Grades& other);

    Grades& operator = (const Grades& other) {
        subject = other.subject;
        grades = other.grades;
        average = other.average;
        passed = other.passed;
        std::cout << "Grades Operator =\n";
        return *this;
    }

    ~Grades();

    void print();

    float calculateAverage();

    bool passedOrFailed();

    //void sortGrades();

    float get_average();
};


#endif //OOP_GRADES_H
