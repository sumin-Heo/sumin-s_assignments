#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Tree;

class Tnode {         // 이진트리 속의 노드 객체
private:
	int key;          // Tnode의 int 값
	char value;       // Tnode의 char 값
	Tnode* leftChild; // 현재 node보다 key 값이 작은 자식 node
	Tnode* rightChild;// 현재 node보다 key 값이 큰 자식 node

public:
	Tnode();          // 생성자 
	Tnode(int, char); // int형의 key와 char형의 value를 입력받는 생성자
	~Tnode() {}       // 파괴자

	friend class Tree;// Tree 클래스와의 friend 선언
};

class Tree {                     // 이진트리
private:
	Tnode* Root;                 // Tree 클래스의 root

public:
	Tree();
	~Tree(){}
	char Get(const int);         // 순환적 탐색을 위한 아래 탐색 함수 Get 호출 함수
	char Get(Tnode*, const int); // 탐색 함수
	void Insert(Tnode*);         // 삽입 함수
	void Delete(const int);      // 삭제 함수
	void View_In();              // 보기 함수의 driver
	void View_In(Tnode*);        // 중위순회를 이용해 정렬한 후 출력하는 보기함수의 workhorse
};