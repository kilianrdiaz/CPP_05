#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
    try
    {
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
    return 0;
}