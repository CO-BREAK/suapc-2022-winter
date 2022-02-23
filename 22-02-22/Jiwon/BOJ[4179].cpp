#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
string board[1002];	//board�� ���ڵ� �����ϱ� string���� �޴´�. 
int dist1[1002][1002];	//���� �̵��Ÿ� 
int dist2[1002][1002];	//������ �̵��Ÿ� 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q1;	//���� ť 
    queue<pair<int,int>> Q2;	//������ ť 
    cin >> n >> m;
    for(int i=0 ; i<n ; i++) cin >> board[i];
    for(int i=0 ; i<n ; i++){	//dist �迭�� ��� -1�� �ʱ�ȭ. 
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
    while(!Q1.empty()){	//���� �̵����� BFS ������. 
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
    while(!Q2.empty()){	//���� �̵��� ���� ������ �̵��� ������. ������ ���� �� x, ���� ���� ���� �� x 
        pair<int,int> cur = Q2.front(); Q2.pop();�� 
        for(int dir=0 ; dir<4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx >= n || ny < 0 || ny >=m){	//������ n*m ��Ŀ��� ����ٴ� ���� Ż���ߴٴ� ��. 
                cout << dist2[cur.X][cur.Y]+1;
                return 0;
            };
            if(board[nx][ny]=='#' || dist2[nx][ny]>=0) continue;
            if(dist1[nx][ny]!=-1 && dist1[nx][ny]<=dist2[cur.X][cur.Y]+1) continue;	//���� ���� �� ĭ �� 
            dist2[nx][ny] = dist2[cur.X][cur.Y]+1;
            Q2.push({nx,ny});
        }
        
    }
    cout << "IMPOSSIBLE";
    return 0;    
}
