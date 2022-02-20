/* 수 정렬하기 4 */

#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int tmp[1000001];

void merge(int st, int en) // arr[st:en]을 정렬하는 함수 : arr[st], arr[st+1], ... arr[en-1]
{
  int mid = (st + en) / 2;

  int xidx = st;
  int yidx = mid;

  for (int i = st; i < en; i++)
  {
    if (xidx == mid)
    {
      tmp[i] = arr[yidx++];
    }
    else if (yidx == en)
    {
      tmp[i] = arr[xidx++];
    }
    else if (arr[xidx] <= arr[yidx])
    {
      tmp[i] = arr[xidx++];
    }
    else
    {
      tmp[i] = arr[yidx++];
    }
  }
  for (int i = st; i < en; i++)
    arr[i] = tmp[i];
}

void merge_sort(int st, int en)
{
  if (en - st == 1)
  {
    return;
  }
  int mid = (st + en) / 2;
  merge_sort(st, mid);
  merge_sort(mid, en);
  merge(st, en);
}

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

  merge_sort(0, n);
  for (int i = n - 1; i >= 0; i--)
    cout << arr[i] << '\n';

  return 0;
}