//
// Created by gruno on 3/21/18.
//

#ifndef PROJECT_EVOLUTION_ENTRY_HPP
#define PROJECT_EVOLUTION_ENTRY_HPP
#include <string>
#include <vector>
#include <ctime>

using std::string;
using std::vector;
using std::time_t;

class Entry {
public:
    Entry(const string& fileName);
    void addEntry(const vector<string>&);
    void deleteEntry(const string&);
    string showDifference();
private:
    string file_;
    time_t epoch_;
    time_t now_;
};


#endif //PROJECT_EVOLUTION_ENTRY_HPP
