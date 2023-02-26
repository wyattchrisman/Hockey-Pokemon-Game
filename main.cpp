#include "Player.cpp"
#include "Normal.cpp"
#include "Sniper.cpp"
#include "Fighter.cpp"
#include "Playmaker.cpp"
#include "Veteran.cpp"
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

void getDataFromFile(string filename, vector<unique_ptr<Player>>& players);
void printHeader();
void getPlayerAmounts(vector<unique_ptr<Player>>& players);
void getPlayerStats(unique_ptr<Player> &player, double &fightStat, double &shotStat, double &passStat);
void getPlayer(vector<unique_ptr<Player>> &players, unique_ptr<Player> &newPlayer, unique_ptr<Player> &discardPlayer);
void getTeams(vector<unique_ptr<Player>> &players, vector<unique_ptr<Player>> &userTeam, vector<unique_ptr<Player>> &compTeam);
void printRules();
int getInt(int min, int max);
void setPlayer(vector<unique_ptr<Player>> &players, unique_ptr<Player> &player);
void setComputerPlayer(vector<unique_ptr<Player>> &players, unique_ptr<Player> &player);
void addToTeam(vector<unique_ptr<Player>> &team, unique_ptr<Player> &playerAdded);
void fight(unique_ptr<Player> &player1, unique_ptr<Player> &player2);
void shot(unique_ptr<Player> &player1, unique_ptr<Player> &player2);
void pass(unique_ptr<Player> &player1, unique_ptr<Player> &player2);



int main(){

    // Read in all players to vector
    string filename = "../Players_List.csv";
    vector<unique_ptr<Player>> players;

    getDataFromFile(filename,players);

    unique_ptr<Player> newPlayer, discardPlayer;

    srand(time(NULL));

    vector<unique_ptr<Player>> userTeam;
    vector<unique_ptr<Player>> compTeam;

    getTeams(players, userTeam, compTeam);





    return 0;
};

// Add all players to vector from file
void getDataFromFile(string filename, vector<unique_ptr<Player>>& players) {
    //open file
    ifstream inFile;
    inFile.open(filename);

    //get header
    string header;
    if(inFile){
        //Read in the header for each category
        getline(inFile, header);
        //cout << header << endl;
    } else {
        cout << "File could not be opened." << endl;
    }

    //set variables to recognizable values
    int rank = -1, born = -1, gamesPlayed = -1, goals = -1,
        assists = -1,points = -1, penalty = -1;

    double fightStat = -1, shotStat = -1, passStat = -1;

    string name = "XXX XXX", position = "XXX XXX";
    char comma;

    //loop to validate that file continues while printing player data
    while(inFile && inFile.peek() != EOF) {
        //assign player rank and print
        inFile >> rank;
        inFile >> comma;

        getline(inFile, name, ',');
        //cout << name << endl;

        inFile >> born;
        //cout << born << endl;
        inFile >> comma;

        getline(inFile, position, ',');

        inFile >> gamesPlayed;
        inFile >> comma;

        inFile >> goals;
        inFile >> comma;

        inFile >> assists;
        inFile >> comma;

        inFile >> points;
        //cout << points << endl;
        inFile >> comma;

        inFile >> penalty;

        fightStat = penalty/49.5;
        shotStat = goals/11.1;
        passStat = assists/22.40;

        bool setType = false;
        if(goals >= 356) {
            players.push_back(make_unique<Sniper>(rank, name, born, position, gamesPlayed, goals,
                                                  assists, points, penalty, fightStat, shotStat, passStat));
            setType = true;
        }
        if(assists >= 409 && !setType) {
            players.push_back(make_unique<Playmaker>(rank, name, born, position, gamesPlayed, goals,
                                                     assists, points, penalty, fightStat, shotStat, passStat));
            setType = true;
        }
        if(penalty >= 798 && !setType){
            players.push_back(make_unique<Fighter>(rank, name, born, position, gamesPlayed, goals,
                                                   assists, points, penalty, fightStat, shotStat, passStat));
            setType = true;
        }
        if(gamesPlayed >= 700 && !setType){
            players.push_back(make_unique<Veteran>(rank, name, born, position, gamesPlayed, goals,
                                                   assists, points, penalty, fightStat, shotStat, passStat));
            setType = true;
        }
        if(!setType){
            players.push_back(make_unique<Normal>(rank, name, born, position, gamesPlayed, goals,
                                                  assists, points, penalty, fightStat, shotStat, passStat));

        }


    }
    inFile.close();
}

// For user comprehension of player stats
void printHeader() {

    cout << left << setw(25) << "NAME" << setw(6) << "RANK" << setw(11) <<
         "YEAR BORN" << setw(10) << "POSITION" << setw(14) << "GAMES PLAYED" <<
         setw(8) << "GOALS" << setw(9) << "ASSISTS" << setw(8) << "POINTS"
         << setw(15) << "PENALTY MINUTES" << endl;
    cout << setfill(' ');
}

// For sake of balancing out the number of each category
void getPlayerAmounts(vector<unique_ptr<Player>>& players) {
    int vet = 0, snip = 0, fight = 0, play = 0, normal = 0;
    for(int i = 0; i < players.size(); ++i){
        if(players[i]->playerSaying() == "Normal"){
            ++normal;
        }
        if(players[i]->playerSaying() == "Veteran"){
            ++vet;
        }
        if(players[i]->playerSaying() == "Sniper"){
            ++snip;
        }
        if(players[i]->playerSaying() == "Fighter"){
            ++fight;
        }
        if(players[i]->playerSaying() == "Playmaker"){
            ++play;
        }
    }

    cout << "Normal: " << normal << endl;
    cout << "Veteran: " << vet << endl;
    cout << "Sniper: " << snip << endl;
    cout << "Fighter: " << fight << endl;
    cout << "Playmaker: " << play << endl;
}

void getPlayerStats(unique_ptr<Player> &player, double &fightStat, double &shotStat, double &passStat){
    cout << "Player name: " << player->getName() << endl;
    cout << "Player type: " << player->getPlayerType() << endl;

    fightStat = player->getFightStat();
    cout << "Fighter Stat: " << fightStat << endl;

    shotStat = player->getShotStat();
    cout << "Shot Stat: " << shotStat << endl;

    passStat = player->getPassStat();
    cout << "Pass Stat: " << passStat << endl;
    cout << endl;
}


void getPlayer(vector<unique_ptr<Player>>& players, unique_ptr<Player> &newPlayer, unique_ptr<Player> &discardPlayer){


    int randNum = rand()%players.size();

    if (players[randNum]->getPlayerType() == "Normal") {
        discardPlayer = make_unique<Normal>(players[randNum]->getRank(),
                                                               players[randNum]->getName(),
                                                               players[randNum]->getBorn(),
                                                               players[randNum]->getPosition(),
                                                               players[randNum]->getGamesPlayed(),
                                                               players[randNum]->getGoals(),
                                                               players[randNum]->getAssists(),
                                                               players[randNum]->getPoints(),
                                                               players[randNum]->getPenalty(),
                                                               players[randNum]->getFightStat(),
                                                               players[randNum]->getShotStat(),
                                                               players[randNum]->getPassStat());

        players.erase(players.begin() + randNum);

        newPlayer.swap(discardPlayer);
        discardPlayer.reset();

    }
    if (players[randNum]->getPlayerType() == "Sniper") {
        discardPlayer = make_unique<Sniper>(players[randNum]->getRank(),
                                                               players[randNum]->getName(),
                                                               players[randNum]->getBorn(),
                                                               players[randNum]->getPosition(),
                                                               players[randNum]->getGamesPlayed(),
                                                               players[randNum]->getGoals(),
                                                               players[randNum]->getAssists(),
                                                               players[randNum]->getPoints(),
                                                               players[randNum]->getPenalty(),
                                                               players[randNum]->getFightStat(),
                                                               players[randNum]->getShotStat(),
                                                               players[randNum]->getPassStat());

        players.erase(players.begin() + randNum);

        newPlayer.swap(discardPlayer);
        discardPlayer.reset();
    }
    if (players[randNum]->getPlayerType() == "Fighter") {
        discardPlayer = make_unique<Fighter>(players[randNum]->getRank(),
                                                                players[randNum]->getName(),
                                                                players[randNum]->getBorn(),
                                                                players[randNum]->getPosition(),
                                                                players[randNum]->getGamesPlayed(),
                                                                players[randNum]->getGoals(),
                                                                players[randNum]->getAssists(),
                                                                players[randNum]->getPoints(),
                                                                players[randNum]->getPenalty(),
                                                                players[randNum]->getFightStat(),
                                                                players[randNum]->getShotStat(),
                                                                players[randNum]->getPassStat());

        players.erase(players.begin() + randNum);

        newPlayer.swap(discardPlayer);
        discardPlayer.reset();
    }
    if (players[randNum]->getPlayerType() == "Playmaker") {
        discardPlayer = make_unique<Playmaker>(players[randNum]->getRank(),
                                                                  players[randNum]->getName(),
                                                                  players[randNum]->getBorn(),
                                                                  players[randNum]->getPosition(),
                                                                  players[randNum]->getGamesPlayed(),
                                                                  players[randNum]->getGoals(),
                                                                  players[randNum]->getAssists(),
                                                                  players[randNum]->getPoints(),
                                                                  players[randNum]->getPenalty(),
                                                                  players[randNum]->getFightStat(),
                                                                  players[randNum]->getShotStat(),
                                                                  players[randNum]->getPassStat());

        players.erase(players.begin() + randNum);

        newPlayer.swap(discardPlayer);
        discardPlayer.reset();
    }
    if (players[randNum]->getPlayerType() == "Veteran") {
        discardPlayer = make_unique<Veteran>(players[randNum]->getRank(),
                                                                players[randNum]->getName(),
                                                                players[randNum]->getBorn(),
                                                                players[randNum]->getPosition(),
                                                                players[randNum]->getGamesPlayed(),
                                                                players[randNum]->getGoals(),
                                                                players[randNum]->getAssists(),
                                                                players[randNum]->getPoints(),
                                                                players[randNum]->getPenalty(),
                                                                players[randNum]->getFightStat(),
                                                                players[randNum]->getShotStat(),
                                                                players[randNum]->getPassStat());

        players.erase(players.begin() + randNum);

        newPlayer.swap(discardPlayer);
        discardPlayer.reset();
    }

}

void getTeams(vector<unique_ptr<Player>> &players, vector<unique_ptr<Player>> &userTeam, vector<unique_ptr<Player>> &compTeam){
    cout << "Welcome to Wyatt's Hockey Game!" << endl;
    printRules();

    cout << "Here are your three player choices: " << endl;

    unique_ptr<Player> userPlayer1;
    setPlayer(players, userPlayer1);

    unique_ptr<Player> userPlayer2;
    setPlayer(players, userPlayer2);

    unique_ptr<Player> userPlayer3;
    setPlayer(players, userPlayer3);

    unique_ptr<Player> userPlayer4;
    setPlayer(players, userPlayer4);

    unique_ptr<Player> userPlayer5;
    setPlayer(players, userPlayer5);

    addToTeam(userTeam, userPlayer1);
    addToTeam(userTeam, userPlayer2);
    addToTeam(userTeam, userPlayer3);
    addToTeam(userTeam, userPlayer4);
    addToTeam(userTeam, userPlayer5);



    cout << "\nYour Team: " << endl;
    printHeader();
    for(int i = 0; i < userTeam.size(); ++i){
        cout << userTeam[i] << endl;
    }

    unique_ptr<Player> compPlayer1;
    setComputerPlayer(players, compPlayer1);

    unique_ptr<Player> compPlayer2;
    setComputerPlayer(players, compPlayer2);

    unique_ptr<Player> compPlayer3;
    setComputerPlayer(players, compPlayer3);

    unique_ptr<Player> compPlayer4;
    setComputerPlayer(players, compPlayer4);

    unique_ptr<Player> compPlayer5;
    setComputerPlayer(players, compPlayer5);

    addToTeam(compTeam, compPlayer1);
    addToTeam(compTeam, compPlayer2);
    addToTeam(compTeam, compPlayer3);
    addToTeam(compTeam, compPlayer4);
    addToTeam(compTeam, compPlayer5);

    cout << "\nOpponents Team: " << endl;
    printHeader();
    for(int i = 0; i < compTeam.size(); ++i){
        cout << compTeam[i] << endl;
    }

}

void printRules(){
    cout << "You will create your team of 5 players. " << endl;
    cout << "For each pick, you will be given a choice of 3 players." << endl;
    cout << "BUT, if you don't like any of those players you will have" << endl;
    cout << "a choice at an unknown player, which will automatically be assigned to you team." << endl;
    cout << endl;
    cout << "This team will then go head to head against another 5 man team." << endl;
    cout << "There will consist of 3 different game modes: " << endl;
    cout << "A fight, an accuracy shooting competition, and a passing accuracy competition." << endl;
    cout << "To begin the game, one of these modes will be chosen at random." << endl;
    cout << "Your first player will be put head to head against their first player." << endl;
    cout << "If you win the game, you can choose a different game mode and your opponents second player will come in." << endl;
    cout << "But, if your opponent wins, the game mode will be chosen at random and you can assign a new player." << endl;
    cout << endl;
}

int getInt(int min, int max) {
    cout << "\nEnter your choice of player 1, 2, 3, or 4 for an unknown player: ";

    string stringIn;
    int input;
    char character;
    stringstream ss;

    getline(cin, stringIn);

    bool valid = false;
    while(!valid){
        if(stringIn.size() != 1){
            cout << "Input must be one digit. Please enter a number between " << min << "-" << max << ": ";
            getline(cin, stringIn);
        }

        if(stringIn.size() == 1){
            character = stringIn[0];
            if (!isdigit(character)) {
                cout << "Input can only be integers. Please enter a number between " << min << "-" << max << ": ";
                getline(cin, stringIn);
                character = stringIn[0];
            }
            if(isdigit(character)) {
                ss << stringIn;
                ss >> input;
                if(input > max || input < min) {
                    cout << "Input can only be between " << min << "-" << max << ". Please enter a valid number: ";
                    getline(cin, stringIn);
                    ss.clear();
                    ss << stringIn;
                    ss >> input;
                }
                if(input <= max && input >= min) {
                    valid = true;
                }
            }
        }
    }
    return input;
}

void setPlayer(vector<unique_ptr<Player>>& players, unique_ptr<Player> &player){
    unique_ptr<Player> discardPlayer;
    unique_ptr<Player> temp1;
    unique_ptr<Player> temp2;
    unique_ptr<Player> temp3;


    getPlayer(players, temp1, discardPlayer);
    getPlayer(players, temp2, discardPlayer);
    getPlayer(players, temp3, discardPlayer);

    printHeader();
    cout << temp1 << endl;
    cout << temp2 << endl;
    cout << temp3 << endl;

    int input = getInt(1,4);

    if(input == 1){
        player.swap(temp1);
    }
    if(input == 2){
        player.swap(temp2);
    }
    if(input == 3){
        player.swap(temp3);
    }
    if(input == 4){
        unique_ptr<Player> temp4;
        getPlayer(players, temp4, discardPlayer);
        player.swap(temp4);
        cout << "Your random player: " << endl;
        cout << player << endl;
        cout << endl;
    }
}

void setComputerPlayer(vector<unique_ptr<Player>>& players, unique_ptr<Player> &player){
    unique_ptr<Player> discardPlayer;
    unique_ptr<Player> temp1;
    unique_ptr<Player> temp2;
    unique_ptr<Player> temp3;

    getPlayer(players, temp1, discardPlayer);
    getPlayer(players, temp2, discardPlayer);
    getPlayer(players, temp3, discardPlayer);

    if(temp1->getRank() < temp2->getRank()){
        player.swap(temp1);
    } else {
        player.swap(temp2);
    }

    if(temp3->getRank() < player->getRank()) {
        player.swap(temp3);
    }
}

void addToTeam(vector<unique_ptr<Player>> &team, unique_ptr<Player> &playerAdded){
    if (playerAdded->getPlayerType() == "Normal") {
        team.push_back(make_unique<Normal>(playerAdded->getRank(),
                                            playerAdded->getName(),
                                            playerAdded->getBorn(),
                                            playerAdded->getPosition(),
                                            playerAdded->getGamesPlayed(),
                                            playerAdded->getGoals(),
                                            playerAdded->getAssists(),
                                            playerAdded->getPoints(),
                                            playerAdded->getPenalty(),
                                            playerAdded->getFightStat(),
                                            playerAdded->getShotStat(),
                                            playerAdded->getPassStat()));
    }
    if (playerAdded->getPlayerType() == "Sniper") {
        team.push_back(make_unique<Sniper>(playerAdded->getRank(),
                                           playerAdded->getName(),
                                           playerAdded->getBorn(),
                                           playerAdded->getPosition(),
                                           playerAdded->getGamesPlayed(),
                                           playerAdded->getGoals(),
                                           playerAdded->getAssists(),
                                           playerAdded->getPoints(),
                                           playerAdded->getPenalty(),
                                           playerAdded->getFightStat(),
                                           playerAdded->getShotStat(),
                                           playerAdded->getPassStat()));
    }
    if (playerAdded->getPlayerType() == "Fighter") {
        team.push_back(make_unique<Fighter>(playerAdded->getRank(),
                                           playerAdded->getName(),
                                           playerAdded->getBorn(),
                                           playerAdded->getPosition(),
                                           playerAdded->getGamesPlayed(),
                                           playerAdded->getGoals(),
                                           playerAdded->getAssists(),
                                           playerAdded->getPoints(),
                                           playerAdded->getPenalty(),
                                           playerAdded->getFightStat(),
                                           playerAdded->getShotStat(),
                                           playerAdded->getPassStat()));
    }
    if (playerAdded->getPlayerType() == "Playmaker") {
        team.push_back(make_unique<Playmaker>(playerAdded->getRank(),
                                           playerAdded->getName(),
                                           playerAdded->getBorn(),
                                           playerAdded->getPosition(),
                                           playerAdded->getGamesPlayed(),
                                           playerAdded->getGoals(),
                                           playerAdded->getAssists(),
                                           playerAdded->getPoints(),
                                           playerAdded->getPenalty(),
                                           playerAdded->getFightStat(),
                                           playerAdded->getShotStat(),
                                           playerAdded->getPassStat()));
    }
    if (playerAdded->getPlayerType() == "Veteran") {
        team.push_back(make_unique<Veteran>(playerAdded->getRank(),
                                           playerAdded->getName(),
                                           playerAdded->getBorn(),
                                           playerAdded->getPosition(),
                                           playerAdded->getGamesPlayed(),
                                           playerAdded->getGoals(),
                                           playerAdded->getAssists(),
                                           playerAdded->getPoints(),
                                           playerAdded->getPenalty(),
                                           playerAdded->getFightStat(),
                                           playerAdded->getShotStat(),
                                           playerAdded->getPassStat()));
    }
}

