/*
오차범위 맞추는 게 중요함. 10^-6이 오차범위. 
이 코드는 소수점 16자리까지 출력하게 함. 
*/
#include <bits/stdc++.h>
using namespace std;
int N;
double ans;
double a[100002];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cout << fixed;	//소수점 자릿수를 고정한다. 
    cout.precision(16);	//소수점 16자리로 출력 
    for (int i = 0; i < N; i++) {
		cin >> a[i];
		ans += a[i];
		if (i)
			ans += a[i - 1] * (1 - a[i]) + a[i] * (1 - a[i - 1]);
	}
    cout << ans << '\n';
    return 0;
}
