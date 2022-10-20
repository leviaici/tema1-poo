#include <iostream>
#include <vector>
#include <algorithm>

class Grades {
private:
    std::string subject = "Unknown";
    std::vector<int> grades;
//    float bonusPoints = .0; // TBA
    float average = .0;
    bool passed = false;

public:
    Grades() = default;

    Grades(const std::string& subject, const std::vector<int>& grades) {
        this -> subject = subject;
        this -> grades = grades;
        this -> average = calculateAverage();
        this -> passed = passedOrFailed();
    }

    Grades(const Grades& other) : subject{other.subject}, grades{other.grades}, average{other.average}, passed{other.passed} {
        std::cout << "Creating Grades via copy-constructor.\n";
    }

    Grades& operator = (const Grades& other) {
        subject = other.subject;
        grades = other.grades;
        average = other.average;
        passed = other.passed;
        std::cout << "Grades Operator =\n";
        return *this;
    }

    ~Grades() {
        std::cout << "Killing the grades.\n";
    }

    void print() {
        std::cout << this -> subject << "\n";
        for(auto c : this -> grades)
            std::cout << c << " ";
        std::cout << "\n" << this -> average << "\n";
        std::cout << this -> passed << "\n\n\n";
    }

    float calculateAverage() {
        float sum = 0;
        for(auto c : this -> grades)
            sum += c;
        return float(sum / (this -> grades).size());
    }

    bool passedOrFailed() {
        return this -> average >= 5;
    }

    /*void sortGrades() {
        sort((this -> grades).begin(), (this -> grades).end());
    }*/

    float get_average() { return this ->  average; }
};

class Professor {
private:
    std::string name = "Unknown";
    std::string subject = "Unknown";
    std::string email = "Unknown";
    std::string phoneNumber = "Unknown";
    int age = 0;

public:
    Professor() = default;

    Professor(const std::string& name, const std::string& subject, const std::string& email, const std::string& phoneNumber, const int& age) {
        this -> name = name;
        this -> subject = subject;
        this -> email = email;
        this -> phoneNumber = phoneNumber;
        this -> age = age;
    }

    Professor(const Professor& other) : name{other.name}, subject{other.subject}, email{other.email}, phoneNumber{other.phoneNumber}, age{other.age} {
        std::cout << "Creating Professor via copy-constructor.\n";
    }

    Professor& operator = (const Professor& other) {
        name = other.name;
        subject = other.subject;
        email = other.email;
        phoneNumber = other.phoneNumber;
        age = other.age;
        std::cout << "Professor Operator =\n";
        return *this;
    }

    ~Professor() {
         std::cout << "Killing the professor.\n";
    }

    void print() {
        std::cout << this -> name << "\n";
        std::cout << this -> subject << "\n";
        std::cout << this -> email << "\n";
        std::cout << this -> phoneNumber << "\n";
        std::cout << this -> age << "\n\n\n";
    }

    std::string get_name() { return this -> name; }
    /*[[maybe_unused]] std::string get_subject() { return this -> subject; }
    [[maybe_unused]] std::string get_email() { return this -> email; }
    [[maybe_unused]] std::string get_phoneNumber() { return this -> phoneNumber; }
    [[maybe_unused]] int get_age() { return this -> age; } */
};

class Student {
private:
    std::string name = "Unknown";
    std::string email = "Unknown";
    std::string phoneNumber = "Unknown";
    int group = 0;
    int age = 0;
    int id = 0;
    float overallAverage = .0;
    bool tuitionFree = false;

    std::vector<Grades> g;

public:
    Student() = default;

    Student(const std::string& name, const std::string& email, const std::string& phoneNumber, const int& group, const int& age, const std::vector<Grades>& g) {
        this -> name = name;
        this -> email = email;
        this -> phoneNumber = phoneNumber;
        this -> group = group;
        this -> age = age;
        this -> g = g;
        calculateOverallAverage();
    }

    Student(const std::string& name, const std::string& email, const std::string& phoneNumber, const int& group, const int& age) {
        this -> name = name;
        this -> email = email;
        this -> phoneNumber = phoneNumber;
        this -> group = group;
        this -> age = age;
    }

    Student(const Student& other) : name{other.name}, email{other.email}, phoneNumber{other.phoneNumber}, group{other.group}, age{other.age}, id{other.id}, overallAverage{other.overallAverage}, tuitionFree{other.tuitionFree}, g{other.g} {
        std::cout << "Creating Student via copy-constructor.\n";
    }

    Student& operator = (const Student& other) {
        name = other.name;
        email = other.email;
        phoneNumber = other.phoneNumber;
        group = other.group;
        age = other.age;
        id = other.id;
        overallAverage = other.overallAverage;
        tuitionFree = other.tuitionFree;
        g = other.g;
        std::cout << "Student Operator =\n";
        return *this;
    }

    ~Student() {
        std::cout << "Killing the student.\n";
    }

    void set_id(const int& other) { this -> id = other; }

    void calculateOverallAverage() {
        for(auto c : (this -> g))
            (this -> overallAverage) += c.get_average();
        (this -> overallAverage) /= (this -> g).size();
    }

    float get_overallAverage() { return this -> overallAverage; }

    void print() {
        std::cout << this -> name << "\n";
        std::cout << this -> email << "\n";
        std::cout << this -> phoneNumber << "\n";
        std::cout << this -> group << "\n";
        std::cout << this -> age << "\n";
        std::cout << this -> id << "\n";
        std::cout << this -> overallAverage << "\n";
        for(auto c : this -> g)
            c.print();
        std::cout << "TUITION FREE: " << this -> tuitionFree << "\n\n\n\n";
    }

    void set_tuitionFree(const bool& status) { this -> tuitionFree = status; }

    /*std::string get_name() { return this -> name; }
    std::string get_email() { return this -> email; }
    std::string get_phoneNumber() { return this -> phoneNumber; }
    int get_group() { return this -> group; }
    int get_age() { return this -> age; }
    bool get_tuitionFree() { return this -> tuitionFree; } */
};

class University {
private:
    std::string name;
    std::string subject;
    int foundationYear;

    std::vector<Professor> p;
    std::vector<Student> s;

public:
    University(const std::string& name, const std::string& subject, const int& foundationYear, const std::vector<Professor>& p, const std::vector<Student>& s) {
        this -> name = name;
        this -> subject = subject;
        this -> foundationYear = foundationYear;
        this -> p = p;
        this -> s = s;
    }

    University(const std::string& name, const std::string& subject, const int& foundationYear) {
        this -> name = name;
        this -> subject = subject;
        this -> foundationYear = foundationYear;
    }

    University(const University& other) : name{other.name}, subject(other.subject), foundationYear{other.foundationYear}, p{other.p}, s{other.s} {
        std::cout << "Creating University via copy-constructor.\n";
    }

    University& operator = (const University &other) {
        name = other.name;
        subject = other.subject;
        foundationYear = other.foundationYear;
        p = other.p;
        s = other.s;
        std::cout << "University Operator =\n";
        return *this;
    }

    ~University() {
        std::cout << "Destructing the university.\n";
    }

    /*std::string get_name() { return this -> name; }
    std::string get_subject() { return this -> subject; }
    int get_foundationYear() { return this -> foundationYear; }
    std::vector<Student> get_students() { return this -> s; }*/

    void print() {
        std::cout << this -> name << " cu specializarea " << this -> subject << " a fost fondata in anul " << this -> foundationYear << ".\nAre un cumul de 500 profesori de exceptie printre care si " << (this -> p)[2].get_name() << "\n";
    }

    void add_professor(const Professor& other) {
        (this -> p).push_back(other);
    }

    void add_student(const Student& other) {
        (this -> s).push_back(other);
    }

    void add_vectorOfProfessors(const std::vector<Professor>& other) {
        for(auto& pr : other)
            (this -> p).push_back(pr);
    }

    void add_vectorOfStudents(const std::vector<Student>& other) {
        for(auto& st : other)
            (this -> s).push_back(st);
    }

    void print_students() {
        for(auto c : this -> s)
            c.print();
    }

    void print_professors() {
        for(auto c : this -> p)
            c.print();
    }

    void reclassify() {
        sort((this -> s).begin(), (this -> s).end(), [](Student s1, Student s2) { return(s1.get_overallAverage() > s2.get_overallAverage()); });
        unsigned count = 1;
        for(Student& c: this -> s) {
            c.set_id(int(count));
            c.set_tuitionFree((count++ <= ((this -> s).size() * 80 /100)));
        }
    }
};


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