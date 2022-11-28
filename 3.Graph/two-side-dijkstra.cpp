#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dijkstra(int n, int s, vector<vector<pair<int, int>>> &G, vector<int> &curlen){
    vector<bool> isShortest(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    curlen[s] = 0;
    pq.emplace(0, s);
    while(!pq.empty()){
        auto curweight = pq.top().first;
        auto curvertex = pq.top().second;
        pq.pop();
        if(!isShortest[curvertex]){
            isShortest[curvertex] = true;
            for(int i = 0; i < G[curvertex].size(); i++){// update all the vertices
            //take the edges with source "curvertex"
            auto vertex = G[curvertex][i].second;
            auto weight = G[curvertex][i].first;
            //if the currlent length of i is greater than updated data, update it
                if(curlen[vertex] > weight + curweight){
                    curlen[vertex] = weight + curweight;
                    //then, emplace back the new edge
                    pq.emplace(curlen[vertex], G[curvertex][i].second);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> prices(n);
    vector<vector<pair<int, int>>> graph(n);
    vector<vector<pair<int, int>>> antigraph(n);
    vector<int> cost(n, 0x3f3f3f3f);
    vector<int> anticost(n, 0x3f3f3f3f);
    for(int i = 0; i < n; i++){
        cin>>prices[i];
    }
    for(int i = 0; i < m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].emplace_back(c, b);
        antigraph[b].emplace_back(c, a);
    }
    dijkstra(n, 0, graph, cost);
    dijkstra(n, 0, antigraph, anticost);
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, prices[i]-cost[i]-anticost[i]);
    }
    cout<<ans;
    return 0;
}
