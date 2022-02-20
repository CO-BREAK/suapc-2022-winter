# 0x0E : 정렬 I



## 기초 정렬

### 1) 선택정렬

- 전체 배열에서 가장 큰 원소를 선택해서 맨 오른쪽으로 옮기기 (오름차)
- 가장 작은 원소를 왼쪽으로 옮기는 것도 가능 (오름차)

```cpp
/* 선택 정렬 - 오름차순 */

int arr[10] = {3, 2, 7, 116, 62, 235, 1, 23, 55, 77};
int n = 10;

for(int i = n-1; i > 0; i--){
	swap(*max_element(arr, arr+i+1), arr[i]);
}

// 시간복잡도 : O(N^2)
```

```cpp
/*전체 배열에서 가장 큰 원소가 들어있는 인덱스 구하기*/
*max_element(arr, arr+n)-arr
```

### 2) 버블정렬

- 앞에서부터 인접한 두 원소를 보면서 앞의 원소가 뒤의 원소보다 클 경우 자리를 바꾸는 것을 반복 → 제일 큰 것부터 오른쪽에 쌓이게 됨

```cpp
/* 버블 정렬 - 오름차순 */
int arr[5] = {-2, 2, 4, 6 ,13};
int n = 5;

for(int i=0; i < n; i++){
	for(int j=0; j < n-1-i; j++){  //n-1-i이 아니라 n-1로 둬도 같은 결과를 출력하기는 함
		if(arr[j] > arr[j+1])
			swap(arr[j], arr[j+1]);
	}
}

// 시간복잡도 : O(N^2)
```

- 선택 정렬과 버블 정렬의 문제는 시간 복잡도가 O(N^2)이라 N이 커지면 효율적이지 못함 → 그래서 다른 알고리즘-Merge, Quick Sort 등등-을 사용하기도 하는 것
    - N이 10만st일 경우 연산 시간:
        
        → O(N^2) = 10초~1분 정도 소요
        
        → O(NlgN) = 설명하자면 눈 깜짝할 사이....? (매우 빠름)
        

# Merge Sort

- 재귀적으로 수열을 나눠 정렬한 후 합치는 방법
    1. 주어진 리스트를 2개로 나눈다
    2. 나눈 리스트 2개를 정렬
    3. 정렬된 두 리스트를 합친다
- 길이가 N,M인 두 정렬된 리스트를 합쳐서 길이 N+M의 정렬된 리스트를 만드는 방법

![MergeSort](https://user-images.githubusercontent.com/68195241/155100603-2b02279c-34ed-4291-a311-c0b5dd79f3b0.png)

```cpp
/* Merge Sort */

#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = {...};   // 여기에 정렬할 배열 입력?
int tmp[1000001];

void merge(int st, int en) // arr[st:en]을 정렬하는 함수 : arr[st], arr[st+1], ... arr[en-1]
{
    int mid = (st + en) / 2;
    int lidx = st;
    int ridx = mid;

    for (int i = st; i < en; i++)
    {
        if (ridx == en)
        {
            tmp[i] = arr[lidx++];
        }
        else if (lidx == mid)
        {
            tmp[i] = arr[ridx++];
        }
        else if (arr[lidx] <= arr[ridx])
        {
            tmp[i] = arr[lidx++];
        }
        else
        {
            tmp[i] = arr[ridx++];
        }
    }
    for (int i = st; i < en; i++)
        arr[i] = tmp[i];
}

void merge_sort(int st, int en)
{
    if (en == st + 1)
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
    merge_sort(0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}

// 시간복잡도 : O(NlgN)
```

## Stable Sort

- 우선 순위가 같은 원소들 사이에서는 정렬 이전 순서를 따라가도록 하는 것
    - 우선 순위가 같은 원소란?
        - [2, 3, 3, 3, 4] 이런 상황에서의 3

# Quick Sort

- 일반적으로는 퀵 소트가 거의 모든 정렬 알고리즘보다 빠름 → 많은 라이브러리들의 정렬은 퀵 소트로 만들어져있음
- 단, **코딩 테스트에서 STL를 사용하지 못하는 경우라면 Merge Sort를 쓰는 것이 효율적. 퀵 소트를 쓰지 않는 것이 좋다**
- 퀵소트란?
    - 재귀적으로 구현됨
    - 매 단계마다 pivot이라고 이름 붙은 원소 하나를 제자리로 보내는 과정을 반복
    - 장점 : 추가적인 공간(추가적인 공간을 사용하는 것이 필요하지 않다 (In-Place Sort)
    - 단점 : 최악의 경우 시간복잡도가 O(N^2)이 될 수 있음 (STL을 사용하지 못하는 경우 등등)

![QuickSort](https://user-images.githubusercontent.com/68195241/155100703-6270f2ff-bac9-400d-b0da-8a4e62b4e602.png)

```cpp
#include <bits/stdc++.h>
using namespace std;

int n = 10;
int arr[1000001] = {...};

void quick_sort(int st, int en)
{
    if (en <= st + 1)
        return;

    int pivot = arr[st];
    int l = st + 1;
    int r = en - 1;

    while (1)
    {
        while (1 <= r && arr[l] <= pivot)
            l++;
        while (1 <= r && arr[r] > pivot)
            r--;
        if (l > r)
            break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(r + 1, en);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    quick_sort(0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
}

// 시간복잡도 : O(NlgN)
```

## Merge Sort와 Quick Sort 비교

![M G](https://user-images.githubusercontent.com/68195241/155100799-b86187c5-a255-43b6-a3ab-3f893d94d79c.png)