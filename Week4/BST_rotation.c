#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
    int height;
};

int max(int a, int b) { return (a > b) ? a : b; }
int getHeight(struct Node *n) { return (n == NULL) ? 0 : n->height; }

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

struct Node *rightRotate(struct Node *y) {
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

struct Node *leftRotate(struct Node *x) {
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

struct Node* balanceTree(struct Node* node) {
    if (node == NULL) return NULL;
    node->left = balanceTree(node->left);
    node->right = balanceTree(node->right);
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getHeight(node->left) - getHeight(node->right);
    if (balance > 1 && getHeight(node->left->left) >= getHeight(node->left->right)) return rightRotate(node);
    if (balance > 1 && getHeight(node->left->left) < getHeight(node->left->right)) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && getHeight(node->right->right) >= getHeight(node->right->left)) return leftRotate(node);
    if (balance < -1 && getHeight(node->right->right) < getHeight(node->right->left)) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void printGivenLevel(struct Node* root, int level) {
    if (root == NULL) return;
    if (level == 1) printf("%d ", root->key);
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrder(struct Node* root) {
    int h = getHeight(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
        printf("| ");
    }
}

int main() {
    printf("CH.SC.U4CSE24113\n");
    struct Node *root = newNode(157);
    root->left = newNode(110);
    root->left->right = newNode(147);
    root->left->right->left = newNode(122);
    root->left->right->right = newNode(149);
    root->left->right->right->right = newNode(151);
    root->left->right->left->left = newNode(111);
    root->left->right->left->right = newNode(141);
    root->left->right->left->left->right = newNode(112);
    root->left->right->left->right->left = newNode(123);
    root->left->right->left->right->left->right = newNode(133);
    root->left->right->left->left->right->left = newNode(117);
    root = balanceTree(root);
    printf("AVL Level Order: ");
    printLevelOrder(root);
    printf("\n");
    return 0;
}