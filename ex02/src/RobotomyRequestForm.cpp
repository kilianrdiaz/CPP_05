#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form", 72, 45), _target("Default")
{
    std::cout << "Default RobotomyRequestForm created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm " << this->_target << " created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "RobotomyRequestForm " << this->_target << " copy created." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm " << this->_target << " destructed." << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::cout << "Bzzzz... Drilling noises..." << std::endl;
    if (rand() % 2)
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Failed to robotomize " << this->_target << "." << std::endl;
}