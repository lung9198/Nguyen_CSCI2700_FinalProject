#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <limits>
#include "Graph.h"
#include <time.h>
using namespace std;

int main(int argc, char* argv[])
{
    srand(time(0));
    Graph g;
    string input;
    int test=0;
    g.createNodes();
    while(test!=1)
    {
        g.getAdj();
        cout<<"-Which Outpost would you like to travel?"<<endl;
        cin>>input;
        g.action(input);
        if(g.endGame()==1)
        {
            test=1;
        }
    }
    return 0;
}
