#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Struktur untuk Node Pohon
struct Node {
    string data;
    Node *left, *right, *parent;
};

// Fungsi untuk membuat node baru
Node* createNode(const string& data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = newNode->parent = nullptr;
    return newNode;
}

// Fungsi untuk menambahkan node ke dalam pohon
void insertNode(Node*& root, const string& data) {
    if (root == nullptr) {
        root = createNode(data);
    } else {
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (temp->left == nullptr) {
                temp->left = createNode(data);
                temp->left->parent = temp;
                return;
            } else {
                q.push(temp->left);
            }
            if (temp->right == nullptr) {
                temp->right = createNode(data);
                temp->right->parent = temp;
                return;
            } else {
                q.push(temp->right);
            }
        }
    }
}

// Fungsi untuk mencari node dalam pohon
Node* searchNode(Node* root, const string& data) {
    if (root == nullptr || root->data == data) {
        return root;
    }
    Node* found = searchNode(root->left, data);
    if (found == nullptr) {
        found = searchNode(root->right, data);
    }
    return found;
}

// Fungsi untuk menampilkan anak-anak dari node
void displayChildren(Node* node) {
    if (node != nullptr) {
        cout << "Node " << node->data << " memiliki anak-anak: ";
        if (node->left != nullptr) {
            cout << node->left->data << " ";
        }
        if (node->right != nullptr) {
            cout << node->right->data << " ";
        }
        if (node->left == nullptr && node->right == nullptr) {
            cout << "Tidak ada";
        }
        cout << endl;
    } else {
        cout << "Node tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan semua keturunan dari node
void displayDescendants(Node* node) {
    if (node != nullptr) {
        queue<Node*> q;
        q.push(node);
        cout << "Keturunan dari node " << node->data << ": ";
        bool hasDescendants = false;
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            if (temp != node) {
                cout << temp->data << " ";
                hasDescendants = true;
            }
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
        if (!hasDescendants) {
            cout << "Tidak ada";
        }
        cout << endl;
    } else {
        cout << "Node tidak ditemukan." << endl;
    }
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Tambah Node\n";
    cout << "2. Tampilkan Anak-anak dari Node\n";
    cout << "3. Tampilkan Keturunan dari Node\n";
    cout << "4. Keluar\n";
    cout << "Pilih opsi: ";
}

int main() {
    Node* root = nullptr;
    int choice;
    string data, parentData;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Mengabaikan karakter newline setelah memasukkan pilihan
        switch (choice) {
            case 1:
                cout << "Masukkan data node baru: ";
                getline(cin, data);
                insertNode(root, data);
                break;
            case 2:
                cout << "Masukkan data node untuk menampilkan anak-anaknya: ";
                getline(cin, data);
                displayChildren(searchNode(root, data));
                break;
            case 3:
                cout << "Masukkan data node untuk menampilkan keturunannya: ";
                getline(cin, data);
                displayDescendants(searchNode(root, data));
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
