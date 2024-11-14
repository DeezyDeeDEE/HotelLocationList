#ifndef GUEST_H
#define GUEST_H

#include <iostream>
#include <string>

class Guest 
{
private:
    std::string name;
    int roomNumber;
    std::string checkInDate;
    std::string checkOutDate; 

public:
    //constructor? default
    Guest() : name(""), roomNumber(0), checkInDate(""), checkOutDate("") {}
    Guest(std::string n, int room, std::string checkIn, std::string checkOut) //inits guest
        : name(n), roomNumber(room), checkInDate(checkIn), checkOutDate(checkOut) {}

    std::string getName() const { return name; } //name getter
    
    int getRoomNumber() const { return roomNumber; } //room num getter
    
    std::string getCheckInDate() const { return checkInDate; } // check in date 
    
    std::string getCheckOutDate() const { return checkOutDate; } // check out date

    void setName(const std::string& n) { name = n; } //name setter
    
    void setRoomNumber(int room) { roomNumber = room; } //room setter
    
    void setCheckInDate(const std::string& checkIn) { checkInDate = checkIn; } //check-in setter
    
    void setCheckOutDate(const std::string& checkOut) { checkOutDate = checkOut; }// out date set

    // printing out full info of the guest
    friend std::ostream& operator<<(std::ostream& os, const Guest& guest) 
    {
        os << "Guest Name: " << guest.name << ", Room: " << guest.roomNumber
           << ", Check-In: " << guest.checkInDate << ", Check-Out: " << guest.checkOutDate;
        return os;
    }

    // sorting guests
    bool operator<(const Guest& other) const { return checkInDate < other.checkInDate; }
    bool operator>(const Guest& other) const { return checkInDate > other.checkInDate; }
    bool operator==(const Guest& other) const { return roomNumber == other.roomNumber; }
};

#endif