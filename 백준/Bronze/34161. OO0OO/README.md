# [Bronze II] OO0OO - 34161 

[문제 링크](https://www.acmicpc.net/problem/34161) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2025년 8월 24일 17:16:30

### 문제 설명

<blockquote>
<p><strong><em>제 이름은 똑바로 읽어도 거꾸로 읽어도 우영우입니다. 기러기, 토마토, 스위스, 인도인, 별똥별, 우영우. ...역삼역? </em> </strong></p>

<p>- 드라마 “이상한 변호사 우영우” 中 우영우</p>
</blockquote>

<p>현제는 요즘 드라마 “이상한 변호사 우영우”에 푹 빠져있다. 우영우는 똑바로 읽어도 거꾸로 읽어도 우영우다. 심지어 영어로 해도 <code>OO-0-OO</code>여서 거꾸로 읽어도 똑같다.</p>

<p>이렇게 거꾸로 읽어도 똑같은 문자열을 팰린드롬이라고 한다.</p>

<p>팰린드롬 문자열인지 확인하는 방법들 중 하나는 문자열을 뒤집은 뒤 원래 문자열과 같은지 비교하는 방식이 있다.</p>

<p>팰린드롬은 코딩에서 상당히 많이 등장한다. 대표적으로 팰린드롬과 관련된 알고리즘은 매내처 알고리즘이 있으며, 이를 활용하여 선형 시간 내에 모든 중심에서의 최장 팰린드롬의 길이를 구할 수 있다.</p>

<p>KMP나 Z 알고리즘 등을 이용해 최단 팰린드롬을 만들 수도 있으며, 자료구조 이름부터 팰린드롬인 <code>EERTREE</code>를 활용하여 온라인으로 팰린드롬과 관련한 여러 쿼리를 처리할 수도 있다.</p>

<p>팰린드롬은 코딩 및 알고리즘 이외에도 다양한 분야에 활용된다. 1722년 프란츠 요제프 하이든이 지은 교향곡 47번은 팰린드롬이라는 이름도 가지고 있는데, 미뉴에트 악장의 경우 악보가 팰린드롬으로 만들어졌기 때문이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/ac648ac9-238d-4cb7-87c2-d10206abcf16/-/preview/" style="width:600px;max-width:100%;"></p>

<p style="text-align: center;">프란츠 요제프 하이든이 지은 교향곡 47번 <팰린드롬> 中 팰린드롬 부분</p>

<p>이외에도 다양한 회문 악보가 존재하며, 여러 음악적인 영감을 주었다.</p>

<p>팰린드롬은 특히 생물학에서도 중요하게 등장한다. 우리의 몸에 있는 DNA에서도 팰린드롬을 발견할 수 있다.</p>

<p>DNA는 뉴클레오티드의 이중나선 구조로 이루어져 있으며, 뉴클레오티드는 당, 염기, 인산기로 이루어져 있다. DNA의 당은 디옥시리보오스(Deoxyribose)이며, 염기는 구아닌(Guanine), 아데닌(Adenine), 티민(Thymine), 시토신(Cytosine)의 종류가 있다. 새의 배설물이 굳어서 만들어진 암석 ‘구아노’에서 구아닌이 발견되었고, 이후 새로 발견된 염기와 함께 A(아데닌), T(티민), C(시토신), G(구아닌)으로 표기한다.</p>

<p>염기는 서로 상보적인 결합을 하며 아데닌과 티민은 이중 수소 결합, 구아닌과 시토신은 삼중 수소 결합을 형성한다. 염기들을 DNA를 구성하는 순서대로 <code>AATTCATG</code>와 같이 적어 염기 서열로 표기하며, 대응되는 상보 서열도 정의하여 위의 서열의 상보 서열은 <code>TTAAGTAC</code>이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/1ad38ba1-d10d-40cf-9f5f-9b925d4a3c76/-/preview/" style="width:600px;max-width:100%;"></p>

<p>여기서 유전자 가위라는 개념이 나온다. 크리스퍼(CRISPR, Clustered Regularly Interspaced Short Palindromic Repeats)는 주기적으로 반복되는 짧은 회문 염기 서열을 의미하며, 앞 뒤 어느 방향으로 읽어도 똑같다. 예를 들어 염기 서열 <code>GAATTC</code>의 상보 서열은 <code>CTTAAG</code>인데, 상보 서열을 거꾸로 읽으면 원래 서열인 <code>GAATTC</code>가 된다.</p>

<p>DNA는 양쪽 나선의 읽는 방향이 반대이므로, 이 <code>GAATTC</code> 염기 서열의 경우 어떤 나선을 기준으로 읽더라도 같은 결과인 <code>GAATTC</code>를 읽게 된다.</p>

<p>특정 염기 서열을 읽어 제거하는 제한 효소 역시 이런 회문 구조를 읽어 DNA를 절단하며, 이 중 <code>EcoRI</code>가 위의 서열인 <code>GAATTC</code>를 인식하여 제거한다.</p>

<p>유전자 가위는 이런 제한 효소의 성질을 이용하여 손상된 DNA를 절단해 제거하는 기술이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/4cf9f38e-4f4d-42d1-8544-eecaeb4688ac/-/preview/" style="width:600px;max-width:100%;"></p>

<p>유전자 가위는 세대를 거치며 발전해 왔다. 1세대에는 ZFN, 2세대는 TALEN, 3세대의 경우 CRISPR/Cas9으로 발전해 왔다.</p>

<p>특히 3세대 CRISPR/Cas9을 개발한 사르팡티에와 다우드나는 2020년 노벨화학상을 수상할 정도로 혁신적이고 고무적인 기술이다.</p>

<p>회문과 관련된 이야기는 여기까지 하도록 하고, 드라마 “이상한 변호사 우영우”에서 우영우는 아래와 같은 고래 문제를 낸다.</p>

<blockquote>
<p><strong><em>“몸무게가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c32"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>22</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$22$</span></mjx-container>톤인 암컷 향고래가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>500</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$500$</span></mjx-container>kg에 달하는 대왕오징어를 먹고 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c36"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>6</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$6$</span></mjx-container>시간 뒤 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c2E"></mjx-c><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1.3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1.3$</span></mjx-container>톤짜리 알을 낳았다면 이 암컷 향고래의 몸무게는 얼마일까요?”</em></strong></p>
</blockquote>

<blockquote>
<p><strong><em>정답은 ’고래는 알을 낳을 수 없다’입니다. 고래는 포유류라 알이 아닌 새끼를 낳으니까요. 무게에만 초점을 맞추면 문제를 풀 수 없습니다. 핵심을 봐야 돼요.</em></strong></p>
</blockquote>

<p>현제는 여기에 감동을 받아 다음과 같은 문제를 냈다.</p>

<blockquote>
<p><strong><em>“몸무게가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>A</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$A$</span></mjx-container>톤인 암컷 향고래가 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>B</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$B$</span></mjx-container>kg에 달하는 대왕오징어를 먹고 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>C</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$C$</span></mjx-container>시간 뒤 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D437 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>D</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$D$</span></mjx-container>톤짜리 알을 낳았다면 이 암컷 향고래의 몸무게는 얼마일까요?”</em></strong></p>
</blockquote>

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D437 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn><mo>≤</mo><mi>A</mi><mo>,</mo><mi>B</mi><mo>,</mo><mi>C</mi><mo>,</mo><mi>D</mi><mo>≤</mo><mn>10</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1\le A,B,C,D\le 10$</span></mjx-container>을 만족하는 모든 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>10</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10\, 000$</span></mjx-container>개의 정수 튜플 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D437 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">(</mo><mi>A</mi><mo>,</mo><mi>B</mi><mo>,</mo><mi>C</mi><mo>,</mo><mi>D</mi><mo data-mjx-texclass="CLOSE">)</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\left( A,B,C,D \right)$</span></mjx-container>에 대해 문제를 풀어보자.</p>

### 입력 

 <p>첫 번째 줄에 문자열 <span style="color:#e74c3c;"><code>Welcome</code></span>이 주어진다.</p>

<p>두 번째 줄에 문자열 <span style="color:#e74c3c;"><code>To The</code></span>이 주어진다.</p>

<p>세 번째 줄에 문자열 <span style="color:#e74c3c;"><code>MatKor Cup!</code></span>이 주어진다.</p>

### 출력 

 <p>총 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>10</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10\, 000$</span></mjx-container> 줄을 출력한다. 조건을 만족하는 모든 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>10</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>000</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$10\, 000$</span></mjx-container>개의 정수 튜플 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D437 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">(</mo><mi>A</mi><mo>,</mo><mi>B</mi><mo>,</mo><mi>C</mi><mo>,</mo><mi>D</mi><mo data-mjx-texclass="CLOSE">)</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\left( A,B,C,D \right)$</span></mjx-container> 쌍에 대해 문제에 대한 답을 kg 단위로 한 줄에 한 개씩 출력한다. 정답이 없거나 정수가 아니라면 대신 <span style="color:#e74c3c;"><code>-1</code></span>을 출력한다. 이때, <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mrow><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D434 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D435 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D436 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D437 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-mrow></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mrow data-mjx-texclass="INNER"><mo data-mjx-texclass="OPEN">(</mo><mi>A</mi><mo>,</mo><mi>B</mi><mo>,</mo><mi>C</mi><mo>,</mo><mi>D</mi><mo data-mjx-texclass="CLOSE">)</mo></mrow></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$\left( A,B,C,D \right)$</span></mjx-container>가 오름차순인 순서로 각 튜플의 답을 출력한다.</p>

<p>주어진 조건 내에서 정답이 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c39"></mjx-c><mjx-c class="mjx-c39"></mjx-c><mjx-c class="mjx-c38"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c34"></mjx-c><mjx-c class="mjx-c34"></mjx-c></mjx-mn><mjx-mstyle><mjx-mspace style="width: 0.167em;"></mjx-mspace></mjx-mstyle><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>998</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>244</mn><mstyle scriptlevel="0"><mspace width="0.167em"></mspace></mstyle><mn>353</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$998\, 244\, 353$</span></mjx-container> 미만의 정수 혹은 정답이 없거나 정수가 아님이 보장된다.</p>

