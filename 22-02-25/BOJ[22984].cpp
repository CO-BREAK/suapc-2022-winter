/*
�������� ���ߴ� �� �߿���. 10^-6�� ��������. 
�� �ڵ�� �Ҽ��� 16�ڸ����� ����ϰ� ��. 
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
    cout << fixed;	//�Ҽ��� �ڸ����� �����Ѵ�. 
    cout.precision(16);	//�Ҽ��� 16�ڸ��� ��� 
    for (int i = 0; i < N; i++) {
		cin >> a[i];
		ans += a[i];
		if (i)
			ans += a[i - 1] * (1 - a[i]) + a[i] * (1 - a[i - 1]);
	}
    cout << ans << '\n';
    return 0;
}
