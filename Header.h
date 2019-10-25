//
//  Header.h
//  CPlusAirport
//
//  Created by 김재민 on 9/12/19.
//  Copyright © 2019 김재민. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
using namespace std;

class Node{
public:
    string Name;
    Node* pToCus;
    Node* pToFlight;
};

class List{
public:
    Node* Head;
    void addFlight(string FlightName);
    void addCustomer(string FlightName, string CusName);
    void checkReservation(string FlightName, string CusName);
    void deleteCustomer(string FlightName, string CusName);
    void printAirportInfo(string FlightName);
    void printAllAirport();
};

#endif /* Header_h */
