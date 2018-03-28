//
// Created by gruno on 3/21/18.
//

#include <iostream>
#include <string>
#include "Shell.hpp"
#include "Entry.hpp"

using std::cout;
using std::endl;
using std::string;
using std::cin;

Shell::Shell(const string &dataFile) {
    entryMaker_ = new Entry(dataFile);
}

Shell::~Shell(){
    delete entryMaker_;
}

void Shell::prompt() {
    cout << "> ";
    string userInput;
    getline(cin, userInput);

    functionMapper(userInput);
    return;
}

void Shell::functionMapper(const string &command) {
    if (command == ""){
        return;
    }
    else if(command == "EXIT"){
        callExit();
    }
    else if(command == "ADDE"){
        addEntry();
    }
    else if(command == "REMOVE") {
        deleteEntry();
    }
    else if(command == "SHOW"){
        showFlair();
    }
    else{
        showHelp();
    }
}

//Call addEntry
void Shell::addEntry() {
    //Ask the user for the input
    cout << "Enter your journal entry" << endl;
    cout << "> ";
    vector<string> inputs;

	while (true){
		string line;
		getline(cin, line);
		if(line == "DONE") break;
		inputs.push_back(line);
	}
    entryMaker_->addEntry(inputs);
}

//Call deleteEntry
void Shell::deleteEntry() {
    cout << "Enter the entry you would like to delete" << endl;
    cout << "> ";
    string line;
    getline(cin, line);
    entryMaker_->deleteEntry(line);
}

void Shell::showFlair() {
    cout << entryMaker_->showDifference() << endl;
}

void Shell::showHelp(){
    cout << "ADDE: Adds a new Entry to an automated file" << endl;
    cout << "REMOVE: Removes a specified entry" << endl;
    cout << "SHOW: Shows the time since start" << endl;
    cout << "EXIT: Exits the program" << endl;
}

void Shell::callExit(){
    status_ = true;
    cout << "Thank you for using Evolution" << endl;
}
