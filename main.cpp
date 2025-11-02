#include <iostream>

#include "src/gradebook.hpp"

// This main.cpp is used to show how you would utilize the
// Gradebook class. It does not have a working menu for the
// user to interact with and is just a demonstration of how
// Gradebook works.

int main() {
    Gradebook gradebook;

    // Adding Students.
    // Need to be the following: First Name, Last Name, ID
    try {
        gradebook.add_student("JT", "Gutman", "H0046733");
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    try {
        gradebook.add_student("Vic", "Krol", "H0012299");
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    try {
        gradebook.add_student("Blue", "Bailey", "H0033495");
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    try {
        gradebook.add_student("Grace", "Ziomek", "H0053112");
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    // Will throw an exception if you try to add a student with the same ID
    try {
        gradebook.add_student("JT", "Gutman", "H0046733");
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    // Adding Assignments.
    // Need to be the following: Assignment Name, Max Grade
    try {
        gradebook.add_assignment("Unit 1 Exam", 100);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    try {
        gradebook.add_assignment("9.3 Homework", 20);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    try {
        gradebook.add_assignment("9.4  Homework", 20);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    // Will throw an exception if you add an assignment with the same name
    try {
        gradebook.add_assignment("9.4  Homework", 20);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    // Adding each student's grades.
    // Need to be the following: Assignment Name, ID, Grade

    // Adding JT's grades
    try {
        gradebook.add_grade("Unit 1 Exam", "H0046733", 93);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    try {
        gradebook.add_grade("9.3 Homework", "H0046733", 19);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    try {
        gradebook.add_grade("9.4  Homework", "H0046733", 16);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    // Adding Vic's grades
    try {
        gradebook.add_grade("Unit 1 Exam", "H0012299", 62);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    try {
        gradebook.add_grade("9.4  Homework", "H0012299", 18.5);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    // Adding Blue's grades
    try {
        gradebook.add_grade("Unit 1 Exam", "H0033495", 102);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    try {
        gradebook.add_grade("9.3 Homework", "H0033495", 0);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    try {
        gradebook.add_grade("9.4  Homework", "H0033495", 6.5);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    // Adding Grace's grades
    try {
        gradebook.add_grade("9.3 Homework", "H0053112", 91.5);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    try {
        gradebook.add_grade("9.4  Homework", "H0053112", 20);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    // Will throw an exception if you add a grade for an Assignment that doesn't exist
    try {
        gradebook.add_grade("Unit 2 Exam", "H0053112", 91.5);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    // Will throw an exception if you add a grade for a Student that doesn't exist
    try {
        gradebook.add_grade("Unit 1 Exam", "ABC123", 91.5);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    // Will throw an exception if you try to add a negative grade
    try {
        gradebook.add_grade("Unit 1 Exam", "H0053112", -22.5);
    } catch (const std::invalid_argument& ia) {
        std::cout << ia.what() << std::endl;
    }

    std::cout << std::endl << gradebook.report();

    return 0;
}
