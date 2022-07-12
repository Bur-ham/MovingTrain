#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <unistd.h>


typedef std::string string;
typedef std::stringstream stringstream;

void clearScreen() {
    system("clear");
}

string createEmptyString(int movement) {
    string emptyString = "";
    for (int i = 0; i < movement; i++) {
        emptyString += " ";
    }
    return emptyString;
}

string newTrain(int movement, string train) {
    string returnString = "";
    string tmp = "";
    stringstream ss(train);
    while (std::getline(ss, tmp)) {
        string spaces = createEmptyString(movement);
        string trainPart = spaces + tmp;
        returnString += trainPart + "\n";
    }
    return returnString;
}

void runLoop() {
    int movement = 0;
    string train = "____\n" \
                   "|DD|____T_\n" \
                   "|__|_____|<\n" \
                    "@-@-@-oo";

    while (true) {
        clearScreen();
        if (movement > 60) {
            movement = 0;
            string render = newTrain(movement, train);
            std::cout << render << std::endl;
            movement++;
        } else {
            string render = newTrain(movement, train);
            std::cout << render << std::endl;
            movement++;
        }
        usleep(150000);
    }
    
    
}