
#include <ctime>
#include <chrono>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>


struct person
{
    int ID;
    std::string NAME;
    std::string SEC_NAME;
    int DATE;
};

std::vector<person> personTable;

void add_item();
void show_item();
void control_info();
void show_file();
void load_file();

int main()
{

    bool run = true;
    int input = NULL;

    control_info();

    while (run)
    {
        std::cout << "\nEnter input command> "; std::cin >> input; std::cout << std::endl;

        switch (input)
        {
        case 0:
            run = false;
            break;
        case 1:
            show_item();
            break;
        case 2:
            add_item();
            break;
        case 3:
            show_file();
            break;
        }
    }

    return 0;
}

void add_item()
{
    std::ofstream file;
    file.open("./table.txt", std::ios_base::out | std::ios_base::ate | std::ios_base::app);

    bool add_process = true;

    while (add_process)
    {
        system("cls");
        person add;

        std::cout << "\nEnter ID: "; int id = NULL; std::cin >> id; add.ID = id;
        std::cout << "\nEnter Name: "; std::string name; std::cin >> name; add.NAME = name;
        std::cout << "\nEnter Second Name: "; std::string secname; std::cin >> secname; add.SEC_NAME = secname;
        std::cout << "\nEnter Date: "; int date = NULL; std::cin >> date; add.DATE = date;

        personTable.push_back(add);
        std::cout << "\n" << add.NAME << " " << add.SEC_NAME << " added in to table " << std::endl;

        file << std::right
            << std::setw(3) << add.ID << " "
            << std::setw(20) << std::left << add.NAME
            << std::setw(20) << add.SEC_NAME
            << std::setw(8) << std::right << add.DATE
            << std::endl;

        file.close();
        add_process = false;
    }

    control_info();
}

void show_item()
{
    system("cls");
    std::cout << "ID# "
        << std::setw(20) << std::left << "First Name"
        << std::setw(20) << "Second Name"
        << std::setw(8) << "Date"
        << "\n"
        << std::endl;

    for (auto element : personTable)
    {
        std::cout << std::right
            << std::setw(3) << element.ID << " "
            << std::setw(20) << std::left << element.NAME
            << std::setw(20) << element.SEC_NAME
            << std::setw(8) << std::right << element.DATE
            << std::endl;
    }

    control_info();
}

void control_info()
{
    std::cout << "\n Table programm " << std::endl;
    std::cout << " Commands: " << std::endl;
    std::cout << "  0 - Exit " << std::endl;
    std::cout << "  1 - Show " << std::endl;
    std::cout << "  2 - Add " << std::endl;
    std::cout << "  3 - Show from file " << std::endl;
}

void show_file()
{
    std::ifstream file;
    file.open("./table.txt", std::ios_base::in);
    system("cls");

    char buff[64];
    while (!file.eof())
    {
        file.getline(buff, 64);
        std::cout << buff << std::endl;
    }

    file.close();

    control_info();
}

void load_file()
{
    std::ifstream file;
    file.open("./table.txt", std::ios_base::in);

    system("cls");

    char buff[64];

}