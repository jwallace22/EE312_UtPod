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
    Song();
    //Constructor with size parameter
    // set the title, artist and size to those input by the user.
    //the next pointer is default NULL unless a new one is entered by the user
    Song(string newTitle, string newArtist, int newSize);
    void setTitle(string newTitle);
    void setArtist(string newArtist);
    void setSize(int newSize);
    string getTitle() const;
    string getArtist() const ;
    int getSize() const ;

    bool operator<(Song s2){
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

    bool operator>(Song s2){
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

    bool operator==(Song s2){
        string title2 = s2.title;
        string artist2 = s2.artist;
        int size2 = s2.size;
        return (title.compare(title2) == 0) && (artist.compare(artist2) == 0) && (size2 == size);
    }
};



#endif
