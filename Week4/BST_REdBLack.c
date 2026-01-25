#include <stdio.h>
#include <stdlib.h>

enum Color { RED, BLACK };

struct Node {
    int data;
    enum Color color;
    struct Node *left, *right, *parent;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = temp->parent = NULL;
    temp->color = RED;
    return temp;
}

void rotateLeft(struct Node** root, struct Node* x) {
    struct Node* y = x->right;
    x->right = y->left;
    if (y->left != NULL) y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) *root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rotateRight(struct Node** root, struct Node* y) {
    struct Node* x = y->left;
    y->left = x->right;
    if (x->right != NULL) x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL) *root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;
    x->right = y;
    y->parent = x;
}

void fixViolation(struct Node** root, struct Node* z) {
    while (z != *root && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            struct Node* y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rotateLeft(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(root, z->parent->parent);
            }
        } else {
            struct Node* y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rotateRight(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

int height(struct Node* node) {
    if (node == NULL) return 0;
    int l = height(node->left);
    int r = height(node->right);
    return (l > r ? l : r) + 1;
}

void printGivenLevel(struct Node* root, int level) {
    if (root == NULL) return;
    if (level == 1) printf("%d ", root->data);
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrder(struct Node* root) {
    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i);
        printf("| ");
    }
}

int main() {
    printf("CH.SC.U4CSE24113\n");
    struct Node* root = newNode(157); root->color = BLACK;

    struct Node* n110 = newNode(110); root->left = n110; n110->parent = root;
    struct Node* n147 = newNode(147); n110->right = n147; n147->parent = n110;

    struct Node* n122 = newNode(122); n147->left = n122; n122->parent = n147;
    struct Node* n149 = newNode(149); n147->right = n149; n149->parent = n147;

    struct Node* n111 = newNode(111); n122->left = n111; n111->parent = n122;
    struct Node* n141 = newNode(141); n122->right = n141; n141->parent = n122;
    struct Node* n151 = newNode(151); n149->right = n151; n151->parent = n149;

    struct Node* n112 = newNode(112); n111->right = n112; n112->parent = n111;
    struct Node* n123 = newNode(123); n141->left = n123; n123->parent = n141;

    struct Node* n117 = newNode(117); n112->left = n117; n117->parent = n112;
    struct Node* n133 = newNode(133); n123->right = n133; n133->parent = n123;

    fixViolation(&root, n147);
    fixViolation(&root, n111);
    fixViolation(&root, n141);
    fixViolation(&root, n151);
    fixViolation(&root, n117);
    fixViolation(&root, n133);

    printf("Red-Black Level Order: ");
    printLevelOrder(root);
    printf("\n");
    return 0;
}