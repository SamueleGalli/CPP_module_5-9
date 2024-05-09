/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:16:51 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/09 13:52:11 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    //Bureaucrat
    //Bureaucrat invalid_B("Bill", 0);
    //Bureaucrat invalid_B2("Micheal", 151);    
    Bureaucrat B("Bill", 2);
    Bureaucrat B2("Micheal", 150);

    std::cout << B << std::endl;
    std::cout << "--------------------------" << std::endl;
    B.Increment_Grade();
    std::cout << B << std::endl;
    std::cout << "--------------------------" << std::endl;
    B.Increment_Grade();
    std::cout << B << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << B2 << std::endl;
    std::cout << "--------------------------" << std::endl;
    B2.Decrement_Grade();
    std::cout << B2 << std::endl;
    std::cout << "--------------------------" << std::endl;
    B2.Increment_Grade();
    std::cout << B2 << std::endl;
    std::cout << "--------------------------" << std::endl;
}