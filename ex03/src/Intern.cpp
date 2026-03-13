#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern &Intern::operator=(const Intern& other)
{
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern(void)
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string& type, const std::string& target)
{
    const std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (type == formTypes[i])
        {
            std::cout << "Intern creates " << type << " form" << std::endl;
            switch (i)
            {
                case 0: return new ShrubberyCreationForm(target);
                case 1: return new RobotomyRequestForm(target);
                case 2: return new PresidentialPardonForm(target);
            }
        }
    }
    throw Intern::UnknownFormTypeException();
}

const char *Intern::UnknownFormTypeException::what() const throw()
{
    return "Intern cannot create form: unknown form type";
}