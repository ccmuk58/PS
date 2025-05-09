# [Bronze II] 경로당펑크 2077 - 25205 

[문제 링크](https://www.acmicpc.net/problem/25205) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현, 문자열

### 제출 일자

2025년 5월 10일 01:33:52

### 문제 설명

<p>시은이는 종합설계 프로젝트로 오픈월드 액션 고스톱 게임 <em>경로당펑크 2077</em>을 개발하고 있다. 대사를 추가하던 중, 사용자 이름에 따라 '을' 또는 '를' 중 하나를 출력해야 함을 깨달았다. 예를 들어 이름이 도현이라면 도현'을' 이라고 출력해야 하고, 인하라면 인하'를' 이라고 출력해야 한다. 그 기준은 이름 마지막 글자의 받침 존재 여부이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d255f32e-1f5e-4417-922a-2425e68151ae/-/preview/"></p>

<p>사용자는 반드시 한글 음절로만 구성된 이름을 사용한다. 이름의 모든 음절은 위 표의 초성, 중성, 종성을 순서대로 하나씩만 골라 조합하여 만들 수 있다. 예를 들어 음절 <code>인</code>(초성 ㅇ, 중성 ㅣ, 종성 ㄴ), <code>하</code>(초성 ㅎ, 중성 ㅏ, 종성 없음)는 사용자 이름에 등장할 수 있다. 반대로 <code>짜</code>, <code>계</code>, <code>와</code>, <code>삵</code>은 모두 위 표에 없는 낱자가 포함되어 사용자 이름에 등장하지 않는다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/b091e984-89f4-4c99-af3e-a251bea7545c/-/preview/"></p>

<p>위 그림과 같은 표준 두벌식 자판에서 사용자 이름을 영문 모드 소문자로 타이핑하여 얻는 문자열을 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D460 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>s</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$s$</span></mjx-container>라고 하자. 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D460 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>s</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$s$</span></mjx-container>가 주어지면 원래 사용자 이름 마지막 글자에 받침이 존재하는지 판별하는 프로그램을 작성하라.</p>

### 입력 

 <p>첫 번째 줄에 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D460 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>s</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$s$</span></mjx-container>의 길이를 나타내는 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

<p>두 번째 줄에 문자열 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D460 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>s</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$s$</span></mjx-container>가 주어진다.</p>

### 출력 

 <p>사용자 이름 마지막 글자에 받침이 있다면 1, 없다면 0을 출력한다.</p>

