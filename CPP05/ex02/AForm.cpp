#include "AForm.hpp"

//constructor

AForm::AForm(char const *name_form, const int grade_sign, const int grade_ex)
: sign(false), grade_to_sign(grade_sign), grade_to_execute(grade_ex), name(name_form)
{
    try
    {
        if (grade_sign < 1 || grade_ex < 1)
            throw std::exception();
    }
    catch (std::exception &e)
    {
        GradeTooHighException();
    }
    try
    {
        if (grade_sign > 150 || grade_ex > 150)
            throw std::exception();
    }
    catch (std::exception &e)
    {
        GradeTooLowException();
    }
}

//executing form
void    AForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (executor.getGrade() > this->grade_to_sign)
            throw std::exception();
    }
    catch (std::exception &e)
    {
        InvalidGradeException();
    }
    try
    {
        if (this->sign == false)
            throw std::exception();
    }
    catch (std::exception &e)
    {
        InvalidSignException();
    }
}

AForm::AForm(void)
: sign(false), grade_to_sign(1), grade_to_execute(1), name("default")
{
}
//copy constructor
AForm::AForm(AForm const &copy)
: sign(copy.sign),
  grade_to_sign(copy.grade_to_sign),
  grade_to_execute(copy.grade_to_execute),
  name(copy.name)
{
}

//copy assignment operator
AForm  &AForm::operator=(AForm const &f)
{
    if (this != &f)
    {
        this->sign = f.sign;
        this->name = f.name;
    }
    return (*this);
}

//exeception

void    AForm::InvalidGradeException(void) const
{
    std::cout << "grade insufficient for work" << std::endl;
}

void      AForm::GradeTooHighException(void) const
{
    std::cout << "Error it must not be minor of 1" << std::endl;
}

void    AForm::GradeTooLowException(void) const
{
    std::cout << "Error it must not be major of 150" << std::endl;
}

void    AForm::InvalidSignException(void) const
{
    std::cout << "Error: already signed" << std::endl;
}

//sign

void AForm::beSigned(Bureaucrat &b) const
{
    if (this->grade_to_sign > 150 || this->grade_to_sign < 1 || this->grade_to_execute > 150 || this->grade_to_execute < 1)
    {
        std::cout << "Invalid: grade Form cannot be compiled" << std::endl;
        return ;
    }
    if (b.getGrade() <= this->grade_to_sign)
    {
        if (this->sign == false)
        {
            std::cout << "|signing \"" << this->name << "\" form|" << std::endl;
            this->sign = true;
        }
        else
            std::cout << "invalid: already signed" << std::endl;
    }
    else
        std::cout << "Invalid: grade insufficient" << std::endl;
}

//getting

char const    *AForm::getName(void) const
{
    return (this->name);
}

bool    AForm::getSign(void) const
{
    return (this->sign);
}


int   AForm::getGradeToSign(void) const
{
    return (this->grade_to_sign);
}

int   AForm::getGradeToExecute(void) const
{
    return (this->grade_to_execute);
}

//decostructor

AForm::~AForm()
{
}

//overload operator <<
std::ostream    &operator<<(std::ostream &out, AForm &F)
{
    out << "Form: " << F.getName() << "\ngrade to execute: " << F.getGradeToExecute() << "\ngrade to sign: " << F.getGradeToSign() << std::endl;
    return out;
}