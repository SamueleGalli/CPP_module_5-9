#include "Bureaucrat.hpp"

//constructor

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(int grade_b, char const *name_b)
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

//inc and dec

void        Bureaucrat::Increment_Grade(int increment)
{
    int     grade1 = this->grade - increment;
    try 
    {
        if (grade1 < 1)
            throw std::exception();
        else
            this->grade = this->grade - increment;
    }
    catch (std::exception &e)
    {
        GradeTooHighException();
    }
}

void        Bureaucrat::Decrement_Grade(int decrement)
{
    int     grade1 = this->grade + decrement;
    try
    {
        if (grade1 > 150)
            throw std::exception();
        else
            this->grade = this->grade + decrement;

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
    return (name);
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

//show form
void    Bureaucrat::signForm(Form &f)
{
    std::cout << "|Form : (" << f.getName() << ")|" << std::endl;
    if (f.getSign() == true)
        std::cout << "|Sign : (is signed" << ")|" << std::endl;
    else
        std::cout << "|Sign : (is not signed" << ")|" << std::endl;
    std::cout << "|Grade to sign : ("  << f.getGradeToSign() << ")|" << std::endl;
    std::cout << "|Grade to execute : (" << f.getGradeToExecute() << ")|" << std::endl;
}

//destructor

Bureaucrat::~Bureaucrat()
{
}