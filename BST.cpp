#include "BST.h"
using namespace std;

Tnode::Tnode(){}  // Tnode ������ ����
Tnode::Tnode(int k, char v) { key = k; value = v; } 
// �Է¹��� key�� value�� ������ ��� ����
Tree::Tree(){}    // Tree ������ ����

char Tree::Get(int k) {  // Ž���� Root���� �����ϱ� ���� �Ʒ� Get �Լ� ȣ�� �Լ�
	return Get(Root, k);
}
char Tree::Get(Tnode* p, int k) { // ���� Ž�� Ʈ������ k�� key���� ���� ��� Ž�� �Լ�
	if (!p) return 0;             // ��尡 �������� ������ 0�� ��ȯ
	if (k < p->key) return Get(p->leftChild, k); 
	// p�� key���� ã�� key���� k���� Ŭ �� p�� leftChild ���� ���Ͽ� �ٽ� Ž��
	if (k > p->key) return Get(p->rightChild, k);
	//  p�� key���� ã�� key���� k���� ���� �� p�� rightChild ���� ���Ͽ� �ٽ� Ž��
	return p->value;              // key�� ���� k�� ��带 ã�Ҵٸ� �ش� ����� value �� ��ȯ
}
void Tree::Insert(Tnode* n) {     // ����Ž��Ʈ���� n��带 �����ϴ� �Լ�
	Tnode* p = Root, * pp = 0;    // root�� ����Ű�� p ������ p ������ �θ��� pp ���� �ʱ�ȭ
	while (p) {                   // p�� ���� �ִٸ� while�� ����
		pp = p;                   // ���� p�� ���� pp�� ����
		if (n->key > p->key) { p = p->rightChild; }
		else if (n->key < p->key) { p = p->leftChild; }
		// ������ ����� key���� p�� key ���� ���� p���� ���� p�� �ڽ� ��� �� �ϳ��� ����
		else { cout << "A key that already exists." << endl; return; }
		// ������ n ����� key ���� ���� p�� key ���� ���ٸ� ���� ������ ���� �Լ� ����
	}
	p = n;      // while ������ n��尡 ������ ��ġ�� p�� ã�� �ش� ��ġ ��带 n���� ����
	if (Root) { // tree�� ������ �ƴ�
		if (p->key < pp->key) pp->leftChild = p;
		else pp->rightChild = p;
	}
	// ������ ��带 �θ� ���pp�� �� �� left �Ǵ� right�� ����
	else Root = p; // tree�� �����̶�� p�� root���� ����
}
void Tree::Delete(const int k){  // �Է¹��� key ���� ���� ��带 �����ϴ� �Լ�
	Tnode* p = Root, * pp = 0, * removeN = NULL;
	// ��带 �����ϴ� �� ������ ����
	while (p) {                  // p�� ���� �ִٸ� while�� ����
		if (k > p->key) { pp = p; p = p->rightChild; }
		else if (k < p->key) { pp = p; p = p->leftChild; }
		// �Է¹��� key ���� ���� ����� p�� key ���� ���ϸ� key�� ���� k�� ��� ã��
		else { removeN = p; break; }
		// k�� key ���� ���� ��带 removeN�� ����
	}
	if (p->leftChild == NULL && p->rightChild == NULL) {      // ������ ��尡 ���ϳ���� ��
		if (pp->leftChild == p) pp->leftChild = NULL;
		if (pp->rightChild == p) pp->rightChild = NULL;
		// �θ� ����� pp�� �ڽ��� NULL�� ������ p ��� ����
	}
	else if (p->leftChild == NULL || p->rightChild == NULL) { // ������ ��尡 �ڽ��� 1���϶�
		if (p->leftChild != NULL) pp->leftChild = p->leftChild;
		else pp->rightChild = p->rightChild;
		// �θ� ���pp�� �ڽ� ��带 p�� �ڽ� ���� ������ p ����
	}
	else if (p->leftChild != NULL && p->rightChild != NULL) { // ������ ��尡 �ڽ��� 2���� ��
		p = p->rightChild;
		while (p->leftChild != NULL) {p = p->leftChild;}
		// ������ ����� �ڸ��� �� ��带 Ž��
		Tnode* temp = p; // ������ ��� �ڸ��� �� ��带 temp�� ����
		Delete(p->key);  // ������ ��� �ڸ��� �� ��带 ����
		removeN->key = temp->key; removeN->value = temp->value;
		// ������ ����� key�� value ���� temp�� �����ص� ����� ����
	}
}

void Tree::View_In() { View_In(Root); }  // Root�������� ����ϱ� ���� �Ƹ� View_In ȣ�� �Լ�
void Tree::View_In(Tnode* currentNode) { // ������ȸ�� �̿��� ������ Ʈ�� ��� �Լ�
	if (currentNode) {                   // ���� ��忡 ���� �����Ѵٸ�
		View_In(currentNode->leftChild);
		cout << currentNode->value << " ";
		View_In(currentNode->rightChild);// ������ȸ�� ���� �湮
	}
}