/* X보다 작은 수 */

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, a[10005], r[1000], ridx = 0;

    cin >> n >> x; // n과 x 입력받기

    for (int i = 0; i < n; i++) // 수열의 길이만큼 반복
    {
        cin >> a[i];          // 수열의 원소 입력받기
        if (a[i] < x)         // 원소가 정수 x보다 작을 경우
            r[ridx++] = a[i]; // 배열 r에 해당 원소 값 저장 + 배열 r을 인덱스 1 증가
    }

    for (int i = 0; i < ridx; i++) // 배열 r의 원소 출력
        cout << r[i] << ' ';

    return 0;
}