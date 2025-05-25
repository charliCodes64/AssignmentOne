#include "logic.h"
#include <iostream>
#include <fstream>

using namespace std;

logic::logic() {
	word = " ";
	scramble = " ";
	for (int i = 0; i < 100; i++) {
		//words[i] = "";
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
	
	while (readFile >> word) {
		words.push_back(word);

		if (word.length() <= 5 && word.length() >= 4) {
			smallWords.push_back(word);
		}
		if (word.length() <= 7 && word.length() >= 6) {
			mediumWords.push_back(word);
		}
		if (word.length() <= 100 && word.length() >= 8) {
			largeWords.push_back(word);
		}
	}
	std::cout;
	for (const std::string& w : smallWords) {
		std::cout << w << "\n";
	}
	//return 0;
	std::string welcome = "Break here before medium words";
	std::cout << welcome << std::endl;	std::cout;
	for (const std::string& w : mediumWords) {
		std::cout << w << "\n";
	}
	std::string welcomel = "Break here before large words";
	std::cout << welcomel << std::endl;	std::cout;
	for (const std::string& w : largeWords) {
		std::cout << w << "\n";
	}
	return 0;

}
std::string scrambler(std::string word) {

}

//void::end() {
//
//}