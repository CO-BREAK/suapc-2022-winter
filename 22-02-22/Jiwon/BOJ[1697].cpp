/*
일차원 BFS
*/
#include <bits/stdc++.h>
using namespace std;
int n,m;
int dist[100002];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    fill(dist, dist+100002, -1);
    dist[n]=0;
    queue<int> Q;
    Q.push(n);
    while(dist[m]==-1){
        int cur = Q.front(); Q.pop();
        for(int nxt : {cur-1, cur+1, cur*2}){	//이 for문도 기억할 것! 
            if(nxt<0 || nxt > 100002 || dist[nxt]>=0) continue;	//이동한 범위가 0미만 100000이상이면 x 
            dist[nxt] = dist[cur]+1;
            Q.push(nxt);
        }
    }
    cout << dist[m];
    return 0;
}
