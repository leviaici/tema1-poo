//
// Created by Adrian Leventiu on 03.11.2022.
//

#ifndef OOP_FUNCTIONALITIES_H
#define OOP_FUNCTIONALITIES_H
#include <iostream>
#include <ctime>
#include "../University.h"

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
    std::vector<Professor> p;

    Professor p1 = Professor("Marius", "Micluta", "Informatica", "marius.micluta@unibuc.ro", "Unknown", 23, 02, 1999);
    Professor p2 = Professor("Radu", "Boriga", "Informatica", "radu.boriga@unibuc.ro", "Unknown", 20, 7 ,1975);
    p.push_back(p1); p.push_back(p2);

    std::vector<Student> s;

    Student s1 = Student("Adrian", "Leventiu", "adrian.leventiu@s.unibuc.ro", "Unknown", 262, 31, 1, 2003);
    Student s2 = Student("Stefan", "Radu", "stefan.radu@s.unibuc.ro", "Unknown", 263, 19, 5, 2002);
    s.push_back(s1); s.push_back(s2);

    University unibuc("Universitatea din Bucuresti", "Matematica si Informatica", 1864, {}, {});
    unibuc.add_professor(Professor("Liliana", "Mitre", "Matematica", "liliana.mitre@unibuc.ro", "Unknown", 20, 1, 1990));
    unibuc.add_multipleProfessors(p);

    unibuc.print_professors();
    unibuc.sortProfessors();
    unibuc.print_professors();

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

void showLocalTime() {
    time_t now = time(nullptr);

    tm *ltm = localtime(&now);

    std::cout << "Your current date: " << ltm -> tm_mday << "/" << 1 + ltm -> tm_mon << "/" << 1900 + ltm -> tm_year << "\n";
    std::cout << "Your current time: " << ltm -> tm_hour << ":" << ltm -> tm_min << ":" << ltm -> tm_sec << "\n";
}

#endif //OOP_FUNCTIONALITIES_H
