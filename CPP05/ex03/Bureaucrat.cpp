#include "Bureaucrat.hpp"

//constructor

Bureaucrat::Bureaucrat()
{
}

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

void        Bureaucrat::Increment_Grade()
{
    int     grade1 = this->grade--;
    try 
    {
        if (grade1 < 1)
            throw std::exception();
        else
            this->grade--;
    }
    catch (std::exception &e)
    {
        GradeTooHighException();
    }
}

void        Bureaucrat::Decrement_Grade()
{
    int     grade1 = this->grade++;
    try
    {
        if (grade1 > 150)
            throw std::exception();
        else
            this->grade++;

    }
    catch (std::exception &e)
    {
        GradeTooLowException();
    }
}

//show form
void    Bureaucrat::signForm(AForm &f)
{
    if (f.getGradeToSign() > 150 || f.getGradeToSign() < 1 || f.getGradeToExecute() > 150 || f.getGradeToExecute() < 1)
    {
        std::cout << "invalid Form value to be shown" << std::endl;
        return ;
    }
    std::cout << "|Form : (" << f.getName() << ")|" << std::endl;
    if (f.getSign() == true)
        std::cout << "|Sign : (is signed" << ")|" << std::endl;
    else
        std::cout << "|Sign : (is not signed" << ")|" << std::endl;
    std::cout << "|Grade to sign : ("  << f.getGradeToSign() << ")|" << std::endl;
    std::cout << "|Grade to execute : (" << f.getGradeToExecute() << ")|" << std::endl;
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

int Bureaucrat::getGrade(void) const
{
    return (grade);
}

//execute Form
void Bureaucrat::executeForm(const AForm &form)
{
    if (form.getSign() == false || this->getGrade() > form.getGradeToExecute())
        std::cout << this->name << " cannot execute " << form.getName() << std::endl;
    else
    {
        form.execute(*this);
        std::cout << this->name << " execute " << form.getName() << std::endl;
    }
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