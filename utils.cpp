#include "utils.h"

std::string toLower(std::string str)
{
    for (char& c : str) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return str;
}

void nullArr(std::string arr[100])
{
    for(int i = 0; i < 100; i++)
        arr[i] = '\0';
}

int inArr(std::string arr[100], const std::string& str, int size)
{
    for(int i = 0; i < size; i++)
        if(arr[i] == str)
            return 1;

    return 0;
}

void parseAndPrint(const std::string& songString)
{
    int i = 1;
    std::string song;
    song = "";
    while(songString[i] != '"')
    {
        if(songString[i] != ',' && songString[i+1] != '\"')
            song += songString[i];
        else
        {
            if(songString[i+1] == '\"')
                song+=songString[i];

            std::list<Song>::iterator temp = globalSongList.begin();

            while(temp != globalSongList.end())
            {
                if(song == temp->songName)
                    std::cout << temp->artistName << " - " << temp->songName << std::endl;
                ++temp;
            }
            song = "";
        }
        i++;
    }
}

bool checkIfSubstr(const std::string& str, const std::string& substr)
{
    if(str.find(substr) != std::string::npos)
    {
        std::cout << "This song is already in the playlist!" << std::endl;
        return true;
    }
    return false;
}

void removeDoubleCommas(std::string& str)
{
    for(int i = 0; i < str.length() - 1; i++)
    {
        if(str[i] == ',' && (str[i+1] == ',' || str[i+1] == '"'))
            str.erase(i, 1);
    }
}