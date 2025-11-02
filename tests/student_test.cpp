#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/student.h"

TEST_CASE( "Student test accurately returns student data" ) {
    Student student("John", "Doe", "H0012345");
    REQUIRE( student.get_first_name() == "John" );
    REQUIRE( student.get_last_name() == "Doe" );
    REQUIRE( student.get_id() == "H0012345" );
}