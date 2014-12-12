#include "studentRosterType.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <sstream>

int studentRosterType::median()//does not work
{
    vector<int> storeScores;
    int mid;
    for(int i=0;i<(info.size());i++)
    {
        storeScores.push_back(info[i].getScore());
    }
    sort(storeScores.begin(),storeScores.end(),greater<int>());
    int check = ((storeScores.size()) % 2);
    if(check == 0)
    {
        //even number of objects
        int temp;
        temp = ((storeScores.size()) / 2);
        int calculator;
        calculator = storeScores[temp-1] + storeScores[temp];
        mid = calculator/2;
    }
    else if(check != 0)
    {
        //odd number of objects
        int index;
        index = (storeScores.size()/2) - 0.5;
        mid = storeScores[index];
    }
    return mid;
}
int studentRosterType::returnVectorSize()
{
    return info.size();
}
int studentRosterType::removeAndGetID(string name)
{
    int tempo = 0;
    for(int i=0;i<(info.size());i++)
    {
        if(info[i].getName() == name)
        {
            tempo = info[i].getId();
            info.erase((info.begin() + i));
        }
    }
    return tempo;
}
studentRosterType::studentRosterType(): Student("",0)
{
    classAverage = 0;
    classMedian = 0;
}
void studentRosterType::printNamesAbove(double average,ofstream &fout)
{
    for(unsigned int j=0;j<(info.size());j++)
    {
        if((info[j].getScore()) > average)
        {
            fout << info[j].getName() << endl;
        }
    }

}
void studentRosterType::printIDsBelow(double avg,ofstream &fout)
{
    for(unsigned int j=0;j<(info.size());j++)
    {
        if((info[j].getScore()) > avg)
        {
            fout << info[j].getId() << endl;
        }
    }
}
void studentRosterType::printInfoFor(int median,ofstream &fout)
{
    for(unsigned int j=0;j<(info.size());j++)
    {
        if((info[j].getScore()) == median)
        {
            fout << info[j].getName() << endl;
            fout << info[j].getScore() << endl;
            fout << info[j].getId() << endl;
        }
    }
}
studentRosterType::studentRosterType(string name,int score): Student(name,score)
{
    classAverage = 0;
    classMedian = 0;
}
void studentRosterType::print() const
{
    for(int i=0;i<(info.size());i++)
    {
        cout << info[i] << endl;
    }
}
double studentRosterType::average()
{
    double temp=0;
    for(int n=0;n<(info.size());n++)
    {
        temp = temp + (info[n].getScore());
    }
    classAverage = temp/(info.size());
    return classAverage;
}
void studentRosterType::load(string filename)
{
    ifstream in;
    string line;
    string t1;
    string t2;
    string t3;
    int score1;
    int id;
    in.open("studentData.txt");
    if(in.fail())
    {
        cout << "Fail-Safe #1" << endl;
        exit(1);
    }
    getline(in,line);
    while(in)
    {
        //cout << line << endl;
        stringstream stream(line);
        getline(stream,t1,' ');
        getline(stream,t2,' ');
        getline(stream,t3,'\n');
        score1 = atoi(t2.c_str());
        id = atoi(t3.c_str());
        Student createNew(t1,score1,id);
        info.push_back(createNew);
        t1 = "";
        t2 = "";
        t3 = "";

        getline(in,line);
    }

    in.close();


}
