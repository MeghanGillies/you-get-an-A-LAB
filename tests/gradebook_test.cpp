#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/gradebook.hpp"

// Tests on add_student() method
TEST_CASE( "add_student() adds a new student object to the map" ) {
    Gradebook gradebook;

    // These pass since the add_student() method returns the size of the map of students when successful
    REQUIRE( gradebook.add_student("John", "Smith", "123456") == 1 );
    REQUIRE( gradebook.add_student("James", "Turner", "789101") == 2 );
    REQUIRE( gradebook.add_student("Hailey", "Johnson", "ABCD123") == 3 );
}

TEST_CASE( "add_student() will throw an exception if the student ID has already been used" ) {
    Gradebook gradebook;

    gradebook.add_student("John", "Smith", "123456");
    REQUIRE_THROWS_AS( gradebook.add_student("John", "Smith", "123456"), std::invalid_argument );
}

// Tests on add_assignment() method
TEST_CASE( "add_assignment() adds a new assignment object to the map" ) {
    Gradebook gradebook;

    // These pass since the add_assignment() method returns the size of the map of assignments when successful
    REQUIRE(gradebook.add_assignment("Quiz 1", 50) == 1);
    REQUIRE(gradebook.add_assignment("Exam 1", 100) == 2);
    REQUIRE(gradebook.add_assignment("Soil Sample Lab", 30) == 3);
}

TEST_CASE( "add_assignment() will throw an exception if the assignment name has already been used" ) {
    Gradebook gradebook;
    gradebook.add_assignment("Exam 1", 50);

    REQUIRE_THROWS_AS( gradebook.add_assignment("Exam 1", 50), std::invalid_argument );
}

// Tests on add_grade() method
TEST_CASE( "add_grade() will add a grade to the gradebook" ) {
    Gradebook gradebook;
    gradebook.add_student("John", "Smith", "123456");
    gradebook.add_assignment("Exam 1", 50);

    REQUIRE_NOTHROW( gradebook.add_grade("Exam 1", "123456", 20) );
}

TEST_CASE( "add_grade() throws exception if the student doesn't exist" ) {
    Gradebook gradebook;
    gradebook.add_student("John", "Smith", "123456");
    gradebook.add_assignment("Exam 1", 50);

    REQUIRE_THROWS_AS( gradebook.add_grade("Exam 1", "5678910", 20), std::invalid_argument );
}

TEST_CASE( "add_grade() throws exception if the assignment doesn't exist" ) {
    Gradebook gradebook;
    gradebook.add_student("John", "Smith", "123456");
    gradebook.add_assignment("Exam 1", 50);

    REQUIRE_THROWS_AS( gradebook.add_grade("Quiz 1", "123456", 20), std::invalid_argument );
}

TEST_CASE( "add_grade() throws an exception if you enter a negative grade" ) {
    Gradebook gradebook;
    gradebook.add_student("John", "Smith", "123456");
    gradebook.add_assignment("Exam 1", 50);

    REQUIRE_THROWS_AS( gradebook.add_grade("Exam 1", "123456", -10), std::invalid_argument );
}

// Tests on report() method
TEST_CASE( "report() returns a formatted empty gradebook" ) {
    Gradebook gradebook;
    REQUIRE(gradebook.report() == "Last Name      First Name     ID          \n" );
}

TEST_CASE( "report() returns a formatted gradebook with 1 assignment" ) {
    Gradebook gradebook;
    gradebook.add_assignment("Exam 1", 50);

    REQUIRE(gradebook.report() == "Last Name      First Name     ID          Exam 1         \n" );
}

TEST_CASE( "report() returns a formatted gradebook with 1 student" ) {
    Gradebook gradebook;
    gradebook.add_student("John", "Smith", "123456");

    REQUIRE( gradebook.report() == "Last Name      First Name     ID          \nSmith          John           123456      \n" );
}

TEST_CASE( "report() returns a formatted gradebook with 1 student, 1 assignment, and no entered grades" ) {
    Gradebook gradebook;
    gradebook.add_student("John", "Smith", "123456");
    gradebook.add_assignment("Exam 1", 50);

    REQUIRE( gradebook.report() == "Last Name      First Name     ID          Exam 1         \nSmith          John           123456      N/A            \n" );
}

TEST_CASE( "report() returns a formatted gradebook with 1 student, 1 assignment, and an entered grade" ) {
    Gradebook gradebook;
    gradebook.add_student("John", "Smith", "123456");
    gradebook.add_assignment("Exam 1", 50);
    gradebook.add_grade("Exam 1", "123456", 20);

    REQUIRE( gradebook.report() == "Last Name      First Name     ID          Exam 1         \nSmith          John           123456      20             \n" );
}

TEST_CASE( "report() returns a formatted gradebook" ) {
    Gradebook gradebook;
    gradebook.add_student("John", "Smith", "123456");
    gradebook.add_student("Jane", "Doe", "ABC123");

    gradebook.add_assignment("Exam 1", 50);
    gradebook.add_grade("Exam 1", "123456", 20);
    gradebook.add_grade("Exam 1", "ABC123", 45.5);

    gradebook.add_assignment("Midterm", 100);
    gradebook.add_grade("Midterm", "123456", 77);
    gradebook.add_grade("Midterm", "ABC123", 89);

    REQUIRE( gradebook.report() == "Last Name      First Name     ID          Exam 1         Midterm        \nSmith          John           123456      20             77             \nDoe            Jane           ABC123      45.5           89             \n" );
}