#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Tree;

class Tnode {         // ����Ʈ�� ���� ��� ��ü
private:
	int key;          // Tnode�� int ��
	char value;       // Tnode�� char ��
	Tnode* leftChild; // ���� node���� key ���� ���� �ڽ� node
	Tnode* rightChild;// ���� node���� key ���� ū �ڽ� node

public:
	Tnode();          // ������ 
	Tnode(int, char); // int���� key�� char���� value�� �Է¹޴� ������
	~Tnode() {}       // �ı���

	friend class Tree;// Tree Ŭ�������� friend ����
};

class Tree {                     // ����Ʈ��
private:
	Tnode* Root;                 // Tree Ŭ������ root

public:
	Tree();
	~Tree(){}
	char Get(const int);         // ��ȯ�� Ž���� ���� �Ʒ� Ž�� �Լ� Get ȣ�� �Լ�
	char Get(Tnode*, const int); // Ž�� �Լ�
	void Insert(Tnode*);         // ���� �Լ�
	void Delete(const int);      // ���� �Լ�
	void View_In();              // ���� �Լ��� driver
	void View_In(Tnode*);        // ������ȸ�� �̿��� ������ �� ����ϴ� �����Լ��� workhorse
};