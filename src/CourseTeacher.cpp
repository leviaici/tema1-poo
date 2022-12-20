//
// Created by Adrian Leventiu on 16.11.2022.
//

#include "../headers/CourseTeacher.h"
#include <fstream>
#include <filesystem>

CourseTeacher::CourseTeacher() : Professor() {}

CourseTeacher::CourseTeacher(const std::string &firstName, const std::string &lastName, const std::string &subject, const std::string &email, const std::string &phoneNumber, const int &birthDay, const int &birthMonth, const int &birthYear) : Professor(firstName, lastName, subject, email, phoneNumber, birthDay, birthMonth, birthYear) {}

CourseTeacher::CourseTeacher(const CourseTeacher& other) : Professor(other) {}

std::shared_ptr<Professor> CourseTeacher::clone() const {
    return std::make_shared<CourseTeacher>(*this);
}

std::ostream &operator<<(std::ostream &os, const CourseTeacher &other) {
    os << dynamic_cast<const Professor&>(other);
    other.print(os);

    return os;
}

void CourseTeacher::createExam(const std::string &subject) {
    std::filesystem::create_directory("./exams/course/" + subject);
    std::ofstream printQuestions("./exams/course/" + subject + "/questions.txt");
    std::ofstream printAnswers("./exams/course/" + subject + "/answers.txt");

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

void CourseTeacher::print([[maybe_unused]] std::ostream &os) const {
    os << "Course subject: " << get_subject() << "\n\n";
}

CourseTeacher::~CourseTeacher() {}