#include "Bureaucrat.hpp"

//constructor
Bureaucrat::Bureaucrat(char const *name_b, int grade_b)
{
    if (grade_b < 1)
    {
        std::cout << "too high grade" << std::endl;
        exit (1);
    }
    if (grade_b > 150)
    {
        std::cout << "too low grade" << std::endl;
        exit (1);
    }
    this->name = name_b;
    this->grade = grade_b;
}

Bureaucrat::Bureaucrat(void)
{
}

//copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    if (this != &copy)
        *this = copy;
}

//copy assignment operator
Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &B)
{
    if (this != &B)
    {
        this->grade = B.grade;
        this->name = B.name;
    }
    return (*this);
}

//method inc and dec
void        Bureaucrat::Increment_Grade()
{  
    this->grade--;
    try 
    {
        if (this->grade < 1)
        {
            this->grade++;
            throw std::exception();
        }
    }
    catch (std::exception &e)
    {
        GradeTooHighException();
    }
}

void        Bureaucrat::Decrement_Grade()
{
    this->grade++;
    try
    {
        if (this->grade > 150)
        {
            this->grade--;
            throw std::exception();
        }
    }
    catch (std::exception &e)
    {
        GradeTooLowException();
    }
}

//exception
void      Bureaucrat::GradeTooHighException(void)
{
    std::cout << "Error: (invalid increment)=\"higher than 1\"" << std::endl;
}

void    Bureaucrat::GradeTooLowException()
{
    std::cout << "Error: (invalid decrement)=\"lower than 150\"" << std::endl;
}

//getter
char const *Bureaucrat::getName(void)
{
    return (this->name);
}

int Bureaucrat::getGrade(void)
{
    return (grade);
}

//overload operator print
std::ostream    &operator<<(std::ostream &out, Bureaucrat &B)
{
    out << B.getName() << ", bureaucrat grade " << B.getGrade();
    return out;
}

//destructor
Bureaucrat::~Bureaucrat()
{
}