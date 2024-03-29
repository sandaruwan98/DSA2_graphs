
#include <iostream>
#include <list>
using namespace std;

class Graph
{
    list<int> *gph;
    int v;
    int *inDegree;
    int *outDegree;

public:
    Graph(int v);
    void AddNode(int v, int w);
    void BFS(int s);
    void DFS();
    void Visit(int v, char *visited);
    void FindInDegree();
    void FindOutDegree();
};

Graph::Graph(int v)
{
    this->v = v;
    gph = new list<int>[v];
    inDegree = new int[v];
    outDegree = new int[v];
}

void Graph::AddNode(int v, int w)
{
    gph[v].push_back(w);
}

void Graph::BFS(int s)
{
    int *visited = new int[v];

    int i;
    for (i = 0; i < v; i++)
    {
        visited[i] = 0;
    }

    list<int> queue;
    queue.push_back(s);

    std::list<int>::iterator j;
    while (!queue.empty())
    {
        s = queue.front();
        //print
        cout << s << endl;
        for (j = gph[s].begin(); j != gph[s].end(); ++j)
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

void Graph::DFS()
{
    char *visited = new char[v];
    int i;
    for (i = 0; i < v; i++)
        visited[i] = 'W';

    for (i = 0; i < v; i++)
        if (visited[i] == 'W')
            Visit(i, visited);
}

void Graph::Visit(int v, char *visited)
{
    visited[v] = 'G';

    list<int>::iterator i;
    for (i = gph[v].begin(); i != gph[v].end(); ++i)
    {
        if (visited[*i] == 'W')
        {
            Visit(*i, visited);
        }
    }

    cout << v << endl;
}

void Graph::FindInDegree()
{
    int i;
    for (i = 0; i < v; i++)
        inDegree[i] = 0;

    for (i = 0; i < v; i++)
    {
        list<int>::iterator j;
        for (j = gph[i].begin(); j != gph[i].end(); ++j)
            inDegree[*j]++;
    }

    for (i = 0; i < v; i++)
        cout << i << " -- " << inDegree[i] << endl;
}

void Graph::FindOutDegree()
{
    int i;
    for (i = 0; i < v; i++)
        outDegree[i] = 0;

    for (i = 0; i < v; i++)
    {
        list<int>::iterator j;
        for (j = gph[i].begin(); j != gph[i].end(); ++j)
            outDegree[i]++;
    }

    for (i = 0; i < v; i++)
        cout << i << " -- " << outDegree[i] << endl;
}

int main()
{
    Graph g(4);
    g.AddNode(0, 1);
    g.AddNode(1, 3);
    g.AddNode(2, 1);
    g.AddNode(3, 0);
    cout << endl
         << "BFS" << endl;
    g.BFS(2);
    cout << endl
         << "DFS" << endl;
    g.DFS();
    cout << endl
         << "InDegree" << endl;
    g.FindInDegree();
    cout << endl
         << "OutDegree" << endl;
    g.FindOutDegree();
    return 0;
}

// 0   1
// 1   3
// 2   1
// 3   0
