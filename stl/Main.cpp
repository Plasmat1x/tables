#include "Main.h"


int main()
{
    Main main;
    main.init();
    main.run();
    main.cleanup();
    return 0;
}

void Main::init()
{
    RUN = true;
    control_info();
}

void Main::run()
{
    while (RUN)
    {
        std::cout << "Enter input command> "; std::cin >> _input; std::cout << std::endl;

        switch (_input)
        {
        case 0:
            if (dialog.start("You shure about exit?"))
            {
                RUN = false;
                break;
            }
            else
            {
                system("cls");
                control_info();
                break;
            }

        case 1:
            show_tables();
            std::cout << std::endl;
            control_info();
            break;
        case 2:
            if (dialog.start("You want create table?"))
            {
                system("cls");
                std::cout << "Enter name table: ";
                std::string name;
                std::cin >> name;
                create_table(name);
                system("cls");
                control_info();
                break;
            }
            else
            {
                system("cls");
                control_info();
                break;
            }
        case 3:
            if (_tables.size() != 0)
            {
                system("cls");
                show_tables();
                std::cout << "Enter ID of table: "; std::cin >> _input; std::cout << std::endl;
                if (_input >= _tables.size())
                {
                    system("cls");
                    std::cout << "Table " << _input << " not found " << std::endl;
                    control_info();
                    break;
                }
                show_table(_input);
                std::cout << std::endl;
                control_info();
                break;
            }
            else
            {
                std::cout << "Not found no one table" << std::endl;
                break;
            }
        }
    }
}

void Main::cleanup()
{

}

void Main::control_info()
{
    std::cout << "Table programm " << std::endl;
    std::cout << " Commands: " << std::endl;
    std::cout << "  1 - Show all tables" << std::endl;
    std::cout << "  2 - Create table" << std::endl;
    std::cout << "  3 - Show table" << std::endl;
    std::cout << "  0 - Exit " << std::endl;
}

void Main::add_item()
{
}

void Main::create_table(const std::string& name)
{
    Table table;
    table._name = name;
    std::string input;
    std::string _input;

    while (true)
    {
        std::cout << "Enter field name or \"exit\" for quit: "; 
        std::cin >> input;
        _input = input;
        if (input.compare("exit") == 0)
        {
            if (dialog.start("You want stop create table?"))
            {
                system("cls");
                control_info();

                break;
            }
        
        }
        if (!input.empty())
        {
            std::cout << "Enter size of field <int>: ";
            std::cin >> _input;
            std::cout << std::endl;
            table.fields.push_back(input);
            table._fields.insert(std::pair<std::string, int>(input, atoi(_input.data())));
        }
    }

    _tables.push_back(table);
}

void Main::show_tables()
{


    system("cls"); 
    std::cout.fill('-');
    std::cout <<'+'<< std::setw(3) << "+" << std::setw(17) <<"+" << std::endl;
    std::cout.fill(' ');
    std::cout << std::left << "|ID" << "|" << std::setw(16)  << "Tables" <<  "|" << std::right << std::endl;
    std::cout.fill('-');
    std::cout << '+' << std::setw(3) << "+" << std::setw(17) << "+" << std::endl;
    for (int x = 0; x< _tables.size(); x++)
    {
        std::cout.fill(' ');
        std::cout
            << '|' << std::left << std::setw(2) << x << std::right
            << '|' << std::left << std::setw(16) << _tables[x]._name << std::right << '|'
            << std::endl;
    }
    std::cout.fill('-');
    std::cout << '+' << std::setw(3) << "+" << std::setw(17) << "+" << std::endl;
    std::cout.fill(' ');
}

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

/*
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
*/