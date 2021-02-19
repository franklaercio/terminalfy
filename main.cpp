#include <iostream>

#include "song.h"
#include "songlist.h"
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
    string title, songwiter, namePlaylist;
    SongList *songList = new SongList();
    PlayList *playList = new PlayList();

    do{
        cout << "--------MENU---------------" << endl;
        cout << "[0] - EXIT" << endl;
        cout << "[1] - ADD SONG" << endl;
        cout << "[2] - DELETE SONG" << endl;
        cout << "[3] - VIEW ALL SONGS" << endl;
        cout << "[4] - FIND A SONG" << endl;
        cout << "[5] - NEW PLAYLIST" << endl;
        cout << "[6] - VIEW ALL PLAYLIST" << endl;
        cout << "Type an option: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 0: {
                exit = true;
                break;
            } case 1: {
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

                songList-> add(*song);
                break;  
            } case 2: {
                cout << "--------REMOVE SONG-----------------" << endl;

                cout << "Type a title: ";
                cin >> ws;
                getline(cin,title); 
                cout << endl;

                songList-> remove(title);
                break;  
            } case 3: {
                cout << "--------LIST ALL SONG-------------" << endl;
                songList-> list();
                break;
            } case 4: {
                cout << "--------FIND A SONG-------------" << endl;

                cout << "Type a title: ";
                cin >> ws;
                getline(cin,title);

                Song *song = new Song(); 

                *song = songList->findSong(title);

                cout << song->getTitle() << endl;

                break;
            } case 5: {
                cout << "--------NEW PLAYLIST-------------" << endl;

                cout << "Type a title: ";
                cin >> ws;
                getline(cin,namePlaylist); 

                playList->create(namePlaylist);

                break;
            } case 6: {
                cout << "--------VIEW ALL PLAYLIST-------------" << endl;

                playList->listAll();
                
                break;
            }
            default:
                cout << "ERROR: type a valid option!" << endl;   
        }
    } while(exit != true);

    return 0;
}
