#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
string board[102];	//�迭�� ���� ���� �־����Ƿ� string���� �޴´�. 
int dist[102][102];	//�ִܰŸ��� ���ϴ� �����̹Ƿ� �Ÿ��� ����� �� �� 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;    //��� �Է¹���
    for(int i=0 ; i<n ; i++)
        cin >> board[i];
    for(int i=0 ; i<n ; i++) fill(dist[i], dist[i]+(m), -1);	//�Ÿ� �迭�� -1�� �ʱ�ȭ. �̸� ���� vis�迭 ���ҵ� �� �� ����. 0���� ũ�ų� ������ visit. �� fill �Լ��� �ι�° ���� ����x 
    queue<pair<int,int>> Q;
    Q.push({0,0});	//(1,1)���� ����Ѵٰ� �߱� ������ 
    dist[0][0]=0; //�������̴ϱ� �Ÿ��� 0���� ���� 
    while(dist[n-1][m-1]==-1){	//(n,m)�� �Ÿ��� ������ ���� 
        pair<int,int> cur = Q.front(); Q.pop();
        for(int dir=0 ; dir<4 ; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist[nx][ny]>=0 || board[nx][ny]!='1') continue;	//����� ĭ�� �Ÿ��� 0�̻�, �̷δ� 1�� ���󼭸� �� �� ����. 
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            Q.push({nx,ny});
        }         
    }
    cout << dist[n-1][m-1]+1;
    return 0;
}
