#include <iostream>
#include <vector>

class Professor {
private:
    std::string name = "Unknown";
    std::string subject = "Unknown";
    std::string email = "Unknown";
    std::string phoneNumber = "Unknown";
    int age = 0;

public:
    Professor() = default;
    Professor(const std::string name, const std::string subject, const std::string email, const std::string phoneNumber, const int age) {
        this -> name = name;
        this -> subject = subject;
        this -> email = email;
        this -> phoneNumber = phoneNumber;
        this -> age = age;
    }
    Professor(const Professor& other) : name{other.name}, subject{other.subject}, email{other.email}, phoneNumber{other.phoneNumber}, age{other.age} {
        // std:: cout << "Creating the Professor from a copy-constructor.\n";
    }
    Professor& operator = (const Professor& other) {
        name = other.name;
        subject = other.subject;
        email = other.email;
        phoneNumber = other.phoneNumber;
        age = other.age;
        // std:: cout << "Operator Professor =\n";
        return *this;
    }
    ~Professor() {
        // std::cout << "Killing the professor.\n";
    }
    std::string get_name() { return this -> name; }
    std::string get_subject() { return this -> subject; }
    std::string get_email() { return this -> email; }
    std::string get_phoneNumber() { return this -> phoneNumber; }
    int get_age() { return this -> age; }
};

class Student {
private:
    std::string name = "Unknown";
    std::string email = "Unknown";
    std::string phoneNumber = "Unknown";
    int group = 0;
    int age = 0;
    bool tuitionFree = false;

public:
    Student() = default;
    Student(const std::string name, const std::string email, const std::string phoneNumber, const int group, const int age, const bool tuitionFree) {
        this -> name = name;
        this -> email = email;
        this -> phoneNumber = phoneNumber;
        this -> group = group;
        this -> age = age;
        this -> tuitionFree = tuitionFree;
    }
    Student(const Student& other) : name{other.name}, email{other.email}, phoneNumber{other.phoneNumber}, group{other.group}, age{other.age}, tuitionFree{other.tuitionFree} {
        // std:: cout << "Creating the Student from a copy-constructor.\n";
    }
    Student& operator = (const Student& other) {
        name = other.name;
        email = other.email;
        phoneNumber = other.phoneNumber;
        group = other.group;
        age = other.age;
        tuitionFree = other.tuitionFree;
        // std:: cout << "Operator Student =\n";
        return *this;
    }
    ~Student() {
        // std::cout << "Killing the student.\n";
    }
    std::string get_name() { return this -> name; }
    std::string get_email() { return this -> email; }
    std::string get_phoneNumber() { return this -> phoneNumber; }
    int get_group() { return this -> group; }
    int get_age() { return this -> age; }
    bool get_tuitionFree() { return this -> tuitionFree; }
};

class University {
private:
    std::string name;
    std::string subject;
    int foundationYear;
    int numberOfProfessors;
    int numberOfStudents;
    std::vector<Professor> p;
    std::vector<Student> s;

public:
    University(const std::string name, const std::string subject, const int foundationYear, const int numberOfProfessors, const int numberOfStudents, const std::vector<Professor> p, const std::vector<Student> s) {
        this -> name = name;
        this -> subject = subject;
        this -> foundationYear = foundationYear;
        this -> numberOfProfessors = numberOfProfessors;
        this -> numberOfStudents = numberOfStudents;
        this -> p = p;
        this -> s = s;
    }
    University(const University& other) : name{other.name}, subject(other.subject), foundationYear{other.foundationYear}, p{other.p}, s{other.s} {
        // std:: cout << "Building the University from a copy-constructor.\n";
    }
    University& operator = (const University &other) {
        name = other.name;
        subject = other.subject;
        foundationYear = other.foundationYear;
        p = other.p;
        s = other.s;
        // std:: cout << "Operator University =\n";
        return *this;
    }
    ~University() {
        // std:: cout << "Destructing the University.\n";
    }
    std::string get_name() { return this -> name; }
    std::string get_subject() { return this -> subject; }
    int get_foundationYear() { return this -> foundationYear; }
    void print() {
        std::cout << this -> name << " cu specializarea " << this -> subject << " a fost fondata in anul " << this -> foundationYear << ".\nAre un cumul de " << this -> numberOfProfessors << " de profesori de exceptie printre care si " << (this -> p)[0].get_name();
    }
};


int main() {
    std::vector<Professor> p;
    Professor p1("Gigel Militaru", "Matematica", "gigel.militaru@s.unibuc.ro", "0722113344", 50);
    Professor p2("Gigel Militianu", "Informatica", "gigel.militianu@s.unibuc.ro", "0722113355", 70);
    p.push_back(p1);
    p.push_back(p2);

    std::vector<Student> s;
    Student s1("Gigel Soldatu", "gigel.soldatu@s.unibuc.ro", "0711223344", 262, 19, true);
    Student s2("Gigel Copoiu", "gigel.copoiu@s.unibuc.ro", "0711223311", 261, 20, false);
    s.push_back(s1);
    s.push_back(s2);

    University unibuc("Universitatea din Bucuresti", "Matematica si Informatica", 1864, 500, 4000, p, s);
    unibuc.print();
    return 0;
}