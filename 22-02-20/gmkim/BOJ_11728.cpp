/* 배열 합치기 */

#include <bits/stdc++.h>
using namespace std;

int n, m, x[1000005], y[1000005], z[1000005]; // 런타임 에러를 방지하려면 전역으로 (자동 0으로 초기화)

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int xidx = 0, yidx = 0;

    cin >> n >> m; // N,M 배열 길이 입력받기

    for (int i = 0; i < n; i++) // 배열 x 입력받기
    {
        cin >> x[i];
    }

    for (int i = 0; i < m; i++) // 배열 y 입력받기
    {
        cin >> y[i];
    }

    for (int i = 0; i < n + m; i++)
    {
        if (xidx == n) // 배열 x에서 인덱스를 모두 비교했을 경우(남는 원소가 없을 때)
        {
            z[i] = y[yidx++];
        }
        else if (yidx == m) // 배열 y에서 인덱스를 모두 비교했을 경우(남는 원소가 없을 때)
        {
            z[i] = x[xidx++];
        }
        else if (x[xidx] <= y[yidx]) // 배열 x의 비교 원소가 배열 y의 것보다 작거나 같을 때
        {
            z[i] = x[xidx++];
        }
        else // 배열 y의 비교 원소가 배열 x의 것보다 작거나 같을 때
        {
            z[i] = y[yidx++];
        }
    }

    for (int i = 0; i < n + m; i++) // 최종 정렬된 배열 z 출력
    {
        cout << z[i] << ' ';
    }

    return 0;
}