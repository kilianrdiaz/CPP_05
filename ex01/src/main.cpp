#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    try
    {
        std::cout << "--- TEST 1 ---" << std::endl;
        Bureaucrat bureaucrat("Watson", 21);
        std::cout << bureaucrat << std::endl;
        
        Form form("001", 20, 30);
        std::cout << form << std::endl;
        bureaucrat.signForm(form);

        bureaucrat.incrementGrade();

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- TEST 2 ---" << std::endl;
        Bureaucrat bureaucrat("Laura", 40);
        std::cout << bureaucrat << std::endl;
        
        Form form("002", 20, 30);
        std::cout << form << std::endl;
        bureaucrat.signForm(form);      // Bureaucrat does not have enough grade

        bureaucrat.incrementGrade();

        bureaucrat.signForm(form);

        std::cout << form << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << "\n--- TEST 3 ---" << std::endl;
        Bureaucrat bureaucrat("David", 40);
        std::cout << bureaucrat << std::endl;
        
        Form form("003", 151, 151);       // Invalid grade
        std::cout << form << std::endl;
        bureaucrat.signForm(form);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}