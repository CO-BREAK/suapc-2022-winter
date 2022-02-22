/*
[하노이탑 문제]
n개의 원판을 기둥 1에서 기둥 3으로 옮기기 위해서는,
n-1개의 원판을 우선 기둥 1에서 기둥 2로 옮겼다가,
n번째 원판을 기둥 1에서 기둥 3으로 옮기고,
n-1개의 원판을 기둥 2에서 기둥 3으로 옮긴다. 
->이것을 재귀함수를 이용해서 구현. 
*/
#include <bits/stdc++.h>
using namespace std;
int n;
void hanoi(int a, int b, int n){
    if(n==1){
        cout << a << ' ' << b << '\n';         
        return;
    }
    hanoi(a, 6-a-b, n-1);
    cout << a << ' ' << b << '\n';
    hanoi(6-a-b, b, n-1);
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cout << (1<<n)-1 << '\n';
    hanoi(1, 3, n);
    return 0;
}
