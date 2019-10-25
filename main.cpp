//
//  main.cpp
//  CPlusAirport
//
//  Created by Jaemin Kim on 10/19/18.
//  Copyright © 2018 Jaemin Kim. All rights reserved.
//

#include "Header.h"

int main(int argc, const char * argv[]) {
    int ch;
    string FlightName;
    string CusName;

    List l;
    
    while(true){
        cout << "CHOICES:\n";
        cout << "1. Reservation\n";
        cout << "2. Check Reservation\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. Show Airport Info" << endl;
        cout << "5. Exit Program" << endl;
        cout << "Enter your choice: ";
        cin >> ch; cout << "\n\n";
        
        switch(ch){
            case 1: cout << "Reservation\n";
                std::cout << "Enter PortName" << std::endl;
                std::cin >> FlightName;
                l.addFlight(FlightName);
                std::cout << "Enter Your Name" << std::endl;
                std::cin >> CusName;
                l.addCustomer(FlightName, CusName);
                break;
            case 2: cout << "Check Reservation\n";
                cout << "Enter PortName" << endl;
                cin >> FlightName;
                cout << "Enter Name" << endl;
                cin >> CusName;
                l.checkReservation(FlightName, CusName);
                break;
            case 3: cout << "Cancel Reservation\n";
                cout << "Enter PortName" << endl;
                cin >> FlightName;
                cout << "Enter Name" << endl;
                cin >> CusName;
                l.deleteCustomer(FlightName, CusName);
                break;
            case 4: cout << "Show Airports Information" << endl;
                cout << "Enter Flight Name" << endl;
                cin >> FlightName;
                l.printAirportInfo(FlightName);
                break;
            case 5: cout << "Terminating......\n";
                return 0;
            default: cout << "Not Valid\n\n";break;
        }
    }
    return 0;
}
