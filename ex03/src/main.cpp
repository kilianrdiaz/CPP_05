#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
    Intern intern;
    Bureaucrat bureaucrat("Jeff", 1);

    try
    {
        AForm* form1 = intern.makeForm("shrubbery creation", "home");
        std::cout << *form1 << std::endl;

        bureaucrat.signForm(*form1);
        bureaucrat.executeForm(*form1);

        delete form1;

        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        std::cout << *form2 << std::endl;

        bureaucrat.signForm(*form2);
        bureaucrat.executeForm(*form2);

        delete form2;

        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    try
    {
        AForm* form3 = intern.makeForm("presidential pardon", "Alice");
        std::cout << *form3 << std::endl;
        
        bureaucrat.signForm(*form3);
        bureaucrat.executeForm(*form3);

        delete form3;

        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        AForm* form4 = intern.makeForm("unknown form", "target");  // Throws exception
        delete form4;

        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}