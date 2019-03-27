#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_SIZE = 5000;

struct Cell
{
    int x;
    int y;
    int dist;

    Cell()
    {
        x = 0;
        y = 0;
        dist = 0;
    }
};

void getNeighbours(Cell cell, vector<Cell>& neighbours, int n, int m)
{
    Cell next;
    if(cell.x > 0)
    {
        next.x = cell.x - 1;
        next.y = cell.y;
        next.dist = cell.dist + 1;
        neighbours.push_back(next);
       // cout << "nextX = " << next.x << " nextY = " << next.y << endl;
    }
    if(cell.y > 0)
    {
        next.x = cell.x;
        next.y = cell.y - 1;
        next.dist = cell.dist + 1;
        neighbours.push_back(next);
        //cout << "nextX = " << next.x << " nextY = " << next.y << endl;


    }
    if(cell.x < n - 1)
    {
        next.x = cell.x + 1;
        next.y = cell.y;
        next.dist = cell.dist + 1;
        neighbours.push_back(next);
       // cout << "nextX = " << next.x << " nextY = " << next.y << endl;

    }
    if(cell.y < m - 1)
    {
        next.x = cell.x;
        next.y = cell.y + 1;
        next.dist = cell.dist + 1;
        neighbours.push_back(next);
       // cout << "nextX = " << next.x << " nextY = " << next.y << endl;


    }
}

int bfs(vector<vector<int>>& matrix, Cell destination, int n, int m)
{
    Cell start;
    start.x = 0;
    start.y = 0;
    start.dist = 0;
    bool** visited = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    queue<Cell> openList;
    openList.push(start);
    visited[start.x][start.y] = true;
    while(!openList.empty())
    {
        Cell current = openList.front();
        openList.pop();
        if(current.x == destination.x && current.y == destination.y)
        {
            return current.dist;
        } else
        {
            vector<Cell> neighbours;
            getNeighbours(current, neighbours, n, m);
            for(int i = 0; i < neighbours.size(); i++)
            {
                if(visited[neighbours[i].x][neighbours[i].y] == false)
                {
                    visited[neighbours[i].x][neighbours[i].y] = true;
                   if(matrix[neighbours[i].x][neighbours[i].y] != 1)
                   {
                        openList.push(neighbours[i]);
                   }
                }
            }
        }

    }

    return -1;

}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> matrix;
    int k;
    cin >> k;
    for(int i = 0; i < n; i++)
    {
        vector<int> tempVector;
        for(int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            tempVector.push_back(tmp);
        }
        matrix.push_back(tempVector);
    }

 /*   vector<vector<bool>> visited;
    for(int i = 0; i < n; i++)
    {
        vector<bool> vis;
        for(int j = 0; j < m; j++)
        {
            vis.push_back(false);
        }
        visited.push_back(vis);
    }
     for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }*/


    bool** visited = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    for(int i = 0; i < k; i++)
    {
        Cell destination;
        int x;
        cin >> x;
        int y;
        cin >> y;
        destination.x = x;
        destination.y = y;
        if(visited[x][y])
        cout << bfs(matrix, destination, n, m) << endl;
    }










    return 0;
}
