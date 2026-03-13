#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
    std::cout << "=== SHRUBBERY CREATION FORM ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 145);
        ShrubberyCreationForm shrubbery("garden");
        std::cout << bob << std::endl;
        std::cout << shrubbery << std::endl;
        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== ROBOTOMY REQUEST FORM ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 45);
        RobotomyRequestForm robotomy("Bender");
        std::cout << alice << std::endl;
        std::cout << robotomy << std::endl;
        alice.signForm(robotomy);
        alice.executeForm(robotomy);
        alice.executeForm(robotomy);
        alice.executeForm(robotomy);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== PRESIDENTIAL PARDON FORM ===" << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Ford");
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== TESTS DE ERROR ===" << std::endl;
    try
    {
        std::cout << "-- Intentar ejecutar sin firmar --" << std::endl;
        Bureaucrat carl("Carl", 1);
        ShrubberyCreationForm form("home");
        carl.executeForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "-- Grado insuficiente para firmar --" << std::endl;
        Bureaucrat lowly("Lowly", 150);
        RobotomyRequestForm form("target");
        lowly.signForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "-- Grado insuficiente para ejecutar --" << std::endl;
        Bureaucrat signer("Signer", 45);
        Bureaucrat executor("Executor", 150);
        PresidentialPardonForm form("target");
        signer.signForm(form);
        executor.executeForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}