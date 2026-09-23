#include <iostream>
#include<vector>
#include <string>
using namespace std;

class Player{

private:
    string name;
    string team;
    int goals;
    int assists;

public:
    Player(string name, string team, int goals, int assists) {
        this->name = name;
        this->team = team;
        this->goals = goals;
        this->assists = assists;
    }

    void playerDetails() {
        cout<< "Name: " << getName() << endl;
        cout << "Team: " << getTeam()<< endl;
        cout<< "Goals: " << getGoals() << endl;
        cout<< "Assists: "<< getAssists() << endl;
    }

    string getName() {
        return name;
    }

    string getTeam() {
        return team;
    }

    int getGoals() {
        return goals;
    }

    int getAssists() {
        return assists;
    }
};


class PlayerMAnalyzer{

public:
    vector<Player> players;

    void addPlayer(Player player) {
        players.push_back(player);
    }

    void displayPlayers() {

        for(Player& player: players) {
            cout<< "Name: " << player.getName() << endl; 
            cout<< "Team: " << player.getTeam() << endl; 
            cout<< "Goals: " << player.getGoals() << endl; 
            cout<< "Assists: " << player.getAssists() << endl; 
        }
    }

    void searchPlayer(string name) {

        bool isFound = false;

        for(Player& player: players) {

            if(player.getName() == name) {
                isFound = true;
                cout<< "Player Found!..." << endl;
                player.playerDetails();
                break;
            }
        }

        if(!isFound) {
            cout<< "Player not Found!" << endl;
        }

    }


    void sortByGoals() {

        for(int i = 1; i < players.size() ; i++) {

            Player curr = players[i];
            int prev = i - 1;
            
            while(prev >= 0 && players[prev].getGoals() > curr.getGoals()) {
                players[prev + 1] = players[prev];
                prev--;
            }

            players[prev + 1] = curr;

        }
    }


};