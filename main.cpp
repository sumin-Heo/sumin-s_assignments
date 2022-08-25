#include "BST.h"

int main() {
	Tree t; // Tnode를 넣을 트리 선언
	cout << "1.입력 2.탐색 3.삭제 4.보기 5.종료" << endl; 
	// 각 번호를 입력하면 호출되는 함수 명시
	while (true) {                      // break 직접 호출 전까지 while문 작동
		int i = 0; int k = -1; char v;  // 각 변수들 정의 및 초기화
		cin >> i;                       // 함수 호출 및 동작을 위한 번호를 입력받음
		if (i == 1) {                   // 입력함수 호출
			cin >> k >> v;              // 삽입할 노드의 key와 value 값 입력받음
			Tnode* tn = new Tnode(k, v);// 각 값을 포함한 새로운 노드 생성
			t.Insert(tn);               // 삽입 함수를 호출해 트리 t에 새로 생성한 노드 tn 삽입
		}
		else if (i == 2) {              // 탐색함수 호출
			cin >> k;                   // 탐색할 노드의 key값을 입력받음
			cout << t.Get(k) << endl;   // 입력받은 key 값을 가진 노드의 value 값 출력
		}
		else if (i == 3) {              // 삭제함수 호출
			cin >> k;                   // 삭제할 노드의 key 값을 입력받음
			t.Delete(k);                // 삭제함수를 호출해 트리 t에서 key 값이 k인 노드를 찾아 삭제
		}
		else if (i == 4) {              // 보기함수 출력
			t.View_In();                // 트리 t에 있는 노드들을 출력하는 함수 호출
			cout << endl;
		}
		else if (i == 5) { break; }     // while문을 종료하며 프로그램 종료
	}
}