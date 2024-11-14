/*  
    Names: Jackson Whitworth,Spencer Kirksey
    Date: 10/24/2024
    File Purpose: Creates and uses linked list class for multiple purposes
*/
#include "GuestList.h"
#include "Guest.h"
#include <iostream>
using namespace std;

int main() 
{
    GuestList<Guest> bookings; // guestlist obj
    int choice; // var for menu
    string name, checkIn, checkOut; //vars for guest info
    int roomNumber;

    do 
    {
        cout << "\nHotel Guest Management System:\n"
             << "1. Add a new guest\n"
             << "2. Check out front guest\n"
             << "3. Display all bookings\n"
             << "4. Sort bookings by check-in date\n"
             << "5. Quit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            cout << "Enter guest name: ";
            cin.ignore();
            getline(cin, name); // gets guest name
            cout << "Enter room number: ";
            cin >> roomNumber;
            cout << "Enter check-in date (YYYY-MM-DD): ";
            cin >> checkIn;
            cout << "Enter check-out date (YYYY-MM-DD): ";
            cin >> checkOut;
            bookings.addGuest(Guest(name, roomNumber, checkIn, checkOut)); //add guest to list
            break;

        case 2:
            try 
            {
                bookings.removeFrontGuest();
                cout << "Guest has checked out.\n"; //rm front guest
            } catch (const exception& e) 
            {
                cout << e.what() << endl;
            }
            break;

        case 3:
            cout << "Current bookings:\n" << bookings << endl; // show list
            break;

        case 4:
            bookings.sortBookings(); // sort bookings
            cout << "Bookings sorted by check-in date.\n";
            break;
        }
    }
}