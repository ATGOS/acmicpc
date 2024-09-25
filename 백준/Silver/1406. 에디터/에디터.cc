#include <iostream>
#include <list>
#include <string>

int main() {
	std::list<char> l;
	int str_len{ 0 };
	std::string t;
	
	std::cin >> t;
	for (char i : t) {
		l.push_back(i);
	}
	str_len = t.length();
	std::list<char>::iterator cur = l.end();

	int M;
	std::cin >> M;
	char com;

	while (M--) {
		std::cin >> com;
		switch (com) {
		case 'L':
			if (cur != l.begin()) cur--;
			break;
		case 'D':
			if (cur != l.end()) cur++;
			break;
		case 'B':
			if (cur != l.begin()) {
				std::list<char>::iterator temp_cur = cur;
				temp_cur--;
				l.erase(temp_cur);
			}
			break;
		case 'P':
			char temp;
			std::cin >> temp;
			l.insert(cur, temp);
			break;
		}
	}
	for (char i : l) std::cout << i;

}