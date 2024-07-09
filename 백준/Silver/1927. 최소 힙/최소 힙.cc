
#include <iostream>
#include <climits>

int N;
int heap_len{ 0 };
int heap[100'000];


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printing() {
	// 테스트용
	for (int i = 0; i < heap_len; i++) {
		std::cout << heap[i] << " ";
	}
	std::cout << heap_len << "\n";
}


void push(int insert) {
	/*
	heap의 맨 마지막에 숫자 삽입 후
	재정렬.
	*/
	
	heap[heap_len] = insert;
	heap_len++;

	int child{ heap_len - 1 };
	int parent{ (child - 1) / 2 };

	while (heap[child] < heap[parent] && child > 0) {
		swap(&heap[child], &heap[parent]);
		child = parent;
		parent = (child - 1) / 2;
	}

}

int pop() {
	/*
	heap[0] return 후
	heap의 맨 마지막을 heap[0]으로 만든 다음
	재정렬.
	*/

	if (heap_len == 0) {
		return 0;
	}

	int rtn;
	rtn = heap[0];

	// 맨 뒤를 맨 앞으로 보내고 맨 뒤 0으로 초기화, 그 다음에 길이 1 감소
	heap[0] = heap[heap_len - 1];
	heap_len--;

	int parent{ 0 };

	while (true) {
		int left_child = 2 * parent + 1;
		int right_child = 2 * parent + 2;
		int min_child;

		if (left_child >= heap_len) break; // 자식 노드가 없으면 종료
		if (right_child >= heap_len) {
			min_child = left_child;
		}
		else {
			min_child = (heap[left_child] < heap[right_child]) ? left_child : right_child;
		}

		if (heap[parent] <= heap[min_child]) break; // 부모가 자식보다 작으면 종료

		swap(&heap[parent], &heap[min_child]);
		parent = min_child;
	}

	return rtn;
}


int main() {
	std::cin.tie(NULL);
	std::ios_base::sync_with_stdio(false);

	std::cin >> N;

	int a;

	for (int i = 0; i < N; i++) {
		std::cin >> a;
		if (a == 0) {
			std::cout << pop() << "\n";
		}
		else {
			push(a);
		}
		// printing();
	}

}