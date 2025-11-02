#pragma once

#include <string>
#include <map>

class Assignment {
private:
    std::string assignment_name;
    double max_grade;
    std::map< std::string, double> grades;

public:
    Assignment(std::string name, double max);
    void add_grade(std::string id, double grade);

    std::string get_name() const;
    double get_grade(std::string id) const;
};
