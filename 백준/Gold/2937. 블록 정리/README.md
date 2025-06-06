# [Gold IV] 블록 정리 - 2937 

[문제 링크](https://www.acmicpc.net/problem/2937) 

### 성능 요약

메모리: 2100 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘, 누적 합

### 제출 일자

2025년 5월 5일 03:03:16

### 문제 설명

<p>민혁 유치원에서는 아이들의 창의력과 인내력, 근력과 지구력, 잉여력과 탄성력, 판단력과 노력, 기력과 활동력, 활력과 달력, 내구력과 변형력, 응집력과 무력, 지력과 매력, 미력과 담력, 능력과 실력, 압력과 협력, 체력과 경력, 폭력과 세력, 양력과 음력, 입력과 출력, 권력과 주력, 병력과 전력, 마찰력과 동력, 전기력과 효력, 내력과 국력, 자기력과 중력, 화력과 수력, 원자력과 영향력, 이력과 경쟁력, 경제력과 설득력, 공권력과 원동력, 정치력과 집중력, 추진력과 연기력, 잠재력과 정신력, 부력과 재력, 마력과 유력, 조력과 여력, 초능력과 예지력, 표현력과 기억력, 무기력과 창조력, 순발력과 저항력, 호소력과 관찰력, 구속력과 풍력, 청력과 시력, 학력과 필력, 완력과 사력, 수사력과 자생력, 고학력과 번식력, 자금력과 포용력, 정력과 편력, 속력과 피력, 지도력과 통제력, 기동력과 사고력, 무중력과 결정력, 이해력과 친화력, 결단력과 태양력, 공격력과 방어력, 돌파력과 장악력, 전속력과 흡인력, 괴력과 극력, 독력과 경기력, 기획력과 득점력, 적응력과 파괴력, 행정력과 구매력, 도약력과 반발력, 진력과 금력, 강력과 약력, 정치권력과 분석력, 세정력과 자제력, 반작용력과 만유인력, 근지구력과 진심전력, 불가항력과 청천벽력, 폭발력과 형성력, 견제력과 장력, 각력과 감항능력, 겸인지력과 결심육력, 고광지력과 구사력, 단결력과 생활력, 수비력과 운동력, 교정시력과 공력, 어휘력과 군책군력, 구태양력과 조직력, 가창력과 문장력, 발표력과 교력, 궁력과 동심합력, 방위력과 소비력, 연출력과 자본력, 주도력과 그레고리력, 율리우스력과 마호메트력, 무능력과 작용력, 주동력과 가로복원력, 강제통영력과 게이지압력, 경제잠재력과 분투노력, 공소의효력과 불유여력, 직감력과 직관력, 추리력과 충격력, 횡압력과 감별력, 결합력과 기술력, 미적판단력과 발전소출력, 사회적압력과 신통력, 동원력과 가호력, 다력과 대력, 감각력과 감득력, 자기세력과 일심협력, 이집트력과 정지마찰력, 잠재구매력과 최대마찰력, 감상력과 개괄력, 개발력과 개념력, 도력과 구상력, 관통력과 물력, 기조력과 기전력, 담세력과 독서력, 독창력과 법력, 강한핵력과 약한핵력을 기르기 위해 재미있는 게임을 만들었다.</p>

<p>이 게임을 하려면 한 변의 길이가 N인 정사각형 보드가 필요하다. 이 보드는 변의 길이가 1인 정사각형 N*N개로 나누어져 있다. 또, 변의 길이가 1인 정육면체 블록도 여러 개 있다. 아이들은 이 블록을 보드 위의 한 정사각형 위에 올려놓거나, 다른 블록 위에 올려 놓는다. 항상 블록은 정사각형 하나를 가득 채우게 놓아야 한다.</p>

<p>아이들은 이 놀이를 하고 난 다음에 반드시 뒷정리를 하고 집에 가야 한다. 만약, 뒷정리를 하지 않을 경우에는 민혁 선생님과 력으로 끝나는 단어 외우기를 해야 한다.</p>

<p>선생님은 아이들에게 직사각형을 가르쳐 주기 위해서, 블록을 직사각형 모양으로 배열하라고 했다. 이때, 한 블록 위에 다른 블록이 있으면 안 된다.</p>

<p>지금 블록의 상태가 주어졌을 때, 이 블록이 놓인 모습이 직사각형이 되게 하기 위해서 블록을 최소 몇 개 움직여야 하는지 구하는 프로그램을 작성하시오. 한 칸의 가장 위에 있는 블록을 다른 칸의 가장 위에 올려놓는 이동만 할 수 있다.</p>

### 입력 

 <p>첫째 줄에 보드판의 한 변의 길이 N과 그 위의 블록의 개수 M이 주어진다. (1 ≤ N ≤ 100, 1 ≤ M ≤ N<sup>2</sup>)</p>

<p>다음 M개 줄에는 블록이 있는 위치(좌표) R과 C가 주어진다. (1 ≤ R, C ≤ N)</p>

### 출력 

 <p>첫째 줄에 블록을 최소 몇 개 이동시키면 직사각형을 만들 수 있는지 출력한다. 항상 직사각형을 만들 수 있는 경우만 입력으로 주어진다.</p>

