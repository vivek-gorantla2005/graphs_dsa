#include<iostream>
#include<vector>
using namespace std;

bool DFS(int node,vector<int>adj[],vector<int>visited,vector<int>pathVisited){
    visited[node] = 1;
    pathVisited[node] = 1;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(DFS(it,adj,visited,pathVisited)){
                return true;
            }
        }
        else if(pathVisited[it]){
            return true;
        }
    }
}

void main(){
    vector<int>adj[6] = {{1,2},{3},{3,4},{5},{5},{}};
    vector<int>visited(6,0);
    vector<int>pathVisited(6,0);
    for(int i=0;i<6;i++){
        if(!visited[i]){
            if(DFS(i,adj,visited,pathVisited)){
                cout<<"Cycle is present";
                return;
            }
        }
    }
    cout<<"Cycle is not present";
    return;
}