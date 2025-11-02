#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

#include "gradebook.hpp"
#include "assignment.h"
#include "student.h"

// Creates a new Student Object using entered parameters
// then adds it to the map using its ID as the key
int Gradebook::add_student(std::string f_name, std::string l_name, std::string student_id) {
    if (students.contains(student_id)) {
        throw std::invalid_argument("Error: You already added a student with this ID.");
    }

    Student *s = new Student(f_name, l_name, student_id);
    students.insert({s->get_id(), s});
    return students.size(); // Returns size of students map for testing purposes
}

// Creates a new Assignment Object using entered parameters
// then adds it to the map using its name as the key
int Gradebook::add_assignment(std::string name, double max) {
    if (assignments.contains(name)) {
        throw std::invalid_argument("Error: You already added an assignment with that name.");
    }

    Assignment *a = new Assignment(name, max);
    assignments.insert({a->get_name(), a});
    return assignments.size(); // Returns size of assignments map for testing purposes
}

void Gradebook::add_grade(std::string const assignment_name, std::string const id, double const grade) {
    if ( assignments.contains(assignment_name) ) { // Check if assignment exists
        if ( students.contains(id) ) { // Check if that student exists
            // Add the student's grade to the assignment
            assignments.at(assignment_name)->add_grade(id, grade);

        } else { // Throws exception if the student doesn't exist
            throw std::invalid_argument("Error: No matching student for this ID.");
        }
    } else { // Throws exception if the assignment doesn't exist
        throw std::invalid_argument("Error: This assignment doesn't exist.");
    }
}

std::string Gradebook::report() {
    std::stringstream ss;

    // Header
    ss << std::setw(15) << std::left << "Last Name";
    ss << std::setw(15) << std::left << "First Name";
    ss << std::setw(12) << std::left << "ID";

    // Adds each assignment name to the Header
    for (const auto& [name,a] : assignments) {
        ss << std::setw(15) << std::left << name;
    }

    // Adds each row of student data
    for (const auto& [id, s] : students) {
        ss << "\n";
        ss << std::setw(15) << std::left << s->get_last_name();
        ss << std::setw(15) << std::left << s->get_first_name();
        ss << std::setw(12) << std::left << id;

        // Adds this student's grades for each assignment
        for (const auto& [name,a] : assignments) {
            try {
                ss << std::setw(15) << std::left << a->get_grade(id);
            } catch (const std::invalid_argument &ia) { // Adds N/A for empty grades
                ss << std::setw(15) << std::left << "N/A";
            }
        }
    }

    ss << "\n";

    return ss.str();
}

// Destructor: Deletes the students + assignments that were
// allocated on the heap and clears their respective maps.
Gradebook::~Gradebook() {
    for (auto const& [id, s] : students) {
        delete s; // Delete the student object
    }
    students.clear(); // Clear the map

    for (auto const& [id, a] : assignments) {
        delete a; // Delete the assignment object
    }
    assignments.clear(); // Clear the map
}