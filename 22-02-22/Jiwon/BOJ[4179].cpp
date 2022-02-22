#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
string board[1002];	//board에 문자도 있으니까 string으로 받는다. 
int dist1[1002][1002];	//불의 이동거리 
int dist2[1002][1002];	//지훈의 이동거리 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q1;	//불의 큐 
    queue<pair<int,int>> Q2;	//지훈의 큐 
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) cin >> board[i];
    for(int i=0 ; i<n ; i++){	//dist 배열을 모두 -1로 초기화. 
        fill(dist1[i], dist1[i]+m, -1);
        fill(dist2[i], dist2[i]+m, -1);
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(board[i][j]=='F'){
                Q1.push({i,j});
                dist1[i][j]=0;
            }
            if(board[i][j]=='J'){
                Q2.push({i,j});
                dist2[i][j]=0;
            }
        }
    }
    while(!Q1.empty()){	//불의 이동부터 BFS 돌리기. 
        pair<int,int> cur = Q1.front(); Q1.pop();
        for(int dir=0 ; dir<4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx >= n || ny < 0 || ny >=m) continue;
            if(board[nx][ny]=='#' || dist1[nx][ny]>=0) continue;
            dist1[nx][ny] = dist1[cur.X][cur.Y]+1;
            Q1.push({nx,ny});
        }
        
    }
    while(!Q2.empty()){	//불의 이동에 따라 지훈의 이동이 정해짐. 벽으로 막힌 곳 x, 불이 먼저 붙은 곳 x 
        pair<int,int> cur = Q2.front(); Q2.pop();외 
        for(int dir=0 ; dir<4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx >= n || ny < 0 || ny >=m){	//지훈이 n*m 행렬에서 벗어낫다는 것은 탈출했다는 것. 
                cout << dist2[cur.X][cur.Y]+1;
                return 0;
            };
            if(board[nx][ny]=='#' || dist2[nx][ny]>=0) continue;
            if(dist1[nx][ny]!=-1 && dist1[nx][ny]<=dist2[cur.X][cur.Y]+1) continue;	//불이 먼저 난 칸 제 
            dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
            Q2.push({nx,ny});
        }
        
    }
    cout << "IMPOSSIBLE";
    return 0;    
}
