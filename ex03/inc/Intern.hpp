#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern(void);

        AForm *makeForm(const std::string& type, const std::string& target);

        class UnknownFormTypeException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
};

#endif