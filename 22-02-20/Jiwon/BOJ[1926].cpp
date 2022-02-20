#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int> >Q;
    int n, m;
    int max_w=0;
    int num=0;
    cin >> n >> m;
    int **board = (int **)malloc(sizeof(int*)*n);
    for(int i=0 ; i<n ; i++)
        board[i] = (int *)malloc(sizeof(int)*m);
    for(int i=0 ; i<n ; i++)
        for(int j=0 ; j<m ; j++){
            cin >> board[i][j];
        }
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(board[i][j]==1 && vis[i][j]==0){
                vis[i][j]=1; num++;
                Q.push({i, j});
                int j=0;
                while(!Q.empty()){          
                    pair<int, int> cur = Q.front(); Q.pop(); j++;
                    for(int dir=0 ; dir<4 ; dir++){
                        int nx = cur.X+dx[dir];
                        int ny = cur.Y+dy[dir];
                        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                        if(vis[nx][ny] || board[nx][ny] !=1) continue;
                        vis[nx][ny]=1;
                        Q.push({nx, ny});
                    }
                }
                if(max_w<j) max_w=j;
            }
        }
    }
    cout << num << '\n' << max_w;
    return 0;
}
