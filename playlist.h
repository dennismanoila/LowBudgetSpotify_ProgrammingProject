
#ifndef LOWBUDGETSPOTIFY_PLAYLIST_H
#define LOWBUDGETSPOTIFY_PLAYLIST_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include "song.h"
#include "app.h"
#include "utils.h"

extern std::list<struct Playlist> globalPlaylistList;

struct Playlist {
    std::string name;
    std::string songString;
};

void loadPlaylistFromTXT();
void createPlaylist(const std::string& name, const std::string& surname);
void searchPlaylist(const std::string& name, const std::string& surname);
void addPlaylistToTXT(const std::string& playlistName, const std::string& songString);

#endif //LOWBUDGETSPOTIFY_PLAYLIST_H
