#include "utility.h"
#include "List.h"

void write_entry(char &c){
    cout << c;
}

int main(){
    char x;
    List<char> c_list;
    cout << "List is empty, it has " << c_list.size() << " items.\n";
    cout << "Enter characters and the program adds them to the list.\n";
    cout << "Use Enter key (newline) to terminate the input.\n";
    cout << "When ListSize() is 3, the element will be inserted at the ";
    cout << "front of the list.\n The others will appear at the back.\n";
    while(!c_list.full() && (x = cin.get()) != '\n')
        if(c_list.size() == 3) c_list.insert(0, x);
        else c_list.insert(c_list.size(), x);
    cout << "The list has " << c_list.size() << " items.\n";
    cout << "The function c_list.full(), got " << c_list.full();
    if(c_list.full()) cout << " because the list is full.\n";
    else cout << " because the list is NOT full.\n";
    cout << "c_list.empty(), expecting 0, got " << c_list.empty() << ".\n";
    cout << "c_list.traverse(write_entry) output:  ";
    c_list.traverse(write_entry);
    cout << "\n";
    c_list.clear();
    cout << "Cleared the list, printing its contents:\n";
    c_list.traverse(write_entry);
    cout << "\n";
    cout << "Enter characters and the program adds them to the list.\n";
    cout << "Use Enter key (newline) to terminate the input.\n";
    cout << "When ListSize() is < 3, the element will be inserted at the ";
    cout << "front of the list.\n The others will appear at the back.\n";
    while (!c_list.full() && (x = cin.get()) != '\n')
        if (c_list.size() < 3) c_list.insert(0, x);
        else c_list.insert(c_list.size(), x);
    c_list.traverse(write_entry);
    cout << "\n";
    
    return 0;
}