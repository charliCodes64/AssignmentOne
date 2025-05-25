#include "logic.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

logic::logic() {
	word = " ";
	//scramble = " ";
	std::srand(static_cast<unsigned int>(std::time(nullptr))); //starts random number generator each time program starts
	//https://www.softwaretestinghelp.com/random-number-generator-cpp/
}

void logic::introduction() {
	std::string welcome = "Welcome to to GUESS THAT WORD!! \nYour mission is to unscramble the characters you see and to form the correct word! \nGood luck ";
	std::cout << welcome << std::endl;
}
//opens .txt file and stores stings based on their length
bool logic::createLists() {
	
	ifstream readFile("dictionary.txt");
	 
	if (readFile.fail()) {
		cerr << "Cannot locate file!!";
		return 1;
	}
	///*std::cout << "Words loaded: " << words.size();
	//std::cout << "Small worrds: " << smallWords.size();
	//std::cout << "Medium words: " << mediumWords.size();
	//std::cout << "Large words: " << largeWords.size();*/
	
	//storing words based on their length
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
//	/*std::cout; tested to see if words where read in depending on length
//	for (const std::string& w : smallWords) {
//		std::cout << w << "\n";
//	}
//	std::string welcome = "Break here before medium words";
//	std::cout << welcome << std::endl;	std::cout;
//	for (const std::string& w : mediumWords) {
//		std::cout << w << "\n";
//	}
//	std::string welcomel = "Break here before large words";
//	std::cout << welcomel << std::endl;	std::cout;
//	for (const std::string& w : largeWords) {
//		std::cout << w << "\n";
//	}*/
	return 0;
 }
//randomly organizes strigns
std::string logic::scrambler(std::string word) {
	int length = word.length();
	int getRand;
	char randChar;

	for (int i = length - 1; i >= 1; --i) {
		getRand = rand() % (i + 1);
		randChar = word[i];
		word[i] = word[getRand];
		word[getRand] = randChar;
	}
	return word;
}

bool logic::playGame() {
	int correctWords = 0;
	std::string typedWord;
	std::string correctscramWord;

	//selecting word and sending it to be randomized based on stage in game
	while (correctWords < 5) {
		if (correctWords < 2 && !smallWords.empty()) {
			correctscramWord = smallWords[rand() % smallWords.size()];
			//std::cout << "\nYour doing great!" << std::endl;
		}
		else if (correctWords < 4 && !mediumWords.empty()) {
			correctscramWord = mediumWords[rand() % mediumWords.size()];
			std::cout << "\nKeep it up your almost at the final level!" << std::endl;
		}
		else if (correctWords >= 4 && !largeWords.empty()) {
			correctscramWord = largeWords[rand() % largeWords.size()];
			std::cout << "\nYou got this one more word to go!!!" << std::endl;
		}
		std::string scramble = scrambler(correctscramWord);

		//checks user input to see if they made the correct choice if so adds 1 to correctWords int
		while (true) {
			std::cout << "Word to unscramble: " << scramble;
			std::cout << "\nMake a guess: ";
			std::cin >> typedWord;

			if (typedWord == correctscramWord) {
				std::cout << "\nGuess is correct moving on" << std::endl;
				correctWords++;
				break;
			}
			else {
				std::cout << "\nGuess is incorrect try again!!!";
			}
		}
	}
	std::cout << "You have guessed all Five Words correctly!!!";
	return true;
}

//void::end() {
//	std::string welcome = "Please come back and play again soon!";
//	std::cout << welcome << std::endl;
//}