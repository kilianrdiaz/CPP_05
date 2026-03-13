#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>

class Bureaucrat;

class AForm
{
    protected:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _executeGrade;
        
        AForm(void);
        AForm(const std::string name, int signGrade, int executeGrade);
        virtual ~AForm(void);

    public:
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        int getSignGrade() const;
        int getExecuteGrade() const;
        std::string getName() const;
        bool isSigned() const;
        std::string getIsSigned() const;
        
        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(const Bureaucrat &executor)const = 0;

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw(); 
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw(); 
        };

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif