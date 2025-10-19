# [Gold IV] Catching the Krug - 34627 

[문제 링크](https://www.acmicpc.net/problem/34627) 

### 성능 요약

메모리: 2020 KB, 시간: 4 ms

### 분류

수학, 그리디 알고리즘, 게임 이론

### 제출 일자

2025년 10월 20일 00:51:00

### 문제 설명

<p>Doran and the Krug are playing a game on a grid consisting of $(n + 1) \times (n + 1)$ cells whose coordinates are pairs of integers from $0$ to $n$, inclusive. The Krug's goal is not to be <em>caught</em> by Doran for as long as possible, while Doran's goal is to <em>catch</em> the Krug as early as possible. We say Doran <em>caught</em> the Krug if they stand on the same grid cell.</p>

<p>To play the game, the Krug and Doran take turns alternately, starting from the Krug:</p>

<ul>
<li>The Krug can either stay in the same cell or move to a cell vertically or horizontally (but <strong>not</strong> diagonally) adjacent. Formally, if the Krug is currently at the cell $(a, b)$, she can stay at $(a, b)$ or move to either $(a-1, b), (a, b-1), (a, b+1), (a+1, b)$.</li>
<li>Doran can either stay in the same cell or move to a cell vertically, horizontally, or diagonally adjacent. Formally, if Doran is currently at the cell $(c, d)$, he can stay at $(c, d)$ or move to either $(c-1, d-1), (c-1, d), (c-1, d+1), (c, d-1), (c, d+1), (c+1, d-1), (c+1, d), (c+1, d+1)$.</li>
<li>Both players cannot go outside of the grid.</li>
</ul>

<p style="text-align: center;"><img alt="" src="" style="width: 434px; height: 187px;"></p>

<p style="text-align: center;">Figures showing possible movements of the Krug and Doran. Letters 'K' and 'D' represent the current position of the Krug and Doran, and the colored cells represent possible positions each player can move to in their respective turn.</p>

<p>The Krug's <em>survival time</em> is defined as the number of Doran's turns until Doran <em>catches</em> the Krug for the given starting cells of the players. Assuming that both players play optimally, find the Krug's <em>survival time</em> or report that the Krug can survive for infinite turns.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.</p>

<p>Each test case consists of a single line containing five integers $n$, $r_K$, $c_K$, $r_D$, and $c_D$ ($1 \le n \le 10^9$, $0 \le r_K, c_K, r_D, c_D \le n$, $(r_K, c_K) \ne (r_D, c_D)$) --- $n$ is the size of the grid, $(r_K, c_K)$ represents the Krug's starting cell, and $(r_D, c_D)$ represents Doran's starting cell.</p>

### 출력 

 <p>For each test case, output the Krug's <em>survival time</em> when both players play optimally. If the Krug can survive for infinite turns, print $-1$.</p>

