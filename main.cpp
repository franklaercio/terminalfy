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
        cout << "----------> MENU <----------" << endl;
        cout << "[0] - EXIT" << endl;
        cout << "[1] - ADD SONG" << endl;
        cout << "[2] - DELETE SONG" << endl;
        cout << "[3] - VIEW ALL SONGS" << endl;
        cout << "[4] - FIND A SONG" << endl;
        cout << "[5] - NEW PLAYLIST" << endl;
        cout << "[6] - ADD MUSIC TO PLAYLIST" << endl;
        cout << "[7] - REMOVE MUSIC OF PLAYLIST" << endl;
        cout << "[8] - VIEW ALL PLAYLIST" << endl;
        cout << "[9] - LIST ALL MUSIC BY PLAYLIST" << endl;
        cout << "[10] - ADDING ONE OR MORE SONGS IN SONGLIST" << endl;
        cout << "[11] - DELETE ONE OR MORE SONGS IN SOGLIST" << endl;
        cout << "[12] - OVERLOAD SONGLIST WITH OPERATION +" << endl;
        cout << "[13] - REMOVE LAST MUSIC OF SONGLIST" << endl;
        cout << "[14] - ADDING SONG IN THE LAST OF SONGLIST" << endl;
        cout << "[15] - ADDING ONE OR MORE SONGS IN PLAYLIST" << endl;
        cout << "[16] - DELETE ONE OR MORE SONGS IN PLAYLIST" << endl;
        cout << "[17] - UNION OF TWO PLAYLISTS ANOTHER REPEAT" << endl;
        cout << "[18] - CREATE A NEW PLAYLIST WITH A COPY ONE PLAYLIST AND ADD ONE MORE MUSIC" << endl;
        cout << "[19] - CASE CREATE A PLAYLIST A - B" << endl;
        cout << "[20] - CREATE A NEW PLAYLIST WITH DELETE ONE MUSIC" << endl;
        cout << "[21] - DELETE LAST MUSIC OF PLAYLIST" << endl;
        cout << "[22] - ADD MUSIC OF LAST POSITION PLAYLIST" << endl;
        cout << "Type an option: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 0: {
                exit = true;
                break;
            } case 1: {
                cout << "----------> ADD SONG <----------" << endl;

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
                cout << "----------> REMOVE SONG <----------" << endl;

                cout << "Type a title: ";
                cin >> ws;
                getline(cin,title); 
                cout << endl;

                songList-> remove(title);
                break;  
            } case 3: {
                cout << "----------> LIST ALL SONG <----------" << endl;
                songList-> list();
                break;
            } case 4: {
                cout << "----------> FIND A SONG <----------" << endl;

                cout << "Type a title: ";
                cin >> ws;
                getline(cin,title);

                Song *song = new Song(); 

                *song = songList->findSong(title);

                cout << song->getTitle() << endl;

                break;
            } case 5: {
                cout << "----------> NEW PLAYLIST <----------" << endl;

                SongList *playlistMusic = new SongList();

                cout << "Type a playlist name: ";
                cin >> ws;
                getline(cin,namePlaylist); 

                playList->add(namePlaylist, playlistMusic);

                break;
            } case 6: {
                cout << "----------> ADD MUSIC TO PLAYLIST <----------" << endl;

                cout << "Type a playlist name: ";
                cin >> ws;
                getline(cin,namePlaylist); 

                playlistNode list = playList->findPlaylistNode(namePlaylist);

                if(!list.name.empty()) {
                    cout << "Type a music title: ";
                    cin >> ws;
                    getline(cin,title);

                    Song *song = new Song(); 
                    *song = songList->findSong(title);

                    if(!song->getTitle().empty()) {
                        list.songList->add(*song);
                    }else{
                        cout << "Sorry! Can't found a song: " + title << endl;
                    }
                } else {
                    cout << "Sorry! Can't found a playlist: " + namePlaylist << endl;
                }

                break;
            } case 7: {
                cout << "----------> REMOVE MUSIC OF PLAYLIST <----------" << endl;

                cout << "Type a playlist name: ";
                cin >> ws;
                getline(cin,namePlaylist); 

                playlistNode list = playList->findPlaylistNode(namePlaylist);

                if(!list.name.empty()) {
                    cout << "Type a music title: ";
                    cin >> ws;
                    getline(cin,title);

                    Song *song = new Song(); 
                    *song = songList->findSong(title);

                    if(!song->getTitle().empty()) {
                        list.songList->remove(title);
                    }else{
                        cout << "Sorry! Can't found a song: " + title << endl;
                    }
                } else {
                    cout << "Sorry! Can't found a playlist: " + namePlaylist << endl;
                }

                break;
            } case 8: {
                cout << "----------> VIEW ALL PLAYLIST <----------" << endl;
                playList->listAll();
                break;
            } case 9: {
                cout << "----------> LIST ALL MUSIC BY PLAYLIST <----------" << endl;

                cout << "Type a playlist name: ";
                cin >> ws;
                getline(cin,namePlaylist);

                playList->listAllMusicByPlaylistName(namePlaylist);
                
                break;
            } case 10: {
                songList -> add(songList);
                break;
            } case 11: {
                songList -> remove(songList);

                break;
            } case 12: {
                SongList *firstList = new SongList();
                SongList *secondList = new SongList();

                cout << "----------> Adding First List <----------" << endl;
                firstList -> add(firstList);

                cout << "----------> Adding Second List <----------" << endl;
                secondList -> add(secondList);

                SongList *resultList;
                resultList = (*firstList + *secondList);

                cout << "----------> First List <----------" << endl;
                firstList->list();

                cout << "----------> Second List <----------" << endl;
                secondList->list();

                cout << "----------> First List + Second List <----------" << endl;
                resultList->list();

                break;
            } case 13: {
                *songList >> *songList;
                break;
            } case 14: {
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

                songList << *song;

                break;
            } case 15: {
                playList->add(playList, songList);
                break;
            } case 16: {
                playList->removeSongs(playList, songList);
                break;
            } case 17: {
                cout << "----------> UNION OF TWO PLAYLISTS <----------" << endl;
                cout << "Type a playlist name of playlist one: ";
                cin >> ws;
                getline(cin,namePlaylist); 

                playlistNode listOne = playList->findPlaylistNode(namePlaylist);

                if(!listOne.name.empty()) {
                    cout << "Type a playlist name of playlist two: ";
                    cin >> ws;
                    getline(cin,namePlaylist); 

                    playlistNode listTwo = playList->findPlaylistNode(namePlaylist);

                    if(!listTwo.name.empty()) {
                        cout << "Type a playlist name for this union: ";
                        cin >> ws;
                        getline(cin,namePlaylist);

                        playlistNode *newPlayList;
                        newPlayList = (listOne + listTwo);

                        playList->add(namePlaylist, newPlayList->songList);
                    }else{
                        cout << "Can't find a playlist, try again please!";
                    }    
                }else{
                    cout << "Can't find a playlist, try again please!";
                }

                break;
            } case 18: {
                cout << "----------> CREATE A NEW PLAYLIST WITH A COPY ONE PLAYLIST AND ADD ONE MORE MUSIC <----------" << endl;
                cout << "Type a playlist name of exists playlist: ";
                cin >> ws;
                getline(cin,namePlaylist); 

                playlistNode listNodeMusics = playList->findPlaylistNode(namePlaylist);

                if(!listNodeMusics.name.empty()) {
                    cout << "Type a playlist name for new playlist: ";
                    cin >> ws;
                    getline(cin,namePlaylist);

                    playlistNode *newPlayListNode;
                    newPlayListNode = (*newPlayListNode + listNodeMusics.songList);

                    playList->add(namePlaylist, newPlayListNode->songList);
                }else{
                    cout << "Can't find a playlist, try again please!";
                }

                break;
            } case 19: {
                cout << "----------> CASE CREATE A PLAYLIST A - B <----------" << endl;
                cout << "Type a playlist name of playlist one: ";
                cin >> ws;
                getline(cin,namePlaylist); 

                playlistNode listOne = playList->findPlaylistNode(namePlaylist);

                if(!listOne.name.empty()) {
                    cout << "Type a playlist name of playlist two: ";
                    cin >> ws;
                    getline(cin,namePlaylist); 

                    playlistNode listTwo = playList->findPlaylistNode(namePlaylist);

                    if(!listTwo.name.empty()) {
                        cout << "Type a playlist name for this union: ";
                        cin >> ws;
                        getline(cin,namePlaylist);

                        playlistNode *newPlayList;
                        newPlayList = (listOne - listTwo);

                        playList->add(namePlaylist, newPlayList->songList);
                    }else{
                        cout << "Can't find a playlist, try again please!";
                    }    
                }else{
                    cout << "Can't find a playlist, try again please!";
                }

                break;
            } case 20: {
                cout << "----------> CREATE A NEW PLAYLIST WITH DELETE ONE MUSIC <----------" << endl;
                cout << "Type a playlist name of exists playlist: ";
                cin >> ws;
                getline(cin,namePlaylist); 

                playlistNode listNodeMusics = playList->findPlaylistNode(namePlaylist);

                if(!listNodeMusics.name.empty()) {
                    cout << "Type a playlist name for new playlist: ";
                    cin >> ws;
                    getline(cin,namePlaylist);

                    playlistNode *newPlayListNode;
                    newPlayListNode = (*newPlayListNode - listNodeMusics.songList);

                    playList->add(namePlaylist, newPlayListNode->songList);
                }else{
                    cout << "Can't find a playlist, try again please!";
                }

                break;
            } case 21: {
                cout << "----------> DELETE LAST MUSIC OF PLAYLIST <----------" << endl;
                cout << "Type a playlist name of exists playlist: ";
                cin >> ws;
                getline(cin,namePlaylist); 

                playlistNode listNodeMusics = playList->findPlaylistNode(namePlaylist);

                if(!listNodeMusics.name.empty()) {
                    playList >> listNodeMusics;
                }else{
                    cout << "Can't find a playlist, try again please!";
                }

                break;
            } case 22: {
                cout << "----------> ADD MUSIC OF LAST POSITION PLAYLIST <----------" << endl;
                cout << "Type a playlist name of exists playlist: ";
                cin >> ws;
                getline(cin,namePlaylist); 

                playlistNode listNodeMusics = playList->findPlaylistNode(namePlaylist);

                if(!listNodeMusics.name.empty()) {
                    playList << listNodeMusics;
                }else{
                    cout << "Can't find a playlist, try again please!";
                }

                break;
            }
            default:
                cout << "ERROR: type a valid option!" << endl;   
        }
    } while(exit != true);

    return 0;
}
