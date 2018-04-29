# 15573번 : 채굴
* [문제](https://www.acmicpc.net/problem/15573)<br>
* [예시 코드](https://github.com/njw1204/LA-solutions/blob/make-solutions/(BOJ%2015573)%20%EC%B1%84%EA%B5%B4/15573.cpp)<br>

<br>

Binary Search + BFS를 이용해 O(NMlogS<sub>max</sub>)에 해결할 수 있습니다. 채굴기의 성능 D를 이진 탐색으로 바꿔가며 각각의 D에 대해 채굴 가능한 광물의 수를 BFS로 구하면 됩니다. K개 이상 채굴할 수 있으면 채굴기의 성능을 낮추고, 채굴할 수 없으면 성능을 높인 뒤 다시 BFS를 하는 과정을 답이 나올 때까지 하면 끝.

<br>

참고로 문제에는 없는 설명인데.. 광물은 중력의 영향을 받지 않습니다. 이걸 모르면 헷갈릴 수도 있어서 남깁니다.