/* 기본 틀 */

#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n; // 수열 a의 길이 n 입력받기

  for (int i = 0; i < n; i++)
  {                // 수열의 길이 n만큼 반복
    cin >> arr[i]; // 수열 arr에 들어가는 값 입력받기
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - 1 - i; j++)
    { // n-1-i이 아니라 n-1로 둬도 같은 결과를 출력하기는 함
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }

  for (int i = 0; i < n; i++)
    cout << arr[i] << '\n';

  return 0;
}