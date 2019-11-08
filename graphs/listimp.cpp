
#include <iostream>
#include <list> 
using namespace std;
// struct node
// {
//     list<int> vertex;
//     int val;
// };



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
    
    

    std::list<int>::iterator j;
    while (!queue.empty())
    {
        s = queue.front();
        //print 
        cout << s << endl;
        for ( j = gph[s].begin(); j != gph[s].end(); ++j)
        {
            if (visited[*j] == 0)
            {
                queue.push_back(*j);
                visited[*j] = 1;
            }
        }

        queue.pop_front();
        
    }
    


}

int main()
{
    Graph g(4);
    g.AddNode(0,1);
    g.AddNode(1,3);
    g.AddNode(2,1);
    g.AddNode(3,0);
    g.BFS(2);
    return 0;
}

