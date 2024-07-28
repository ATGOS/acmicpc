#include <iostream>
#include <climits>

int N;
int heap_len{ 0 };
std::pair<int, int> heap[100'000];	// first에 진짜, second에 절댓값


void swap(std::pair<int, int>* a, std::pair<int, int>* b) {
	std::pair<int, int> temp = *a;
	*a = *b;
	*b = temp;
}

void printing() {
	// 테스트용
	for (int i = 0; i < heap_len; i++) {
		std::cout << heap[i].first << " ";
	}
	std::cout << heap_len << "\n\n";
}


void push(int insert) {
	/*
	heap의 맨 마지막에 숫자 삽입 후
	재정렬.
	*/

	heap[heap_len].first = insert;
	heap[heap_len].second = std::abs(insert);
	heap_len++;

	int child{ heap_len - 1 };
	int parent{ (child - 1) / 2 };

	while (heap[child].second <= heap[parent].second && child > 0) {
		if (heap[child].second == heap[parent].second && heap[child].first > heap[parent].first) {
			break;
		}
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
	rtn = heap[0].first;

	// 맨 뒤를 맨 앞으로 보내고 맨 뒤 0으로 초기화, 그 다음에 길이 1 감소
	heap[0] = heap[heap_len - 1];
	heap_len--;

	int parent{ 0 };

	while (true) {
		int left_child = 2 * parent + 1;
		int right_child = 2 * parent + 2;
		int min_child;

		if (left_child >= heap_len) break; // 자식 노드가 없으면 종료
		if (right_child >= heap_len) {	// 오른쪽 자식이 없으면 min_child를 왼쪽 자식으로 함
			min_child = left_child;
		}
		else { // 자식이 둘 다 있을 때, 절댓값이 작은 것을 min_child로, 절댓값이 같으면 실제값이 작은 것을 min_child로
			if (heap[left_child].second == heap[right_child].second) {
				min_child = (heap[left_child].first < heap[right_child].first) ? left_child : right_child;
			}
			else {
				min_child = (heap[left_child].second < heap[right_child].second) ? left_child : right_child;
			}
		}

		if (heap[parent].second < heap[min_child].second) break; // 부모가 자식보다 작으면 종료
		if (heap[parent].second == heap[min_child].second && heap[parent].first < heap[min_child].first) break; // 값이 같은데 부모의 실제값이 더 작으면 종료
		swap(&heap[parent], &heap[min_child]);
		parent = min_child;
		//printing();
	}

	return rtn;
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);

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
		//printing();
	}

}