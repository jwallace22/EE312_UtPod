//
// Created by jwall on 10/17/2019.
//
#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

public:
    //Default constructor
    //set the memory size to MAX_MEMORY
    UtPod();

    //Constructor with size parameter
    //The user of the class will pass in a size.
    //If the size is greater than MAX_MEMORY or less than or equal to 0,
    //set the size to MAX_MEMORY.
    UtPod(int size);

    /* FUNCTION - int addSong
     * attempts to add a new song to the UtPod
         o returns SUCCESS  if successful
         o returns NO_MEMORY if not enough memory to add the song

     precondition: s is a valid Song

     input parms - a valid song is passed by reference but unchangeable 

     output parms - a copy of the song is added to the top of the linked list of songs
    */

    int addSong(Song const &s);


    /* FUNCTION - int removeSong
     * attempts to remove a song from the UtPod
     * removes the first instance of a song that is in the the UtPod multiple times
         o returns SUCCESS if successful
         o returns NOT_FOUND if nothing is removed


       input parms - a valid song is passed by reference but does not have to be in the list

       output parms - if the song is in the list, it is removed, Success is returned if found and Not_Found is returned if the input song is not in the list
    */

    int removeSong(Song const &s);


    /* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms - an initialized list that has an number of songs or no songs at all

       output parms - the list is shuffled pseudo-randomly by swapping the values in the nodes
    */

    void shuffle();


    /* FUNCTION - void showSongList
     * prints the current list of songs in order from first to last to standard output
     * format - Title, Artist, size in MB (one song per line)

       input parms - an initialized song list with any number of songs or no songs at all

       output parms - the current list of songs is printed to the screen
    */

    void showSongList();


    /* FUNCTION - void sortSongList
     *  sorts the songs in ascending order
        o will do nothing if there are less than two songs in the current list

       input parms - an initialized list of songs with any number of elements 

       output parms - the songs are sorted by artist, then title, then size inside of the linked list
    */

    void sortSongList();


    /* FUNCTION - void clearMemory
     * clears all the songs from memory

       input parms - an initialized song list with a NULL pointer at the end

       output parms - all the allocated memory in the Linked list is freed and the head ptr is assigned NULL
    */
    void clearMemory();


    /* FUNCTION - int getTotalMemory
     *  returns the total amount of memory in the UtPod
        o will do nothing if there are less than two songs in the current list

       input parms - the memSize has been initialized by the constructor

       output parms - simply returns how much memory the UtPod has total, regardless of the ammount used
    */

    int getTotalMemory() {
        return memSize;
    }



    /* FUNCTION - int getRemainingMemory
     *  returns the amount of memory available for adding new songs

       input parms - the linked list has been initialized and all songs have a valid size

       output parms - returns the amount of memory left in the UtPod to be used by more songs
    */

    int getRemainingMemory();


    ~UtPod();

};



#endif