#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137), _target("Default")
{
    std::cout << "Default ShrubberyCreationForm created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery Creation Form", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm " << this->_target << " created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target)
{
    std::cout << "ShrubberyCreationForm " << this->_target << " copy created." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        //this->_target = copy._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm " << this->_target << " destructed." << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::ofstream ofs((this->_target + "_shrubbery").c_str());
    if (!ofs)
    {
        std::cerr << "Error: Could not create file." << std::endl;
        return;
    }
    ofs << "          &&& &&  & &&          " << std::endl;
    ofs << "      && &\\/&\\|& ()|/ @, &&      " << std::endl;
    ofs << "      &\\/(/&/&||/& /_/)_&/_&     " << std::endl;
    ofs << "   &() &\\/&|()|/&\\/ '%%' & ()   " << std::endl;
    ofs << "  &_\\_&&_\\ |& |&&/&__%_/_& &&   " << std::endl;
    ofs << "&&   && & &| &| /& & %% ()@ ^  &&" << std::endl;
    ofs << " ()&_---()&\\&\\|&&-&&--%---()~   " << std::endl;
    ofs << "      &&   \\\\|||                 " << std::endl;
    ofs << "              |||                " << std::endl;
    ofs << "              |||                " << std::endl;
    ofs << "               ||                " << std::endl;

    ofs << "       _-_        " << std::endl;
    ofs << "    /~~   ~~\\    " << std::endl;
    ofs << " /~~         ~~\\ " << std::endl;
    ofs << "{               }" << std::endl;
    ofs << " \\  _-     -_  /" << std::endl;
    ofs << "   ~  \\\\ //  ~  " << std::endl;
    ofs << "_- -   | | _- _  " << std::endl;
    ofs << "  _ -  | |   -_  " << std::endl;
    ofs << "      // \\\\      " << std::endl;

    ofs.close();
}

