# [Gold III] 받아쓰기 - 20542 

[문제 링크](https://www.acmicpc.net/problem/20542) 

### 성능 요약

메모리: 49916 KB, 시간: 56 ms

### 분류

다이나믹 프로그래밍, 문자열

### 제출 일자

2025년 5월 7일 02:36:15

### 문제 설명

<p>세계적인 기업 CTP(Chickens Threaten Programming)에 입사하기 위해서는 영어 받아쓰기 테스트를 통과해야 한다. 영어 받아쓰기는 채용 담당자가 불러주는 단어를 지원자가 받아쓰는 시험이다. CTP에서는 받아쓰기 채점 프로그램을 통해 지원자가 작성한 답안에 점수를 매긴다. 지원자가 작성한 답안을 몇 번이나 수정해야 정답과 같아지는지 확인하는 방법이다. 수정에는 추가, 삭제, 변환 세 가지 방법이 있다. 추가는 한 글자를 추가하는 것이고, 삭제는 한 글자를 삭제하는 것이며, 변환은 한 글자를 다른 글자로 바꾸는 것을 의미한다. 추가, 삭제, 변환은 모두 동일하게 1회의 수정으로 취급한다. 다음은 각 수정 방법의 예를 나타낸 표이다.</p>


<table class="table table-bordered" style="width: 500px;">
	<tbody>
		<tr>
			<td> </td>
			<td style="text-align: center;"><strong>답안</strong></td>
			<td style="text-align: center;"><strong>정답</strong></td>
			<td style="text-align: center;"><b>수정 사항</b></td>
			<td style="text-align: center;"><strong>수정</strong></td>
		</tr>
		<tr>
			<td style="text-align: center;"><strong>추가</strong></td>
			<td style="text-align: center;">piza</td>
			<td style="text-align: center;">pizzaa</td>
			<td style="text-align: center;">z,a 추가</td>
			<td style="text-align: center;">2회</td>
		</tr>
		<tr>
			<td style="text-align: center;"><strong>삭제</strong></td>
			<td style="text-align: center;">pineapple</td>
			<td style="text-align: center;">apple</td>
			<td style="text-align: center;">p,i,n,e 삭제</td>
			<td style="text-align: center;">4회</td>
		</tr>
		<tr>
			<td style="text-align: center;"><strong>변환</strong></td>
			<td style="text-align: center;">johnber</td>
			<td style="text-align: center;">johnson</td>
			<td style="text-align: center;">b->s, e->o, r->n 으로 각각 변환</td>
			<td style="text-align: center;">3회</td>
		</tr>
		<tr>
			<td style="text-align: center;"><strong>종합</strong></td>
			<td style="text-align: center;">fishcake</td>
			<td style="text-align: center;">taken</td>
			<td style="text-align: center;">f->t  변환 / i,s,h,c 삭제 / n 추가</td>
			<td style="text-align: center;">6회</td>
		</tr>
	</tbody>
</table>

<p>받아쓰기 테스트에서의 수정 횟수는 추가, 삭제, 변환 세 가지 수정 횟수의 합이 가장 최소로 일어난 경우를 말한다. 그리고 받아쓰기 테스트 점수는 작성한 답안을 정답으로 바꿀 때 필요한 총 수정 횟수와 같다. 만약 총 세 번의 수정이 일어났다면 3점을 획득하는 것이다. 0점이 제일 좋은 점수이다.</p>

<p>승연이는 CTP에 입사하기 위해 영어 받아쓰기를 공부중이다. 그러던 중 기가막힌 방법을 알게 되었는데, 그것은 바로 i와 v를 휘갈겨 쓰는 것이다. 실제로 CTP의 채점 시스템은 종이에 작성한 답안을 카메라로 인식해 정답과 비교하기 때문에, 휘갈겨 쓴 글자를 잘못 인식하는 에러가 있다. 휘갈겨 쓴 i는 i, j, l 모두와 매칭된다. 예를 들어 정답이 'james'일 때 답안이 'iames'라면 수정 횟수는 0회로 채점된다.대신 답안에 작성한 j와 l은 정확하게 인식한다. 마찬가지로 휘갈겨 쓴 v는 v, w와 매칭된다. 정답이 'warren'일 때 답안이 'varren'이라면 채점 결과는 0점이다. 단, w는 정확히 인식하기 때문에, 정답이 'vaccine'일 때 답안이 'waccine'이라면 점수는 1점으로 채점된다. 다시 한 번 정리하자면 i와 v를 제외한 모든 글자는 정확히 인식한다. 미리 자신의 점수를 확인해보고싶어하는 승연이를 위해 받아쓰기 점수를 계산하는 프로그램을 만들어보자!</p>

### 입력 

 <p>첫 번째 줄에 승연이가 작성한 답안의 길이 n, 정답의 길이 m이 공백을 두고 차례로 주어진다.</p>

<p><meta charset="utf-8"></p>

<p dir="ltr">두 번째 줄에 승연이가 작성한 답안이, 세 번째 줄에 정답이 주어진다.</p>

<p dir="ltr">승연이가 작성한 답안과 정답은 모두 영어 소문자로만 이루어진다.</p>

### 출력 

 <p>첫 번째 줄에 승연이의 점수를 출력한다.</p>

