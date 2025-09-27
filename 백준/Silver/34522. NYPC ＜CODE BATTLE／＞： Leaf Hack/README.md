# [Silver II] NYPC <CODE BATTLE/>: Leaf Hack - 34522 

[문제 링크](https://www.acmicpc.net/problem/34522) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

게임 이론

### 제출 일자

2025년 9월 28일 00:38:55

### 문제 설명

<p><a href="https://battle.nypc.co.kr">NYPC <CODE BATTLE/></a>은 참가자들이 직접 만든 AI 프로그램이 맞붙는 전략형 코딩 대전이다. 단순히 코드를 작성하는 것에 그치지 않고, 상대의 수를 읽으며 나만의 전술을 세우는 재미 때문에 많은 학생들에게 인기가 있다.</p>

<p>이번 온라인 라운드에서는 핑크빈과 예티라는 이름의 두 AI가 서버를 해킹해 대결한다. 서버는 루트를 가진 트리 구조로 되어 있으며, 모든 내부 노드에는 플래그가 하나씩 존재한다. 내부 노드란 초기 트리 상태에서 리프 노드가 아닌 노드를 의미한다.</p>

<p>이번 코드 배틀 규칙은 다음과 같다.</p>

<ul>
<li>핑크빈이 선공으로, 각 AI는 번갈아 턴을 진행한다.</li>
<li>각 턴에서 AI는 현재 남아 있는 <strong>리프 노드</strong> 중 하나를 셧다운해야 한다.</li>
<li>만약 어떤 노드의 모든 자식 노드가 셧다운되면, 그 노드는 새로운 리프 노드가 된다. 이때 마지막으로 자식 노드를 셧다운한 AI가 플래그 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container>개를 획득한다.</li>
</ul>

<p>게임은 루트 노드만 남을 때까지 진행된다. 루트 노드는 셧다운할 수 없으며, 게임이 끝났을 때 획득한 플래그 수가 더 많은 AI가 승리한다. 획득한 플래그 수가 같으면 무승부이다.</p>

<p>아직 실전 라운드가 진행되기 전, 연습 라운드로 코드 배틀이 진행 중이다. 실전 라운드에서는 다양한 모양의 서버 트리가 주어지지만, 현재 연습 라운드에서는 정점의 개수가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.363em;"><mjx-mi class="mjx-i" size="s"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>2</mn><mi>N</mi></msup><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2^N-1$</span></mjx-container>개인 포화 이진 트리<sup><a href="#perfect-bintree" id="r-perfect-bintree">[1]</a></sup> 형태의 서버가 주어진다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/b6e89484-9fca-4691-b58e-06256cce8507/-/preview/" style="width: 75%; margin-left: auto; margin-right: auto; display: block;"></p>

<p style="text-align: center;">위 그림은 정점이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-msup><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c></mjx-mn><mjx-script style="vertical-align: 0.363em;"><mjx-mn class="mjx-n" size="s"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-script></mjx-msup><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><msup><mn>2</mn><mn>3</mn></msup><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$2^3-1$</span></mjx-container>개인 포화 이진 트리 형태의 서버에서 코드 배틀을 진행한 모습이다.</p>

<p>두 AI는 성능이 우수하므로 항상 최선의 수를 둔다. 연습 라운드에서 어떤 AI가 이기게 될지 예측하는 프로그램을 작성해 보자.</p>

### 입력 

 <p>첫 번째 줄에 정수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 핑크빈이 이기는 경우 <span style="color:#e74c3c;"><code>Pink Bean</code></span>을, 예티가 이기는 경우 <span style="color:#e74c3c;"><code>Yeti</code></span>를, 무승부인 경우에는 <span style="color:#e74c3c;"><code>Draw</code></span>를 출력한다.</p>

