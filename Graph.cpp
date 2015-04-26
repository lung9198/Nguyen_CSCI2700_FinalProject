#include "Graph.h"
#include <vector>
#include <iostream>
#include <queue>
#include <time.h>
using namespace std;

Graph::Graph()
{
    //ctor
}

Graph::~Graph()
{
    //dtor
}
void Graph::action()
{

}
void Graph::getAdj()
{
    cout<<"--Connected Outposts-- -||- ";
    for(int i=0;i<vertices[curIndex].adj.size();i++)
    {
        cout<<vertices[curIndex].adj[i].v->name<<" -||- ";
    }
    cout<<endl;
    cout<<"-# of Outpost from HQ- -||- ";
    for(int j=0;j<vertices[curIndex].adj.size();j++)
    {
        cout<<vertices[curIndex].adj[j].v->fromEndPoint<" -||- ";
    }
    cout<<endl;
}
void Graph::setDistance()
{
    for(int i=0;i<vertices.size();i++)
    {
        if(i==endIndex)
        {
            vertices[i].fromEndPoint=0;
        }
        if(i!=endIndex)
        {
            vertices[i].fromEndPoint=findPoint(i,endIndex);
            //cout<<i<<"------"<<vertices[i].fromEndPoint<<endl;
        }

    }
}
void Graph::createNodes()
{
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j"};
    for(int n=0;n<10;n++)
    {
        for(int m=1;m<11;m++)
        {
            string a;
            a=alphabet[n]+to_string(m);
            nodes.push_back(a);
        }
    }
    curIndex=0;
    setOrigin();
    randomize();
    setEdges();
    setEndPoint();
    setDistance();

}
void Graph::setOrigin()
{
    srand ( time(NULL) );
    int ori=rand() %100;
    addVertex(nodes[ori]);
    nodes.erase(nodes.begin()+ori);
}
void Graph::randomize()
{
    while(!nodes.empty())
    {
        srand ( time(NULL) );
        int randx=rand()%nodes.size();
        addVertex(nodes[randx]);
        nodes.erase(nodes.begin()+randx);
    }
}

void Graph::setEdges()
{
    int i=0;
    bool check=0;
    int levelcheck=0;
    int newc=0;
    int lvlc=0;
    queue<vertex> e;
    e.push(vertices[i]);
    vertices[0].row=1;
    vertices[0].col=1;
    for(int j=0;j<2;j++)
    {
        i++;
        addEdge(e.front().name,vertices[i].name,randt());
        if(i==1)
        {
           vertices[1].row=2;
           vertices[1].col=1;
        }
        if(i==2)
        {
           vertices[2].row=1;
           vertices[2].col=2;
        }
        e.push(vertices[i]);
        levelcheck=2;
    }
    e.pop();
    while(!e.empty() and i<100)
    {
        if(i==99)
            break;
        for(int k=0;k<=1;k++)
        {
            if(i==99)
                break;
            if(k==0 and check==0)
            {
                i++;
                addEdge(e.front().name,vertices[i].name,randt());
                vertices[i].row=e.front().row+1;
                vertices[i].col=e.front().col;
                e.push(vertices[i]);
                //newc++;
                cout<<"INDEX--"<<e.front().index+1<<endl;
                cout<<i+1<<"        "<<"ROW--"<<vertices[i].row<<"COL--"<<vertices[i].col<<endl;
            }
            if(k==0 and check==1)
            {
                addEdge(e.front().name,vertices[i].name,randt());
                vertices[i].row=e.front().row+1;
                vertices[i].col=e.front().col;
                e.push(vertices[i]);
                //newc++;
                //cout<<i+1<<"        "<<"ROW--"<<vertices[i].row<<"COL--"<<vertices[i].col<<endl;
            }
            if(k==1 and check==1)
            {
                i++;
                addEdge(e.front().name,vertices[i].name,randt());
                vertices[i].row=e.front().row;
                vertices[i].col=e.front().col+1;
                e.push(vertices[i]);
                //newc++;
                cout<<"INDEX--"<<e.front().index+1<<endl;
                cout<<i+1<<"        "<<"ROW--"<<vertices[i].row<<"COL--"<<vertices[i].col<<endl;
                                lvlc++;
                e.pop();
            }
            if(k==1 and check==0)
            {
                i++;
                addEdge(e.front().name,vertices[i].name,randt());
                vertices[i].col=e.front().col+1;
                vertices[i].row=e.front().row;
                check=1;
                lvlc++;
                e.pop();
                cout<<"INDEX--"<<e.front().index+1<<endl;
                cout<<i+1<<"        "<<"ROW--"<<vertices[i].row<<"COL--"<<vertices[i].col<<endl;
            }
        }
//        cout<<i<<"        "<<"ROW--"<<vertices[i].row<<"COL--"<<vertices[i].col<<endl;
        if(lvlc==levelcheck)
        {
            levelcheck=levelcheck+1;
            check=0;
            lvlc=0;
            newc=0;
        }
    }
}
int Graph::findPoint(int one, int two)
{
    int coltotal=0;
    int rowtotal=0;
    if(vertices[one].col<vertices[two].col)
    {
        coltotal=vertices[two].col-vertices[one].col;
    }
    if(vertices[one].col>vertices[two].col)
    {
        coltotal=vertices[one].col-vertices[two].col;
    }
    if(vertices[one].row<vertices[two].row)
    {
        rowtotal=vertices[two].row-vertices[one].row;
    }
    if(vertices[one].row>vertices[two].row)
    {
        rowtotal=vertices[one].row-vertices[two].row;
    }
    int total=coltotal+rowtotal;
    return total;
};

void Graph::setEndPoint()
{
    int k=rand()%15+1;
    vertices[85-k].isEnd=1;
    endIndex=85-k;
}
int Graph::randt()
{
    //srand(time(NULL));
    int time=rand()%100+1;
    if(time<6)
        return 5;
    if(time>5 and time<16)
        return 4;
    if(time>15 and time<36)
        return 3;
    if(time>35 and time<66)
        return 2;
    if(time>65)
        return 1;
}
//int Graph::rande()
//{
//    int edges=0;
//    //srand(time(NULL));
//    edges=rand()%100+1;
//    //cout<<edges<<endl;
//    if(edges<26)
//    {
//        return 2;
//    }
//    if(edges>25 and edges<61)
//    {
//        return 3;
//    }
//    if(edges>60)
//    {
//        return 4;
//    }
//}
int Graph::addEdge(std::string v1, std::string v2, int weight)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == v1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j].name == v2 && i != j)
                {
                    if(vertices[i].adj.empty())
                    {
                        adjVertex av;
                        av.v = &vertices[j];
                        av.weight = weight;
                        vertices[i].adj.push_back(av);
                        //another vertex for edge in other direction
                        adjVertex av2;
                        av2.v = &vertices[i];
                        av2.weight = weight;
                        vertices[j].adj.push_back(av2);
                        return 1;
                    }
                    for(int k=0;k<vertices[i].adj.size();k++)
                    {
                        if(vertices[i].adj[k].v->name==v2)
                        {
                            return 1;
                        }
                        if(k==vertices[i].adj.size()-1)
                        {
                            adjVertex av;
                            av.v = &vertices[j];
                            av.weight = weight;
                            vertices[i].adj.push_back(av);
                            //another vertex for edge in other direction
                            adjVertex av2;
                            av2.v = &vertices[i];
                            av2.weight = weight;
                            vertices[j].adj.push_back(av2);
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 1;
};

void Graph::addVertex(string name)
{
    vertex v;
    v.name = name;
    v.index = pos;
    vertices.push_back(v);
    pos++;
};

int Graph::shortPath(std::string c1, std::string c2)
{
    for(int j=0;j<vertices.size();j++)
    {
        vertices[j].visited=0;
        vertices[j].prev=-1;
    }
    vector<vertex> x;
    queue<vertex> path;
    int num=0;
    for(int i=0;i<vertices.size();i++)
    {
        if(vertices[i].name==c1)
        {
            path.push(vertices[i]);
            vertices[i].visited=1;
            while(!path.empty())
            {
                for(int k=0;k<path.front().adj.size();k++)
                {
                    for(int h =0;h<vertices.size();h++)
                    {
                        if(vertices[h].name==path.front().adj[k].v->name and vertices[h].visited==0)
                        {
                            path.push(vertices[h]);
                            vertices[h].visited=1;
                            vertices[h].prev=path.front().index;
                            if(path.back().name==c2)
                            {
                                int y = path.back().index;
                                x.push_back(vertices[y]);
                                while(vertices[y].prev!=-1)
                                {
                                    x.push_back(vertices[y]);
                                    y=vertices[y].prev;
                                }
                                x.push_back(vertices[y]);
                                num++;
                                return num;
                                //cout<<num;
                                for(int g=x.size()-1;g>0;g--)
                                {
                                    cout<<","<<x[g].name;
                                }
                                //cout<<endl;
                            }
                        }
                    }
                }
                path.pop();
                num++;
            }
        }
    }
};

void Graph::shortDistance(std::string c1, std::string c2)
{
    for(int j=0;j<vertices.size();j++)
    {
        vertices[j].visited=0;
        vertices[j].prev=-1;
    }
    int distance=0;
    int maxd=100000;
    int tempd=0;
    vertex *x;
    int previ;
    vector<vertex>path;
    for(int i =0;i<vertices.size();i++)
    {
        if(vertices[i].name==c1)
        {
            path.push_back(vertices[i]);
            vertices[i].visited=1;
            for(int l=0;l<vertices.size();l++)
            {
                if(vertices[l].name==c2)
                {
                    while(vertices[l].visited==0&&vertices[l].id==vertices[i].id)
                    {
                        maxd=100000;
                        for(int k=0;k<path.back().adj.size();k++)
                        {
                            if(path.back().adj[k].weight<=maxd)
                            {
                                if(path.back().adj[k].v->name==c2)
                                {
                                    distance=distance+path.back().adj[k].weight;
                                    path.push_back(vertices[l]);
                                    cout<<distance;
                                    for (int m=0;m<path.size();m++)
                                    {
                                        cout<<","<<path[m].name;
                                    }
                                    cout<<endl;
                                    return;
                                }
                                if(path.back().adj[k].v->adj.size()<2)
                                {
                                    vertices[path.back().adj[k].v->index].visited=1;
                                }
                                if(path.back().adj[k].v->adj.size()>1)
                                {
                                    previ=path.back().adj[k].v->index;
                                    maxd=path.back().adj[k].weight;
                                }
                                if(path.back().prev!=-1)
                                {
                                    int temp = path.back().adj[k].v->index;
                                    for(int r=0;r<vertices[temp].adj.size();r++)
                                    {
                                        if(vertices[temp].adj[r].v->index==path.back().prev)
                                        {
                                            if(((vertices[temp].adj[r].v->dist)+vertices[temp].adj[r].weight)<=(distance+maxd))
                                            {
                                                distance=-tempd;
                                                maxd=vertices[temp].adj[r].weight;
                                                previ=vertices[temp].adj[r].v->index;
                                            }
                                        }
                                    }
                                }

                            }
                        }
                        tempd=maxd;
                        distance=+maxd;
                        vertices[previ].prev=path.back().index;
                        vertices[previ].visited=1;
                        vertices[previ].dist=distance;
                        path.push_back(vertices[previ]);
                    }
                }
            }
        }
    }
        cout << "No safe path between cities" << endl;
    return;
};

void Graph::printVertices()
{
    for(int i =0; i<vertices.size();i++)
    {
        cout<<vertices[i].id<<":"<<vertices[i].name;
        cout<<"-->";
        for(int k =0;k<vertices[i].adj.size();k++)
        {
            cout<<vertices[i].adj[k].v->name;
            if(k!=vertices[i].adj.size()-1)
            {
                cout<<"***";
            }
        }
        cout<<endl;
    }
};

int Graph::checkA()
{
    return a;
};

int Graph::checkV(string c1, string c2)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == c1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j].name == c2 && i != j)
                {
                    return 1;
                }
            }
        }
    }
    cout << "One or more cities doesn't exist" << endl;
    return 0;
};

void Graph::extra(string c1)
{
    min1=0;
    e=0;
    maxmin=10000000;
    curw=0;
    maxi=0;
    firstw =0;
    int x;
    for(int i =0;i<vertices.size();i++)
    {
         if(vertices[i].name==c1)
         {
             firstw=i;
             x=i;
             vertices[i].visited=1;
             z.push_back(vertices[i]);
         }
         else
         {
             vertices[i].visited=0;
         }
    }
    for(int k=0;k<vertices[x].adj.size();k++)
    {
        if(vertices[x].adj[k].v->visited==0)
        {
            e++;
            curw=vertices[x].adj[k].weight;
            min1+=curw;
            vertices[vertices[x].adj[k].v->index].visited=1;
            z.push_back(vertices[vertices[x].adj[k].v->index]);
            abc(vertices[vertices[x].adj[k].v->index]);
            vertices[vertices[x].adj[k].v->index].visited=0;
            z.pop_back();
            e--;
            min1-=vertices[x].adj[k].weight;
        }
    }
    cout << maxmin<<endl;
    cout<<maxmin;
    for(int j=0;j<lowest.size();j++)
    {
        cout << "," << lowest[j].name;
    }
    cout <<","<<lowest[0].name<< endl;
    for(int b=0;b<lowest.size();b++)
    {
        lowest.pop_back();
    }
};

void Graph::abc(vertex v)
{
    for(int i=0;i<v.adj.size();i++)
    {
        if(v.adj[i].v->visited==0)
        {
            e++;
            curw=v.adj[i].weight;
            min1+=curw;
            vertices[v.adj[i].v->index].visited=1;
            maxi++;
            z.push_back(vertices[v.adj[i].v->index]);
            abc(vertices[v.adj[i].v->index]);
            vertices[v.adj[i].v->index].visited=0;
            z.pop_back();
            min1-=v.adj[i].weight;
            e--;
        }
    }
        int q=0;
        if(e==9)
        {
            for(int n=0;n<v.adj.size();n++)
            {
                if(v.adj[n].v->index==firstw)
                {
                    q=v.adj[n].weight;
                    min1+=q;
                }
            }
        }
    //cout<<e<<endl;
    if(e==9&&maxmin>min1)
    {
        if(lowest.size()>1)
        {
            for(int t=0;t<z.size();t++)
            {
                lowest.pop_back();
            }
        }
        for(int t=0;t<z.size();t++)
        {
            lowest.push_back(z[t]);
        }
        maxmin=min1;
        //cout<<maxmin<<endl;
    }
    min1-=q;

};















