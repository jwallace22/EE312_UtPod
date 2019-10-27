//
// Created by jwall on 10/17/2019.
//
/*
#include <cstdlib>
#include "Song.h"
#include "UtPod.h"
#include <iostream>

int main(){
    Song s("Africa","Toto",512);
    Song b("Every Time We Touch", "Casanda",25);
    std::cout << s.getTitle() << " by " << s.getArtist() << endl;
    std::cout << b.getTitle() << " by " << b.getArtist() << endl;
    return 0;
}
*/
/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);


    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);


    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);

    t.showSongList();
    cout << endl;
    t.sortSongList();

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;


}
