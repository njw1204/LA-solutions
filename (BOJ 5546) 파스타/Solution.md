# 5546번 : 파스타
* [문제](https://www.acmicpc.net/problem/5546)
* [예시 코드]()
<br>

DP로 풀 수 있습니다.  
파스타의 종류와 연속으로 몇 번 먹는지를 고려해야 하므로 다음과 같이 하면 됩니다.
```
dp[i][j][k] :
i = i번째 날이 마지막 날이고
j = 마지막 날에 j번 파스타를
k = k연속 먹은 경우의 수
```
<br>
미리 정해진 파스타도 배열에 저장해둡니다.
```
fix[i] : i번째 날에 먹는 고정된 파스타의 번호
```
<br>
DP 배열을 아래와 같이 채워주면 됩니다.  
미리 정해진 날은 고정된 파스타의 번호에 대해서만 dp를 채우고,  
다른 파스타들은 먹을 수 없으니 0으로 채워주세요.  
<br>
<img align="left" src="https://latex.codecogs.com/gif.latex?%5C%5Cdp%5Bi%5D%5Bj%5D%5B1%5D%20%3D%20%5Csum_%7Bk%3D1%7D%5E%7B3%7D%28dp%5Bi-1%5D%5Bk%5D%5B1%5D&plus;dp%5Bi-1%5D%5Bk%5D%5B2%5D%2C%20k%5Cneq%20j%29%20%5C%5C%5C%5Cdp%5Bi%5D%5Bj%5D%5B2%5D%20%3D%20dp%5Bi-1%5D%5Bj%5D%5B1%5D">