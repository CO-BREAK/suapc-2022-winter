/* 수 정렬하기 3 */

#include <bits/stdc++.h>
using namespace std;

int arr[10001];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, a;
  cin >> n; // 수열 a의 길이 n 입력받기

  for (int i = 0; i < n; i++) //  메모리 초과 때문에 Count Sort 사용 : 입력받은 모든 수를 저장하면 안됨
  {                           // 수열의 길이 n만큼 반복
    cin >> a;
    arr[a]++; // 입력된 숫자에 따라 배열의 원소 중 한 개 숫자 증가
  }

  for (int i = 1; i <= 10000; i++)
    while (arr[i]--) // 원소가 0이 아닌 경우, 입력을 받은 것이나 같기 때문에 숫자 출력, 자연수이니 1부터
    {
      cout << i << '\n';
    }

  return 0;
}