/*
������ BFS
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
        for(int nxt : {cur-1, cur+1, cur*2}){	//�� for���� ����� ��! 
            if(nxt<0 || nxt > 100002 || dist[nxt]>=0) continue;	//�̵��� ������ 0�̸� 100000�̻��̸� x 
            dist[nxt] = dist[cur]+1;
            Q.push(nxt);
        }
    }
    cout << dist[m];
    return 0;
}
