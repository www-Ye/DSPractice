#include "utility.h"

bool user_says_yes()
{
    int c;
    bool initial_response = true;
    do{         // loop until an appropriate input is received.
        if(initial_response)
            cout << "(y,n)?" << flush;
        else
            cout << "Respond with either y or n:" << flush;
        do{
            c = cin.get();
        }while(c == '\n' || c == ' ' || c == '\t');
        initial_response = false;
    }while(c != 'Y' && c != 'y' && c != 'N' && c != 'n');
    return (c == 'Y' || c == 'y');
}
