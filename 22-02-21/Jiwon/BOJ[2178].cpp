#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
string board[102];	//배열이 띄어쓰기 없이 주어지므로 string으로 받는다. 
int dist[102][102];	//최단거리를 구하는 문제이므로 거리를 기록할 배 열 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;    //행렬 입력받음
    for(int i=0 ; i<n ; i++)
        cin >> board[i];
    for(int i=0 ; i<n ; i++) fill(dist[i], dist[i]+(m), -1);	//거리 배열을 -1로 초기화. 이를 통해 vis배열 역할도 할 수 있음. 0보다 크거나 같으면 visit. 또 fill 함수는 두번째 인자 포함x 
    queue<pair<int,int>> Q;
    Q.push({0,0});	//(1,1)에서 출발한다고 했기 때문에 
    dist[0][0]=0; //시작점이니까 거리는 0으로 설정 
    while(dist[n-1][m-1]==-1){	//(n,m)의 거리가 나오면 종료 
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir=0 ; dir<4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist[nx][ny]>=0 || board[nx][ny]!='1') continue;	//방몬한 칸은 거리가 0이상, 미로는 1을 따라서만 갈 수 있음. 
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }         
    }
    cout << dist[n-1][m-1]+1;
    return 0;
}
