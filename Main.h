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
    std::string name;
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
    std::string input;
    Dialog dialog;

    std::vector<Table> tables;
    Table allTables;
    Table* used;

    void info();
    void show_tables(std::vector<Table> & tables);
    void show_table(Table * table);

    void border(Table * table);
};