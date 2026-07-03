#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;


class Rover{
private:

    string robotName;
    int x_cord;
    int y_cord;
    int battery_life;

    bool consumeEnergy() {

        int distanceToHome = distanceToTravel(0,0);

        if (battery_life <= distanceToHome) {
            cout << "Low Battery FallBack Activated..Returning Home Safely.." << endl;
            x_cord = 0;
            y_cord = 0;
            battery_life = 100;
            return false;
        }

        if (battery_life > 0) {
            battery_life -= 1;
            return true;
        } else {
            cout << robotName << " is out of battery. Cannot Move." << endl;
            return false;
        }
    }

    bool isValidMove (int nextX, int nextY) {
        if ((nextX <= 5 && nextX >= -5) && (nextY <= 5 && nextY >= -5)) {
            return true;
        } else {
            cout << "Obstackle/Boundary reach..Cannot Move" << endl;
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
        if (isValidMove(x_cord, y_cord + 1)) {
            if(consumeEnergy()) {
                y_cord += 1;
                cout << robotName << " is moving Up." << endl;
            }
        }
    }

    void moveDown() { 
        if (isValidMove (x_cord, y_cord - 1)) {
            if (consumeEnergy()) {
                y_cord -= 1;
                cout << robotName << " is moving Down." << endl;
            } 
        }
    }

    void moveRight() { 
        if (isValidMove(x_cord + 1, y_cord)) {
            if (consumeEnergy()) {
                x_cord += 1;
                cout << robotName << " is moving Right." << endl;
            } 
        }
    }

    void moveLeft() {
        if (isValidMove(x_cord - 1, y_cord)) {
            if (consumeEnergy()) {
                x_cord -= 1;
                cout << robotName << " is moving Left." << endl;
            } 
        }
    }

    void displayStatus() {
        cout << "Currently robot is at: ( " << x_cord << ", " << y_cord << " )" << endl;
        cout << "Battery life: " << battery_life << endl;
    }


    int distanceToTravel(int targetX, int targetY) {
        int dist = abs(x_cord - targetX) + abs(y_cord - targetY);
        return dist;
    }


    void LoadAndRunData() {

        ifstream file("robotPackages.csv");

        if (!file.is_open()) {
            cout << "Error. Cannot open this file" << endl;
            return;
        }

        string line;
        getline(file, line);

        while(getline(file, line)) {
            stringstream ss(line);

            string id, textX, textY, textWeight;

            getline(ss, id, ',');
            getline(ss, textX, ',');
            getline(ss, textY, ',');
            getline(ss, textWeight, ',');


        int targetX = stoi(textX);
        int targetY = stoi(textY);

        cout << "\n=========================================" << endl;
        cout << "🚀 STARTING DELIVERY: Package " << id << " to (" << targetX << ", " << targetY << ")" << endl;
        cout << "=========================================" << endl;

        while (x_cord != targetX || y_cord != targetY)
        {
        
            while(x_cord != targetX) {
                if (x_cord < targetX) {
                    moveRight();
                } else {
                    moveLeft();
                }
            }

            while (y_cord != targetY) {
                if (y_cord < targetY){
                    moveUp();
                } else {
                    moveDown();
                }
                
            }
        
        }
        cout << "✅ Package " << id << " delivered successfully!" << endl;
        displayStatus();
        }

        file.close();
    }
};

int main () {

    Rover r1("Milo", 0, 0, 20);

    r1.LoadAndRunData();

    // cout << "Distance to be travelled: " << r1.distanceToTravel(3,4) << endl;

    // while(true) {
    //     char option;
    //     cout << "Enter option: (U/D/R/L) or Q for quit" << endl;
    //     cin >> option;

    //     switch(option)
    //     {
    //     case 'U':
    //          r1.moveUp();
    //          break;

    //     case 'D':
    //         r1.moveDown();
    //         break;

    //     case 'R': 
    //         r1.moveRight();
    //         break;

    //     case 'L':
    //         r1.moveLeft();
    //         break;

    //     case 'Q':
    //         cout << "Stopping robot.." << endl;
    //         r1.displayStatus();
    //         return 0;
    //     }

        r1.displayStatus();
}

