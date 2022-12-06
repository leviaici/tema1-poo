//
// Created by Adrian Leventiu on 06.12.2022.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <stdexcept>

class error31st : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class errorYoung : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class errorDead : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class errorNotBorn : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class error29 : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

#endif //OOP_EXCEPTIONS_H