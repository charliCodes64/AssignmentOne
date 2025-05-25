#pragma once
#include <string>
#include <vector>

class logic
{
public:
    logic();
    //constructor

    void introduction(); //done
    //Provides a basic introduction to the user

    bool createLists(); //done
    //Opens a file and reads in the list of words that can be scrambled
    //Returns: true if words inserted and false if not
    
    bool playGame();
    //Carries out the actual word scrambling
    //Returns: true if user wins and false if not
    
    std::string scrambler(std::string word);
    //Takes in a word and scrambles it
    //Returns a scrambled version of the parameter
    
    void end();
    //Displays the endgame information

private:
	std::string word;
	std::string scramble;
	std::vector<std::string> words;
	std::vector<std::string> smallWords;   //array of words of length 4-5
	std::vector<std::string> mediumWords;   //array of words of length 6-7
	std::vector<std::string> largeWords;    //8+ letters

};


