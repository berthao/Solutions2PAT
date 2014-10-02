#include <iostream>
#include <stack>
#include <string>

using namespace std;

int node_count, current = 0;
bool first = true;

struct Binary_node {
	Binary_node (int name = NULL) {
		data = name;
		left = right = NULL;
	}
	int data;
	Binary_node *left;
	Binary_node *right;
};

void post_order (Binary_node visit) {
	if (visit.left != NULL)post_order (*(visit.left));
	if (visit.right != NULL)post_order (*(visit.right));
	if (first) {
		cout << visit.data;
		first = false;
	}
	else {
		cout << " " << visit.data;
	}
	return;
}

void in_order (Binary_node visit) {
	if (visit.left != NULL)post_order (*(visit.left));
	cout << visit.data << " ";
	if (visit.right != NULL)post_order (*(visit.right));
	return;
}

void pre_order (Binary_node visit) {
	cout << visit.data << " ";
	if (visit.left != NULL)post_order (*(visit.left));
	if (visit.right != NULL)post_order (*(visit.right));
	return;
}

Binary_node* create_tree () {
	Binary_node* node = NULL;
	if (current < 2 * node_count){
		string temp;
		cin >> temp;
		current++;
		if (temp !="Pop"){
			int num;
			cin >> num;
			node = new Binary_node(num);
			node->left = create_tree ();
			node->right = create_tree ();
		}
	}
	return node;
}


int main () {
	cin>>node_count;
	auto root = create_tree ();
	post_order (*root);

	return 0;
}