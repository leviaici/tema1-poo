//
// Created by Adrian Leventiu on 03.11.2022.
//

#ifndef OOP_FUNCTIONALITIES_H
#define OOP_FUNCTIONALITIES_H
#include <iostream>
#include <ctime>
#include <filesystem>
#include <limits>
#include <ios>
#include <memory>
#include "rlutil.h"
#include "../University.h"
#include "../SeminarTeacher.h"
#include "../LaboratoryTeacher.h"
#include "../CourseTeacher.h"

void ignoreReading() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max());
}

std::string toLower(std::string word) {
    if(word[0] >= 65 && word[0] <= 90)
        word[0] += 32;
    for(unsigned i = 1; i < word.size(); i++)
        if(word[i] == '-' && word[i + 1] >= 65 && word[i + 1] <= 90)
            word[i + 1] += 32;
    return word;
}
std::string toLowerWholeWord(std::string word) {
    for(char &letter : word)
        if(letter >= 65 && letter <= 90)
            letter += 32;
    return word;
}

void test() {
    std::vector<std::shared_ptr<Professor>> p;
    std::vector<std::shared_ptr<Professor>> empty;

    std::shared_ptr<Professor> p1 = static_cast<std::shared_ptr<Professor>>(new LaboratoryTeacher("Marius", "Micluta","Informatica","marius.micluta@unibuc.ro","Unknown", 23, 02,1999));
    std::shared_ptr<Professor> p2 = static_cast<std::shared_ptr<Professor>>(new CourseTeacher("Radu", "Boriga","Informatica","radu.boriga@unibuc.ro","Unknown", 20, 7, 1975));
    p.push_back(p1); p.push_back(p2);

//    LaboratoryTeacher p3 = LaboratoryTeacher("Marius", "Micluta","Informatica","marius.micluta@unibuc.ro","Unknown", 23, 02,1999);

//    std::cout << *(p1);

    std::vector<Student> s;

    Student s1 = Student("Adrian", "Leventiu", "adrian.leventiu@s.unibuc.ro", "Unknown", 262, 31, 1, 2003);
    Student s2 = Student("Stefan", "Radu", "stefan.radu@s.unibuc.ro", "Unknown", 263, 19, 5, 2002);
    s.push_back(s1); s.push_back(s2);

    University unibuc("Universitatea din Bucuresti", "Matematica si Informatica", 1864, empty , {});
    unibuc.add_professor(static_cast<std::shared_ptr<Professor>>(new SeminarTeacher("Liliana", "Mitre", "Matematica","liliana.mitre@unibuc.ro","Unknown", 20, 1, 1990)));
    unibuc.add_multipleProfessors(p);

    unibuc.print_professors();

    unibuc.sortProfessors();
    unibuc.print_professors();
//
    std::vector<int> g;
    g.push_back(4); g.push_back(8); g.push_back(7); g.push_back(5);

    Subject note("Informatica", g);
    Subject note2("Matematica", std::vector<int>{10, 10, 10, 8});

    std::vector<Subject> note3, note4;
    note3.push_back(note); note3.push_back(note2);
    note4.push_back(note2); note4.push_back(Subject("Informatica", std::vector<int>{4, 9, 7, 5}));


    unibuc.add_student(Student("Flavius", "Popescu", "flavius.popescu@s.unibuc.ro", "0711223344", 261, 19, 9, 2001, note3));
    unibuc.add_multipleStudents(s);
    unibuc.add_student(Student("Flavius", "Ratat", "flavius.popescu@s.damada.ro", "nu am", 262, 26, 6, 1996, note4));
    unibuc.add_student(Student("Radu", "Macelaru", "radu.macelaru@s.unibuc.ro", "0711223344", 104, 19, 4, 1998, note3));
    unibuc.print_students();
    unibuc.reclassify();
    unibuc.print_students();

    unibuc.print_groups();
}

int localDay() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    return ltm -> tm_mday;
}

int localMonth() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    return 1 + ltm -> tm_mon;
}

int localYear() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    return 1900 + ltm -> tm_year;
}

void showLocalTime() {
    time_t now = time(nullptr);

    tm *ltm = localtime(&now);

    std::cout << "Your current date: " << ltm -> tm_mday << "/" << 1 + ltm -> tm_mon << "/" << 1900 + ltm -> tm_year << "\n";
    std::cout << "Your current time: " << ltm -> tm_hour << ":" << ltm -> tm_min << ":" << ltm -> tm_sec << "\n";
}

bool checkSymbols(const std::string& password) {
    std::vector<char> symbols = {'@', '_', ',', '!', '.', '-', ';', '+', '/', '?', '|', ']', '[', '=', '(', ')', '*', '&', '^', '%', '$', '#', '\\', '`', '~', '<', '>', '{', '}', ':'};
    return std::any_of(symbols.begin(), symbols.end(),
                       [&password](const auto& s){ return password.find(s) != std::string::npos; });
}

bool checkNumbers(const std::string& password) {
    std::vector<char> numbers = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    return std::any_of(numbers.begin(), numbers.end(),
                       [&password](const auto& s){ return password.find(s) != std::string::npos; });
}

bool checkUppercaseLetters(const std::string& password) {
    std::vector<char> uppercaseLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    return std::any_of(uppercaseLetters.begin(), uppercaseLetters.end(),
                       [&password](const auto& s){ return password.find(s) != std::string::npos; });
}

bool checkLowercaseLetters(const std::string& password) {
    std::vector<char> uppercaseLetters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    return std::any_of(uppercaseLetters.begin(), uppercaseLetters.end(),
                       [&password](const auto& s){ return password.find(s + 32) != std::string::npos; });
}

float checkPasswordComplexity(const std::string& password) {
    float complexity = 50;

    bool symbolsFound = checkSymbols(password);

    bool numbersFound = checkNumbers(password);

    bool uppercaseLettersFound = checkUppercaseLetters(password);
    bool lowercaseLettersFound = checkLowercaseLetters(password);

    if(symbolsFound)
        complexity += 12.5;
    else complexity -= 12.5;

    if(numbersFound)
        complexity += 12.5;
    else complexity -= 12.5;

    if(uppercaseLettersFound)
        complexity += 12.5;
    else complexity -= 12.5;

    if(lowercaseLettersFound)
        complexity += 12.5;
    else complexity -= 12.5;

    return complexity;
}

void initialPrintForPassword(const int& complexity, const std::string& password) {
    rlutil::setColor(7);
    std::cout << "Minimum number of characters of the password: 10";
    if(password.size() >= 10) {
        rlutil::setColor(10);
        std::cout << " ✔\n";
    } else std::cout << "\n";
    rlutil::setColor(7);
    std::cout << "Minimum complexity of password: ";
    rlutil::setColor(14);
    std::cout << "[■■■■■■■■■■■■■■■■                ]";
    if(complexity >= 50) {
        rlutil::setColor(10);
        std::cout << " ✔\n";
    } else std::cout << "\n";
    rlutil::setColor(7);
    std::cout << "Complexity of your password:    ";
    rlutil::setColor(12);
    std::cout << "[                                ]";
}

void printComplexity(const int& complexity, const std::string& password) {
    initialPrintForPassword(complexity, password);

    rlutil::locate(33, 3);
    switch(complexity) {
        case 25:
            rlutil::setColor(13);
            std::cout << "[■■■■■■■■                        ]\n";
            rlutil::setColor(12);
            rlutil::locate(1, 5);
            std::cout << "Password too weak.\n";
            break;
        case 50:
            rlutil::setColor(14);
            std::cout << "[■■■■■■■■■■■■■■■■                ]\n";
            rlutil::locate(1, 5);
            std::cout << "Unsafe password.\n";
            break;
        case 75:
            rlutil::setColor(10);
            std::cout << "[■■■■■■■■■■■■■■■■■■■■■■■■        ]\n";
            rlutil::locate(1, 5);
            std::cout << "Decent password.\n";
            break;
        case 100:
            rlutil::setColor(11);
            std::cout << "[■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■]\n";
            rlutil::locate(1, 5);
            std::cout << "Great password.\n";
            break;
        default:
            break;
    }

    rlutil::setColor(7);
}

#endif //OOP_FUNCTIONALITIES_H
