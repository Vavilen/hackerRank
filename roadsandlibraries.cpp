#include <vector>
#include <iostream>

using namespace std;

void dfs(int v, bool visited[], vector<int> edge[], int &cc)
{
    visited[v] = true;
    cc++;
    for(vector<int>::iterator it = edge[v].begin(); it != edge[v].end(); ++it){
        if(!visited[*it]) dfs(*it, visited, edge, cc);
    }
}

int main(){
    int q;
    cin >> q;

    uint64_t cost[q];

    for(int i=0; i<q; i++){
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        vector<int> edge[n+5];
        bool *visited = new bool[n+5];
        vector<int> components;
        int not_connected = 0;
        //add edges for the both vertexes
        for(int j = 0; j < m; j++){
            int c1;
            int c2;
            cin >> c1 >> c2;
            edge[c1].push_back(c2);
            edge[c2].push_back(c1);
        }
        //if price of the library is less or equal than road and the count of the roads is zero
        // just calculate the total price for the case
        if(x <= y || m == 0){
            cost[i] = n*x;
            continue;
        }
        //mark all vertexes as unvisited
        for(int v = 1; v <= n; v++)
            visited[v] = false;

        // for all vertexes
        for(int v = 1; v <= n; v++)
        {
            // no edges for this vertex
            if(edge[v].empty()){
                //add as not connected vertex
                not_connected++;
            } else if (!visited[v]) // not visited
            {
                int cc = 0;
                dfs(v, visited, edge, cc);
                // roads count to build for the vertex
                components.push_back(cc);
            }
        }

        // WTF???
        cost[i] = not_connected*x;
        for(auto c: components){
            cost[i] += x + (c-1)*y; // total cost for the case
        }

        delete[] visited;

    }

    for(int i=0; i<q; i++){
        cout << cost[i] << endl;
    }

    return 0;
}

// для определения кол-ва дорог нам подходит DFS, тк задача пройти каждый соединенный вертекс только 1 раз. Если мы где-то не были, то просто идем до
// непройденного вертекса. если были, то просто останавливаемся. таким образом, мы пройдем все участки соединенные участки. для каждого участка мы построим 1 библиотеку и дороги в количестве,
// равном количеству переходов по участку

