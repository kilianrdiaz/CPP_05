#include "Bureaucrat.hpp"

Form::Form(void) : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150) {}

Form::Form(const std::string name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

Form &Form::operator=(const Form& other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

Form::~Form(void)
{
    std::cout << "Form " << this->_name << " destructed." << std::endl;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw Bureaucrat::GradeTooLowException();
    this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form " << form.getName() << ", signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade() << ".";
    return os;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::isSigned() const
{
    return this->_signed;
}

int Form::getSignGrade() const
{
    return this->_signGrade;
}

int Form::getExecuteGrade() const
{
    return this->_executeGrade;
}

std::string Form::getIsSigned() const
{
    if (this->_signed)
        return "yes";
    else
        return "no";
}

