//
// Created by Adrian Leventiu on 30.01.2023.
//

#include "../headers/TeacherEvidence.h"
#include <iostream>

template<class T>
TeacherEvidence<T>::TeacherEvidence(T& teacher, int salary, int failedExamBonus) : T(teacher), salary(salary), failedExamBonus(failedExamBonus) {}

template<class T>
void TeacherEvidence<T>::print() {
    std::cout << "Dear, " << (this->teacher).get_name() << " you have a salary of " << this->salary << "and a bonus for every failed exam of " << failedExamBonus << " RON.\n";
}