/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:16:51 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/08 14:15:19 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    //Bureaucrat
    //Bureaucrat invalid_B(0, "Bill");
    //Bureaucrat invalid_B2(151, "Micheal");    
    Bureaucrat B(2, "Bill");
    Bureaucrat B2(150, "Micheal");

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