# [Gold III] 서로소 그래프 게임 - 34035 

[문제 링크](https://www.acmicpc.net/problem/34035) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 게임 이론

### 제출 일자

2025년 9월 26일 17:32:21

### 문제 설명

<p>승민이와 찬영이는 서로소 그래프 게임을 하려고 한다. 이 게임은 간선이 없는 정점 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개로 시작하며, 두 사람은 번갈아 가며 다음과 같은 규칙으로 게임을 진행한다.</p>

<ul>
	<li>자신의 차례에는, 연결 요소에 속한 정점의 수가 서로소인 서로 다른 두 정점을 선택해 간선을 추가해야 한다.</li>
	<li>간선을 추가할 수 있는 정점 쌍이 없다면, 해당 차례의 플레이어는 패배한다.</li>
</ul>

<p>승민이가 먼저 시작하여 두 사람 모두 최선의 전략으로 게임을 진행할 때, 누가 승리하는지 판단하자.</p>

### 입력 

 <p>첫째 줄에 테스트 케이스의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>가 주어진다.</p>

<p>둘째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D447 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>T</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$T$</span></mjx-container>개의 줄에 걸쳐, 각 테스트 케이스에 대해 정점의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

### 출력 

 <p>각 테스트 케이스에 대해 승민이가 이긴다면 <span style="color:#e74c3c;"><code>kang</code></span>을, 찬영이가 이긴다면 <span style="color:#e74c3c;"><code>chan</code></span>을 한 줄에 하나씩 출력한다.</p>

