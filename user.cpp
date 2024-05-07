#include "user.h"
#include "app.h"

std::list<User> globalUserList;

int userInput()
{
    int number;
    std::cout<<"->";
    std::cin>>number;
    //std::cout<<std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return number;
}

void loadUsersFromTXT()
{
    std::ifstream file("C:\\Users\\Denis\\Desktop\\CLionProjects\\LowBudgetSpotify\\user.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file: user.txt" << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string name, surname, password;

        getline(iss, name, ',');
        getline(iss, surname, ',');
        getline(iss, password);

        User newUser = {name, surname, password};
        globalUserList.push_back(newUser);
    }

    file.close();

}

void addUserToTXT(const std::string& name, const std::string& surname, const std::string& password)
{
    std::string filename = "C:\\Users\\Denis\\Desktop\\CLionProjects\\LowBudgetSpotify\\user.txt";

    std::ofstream outFile(filename, std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for appending." << std::endl;
        return;
    }

    outFile << name << "," << surname << "," << password << std::endl;

    outFile.close();
}

int searchUser(const std::string& name, const std::string& surname)
{
    int position = 1;

    for(std::list<User>::iterator it = globalUserList.begin(); it != globalUserList.end(); ++it)
    {
        if(it->name == name && it->surname == surname)
            return position;
        else
            position++;
    }
    return 0;
}

void createUser(std::string& name, std::string& surname)
{
    int goBack;
    int answer;

    while(true)
    {

        int userExists = searchUser(name, surname);

        if (userExists)
        {
            std::cout << "A user called '" << name << ' ' << surname << "' already exists!" << std::endl;
            std::cout << "Would you like to try again?";
            std::cout << "Type '1' if yes, else type '2'." << std::endl;

            answer = userInput();

            while (answer != 1 && answer != 2) {
                std::cout << "Please provide a valid input!" << std::endl;
                answer = userInput();
            }

            if (answer == 2)
            {
                goBack = 1;
                break;
            }
            else {
                std::cout << "\n\n\n\n\n\n\n\n\n\n\n";
                //system("CLS");
                std::cout << "Please type your name:";
                std::cin >> name;
                std::cout << "Please type your surname:";
                std::cin >> surname;
            }
        }
        else
        {
            std::string password;
            std::cout << "Please type your password:";
            std::cin >> password;

            //system("CLS");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "Your account has successfully been created!" << std::endl;

            User newUser = {name, surname, password};
            globalUserList.push_back(newUser);
            addUserToTXT(name,surname,password);

            std::cout << "Do you want to also log in?";
            std::cout << "Type '1' if yes, else type '2'." << std::endl;

            answer = userInput();

            while (answer != 1 && answer != 2) {
                std::cout << "Please provide a valid input!" << std::endl;
                answer = userInput();
            }

            if(answer == 1)
                goBack = 0;
            else
                goBack = 1;
            break;
        }
    }

    if(goBack)
    {
        //system("CLS");
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        display_initialPage();
    }
    else
    {
        //system("CLS");
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        display_mainMenu(name, surname);
    }
}
