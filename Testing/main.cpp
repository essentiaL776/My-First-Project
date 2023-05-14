#define CATCH_CONFIG_MAIN

#include <iostream>
#include "../mylib.h"
#include "../student.h"
#include "catch_amalgamated.hpp"

TEST_CASE("Student constructor"){
    vector<int> grades{1,2,3};
    Student student("firstName", "lastName", grades, 9, 5.7, 1.5);
    REQUIRE(student.getFirstName() == "firstName");
    REQUIRE(student.getLastName() == "lastName");
    REQUIRE(student.getFinalExamGrade() == 9);
    REQUIRE(student.getMedian() == 5.7);
    REQUIRE(student.getAverage() == 1.5);
}

TEST_CASE("Student copy operator"){
    vector<int> grades{1,2,3};
    Student s1("firstName","lastName",grades,4,5.2,8.4);
    Student s5 = s1;
    REQUIRE(s5.getFirstName() == "firstName");
    REQUIRE(s5.getLastName() == "lastName");
    REQUIRE(s5.getFinalExamGrade() == 4);
    REQUIRE(s5.getMedian() == 5.2);
    REQUIRE(s5.getAverage() == 8.4);

}
