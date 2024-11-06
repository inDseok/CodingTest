#include <iostream>

using namespace std;
char tree[28][2];

void preorder(char node) {
	if (node == NULL) 
		return;
	cout << node;
	preorder(tree[node - 'A'][0]);
 	preorder(tree[node - 'A'][1]);
}
void inorder(char node) {
	if (node == NULL)
		return;
	inorder(tree[node - 'A'][0]);
	cout << node;
	inorder(tree[node - 'A'][1]);
}
void postorder(char node) {
	if (node == NULL)
		return;
	postorder(tree[node - 'A'][0]);
	postorder(tree[node - 'A'][1]);
	cout << node;
}
int main() {
	int N;
	cin >> N;
	char p, lc, rc;
	for (int i = 0; i < N; i++) {
		cin >> p >> lc >> rc;
		if (lc == '.') {
			tree[p-'A'][0] = NULL;
		}
		else {
			tree[p - 'A'][0] = lc;
		}
		if (rc == '.') {
			tree[p - 'A'][1] = NULL;
		}
		else {
			tree[p - 'A'][1] = rc;
		}
	}
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
}