#include <string>

#include "student.h"

Student::Student(std::string f_name, std::string l_name, std::string student_id) {
    first_name = f_name;
    last_name = l_name;
    id = student_id;
}

std::string Student::get_first_name() {
    return first_name;
}

std::string Student::get_last_name() {
    return last_name;
}

std::string Student::get_id() {
    return id;
}