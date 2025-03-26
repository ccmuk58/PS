# [Platinum V] 상남자 - 17267 

[문제 링크](https://www.acmicpc.net/problem/17267) 

### 성능 요약

메모리: 7060 KB, 시간: 36 ms

### 분류

너비 우선 탐색, 그래프 이론, 그래프 탐색

### 제출 일자

2025년 3월 27일 03:09:32

### 문제 설명

<p>CTP의 대표 상남자 영조는 자유롭게 이동하는 것을 좋아한다. 그렇지만 영조는 상남자이기 때문에 위아래로만 간다. 따라서 위, 아래로는 얼마든지 이동할 수 있지만 왼쪽, 오른쪽으로는 이동하지 않는다. 하지만 영조의 행동이 답답한 영조의 친구 보성이는 영조가 위, 아래로만 가는 걸 막기 위해 영조와 같이 다니며 왼쪽으로 최대 <em>L</em>번 오른쪽으로 최대 <em>R</em>번만큼 이동할 수 있게 영조를 도와준다. 영조와 보성이는 지도 밖으로는 나가지 않는다.</p>

<p>갈수 있는 땅, 벽의 위치, 영조와 보성이의 출발 위치가 지도 정보로 주어졌을 때 영조와 보성이가 출발 위치로부터 이동해서 갈 수 있는 모든 땅의 개수를 구해보자.</p>

<p>다음은 이해를 돕기 위한 예제1 그림이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/15fee471-cd34-476c-8572-cd934325c416/-/preview/" style="height: 337px; width: 500px;"></p>

<p>영조와 보성이가 시작 위치에서 갈수 있는 땅은 파란색, 벽이 있어 갈수 없는 땅은 검은색이다.</p>

<p>다음 그림은 영조와 보성이가 시작 위치에서 왼쪽으로 한 칸 이동했을 때이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/c8916dab-ab2e-45e3-8465-0820629a3d5c/-/preview/" style="height: 348px; width: 500px;"></p>

<p><strong>왼쪽으로 한 칸 이동하였으므로 더 이상 왼쪽으로는 갈 수 없고,</strong> 현재 상태에서 갈수 있는 길은 파란색으로 나타내었다.</p>

<p>다음 그림은 영조와 보성이가 시작 위치에서 아래로 갔을 때이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/9d07a586-8c16-4ebe-a2f4-b9679b497fc0/-/preview/" style="height: 363px; width: 500px;"></p>

<p>영조와 보성이가 아래로 한 칸 이동했을 때의 갈 수 있는 땅과 현재 상태이다.</p>

<p>다음 그림은 영조와 보성이가 자유롭게 이동하였을 때 도달 가능한 땅을 나타낸다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/7f6bdee8-a65f-43d4-88b6-5ad0f38277d9/-/preview/" style="width: 400px; height: 344px;"></p>

<p>영조와 보성이가 최대 왼쪽으로 <em>L</em>번, 오른쪽으로 <em>R</em>번 만큼 움직여서 자유롭게 이동했을 때 도달 가능한 땅은 13칸이다.</p>

### 입력 

 <p>첫 번째 줄에 지도의 행과 열 <em>N</em>, <em>M</em>이 주어진다 (1 ≤ <em>N</em>, <em>M </em>≤ 1,000)</p>

<p>두 번째 줄에 왼쪽과 오른쪽으로 갈수 있는 최대 횟수 <em>L</em>, <em>R</em>이 주어진다. (0 ≤ <em>L</em>,<em> R</em> ≤ <em>M</em>)</p>

<p>세 번째 줄부터 <em>N</em>+2줄까지 <em>M </em>의 크기만큼 지도가 주어진다.</p>

<ul>
	<li>0: 갈 수 있는 땅</li>
	<li>1: 벽이 있어 갈 수 없는 땅</li>
	<li>2: 영조와 보성이가 있는 위치</li>
</ul>

### 출력 

 <p>시작 위치를 포함하여 갈수 있는 땅의 개수를 출력한다.</p>

