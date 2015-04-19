#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <limits>
#include "Graph.h"
using namespace std;

int main(int argc, char* argv[])
{
    Graph g;
    ifstream infile;
    string filename = argv[1];
    infile.open(filename.c_str());
    string line;
    string input;
    vector<string> cnames;
    if(infile.is_open())
    {
        string temp;
        getline(infile,line);
        istringstream iss(line);
        while(getline(iss,temp,','))
        {
            cnames.push_back(temp);
        }
        for(int k=1; k<cnames.size();k++)
        {
            g.addVertex(cnames[k]);
        }
        while(getline(infile,line))
        {
            vector<string> tempc;
            string temps;
            istringstream ss(line);
            while(getline(ss,temps,','))
            {
                tempc.push_back(temps);
            }
            for(int i=1;i<tempc.size();i++)
            {
                if(stoi(tempc[i])!=-1 && stoi(tempc[i])!=0)
                {
                    g.addEdge(tempc[0],cnames[i],stoi(tempc[i]));
                }
            }
        }
        infile.close();
    }
    while(input!="6")
    {
        cout << "======Main Menu=====" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path" << endl;
        cout << "4. Find shortest distance" << endl;
        cout << "5. Extra credit" << endl;
        cout << "6. Quit" << endl;
        cin>>input;
        if(input=="1")
        {
            g.printVertices();
        }
        if(input=="2")
        {
            g.findDistricts();
        }
        if(input=="3")
        {
            string city1;
            string city2;
            cout<<"Enter a starting city:"<<endl;
            cin.ignore(100, '\n');
            getline(cin, city1);
            cout<<"Enter an ending city:"<<endl;
            //cin.ignore(100, '\n');
            getline(cin, city2);
            if(g.checkA()==1)
            {
                if(g.checkV(city1, city2)==1)
                {
                     g.shortPath(city1, city2);
                }
            }
            else
            {
                cout<<"Please identify the districts before checking distances"<<endl;
            }

        }
        if(input=="4")
        {
            string city1;
            string city2;
            cout<<"Enter a starting city:"<<endl;
            cin.ignore(100, '\n');
            getline(cin, city1);
            cout<<"Enter an ending city:"<<endl;
            //cin.ignore(100, '\n');
            getline(cin, city2);
            if(g.checkA()==1)
            {
                if(g.checkV(city1, city2)>0)
                {
                     g.shortDistance(city1, city2);
                }
            }
            else
            {
                cout<<"Please identify the districts before checking distances"<<endl;
            }
        }
        if(input=="5")
        {
            string city1;
            cout<<"Enter a starting city:"<<endl;
            cin.ignore(100, '\n');
            getline(cin, city1);
            if(g.checkA()==1)
            {
                g.extra(city1);
            }
            else
            {
                cout<<"Please identify the districts before checking distances"<<endl;
            }
        }
        if(input=="6")
        {
            cout<<"Goodbye!"<<endl;
            return 0;
        }
    }
    return 0;
}
