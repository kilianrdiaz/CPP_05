#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Bureaucrat bureaucrat1("Mike", 1);
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat bureaucrat2("Laura", 50);
        std::cout << bureaucrat2 << std::endl;
        bureaucrat2.incrementGrade();

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Bureaucrat bureaucrat3("Jon", 150);
        std::cout << bureaucrat3 << std::endl;
        // Exception thrown here
        bureaucrat3.decrementGrade();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bureaucrat4("Abril", 151);   // Exception thrown here
        std::cout << bureaucrat4 << std::endl;
        bureaucrat4.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Bureaucrat bureaucrat5("David", 0);   // Exception thrown here
        std::cout << bureaucrat5 << std::endl;
        bureaucrat5.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}