#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5), _target("Default")
{
    std::cout << "Default PresidentialPardonForm created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", 25, 5), _target(target)
{
    std::cout << "PresidentialPardonForm " << this->_target << " created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "PresidentialPardonForm " << this->_target << " copy created." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm " << this->_target << " destructed." << std::endl;
}

void PresidentialPardonForm::execute (const Bureaucrat &executor) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}