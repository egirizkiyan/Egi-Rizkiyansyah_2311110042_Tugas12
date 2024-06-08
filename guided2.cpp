#include <iostream>
using namespace std;

// PROGRAM BINARY TREE

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root, *baru;

// Inisialisasi
void init() {
    root = NULL;
}

// Membuat Node Baru
Pohon* createNode(char data) {
    Pohon* newNode = new Pohon();
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

// Menambahkan Node ke Pohon
void insert(Pohon* &root, char data) {
    if (root == NULL) {
        root = createNode(data);
    } else {
        if (data < root->data) {
            if (root->left == NULL) {
                root->left = createNode(data);
                root->left->parent = root;
            } else {
                insert(root->left, data);
            }
        } else {
            if (root->right == NULL) {
                root->right = createNode(data);
                root->right->parent = root;
            } else {
                insert(root->right, data);
            }
        }
    }
}

// Mencari Node
bool search(Pohon* root, char data) {
    if (root == NULL) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Fungsi Utama
int main() {
    init();
    
    insert(root, 'F');
    insert(root, 'B');
    insert(root, 'G');
    insert(root, 'A');
    insert(root, 'D');
    insert(root, 'I');
    insert(root, 'C');
    insert(root, 'E');
    insert(root, 'H');
    
    char cari = 'E';
    if (search(root, cari)) {
        cout << "Node dengan data " << cari << " ditemukan." << endl;
    } else {
        cout << "Node dengan data " << cari << " tidak ditemukan." << endl;
    }
    
    return 0;
}
