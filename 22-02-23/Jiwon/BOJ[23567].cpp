#include <bits/stdc++.h>
using namespace std;
int n, k;
int board[10002];
bool check[10002];
int idx;
int number;
int min_num=10002;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0 ; i<n ; i++){
        cin >> board[i];
    }
    for(int i=0 ; i<n ; i++){
    	fill(check, check+n, 0);
        idx=0; number=0;
        while(idx!=k && number<=n){
            int j;
            for(j=i ; j<n ; j++){
                if(check[board[j]]==1){
                    number++;
                    continue;
                }
                if(check[board[j]]==0){
                    check[board[j]]=1;    
                    number++;
                    idx++;
                }
            }
            
        }
        
        min_num=min(min_num, number);
        
    }
    if(min_num==n) cout << 0;
    else cout << min_num;
    return 0;
}

