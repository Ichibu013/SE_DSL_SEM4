#include<iostream>
#include<string>
using namespace std;

struct node
{
	string label;
	int chno;
	struct node* child[10];
}*root;

class tree {
	tree() { root = NULL; }
	void create() {
		int books, chapters;
		root = new node;
		cout << "Enter the name of Book :";
		cin.get();
		getline(cin, root->label);
		cout << "Enter the number of chapters: ";
		cin >> chapters;
		root->chno = chapters;
	}
};