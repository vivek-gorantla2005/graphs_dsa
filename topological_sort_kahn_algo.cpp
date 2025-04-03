#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    vector<int>adj[6] = {{},{1},{3},{1},{0,1},{0,2}};
    vector<int>indegree(6,0);
    for(int i=0;i<6;i++){
        for(auto it:adj[i]){
            indegree[it]++;
        }
    }

    queue<int>q;
    for(int i=0;i<6;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    for(auto it:topo){
        cout<<it<<" ";
    }

}