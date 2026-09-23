#include <iostream>
#include<vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
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


class PlayerAnalyzer{

public:
    vector<Player> players;
    stack<string> recentEvents;
    queue<string> substitutionQueue;
    unordered_map<string, Player> m;

    void addPlayer(Player player) {
        players.push_back(player);
        m.insert({player.getName(), player});
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


    void searchPlayerFast(string plr) {

        auto it = m.find(plr);

        if(it != m.end()) {
            cout<<"Player found" << endl;
            it->second.playerDetails();
        } else {
            cout<< "Player Not Found" << endl;
        }

    }

    void sortByGoals() {

        for(int i = 0; i < players.size(); i++) {

                Player curr = players[i];
                int prev = i - 1;

                while(prev >= 0 && players[prev].getGoals() > curr.getGoals()) {
                    players[prev + 1] = players[prev];
                    prev--;
                }

                players[prev + 1] = curr;
        }
    }

    void addMatchEvent(string event) {

        recentEvents.push(event);
    }

    string getRecentEvent() {

        if(recentEvents.empty()) {
            return "No Recent Event";
        }
        return recentEvents.top();
    }

    void removeRecentEvent() {

        if(recentEvents.empty()) {
            cout<< "No recent Event" << endl;
            return;
        }
        recentEvents.pop();
    }

    void addSubstitution(string plr) {

        substitutionQueue.push(plr);
    }

    void processSubstitution() {

        if(substitutionQueue.empty()) {
            cout<< "No players Substituted yet" << endl;
            return;
        }

        cout << substitutionQueue.front() << " is being processed" << endl;
        
        substitutionQueue.pop();
        cout << "Player has been processed" << endl;
    }


    int totalGoals() {

        int totalsum = 0;

        for(int i = 0; i < players.size(); i++) {
            totalsum += players[i].getGoals();
        }

        cout<< "Total Goals: ";
        return totalsum;
    }

    void topScorer() {

        if(players.empty()) {
            cout<< "No player record found" << endl;
        }

        int max = players[0].getGoals();
        Player topPlayer = players[0];
        
        for(int i = 0; i < players.size(); i++) {
    
            if(players[i].getGoals() > max) {
                max = players[i].getGoals();
                topPlayer = players[i];
            }
        }
        cout<< "Top Scorer: " << endl;
        topPlayer.playerDetails();
        
    }


    void averageGoals() {

        if(players.empty()) {
            cout<< "No such player record"<< endl;
        } else {
            double avegGoals = static_cast<double>(totalGoals())/players.size();
            cout<< "Average Goals: " << avegGoals << endl;
        }
        
    }
};