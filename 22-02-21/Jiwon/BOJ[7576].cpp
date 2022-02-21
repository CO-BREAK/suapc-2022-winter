#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int board[1002][1002];
int dist[1002][1002];	//전역변수이기 때문에 dist는 0으로 초기화 된다. 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int> > Q;
    cin >> m >> n;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> board[i][j];
            if(board[i][j]==1){
                Q.push({i,j});    //익은 토마토 큐에 넣기
            } 
            if(board[i][j]==0) dist[i][j]=-1;	//안 익은 토마토는 길의 대상이기 때문에 -1 대입. 
        }
    }
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir=0 ; dir<4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx >=n || ny<0 || ny >=m) continue;
            if(dist[nx][ny]>=0) continue;	//dist가 0이면 익은 토마토이거나 토마토가 없는 칸이다. 따라서 갈 필요가 없다. 
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }
    }
    int ans=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(dist[i][j]==-1){	//안익은 토마토에게만 -1을 대입했었기 때문에 -1이 있으면 모두 익지 않았음을 알 수 있다. 
                cout << -1;
                return 0;
            }
            ans = max(ans, dist[i][j]);
        }
    }
    cout << ans;
    return 0;
}
