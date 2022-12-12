//
// Created by Adrian Leventiu on 06.12.2022.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class errorInput : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class error31st : public errorInput {
public:
    explicit error31st(const std::string &error) : errorInput("Error - 31st: " + error) {}
};

class errorYoung : public errorInput {
public:
    explicit errorYoung(const std::string &error) : errorInput("Error - Too Young: " + error) {}
};

class errorDead : public errorInput {
public:
    explicit errorDead(const std::string &error) : errorInput("Error - Dead: " + error) {}
};

class errorNotBorn : public errorInput {
public:
    explicit errorNotBorn(const std::string &error) : errorInput("Error - Not Born Yet: " + error) {}
};

class error29 : public errorInput {
public:
    explicit error29(const std::string &error) : errorInput("Error - 29: " + error) {}
};

#endif //OOP_EXCEPTIONS_H