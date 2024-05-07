#include "app.h"

void display_initialPage()
{
    std::cout << "Welcome to LowBudget Spotify!" << std::endl;
    std::cout << "1.Login" << std::endl;
    std::cout << "2.Sign Up" << std::endl;
    std::cout << "3.Exit" << std:: endl;
}

void signUpProcess()
{
    //system("CLS");
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::string userName, userSurname;

    std::cout << "Please type your name: " << std::endl;
    std::cin >> userName;

    std::cout << "Please type your surname: " << std::endl;
    std::cin >> userSurname;

    createUser(userName, userSurname);
}

void loginProcess()
{
    int answer;
    int goBack;
    int position;
    int userExists;
    int log;
    std::string userName, userSurname;

    while(true)
    {
        //system("CLS");
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        std::cout << "Please type your name\n->";
        std::cin >> userName;

        std::cout << "Please type your surname\n->";
        std::cin >> userSurname;

        userExists = searchUser(userName, userSurname);

        if (userExists)
        {
            goBack = 0;
            break;
        }
        else
        {
            std::cout << "There is no user called '" << userName << ' ' << userSurname << "'!" << std::endl;
            std::cout << "Would you like to try again?";
            std::cout << "Type '1' if yes, else type '2'." << std::endl;

            answer = userInput();

            while (answer != 1 && answer != 2) {
                std::cout << "Please provide a valid input!" << std::endl;
                answer = userInput();
            }

            if(answer == 2)
            {
                goBack = 1;
                break;
            }
        }
    }

    if(!(goBack))
    {
        position = userExists;
        std::string password;

        while(true) {
            std::cout << "Please type your password\n->";
            std::cin >> password;

            int cnt = 1;

            std::list<User>::iterator temp = globalUserList.begin();

            while (cnt < position) {
                cnt++;
                ++temp;
            }

            if (password == temp->password) {
                log = 1;
                break;
            } else {
                std::cout << std::endl << "Incorrect password!" << std::endl;
                std::cout << "Do you want to try again?" << std::endl;
                std::cout << "Type '1' if yes, else type '2'." << std::endl;

                answer = userInput();

                while (answer != 1 && answer != 2) {
                    std::cout << "Please provide a valid input!" << std::endl;
                    answer = userInput();
                }

                if (answer == 2) {
                    log = 0;
                    break;
                }
            }
        }

        if(log == 1)
        {
            //system("CLS");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            display_mainMenu(userName, userSurname);
        }
        else
        {
            //system("CLS");
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            display_initialPage();
        }
    }
    else
    {
        //system("CLS");
        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        display_initialPage();
    }
}

void display_mainMenu(const std::string& name, const std::string& surname)
{
    std::cout << "Welcome " << surname << "!" << std::endl;
    std::cout << "1.Create playlist" << std::endl;
    std::cout << "2.Search playlist" << std::endl;
    std::cout << "3.Search song" << std::endl;
    std::cout << "4.Search artist" << std::endl;
    std::cout << "5.Upload song" << std::endl;
    std::cout << "6.Exit" << std::endl;
    std::cout << "Please choose one of the options from above" << std::endl;

    int input = userInput();

    while(input != 1 && input != 2 && input != 3 && input != 4 && input != 5 && input != 6)
    {
        std::cout << "Please provide a valid input!" << std::endl;
        input = userInput();
    }

    if(input == 1)
        createPlaylist(name, surname);
    else if(input == 2)
        searchPlaylist(name, surname);
    else if(input == 3)
        searchSong(name, surname);
    else if(input == 4)
        searchArtist(name, surname);
    else if(input == 5)
        uploadSong(name, surname);
    else
        exitProcess();

}

void exitProcess()
{
    //system("CLS");
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "We hope we will see you soon! Goodbye!";
    std::this_thread::sleep_for(std::chrono::seconds(3));
    exit(0);
}