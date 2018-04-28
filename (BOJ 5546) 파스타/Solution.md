# 5546번 : 파스타
* [문제](https://www.acmicpc.net/problem/5546)
* [예시 코드](https://github.com/njw1204/LA-solutions/blob/master/(BOJ%205546)%20파스타/5546.cpp)  
&nbsp;

O(N) DP로 풀 수 있습니다.  
dp 배열을 선언해봅시다.  

```
dp[i][j][k] :
i = i번째 날이 마지막 날이고
j = 마지막 날에 j번 파스타를
k = k연속 먹은 경우의 수
```
&nbsp;

DP 배열을 아래와 같이 채워주면 됩니다.  
미리 정해진 날은 고정된 파스타의 번호에 대해서만 dp를 채워주세요.  
자세한 것은 예시 코드를 참고해주세요.  
&nbsp;

<img align="left" src="https://latex.codecogs.com/gif.latex?%5C%5Cdp%5Bi%5D%5Bj%5D%5B1%5D%20%3D%20%5Csum_%7Bk%3D1%7D%5E%7B3%7D%28dp%5Bi-1%5D%5Bk%5D%5B1%5D&plus;dp%5Bi-1%5D%5Bk%5D%5B2%5D%2C%20k%5Cneq%20j%29%20%5C%5C%5C%5Cdp%5Bi%5D%5Bj%5D%5B2%5D%20%3D%20dp%5Bi-1%5D%5Bj%5D%5B1%5D">
