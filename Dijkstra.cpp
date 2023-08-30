#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
const int N= 1e3+5;
const int INF= 1e9+10;
//vector<pair<int,int>>pii;
vector<pii>adj[N];
vector<bool>visited(N);

vector<int>dist(N,INF);
//initially shobar distance INF kore raklam

void dijkstra(int source){
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    dist[source]=0;
    pq.push({dist[source], source});

    while(!pq.empty()){
        int u= pq.top().second;//node ta ber korchi distance ta na
        pq.pop();
        visited[u]=true;

        for(pii vpair: adj[u]){
            int v= vpair.first;//input eo ei order ei nisi
            int w= vpair.second;
        
          if(visited[v]) continue;
          if(dist[v]> dist[u]+w){
            dist[v]= dist[u]+w;
            pq.push({dist[v],v});
           
          }
        }
    }

}

int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    }
    int s,d;
    cin>>s>> d;
    dijkstra(s);
    cout<<dist[d];
// for(int i=1; i<=n; i++){
//     cout<<"Distance of "<<i<<" : ";
//     cout<<dist[i]<<endl;
// }

   
return 0;
}
