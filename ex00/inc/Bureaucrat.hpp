#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat(void);

        class GradeTooHighException : public std::exception 
        {
            public: const char* what() const throw() { return "Grade too high"; }
        };
        class GradeTooLowException : public std::exception
        {
            public: const char* what() const throw() { return "Grade too low"; }
        };

        std::string getName() const;
        int         getGrade() const;
        void        incrementGrade();
        void        decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif