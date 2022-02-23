/*
[����]
�ڿ��� A�� B�� ���� ���� �˰� �ʹ�. 
�� ���Ϸ��� ���� �ſ� Ŀ�� �� �����Ƿ� �̸� C�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

A, B, C ��� 20���� �Ѵ� ���̱� ������ �ϴ� �ڷ������� long long ���.
O(n)���ε� Ŀ���� �� ���� ���ڿ���, ���� ũ�Ⱑ 2�� log�� ����. 
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
