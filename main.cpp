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
    Professor(const std::string& name, const std::string& subject, const std::string& email, const std::string& phoneNumber, const int& age) {
        this -> name = name;
        this -> subject = subject;
        this -> email = email;
        this -> phoneNumber = phoneNumber;
        this -> age = age;
        std:: cout << "Creating the Professor from a regular-constructor.\n";
    }
    Professor(const Professor& other) : name{other.name}, subject{other.subject}, email{other.email}, phoneNumber{other.phoneNumber}, age{other.age} {
         std:: cout << "Creating the Professor from a copy-constructor.\n";
    }
    Professor& operator = (const Professor& other) {
        name = other.name;
        subject = other.subject;
        email = other.email;
        phoneNumber = other.phoneNumber;
        age = other.age;
         std:: cout << "Operator Professor =\n";
        return *this;
    }
    ~Professor() {
         std::cout << "Killing the professor.\n";
    }
    [[maybe_unused]] std::string get_name() { return this -> name; }
    [[maybe_unused]] std::string get_subject() { return this -> subject; }
    [[maybe_unused]] std::string get_email() { return this -> email; }
    [[maybe_unused]] std::string get_phoneNumber() { return this -> phoneNumber; }
    [[maybe_unused]] int get_age() { return this -> age; }
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
    Student(const std::string& name, const std::string& email, const std::string& phoneNumber, const int& group, const int& age, const bool& tuitionFree) {
        this -> name = name;
        this -> email = email;
        this -> phoneNumber = phoneNumber;
        this -> group = group;
        this -> age = age;
        this -> tuitionFree = tuitionFree;
        std:: cout << "Creating the Student from a regular-constructor.\n";
    }
    Student(const Student& other) : name{other.name}, email{other.email}, phoneNumber{other.phoneNumber}, group{other.group}, age{other.age}, tuitionFree{other.tuitionFree} {
         std:: cout << "Creating the Student from a copy-constructor.\n";
    }
    Student& operator = (const Student& other) {
        name = other.name;
        email = other.email;
        phoneNumber = other.phoneNumber;
        group = other.group;
        age = other.age;
        tuitionFree = other.tuitionFree;
         std:: cout << "Operator Student =\n";
        return *this;
    }
    ~Student() {
         std::cout << "Killing the student.\n";
    }
    [[maybe_unused]] std::string get_name() { return this -> name; }
    [[maybe_unused]] std::string get_email() { return this -> email; }
    [[maybe_unused]] std::string get_phoneNumber() { return this -> phoneNumber; }
    [[maybe_unused]] int get_group() { return this -> group; }
    [[maybe_unused]] int get_age() { return this -> age; }
    [[maybe_unused]] bool get_tuitionFree() { return this -> tuitionFree; }
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
    University(const std::string& name, const std::string& subject, const int& foundationYear, const int& numberOfProfessors, const int& numberOfStudents, const std::vector<Professor>& p, const std::vector<Student>& s) {
        this -> name = name;
        this -> subject = subject;
        this -> foundationYear = foundationYear;
        this -> numberOfProfessors = numberOfProfessors;
        this -> numberOfStudents = numberOfStudents;
        this -> p = p;
        this -> s = s;
        std:: cout << "Building the University from a regular-constructor.\n";
    }
    University(const std::string& name, const std::string& subject, const int& foundationYear, const int& numberOfProfessors, const int& numberOfStudents) {
        this -> name = name;
        this -> subject = subject;
        this -> foundationYear = foundationYear;
        this -> numberOfProfessors = numberOfProfessors;
        this -> numberOfStudents = numberOfStudents;
        std:: cout << "Building the University from a regular-constructor.\n";
    }
    University(const University& other) : name{other.name}, subject(other.subject), foundationYear{other.foundationYear}, numberOfProfessors{other.numberOfProfessors}, numberOfStudents{other.numberOfStudents}, p{other.p}, s{other.s} {
         std:: cout << "Building the University from a copy-constructor.\n";
    }
    University& operator = (const University &other) {
        name = other.name;
        subject = other.subject;
        foundationYear = other.foundationYear;
        numberOfProfessors = other.numberOfProfessors;
        numberOfStudents = other.numberOfStudents;
        p = other.p;
        s = other.s;
         std:: cout << "Operator University =\n";
        return *this;
    }
    ~University() {
         std:: cout << "Destructing the University.\n";
    }
    [[maybe_unused]] std::string get_name() { return this -> name; }
    [[maybe_unused]] std::string get_subject() { return this -> subject; }
    [[maybe_unused]] int get_foundationYear() { return this -> foundationYear; }
    void print() {
        std::cout << this -> name << " cu specializarea " << this -> subject << " a fost fondata in anul " << this -> foundationYear << ".\nAre un cumul de " << this -> numberOfProfessors << " de profesori de exceptie printre care si " << (this -> p)[0].get_name() << "\n";
    }
    void add_professor(const Professor& other) {
        (this -> p).push_back(other);
    }
    void add_student(const Student& other) {
        (this -> s).push_back(other);
    }
};


int main() {
    University unibuc("Universitatea din Bucuresti", "Matematica si Informatica", 1864, 500, 4000);
    unibuc.add_professor(Professor("Gigel Militaru", "Matematica", "gigel.militaru@s.unibuc.ro", "123", 50));
    unibuc.add_student(Student("Gigel Soldatu", "gigel.soldatu@s.unibuc.ro", "0711223344", 262, 19, true));
    unibuc.print();

    return 0;
}