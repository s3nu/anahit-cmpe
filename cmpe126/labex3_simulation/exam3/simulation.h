//
//  simulation.h
//  exam3
//
//  Created by senu on 12/1/14.
//  Copyright (c) 2014 Anahit Sarao. All rights reserved.
//

#ifndef __exam3__simulation__
#define __exam3__simulation__

#include <stdio.h>
#include <string>
#include <queue>
using namespace std;

    //Class type for train and simulation information
class train {
public:
    train();
    void getinfo();
protected:
    int howmanyppl;
    int howmanytrains;
    string collisions;
    string weather;
    int distance;
};

    //Class for Stop Simulation
class stop:public train {
public:
    stop();
    void initialize();
    double getdelay();
    void runsimul();
    
private:
    queue<train> trainlsit;
    queue<int> stations;
    double traveltime;
    double stops;
    double accidentdelay;
    double stationtostion;
    double stationdelay;
    int *delayfornext;
    queue<int> trains;
};


#endif /* defined(__exam3__simulation__) */
