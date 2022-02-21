# 0x0F : 정렬 II

## Counting Sort

- 카운팅 소트 : 각 수의 등장 횟수를 저장해야 함
    - 등장 횟수를 쓰는 방법 (0x03강 참고)
        - 미리 큰 테이블을 만들어두고 수에 대응되는 원소의 값을 1 증가시켜서 처리하는 방법 : **freq[#]**
        - 단점 : 수의 범위가 너무 크면 메모리 제한에 취약
- 수의 범위가 한정적일 때에만 사용 가능
    - 대략적으로 수의 범위가 **1000만 이하면 사용 가능**

<details>
<summary>BOJ 11652 : 카드</summary>

```cpp
/* Counting Sort : BOJ 15688 수 정렬하기 5 */

#include <bits/stdc++.h>
using namespace std;

int freq[2000001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        freq[a + 1000000]++;
    }

    for (int i = 0; i <= 2000000; i++)
    {
        while (freq[i]--)
        {
            cout << i - 1000000 << '\n';
        }
    }
}

// 시간 복잡도 : O(N+K)
// K = 수의 범위
```

</details>

## Radix Sort

- =기수 정렬
- 자릿수를 이용해서 정렬하는, Counting Sort 응용 버전
- 동작 방식
    1. 0~9, 총 10개의 리스트 생성
    2. 1의 자릿수들만 보고 리스트에 넣기
    ex) 421, 021는 모두 1로. 105, 445는 모두 5로
    3. 10의 자릿수들만 보고 2번에서 정렬된 순서로 리스트에 넣기
    ex) 0 리스트에는 100, 502, 103, 007 순서로
    4. 100의 자릿수들만 보고 3번에서 정렬된 순서......처럼 계속 반복
    
   ![RadixSort1](https://user-images.githubusercontent.com/68195241/155112845-fc401bc0-0ee1-4175-b364-3a83e54a7e62.png)
    
- Radix Sort는 사용하지 않는 배열에 대한 공간도 할당해둬야 해서 공간 낭비가 심함 → 동적 배열이나 연결 리스트 필요 → 구현을 위해 STL 사용 필요 → STL Sort를 사용하지, 굳이 Radix를...? → **코딩 테스트에 거의 사용하지 않음**
    

    

### Comparison vs. Non-comparison Sort

- Comparison Sort : 원소들끼리 크기를 비교
- Non-comparison Sort : 원소들끼리 크기를 비교 ❌

![Comp Ncomp](https://user-images.githubusercontent.com/68195241/155112850-7e5e1ea9-1702-4f65-bde3-9b51793d07d0.png)


## STL sort

```cpp
int a[5] = {1, 4, 3, 2, 5};
sort(a, a+5);

vector<int> b = {1, 4, 3, 2, 5};
sort(b.begin(), b.end());
// or 'sort(b.begin(), b.begin()+5);

// 시간 복잡도 : (최대) O(NlgN)
```

- Quick Sort를 기반으로 함
- 리스트가 불균등하게 쪼개지는 상황이 계속 반복 → 재귀의 깊이가 너무 깊어짐 → 시간 복잡도 O(NlgN)이 보장되는 정렬 알고리즘으로 나머지 처리 → **최악의 경우에도 O(NlgN)이 보장!**
- 단, Stable Sort가 아님
    - 동일한 우선순위를 가진 원소들 사의의 상대적인 순서 보존 어려움
    - Stable Sort 필요 → **stable_sort 사용**
- STL Sort의 장점
    - 비교 함수를 정해서 넘겨줄 수 있음
        - ex) int형을 5로 나눈 나머지 순으로, 나머지가 같다면 크기 순으로
            
            ```cpp
            bool cmp(int a, int b){
            	if(a%5 != b%5)
            		return a%5 < b%5;
            }
            
            int a[7] = {1,2,3,4,5,6,7};
            sort(a, a+7, cmp);
            ```
            
        - 비교 함수 사용 시 주의사항
            1. 비교 함수는 두 값이 같을 때(혹은 우선순위가 같을 때) false를 반환
                
                ⚠ 런타임 에러!
                
            2. 비교 함수의 인자로 STL 혹은 클래스 객체를 전달시 reference를 사용
                
                ⚠ 함수의 인자로 STL이나 구조체 객체를 실어서 보내면 값의 복사가 일어남
                
                ✅ string a → **const string& a**
                

## 정렬의 응용

<details>
<summary>BOJ 11652 : 카드</summary>

```cpp
/* BOJ 11652 카드 */

#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);

    int cnt = 0;
    long long mxval = -(1ll << 62) - 1;
    int mxcnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0 || a[i - 1] == a[i])
            cnt++;
        else
        {
            if (cnt > mxcnt)
            {
                mxcnt = cnt;
                mxval = a[i - 1];
            }
            cnt = 1;
        }
    }

    if (cnt > mxcnt)
        mxval = a[n - 1]; // 제일 마지막 수가 몇 번 등장했는지를 별도로 확인해야함
    cout << mxval;
    
}

// 시간 복잡도 : O(NlgN)
```
</details>