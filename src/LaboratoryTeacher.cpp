//
// Created by Adrian Leventiu on 16.11.2022.
//

#include "../headers/LaboratoryTeacher.h"
#include <fstream>
#include <filesystem>

LaboratoryTeacher::LaboratoryTeacher() : Professor() {}

LaboratoryTeacher::LaboratoryTeacher(const std::string &firstName, const std::string &lastName, const std::string &subject, const std::string &email, const std::string &phoneNumber, const int &birthDay, const int &birthMonth, const int &birthYear) : Professor(firstName, lastName, subject, email, phoneNumber, birthDay, birthMonth, birthYear) {}

LaboratoryTeacher::LaboratoryTeacher(const LaboratoryTeacher& other) : Professor(other) {}

std::shared_ptr<Professor> LaboratoryTeacher::clone() const {
    return std::make_shared<LaboratoryTeacher>(*this);
}

std::ostream &operator<<(std::ostream &os, const LaboratoryTeacher &other) {
    os << dynamic_cast<const Professor&>(other);
    other.print(os);

    return os;
}

void LaboratoryTeacher::createExam(const std::string &classSubject) {
    std::filesystem::create_directory("./exams/laboratory/" + classSubject);
    std::ofstream printQuestions("./exams/laboratory/" + classSubject + "/questions.txt");
    std::ofstream printAnswers("./exams/laboratory/" + classSubject + "/answers.txt");

    int counter = 0;
    std::string question, answer, possibleAnswers;
    char choice;

    std::cout << "You'll start creating the exam.\n";
    while (true) {
        counter++;

        std::cout << "Question: ";
        std::getline(std::cin >> std::ws, question);

        std::cout << "Possible answers: ";
        std::getline(std::cin >> std::ws, possibleAnswers);

        std::cout << "Correct answer (A/B/C/D/...): ";
        std::cin >> answer;

        printQuestions << counter << ". " << question << "\n" << possibleAnswers << "\n";
        printAnswers << counter << ". " << answer << "\n";

        std::cout << "Do you want to type another question?\n(Y/N): ";
        std::cin >> choice;

        while (choice != 'Y' && choice != 'N' && choice != 'y' && choice != 'n') {
            std::cout << "Asked for Y or N. Try again.\n";
            std::cin >> choice;
        }

        if(choice == 'N' || choice == 'n')
            break;
    }
}

void LaboratoryTeacher::print([[maybe_unused]] std::ostream &os) const {
    os << "Laboratory subject: " << get_subject() << "\n\n";
}

LaboratoryTeacher::~LaboratoryTeacher() {}