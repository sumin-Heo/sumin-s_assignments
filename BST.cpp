#include "BST.h"
using namespace std;

Tnode::Tnode(){}  // Tnode 생성자 정의
Tnode::Tnode(int k, char v) { key = k; value = v; } 
// 입력받은 key와 value를 포함한 노드 생성
Tree::Tree(){}    // Tree 생성자 정의

char Tree::Get(int k) {  // 탐색을 Root에서 시작하기 위한 아래 Get 함수 호출 함수
	return Get(Root, k);
}
char Tree::Get(Tnode* p, int k) { // 이진 탐색 트리에서 k의 key값을 갖는 노드 탐색 함수
	if (!p) return 0;             // 노드가 존재하지 않으면 0을 반환
	if (k < p->key) return Get(p->leftChild, k); 
	// p의 key값이 찾는 key값인 k보다 클 때 p의 leftChild 값과 비교하여 다시 탐색
	if (k > p->key) return Get(p->rightChild, k);
	//  p의 key값이 찾는 key값인 k보다 작을 때 p의 rightChild 값과 비교하여 다시 탐색
	return p->value;              // key의 값이 k인 노드를 찾았다면 해당 노드의 value 값 반환
}
void Tree::Insert(Tnode* n) {     // 이진탐색트리에 n노드를 삽입하는 함수
	Tnode* p = Root, * pp = 0;    // root를 가르키는 p 변수와 p 변수의 부모인 pp 변수 초기화
	while (p) {                   // p에 값이 있다면 while문 실행
		pp = p;                   // 현재 p의 값을 pp에 저장
		if (n->key > p->key) { p = p->rightChild; }
		else if (n->key < p->key) { p = p->leftChild; }
		// 삽입할 노드의 key값과 p의 key 값을 비교해 p값을 현재 p의 자식 노드 중 하나로 변경
		else { cout << "A key that already exists." << endl; return; }
		// 삽입할 n 노드의 key 값이 현재 p의 key 값과 같다면 오류 문장을 띄우고 함수 종료
	}
	p = n;      // while 문으로 n노드가 삽입할 위치인 p를 찾고 해당 위치 노드를 n으로 지정
	if (Root) { // tree가 공백이 아님
		if (p->key < pp->key) pp->leftChild = p;
		else pp->rightChild = p;
	}
	// 삽입한 노드를 부모 노드pp와 비교 후 left 또는 right로 연결
	else Root = p; // tree가 공백이라면 p를 root노드로 지정
}
void Tree::Delete(const int k){  // 입력받은 key 값을 가진 노드를 삭제하는 함수
	Tnode* p = Root, * pp = 0, * removeN = NULL;
	// 노드를 지정하는 각 변수들 정의
	while (p) {                  // p에 값이 있다면 while문 실행
		if (k > p->key) { pp = p; p = p->rightChild; }
		else if (k < p->key) { pp = p; p = p->leftChild; }
		// 입력받은 key 값과 현재 노드인 p의 key 값을 비교하며 key의 값이 k인 노드 찾기
		else { removeN = p; break; }
		// k와 key 값이 같은 노드를 removeN에 저장
	}
	if (p->leftChild == NULL && p->rightChild == NULL) {      // 삭제할 노드가 단일노드일 때
		if (pp->leftChild == p) pp->leftChild = NULL;
		if (pp->rightChild == p) pp->rightChild = NULL;
		// 부모 노드인 pp의 자식을 NULL로 지정해 p 노드 삭제
	}
	else if (p->leftChild == NULL || p->rightChild == NULL) { // 삭제할 노드가 자식이 1개일때
		if (p->leftChild != NULL) pp->leftChild = p->leftChild;
		else pp->rightChild = p->rightChild;
		// 부모 노드pp의 자식 노드를 p의 자식 노드로 지정해 p 삭제
	}
	else if (p->leftChild != NULL && p->rightChild != NULL) { // 삭제할 노드가 자식이 2개일 때
		p = p->rightChild;
		while (p->leftChild != NULL) {p = p->leftChild;}
		// 삭제할 노드의 자리로 들어갈 노드를 탐색
		Tnode* temp = p; // 삭제할 노드 자리에 들어갈 노드를 temp에 저장
		Delete(p->key);  // 삭제할 노드 자리에 들어갈 노드를 삭제
		removeN->key = temp->key; removeN->value = temp->value;
		// 삭제할 노드의 key와 value 값을 temp에 저장해둔 값들로 변경
	}
}

void Tree::View_In() { View_In(Root); }  // Root에서부터 출력하기 위한 아리 View_In 호출 함수
void Tree::View_In(Tnode* currentNode) { // 중위순회를 이용해 정렬한 트리 출력 함수
	if (currentNode) {                   // 현재 노드에 값이 존재한다면
		View_In(currentNode->leftChild);
		cout << currentNode->value << " ";
		View_In(currentNode->rightChild);// 중위순회에 따른 방문
	}
}