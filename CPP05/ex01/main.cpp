/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalli <sgalli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:16:51 by sgalli            #+#    #+#             */
/*   Updated: 2024/05/09 13:53:05 by sgalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    //Bureaucrat
    Bureaucrat B("Bill", 49);
    //Form
    Form F("ASIA", -50, -50);
    Form F1("AMERICA", 300, 300);
    Form F2("EUROPE", 50, 50);

    B.signForm(F);
    B.signForm(F1);
    B.signForm(F2);
    F.beSigned(B);
    F1.beSigned(B);
    F2.beSigned(B);
    F2.beSigned(B);
}