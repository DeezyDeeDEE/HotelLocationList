//add if definition here and at end
/*  
    Names: Jackson Whitworth,
    Date: 10/24/2024
    File Purpose: Creates linked list nodes template
*/
#ifndef NODE_H
#define NODE_H

// node with data and next ptr (and prev)
template <typename T>
struct Node 
{
    T data; // stores data
    Node* next; // next node pointer
    Node* prev; // prev pointer

    //constructor
    Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
};

#endif