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