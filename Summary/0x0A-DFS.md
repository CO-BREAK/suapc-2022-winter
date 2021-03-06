## DFS(Depth First Search)

: 다차원 배열에서 각 칸을 방문할 때 `깊이`를 우선으로 방문하는 알고리즘

### 예시

1. 시작하는 칸을 `스택`에 넣고 방문했다는 표시를 남긴다.
2. 스택에서 원소를 꺼내어 그 칸과 상하좌우로 인접한 칸에 대해 3번을 진행한다
3. 해당 칸을 이전에 방문했다면 아무 것도 하지 않고, 처음으로 방문했다면 방문했다는 표시를 남기고 해당 칸을 스택에 삽입
4. 스택이 빌 때까지 2번을 반복한다.

→큐를 쓰면 BFS, 스택을 쓰면 DFS

- BFS에서 유용하게 썼던 “현재 보는 칸으로부터 추가되는 인접한 칸은 거리가 현재 보는 칸보다 1만큼 더 떨어져있다”는 성질이 DFS에서는 성립하지 않는다.

→다차원 배열에서 굳이 BFS 대신 DFS를 써야하는 일은 없다.
