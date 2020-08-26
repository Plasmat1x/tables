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
    std::vector<std::string> fields;
    std::map<std::string, int> _fields;
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

    void control_info();
    void add_item();
    void create_table(const std::string& name);
    void show_tables();
    void show_table(const int& num);
};

/*
imp lambda function

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