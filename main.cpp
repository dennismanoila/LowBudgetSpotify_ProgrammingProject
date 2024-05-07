#include <iostream>
#include "user.h"
#include "song.h"
#include "playlist.h"
#include "app.h"

int main() {

    loadUsersFromTXT();
    loadSongFromTXT();
    loadPlaylistFromTXT();

    display_initialPage();

    while(true) {

        int input = userInput();

        while (input != 1 && input != 2 & input != 3) {
            std::cout << "Please provide a valid input!" << std::endl;
            input = userInput();
        }

        if (input == 1)
            loginProcess();
        else if (input == 2)
            signUpProcess();
        else if (input == 3)
            break;
    }
    exitProcess();
    return 0;
}
