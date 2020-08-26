#include "Dialog.h"



bool Dialog::start(std::string Content)
{
    content = Content;
    system("cls");
    std::cout << content << " Y/n: "; std::cin >> flag; std::cout << std::endl;
    if (answer(flag))
    {
        return true;
    }
    return false;
}

bool Dialog::answer(char Flag)
{
    if (Flag == 'y' || Flag == 'Y')
    {
        return true;
    }
    else if (Flag == 'n' || Flag == 'N')
    {
        return false;
    }
    else
    {
        return false;
    }
}
