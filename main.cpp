#include <vector>
#include <fstream>
#include <thread>
#include <chrono>

#include "headers/functionality/functionalities.h"

void loginAccount(int counter);
void registerAccount();

std::string checkAccountType(std::string accountType) {
    if(accountType == "student" || accountType == "professor")
        return accountType;
    if(accountType[0] == 's' && accountType[1] == 't')
        return "student";
    if(accountType[0] == 'p' && accountType[1] == 'r')
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
    std::cout << "You can try to log back in now as your cooldown expired.\n";
}

void createProfessorSavingsFile(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& password, const std::string& subject, const std::string& phoneNumber, const int& birthDay, const int& birthMonth, const int& birthYear) {
    std::ofstream print("savings/professors/" + email + ".txt");

    print << email + "\n" + password + "\n" + firstName + "\n" + lastName + "\n" + subject + "\n" + phoneNumber + "\n" << birthDay << "\n" << birthMonth << "\n" << birthYear << "\n";
    print.close();
}
void createStudentSavingsFile(const std::string& firstName, const std::string& lastName, const std::string& email, const std::string& password, const std::string& phoneNumber, const int& group, const int& birthDay, const int& birthMonth, const int& birthYear, const std::vector<Subject>& subjects) {
    std::ofstream print("savings/students/" + email + ".txt");

    print << email + "\n" + password + "\n" + firstName + "\n" + lastName + "\n" + phoneNumber + "\n" << group << "\n" << birthDay << "\n" << birthMonth << "\n" << birthYear << "\n";

    for(auto c1: subjects) {
        print << c1.get_subject() << "\n" << "Grades: ";
        for(auto c2: c1.get_grades())
            print << c2 << " ";
        print << "\n" << "Average: " << c1.get_average() << "\n";
        print << "Passed/Failed (1/0): " << c1.get_passed() << "\n\n";
    }

    print.close();
}

bool checkExistingAccount(const std::string& email, const std::string& accountType) {
    std::ifstream read("savings/" + accountType + "s/" + email + ".txt");
    if(read)
        return true;
    return false;
}

void registerProfessorAccount(const std::string& firstName, const std::string& lastName, const std::string& email) {
    std::string phoneNumber, subject;
    int birthDay, birthMonth, birthYear;
    char unused1, unused2;

    std::cout << "Nice to meet you, " << firstName << "!\n";

    std::cout << "Here's your brand new generated e-mail: " << email << "\n";

    std::cout << "Key note if you ever forget your e-mail. It's your firstName.lastName@s.unibuc.ro\n";
    std::cout << "If you have 2 first names, it's going to be firstName1-firstName2.lastName@s.unibuc.ro\n";

    std::cout << "What is the subject you are teaching students?\n";
    std::cin >> subject;

    std::cout << "What's your phone number?\n";
    std::cin >> phoneNumber;

    std::cout << "When were you born? DD/MM/YYYY\n";
    std::cin >> birthDay >> unused1 >> birthMonth >> unused2 >> birthYear;

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

    createProfessorSavingsFile(firstName, lastName, email, password, subject, phoneNumber, birthDay, birthMonth, birthYear);

    std::cout << "Great! Now, when you'll want to login you'll need to enter your data as it is like in the example below:\n";
    std::cout << "E-mail: generated_email@s.unibuc.ro\n";
    std::cout << "Password: yourPasswordHere\n";
}
void registerStudentAccount(const std::string& firstName, const std::string& lastName, const std::string& email) {
    std::string phoneNumber;
    int group, birthDay, birthMonth, birthYear;
    char unused1, unused2;

    std::cout << "Nice to meet you, " << firstName << "!\n";

    std::cout << "Here's your brand new generated e-mail: " << email << "\n";

    std::cout << "Key note if you ever forget your e-mail. It's your firstName.lastName@s.unibuc.ro\n";
    std::cout << "If you have 2 first names, it's going to be firstName1-firstName2.lastName@s.unibuc.ro\n";

    std::cout << "What's your phone number?\n";
    std::cin >> phoneNumber;

    std::cout << "What group were you assigned to?\n";
    std::cin >> group;

    std::cout << "When were you born? DD/MM/YYYY\n";
    std::cin >> birthDay >> unused1 >> birthMonth >> unused2 >> birthYear;

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

    createStudentSavingsFile(firstName, lastName, email, password, phoneNumber, group, birthDay, birthMonth, birthYear, subjects);

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
            loginAccount(1);
        return;
    }else {
        if(accountType == "student")
            registerStudentAccount(firstName, lastName, email);
        else registerProfessorAccount(firstName, lastName, email);
    }

    std::cout << "Do you want now to login?\n";
    char choice;
    std::cin >> choice;
    while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
        std::cout << "Asked for Y or N. Try again, please.\n";
        std::cin >> choice;
    }
    if(choice == 'y' || choice == 'Y')
        loginAccount(1);
}

void deleteAccount(const std::string& email, const std::string& password) {
    char choice;
    std::cout << "Are you sure you want to permanently delete your account?\n(Y/N): ";
    std::cin >> choice;

    while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
        std::cout << "Asked for Y or N. Try again, please.\n";
        std::cin >> choice;
    }

    if(choice == 'y' || choice == 'Y') {
        std::string passwordVerification;
        std::cout << "Enter the password for confirmation and your account will be deleted as you wish.\n";
        std::cin >> passwordVerification;

        int counter = 0;
        while(passwordVerification != password) {
            std::cout << "Wrong password.\n";
            counter++;
            if(!(counter % 3))
                blockUser(counter);
            std::cout << "Try again typing your password to confirm the account deletion.\n";
            std::cin >> passwordVerification;
        }

        std::string accountType;
        if(checkExistingAccount(email, "student"))
            accountType = "student";
        else accountType = "professor";

        std::cout << "Deleting account...\n";
        try {
            std::string path = "savings/" + accountType + "s/" + email + ".txt";
            const char* filePath = path.c_str(); /// PENTRU CA NU MA LASA CU std::filesystem::remove() MA IMPUSC

            if((remove(filePath)))
                throw std::exception();
            std::cout << "Account deletion complete. All your data have been erased.\n";
        } catch (std::exception& e) {
            std::cout << e.what();
            std::cout << " Error 404: Account deletion incomplete as file was not found.\n";
        }
    }
}

void loginAccount(int counter) {
    std::string email, password;
    std::cout << "E-mail: ";    std::cin >> email;
    std::ifstream read("savings/students/" + email + ".txt");

    if(!read)
        read = std::ifstream("savings/professors/" + email + ".txt");
    if(!read) {
        std::cout << "This e-mail wasn't registered. Do you want to register a new account?\n(Y/N): ";
        char choice;    std::cin >> choice;
        if(choice == 'y' || choice == 'Y') {
            registerAccount();
            return;
        }
        std::cout << "Try again.\n";
        loginAccount(1);
        return;
    }

    std::cout << "Password: ";  std::cin >> password;

    std::string readEmail, readPassword;
    getline(read, readEmail);
    getline(read, readPassword);

    read.close();

    if(password == readPassword) {
        bool choice;
        std::cout << "Do you want to continue the saved game (1) or do you want to delete the savings/account and start again (0)?\n(1/0): ";
        std::cin >> choice;
        if(choice)
            std::cout << "Continuing...\n"; ///TBA CONTINUING GAME FUNCTION
        else deleteAccount(email, password);
    } else {
        std::cout << "Incorrect E-mail or password. ";
        if(counter % 3) {
            std::cout << "You have " << 3 - (counter % 3);
            if(counter % 3 == 1)
                std::cout << " more attempts ";
            else std:: cout << " more attempt ";
            char choice;
            std::cout << "left before you get a cooldown. Would you like to try again?\n(Y/N): ";
            std::cin >> choice;
            if(choice == 'Y' || choice == 'y') {
                loginAccount(++counter);
                return;
            }
            std::cout << "Would you like to register a new account?\n(Y/N): ";
            std::cin >> choice;
            if(choice == 'Y' || choice == 'y') {
                registerAccount();
                return;
            }
            std::cout << "Well... Goodbye!";
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

    while(choice != 'l' && choice != 'r' && choice != 'L' && choice != 'R') {
        std::cout << "Asked for L or R... Please, try again!\n";
        std::cin >> choice;
    }

    if(choice == 'r' || choice == 'R')
        registerAccount();
    else loginAccount(1);
}

int main() {
    test();
    registerOrLogin();
//    std::vector<std::string>monthsOfYear = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//    for (int i = 0; i < 12; i++) {
//        for(int j = 1; j <= 31; j++) {
//            std::cout << j << " " << monthsOfYear[i] << "\r" << std::flush;
//            std::this_thread::sleep_for(std::chrono::milliseconds (100));
//        }
//    }
    return 0;
}///TBA birthday message