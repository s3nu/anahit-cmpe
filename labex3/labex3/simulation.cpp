//
//  simulation.cpp
//  exam3
//
//  Created by senu on 12/1/14.
//  Copyright (c) 2014 Anahit Sarao. All rights reserved.
//

#include "simulation.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <queue>
#include <iomanip>
#include <time.h>

using namespace std;

    //Car Class
train::train(){
     howmanyppl=0;
     howmanytrains=0;
     collisions="";
     weather="";
     distance=0;
}

void train::getinfo(){
    cout<<"Welcome to Train Simulation\n"<<
        "Details:\n"<<
        "Every 5 Miles Has a Stop\n"<<
        "People Leave and Board each Station by a number of 200\n"<<
        "Delay and Time is all in Minutes\n"
        "Distance is in Miles\n"<<
        "Wait Time at a Station is 5 Minutes\n"<<
        "Accident or Maintenance Causes 30 Minute Delay\n"<<
        "Train Travels ~25MPH"<<endl;
    
    cout<<"The simulation will now gather needed information:"<<endl;
    cout<<"\nHow many People?"<<endl;
    cin>>howmanyppl;
    cout<<"How many Miles?"<<endl;
    cin>>distance;
    cout<<"Random Accidents and or Maintenance? (yes/no)"<<endl;
    cin>>collisions;
    cout<<"Weather Condition?\n"<<
        "Snow -5 delay\n"<<
        "Rain -3 delay\n"<<
        "Cloudy -1 delay\n"<<
        "Sunny No delay"<<endl;
    cin>>weather;
    cout<<"\nThe simulation will now run..."<<endl;
}

    //Stop Class
stop::stop(){
    traveltime=0;
    stops=0;
    stationtostion=0;
    stationdelay=0;
}
void stop::initialize(){
    train temp;
    int traincounter=0;
    traincounter=(howmanyppl/200);
    for (int i=0; i<traincounter; i++) {
        trains.push(i);
        trainlsit.push(temp);
    }
    int stationcounter=0;
    stationcounter=(distance/5);
    for (int i=0; i<stationcounter; i++) {
        stations.push(i);
    }
}
double stop::getdelay(){
    double weight=0;
    if (weather=="snow") {
        weight=5.0;
    }
    if (weather=="rain") {
        weight=3.0;
    }
    if (weather=="cloudy") {
        weight=3.0;
    }
    if (weather=="cloudy") {
        weight=1.0;
    }
    return weight;
}
void stop::runsimul(){//running simulation with queue
    stationtostion=24.0;
    stationdelay=5.0;
    accidentdelay=30.0;
    stops=0.0;
    delayfornext=new int[stations.size()];
    if (collisions=="no"&&weather=="sunny"){//no delay
        if(stations.size()==1){
            stops++;
            traveltime=stationtostion+stationdelay+(distance/25);
            cout<<"Station #"<<stops<<endl;
            cout<<"Travel Time: "<<traveltime<<" Minutes"<<endl;
            cout<<"Number of Trains: "<<trains.size()<<endl;
            cout<<"Travel Time Betweeen Station: "<<stationtostion<<" Minutes"<<endl;
            cout<<"Number of Stops: "<<stations.size()<<endl;
            stations.pop();
        }
        if(stations.size()>1){
            for (int i=0; i<stations.size(); i++) {
                stops++;
                delayfornext[i]=(stationdelay*i)+(stationtostion*i);
                stations.pop();
         }
            for (int i=0; i<stops; i++) {
                traveltime=((distance/stops)/25)+delayfornext[i];
                cout<<"Station #"<<i+1<<endl;
                cout<<"Travel Time: "<<traveltime<<" Minutes"<<endl;
                cout<<"Number of Trains: "<<trains.size()<<endl;
                cout<<"Travel Time Betweeen Station: "<<stationtostion<<" Minutes"<<endl;
                cout<<"Number of Stops: "<<i+1<<endl;
            }
        }
    }
    if (collisions=="yes"&&weather=="sunny"){//delay hazard
        if(stations.size()==1){
            stops++;
            traveltime=stationtostion+stationdelay+(distance/25)+accidentdelay;
            cout<<"Station #"<<stops<<endl;
            cout<<"Travel Time: "<<traveltime<<" Minutes"<<endl;
            cout<<"Number of Trains: "<<trains.size()<<endl;
            cout<<"Travel Time Betweeen Station: "<<stationtostion<<" Minutes"<<endl;
            cout<<"Number of Stops: "<<stations.size()<<endl;
            stations.pop();
        }
        if(stations.size()>1){
            for (int i=0; i<stations.size(); i++) {
                stops++;
                delayfornext[i]=(stationdelay*i)+(stationtostion*i);
                stations.pop();
            }
            int temp=0;
            temp=stops;
            srand(time(NULL));
            double delayer=0;
            delayer=rand()%temp+2;
            cout<<"Accident and or Maintenance at station# "<<delayer<<"\n"<<endl;
            if(delayer<=stops||delayer>=stops){
            for (int i=0; i<stops; i++) {
                if(delayer==i){
                traveltime=traveltime+((distance/stops)/25)+delayfornext[i]+accidentdelay;
                cout<<"Station #"<<i+1<<endl;
                cout<<"Travel Time: "<<traveltime<<" Minutes"<<endl;
                cout<<"Number of Trains: "<<trains.size()<<endl;
                cout<<"Travel Time Betweeen Station: "<<stationtostion<<" Minutes"<<endl;
                cout<<"Number of Stops: "<<i+1<<endl;
                    }
                else{
                    traveltime=traveltime+((distance/stops)/25)+delayfornext[i];
                    cout<<"Station #"<<i+1<<endl;
                    cout<<"Travel Time: "<<traveltime<<" Minutes"<<endl;
                    cout<<"Number of Trains: "<<trains.size()<<endl;
                    cout<<"Travel Time Betweeen Station: "<<stationtostion<<" Minutes"<<endl;
                    cout<<"Number of Stops: "<<i+1<<endl;

                    }
                }
            }
            if (delayer>stops){
                cout<<"\nAccident and or Maintenace was Overflow did not effect simulation"<<endl;
                }
            }
    }
    if (collisions=="yes"&&weather!="sunny") {//mutiple delay hazard
        stop hazard;
        double delayweight=hazard.getdelay();
        if(stations.size()==1){
            stops++;
            traveltime=stationtostion+stationdelay+(distance/25)+accidentdelay+delayweight;
            cout<<"Station #"<<stops<<endl;
            cout<<"Travel Time: "<<traveltime<<" Minutes"<<endl;
            cout<<"Number of Trains: "<<trains.size()<<endl;
            cout<<"Travel Time Betweeen Station: "<<stationtostion<<" Minutes"<<endl;
            cout<<"Number of Stops: "<<stations.size()<<endl;
            stations.pop();
        }
        if(stations.size()>1){
            for (int i=0; i<stations.size(); i++) {
                stops++;
                delayfornext[i]=(stationdelay*i)+(stationtostion*i);
                stations.pop();
            }
            int temp=0;
            temp=stops;
            srand(time(NULL));
            double delayer=0;
            delayer=rand()%temp+2;
            cout<<"Accident and or Maintenance at station# "<<delayer<<"\n"<<endl;
            if(delayer<=stops||delayer>=stops){
                for (int i=0; i<stops; i++) {
                    if(delayer==i){
                        traveltime=traveltime+((distance/stops)/25)+delayfornext[i]+accidentdelay+delayweight;
                        cout<<"Station #"<<i+1<<endl;
                        cout<<"Travel Time: "<<traveltime<<" Minutes"<<endl;
                        cout<<"Number of Trains: "<<trains.size()<<endl;
                        cout<<"Travel Time Betweeen Station: "<<stationtostion<<" Minutes"<<endl;
                        cout<<"Number of Stops: "<<i+1<<endl;
                    }
                    else{
                        traveltime=traveltime+((distance/stops)/25)+delayfornext[i]+delayweight;
                        cout<<"Station #"<<i+1<<endl;
                        cout<<"Travel Time: "<<traveltime<<" Minutes"<<endl;
                        cout<<"Number of Trains: "<<trains.size()<<endl;
                        cout<<"Travel Time Betweeen Station: "<<stationtostion<<" Minutes"<<endl;
                        cout<<"Number of Stops: "<<i+1<<endl;
                        
                    }
                }
            }
            if (delayer>stops){
                cout<<"\nAccident and or Maintenance was Overflow did not effect simulation"<<endl;
            }
        }
    }
    if (collisions=="no"&&weather!="sunny") {//mutiple delay hazard
        stop hazard;
        double delayweight=hazard.getdelay();
        if(stations.size()==1){
            stops++;
            traveltime=stationtostion+stationdelay+(distance/25)+accidentdelay+delayweight;
            cout<<"Station #"<<stops<<endl;
            cout<<"Travel Time: "<<traveltime<<" Minutes"<<endl;
            cout<<"Number of Trains: "<<trains.size()<<endl;
            cout<<"Travel Time Betweeen Station: "<<stationtostion<<" Minutes"<<endl;
            cout<<"Number of Stops: "<<stations.size()<<endl;
            stations.pop();
        }
        if(stations.size()>1){
            for (int i=0; i<stations.size(); i++) {
                stops++;
                delayfornext[i]=(stationdelay*i)+(stationtostion*i);
                stations.pop();
            }
                for (int i=0; i<stops; i++) {
                        traveltime=traveltime+((distance/stops)/25)+delayfornext[i]+delayweight;
                        cout<<"Station #"<<i+1<<endl;
                        cout<<"Travel Time: "<<traveltime<<" Minutes"<<endl;
                        cout<<"Number of Trains: "<<trains.size()<<endl;
                        cout<<"Travel Time Betweeen Station: "<<stationtostion<<" Minutes"<<endl;
                        cout<<"Number of Stops: "<<i+1<<endl;
                        
                    }
                }
            }
    }