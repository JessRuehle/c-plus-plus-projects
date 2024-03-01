/**
 * This function finds the quotient of two given decimal numbers.
 * Precondition: b must not be 0.
 * Post-condition: the quotient a divided by b has been returned.
 */
#include <iostream>
#include <cmath>

using namespace std;

// calculated the distance the projectile travels
double dist_traveled(double velocity, double angle) {
    return ((velocity * velocity) * (sin(2.0 * angle))) / 32;
}

// converts an angle in degrees to radians
double angle(double degrees) {
    return (degrees * 3.14159265) / 180.0; //radian conversion
};

// determines how close the projectile lands to the target in a percent
double percent(double target_dist, double dist_traveled) {
    double diff = abs(target_dist - dist_traveled);
    return (diff / dist_traveled) * 100;
};

int main() {

    int ready;

    // welcome message
    cout<< "Welcome to the projectile throwing game! In this game, your task is to throw a projectile and get it to "
           "land within 0.1% of the target. To do this, you will need to supply the distance of the target, the angle"
           "you are throwing at, and the velocity at which it travels. You will get 5 tries at that distance. Get "
           "withing 0.1% of the target in those 5 tries, and you win! After 5 tries, you lose and can change the"
           " distance again for the next game. Are you ready?\n1 for ready." <<endl;
    cin>>ready;
    cout<< "Great! Let's get started! :)" <<endl;

    // declare variables to store the data
    double velocity;
    double distance;
    double degrees;
    bool GAME_OVER = false;
    bool game_won = false;

    // variables for stats
    int proj_thrown = 0;
    int games_played = 0;
    int games_won = 0;
    int games_lost = 0;


    // while loop to keep user in game
    while (!GAME_OVER) {

        games_played++;
        proj_thrown++;

        // prompt the user for the three pieces of data and assign
        // them to the variable
        cout << "Please enter the velocity" << endl;
        cin >> velocity;
        cout << "Please enter the distance" << endl;
        cin >> distance;
        cout << "Please enter the angle" << endl;
        cin >> degrees;

        // for loop to begin the user's five tries at the target
        for (int i = 1; i < 5; i++) {

            // set the winning status to false
            game_won = false;
            proj_thrown++; // increment projectile counter

            // calculations
            double ang = angle(degrees);
            double d_t = dist_traveled(velocity, ang);

            // check if the user hit close enough to the target
            if (percent(distance, d_t) <= 0.1) {

                cout<< "CONGRATULATIONS! You won!" <<endl;
                games_won++; // increment winning counter
                game_won = true; // set game status to won
                i = 5; // set i to 5 to end for loop

            } else {
                // if they did not, prompt them to input a new velocity and angle
                cout<< "You missed! You landed " <<d_t<< " ft away." <<endl;
                cout<< "Tries left: " << (5 - i) <<endl;
                cout<< "Enter a new velocity." <<endl;
                cin>>velocity;
                cout<< "Enter a new angle." <<endl;
                cin>>degrees;
            }
        }

        // count if they won or lost their game after the final round
        if (!game_won) {
            cout<< "You missed! You landed " <<
            dist_traveled(velocity,angle(degrees))<< " ft away." <<endl;
            cout<< "You are out of tries, you did not win the game." <<endl;
            games_lost++;
        } else {
            cout<< "CONGRATULATIONS! You won!" <<endl;
            games_won++; // increment winning counter
        };

        // see if the player wants to play again
        int again;
        cout<< "Play again?\n1 for yes, 2 for no" <<endl;
        cin>>again;

        if (again == 2) {
            GAME_OVER = true;
        }
    }

    // tell the player their stats
    cout<< "Thank you for playing! Here are your stats: " <<endl;
    cout<< "You played " << games_played << " games!" <<endl;
    cout<< "You threw " << proj_thrown << " projectiles!" <<endl;
    cout<< "You won " << games_won << " times!" <<endl;
    cout<< "You lost " << games_lost << " times!" <<endl;
    cout<< "Thanks for playing!" <<endl;



    return 0;

}

