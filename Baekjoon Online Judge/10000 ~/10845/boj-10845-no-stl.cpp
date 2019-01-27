/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <string>

using namespace std;

class Queue {
private:
	int* arr;
	int frontIdx = 0, rearIdx = 0;

public:
	Queue(const int& MAX) {
		this->arr = new int[MAX];
	}

	void push(int val) {
		this->arr[this->rearIdx] = val;
		this->rearIdx += 1;
	}

	int pop() {
		if (this->empty()) {
			return -1;
		}

		int ret = this->arr[this->frontIdx];
		this->frontIdx += 1;

		return ret;
	}

	int size() {
		return this->rearIdx - this->frontIdx;
	}

	int empty() {
		return this->size() > 0 ? 0 : 1;
	}

	int front() {
		return this->empty() ? -1 : this->arr[this->frontIdx];
	}

	int back() {
		return this->empty() ? -1 : this->arr[this->rearIdx - 1];
	}
};

int main() {
	int n;
	string oper;

	cin >> n;
	Queue* q = new Queue(n + 1);
	
	while (n--) {
		cin >> oper;

		if (oper == "push") {
			int val;
			cin >> val;
			q->push(val);
		} else if (oper == "pop") {
			cout << q->pop() << endl;
		} else if (oper == "size") {
			cout << q->size() << endl;
		} else if (oper == "empty") {
			cout << q->empty() << endl;
		} else if (oper == "front") {
			cout << q->front() << endl;
		} else if (oper == "back") {
			cout << q->back() << endl;
		}
	}
}