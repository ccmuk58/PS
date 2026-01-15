# [Gold II] i18n - 35115 

[문제 링크](https://www.acmicpc.net/problem/35115) 

### 성능 요약

메모리: 10836 KB, 시간: 52 ms

### 분류

다이나믹 프로그래밍, 문자열

### 제출 일자

2026년 1월 15일 16:49:41

### 문제 설명

<p>영어 소문자와 숫자로 구성된 문자열 $S$와 $T$가 주어진다.</p>

<p>$S$에 아래 연산을 단 한 번만 사용해서 약어를 만들 수 있다.</p>

<ul>
<li>서로 겹치지 않는 비어 있지 않은 부분문자열을 $0$개 이상 고른다.</li>
<li>선택한 부분문자열을 각각 그 길이에 해당하는 십진수 문자열로 바꾼다.</li>
<li>이때 십진수 문자열은 <span style="color:#e74c3c;"><code>0</code></span>으로 시작할 수 없다.</li>
</ul>

<p>예를 들어, <span style="color:#e74c3c;"><code>internationalization</code></span>의 약어로 <code><span style="color:#e74c3c;">i18n</span></code>와 <span style="color:#e74c3c;"><code>119</code></span>를 만들 수 있지만 <code><span style="color:#e74c3c;">i3</span></code>나 <span style="color:#e74c3c;"><code>0119</code></span>는 만들 수 없다.</p>

<p>$S$에 주어진 연산을 사용해 만든 약어로 $T$가 가능한지 판별해 보자.</p>

### 입력 

 <p>첫 번째 줄에 문자열 $S$가 주어진다. $(1 \le |S| \le 2\,000)$</p>

<p>두 번째 줄에 문자열 $T$가 주어진다. $(1 \le |T| \le |S|)$</p>

<p>주어지는 모든 문자열은 알파벳 소문자와 숫자로만 구성된다.</p>

<p>$S$에 숫자가 포함될 수 있음에 유의하라.</p>

### 출력 

 <p>$S$의 약어로 $T$가 가능하면 <span style="color:#e74c3c;"><code>Yes</code></span>, 아니라면 <span style="color:#e74c3c;"><code>No</code></span>를 출력한다.</p>

