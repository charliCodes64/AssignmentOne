#pragma once
#include <string>

class logic
{
public:
    logic();
    //constructor

    void introduction();
    //Provides a basic introduction to the user

    bool createLists();
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
	std::string words[100];
	std::string smallWords[50];   //array of words of length 4-5
	std::string mediumWords[50];   //array of words of length 6-7
	std::string largeWords[50];    //8+ letters

};


