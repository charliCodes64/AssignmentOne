
#include <iostream>
#include "logic.h"
#include <allegro5/allegro.h>

using namespace std;
bool finished = false;
bool timeOut = false;

void* input(ALLEGRO_THREAD* ptr, void* arg);
void* timer(ALLEGRO_THREAD* ptr, void* arg);


int main(int argc, char* argv[])
{
    if (!al_init()) {
        cerr << "Cannot start allegro!" << endl;
        return -1;
    }

    //creating threads 
    ALLEGRO_THREAD* create1 = al_create_thread(input, NULL);
    ALLEGRO_THREAD* create2 = al_create_thread(timer, NULL);

    al_start_thread(create1);
    al_start_thread(create2);

    while (!finished && !timeOut) {
        al_rest(0.1); 
    }

    if (finished) {
        std::cout << "\nHighest Intelligence I see!!!";
        std::cout << "\nCongradulations on wining the game!!!";
    }
    else {
        std::cout << "\nPlease try again you ran out of time :(";
    }

    al_destroy_thread(create1);
    al_destroy_thread(create2);

    return 0;
}

//thread that holds game content that run simutaneosly to timer function
void* input(ALLEGRO_THREAD* ptr, void* arg)
{
    logic startGame;
    startGame.introduction();

    if (startGame.createLists()) {
        std::cout << "Can't load dictionary file!" << std::endl;
    }

    finished = startGame.playGame(); //changes status of game when player finishes to true
    return NULL;
}

//A pointer to the function that starts the timer and checks the change in "finished"
void* timer(ALLEGRO_THREAD* ptr, void* arg)
{
    time_t startTime, currentTime;
    startTime = time(NULL);
    currentTime = time(NULL);
    while (currentTime - startTime < 60 && !finished)
    {
        currentTime = time(NULL);
    }
    timeOut = true;
    return NULL;
}
//int main()
//{
//	logic startGame;
//
//	startGame.introduction();
//	startGame.createLists();
//	
//	if (startGame.createLists()) {
//		std::cout << "Can't load dictionary file!" << std::endl;
//		return -1;
//	}
//	
//	if (startGame.playGame()) {
//		std::cout << "Completed";
//	}
//	else {
//		std::cout << "issues occured";
//	}
//	return 0;
//
//}
