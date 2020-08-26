#pragma once
#include <iostream>
#include <string>
class Dialog
{
public:
    bool start(std::string Content);
    bool answer(char Flag);

private:
    std::string content;
    char flag;
};

