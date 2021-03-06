#include <iostream>

#include "songlist.h"

using namespace std;

/**
 *  Function for create the songlist node
 *  
 *  @return
*/
void SongList::create(Song song) {
    node *temp = new node;
    temp->data = song;
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
 *  Function for list all of music
 *  
 *  @return
*/
void SongList::list() {
    node *current = new node;
    current = head;   

    int count = 1;

    if(current == NULL) {
        cout << "Can't found a song because your songlist is empty." << endl; 
    }

    while(current != NULL) {
      if(current->data.getTitle().empty() && count == 1) {
          cout << "Can't found a song because your songlist is empty." << endl; 
      }else{
          cout << count << ": " << current-> data.getTitle() << " - " << current-> data.getSongwriter() << endl;
      }    

      current = current->next;

      count += 1;
    }
}

/**
 *  Function for find the song in songlist
 *  
 *  @return Song
*/
Song SongList::findSong(string songName) {
    node *current = new node;
    current = head;

    int count = 1;

    Song *song = new Song();

    if(current == NULL) {
        cout << "Can't found a song because your songlist is empty." << endl; 
        return *song;
    }

    while(current != NULL) {
      if(current->data.getTitle().compare(songName) == 0) {
          song = &current->data;
          return *song;
      }   

      current = current->next;
    }

    cout << "Can't found the music." << endl;
    return *song;
}

/**
 *  Function for add the song in songlist
 *  
 *  @return
*/
void SongList::add(Song song) {
    node *temp = new node;
    temp->data = song;
    temp->next = head;
    head = temp;
}

/**
 *  Function overload for add on or more musics
 *  
 *  @return
*/
void SongList::add(SongList *songList) {
    bool exit = false;
    int option;
    string title, songwriter;
    
    do {
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
            cout << "Type a title: ";
            cin >> ws; 
            getline(cin,title);

            cout << "Type a songwriter: ";
            cin >> ws; 
            getline(cin,songwriter); 
            cout << endl;

            Song *song = new Song();
            song->setTitle(title);
            song->setSongwriter(songwriter);

            songList->add(*song);

            break;
        }
        default:
            break;
        }
    } while(exit != true);
}

/**
 *  Function for remove a song in songlist
 *  
 *  @return
*/
void SongList::remove(string songTitle) {
    node *current=new node;
    node *previous=new node;

    current=head;

    while(current != NULL) {
        string title = current->data.getTitle();
        
        if((title.compare(songTitle)) == 0) { 
            break; 
        } else {
            previous = current; 
            current = current->next;
        }
    }

    if(current == NULL) {
        cout << "Can't remove value: no match found." << endl; 
    } else {
        cout << "Deleting: " << current->data.getTitle() << endl;
        previous->next = current->next;
        delete current;
    }
}

/**
 *  Function overload for remove on or more musics
 *  
 *  @return
*/
void SongList::remove(SongList *songList) {
    bool exit = false;
    int option;
    string title;
    
    do {
        cout << "----------> REMOVING SONGS <----------" << endl;
        cout << "[0] - STOP " << endl;
        cout << "[1] - REMOVE A SONG" << endl;
        cout << "Type an option: ";
        cin >> option;
        cout << endl;

        switch (option) {
        case 0:
            exit = true;
            break;
        case 1: {
            cout << "Type a title: ";
            cin >> ws; 
            getline(cin,title);

            songList->remove(title);

            break;
        }
        default:
            break;
        }
    } while(exit != true);
}

/**
 *  Function overload for union two playlists another repeat music
 *  
 *  @return
*/
SongList* SongList::unionTwoListAnotherRepeatMusic(SongList *one, SongList *two) {
    SongList* newSongList = new SongList();

    node *currentOne = new node;
    currentOne = one->head;  

    while(currentOne != NULL) {
      newSongList->add(currentOne->data);  
      currentOne = currentOne->next;
    }

    node *currentTwo = new node;
    currentTwo = two->head;

    while(currentTwo != NULL) {
      Song *song = new Song();
      *song = newSongList->findSong(currentTwo->data.getTitle());  

      if(song->getTitle().empty()) {
          newSongList->add(currentTwo->data);
      }

      currentTwo = currentTwo->next;
    }

    return newSongList;
}

/**
 *  Function for delete last music of songlist
 *  
 *  @return
*/
SongList* SongList::deleteLastmusic(SongList *songList) {
    node *current=new node;
    node *previous=new node;

    current = songList->head;

    while(current != NULL) {
        if(current->next == NULL) {
            break;
        }

        previous = current; 
        current = current->next;
    }

    if(current != NULL) {
        cout << "Deleting: " << current->data.getTitle() << endl;
        previous->next = current->next;

        delete current;
    }else{
        cout << "Can't delete last music, bescause your songlist is empty!" << endl;
    }

    return songList;
}