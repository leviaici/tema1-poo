#include <vector>
#include "headers/University.h"
#include <fstream>

std::string toLower(std::string word) {
    if(word[0] >= 65 && word[0] <= 90)
        word[0] += 32;
    for(unsigned i = 1; i < word.size(); i++)
        if(word[i] == '-' && word[i + 1] >= 65 && word[i + 1] <= 90)
            word[i + 1] += 32;
    return word;
}
/*std::string toLowerWholeWord(std::string word) {
    for(unsigned i = 0; i < word.size(); i++)
        if(word[i] >= 65 && word[i] <= 90)
            word[i] += 32;
    return word;
}*/

/*std::string generateEmail(std::string university, std::string firstName, std::string lastName) {
    university = toLowerWholeWord(university);
    if(strstr(university, "universitate"))
        return toLower(firstName) + "." + toLower(lastName) + "@s.unibuc.ro";
    if(strstr(university, "politehnica"))
        return toLower(firstName) + "." + toLower(lastName) + "@upb.ro";
    if(strstr(university, "babes"))
        return toLower(firstName) + "." + toLower(lastName) + "@ubb.ro";
}*/ ///TBA

void test() {
    std::vector<Professor> p;

    Professor p1 = Professor("Marius Micluta", "Informatica", "marius.micluta@unibuc.ro", "Unknown", 23);
    Professor p2 = Professor("Radu Boriga", "Informatica", "radu.boriga@unibuc.ro", "Unknown", 50);
    p.push_back(p1); p.push_back(p2);

    std::vector<Student> s;

    Student s1 = Student("Adrian", "Leventiu", "adrian.leventiu@s.unibuc.ro", "Unknown", 262, 19);
    Student s2 = Student("Stefan", "Radu", "stefan.radu@s.unibuc.ro", "Unknown", 263, 19);
    s.push_back(s1); s.push_back(s2);

    University unibuc("Universitatea din Bucuresti", "Matematica si Informatica", 1864, {}, {});
    unibuc.add_professor(Professor("Liliana Mitre", "Matematica", "liliana.mitre@unibuc.ro", "Unknown", 35));
    unibuc.add_multipleProfessors(p);

    unibuc.sortProfessors();
    unibuc.print_professors();

    std::vector<int> g;
    g.push_back(4); g.push_back(8); g.push_back(7); g.push_back(5);

    Subject note("Informatica", g);
    Subject note2("Matematica", std::vector<int>{10, 10, 10, 8});

    std::vector<Subject> note3, note4;
    note3.push_back(note); note3.push_back(note2);
    note4.push_back(note2); note4.push_back(Subject("Informatica", std::vector<int>{4, 9, 7, 5}));


    unibuc.add_student(Student("Flavius", "Popescu", "flavius.popescu@s.unibuc.ro", "0711223344", 261, 19, note3));
    unibuc.add_multipleStudents(s);
    unibuc.add_student(Student("Flavius", "Ratat", "flavius.popescu@s.damada.ro", "nu am", 262, 25, note4));
    unibuc.add_student(Student("Radu", "Macelaru", "radu.macelaru@s.unibuc.ro", "0711223344", 104, 19, note3));
    unibuc.print_students();
    unibuc.reclassify();
    unibuc.print_students();

    unibuc.print_groups();
//    Student s5("Flavius Popescu", "flavius.popescu@s.unibuc.ro", "0711223344", 261, 19, note3);
//    s5.print();
}

void initializer() {
    std::ifstream read("../tastatura.txt"); ///din fisier ca sa nu crape github actions...
    std::string firstName, lastName, email, phoneNumber;
    int group, age;

    std::cout << "Hello! What's your name?\n";
    read >> firstName >> lastName;

    std::cout << "Nice to meet you, " << firstName << "!\n";

    email = toLower(firstName) + "." + toLower(lastName) + "@s.unibuc.ro";
    std::cout << "Here's your brand new generated e-mail: " << email << "\n";

    std::cout << "What's your phone number?\n";
    read >> phoneNumber;

    std::cout << "What group were you assigned to?\n";
    read >> group;

    std::cout << "How old are you?\n";
    read >> age;

    std::cout << "Great! Now the next step...\n";

    std::vector<Subject> subjects;
    std::vector<std::string> listOfSubjects = {"Mathematics", "Computer Science", "Physics"};
    for(unsigned i = 0; i < listOfSubjects.size(); i++) {
        int grade = 1;
        Subject subject(listOfSubjects[i], {});
        std::cout << "Tell us your grades at " + listOfSubjects[i] + ": ";
        while (grade != 0) {
            read >> grade;
            subject.addGrade(grade);
//            grade = 0; ///doar pentru github actions, in mod normal nu are ce cauta aici
        }
        subjects.push_back(subject);
    }
    for(unsigned i = 0; i < listOfSubjects.size(); i++)
        std::cout << subjects[i] << "\n";

    read.close();

    Student student(firstName, lastName, email, phoneNumber, group, age, subjects);

    std::cout << student;

    ///salvam in fisiere, la fel ca in login system. la fel facem si login system ul, "cryptam" prin aceeasi metoda
    ///salvam in fisier luna + anul in care am ajuns cu simulatul pentru a putea relua o salvare deja existenta
}

int main() {
    test();
    initializer();
    return 0;
}