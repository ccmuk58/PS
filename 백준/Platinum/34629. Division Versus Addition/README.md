# [Platinum III] Division Versus Addition - 34629 

[문제 링크](https://www.acmicpc.net/problem/34629) 

### 성능 요약

메모리: 8080 KB, 시간: 168 ms

### 분류

애드 혹, 누적 합, 게임 이론

### 제출 일자

2025년 10월 20일 00:51:31

### 문제 설명

<p>For an array $b=[b_1,b_2,\ldots,b_m]$ of length $m$ ($b_i \geq 2$), consider the following two-player game played by Poby and Rekkles.</p>

<ul>
<li>The players take turns, with Poby moving first.</li>
<li>On Poby's turn, he must choose an element $x \ge 2$ and replace it with $\left\lfloor \frac{x}{2} \right\rfloor$. In other words, he picks $i$ ($1 \leq i \leq m$) such that $b_i \ge 2$, then does $b_i := \left\lfloor \frac{b_i}{2} \right\rfloor$.</li>
<li>On Rekkles' turn, he must choose an element $x \ge 2$ from the array $b$ and replace it with $x+1$. In other words, he picks $i$ ($1 \leq i \leq m$) such that $b_i \ge 2$, then does $b_i := b_i+1$.</li>
</ul>

<p>The game ends once all elements in the array $b$ are equal to $1$.</p>

<p>Define the <strong>score</strong> of the game as the number of moves that Poby makes. Poby's goal is to minimize the <strong>score</strong>, while Rekkles's goal is to maximize the <strong>score</strong>.</p>

<p>Then, the <strong>value</strong> of the array $b$ is the score of the game when both players play optimally.</p>

<p>You are given an integer array $a$ of length $n$ ($a_i \ge 2$).</p>

<p>Answer $q$ independent queries. In each query, you are given a range $1 \leq l \leq r \leq n$ and must find the <strong>value</strong> of the array $[a_l, a_{l+1}, \ldots, a_r]$.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.</p>

<p>The first line of each test case contains two integers $n$ and $q$ ($1 \le n, q \le 250\,000$) --- the length of the array and the number of queries.</p>

<p>The next line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($2 \le a_i \le 10^9$) --- the elements of the array $a$.</p>

<p>Then $q$ lines follow. The $j$-th of them contains two integers $l_j$ and $r_j$ ($1 \le l_j \le r_j \le n$) --- the range of the subarray for the $i$-th query.</p>

<p>It is guaranteed that the sum of $n$ over all test cases does not exceed $250\,000$.</p>

<p>It is guaranteed that the sum of $q$ over all test cases does not exceed $250\,000$.</p>

### 출력 

 <p>For each test case, output $q$ lines. The $i$-th line should contain a single integer representing the answer to the $i$-th query.</p>

