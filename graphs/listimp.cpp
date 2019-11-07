
#include <iostream>
#include <list> 
using namespace std;
struct node
{
    list<int> vertex;
    int val;
};



class Graph{
    list<int> *gph;
    int v;
    
    public:
    Graph(int v);
    void AddNode(int v,int w);
    void BFS(int s);
};

Graph::Graph(int v){
    this->v = v;
    gph = new list<int>[v];
}

void Graph::AddNode(int v,int w){
    gph[v].push_back(w);
}

void Graph::BFS(int s){
    int *visited = new int[v];
    int i;
    for ( i = 0; i < v; i++)
    {
        visited[i]=0;
    }
    
    list<int> queue;
    queue.push_back(s);
    
    visited[s] = 1;
    while (!queue.empty())
    {
        s = queue.front();
        for ( i = 0; i < gph[s].size(); i++)
        {
           queue.push_back(1);
        }
        
    }
    


}

int main()
{
    
    return 0;
}

