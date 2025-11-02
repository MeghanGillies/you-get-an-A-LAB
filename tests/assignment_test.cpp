#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/assignment.h"

TEST_CASE( "Returns the name of the assignment" ) {
    Assignment assignment("Exam 1", 100);
    REQUIRE(assignment.get_name() == "Exam 1");
}

TEST_CASE( "Successfully adds a grade to the assignment" ) {
    Assignment assignment("Exam 1", 100);
    REQUIRE_NOTHROW(assignment.add_grade("ABC123", 85));
    REQUIRE(assignment.get_grade("ABC123") == 85);
}

TEST_CASE( "Throws an exception if you enter a negative grade" ) {
    Assignment assignment("Exam 1", 100);
    REQUIRE_THROWS_AS( assignment.add_grade("ABC123", -2), std::invalid_argument );
}

TEST_CASE( "Throws an exception if you try to get_grade() of an unused ID" ) {
    Assignment assignment("Exam 1", 100);
    assignment.add_grade("ABC123", 85);
    REQUIRE_THROWS_AS( assignment.get_grade("XYZ789"), std::invalid_argument );
}