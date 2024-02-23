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
		for (int i = 0; i < chapters; i++)
		{
			root->child[i] = new node;
			cout << "Name of the chapter " << i + 1 << ":";
			cin.get();
			getline(cin, root->child[i]->label);
			cout << "Enter no of sctions in chapters :" << root->child[i]->label;
			cin >> root->child[i]->chno;
			for (int j = 0; j < root->child[i]->chno; j++)
			{
				root->child[i]->child[j] = new node;
				cout << "Enter the name of Section " << j + 1 << ":";
				cin.get();
				getline(cin, root->child[i]->child[j]->label);
			}
		}

	}
};