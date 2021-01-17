#include "utility.h"
#include "life.h"

void instructions()
/*Pre: None.
 *Instructions for using the Life program have been printed. */
{
    cout << "Welcome to Conway's game of Life." << endl;
    cout << "This game uses a grid of size"
         << maxrow << "by" << maxcol << "in which" << endl;
    cout << "each cell can either be occupied by an organism or not." << endl;
    cout << "The occupied cells change from generation to generation"
         << endl;
    cout << "according to the number of neighboring cells which are alive."
         << endl;
}

int main()      // Program to play Conway's game of life.
/*Pre:  The user supplies an initial configuration of living cells.
 *post: The program prints a sequence of pictures showing the changes
        int the configuration of living cells according to the rules
        for the game of Life.
 *Uses: The class Life and its methods initialze(), print(), and update().
        The functions instructions(), user_says_yes(). 
 */
{
    Life configuration;
    instructions();
    configuration.initialize();
    configuration.print();
    cout << "Continue viewing new generations?" << endl;
    while(user_says_yes()){
        configuration.update();
        configuration.print();
        cout << "Continue viewing new generations?" << endl;
    }
}
