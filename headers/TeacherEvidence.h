//
// Created by Adrian Leventiu on 30.01.2023.
//

#ifndef OOP_TEACHEREVIDENCE_H
#define OOP_TEACHEREVIDENCE_H

template<class T> class TeacherEvidence {
    T teacher;
    int salary;
    int failedExamBonus;
public:
    TeacherEvidence(T& teacher, int salary, int failedExamBonus);
    void print();
};


#endif //OOP_TEACHEREVIDENCE_H
