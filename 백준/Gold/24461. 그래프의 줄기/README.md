# [Gold II] 그래프의 줄기 - 24461 

[문제 링크](https://www.acmicpc.net/problem/24461) 

### 성능 요약

메모리: 8840 KB, 시간: 40 ms

### 분류

방향 비순환 그래프, 그래프 이론, 위상 정렬

### 제출 일자

2025년 4월 16일 17:20:17

### 문제 설명

<p>그래프에서 사이클이란, 한 정점에서 같은 정점까지, 반복되는 간선이 없으며, 길이가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>0</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$0$</span></mjx-container>이 아닌 경로이다.</p>

<p>사이클이 존재하지 않는 그래프가 주어진다.</p>

<p>우리는 이 그래프의 정점 중에서 연결된 간선이 하나인 정점을 <strong>가장자리 정점</strong>이라고 정의하자.</p>

<p>이 그래프의 <strong>가장자리 정점</strong>을 동시에 없애는 행동을 반복하면서, 그래프가 일직선의 모양이 되면 남아있는 정점의 집합을 <strong>그래프의 줄기</strong>라고 정의하자. 단, 가장자리 정점의 개수가 둘 이하라면 그래프가 일직선 모양이라고 한다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/e7317f66-de4d-4b33-b988-d8fe1bb3c481/-/preview/" style="width: 640px; height: 360px;"></p>

<p>위 그림과 같은 그래프가 있다고 할 때, 아래와 같이 <strong>가장자리 정점과 연결된 간선</strong>을 빨간색으로 표시하면 아래와 같다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/52967942-c2ca-4fd3-b222-605b225cca29/-/preview/" style="width: 640px; height: 360px;"></p>

<p>빨간색 간선과 연결된 가장자리 정점의 연결을 끊으면 아래 그림과 같이 일직선 모양으로 연결된 <strong>그래프의 줄기</strong>가 남는다. 만약 그래프가 일직선 모양이 되었다면, <strong>가장자리 정점</strong>이 더 존재하더라도 더 이상 <strong>가장자리 정점</strong>들을 없애지 않는다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8ad11bd6-1fc6-40a5-b624-ac15f649c8e9/-/preview/" style="width: 640px; height: 360px;"></p>

<p>이때 <strong>그래프의 줄기</strong>를 이루는 정점을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>입력의 첫 번째 줄에는 처음 그래프의 정점의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>2</mn><mo>≤</mo><mi>N</mi><mo>≤</mo><mn>100</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(2 \le N \le 100\,000)$</span> </mjx-container></p>

<p>이후 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N-1$</span></mjx-container>줄에 걸쳐 각 간선으로 연결된 두 정점의 번호 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D44F TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>a</mi><mo>,</mo><mi>b</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$a, b$</span></mjx-container>가 입력된다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mtext class="mjx-n" space="2"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44F TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c3C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mtext class="mjx-n" space="2"><mjx-c class="mjx-cA0"></mjx-c></mjx-mtext><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D44E TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2260"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D44F TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>0</mn><mo>≤</mo><mi>a</mi><mo>,</mo><mtext> </mtext><mi>b</mi><mo><</mo><mi>N</mi><mo>,</mo><mtext> </mtext><mi>a</mi><mo>≠</mo><mi>b</mi><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(0 \le a,\ b < N,\ a \ne b)$</span> </mjx-container></p>

### 출력 

 <p>출력의 첫 번째 줄에 <strong>그래프의 줄기</strong>를 이루는 정점의 번호들을 오름차순으로 정렬하고 공백으로 구분하여 출력한다.</p>

