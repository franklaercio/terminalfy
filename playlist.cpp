#include <iostream>

#include "playlist.h"

using namespace std;

/**
 *  Function for create a playlist
 *  
 *  @return
*/
void PlayList::create(string name, SongList songList) {
    playlistNode *temp = new playlistNode;
    temp->name=name;
    temp->songList = &songList;
    temp->next=NULL;
    
    if(head==NULL) {
        head=temp;
        tail=temp;
        temp=NULL;
    } else {	
        tail->next=temp;
        tail=temp;
    }
}

/**
 *  Function for list all playlist
 *  
 *  @return
*/
void PlayList::listAll() {
    playlistNode *current = new playlistNode;
    current = head;

    int count = 1;

    if(current == NULL) {
        cout << "Can't found a playlist because your playlist is empty." << endl; 
    }

    while(current != NULL) {
      if(current->name.empty() && count == 1) {
          cout << "Can't found a playlist because your playlist is empty." << endl; 
      }else{
          cout << count << ": " << current->name << endl;
      }    

      current = current->next;

      count += 1;
    }
}

/**
 *  Function for add a playlist
 *  
 *  @return
*/
void PlayList::add(string playlistName, SongList *musics) {
    playlistNode *temp = new playlistNode;
    temp->name=playlistName;
    temp->songList=musics;
    temp->next = head;
    head = temp;
}

void PlayList::add(PlayList *playList, SongList *songList) {
    bool exit = false;
    int option;
    string title, songwriter, namePlaylist;

    cout << "Type a playlist name: ";
    cin >> ws;
    getline(cin,namePlaylist); 

    playlistNode list = playList->findPlaylistNode(namePlaylist);

    if(!list.name.empty()) {
        do{
            cout << "----------> ADDING SONGS <----------" << endl;
            cout << "[0] - STOP " << endl;
            cout << "[1] - ADD SONG" << endl;
            cout << "Type an option: ";
            cin >> option;
            cout << endl;

            switch (option) {
            case 0:
                exit = true;

                break;
            case 1: {
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

                break;
            }
            default:
                break;
            }
        } while (exit != true);
    } else {
        cout << "Sorry! Can't found a playlist: " + namePlaylist << endl;
    }
}

/**
 *  Function for list all music by name of playlist
 *  
 *  @return
*/
void PlayList::listAllMusicByPlaylistName(string playlistName) {
    playlistNode *current = new playlistNode;
    current = head;

    int count = 1;

    if(current == NULL) {
        cout << "Sorry! Can't found a playlist." << endl; 
    }

    while(current != NULL) {
      if(current->name.compare(playlistName) == 0) {
        current->songList->list();
      }

      current = current->next;
    }
}

/**
 *  Function for get the name of playlist
 *  
 *  @return string
*/
string PlayList::getName() {
    return this->name;
}

/**
 *  Function for setting the name of playlist
 *  
 *  @return
*/
void PlayList::setName(string name){
    this->name = name;
}

/**
 *  Function for find playlistnode
 *  
 *  @return playlistNode
*/
playlistNode PlayList::findPlaylistNode(string playlistName) {
    playlistNode *current = new playlistNode;
    current = head;

    playlistNode *playlist = new playlistNode();

    if(current == NULL) {
        cout << "Can't found a song because your songlist is empty." << endl; 
        return *playlist;
    }

    while(current != NULL) {
      if(current->name.compare(playlistName) == 0) {
          playlist = current;
          return *playlist;
      }   

      current = current->next;
    }

    cout << "Can't found the music." << endl;
    return *playlist;
}

void PlayList::removeSongs(PlayList *playList, SongList *songList) {
    bool exit = false;
    int option, count = 0;
    string title, songwriter, namePlaylist;

    cout << "Type a playlist name: ";
    cin >> ws;
    getline(cin,namePlaylist); 

    playlistNode list = playList->findPlaylistNode(namePlaylist);

    if(!list.name.empty()) {
        do{
            cout << "----------> REMOVING SONGS <----------" << endl;
            cout << "[0] - STOP " << endl;
            cout << "[1] - DELETE SONG" << endl;
            cout << "Type an option: ";
            cin >> option;
            cout << endl;

            switch (option) {
            case 0:
                exit = true;

                break;
            case 1: {
                cout << "Type a music title: ";
                cin >> ws;
                getline(cin,title);

                Song *song = new Song(); 
                *song = songList->findSong(title);

                if(!song->getTitle().empty()) {
                    list.songList->remove(title);
                    count++;
                }else{
                    cout << "Sorry! Can't found a song: " + title << endl;
                }

                break;
            }
            default:
                break;
            }
        } while (exit != true);

        cout << "Total of music deleted: " + count << endl;
    } else {
        cout << "Sorry! Can't found a playlist: " + namePlaylist << endl;
    }
}