#include "assignment.h"

Assignment::Assignment(std::string name, double max) {
    assignment_name = name;
    max_grade = max;
}

void Assignment::add_grade(std::string id, double grade) {
    if (grade < 0) {
        throw std::invalid_argument("Error: Can't have a negative grade.");
    }

    grades.insert({id, grade});
}

std::string Assignment::get_name() const {
    return assignment_name;
}

double Assignment::get_grade(std::string id) const {
    if ( grades.contains(id) ) {
        return grades.at(id);
    } else {
        throw std::invalid_argument("Error: Can't find grade for id: " + id + ".");
    }
}