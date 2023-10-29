#include <iostream>
#include <vector>
#include <queue>
using namespace std;



    int initState , goalState , edgeNum , from , to , depth[1000];
    bool visited[1000];

    queue<int>openList;

    vector<int> adj[1000] , closedList;

    void setGraph(){
        cout << "Enter The Number Of eadgs: "; cin >> edgeNum;
        cout << "Enter The eadgs: ";
        for (int i = 0; i < edgeNum; i++)
        {
            cin >> from >>to;
            adj[from].push_back(to);
        }
        
    }


    void BFS(int start){
        visited[start] = true;
        depth[start] = 0;
        openList.push(start);

        while (!openList.empty())
        {
            int curState = openList.front();

            openList.pop();

            closedList.push_back(curState);

            if(curState == goalState){ return ; }

             for(auto state : adj[curState]) {
               if(visited[state]) continue;
               visited[state] = true;
               depth[state] = depth[curState] + 1;
               openList.push(state);

             }   
        }
        return ;
    }


    void Display(){
        cout << "The order of Nodes we go to achive the goal node is: ";
        for (int i = 0; i < closedList.size(); i++)
        {
            cout << closedList[i] << " ";
        }
        cout << " And the Goal is in the level: " << depth[goalState] << endl;
        
    }

int main(int argc, const char** argv) {
    setGraph();
    cout << "Enter the Starting Node: ";      cin >> initState;
    cout << "Enter the Goal Node: ";          cin >> goalState;
    BFS(initState);
    Display();
    return 0;
}