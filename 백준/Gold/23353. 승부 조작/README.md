# [Gold III] 승부 조작 - 23353 

[문제 링크](https://www.acmicpc.net/problem/23353) 

### 성능 요약

메모리: 21712 KB, 시간: 196 ms

### 분류

다이나믹 프로그래밍

### 문제 설명

<p>고양이 랑이와 메리는 오목 게임의 변형인 냥목 게임을 하고 있다. 냥목 게임의 규칙은 복잡하니 점수 계산 방법만 보자.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8812c64a-b9d4-418b-9e9b-0fa1c6e15c69/-/preview/" style="width: 331px; height: 300px;"></p>

<p>냥목 게임은 위 그림과 같은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-cD7"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="3"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>×</mo><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N \times N$</span></mjx-container> 크기의 바둑판에서 흑돌과 백돌을 이용해 진행된다.</p>

<p>랑이는 흑돌을, 메리는 백돌을 사용한다.</p>

<p>냥목 게임에서 랑이의 점수는 가로, 세로, 대각선 중 하나의 방향으로 연속하여 존재하는 가장 긴 흑돌의 길이가 된다.</p>

<p>잠시 집사가 돌아와서 메리가 반기러 간 사이 랑이는 메리의 돌 하나를 자신의 돌로 바꿔치기 하려고 한다. 즉, 랑이는 백돌 하나를 흑돌로 바꿀 수 있다.</p>

<p>랑이가 백돌 하나를 흑돌로 바꿀 때 얻을 수 있는 최대 점수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 자연수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="2"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>2</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>1</mn><mo>,</mo><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2 \le N \le 1,000$</span></mjx-container>)</p>

<p>둘째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개 줄에는 줄마다 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 숫자가 공백으로 구분되어 주어진다. 이는 랑이가 돌을 바꿔치기하기 전 바둑판의 상태를 나타낸다. 각 수는 0, 1, 2 중 하나로 주어지고, 0은 비어 있는 위치를, 1은 흑돌을, 2는 백돌을 의미한다.</p>

<p>흑돌과 백돌은 각각 하나 이상 존재한다.</p>

### 출력 

 <p>랑이가 얻을 수 있는 최대 점수를 출력한다.</p>

