#include "utility.h"
#include "life.h"

int main()
/*pre:  The user supplies an initial configuration of living cells.
  post: The program prints a sequence of pictures showing the changes in the
		configuration of living cells according to the rules for the game of Life.
  Uses: The class Life and its methods initialize(), print(), and update().
		The functions instructions(), user_says_yes(). */
{
	Life configuration;
	instructions();
	configuration.initialize();
	configuration.print();
	cout << "Continue viewing new generations?" << endl;
	while (user_says_yes()){
		configuration.update();
		configuration.print();
		cout << "Continue viewing new generations?" << endl;
	}
}