#pragma once
#include <ctime>
#include <chrono>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#include "Dialog.h"

struct Table
{
    std::string _name;
    std::vector<std::pair<std::string, int>> fields;
    std::vector<std::string> content;
};

class Main
{
public:
    void init();
    void run();
    void cleanup();

private:
    bool RUN;
    int _input;
    Dialog dialog;

    std::vector<Table> _tables;
    Table* _use;

    void control_info();
    void add_item(int num);
    void create_table(const std::string& name);
    void show_tables();
    void show_table(int num);
};

/*
<important> lambda function

    auto getminus = [=](int count) -> std::string {
        std::string tmp{};
        for (int i = 0; i < count; i++)
        {
            tmp += '-';
        }
        return tmp;
    };


//use
    std::cout << '+' << getminus(16) << '+' << std::endl;
*/

/*

struct Table
{
    std::string _name;
    std::vector<std::pair<std::string, int>> fields;

    //std::vector<std::string> fields;
    //std::vector<std::pair<std::string, int>> _fields;
    //std::map<std::string, int> __fields;
};

void Main::show_table(const int& num)
{
    std::map<std::string, int>::iterator it;
    // header
      //top border
    std::cout.fill('-');
        for (it = _tables[num]._fields.begin(); it != _tables[num]._fields.end(); it++)
            std::cout << '+' << std::setw(it->second + 1);
    std::cout << '+' << std::endl;

      //content
    std::cout.fill(' ');
        for (it = _tables[num]._fields.begin(); it != _tables[num]._fields.end(); it++)
            std::cout << '|' << std::setw(it->second) << it->first;
    std::cout << '|' << std::endl;

      //bottom border
    std::cout.fill('-');
        for (it = _tables[num]._fields.begin(); it != _tables[num]._fields.end(); it++)
            std::cout << '+' << std::setw(it->second + 1);
    std::cout << '+' << std::endl;

    //body
    std::cout.fill(' ');

      //bottom border
    std::cout.fill('-');
        for (it = _tables[num]._fields.begin(); it != _tables[num]._fields.end(); it++)
            std::cout << '+' << std::setw(it->second + 1);
    std::cout << '+' << std::endl;
}
//table._fields.insert(std::pair<std::string, int>(input, atoi(_input.data())));


void Main::show_table(const int& num)
{
    // header
    ////top border
    std::cout.fill('-');
    for (int x = 0; x < _tables[num].fields.size(); x++)
    {
        std::cout << '+' << std::setw(11);
    }
    std::cout << '+' << std::endl;

    ////content
    std::cout.fill(' ');
    for (int x = 0; x < _tables[num].fields.size(); x++)
    {
        std::cout << '|' << std::setw(10) << _tables[num].fields[x];
    }

    std::cout << '|' << std::endl;

    ////bottom border
    std::cout.fill('-');
    for (int x = 0; x < _tables[num].fields.size(); x++)
    {
        std::cout << '+' << std::setw(11);
    }
    std::cout << '+' << std::endl;

    //body
    std::cout.fill(' ');



    ////bottom border
    std::cout.fill('-');
    for (int x = 0; x < _tables[num].fields.size(); x++)
    {
        std::cout << '+' << std::setw(11);
    }
    std::cout << '+' << std::endl;
}


        for (int x = 0, y = 0; x < _tables[num].content.size(); x++, y++)
        {
            if (y > _tables[num].fields.size())
            {
                y = 0;
                std::cout << std::right << '|' << std::endl;
            }
            std::cout << std::right << '|' << std::setw(_tables[num].fields[y].second) << _tables[num].content[x];
            y++;
        }
        std::cout << std::right << std::endl;
*/