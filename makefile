final: UtPodDriver.o UtPod.o Song.o
	g++ -o UtPodTest UtPodDriver.o UtPod.o Song.o
driver: UtPodDriver.cpp UtPod.h Song.h
	g++ -c -std=c++11 UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c -std=c++11 UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -c -std=c++11 Song.cpp
