/**
 * Wyatt Chrisman
 * CS124
 * Section B
 */

#ifndef PROJECT1_PLAYER_H
#define PROJECT1_PLAYER_H

//add all inclusions
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
using std::cout, std::endl, std::ifstream, std::string, std::vector;
using namespace std;

//create class
class Player {

    //Create all variables to be filled
protected:
    int rank; //players rank out of 1000 for points
    string name; //players name
    int born; //year player was born
    string position; //players position (forward or defense)
    int gamesPlayed; //number of games played in career
    int goals; //number of goals scored in career
    int assists; //number of assists in career
    int points; //number of points in career
    int penalty; //number of penatly minutes in career
    double fightStat;
    double shotStat;
    double passStat;
    double statMultiplier = 1.2;
    double veteranStatMultiplier = 1.075;
    int const MAX_SCORE = 100;


public:
    /**
     * Requires: nothing
     * Modifies: rank, name, born, position, gamesPlayed, goals, assists, points, penalty
     * Effects: sets all player qualities to impossible values
     */
    Player();

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: does nothing
     */
    virtual ~Player() = default;

    /**
     * Requires: all player qualities
     * Modifies: all player qualities
     * Effects: sets all player qualities to input values
     */
    explicit Player(int rank, string name, int born, string position, int gamesPlayed, int goals, int assists,
                    int points, int penalty, double fightStat, double shotStat, double passStat);

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's rank
     */
    virtual int getRank() const;


    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's name
     */
    virtual string getName() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's birth year
     */
    virtual int getBorn() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's position
     */
    virtual string getPosition() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of games played
     */
    virtual int getGamesPlayed() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of goals scored
     */
    virtual int getGoals() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of assists
     */
    virtual int getAssists() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of points
     */
    virtual int getPoints() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of penalty minutes
     */
    virtual int getPenalty() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's fight stat
     */
    virtual double getFightStat() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of shot stat
     */
    virtual double getShotStat() const;

    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns player's amount of pass stat
     */
    virtual double getPassStat() const;

    /**
     * Requires: rank
     * Modifies: rank
     * Effects: sets player's rank
     */
    void setRank(int rank);

    /**
     * Requires: name
     * Modifies: name
     * Effects: sets player's name
     */
    void setName(string name);

    /**
     * Requires: born
     * Modifies: born
     * Effects: sets player's year born
     */
    void setBorn(int born);

    /**
     * Requires: position
     * Modifies: position
     * Effects: sets player's position
     */
    void setPosition(string position);

    /**
     * Requires: gamesPlayed
     * Modifies: gamesPlayed
     * Effects: sets player's games played
     */
    void setGamesPlayed(int gamesPlayed);

    /**
     * Requires: goals
     * Modifies: goals
     * Effects: sets player's goals
     */
    void setGoals(int goals);

    /**
     * Requires: gamesPlayed
     * Modifies: gamesPlayed
     * Effects: sets player's assists
     */
    void setAssists(int assists);

    /**
     * Requires: points
     * Modifies: points
     * Effects: sets player's points
     */
    void setPoints(int points);

    /**
     * Requires: penalty
     * Modifies: penalty
     * Effects: sets player's penalty minutes
     */
    void setPenalty(int penalty);

    /**
     * Requires: fightStat
     * Modifies: fightStat
     * Effects: sets player's fightStat
     */
    void setFightStat(double fightStat);

    /**
     * Requires: shotStat
     * Modifies: shotStat
     * Effects: sets player's shotStat
     */
    void setShotStat(double shotStat);

    /**
     * Requires: passStat
     * Modifies: passStat
     * Effects: sets player's passStat
     */
    void setPassStat(double passStat);

    /**
     *
     * Overload all operators
     *
     */
    friend ostream& operator << (ostream& outs, const Player& pla);

    friend bool operator < (const Player& lhs, const Player& rhs);

    friend bool operator > (const Player& lhs, const Player& rhs);

    friend bool operator <= (const Player& lhs, const Player& rhs);

    friend bool operator >= (const Player& lhs, const Player& rhs);

    friend bool operator == (const Player& lhs, const Player& rhs);

    friend bool operator != (const Player& lhs, const Player& rhs);

    virtual std::string playerSaying() = 0;

    virtual std::string getPlayerType() = 0;


};



#endif