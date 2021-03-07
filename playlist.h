#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"
#include "songlist.h"
#include <string>

using namespace std;

struct playlistNode {
    string name;
    SongList *songList;
    playlistNode *next;

    friend playlistNode* operator + (playlistNode const &listOne, playlistNode const &listTwo) {
        playlistNode *node = new playlistNode;
        SongList *songList = new SongList();

        songList = songList->unionTwoListAnotherRepeatMusic(listOne.songList, listTwo.songList);
        node->songList = songList;

        return node;
    }

    friend playlistNode* operator + (playlistNode const &listOne, SongList *songList) {
        playlistNode *node = new playlistNode;
        string title, songwiter;

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

        songList = songList;
        node->songList = songList;

        return node;
    }

    friend playlistNode* operator - (playlistNode const &a, playlistNode const &b) {
        playlistNode *node = new playlistNode;
        SongList *songList = new SongList();

        songList = songList->unionTwoListAnotherRepeatMusic(a.songList, b.songList);
        node->songList = songList;

        return node;
    }

    friend playlistNode* operator - (playlistNode const &listOne, SongList *songList) {
        playlistNode *node = new playlistNode;
        string title;

        cout << "Type a music title for remove: ";
        cin >> ws; 
        getline(cin,title);

        songList-> remove(title);
        node->songList = songList;

        return node;
    }
};	

class PlayList {
    private:
        string name;
        playlistNode *songList;
        playlistNode *head;
        playlistNode *tail;
    public:
        PlayList() {
            head = NULL;
            tail = NULL;
        }

        PlayList(const PlayList &anotherList) {
            PlayList *newSongList =new PlayList();
            *newSongList = (anotherList);
        }

        void create(string name, SongList songList);

        void listAll();

        void add(string playlistName, SongList *songlist);

        void add(PlayList *playlist, SongList *songList);

        void addSong(Song *song);

        void removeSongs(PlayList *playList, SongList *songList);

        void listAllMusicByPlaylistName(string playlistName);

        string getName();

        void setName(string name);

        playlistNode findPlaylistNode(string playlistName);

        friend PlayList* operator >> (PlayList *playlist, playlistNode const &list) {
            playlistNode *node = new playlistNode;
            SongList *songList = new SongList();

            songList = songList->deleteLastmusic(list.songList);
            node->songList = songList;

            playlistNode *current = new playlistNode;
            current = playlist->head;

            while(current != NULL) {
                if(current->name.compare(list.name) == 0) {
                    current->songList = songList;
                }  

                current = current->next;
            }

            return playlist;
        }
};
  
#endif