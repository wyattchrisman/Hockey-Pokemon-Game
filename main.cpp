//
// Created by Wyatt Chrisman on 2/3/23.
//

#include "Movie.h"
#include <vector>
#include <ctime>

using namespace std;

int generate_number();
bool get_initial_input();
string ask_again();

int main()
{


    // Read in all movies to vector
    string filename = "../movies.csv";
    vector<Movie> movies;
    getDataFromFile(filename,movies);



    cout << "Welcome to Random Movie Generator!" << endl;
    cout << endl;

    int num = generate_number();
    bool in = get_initial_input();

    cout << movies[num] << endl;


}

int generate_number()
{
    // Get random number
    time_t present_time;
    present_time=time(NULL);
    return (present_time)%100;
}

bool get_initial_input()
{
    string stringIn;
    cout << "Press enter to generate a movie.";
    getline(cin, stringIn);

    while(stringIn.length() != 0){
        cout << "Please press enter to continue." << endl;
        getline(cin, stringIn);
    }
    return true;
}


