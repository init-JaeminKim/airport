//
//  airport.cpp
//  CPlusAirport
//
//  Created by 김재민 on 9/12/19.
//  Copyright © 2019 김재민. All rights reserved.
//

#include "Header.h"

void List::addFlight(string FlightName){
    
    Node* pCheckNode = Head;
    
    while(pCheckNode != NULL){
        if(pCheckNode -> Name == FlightName){
            return;
        }
        pCheckNode = pCheckNode -> pToFlight;
    }
    
    Node* pNode = new Node();
    pNode -> Name = FlightName;
    pNode -> pToFlight = Head;
    Head = pNode;
    
}

void List::printAllAirport(){
    Node* pNode = Head;
    
    while(pNode != NULL){
        cout << pNode -> Name << endl;
        pNode = pNode -> pToFlight;
    }
}

void List::addCustomer(string FlightName, string CusName){
    Node* pNode = Head;
    
    while(pNode -> Name != FlightName){
        pNode = pNode -> pToFlight;
    }
    Node* pNewNode = new Node();
    pNewNode -> Name = CusName;
    pNewNode -> pToCus = NULL;
    
    pNewNode -> pToCus = pNode -> pToCus;
    pNode -> pToCus = pNewNode;
}

void List::printAirportInfo(string FlightName){
    Node* pNode = Head;
    
    while(pNode != NULL){
        if(pNode -> Name == FlightName){
            Node* pNode2 = pNode -> pToCus;
            while(pNode2 != NULL){
                cout << pNode2 -> Name << endl;
                pNode2 = pNode2 -> pToCus;
            }
            return;
        }
        else{
            pNode = pNode -> pToCus;
        }
        
    }
    cout << "No matching airport" << endl;
}

void List::checkReservation(string FlightName, string CusName){
    Node* pNode = Head;
    
    while(pNode != NULL){
        if(pNode -> Name == FlightName){
            Node* pNode2 = pNode -> pToCus;
            while(pNode2 != NULL){
                if(pNode2 -> Name == CusName){
                    cout << "Reservation Checked" << endl;
                    return;
                }
                else{
                    pNode2 = pNode2 -> pToCus;
                }
            }
            cout << "No matching name" << endl;
            return;
        }
        else{
            pNode = pNode -> pToFlight;
        }
    }
    cout << "No matching flight" << endl;
}

void List:: deleteCustomer(string FlightName, string CusName){
    Node* pNode = Head;
    
    while(pNode != NULL){
        if(pNode -> Name == FlightName){
            Node* pNode2 = pNode -> pToCus;
            Node* pPreNode = pNode;
            while(pNode2 != NULL){
                if(pNode2 -> Name == CusName){
                    Node* pDelNode = pNode2;
                    pPreNode -> pToCus = pDelNode -> pToCus;
                    delete pDelNode;
                    cout << "Deleted" << endl;
                    return;
                }
                else{
                    pNode2 = pNode2 -> pToCus;
                    pPreNode = pPreNode -> pToCus;
                }
            }
            cout << "No matching Name" << endl;
            return;
        }
        else{
            pNode = pNode -> pToFlight;
        }
    }
    cout << "No matching flight name" << endl;
}
