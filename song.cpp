#include "song.h"

std::list<struct Song> globalSongList;

void loadSongFromTXT()
{
    std::ifstream file("C:\\Users\\Denis\\Desktop\\CLionProjects\\LowBudgetSpotify\\song.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file: playlist.txt" << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string artistName, songName;

        getline(iss, artistName, ',');
        getline(iss, songName);

        Song newSong = {artistName, songName};
        globalSongList.push_back(newSong);
    }

    file.close();
}

void searchSong(const std::string& name, const std::string& surname)
{
    //system("CLS");
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "What song are you looking for?\n->";

    std::string songName;
    std::getline(std::cin, songName);
    int count = 0;

    std::list<Song>::iterator temp = globalSongList.begin();

    std::string str, substr;
    while(temp != globalSongList.end())
    {
        str = temp->songName;
        substr = songName;
        str = toLower(str);
        substr = toLower(substr);
        if(str.find(substr) != std::string::npos)
            std::cout << temp->artistName << " - " << temp->songName << std::endl, count++;
        ++temp;
    }

    str = toLower(temp->songName);
    substr = toLower(songName);
    if(str.find(substr) != std::string::npos)
        std::cout << temp->artistName << " - " << temp->songName << std::endl, count++;

    if(count != 1)
        std::cout << "We have found " << count << " results that match your input!";
    else
        std::cout << "We have found 1 result that matches your input!";

    std::cout << std::endl << "Press any key to go back to the menu:";

    std::string randomInput;
    std::cin >> randomInput;

    //system("CLS");
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    display_mainMenu(name, surname);
}

void searchArtist(const std::string& name, const std::string& surname)
{
    std::string artists[100];
    nullArr(artists);
    int count = 0;

    //system("CLS");
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "What artist are you looking for?\n->";

    std::string artistName;
    std::getline(std::cin, artistName);

    std::list<Song>::iterator temp = globalSongList.begin();

    std::string str, substr;
    while(temp != globalSongList.end())
    {
        str = temp->artistName;
        substr = artistName;
        str = toLower(str);
        substr = toLower(substr);
        if(str.find(substr) != std::string::npos && !(inArr(artists, str, count)))
        {
            artists[count++] = str;
            std::cout << temp->artistName << std::endl;
            std::cout << "----------------------" << std::endl;

            std::list<Song>::iterator tmp = globalSongList.begin();

            while(tmp != globalSongList.end())
            {
                if(tmp->artistName == temp->artistName)
                    std::cout << tmp->artistName << " - " << tmp->songName << std::endl;
                tmp++;
            }
            if(tmp->artistName == temp->artistName)
                std::cout << tmp->artistName << " - " << tmp->songName << std::endl;

            std::cout << std::endl << std::endl;

        }
        ++temp;
    }

    str = temp->artistName;
    substr = artistName;
    str = toLower(str);
    substr = toLower(substr);
    if(str.find(substr) != std::string::npos && !(inArr(artists, str, count)))
    {
        artists[count++] = str;
        std::cout << temp->artistName << std::endl;
        std::cout << "----------------------" << std::endl;

        std::list<Song>::iterator tmp = globalSongList.begin();

        while(tmp != globalSongList.end())
        {
            if(tmp->artistName == temp->artistName)
                std::cout << tmp->artistName << " - " << tmp->songName << std::endl;
            tmp++;
        }
        if(tmp->artistName == temp->artistName)
            std::cout << tmp->artistName << " - " << tmp->songName << std::endl;


        std::cout << std::endl << std::endl;

    }

    if(count != 1)
        std::cout << "We have found " << count << " results that match your input!";
    else
        std::cout << "We have found 1 result that matches your input!";

    std::cout << std::endl << "Press any key to go back to the menu:";

    std::string randomInput;
    std::cin >> randomInput;

    //system("CLS");
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    display_mainMenu(name, surname);
}

void uploadSong(const std::string& name, const std::string& surname)
{
    //system("CLS");
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "We are glad that you are sharing your musical projects with us!" << std::endl;
    std::cout << "What's the name of your song?\n->";

    std::string songName;
    std::getline(std::cin, songName);

    std::cout << '\'' << songName << "' by " << surname << ' ' << name << " has officially been uploaded!";

    std::string artistName = surname + ' ' + name;

    Song newSong = {artistName, songName};
    globalSongList.push_back(newSong);

    addSongToTXT(artistName, songName);

    std::cout << std::endl << "Press any key to go back to the menu:";

    std::string randomInput;
    std::cin >> randomInput;

    //system("CLS");
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    display_mainMenu(name, surname);
}

void addSongToTXT(const std::string& artistName, const std::string& songName)
{
    std::string filename = "C:\\Users\\Denis\\Desktop\\CLionProjects\\LowBudgetSpotify\\song.txt";

    std::ofstream outFile(filename, std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for appending." << std::endl;
        return;
    }

    outFile << artistName << "," << songName << std::endl;

    outFile.close();
}