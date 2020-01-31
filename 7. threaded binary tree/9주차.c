#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

// Node struct to support threaded trees
typedef struct treeNode {
	char data;
	struct treeNode *left;
	struct treeNode *right;
	int isThreadRight;
} treeNode;

// makeNode
treeNode* makeNode(char data, treeNode* leftNode, treeNode* rightNode, int isThreadRight) {
	treeNode* node = (treeNode *)malloc(sizeof(treeNode));
	node->data = data;
	node->left = leftNode;
	node->right = rightNode;
	node->isThreadRight = isThreadRight;
	return node;
}

// return successor
treeNode *findThreadSuccessor(treeNode* p) {
	treeNode *q = p->right;
	if (q == NULL) return q;
	if (p->isThreadRight == 1) return q;
	while (q->left != NULL) q = q->left;
	return q;
}

// inorder traversal
void threadInorder(treeNode* root) {
	treeNode * q;
	q = root;
	while (q->left) q = q->left;
	do {
		printf("%3c", q->data);
		q = findThreadSuccessor(q);
	} while (q);
}


// �� threaded ��带 ã�� ����
treeNode *findThreadPredecessor(treeNode* p) {
	treeNode *q = p->left;
	if (q == NULL) return q;
	if (p->isThreadRight == 1) return q;
	while (q->right != NULL) q = q->right;
	return q;

}

// r�� p�� ���� �ڽ����� �߰�
void *insertLeft(treeNode* p, treeNode *r) {
	treeNode* temp;
	r->left = p->left;
	r->right = p;
	p->left = r; // p<->r ����
	if (r->left) {
		temp = findThreadPredecessor(r->left);
		temp->right = r;
		temp->isThreadRight = 1;
	}
	return NULL;
}

// r�� p�� ������ �ڽ����� �߰�
void *insertRight(treeNode* p, treeNode *r) {
	treeNode* temp;
	r->right = p->right;
	r->isThreadRight = 0;
	p->right = r;
	return NULL;
}

void main() {
	treeNode* n7 = makeNode('S', NULL, NULL, 0);
	treeNode* n6 = makeNode('A', NULL, NULL, 1);
	treeNode* n5 = makeNode('B', NULL, NULL, 1);
	treeNode* n4 = makeNode('C', NULL, NULL, 1);
	treeNode* n3 = makeNode('D', n6, n7, 0);
	treeNode* n2 = makeNode('P', n4, n5, 0);
	treeNode* n1 = makeNode('F', n2, n3, 0);

	n4->right = n2;
	n5->right = n1;
	n6->right = n3;

	printf("\n Inorder of a threaded binary tree : ");
	threadInorder(n1);

	// ���Ӱ� �� ��� �߰�
	treeNode* r1 = makeNode('H', NULL, NULL, 1);

	// B���� �ڽ����� r1(H) �߰�	
	insertLeft(n2, r1);

	// ���Ӱ� �� ��� �߰�
	treeNode* r2 = makeNode('I', NULL, NULL, 1);

	// C������ �ڽ����� r2(I) �߰�
	insertRight(n3, r2);

	printf("\n Inorder of a threaded binary tree : ");
	threadInorder(n1);

	getchar();
}