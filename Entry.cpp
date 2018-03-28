//
// Created by gruno on 3/21/18.
//

#include <fstream>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include "Entry.hpp"

using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::ios_base;
using std::time;
using std::endl;
using std::to_string;
using std::exception;


Entry::Entry(const string &fileName) {
    file_ = fileName;
    ifstream file;
    file.open(file_);
    string beginning;
    getline(file, beginning);
    try{
        epoch_ = stoi(beginning);
    }
    catch (exception &e){
		    file.close();
        epoch_ = time(nullptr);
        //Should be non-blocking since file wasn't being opened for writing
        ofstream modify;
        modify.open(file_);
        modify << epoch_ << endl;
        modify.close();
    }
    file.close();
    now_ = time(nullptr);
}

void Entry::addEntry(const vector<string>& inputVector){
    ofstream file;
    string newFile = ".data/" + showDifference() + ".log";

    file.open(newFile, ios_base::app);

    for(auto &item: inputVector){
        file << item << endl;
    }
    file.close();
}

void Entry::deleteEntry(const string &name) {
    //Delete the entry called name
    remove(name.c_str());
}

string Entry::showDifference() {
    unsigned int day = long(epoch_ - now_) / (24 * 3600);
    return "Day" + to_string(day);
}
