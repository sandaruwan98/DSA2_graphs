
#include <iostream>
#include <string.h>
#include <list>
using namespace std;

class Graph
{
    int **matrix;
    int v;
    int *inDegree;
    int *outDegree;

public:
    Graph(int v);
    void AddEdge(int v, int w) { matrix[v][w] = 1;}

    void BFS(int s);
    void DFS();
    void Visit(int v, char *visited);
    void FindInDegree();
    void FindOutDegree();
    void PrintMatrix();
};

Graph::Graph(int v)
{
    this->v = v;
    matrix = new int *[v];

    inDegree = new int[v];
    outDegree = new int[v];
    int i;
    for (i = 0; i < v; i++)
    {
        matrix[i] = new int[v];
        memset(matrix[i], 0, sizeof(int) * v);
    }
}


void Graph::PrintMatrix()
{
    int i, j;
    cout << "    ";
    for (i = 0; i < v; i++)
        cout << i << " ";
    cout << endl;
    cout << "   ";
    for (i = 0; i < v; i++)
        cout << "--";
    cout << endl;

    for (i = 0; i < v; i++)
    {
        cout << i << " | ";
        for (j = 0; j < v; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// void Graph::DFS()
// {
//     char *visited = new char[v];
//     int i;
//     for (i = 0; i < v; i++)
//         visited[i] = 'W';

//     for (i = 0; i < v; i++)
//         if (visited[i] == 'W')
//             Visit(i, visited);
// }

// void Graph::Visit(int v, char *visited)
// {
//     visited[v] = 'G';

//     list<int>::iterator i;
//     for (i = gph[v].begin(); i != gph[v].end(); ++i)
//     {
//         if (visited[*i] == 'W')
//         {
//             Visit(*i, visited);
//         }
//     }

//     cout << v << endl;
// }

// void Graph::FindInDegree()
// {
//     int i;
//     for (i = 0; i < v; i++)
//         inDegree[i] = 0;

//     for (i = 0; i < v; i++)
//     {
//         list<int>::iterator j;
//         for (j = gph[i].begin(); j != gph[i].end(); ++j)
//             inDegree[*j]++;
//     }

//     for (i = 0; i < v; i++)
//         cout << i << " -- " << inDegree[i] << endl;
// }

// void Graph::FindOutDegree()
// {
//     int i;
//     for (i = 0; i < v; i++)
//         outDegree[i] = 0;

//     for (i = 0; i < v; i++)
//     {
//         list<int>::iterator j;
//         for (j = gph[i].begin(); j != gph[i].end(); ++j)
//             outDegree[i]++;
//     }

//     for (i = 0; i < v; i++)
//         cout << i << " -- " << outDegree[i] << endl;
// }

int main()
{
    Graph g(4);
    g.AddEdge(1, 2);
    g.AddEdge(1, 3);
    g.AddEdge(3, 1);
    g.AddEdge(2, 0);
    g.PrintMatrix();
  
    cout << endl
         << "BFS" << endl;
    g.BFS(2);
    // cout << endl
    //      << "DFS" << endl;
    // g.DFS();
    // cout << endl
    //      << "InDegree" << endl;
    // g.FindInDegree();
    // cout << endl
    //      << "OutDegree" << endl;
    // g.FindOutDegree();
    // return 0;
}

// 0   1
// 1   3
// 2   1
// 3   0
