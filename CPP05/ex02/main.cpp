/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:16:51 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/13 15:00:26 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
  Bureaucrat b("Pippo", 4);
  std::cout << b << std::endl;
  PresidentialPardonForm ppf("Pluto");
  RobotomyRequestForm rrf("topolino");
  ShrubberyCreationForm scf("mario");
  
  std::cout << "<Form 1>\n" << ppf << std::endl;
  std::cout << "<Form 2>\n" << rrf << std::endl;
  std::cout << "<Form 3>\n" << scf << std::endl;
  std::cout << "first form(PresidentialPardonForm)\n-----------------------------------------" << std::endl;
    b.signForm(ppf);
    std::cout << "\n-----------------------------------------" << std::endl;
    ppf.beSigned(b);
    std::cout << "\n-----------------------------------------" << std::endl;
    b.signForm(ppf);
    std::cout << "\nsecond form(RobotomyRequestForm)\n-----------------------------------------" << std::endl;
    b.signForm(rrf);
    std::cout << "\n-----------------------------------------" << std::endl;
    rrf.beSigned(b);
    std::cout << "\n-----------------------------------------" << std::endl;
    b.signForm(rrf);
    std::cout << "\nthird form(ShrubberyCreationForm)\n-----------------------------------------" << std::endl;
    b.signForm(scf);
    std::cout << "\n-----------------------------------------" << std::endl;
    scf.beSigned(b);
    std::cout << "\n-----------------------------------------" << std::endl;
    b.signForm(scf);
    std::cout << "\nexecute first form\n-----------------------------------------" << std::endl;
    b.executeForm(ppf);
    std::cout << "\nexecute second form\n-----------------------------------------" << std::endl;
    b.executeForm(rrf);
    std::cout << "\nexecute third form\n-----------------------------------------" << std::endl;
    b.executeForm(scf);
    std::cout << std::endl;
}