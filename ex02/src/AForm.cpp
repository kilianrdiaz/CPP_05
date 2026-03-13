#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("Default"), _signed(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const std::string name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw AForm::GradeTooHighException();
    else if (signGrade > 150 || executeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

AForm &AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return *this;
}

AForm::~AForm(void) {}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw Bureaucrat::GradeTooLowException();
    this->_signed = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form " << form.getName() << ", signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", execute grade: " << form.getExecuteGrade() << ".";
    return os;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed";
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::isSigned() const
{
    return this->_signed;
}

int AForm::getSignGrade() const
{
    return this->_signGrade;
}

int AForm::getExecuteGrade() const
{
    return this->_executeGrade;
}

std::string AForm::getIsSigned() const
{
    if (this->_signed)
        return "yes";
    else
        return "no";
}

