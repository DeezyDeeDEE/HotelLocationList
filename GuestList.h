/*  
    Names: Jackson Whitworth,Spencer Kirksey
    Date: 10/24/2024
    File Purpose: creates guestlist class and func prototypes
*/
#ifndef GUESTLIST_H
#define GUESTLIST_H

#include "Node.h"
#include <iostream>

//guest list class, to hold a list of guests (surprise)
template <typename T>
class GuestList 
{
private:
    Node<T>* head; //start
    Node<T>* tail; //end
    int size;

public:
    GuestList(); //constructor
    ~GuestList(); // destructor

    void addGuest(const T& guest); //adding guest
    T getFrontGuest() const; //get guest at start
    void removeFrontGuest(); // delete guest at start
    void sortBookings(); // sort guest list
    bool isEmpty() const;
    int getSize() const;

    // Friend ostream ??
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const GuestList<U>& list);

    //quicksort
    void quickSort(Node<T>* start, Node<T>* end);
    Node<T>* partition(Node<T>* start, Node<T>* end);
};

#include "GuestList.cpp"
#endif