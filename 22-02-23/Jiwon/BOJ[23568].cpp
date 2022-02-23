#include <bits/stdc++.h>
using namespace std;
int n, Y;
tuple<int,char,int> loc[10002];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int first, second;
    char l;
    for(int i=0 ; i<n ; i++){
        cin >> first >> l >> second;
        loc[i] = make_tuple(first, l, second);
    }
        
    cin >> Y;
    int k = n;
    while(k--){
        for(int i=0 ; i<n ; i++){
            if(get<0>(loc[i])!=Y) continue;
            if(get<1>(loc[i])=='R')
                Y = Y + get<2>(loc[i]);
            if(get<1>(loc[i])=='L')
                Y = Y - get<2>(loc[i]);
        }
    }
    cout << Y;
    return 0;
}
