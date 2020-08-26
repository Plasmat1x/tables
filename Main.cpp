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
    Table test_table;
    test_table._name = "test";
    test_table.fields.push_back(std::make_pair("ID", 3));
    test_table.fields.push_back(std::make_pair("Name", 16));
    test_table.fields.push_back(std::make_pair("Date", 8));

    test_table.content.push_back("0");
    test_table.content.push_back("Mike");
    test_table.content.push_back("22071997");

    test_table.content.push_back("1");
    test_table.content.push_back("Alexandr");
    test_table.content.push_back("16061997");

    _tables.push_back(test_table);

    Table test_table2;
    test_table2._name = "test2";
    test_table2.fields.push_back(std::make_pair("ID", 3));
    test_table2.fields.push_back(std::make_pair("Name", 16));
    test_table2.fields.push_back(std::make_pair("Date", 8));

    _tables.push_back(test_table2);

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
                system("cls");
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
        case 4:
            if (_tables.size() != 0)
            {
                system("cls");
                show_tables();
                std::cout << "Enter ID of table: ";
                std::cin >> _input;
                if (_input >= _tables.size())
                {
                    system("cls");
                    std::cout << "Table " << _input << " not found " << std::endl;
                    control_info();
                    break;
                }
                system("cls");
                add_item(_input);
                system("cls");
                control_info();
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
    std::cout << "  4 - Add item in table" << std::endl;
    std::cout << "  0 - Exit " << std::endl;
}

void Main::add_item(int num)
{
    _use = &_tables[num];
    std::string input;

    for (int x = 0; x < _use->fields.size(); x++)
    {
        std::cout << "Enter data in cell " << _use->fields[x].first << " or exit for quit: ";
        std::cin >> input;

        if (input.compare("exit") == 0)
        {
            if (dialog.start("You want stop add content in table?"))
            {
                system("cls");
                control_info();

                break;
            }
        }
        if (!input.empty())
        {
            _use->content.push_back(input);
        }
    }
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

            table.fields.push_back(std::make_pair(input, atoi(_input.data())));       
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

void Main::show_table(int num)
{
    // header
        //top border
    std::cout.fill('-');
    for (int x = 0; x < _tables[num].fields.size(); x++)
    {
        std::cout << '+' << std::setw(_tables[num].fields[x].second + 1);
    }
    std::cout << '+' << std::endl;

        //content
    std::cout.fill(' ');
    for (int x = 0; x < _tables[num].fields.size(); x++)
    {
        std::cout << '|' << std::setw(_tables[num].fields[x].second) << _tables[num].fields[x].first;
    }

    std::cout << '|' << std::endl;

        //bottom border
    std::cout.fill('-');
    for (int x = 0; x < _tables[num].fields.size(); x++)
    {
        std::cout << '+' << std::setw(_tables[num].fields[x].second + 1);
    }
    std::cout << '+' << std::endl;

    //body
    std::cout.fill(' ');

    if (!_tables[num].content.empty())
    {
        for (int x = 0, y = 0; x < _tables[num].content.size(); x++, y++)
        {
            if (y >= _tables[num].fields.size())
            {
                y -= _tables[num].fields.size();
                std::cout << "|" << std::endl;
            }
            std::cout << "|" << std::left << std::setw(_tables[num].fields[y].second) << _tables[num].content[x];
        }
        std::cout << "|" << std::right << std::endl;
    }
        //bottom border
    std::cout.fill('-');
    for (int x = 0; x < _tables[num].fields.size(); x++)
    {
        std::cout << '+' << std::setw(_tables[num].fields[x].second + 1);
    }
    std::cout << '+' << std::endl;
    std::cout.fill(' ');
}