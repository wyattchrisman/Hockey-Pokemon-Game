//
// Created by Wyatt Chrisman on 2/3/23.
//

#include "Movie.h"
#include <vector>
#include <ctime>

using namespace std;

int get_input(string prompt, string invalid, int low, int high);
Movie get_movie(vector<Movie> &movies, int index);
int generate_number();

int main()
{
    // Read in all movies to vector
    string filename = "../movies.csv";
    vector<Movie> movies;
    getDataFromFile(filename,movies);

    cout << "Welcome to Random Movie Generator!" << endl;
    cout << endl;

    int num = generate_number();

    int input;
    input = get_input("Press 1 to generate a movie, or 0 to end program: ", "Please press 1 to continue or 0 to quit: ", 0,1);

    bool continueProgram = true;
    while(continueProgram) {

        if (input == 1) {
            cout << get_movie(movies, num) << endl;

            input = get_input("\nPress 1 if you would like to generate another movie, or 0 to end the program: ",
                              "Error: 0 or 1 not entered.\nPlease enter 0 (end) or 1 (continue): ", 0, 1);
        }
        if (input == 0) {
            cout << "\nThank you for using this program!";
            continueProgram = false;
        }
    }
    return 0;
}

int generate_number()
{
    // Get random number
    time_t present_time;
    present_time=time(NULL);
    return (present_time)%100;
}

int get_input(string prompt, string invalid, int low, int high){
    cout << prompt;
    int choice;
    string junk;
    bool length = true;
    while(!(cin >> choice) || (choice > high || choice < low)){
        cout << invalid;
        cin.clear();
        getline(cin,junk);
    }
    return choice;
}

Movie get_movie(vector<Movie> &movies, int index){
    Movie selected;
    selected = movies[index];

    movies.erase(movies.begin() + index);

    return selected;
}


