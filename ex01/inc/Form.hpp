#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _executeGrade;
    public:
        Form(void);
        Form(const std::string name, int signGrade, int executeGrades);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form(void);

        int getSignGrade() const;
        int getExecuteGrade() const;
        std::string getName() const;
        bool isSigned() const;
        void beSigned(const Bureaucrat& bureaucrat);
        std::string getIsSigned() const;

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
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif