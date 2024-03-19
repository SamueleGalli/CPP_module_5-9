#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, std::string name)
{
    this->name = name;
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
}

void        Bureaucrat::Increment_Grade(int increment)
{
    this->grade = this->grade - increment;
}

void        Bureaucrat::Decrement_Grade(int decrement)
{
    this->grade = this->grade + decrement;
}

std::string Bureaucrat::getName(void)
{
    return (name);
}

int Bureaucrat::getGrade(void)
{
    return (grade);
}

std::ostream    &operator<<(std::ostream &out, Bureaucrat &B)
{
    out << "<" << B.getName() << ">, bureaucrat grade " << B.getGrade();
    return out;
}