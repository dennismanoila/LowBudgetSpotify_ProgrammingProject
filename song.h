
#ifndef LOWBUDGETSPOTIFY_SONG_H
#define LOWBUDGETSPOTIFY_SONG_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include "app.h"
#include "utils.h"

extern std::list<struct Song> globalSongList;

struct Song {
    std::string artistName;
    std::string songName;
};

void loadSongFromTXT();
void searchSong(const std::string& name, const std::string& surname);
void uploadSong(const std::string& name, const std::string& surname);
void searchArtist(const std::string& name, const std::string& surname);
void addSongToTXT(const std::string& artistName, const std::string& songName);

#endif //LOWBUDGETSPOTIFY_SONG_H
