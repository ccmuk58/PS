# [Gold I] As Easy as CAB - 13731 

[문제 링크](https://www.acmicpc.net/problem/13731) 

### 성능 요약

메모리: 2164 KB, 시간: 0 ms

### 분류

그래프 이론, 문자열, 방향 비순환 그래프, 위상 정렬

### 제출 일자

2025년 9월 26일 17:01:19

### 문제 설명

<p>We all know how to alphabetize a list when you know the alphabet: One word may be a prefix of another longer word, in which case the shorter word always comes before the longer word. With any other two words there must be a first place in the words where their letters differ. Then the order of the words is determine by the lexicographical order of these first differing letters.</p>

<p>How about the reverse problem: Can you find the lexicographic order of the alphabet from an ordered list of words? Suppose an alphabet exists where the following list of word strings is given in lexicographical order:</p>

<pre>cab 
cda 
ccc 
badca</pre>

<p>It is clear that c comes before b in the underlying alphabet because cab comes before badca. Similarly, we know a comes before d, because cab < cda, a comes before c because cab < ccc, and d comes before c because cda < ccc. The only ordering of the 4 alphabet characters that is possible is adcb.</p>

<p>However, it may be that a list contains inconsistencies that make it impossible to be ordered under any proposed alphabet. For example, in the following list it must be that a comes before b in the alphabet since abc < bca, yet it also must be that b comes before a in the alphabet since bca < aca.</p>

<pre>abc 
bca 
cab 
aca</pre>

<p>Finally, some lists may not provide enough clues to derive a unique alphabet order, such as the following:</p>

<pre>dea 
cfb</pre>

<p>In this list, d comes before c but we don’t know about the relative positions of any of the other letters, so we are unable to uniquely discern the order of the alphabet characters.</p>

### 입력 

 <p>The first line of input will contain L and N, separated by a space, where L is a lowercase character b ≤ L ≤ z representing the highest character in the traditional alphabet that appears in the derived alphabet, and N is a integer 1 ≤ N ≤ 1 000 that is equal to the number of strings in the list. Each of the next N lines will contain a single nonempty string of length at most 1 000, consisting only of characters in the derived alphabet. No two strings will be the same.</p>

### 출력 

 <p>If the input is consistent with a unique ordering of the alphabet, output a string that designates that ordered alphabet. If the data is inconsistent with any ordering, output IMPOSSIBLE. If the data is consistent with multiple orderings, output AMBIGUOUS.</p>

