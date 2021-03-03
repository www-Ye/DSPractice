#include <iostream>
#include "node.h"

using namespace std;

int main(){
    Node first_node('a');
    Node *p0 = &first_node;
    Node *p1 = new Node('b');
    p0->next = p1;
    Node *p2 = new Node('c');
    p1->next = p2;
    Node *p = p0;
    while(p != NULL){
        cout << p->entry << endl;
        p = p->next;
    }
}