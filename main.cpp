#include "Shell.hpp"
int main() {
    //Call the shell
    Shell sh;
    while(!sh.quit()){
        sh.prompt();
    }
}
