/* 수 정렬하기 5 */

#include <bits/stdc++.h>
using namespace std;

int freq[2000001]; // 절댓값까지 고려했을 때

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin >> n; // 수열 a의 길이 n 입력받기

    for (int i = 0; i < n; i++)
    {                        // 수열의 길이 n만큼 반복
        cin >> a;            // 수열 a에 들어가는 값 입력받기
        freq[a + 1000000]++; // freq[1000000]가 0일 경우 증가시키는 데이터일 때를 기준으로 양수, 음수...
    }

    for (int i = 0; i <= 2000000; i++)
    {
        while (freq[i]--)
        {
            cout << i - 1000000 << '\n';
        }
    }
}