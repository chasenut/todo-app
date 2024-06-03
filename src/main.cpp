#include <iostream>
#include <string>
#include <vector>

class Task
{
public:
    std::string m_name;
    Task(std::string& name)
    {
        m_name = name;
    }

};

class App
{
public: 
    std::vector<std::string> m_tasks;
    bool exit = false;
    App()
    {
        std::cout << "Created an App!" << std::endl;
        appLoop();
    }

    void appLoop()
    {
        std::cout << "Welcome to a TODO app! " << std::endl;
        std::cout << "Enter operation type or 'help' for more information!" << std::endl;
        while(!exit)
        {
            std::string operation = userInput();
            if (operation == "exit") { exit = true; break; }
            if (operation == "add")
            {
                operation = "";
                std::cout << "Please enter an item's name ";
                std::string argument = userInput();
                addItem(argument);
            }
            else if (operation == "remove")
            {
                std::cout << "Please enter an item's name ";
                operation = "";
                std::string argument = userInput();
                removeItem(argument);
            }
            else if (operation == "list")
            {
                operation = "";
                std::cout << "List of items in the TODO list: ";
                
                for (auto it = m_tasks.begin(); it != m_tasks.end(); ++it)
                {
                    std::cout << " /" << *it;
                }
                std::cout << std::endl;
            }
            else if (operation == "help")
            {
                std::cout << "Type of operations: " << std::endl;
                std::cout << "-help     for more information" << std::endl;
                std::cout << "-exit     to exit program" << std::endl;
                std::cout << "-list     to view all element of a TODO list" << std::endl;
                std::cout << "-add      to add item to a TODO list" << std::endl;
                std::cout << "-remove   to remove item from a TODO list" << std::endl;
            }
            else
            {
                std::cout << "Invalid input!" << std::endl;
            }
            
        }
        std::cout << "You have exited the program!" << std::endl;
    }

    std::string userInput(){
        std::string input = "";
        std::cout << "> ";
        std::getline(std::cin, input);
        system("clear");
        return input;
    }

   void removeItem(std::string& item)
    {
        bool invalid = true;
        int size = m_tasks.size();
        for (int i = 0; i < size; i++)
        {
            if (m_tasks[i] == item)
            {
                m_tasks.erase(m_tasks.begin() + i);
                system("clear");
                std::cout << "Removed " << item << "from the TODO list!" << std::endl;
                invalid = false;
                break;
            }
        }
        if (invalid){
        std::cout << "Invalid input!" << std::endl;
        }
    }

    void addItem(std::string& item)
    {
        m_tasks.push_back(item);
        system("clear");
        std::cout << "Added " << item << "to the TODO list!" << std::endl;
    }
};

int main()
{
    App app;

    std::cin.get();
}