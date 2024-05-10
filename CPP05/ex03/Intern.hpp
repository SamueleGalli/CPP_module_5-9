#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
class   Intern : public AForm
{
    private:
    public:
    //constructor
    Intern();
    //copy constructo
    Intern(const Intern &copy);

    //copy assignment operator
    Intern &operator=(Intern const &I);

    AForm   makeForm(std::string name_form, std::string target);
    ~Intern();
};

#endif