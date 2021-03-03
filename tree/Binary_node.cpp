#include "Binary_node.h"

template <class Entry>
Binary_node<Entry>::Binary_node(){
    left = right = NULL;
}

template <class Entry>
Binary_node<Entry>::Binary_node(const Entry &x){
    data = x;
    left = right = NULL;
}

template <class Entry>
void Binary_node<Entry>::set_balance(Balance_factor b){

}

template <class Entry>
Balance_factor Binary_node<Entry>::get_balance() const{
    
}