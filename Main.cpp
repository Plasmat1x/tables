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
    allTables.name = "All tables";
    allTables.fields.push_back(std::make_pair("ID", 3));
    allTables.fields.push_back(std::make_pair("Table name", 20));

    tables.push_back(allTables);

    Table test_table;
    test_table.name = "test";
    test_table.fields.push_back(std::make_pair("ID", 3));
    test_table.fields.push_back(std::make_pair("Name", 16));
    test_table.fields.push_back(std::make_pair("Date", 8));

    test_table.content.push_back("0");
    test_table.content.push_back("Mike");
    test_table.content.push_back("22071997");

    test_table.content.push_back("1");
    test_table.content.push_back("Alexandr");
    test_table.content.push_back("16061997");

    tables.push_back(test_table);

    Table test_table2;
    test_table2.name = "tes";
    test_table2.fields.push_back(std::make_pair("ID", 3));
    test_table2.fields.push_back(std::make_pair("Name", 16));
    test_table2.fields.push_back(std::make_pair("Date", 8));

    tables.push_back(test_table2);

    RUN = true;

    std::cout << "Use \"help\" command for command list" << std::endl;
}

void Main::run()
{
    while (RUN)
    {
        if (used == nullptr)
        {
            std::cout << "Enter command > ";
            std::getline(std::cin, input);
            std::cout << input << std::endl;
        }
        else
        {
            std::cout << "<" << used->name << "> Enter command >> ";
            std::getline(std::cin, input);
        }

        if (input.compare("exit") == 0)
        {
            if (dialog.start("exit ?"))
            {
                RUN = false;
            }
        }

        if (input.compare("help") == 0)
        {
            info();
        }

        if (input.compare("clear") == 0)
        {
            system("cls");
        }

        if (input.compare("show") == 0)
        {
            if (used == nullptr)
            {
                show_tables(tables);
            }
            else
            {
                show_table(used);
            }
        }

        if (input.compare("use") == 0)
        {
            std::cout << "Enter table name: ";      
            std::getline(std::cin, input);
            std::cout << input << " selected" << std::endl;

            for (int i = 0; i < tables.size(); i++)
            {
                if (tables[i].name.compare(input.data()) == 0)
                {
                    used = &tables[i];
                }
            }
        }

        if (input.compare("unuse") == 0)
        {
            used = nullptr;
        }
    }
}

void Main::cleanup()
{
}

void Main::info()
{
    std::cout
        << "commands: " << std::endl
        << "use - select tables" << std::endl
        << "show - show all tables if table selected then show table content" << std::endl
        << "info - show command list" << std::endl
        << "exit - exit from programm" << std::endl
        << "clear - clearing console" << std::endl
        << "unuse - deselect table" << std::endl;
}


void Main::show_tables(std::vector<Table> & tables)
{
    int width1 = tables[0].fields[0].second;
    int width2 = tables[0].fields[1].second;

    border(&tables[0]);
    
    std::cout << "|" << std::setw(width1) << "ID" << '|' << std::setw(width2) << "Table name" << "|" << std::endl;
    
    border(&tables[0]);

    for (int i = 0; i < tables.size(); i++)
    {
        std::cout << "|" << std::setw(width1) << i << "|" << std::setw(width2) << tables[i].name << "|" << std::endl;
    }

    border(&tables[0]);
}

void Main::show_table(Table* table)
{
    border(used);
    for (int i = 0; i < table->fields.size(); i++)
    {
        std::cout << "|" << std::setw(table->fields[i].second) << table->fields[i].first;
    }
    std::cout << "|" << std::endl;
    border(used);

    if (!used->content.empty())
    {
        for (int x = 0, y = 0; x < used->content.size(); x++, y++)
        {
            if (y >= used->fields.size())
            {
                y -= used->fields.size();
                std::cout << "|" << std::endl;
            }
            std::cout << "|" << std::left << std::setw(used->fields[y].second) << used->content[x];
        }
        std::cout << "|" << std::right << std::endl;
    }

    border(used);
}

void Main::border(Table * table)
{
    std::cout.fill('-');
    for (int i = 0; i < table->fields.size(); i++)
    {
        std::cout << "+" << std::setw(table->fields[i].second + 1);
    }
    std::cout << "+" << std::endl;
    std::cout.fill(' ');
}

