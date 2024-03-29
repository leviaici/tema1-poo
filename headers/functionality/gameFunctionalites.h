//
// Created by Adrian Leventiu on 03.11.2022.
//

#ifndef OOP_GAMEFUNCTIONALITES_H
#define OOP_GAMEFUNCTIONALITES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>
#include <memory>
#include <filesystem>

#include "functionalities.h"
#include "../Exceptions.h"

void loginAccount(int counter);
void registerAccount();

std::string getPassword(bool mode) { // true - password, false - verify password
    int counter = 0;
    int x, y;
    std::string password;
    float complexity = 100;

    while (true) {
        rlutil::cls();

        if (mode) {
            complexity = checkPasswordComplexity(password);
            printComplexity(int(complexity), password);
            x = 11; y = 4;
            rlutil::locate(1, 4);
            std::cout << "Password: ";
        } else {
            x = 18; y = 1;
            std::cout << "Verify password: ";
        }
        rlutil::locate(x, y);
        for (int i = 0; i < counter; i++) {
            std::cout << "*";
            ++x;
        }
        rlutil::locate(x, y);
        unsigned char ch = getch();
        if (ch == 127 || ch == 8) {
            if( password.length() > 0) {
                --x;
                --counter;
                rlutil::locate(x,y);
                std::cout << " ";
                password.erase(password.length() - 1);
            }
        } else if (ch == '\n') {
            if (!mode)
                break;
            if (complexity >= 50 && password.size() >= 10)
                break;
            else continue;
        } else if (ch != ' ') {
            counter++;
            std::cout << '*';
            password += ch;
        }
    }
    return password;
}

std::string checkAccountType(std::string accountType) {
    if (accountType == "student" || accountType == "professor")
        return accountType;

    if (accountType.substr(0, 2) == "st")
        return "student";

    if (accountType.substr(0, 2) == "pr")
        return "professor";

    return "wrong";
}

void blockUser(int counter) {
    std::cout << "I am sorry to inform you but you are now being blocked from trying to log back in.\n";
    for (int i = counter * 20; i >= 1; i--) {
        std::cout << "You have " << i << " seconds left until you can try and log in again.\r" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "\r" << std::flush;
    ignoreReading();
    std::cout << "You can try to log back in now as your cooldown expired.\n";
}

void createProfessorSavingsFile(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& password, const std::string& subject, const std::string& phoneNumber, const int& birthDay, const int& birthMonth, const int& birthYear, const std::string& type) {
    std::ofstream print("savings/professors/" + email + ".txt");

    print << email + "\n" + password + "\n" + firstName + "\n" + lastName + "\n" + subject + "\n" + type + "\n" + phoneNumber + "\n" << birthDay << "\n" << birthMonth << "\n" << birthYear << "\n";
    print.close();
}
void createStudentSavingsFile(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& password, const std::string& phoneNumber, const int& group, const int& birthDay, const int& birthMonth, const int& birthYear, const std::vector<Subject>& subjects) {
    std::ofstream print("savings/students/" + email + ".txt");

    print << email + "\n" + password + "\n" + firstName + "\n" + lastName + "\n" + phoneNumber + "\n" << group << "\n" << birthDay << "\n" << birthMonth << "\n" << birthYear << "\n";

    for (const auto& subject: subjects) {
        print << subject.get_subject() << "\n" << "Grades: ";
        for (const auto& grade: subject.get_grades())
            print << grade << " ";
        print << "\n" << "Average: " << subject.get_average() << "\n";
        print << "Passed/Failed (1/0): " << subject.get_passed() << "\n\n";
    }

    print.close();
}

bool checkExistingAccount(const std::string& email, const std::string& accountType) {
    std::ifstream open("savings/" + accountType + "s/" + email + ".txt");
    return bool(open);
}

void printError(const std::string& error) {
    rlutil::setColor(12);
    std::cout << error;
}

void readBirthDate(int &birthDay, int &birthMonth, int &birthYear) {
    char unused1, unused2;
    std::cout << "When were you born? DD/MM/YYYY\n";
    std::cin >> birthDay >> unused1 >> birthMonth >> unused2 >> birthYear;

    while (!(birthMonth > 0 && birthMonth < 13)) {
        std::cout << "Invalid month. Try again.\nMonth: ";
        std::cin >> birthMonth;
    }

    while (!(birthDay > 0 && birthDay < 32)) {
        std::cout << "Invalid birthday. Try again.\nDay: ";
        std::cin >> birthDay;
    }

    try {
        if (birthYear < 1900)
            throw errorDead("Oh... you are dead, so... Goodbye and rest in peace.\n");

        if (birthYear >= localYear() && birthMonth >= localMonth()) {
            if (birthMonth == localMonth() && birthDay > localDay()) {
                throw errorNotBorn("Oh... you are not born yet so wait a little bit more for this.\n");
            } else throw errorYoung("Oh... you are too young for this.\n");
        }

        if (localYear() - birthYear <= 17)
            throw errorYoung("Oh... you are too young for this.\n");

        if (birthDay == 29 && birthMonth == 2 && birthYear % 4)
            throw error29("Check your birthday again and try again.\nYour birth year didn't have any 29th February.\n");

        if (birthDay == 31 && !(birthMonth % 2) && birthMonth < 7)
            throw error31st("Check your birthday again and try again.\nYour birth month didn't have any 31st.\n");

        if (birthDay == 31 && birthMonth % 2 && birthMonth > 8)
            throw error31st("Check your birthday again and try again.\nYour birth month didn't have any 31st.\n");

    } catch (error31st &e) {
        printError(e.what());
        exit(1);
    } catch (errorYoung &e) {
        printError(e.what());
        exit(1);
    } catch (errorDead &e) {
        printError(e.what());
        exit(1);
    } catch (errorNotBorn &e) {
        printError(e.what());
        exit(1);
    } catch (error29 &e) {
        printError(e.what());
        exit(1);
    }
}


void greetings(const std::string& firstName, const std::string& email) {
    std::cout << "Nice to meet you, " << firstName << "!\n";

    std::cout << "Here's your brand new generated e-mail: " << email << "\n";

    std::cout << "Key note if you ever forget your e-mail. It's your firstName.lastName@s.unibuc.ro\n";
    std::cout << "If you have 2 first names, it's going to be firstName1-firstName2.lastName@s.unibuc.ro\n";
}

void readPhoneNumber(std::string &phoneNumber) {
    std::cout << "What's your phone number?\n";
    std::cin >> phoneNumber;

    while (phoneNumber.size() < 10) {
        std::cout << "Invalid phone number. Try again.\nPhone number: ";
        std::cin >> phoneNumber;
    }
}

void finalPrintRegistration() {
    std::cout << "Great! Now, when you'll want to login you'll need to enter your data as it is like in the example below:\n";
    std::cout << "E-mail: generated_email@s.unibuc.ro\n";
    std::cout << "Password: yourPasswordHere\n";
}

void readInputPassword(std::string &password) {
    std::cin.ignore();
    password = getPassword(true);
    std::string passwordVerification = getPassword(false);
    rlutil::cls();

    while (password != passwordVerification) {
        std::cout << "Passwords don't match. Try again!\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        password = getPassword(true);
        passwordVerification = getPassword(false);
        rlutil::cls();
    }
}

void readProfessorType(std::string& type) {
    type = toLowerWholeWord(type);

    while ((type[0] != 's' || type[1] != 'e') && (type[0] != 'l' || type[1] != 'a') && (type[0] != 'c' || type[1] != 'o')) {
        std::cout << "Seminar/Laboratory/Course:\n";
        std::cin >> type;
    }

    if (type.substr(0, 2) == "se")
        type = "seminar";
    else if (type.substr(0, 2) == "la")
        type = "laboratory";
    else if (type.substr(0, 2) == "co")
        type = "course";
}

void registerProfessorAccount(const std::string& firstName, const std::string& lastName, const std::string& email) {
    std::string phoneNumber = " ", subject, type;
    int birthDay = 0, birthMonth = 0, birthYear = 0;

    greetings(firstName, email);

    readPhoneNumber(phoneNumber);

    std::cout << "What is the subject you are teaching students?\n";
    std::getline(std::cin >> std::ws, subject);

    std::cout << "Seminar/Laboratory/Course:\n";
    std::cin >> type;

    readProfessorType(type);

    readBirthDate(birthDay, birthMonth, birthYear);

    std::cout << "Great! Now the next and final step...\nLet's choose a password!\n";

    std::string password;
    readInputPassword(password);

    createProfessorSavingsFile(firstName, lastName, email, password, subject, phoneNumber, birthDay, birthMonth, birthYear, type);

    finalPrintRegistration();
}
void registerStudentAccount(const std::string& firstName, const std::string& lastName, const std::string& email) {
    std::string phoneNumber = " ";
    int group, birthDay = 0, birthMonth = 0, birthYear = 0;

    greetings(firstName, email);

    readPhoneNumber(phoneNumber);

    std::cout << "What group were you assigned to?\n";
    std::cin >> group;

    while (!group) {
        std::cout << "Invalid group. Try again.\nGroup: ";
        std::cin >> phoneNumber;
    }

    readBirthDate(birthDay, birthMonth, birthYear);

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

    std::cout<< "Super! Now that we completed all these steps, we have one last step and we finished the registration!\nLet's choose a password!\n";

    std::string password;
    readInputPassword(password);

    createStudentSavingsFile(firstName, lastName, email, password, phoneNumber, group, birthDay, birthMonth, birthYear, subjects);

    finalPrintRegistration();
}

void registerAccount() {
    rlutil::cls();
    std::string firstName, lastName, email, accountType;

    std::cout << "Let's start creating your brand new account!\nAre you a student or a professor?\n";
    std::cin >> accountType;
    accountType = checkAccountType(toLowerWholeWord(accountType));

    if (accountType == "wrong") {
        std::cout << "Wrong input of account type. You needed to choose between being a student or a professor.\n";
        while (accountType == "wrong") {
            std::cout << "Let's try again. Are you a student or a professor?\n";
            std::cin >> accountType;
            accountType = checkAccountType(toLowerWholeWord(accountType));
        }
    }

    std::cout << "Great! Now... what's your name?\n";
    std::cin >> firstName >> lastName;

    email = toLower(firstName) + "." + toLowerWholeWord(lastName) + "@s.unibuc.ro";

    if (checkExistingAccount(email, accountType)) {
        char choice;
        std::cout << "Account already exists. Do you want to login?\nY/N: ";
        std::cin >> choice;
        if (choice == 'Y' || choice == 'y')
            loginAccount(1);
        return;
    }else {
        if (accountType == "student")
            registerStudentAccount(firstName, lastName, email);
        else registerProfessorAccount(firstName, lastName, email);
    }

    std::cout << "Do you want now to login?\n(Y/N): ";
    char choice;
    std::cin >> choice;
    while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
        std::cout << "Asked for Y or N. Try again, please.\n";
        std::cin >> choice;
    }
    if (choice == 'y' || choice == 'Y')
        loginAccount(1);
}

void deleteAccount(const std::string& email, const std::string& password) {
    rlutil::cls();
    char choice;
    std::cout << "Are you sure you want to permanently delete your account?\n(Y/N): ";
    std::cin >> choice;

    while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
        std::cout << "Asked for Y or N. Try again, please.\n";
        std::cin >> choice;
    }

    if (choice == 'y' || choice == 'Y') {
        std::cout << "Enter the password for confirmation and your account will be deleted as you wish.\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cin.ignore();
        std::string passwordVerification = getPassword(false);
        rlutil::cls();

        int counter = 0;
        while (passwordVerification != password) {
            std::cout << "Wrong password.\n";
            counter++;
            if (!(counter % 3))
                blockUser(counter);
            std::cout << "Try again typing your password to confirm the account deletion.\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            passwordVerification = getPassword(true);
            rlutil::cls();
        }

        std::string accountType;
        if (checkExistingAccount(email, "student"))
            accountType = "student";
        else accountType = "professor";

        std::cout << "Deleting account...\n";
        try { // DE IMPLEMENTAT INDICATORS AICI
            std::string path = "savings/" + accountType + "s/" + email + ".txt";
            const char* filePath = path.c_str(); /// PENTRU CA NU MA LASA CU std::filesystem::remove() MA IMPUSC

            if ((remove(filePath)))
                throw std::exception();
            std::cout << "Account deletion complete. All your data have been erased.\n";
        } catch (std::exception& e) {
            std::cout << e.what();
            std::cout << " Error 404: Account deletion incomplete as file was not found.\n";
        }
    }
}

void loginAccount(int counter) {
    rlutil::cls();
    std::string email, password;
    std::cout << "E-mail: ";    std::cin >> email;
    std::ifstream open("savings/students/" + email + ".txt");

    if (!open)
        open = std::ifstream("savings/professors/" + email + ".txt");
    if (!open) {
        std::cout << "This e-mail wasn't registered. Do you want to register a new account?\n(Y/N): ";
        char choice;    std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            registerAccount();
            return;
        } else if (choice == 'n' || choice == 'N')
            return;
        std::cout << "Try again.\n";
        loginAccount(1);
        return;
    }

    std::cin.ignore();
    password = getPassword(false);
    rlutil::cls();

    std::string readEmail, readPassword;
    getline(open, readEmail);
    getline(open, readPassword);

    open.close();

    if (password == readPassword) {
        bool choice;
        std::cout << "Do you want to continue the saved game (1) or do you want to delete the savings/account and start again (0)?\n(1/0): ";
        std::cin >> choice;
        if (choice)
            std::cout << "Continuing...\n"; ///TBA CONTINUING GAME FUNCTION
        else deleteAccount(email, password);
    } else {
        std::cout << "Incorrect E-mail or password. ";
        if (counter % 3) {
            std::cout << "You have " << 3 - (counter % 3);
            if (counter % 3 == 1)
                std::cout << " more attempts ";
            else std:: cout << " more attempt ";
            char choice;
            std::cout << "left before you get a cooldown. Would you like to try again?\n(Y/N): ";
            std::cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                loginAccount(++counter);
                return;
            }
            std::cout << "Would you like to register a new account?\n(Y/N): ";
            std::cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                registerAccount();
                return;
            }
            return;
        } else {
            blockUser(counter);
            loginAccount(++counter);
            return;
        }
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
    showLocalTime();
}

void registerOrLogin() {
    stART();
    char choice;
    std::cout << "Login to an already existent account or register a new one?\n(L/R): ";
    std::cin >> choice;

    while (choice != 'l' && choice != 'r' && choice != 'L' && choice != 'R') {
        std::cout << "Asked for L or R... Please, try again!\n";
        std::cin >> choice;
    }

    if (choice == 'r' || choice == 'R')
        registerAccount();
    else loginAccount(1);
}

void prepareFileSystem() {
    std::filesystem::create_directory("savings");
    std::filesystem::create_directory("savings/professors");
    std::filesystem::create_directory("savings/students");
    std::filesystem::create_directory("exams");
    std::filesystem::create_directory("exams/laboratory");
    std::filesystem::create_directory("exams/course");
    std::filesystem::create_directory("exams/laboratory/questions");
    std::filesystem::create_directory("exams/laboratory/answers");
    std::filesystem::create_directory("exams/course/questions");
    std::filesystem::create_directory("exams/course/answers");
}

//void afisTest() {
//     Hide cursor
//    indicators::show_console_cursor(false);
//
//    indicators::ProgressSpinner spinner{
//            indicators::option::PostfixText{"Checking credentials"},
//            indicators::option::ForegroundColor{indicators::Color::yellow},
//            indicators::option::SpinnerStates{
//                    std::vector<std::string>{"⠈", "⠐", "⠠", "⢀", "⡀", "⠄", "⠂", "⠁"}},
//            indicators::option::FontStyles{
//                    std::vector<indicators::FontStyle>{indicators::FontStyle::bold}}};
//
//     Update spinner state
//    auto job = [&spinner]() {
//        while (true) {
//            if (spinner.is_completed()) {
//                spinner.set_option(indicators::option::ForegroundColor{indicators::Color::green});
//                spinner.set_option(indicators::option::PrefixText{"✔"});
//                spinner.set_option(indicators::option::ShowSpinner{false});
//                spinner.set_option(indicators::option::ShowPercentage{false});
//                spinner.set_option(indicators::option::PostfixText{"Authenticated!"});
//                spinner.mark_as_completed();
//                break;
//            } else
//                spinner.tick();
//            std::this_thread::sleep_for(std::chrono::milliseconds(40));
//        }
//    };
//    std::thread thread(job);
//    thread.join();
//
//     Show cursor
//    indicators::show_console_cursor(true);
//
//}

#endif //OOP_GAMEFUNCTIONALITES_H