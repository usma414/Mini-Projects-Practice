#include <iostream>
using namespace std;

class Rover{
private:

    string robotName;
    int x_cord;
    int y_cord;
    int battery_life;

    bool consumeEnergy() {
        if (battery_life > 0) {
            return true;
        } else {
            cout << robotName << " is out of battery. Cannot Move." << endl;
            return false;
        }
    }

public:

    Rover (string robotName, int x_cord, int y_cord, int battery_life) {
        this->robotName = robotName;
        this->x_cord = x_cord;
        this->y_cord = y_cord;
        this->battery_life = battery_life;
    }

    void moveUp() {
        if(consumeEnergy()) {
            y_cord += 1;
            battery_life -= 1;
            cout << robotName << " is moving Up." << endl;
        }
    }

    void moveDown() {
        if (consumeEnergy()) {
            y_cord -= 1;
            battery_life -= 1;
            cout << robotName << " is moving Down." << endl;
        } 
    }

    void moveRight() {
        if (consumeEnergy()) {
            x_cord += 1;
            battery_life -= 1;
            cout << robotName << " is moving Right." << endl;
        } 
    }

    void moveLeft() {
        if (consumeEnergy()) {
            x_cord -= 1;
            battery_life -= 1;
            cout << robotName << " is moving Left." << endl;
        } 
    }

    void displayStatus() {
        cout << "Currently robot is at: ( " << x_cord << ", " << y_cord << " )" << endl;
        cout << "Battery life: " << battery_life << endl;
    }
};

int main () {

    Rover r1("Milo", 0, 0, 5);

    while(true) {
        char option;
        cout << "Enter option: (U/D/R/L) or Q for quit" << endl;
        cin >> option;

        switch(option)
        {
        case 'U':
             r1.moveUp();
             break;

        case 'D':
            r1.moveDown();
            break;

        case 'R': 
            r1.moveRight();
            break;

        case 'L':
            r1.moveLeft();
            break;

        case 'Q':
            cout << "Stopping robot.." << endl;
            r1.displayStatus();
            return 0;
        }

        r1.displayStatus();
    }
}
