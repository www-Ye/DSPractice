using namespace std;
#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <cctype>
#include <ctime>
bool user_says_yes();

enum Error_code {success, fail, range_error, underflow, overflow, fatal,
				 not_present, duplicate_error, entry_inserted, entry_found,
				 internal_error);