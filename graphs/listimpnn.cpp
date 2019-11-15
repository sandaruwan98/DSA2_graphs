
#include <iostream>
#include <list>
using namespace std;
class node
{
public:
    node(int v)
    {
        val = v;
        // vertex.push_back(w);
    }
    list<int> vertex;
    int val;
};

class Graph
{
    list<node> gph;
    int v;

public:
    Graph(int v);
    void AddNode(int v);
    void AddEdge(int source, int dest);
    void BFS(int s);
    void DFS(int s);
};

Graph::Graph(int v)
{
    this->v = v;
}

void Graph::AddNode(int val)
{
    node *tmp = new node(val);
    // gph[v].push_back(w);
    gph.push_back(*tmp);
    //    cout << gph.back().val << " ";
}

void Graph::AddEdge(int source, int dest)
{

    list<node>::iterator i = gph.begin();
    while (source != (i->val))
    {
        ++i;
    }

    i->vertex.push_back(dest);
    cout << i->val << " - " << i->vertex.back() << endl;
}

void Graph::BFS(int s)
{
    int *visited = new int[v];
    int j;
    for (j = 0; j < v; j++)
    {
        visited[j] = 0;
    }

    list<int> queue;
    queue.push_back(s);

    std::list<int>::iterator i;
    while (!queue.empty())
    {
        s = queue.front();
        visited[s] = 1;
        list<node>::iterator k = gph.begin();
        while (s != (k->val))
        {
            ++k;
        }
        //print
        cout << s << endl;
        for (i = k->vertex.begin(); i != k->vertex.end(); ++i)
        {
            if (visited[*i] == 0)
            {
                queue.push_back(*i);
                visited[*i] = 1;
            }
        }

        queue.pop_front();
    }
    cout << endl;
    for (j = 0; j < v; j++)
    {

        cout << visited[j] << " ";
    }
}

void Graph::DFS(int s)
{
}

int main()
{
    Graph g(4);
    g.AddNode(0);
    g.AddNode(1);
    g.AddNode(2);

    g.AddNode(3);

    g.AddEdge(0, 1);
    g.AddEdge(1, 3);
    g.AddEdge(2, 1);
    g.AddEdge(3, 0);
    cout << endl
         << endl;
    g.BFS(2);
    return 0;
}
