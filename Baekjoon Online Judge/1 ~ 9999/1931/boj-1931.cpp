/*
    Copyright(c) 2019. Minho Cheon. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Room {
	int start, end;

	Room(int _start, int _end) {
		this->start = _start;
		this->end = _end;
	}

	bool operator < (const Room& r) const {
		if (this->end == r.end) {
			return this->start < r.start;
		}
		return this->end < r.end;
	}
};

int main() {
	int n, start, end;
	vector<Room> rooms;

	cin >> n;
	for (int i = 0 ; i < n ; ++i) {
		cin >> start >> end;
		rooms.push_back(Room(start, end));
	}
	sort(rooms.begin(), rooms.end());

	int last = -1, ans = 0;
	for (const auto& room: rooms) {
		if (last <= room.start) {
			++ans;
			last = room.end;
		}
	}

	cout << ans << endl;
}