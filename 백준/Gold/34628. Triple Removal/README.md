# [Gold II] Triple Removal - 34628 

[문제 링크](https://www.acmicpc.net/problem/34628) 

### 성능 요약

메모리: 10124 KB, 시간: 96 ms

### 분류

애드 혹, 누적 합

### 제출 일자

2025년 10월 20일 00:51:16

### 문제 설명

<p>Tired of supporting ranged carries, Keria is now creating a data structure problem about supporting range queries.</p>

<p>For an array $b = [b_1, b_2, \ldots, b_m]$ of length $m$ where $b_i=0$ or $b_i=1$, consider the following <strong>triple removal</strong> operation:</p>

<ol>
<li>Choose three indices $1 \le i < j < k \le m$ such that the elements at these positions are identical ($b_i = b_j = b_k$).</li>
<li>Remove these three elements from the array. The cost of this operation is defined as $\min(k-j, j-i)$. After the removal, the remaining parts of the array are concatenated, and their indices are relabeled.</li>
</ol>

<p>We want to make the array $b$ empty using the <strong>triple removal</strong> operation. Hence, we define the <em>total cost</em> of an array as the minimum possible sum of the costs of <strong>triple removal</strong> operations required to make the array empty. If it is impossible to make the array empty, the cost is defined to be $-1$.</p>

<p>Keria wants to test his data structure. For this, you must answer $q$ independent queries. Initially, you are given an array $a = [a_1, a_2, \ldots, a_n]$ of length $n$ where $a_i=0$ or $a_i=1$. For each query, you are given a range $1 \le l \le r \le n$ and must find the cost for the array $[a_l, a_{l+1}, \ldots, a_r]$.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.</p>

<p>The first line of each test case contains two integers $n$ and $q$ ($1 \le n, q \le 250\,000$) --- the length of the array and the number of queries.</p>

<p>The next line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($a_i = 0$ or $a_i=1$) --- the elements of the array.</p>

<p>Then $q$ lines follow. The $i$-th of them contains two integers $l_i$ and $r_i$ ($1 \le l_i \le r_i \le n$) --- the range of the subarray for the $i$-th query.</p>

<p>It is guaranteed that the sum of $n$ over all test cases does not exceed $250\,000$.</p>

<p>It is guaranteed that the sum of $q$ over all test cases does not exceed $250\,000$.</p>

### 출력 

 <p>For each test case, output $q$ lines. The $i$-th line should contain a single integer representing the answer to the $i$-th query.</p>

