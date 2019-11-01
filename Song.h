//
// Created by jwall on 10/17/2019.
//
#ifndef SONG_H
#define SONG_H
#include <string>
using namespace std;
//Song class declaration
class Song
{
private:
    string title;
    string artist;
    int size;
public:
    //Default constructor
    //set the title and artist to "Empty" and the size to 512(MB)
    //not required in the assigment but can be useful in certain test cases for the driver
    Song();

    // Constructor with size parameter
    // set the title, artist and size to those input by the user.
    // the next pointer is default NULL unless a new one is entered by the user
    Song(string newTitle, string newArtist, int newSize);

    // numerous gets and sets used below so that the private instance variables can be accessed outside of the object
    // all assume valid inputs in the set functions
    void setTitle(string newTitle);
    void setArtist(string newArtist);
    void setSize(int newSize);
    string getTitle() const;
    string getArtist() const ;
    int getSize() const ;

    //overloading comparison operators so that I can compare the songs in sortSongList() and removeSong()
    bool operator<(Song const &s2);
    bool operator>(Song const &s2);
    bool operator==(Song const &s2){
        return (title.compare(s2.getTitle()) == 0) && (artist.compare(s2.getArtist()) == 0) && (s2.getSize() == size);
    }
};



#endif
