#include <vector>
#include "University.h"


int main() {
    std::vector<Professor> p;

    Professor p1 = Professor("Marius Micluta", "Informatica", "marius.micluta@unibuc.ro", "Unknown", 23);
    Professor p2 = Professor("Radu Boriga", "Informatica", "radu.boriga@unibuc.ro", "Unknown", 50);
    p.push_back(p1); p.push_back(p2);

    std::vector<Student> s;

    Student s1 = Student("Adrian Leventiu", "adrian.leventiu@s.unibuc.ro", "Unknown", 262, 19);
    Student s2 = Student("Stefan Radu", "stefan.radu@s.unibuc.ro", "Unknown", 263, 19);
    s.push_back(s1); s.push_back(s2);

    University unibuc("Universitatea din Bucuresti", "Matematica si Informatica", 1864);
    unibuc.add_professor(Professor("Liliana Mitre", "Matematica", "liliana.mitre@unibuc.ro", "Unknown", 35));
    unibuc.add_vectorOfProfessors(p);

    std::vector<int> g;
    g.push_back(4); g.push_back(8); g.push_back(7); g.push_back(5);

    Grades note("Informatica", g);
    Grades note2("Matematica", std::vector<int>{10, 10, 10, 8});

    std::vector<Grades> note3, note4;
    note3.push_back(note); note3.push_back(note2);
    note4.push_back(note2); note4.push_back(Grades("Informatica", std::vector<int>{4,9,7,5}));


    unibuc.add_student(Student("Flavius Popescu", "flavius.popescu@s.unibuc.ro", "0711223344", 261, 19, note3));
    unibuc.add_vectorOfStudents(s);
    unibuc.add_student(Student("Flavius ratat", "flavius.popescu@s.damada.ro", "nu am", 262, 25, note4));
    unibuc.print_students();
    unibuc.reclassify();
    unibuc.print_students();


//    Student s5("Flavius Popescu", "flavius.popescu@s.unibuc.ro", "0711223344", 261, 19, note3);
//    s5.print();
    return 0;
}