#include "playlist.h"

std::list<struct Playlist> globalPlaylistList;

void loadPlaylistFromTXT()
{
    std::ifstream file("C:\\Users\\Denis\\Desktop\\CLionProjects\\LowBudgetSpotify\\playlist.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file: playlist.txt" << std::endl;
        return;
    }

    std::string line;
    while (getline(file, line)) {
        std::istringstream iss(line);
        std::string name, songString;

        getline(iss, name, ',');
        getline(iss, songString);

        Playlist newPlaylist = {name, songString};
        globalPlaylistList.push_back(newPlaylist);
    }

    file.close();
}

void addPlaylistToTXT(const std::string& playlistName, const std::string& songString)
{
    std::string filename = "C:\\Users\\Denis\\Desktop\\CLionProjects\\LowBudgetSpotify\\playlist.txt";

    std::ofstream outFile(filename, std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Failed to open file for appending." << std::endl;
        return;
    }

    outFile << playlistName << "," << songString << std::endl;

    outFile.close();
}

void createPlaylist(const std::string& name, const std::string& surname)
{
    int validName;
    std::string playlistName;
    validName = 1;
    //system("CLS");
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "What name would you like to give to your playlist?\n->";
    //std::getline(std::cin, playlistName);
    while(true)
    {

        std::getline(std::cin, playlistName);

        std::list<Playlist>::iterator it;
        for(it = globalPlaylistList.begin(); it != globalPlaylistList.end(); ++it)
        {
            if(it->name == playlistName)
            {
                validName = 0;
                break;
            }
        }
        if(it->name == playlistName)
            validName = 0;

        if(validName == 0)
        {
            std::cout << "A playlist called '" << playlistName << "' already exist!" << std::endl;
            std::cout << "Please try another name!" << std::endl;
            std::cout << "Press any key to proceed further:";
            std::string key;
            std::cin >> key;
            validName = 1;
            std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            std::cout << "What name would you like to give to your playlist?\n->";
            std::getline(std::cin, playlistName);
        }
        else break;
    }

    std::cout << "\nPlaylist name: " << playlistName << std::endl;

    int adding = 1;
    int found = 0;
    std::string songString, song;
    songString = '\"';
    bool added;
    while(adding)
    {
        added = false;
        found = 0;
        std::string addedSong;
        std::cout << "What song would you like to add?\n->";

        std::getline(std::cin , song);

        std::list<Song>::iterator it;
        std::string str, substr;

        for(it = globalSongList.begin(); it != globalSongList.end(); ++it)
        {
            str = toLower(it->songName);
            substr = toLower(song);

            if(str == substr)
            {
                found = 1;
                addedSong = it->songName;
                break;
            }
        }

        str = toLower(it->songName);
        substr = toLower(song);

        if(str == substr) {
            found = 1;
            addedSong = it->songName;
        }

        if(found)
        {
            if(!(checkIfSubstr(songString, addedSong)))
                songString += addedSong, added = true;

            std::cout << "Would you like to add another song?" << std::endl;
            std::cout << "Type '1' if yes, else type '2'." << std::endl;

            int answer = userInput();

            while(answer != 1 && answer != 2)
            {
                std::cout << "Please provide a valid input!" << std::endl;
                answer = userInput();
            }

            if(answer == 1)
            {
                //system("CLS");
                std::cout << "\n\n\n\n\n\n\n\n";
                if(added)
                    songString += ',';
            }
            else
            {
                //system("CLS");
                std::cout << "\n\n\n\n\n\n\n\n\n\n";

                songString += '"';

                removeDoubleCommas(songString);
                addPlaylistToTXT(playlistName, songString);

                Playlist newPlaylist = {playlistName, songString};
                globalPlaylistList.push_back(newPlaylist);

                std::cout << playlistName << '-' << songString << std::endl;
                std::cout << "Playlist successfully added!" << std:: endl;
                std::cout << std::endl << "Press any key to go back to the menu:";

                std::string randomInput;
                std::cin >> randomInput;

                //system("CLS");
                std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                adding = 0;
            }
        }
        else
        {
            std::string matches[100];
            nullArr(matches);
            int cnt = 0;

            for(it = globalSongList.begin(); it != globalSongList.end(); ++it)
            {
                str = toLower(it->songName);
                substr = toLower(song);
                if(str.find(substr) != std::string::npos)
                    matches[++cnt] = it->songName;
            }
            str = toLower(it->songName);
            substr = toLower(song);
            if(str.find(substr) != std::string::npos)
                matches[++cnt] = it->songName;

            if(cnt)
            {
                //system("CLS");
                std::cout << "\n\n\n\n\n\n\n\n\n";
                std::cout << "We didn't find any song called '" << song << "'." << std::endl;
                std::cout << "Below you can see results similar with your input:" << std::endl;

                for(int i = 1; i <= cnt; i++)
                    std::cout << i << '.' << matches[i] << std::endl;

                if(cnt == 1)
                    std::cout << "Do you want to add this song to your playlist?" << std::endl;
                else
                    std::cout << "Do you want to add one of these songs to your playlist?" << std::endl;

                std::cout << "Type '1' if yes, else type '2'." << std::endl;

                int answer = userInput();
                while(answer != 1 && answer != 2)
                {
                    std::cout << "Please provide a valid input!" << std::endl;
                    answer = userInput();
                }

                if(answer == 1)
                {
                    std::cout << "Great! Please type the index of the desired song!" << std::endl;

                    int index = userInput();
                    while(index < 1 || index > cnt)
                    {
                        std::cout << "Please provide a valid input!" << std::endl;
                        index = userInput();
                    }
                    addedSong = matches[index];

                    if(!(checkIfSubstr(songString, addedSong)))
                        songString += addedSong, added = true;

                    std::cout << "Would you like to add another song?" << std::endl;
                    std::cout << "Type '1' if yes, else type '2'." << std::endl;

                    int answ = userInput();

                    while(answ != 1 && answ != 2)
                    {
                        std::cout << "Please provide a valid input!" << std::endl;
                        answ = userInput();
                    }

                    if(answ == 1)
                    {
                        //system("CLS");
                        std::cout << "\n\n\n\n\n\n\n\n";
                        if(added)
                            songString += ',';
                    }
                    else
                    {
                        //system("CLS");
                        std::cout << "\n\n\n\n\n\n\n\n\n\n";

                        songString += '"';

                        removeDoubleCommas(songString);
                        addPlaylistToTXT(playlistName, songString);

                        Playlist newPlaylist = {playlistName, songString};
                        globalPlaylistList.push_back(newPlaylist);

                        std::cout << playlistName << '-' << songString << std::endl;
                        std::cout << "Playlist successfully added!" << std:: endl;
                        std::cout << std::endl << "Press any key to go back to the menu:";

                        std::string randomInput;
                        std::cin >> randomInput;

                        //system("CLS");
                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        adding = 0;
                    }
                }
                else
                {
                    //system("CLS");
                    std::cout << "\n\n\n\n\n\n\n\n\n\n";
                    std::cout << "Would you like to add other songs?" << std::endl;
                    std::cout << "Type '1' if yes, else type '2'." << std::endl;

                    int ans = userInput();
                    while(ans != 1 && ans != 2)
                    {
                        std::cout << "Please provide a valid input!" << std::endl;
                        ans = userInput();
                    }

                    if(ans == 1)
                        //system("CLS");
                        std::cout << "\n\n\n\n\n\n\n\n\n\n";
                    else
                    {
                        //system("CLS");
                        std::cout << "\n\n\n\n\n\n\n\n\n\n";

                        songString += '"';

                        removeDoubleCommas(songString);
                        addPlaylistToTXT(playlistName, songString);

                        Playlist newPlaylist = {playlistName, songString};
                        globalPlaylistList.push_back(newPlaylist);

                        std::cout << playlistName << '-' << songString << std::endl;
                        std::cout << "Playlist successfully added!" << std:: endl;
                        std::cout << std::endl << "Press any key to go back to the menu:";

                        std::string randomInput;
                        std::cin >> randomInput;

                        //system("CLS");
                        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                        adding = 0;
                    }
                }
            }
            else
            {
                //system("CLS");
                std::cout << "\n\n\n\n\n\n\n\n\n";
                std::cout << "There are no results that match your input!" << std::endl;
                std::cout << "Would you like to add another song?" << std::endl;
                std::cout << "Type '1' if yes, else type '2'." << std::endl;

                int ans = userInput();
                while(ans != 1 && ans != 2)
                {
                    std::cout << "Please provide a valid input!" << std::endl;
                    ans = userInput();
                }

                if(ans == 1)
                    //system("CLS");
                    std::cout << "\n\n\n\n\n\n\n\n\n\n";
                else
                {
                    //system("CLS");
                    std::cout << "\n\n\n\n\n\n\n\n\n\n";

                    songString += '"';

                    removeDoubleCommas(songString);
                    addPlaylistToTXT(playlistName, songString);

                    Playlist newPlaylist = {playlistName, songString};
                    globalPlaylistList.push_back(newPlaylist);

                    std::cout << playlistName << '-' << songString << std::endl;
                    std::cout << "Playlist successfully added!" << std:: endl;
                    std::cout << std::endl << "Press any key to go back to the menu:";

                    std::string randomInput;
                    std::cin >> randomInput;

                    //system("CLS");
                    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    adding = 0;
                }

            }
        }

    }
    display_mainMenu(name, surname);
}

void searchPlaylist(const std::string& name, const std::string& surname)
{
    int count = 0;

    //system("CLS");
    std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    std::cout << "What playlist are you looking for?\n->";

    std::string playlistName;
    std::getline(std::cin, playlistName);

    std::cout << std::endl;

    std::list<Playlist>::iterator temp = globalPlaylistList.begin();

    std::string str, substr;

    while(temp != globalPlaylistList.end())
    {
        str = temp->name;
        substr = playlistName;

        str = toLower(str);
        substr = toLower(substr);

        if(str.find(substr) != std::string::npos)
        {
            count++;

            std::cout << temp->name << std::endl;
            std::cout << "----------------------" << std::endl;

            parseAndPrint(temp->songString);

            std::cout << std::endl << std::endl;

        }
        ++temp;
    }

    str = temp->name;
    substr = playlistName;

    str = toLower(str);
    substr = toLower(substr);

    if(str.find(substr) != std::string::npos)
    {
        std::cout << temp->name << std::endl;
        std::cout << "----------------------" << std::endl;

        parseAndPrint(temp->songString);

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
