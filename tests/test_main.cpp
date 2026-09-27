#include <catch2/catch_test_macros.hpp>
#include "tekbook.hpp"

TEST_CASE("Application name is correct", "[app]") {
    REQUIRE(tekbook::app_name() == "cpp-tekbook");
}

TEST_CASE("Addition works", "[math]") {
    REQUIRE(tekbook::add(2, 3) == 5);
    REQUIRE(tekbook::add(-1, 1) == 0);
}
