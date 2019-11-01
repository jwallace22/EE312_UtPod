//
// Created by jwall on 10/17/2019.
//
#include "Song.h"

using namespace std;

// default constructor created in case I wanted to test my code with an array of songs in the future
Song::Song() {
    title = "Empty";
    artist = "Empty";
    int size = 512;
}

// main constructor used, assuming that a valid song is passed into UtPod driver
Song::Song(string newTitle, string newArtist, int newSize) {
    title = newTitle;
    artist = newArtist;
    size = newSize;
}

// numerous gets and sets used below so that the private instance variables can be accessed outside of the object
// all assume valid inputs in the set functions
void Song::setArtist(string newArtist) {
    artist = newArtist;
}

void Song::setSize(int newSize) {
    if((newSize > 0)&&(newSize < 512)) {
        size = newSize;
    }
    else{
        size = 512;
    }
}

void Song::setTitle(string newTitle) {
    title = newTitle;
}

string Song::getArtist() const {
    return artist;
}

int Song::getSize() const {
    return size;
}

string Song::getTitle() const {
    return title;
}
//overloading comparison operators so that I can compare the songs in sortSongList() and removeSong()
bool Song::operator>(Song const &s2){
    int titleCompare = title.compare(s2.title);
    int artistCompare = artist.compare(s2.artist);
    int size2 = s2.size;
    if(artistCompare > 0){
        return true;
    }
    else if((artistCompare==0)&&(titleCompare>0)){
        return true;
    }
    else if((artistCompare==0)&&(titleCompare==0)&&(size>size2)){
        return true;
    }
    else{
        return false;
    }
}

bool Song::operator<(Song const &s2){
    int titleCompare = title.compare(s2.title);
    int artistCompare = artist.compare(s2.artist);
    int size2 = s2.size;
    if(artistCompare < 0){
        return true;
    }
    else if((artistCompare==0)&&(titleCompare<0)){
        return true;
    }
    else if((artistCompare==0)&&(titleCompare==0)&&(size<size2)){
        return true;
    }
    else{
        return false;
    }
}
