//
// Created by Adrian Leventiu on 23.10.2022.
//

#ifndef OOP_STUDENT_H
#define OOP_STUDENT_H

#include <iostream>
#include <vector>
#include "Subject.h"

class Student {
private:
    std::string firstName = "Unknown";
    std::string lastName = "Unknown";
    std::string email = "Unknown";
    std::string phoneNumber = "Unknown";

    int group = 0;
    int birthDay = 0;
    int birthMonth = 0;
    int birthYear = 0;
    int id = 0;
    static int id_max;
    float overallAverage = .0;
    bool tuitionFree = false;

    std::vector<Subject> subjects;

public:
    Student();

    Student(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& phoneNumber, const int& group, const int& birthDay, const int& birthMonth, const int& birthYear, const std::vector<Subject>& subjects);

    Student(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& phoneNumber, const int& group, const int& birthDay, const int& birthMonth, const int& birthYear);

    Student(const Student& other);

    Student& operator = (const Student& other) {
        firstName = other.firstName;
        lastName = other.lastName;
        email = other.email;
        phoneNumber = other.phoneNumber;
        group = other.group;
        birthDay = other.birthDay;
        birthMonth = other.birthMonth;
        birthYear = other.birthYear;
        id = other.id;
        overallAverage = other.overallAverage;
        tuitionFree = other.tuitionFree;
        subjects = other.subjects;
//        std::cout << "Student Operator =\n";
        return *this;
    }

    ~Student();

    void set_id(const int& other);

    void calculateOverallAverage();

    float get_overallAverage() const;

    int get_group() const;

    void print();

    void set_tuitionFree(const bool& status);
//    void set_subjects(const std::vector<Subject>& other);

    std::string get_firstName() const;
    std::string get_lastName() const;
//    std::vector<Subject> get_subjects();
    /*std::string get_email();
    std::string get_phoneNumber();
    int get_group();
    bool get_tuitionFree();*/
    friend std::ostream& operator<< (std::ostream& os, const Student& other)
    {
        os << "Full name: " << other.lastName << " " << other.firstName << "\n";
        os << "E-mail: " << other.email << "\n";
        os << "Phone number: " << other.phoneNumber << "\n";
        os << "Group: " << other.group << "\n";
        os << "Birth date: " << other.birthDay << "/" << other.birthMonth << "/" << other.birthYear << "\n\n";
        os << "ID: " << other.id << "\n";
        os << "Overall average: " << other.overallAverage << "\n";

        for(const auto &c: other.subjects)
            os << c;

        os << "Tuition free: " << other.tuitionFree << "\n\n\n";
        return os;
    }
};




#endif //OOP_STUDENT_H
