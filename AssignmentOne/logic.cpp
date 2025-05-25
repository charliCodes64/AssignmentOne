#include "logic.h"
#include <iostream>
#include <fstream>

using namespace std;

logic::logic() {
	word = " ";
	scramble = " ";
	for (int i = 0; i < 100; i++) {
		words[i] = "";
	}
}

void logic::introduction() {
	std::string welcome = "Welcome to to GUESS THAT WORD!! \nYour mission is to unscramble the characters you see and to form the correct word! \nGood luck ";
	std::cout << welcome << std::endl;
}

bool logic::createLists() {
	
	ifstream readFile("dictionary.txt");
	 
	if (readFile.fail()) {
		cerr << "Cannot locate file!!";
		return 1;
	}
	
	for (int i = 0; i < 100; i++) {
		readFile >> words[i];
	}
	readFile.close();

	/*cout << "contents: ";
	for (int i = 0; i < 100; i++) {
		cout << words[i] << " ";
	}
	cout << endl;*/
	
	

}
void::end() {

}