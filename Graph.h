#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>

struct gear
{
    int Batteries;
    int Bullets;
    int Flares;
};

struct vertex;

struct adjVertex
{
    vertex *v;
    int weight;
};

struct vertex
{
    std::string name;
    bool visited;
    std::vector<adjVertex> adj;
    int index=-1;
    int prev =-1;
    int dist=0;
    int o=0;
    int id=-1;
   // int pos=0;

    int fromEndPoint;
    int frontlinks=0;
    int backlinks=0;
    int links=0;
    bool isEnd=0;
    int right;
    int left;
    int row=1;
    int col=1;


};
class Graph
{
    public:
        Graph();
        virtual ~Graph();
        int addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        int shortPath(std::string c1, std::string c2);
        void shortDistance(std::string c1, std::string c2);
        void extra(std::string c1);
        void abc(vertex v);
        int checkA();
        int checkV(std::string c1, std::string c2);
        void printVertices();

        void createNodes();
        void setOrigin();
        void randomize();
        void setEdges();
        //int rande();
        int randt();
        void setEndPoint();
        void action();
        void getAdj();
        void setDistance();
        int findPoint(int, int);

    protected:
    private:
        int min1=0;
        int e=0;
        int maxmin=10000000;
        int curw=0;
        int maxi=0;
        int firstw =0;
        int a=0;
        int pos =0;
        int endIndex=-1;
        int curIndex=0;
        std::vector<std::string> nodes;
        std::vector<vertex> vertices;
        std::vector<vertex> z;
        std::vector<vertex> lowest;
};

#endif // GRAPH_H
