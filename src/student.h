#pragma once

#include <string>

class Student {
private:
    std::string first_name;
    std::string last_name;
    std::string id;

public:
    Student(std::string f_name, std::string l_name, std::string student_id);
    std::string get_first_name();
    std::string get_last_name();
    std::string get_id();
};
