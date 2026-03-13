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

    try
    {
        AForm* form1 = intern.makeForm("shrubbery creation", "home");
        AForm* form2 = intern.makeForm("robotomy request", "Bender");
        AForm* form3 = intern.makeForm("presidential pardon", "Alice");

        std::cout << "\nCreated forms:" << std::endl;
        std::cout << *form1 << std::endl;
        std::cout << *form2 << std::endl;
        std::cout << *form3 << std::endl << std::endl;

        delete form1;
        delete form2;
        delete form3;

        AForm* form4 = intern.makeForm("unknown form", "target");
        delete form4;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}