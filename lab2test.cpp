#define CATCH_CONFIG_MAIN //заміна мейну
#include "catch.hpp" // підключення фреймворк
#include <stdio.h>
#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

class Tree {
public:
	TreeNode * root;
	Tree() {
		this->root = NULL;
	}
	void push(int val) {
		if (this->root == NULL) {
			this->root = new TreeNode(val);
			return;
		}
		this->pushHelper(this->root, val);
	}
	void print() {
		printHelper(this->root, 0);
		printf("\n");
	}

	TreeNode *deleteNode(int val) {
		return deleteValHelper(this->root, val);
	}

	int find(TreeNode *root, int elem) {
		if (root == NULL) {
			
			return -1;
		}
		if (elem == root->val) {
			
			return elem;
		}

		if (elem < root->val) {
			return find(root->left, elem);
		}
		else {
			return find(root->right, elem);
		}
		return elem;
	}
private:

	TreeNode * minValueNode(TreeNode *r) {
		TreeNode* curr = r;
		while (curr->left != NULL) curr = curr->left;
		return curr;
	}

	TreeNode *deleteValHelper(TreeNode *r, int val) {
		if (r == NULL) return r;
		if (val < r->val) {
			r->left = deleteValHelper(r->left, val);
		}
		else if (val > r->val) {
			r->right = deleteValHelper(r->right, val);
		}
		else {
			if (
				r->left == NULL) {
				TreeNode *tmp = r->right;
				delete r;
				return tmp;
			}
			else if (r->right == NULL) {
				TreeNode *tmp = r->left;
				delete r;
				return tmp;
			}
			TreeNode *tmp = minValueNode(r->right);
			r->val = tmp->val;
			r->right = deleteValHelper(r->right, tmp->val);
		}
		return r;
	}

	void printHelper(TreeNode* r, int level) {
		if (r == NULL) return;
		printHelper(r->right, level + 1);
		for (int i = 0; i < level; i++) {
			printf(" ");
		}
		printf("%d\n", r->val);
		printHelper(r->left, level + 1);
	}

	void pushHelper(TreeNode *r, int val) {
		if (val >= r->val) {
			if (r->right != NULL) {
				pushHelper(r->right, val);
				return;
			}
			r->right = new TreeNode(val);
		}
		else {
			if (r->left != NULL) {
				pushHelper(r->left, val);
				return;
			}
			r->left = new TreeNode(val);
		}
	}
};

int isEqual(TreeNode* r1, TreeNode* r2) {
	if ((r1 == NULL && r2 != NULL) || (r2 == NULL && r1 != NULL)) {
		return 0;
	}
	if (r2 == r1 && r1 == NULL) {
		return 1;
	}
	if (isEqual(r1->left, r2->left) && isEqual(r1->right, r2->right) && (r1->val == r2->val)
		) {
		return 1;
	}
	return 0;
}
/*
int main() {
	Tree* a = new Tree();
	a->push(10);
	a->push(11);
	a->push(8);
	a->push(5);
	a->push(15);
	a->push(9);
	a->push(90);
	a->print();
	Tree* b = new Tree();
	b->push(10);
	b->push(11);
	b->push(8);
	b->push(5);
	b->push(15);
	b->push(9);
	b->push(90);
	b->print();
	printf("%d\n", isEqual(a->root, b->root));
	// a->deleteNode(1);
	// a->print();
	return 0;
}
*/

TEST_CASE()
{
	Tree* a = new Tree();
	a->push(50);
	a->push(15);
	a->push(9);
	a->push(90);
	
	REQUIRE(a->find(a->root, 90) == 90); //тут я перевіряю чи верне функція бажане значення
	REQUIRE(a->find(a->root, 50) == 50);
	REQUIRE(a->find(a->root, 15) == 15);
	REQUIRE(a->find(a->root, 999) == -1);
}

TEST_CASE()
{
	Tree* a = new Tree();
	a->push(50);
	a->push(15);
	a->push(9);
	a->push(90);
	
	REQUIRE(a->find(a->root, 50) == 50);//тут я перевіряю чи верне функція бажане значення

	a->deleteNode(50); //тут я перевіряю чи дійсно працюєте деліт
	REQUIRE(a->find(a->root, 50) == -1); //якщо працює то функція поверне -1
    REQUIRE(a->root->val == 90);// чи дійсно стане 90
}

TEST_CASE()
{
    Tree* a = new Tree();
	a->push(50);
	a->push(15);
    a->push(17);
	a->push(9);
	a->push(90);   

    REQUIRE(a->find(a->root, 15) == 15);

    a->deleteNode(15); //тут я перевіряю чи дійсно працюєте деліт
	REQUIRE(a->find(a->root, 15) == -1); //якщо працює то функція поверне -1
    REQUIRE(a->root->left->val == 17);// чи дійсно стане 17
}

TEST_CASE()
{
    Tree* a = new Tree();
	a->push(50);
	a->push(15);
    a->push(17);
	a->push(9);
	a->push(90);   
    a->push(90); 
    REQUIRE(a->find(a->root, 90) == 90);
    a->deleteNode(90); //тут я перевіряю чи дійсно працюєте деліт
	REQUIRE(a->root->right->val == 90); //якщо працює то функція поверне -1
}

TEST_CASE()
{
    Tree* a = new Tree();
	a->push(50);
	a->push(15);
    a->push(17);
	a->push(9);
	a->push(90);   
    a->push(90); 
    Tree* b = new Tree();
	b->push(50);
	b->push(15);
    b->push(17);
	b->push(9);
	b->push(90);   
    b->push(90); 

    REQUIRE(isEqual(a->root,b->root) == 1);
}

TEST_CASE()
{
    Tree* a = new Tree();
	a->push(50);
	a->push(15);
    a->push(17);
	a->push(9);
    Tree* b = new Tree();
	b->push(50);
	b->push(15);
    b->push(17);
	b->push(9);
	b->push(90);   
    b->push(90); 

    REQUIRE(isEqual(a->root,b->root) == 0);
}

TEST_CASE()
{
    Tree* a = new Tree();
    Tree* b = new Tree();
	b->push(50);
	b->push(15);
    b->push(17);
	b->push(9);
	b->push(90);   
    b->push(90); 

    REQUIRE(isEqual(a->root,b->root) == 0);
}