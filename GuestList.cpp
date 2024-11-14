/*  
    Names: Jackson Whitworth,Spencer Kirksey
    Date: 10/24/2024
    File Purpose: implements guest linked list funcs
*/
#include "GuestList.h"
#include <iostream>

//init guestlist
template <typename T>
GuestList<T>::GuestList() : head(nullptr), tail(nullptr), size(0) {}

//deconstructor
template <typename T>
GuestList<T>::~GuestList() 
{
    while (!isEmpty()) {
        removeFrontGuest(); //loop delete guest
    }
}

//adding guest to end
template <typename T>
void GuestList<T>::addGuest(const T& guest) {
    Node<T>* newNode = new Node<T>(guest);
    if (isEmpty()) {
        head = tail = newNode; //both to new node
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

//first guest in list
template <typename T>
T GuestList<T>::getFrontGuest() const 
{
    if (!isEmpty()) {
        return head->data;
    }
    throw std::runtime_error("Guest list is empty.");
}

// remove first guest
template <typename T>
void GuestList<T>::removeFrontGuest() 
{
    if (isEmpty()) return;

    Node<T>* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;

    delete temp;
    size--;
}

// sort func for guest/ quicksort here
template <typename T>
void GuestList<T>::sortBookings() {
    if (size > 1) 
    { //sort if more than 1??
        quickSort(head, tail);
    }
}

template <typename T>
bool GuestList<T>::isEmpty() const 
{
    return head == nullptr; //empty if no head
}

template <typename T>
int GuestList<T>::getSize() const 
{
    return size; //return size?
}

// print list of guest
template <typename T>
std::ostream& operator<<(std::ostream& os, const GuestList<T>& list) 
{
    Node<T>* current = list.head;
    while (current) 
    {
        os << current->data << " -> ";
        current = current->next;
    }
    os << "NULL";
    return os;
}

//quick sort method
template <typename T>
Node<T>* GuestList<T>::partition(Node<T>* start, Node<T>* end) 
{
    T pivot = end->data;
    Node<T>* pIndex = start->prev;
    
    for (Node<T>* i = start; i != end; i = i->next) 
    {
        if (i->data < pivot) 
        {
            pIndex = (pIndex == nullptr) ? start : pIndex->next;
            std::swap(i->data, pIndex->data);
        }
    }
    pIndex = (pIndex == nullptr) ? start : pIndex->next;
    std::swap(pIndex->data, end->data);
    return pIndex;
}

template <typename T>
void GuestList<T>::quickSort(Node<T>* start, Node<T>* end) 
{
    if (end != nullptr && start != end && start != end->next) 
    {
        Node<T>* pIndex = partition(start, end);
        quickSort(start, pIndex->prev);
        quickSort(pIndex->next, end);
    }
}






