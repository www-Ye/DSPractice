#ifndef AVL_H
#define AVL_H

#include "utility.h"

enum Balance_factor { left_higher, equal_height, right_higher };

template <class Record>
struct AVL_node:public Binary_node<Record>{
	Balance_factor balance;
	
	AVL_node();
	AVL_node(const Record &x);
	
	void set_balance(Balance_factor b);
	Balance_factor get_balance() const;
};

template <class Record>
class AVL_tree:public Search_tree<Record>{
public:
	Error_code insert(const Record &new_data);
	Error_code remove(const Record &old_data);
private:
};

#endif