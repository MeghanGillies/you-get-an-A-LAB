#pragma once

#include <string>
#include <map>

#include "student.h"
#include "assignment.h"

class Gradebook {
private:
    std::map< std::string, Student * > students;
    std::map< std::string , Assignment * > assignments;

public:
    int add_student(std::string f_name, std::string l_name, std::string student_id);
    int add_assignment(std::string name, double max);
    void add_grade(std::string assignment_name, std::string id, double grade);

    std::string report();

    ~Gradebook(); // Destructor
};