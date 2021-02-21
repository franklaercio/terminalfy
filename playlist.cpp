#include "playlist.h"

using namespace std;

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

void PlayList::add(string playlistName, SongList *musics) {
    playlistNode *temp = new playlistNode;
    temp->name=playlistName;
    temp->songList=musics;
    temp->next = head;
    head = temp;
}

SongList PlayList::getSongListByPlaylistName(string playlistName) {
    playlistNode *current = new playlistNode;
    current = head;

    SongList *songList = new SongList();

    while(current != NULL) {
      if(current->name.compare(playlistName) == 0)  {
          songList = current->songList;
          return *songList;
      }

      current = current->next;
    }

    return *songList;
}

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

string PlayList::getName() {
    return this->name;
}

void PlayList::setName(string name){
    this->name = name;
}

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