#include <vector>
#include <fstream>
#include "headers/University.h"

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

std::string checkAccountType(std::string accountType) {
    if(accountType == "student" || accountType == "professor")
        return accountType;
    if(accountType[0] == 's' && accountType[1] == 't')
        return "student";
    if(accountType[0] == 'p' && accountType[1] == 'r')
        return "professor";
    return "wrong";
}

void test() {
    std::vector<Professor> p;

    Professor p1 = Professor("Marius", "Micluta", "Informatica", "marius.micluta@unibuc.ro", "Unknown", 23);
    Professor p2 = Professor("Radu", "Boriga", "Informatica", "radu.boriga@unibuc.ro", "Unknown", 50);
    p.push_back(p1); p.push_back(p2);

    std::vector<Student> s;

    Student s1 = Student("Adrian", "Leventiu", "adrian.leventiu@s.unibuc.ro", "Unknown", 262, 19);
    Student s2 = Student("Stefan", "Radu", "stefan.radu@s.unibuc.ro", "Unknown", 263, 19);
    s.push_back(s1); s.push_back(s2);

    University unibuc("Universitatea din Bucuresti", "Matematica si Informatica", 1864, {}, {});
    unibuc.add_professor(Professor("Liliana", "Mitre", "Matematica", "liliana.mitre@unibuc.ro", "Unknown", 35));
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

void createProfessorSavingsFile(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& password, const std::string& subject, const std::string& phoneNumber, const int& age) {
    std::ofstream print("../savings/professors/" + email + ".txt");

    print << email + "\n" + password + "\n" + firstName + "\n" + lastName + "\n" + subject + "\n" + phoneNumber + "\n" << age << "\n";
    print.close();

    Professor professor(firstName, lastName, subject, email, phoneNumber, age);
}
void createStudentSavingsFile(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& password, const std::string& phoneNumber, const int& group, const int& age, const std::vector<Subject>& subjects) {
    std::ofstream print("../savings/students/" + email + ".txt");

    print << email + "\n" + password + "\n" + firstName + "\n" + lastName + "\n" + phoneNumber + "\n" << group << "\n" << age << "\n";

    for(auto c1: subjects) {
        print << c1.get_subject() << "\n" << "Grades: ";
        for(auto c2: c1.get_grades())
            print << c2 << " ";
        print << "\n" << "Average: " << c1.get_average() << "\n";
        print << "Passed/Failed (1/0): " << c1.get_passed() << "\n\n";
    }

    print.close();

    Student student(firstName, lastName, email, phoneNumber, group, age, subjects);
}

bool checkExistingAccount(const std::string& email, const std::string& accountType) {
    std::ifstream read("../savings/" + accountType + "s/" + email + ".txt");
    if(read)
        return true;
    return false;
}

void registerProfessorAccount(const std::string& firstName, const std::string& lastName, const std::string& email) {
    std::string phoneNumber, subject;
    int age;

    std::cout << "Nice to meet you, " << firstName << "!\n";

    std::cout << "Here's your brand new generated e-mail: " << email << "\n";

    std::cout << "Key note if you ever forget your e-mail. It's your firstName.lastName@s.unibuc.ro\n";
    std::cout << "If you have 2 first names, it's going to be firstName1-firstName2.lastName@s.unibuc.ro\n";

    std::cout << "What is the subject you are teaching students?\n";
    std::cin >> subject;

    std::cout << "What's your phone number?\n";
    std::cin >> phoneNumber;

    std::cout << "How old are you?\n";
    std::cin >> age;

    std::cout << "Great! Now the next and final step...\nLet's choose a password!\n";

    std::string password, passwordVerification;
    std::cin >> password;
    std::cout << "Now let's verify the password!\n";
    std::cin >> passwordVerification;

    while (password != passwordVerification) {
        std::cout << "Passwords don't match. Try again!\n";
        std::cin >> password;
        std::cout << "Now let's verify the password!\n";
        std::cin >> passwordVerification;
    }

    createProfessorSavingsFile(firstName, lastName, email, password, subject, phoneNumber, age);

    std::cout << "Great! Now, when you'll want to login you'll need to enter your data as it is like in the example below:\n";
    std::cout << "E-mail: generated_email@s.unibuc.ro\n";
    std::cout << "Password: yourPasswordHere\n";
}
void registerStudentAccount(const std::string& firstName, const std::string& lastName, const std::string& email) {
    std::string phoneNumber;
    int group, age;

    std::cout << "Nice to meet you, " << firstName << "!\n";

    std::cout << "Here's your brand new generated e-mail: " << email << "\n";

    std::cout << "Key note if you ever forget your e-mail. It's your firstName.lastName@s.unibuc.ro\n";
    std::cout << "If you have 2 first names, it's going to be firstName1-firstName2.lastName@s.unibuc.ro\n";

    std::cout << "What's your phone number?\n";
    std::cin >> phoneNumber;

    std::cout << "What group were you assigned to?\n";
    std::cin >> group;

    std::cout << "How old are you?\n";
    std::cin >> age;

    std::cout << "Great! Now the next step...\n";

    std::vector<Subject> subjects;
    std::vector<std::string> listOfSubjects = {"Mathematics", "Computer Science", "Physics"};
    unsigned length = listOfSubjects.size();

    for (unsigned i = 0; i < length; i++) {
        int grade = -1;
        Subject subject(listOfSubjects[i], {});
        std::cout << "Tell us your grades at " + listOfSubjects[i] + ": ";

        while (grade != 0) {
            std::cin >> grade;
            subject.addGrade(grade);
        }
        subjects.push_back(subject);
    }

    std::cout<< "Super! Now that we completed all these steps, we have one last step and we finished the registration!\n";
    std::cout << "Let's choose a password!\n";

    std::string password, passwordVerification;
    std::cin >> password;
    std::cout << "Now let's verify the password!\n";
    std::cin >> passwordVerification;

    while (password != passwordVerification) {
        std::cout << "Passwords don't match. Try again!\n";
        std::cin >> password;
        std::cout << "Now let's verify the password!\n";
        std::cin >> passwordVerification;
    }

    createStudentSavingsFile(firstName, lastName, email, password, phoneNumber, group, age, subjects);

    std::cout << "Great! Now, when you'll want to login you'll need to enter your data as it is like in the example below:\n";
    std::cout << "E-mail: generated_email@s.unibuc.ro\n";
    std::cout << "Password: yourPasswordHere\n";
}

void registerAccount() {
    std::string firstName, lastName, email, accountType;

    std::cout << "Let's start creating your brand new account!\nAre you a student or a professor?\n";
    std::cin >> accountType;
    accountType = checkAccountType(toLowerWholeWord(accountType));

    if(accountType == "wrong") {
        std::cout << "Wrong input of account type. You needed to choose between being a student or a professor.\n";
        while(accountType == "wrong") {
            std::cout << "Let's try again. Are you a student or a professor?\n";
            std::cin >> accountType;
            accountType = checkAccountType(toLowerWholeWord(accountType));
        }
    }

    std::cout << "Great! Now... what's your name?\n";
    std::cin >> firstName >> lastName;

    email = toLower(firstName) + "." + toLowerWholeWord(lastName) + "@s.unibuc.ro";

    if(checkExistingAccount(email, accountType)) {
        char choice;
        std::cout << "Account already exists. Do you want to login?\nY/N: ";
        std::cin >> choice;
        if(choice == 'Y' || choice == 'y')
            //login
        return;
    }else {
        if(accountType == "student")
            registerStudentAccount(firstName, lastName, email);
        else registerProfessorAccount(firstName, lastName, email);
    }
}

void stART() {
    std::cout << " ___  ___  ________   ___  ___       ________  _________  ________  ________\n";
    std::cout << "|\\  \\|\\  \\|\\   ___  \\|\\  \\|\\  \\     |\\   __  \\|\\___   ___\\\\   __  \\|\\   __  \\\n";
    std::cout << "\\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\ \\  \\    \\ \\  \\|\\  \\|___ \\  \\_\\ \\  \\|\\  \\ \\  \\|\\  \\\n";
    std::cout << " \\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\ \\  \\    \\ \\   __  \\   \\ \\  \\ \\ \\  \\\\\\  \\ \\   _  _\\\n";
    std::cout<< "  \\ \\  \\\\\\  \\ \\  \\\\ \\  \\ \\  \\ \\  \\____\\ \\  \\ \\  \\   \\ \\  \\ \\ \\  \\\\\\  \\ \\  \\\\  \\|\n";
    std::cout << "   \\ \\_______\\ \\__\\\\ \\__\\ \\__\\ \\_______\\ \\__\\ \\__\\   \\ \\__\\ \\ \\_______\\ \\__\\\\ _\\\n";
    std::cout << "    \\|_______|\\|__| \\|__|\\|__|\\|_______|\\|__|\\|__|    \\|__|  \\|_______|\\|__|\\|__|\n\n";
    std::cout << "Hi! Welcome to Unilator, a University based Simulator!\n";
}

void loginOrRegister() {
    stART();
    char choice;
    std::cout << "Login to an already existent account or register a new one?\n(L/R): ";
    std::cin >> choice;

    while(choice != 'l' && choice != 'r' && choice != 'L' && choice != 'R') {
        std::cout << "Asked for L or R... Please, try again!\n";
        std::cin >> choice;
    }

    if(choice == 'r' || choice == 'R')
        registerAccount();
//    else loginAccount();
}

int main() {
    test();
    loginOrRegister();
    return 0;
}