//
// Created by gruno on 3/21/18.
//

#ifndef PROJECT_EVOLUTION_SHELL_HPP
#define PROJECT_EVOLUTION_SHELL_HPP

#include <iostream>
#include <string>
#include "Entry.hpp"

using std::string;

class Shell {
public:
    //Overloaded Constructor
    Shell(const string& dataFile = "./.data/epoch.data");
    //Destructor
    ~Shell();

    void prompt();

    bool quit() const { return status_;}

private:
    Entry* entryMaker_;
    bool status_ = false;
    void functionMapper(const string& command);

    //Function calls
    void addEntry();
    void deleteEntry();
    void showFlair();
    void showHelp();
    void callExit();
};


#endif //PROJECT_EVOLUTION_SHELL_HPP
