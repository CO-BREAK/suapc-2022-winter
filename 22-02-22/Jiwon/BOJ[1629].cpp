/*
[문제]
자연수 A를 B번 곱한 수를 알고 싶다. 
단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

A, B, C 모두 20억이 넘는 수이기 때문에 일단 자료형으로 long long 사용.
O(n)으로도 커버할 수 없는 숫자여서, 밑의 크기가 2인 log로 만듦. 
*/
#include <bits/stdc++.h>
using namespace std;
long long recur(long long a, long long b, long long c){
    if(b==1){
        return a%c;
    }
    if(b%2==0){
        return (recur(a, b/2, c)*recur(a, b/2, c))%c;
    }
    if(b%2==1){
        return (recur(a, b/2, c)*recur(a, b/2+1, c))%c;
    }    
}
int main(void){
    long long a, b, c;
    cin >> a >> b >> c;
    cout << recur(a, b, c);
    return 0;
}
