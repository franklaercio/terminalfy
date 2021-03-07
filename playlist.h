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

        friend PlayList* operator + (PlayList const &s1, PlayList const &s2) {
            PlayList *result = new PlayList();
            return result; 
        }
};	
  
#endif