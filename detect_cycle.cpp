#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool BFS_detect(int src,vector<int>adj[],vector<bool>&visited){
    visited[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it]=1;
                q.push({it,node});
            }
            else if(parent!=it){
                return true;
            }
        }
        return false;
    }
}

bool DFS_detect(int node,int parent,vector<int>&visited,vector<int>adj[]){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(DFS_detect(it,node,visited)){
                return true;
            }
        }
        else if(it!=parent){
            return true;
        }
    }
    return false;
 
}

int main(){
    vector<int>nums;
    queue<int> q;
    vector<int> adj[5] = {{1,2,4},{2,1,3},{3,2,4,5},{4,1,3},{5,2,3}};
    vector<bool> visited(5, false);

    if(BFS_detect(1,adj,visited)){
        cout<<"Cycle is present";
    }
    else{
        cout<<"Cycle is not present";
    }
    return 0;
}