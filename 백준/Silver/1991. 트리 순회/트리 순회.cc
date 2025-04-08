#include <iostream>
#include <map>

int N;
std::map<char, std::pair< char, char >> tree;	// A : B C == A 왼쪽B 오른쪽C
/*
전위 : 루트 왼 오 preorder
중위 : 왼 루트 오 inorder
후위 : 왼 오 루트 postorder
*/

void preorder(char startnode) {
	std::cout << startnode;

	char l = tree[startnode].first;
	char r = tree[startnode].second;
	
	if(l != '.') 
		preorder(l);
	if(r != '.')
		preorder(r);
}

void inorder(char startnode) {
	char l = tree[startnode].first;
	char r = tree[startnode].second;

	if (l != '.')
		inorder(l);

	std::cout << startnode;

	if (r != '.')
		inorder(r);
}

void postorder(char startnode) {
	char l = tree[startnode].first;
	char r = tree[startnode].second;

	if (l != '.')
		postorder(l);
	if (r != '.')
		postorder(r);

	std::cout << startnode;

}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> N;
	
	for (int i = 0; i < N; ++i) {
		char n, l, r;
		std::cin >> n >> l >> r;
		tree[n] = { l, r };
	}

	preorder('A');
	std::cout << "\n";
	inorder('A');
	std::cout << "\n";
	postorder('A');
	
}