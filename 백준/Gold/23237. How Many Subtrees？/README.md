# [Gold IV] How Many Subtrees? - 23237 

[문제 링크](https://www.acmicpc.net/problem/23237) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

그래프 이론, 브루트포스 알고리즘, 그래프 탐색, 트리

### 제출 일자

2025년 9월 25일 20:23:36

### 문제 설명

<p>Trees are used for all sorts of purposes, such as parsing, information storage and retrieval, sorting, etc. An unweighted, undirected, unrooted tree T is made up of vertices and edges. Each edge connects two vertices. In a tree, any pair of vertices must be connected by some path of edges and vertices through the tree, but they may be connected by only one simple path (no cycles are permitted). Note that any tree with V vertices must have V-1 edges.</p>

<p>There are a lot of trees in computer science, but there are even more than might appear at first glance. This is because every tree is itself made up of one or more subtrees. A subtree S of a tree T is itself a tree, made only from the vertices and edges of T. A subtree must have at least one vertex, and a tree is considered a subtree of itself. Here is an example of a tree with four vertices (the large tree on the left) and its 11 subtrees (the smaller trees in the box on the right):</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/9e9c74ea-a3ba-4c50-95fc-124c30098e67/-/preview/" style="width: 285px; height: 138px;"></p>

<p>Write a program that, for each given tree, determines the number of subtrees that it has.</p>

### 입력 

 <p>The input file contains multiple test cases, each describing a tree. Each test case starts with an integer 1 ≤ V ≤ 10 indicating the number of vertices in the tree. Vertices are implicitly labeled 0 through V-1. V is followed by V-1 edge descriptions. Each edge description has two integers 0 ≤ A < V and 0 ≤ B < V, where A ≠ B, indicating the endpoints A and B are connected. The last test case is followed by a line containing a single zero.</p>

### 출력 

 <p>For each test case, print the case number (beginning with 1) followed by the number of subtrees. Follow the format of the sample output.</p>

