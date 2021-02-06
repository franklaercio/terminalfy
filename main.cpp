#include <iostream>

#include "song.h"
#include "playlist.h"

using namespace std;

int main() {
    cout << "----------------------------Welcome!--------------------------------" << endl;
    cout << "This is an app Terminalfy." << endl;
    cout << "You can add a song, create playlist, adding yours song at playlist," << endl;
    cout << "remove yours song at playlist and other functionalities." << endl;
    cout << "--------------------------------------------------------------------" << endl;

    bool exit = false;
    int option;
    string title, songwiter;
    Playlist *playlist = new Playlist();

    do{
        cout << "--------------MENU---------------" << endl;
        cout << "[0] - EXIT" << endl;
        cout << "[1] - ADD SONG" << endl;
        cout << "[2] - VIEW PLAYLIST" << endl;
        cout << "Type an option: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 0: {
                exit = true;
                break;
            }
            case 1: {
                cout << "--------ADD SONG-----------------" << endl;
                cout << "Type a title: ";
                cin >> ws; 
                getline(cin,title);
                cout << "Type a songwriter: ";
                cin >> ws; 
                getline(cin,songwiter); 
                cout << endl;

                Song *song = new Song();
                song->setTitle(title);
                song->setSongwriter(songwiter);

                playlist-> add(*song);
                break;  
            }   
            case 2: {
                cout << "--------LIST ALL SONG-------------" << endl;
                playlist-> list();
                break;
            }
            default:
                cout << "ERROR: type a valid option!" << endl;   
        }
    }while(exit != true);

    // Song *song = new Song();
    // song -> setTitle("All you Gotta do is Call Me");
    // song -> setSongwriter("Barões da Pisadinha");

    // cout << "Song: " << song->getTitle() << endl;
    // cout << "Songwriter: " << song->getSongwriter() << endl;

    return 0;
}
