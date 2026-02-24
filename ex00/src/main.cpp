#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    try
    {
        Bureaucrat bureaucrat("Watson", 50);
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();

        Bureaucrat bureaucrat1("Mike", 1);
        std::cout << bureaucrat1 << std::endl;
        bureaucrat1.decrementGrade();

        Bureaucrat bureaucrat2("John", 150);
        std::cout << bureaucrat2 << std::endl;
        // Exception thrown here
        bureaucrat2.decrementGrade();

        // Wont be reached due to exception
        Bureaucrat bureaucrat3("Unknown", 33);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}