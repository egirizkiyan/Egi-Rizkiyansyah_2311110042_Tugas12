# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Egi Rizkiyansyah</p>

## Dasar Teori
1. Pengertian Graf
Graf adalah struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node atau vertex dan sambungan antara node tersebut dalam bentuk sisi atau edge. Graf didefinisikan secara matematis sebagai pasangan terurut 
𝐺=(𝑉,𝐸),dimana:

- V adalah himpunan simpul atau vertex.
- E adalah himpunan sisi atau edge yang menghubungkan pasangan simpul.

2. Jenis-jenis Graf
Graf dapat dibagi menjadi beberapa jenis berdasarkan sifat dan karakteristiknya:

- Graf Tak Berarah (Undirected Graph): Sebuah graf di mana tepi tidak memiliki arah. Jika ada tepi antara simpul u dan 𝑣, maka 𝑢 dapat dihubungkan ke 𝑣 dan sebaliknya.

- Graf Berarah (Directed Graph): Sebuah graf di mana setiap tepi memiliki arah tertentu. Jika ada tepi dari u ke v, maka tidak berarti ada tepi dari v ke u.

- Graf Berbobot (Weighted Graph): Graf di mana setiap tepi memiliki bobot atau nilai tertentu.

- Graf Tidak Berbobot (Unweighted Graph): Graf di mana semua tepi dianggap memiliki bobot yang sama.

3. Representasi Graf
Graf dapat direpresentasikan dalam berbagai cara:

- Matriks Adjacency: Matriks persegi dengan ukuran ∣V∣×∣V∣ dimana setiap elemen a[i][j] menunjukkan ada atau tidaknya tepi antara simpul 𝑖 dan j.

- Daftar Adjacency: Koleksi daftar dimana setiap daftar berisi simpul-simpul yang terhubung dengan simpul tertentu.

4. Operasi pada Graf
Beberapa operasi dasar yang dapat dilakukan pada graf meliputi:

- Penambahan Simpul (Vertex Addition): Menambah simpul baru ke dalam graf.

- Penambahan Sisi (Edge Addition): Menambah sisi baru yang menghubungkan dua simpul.

- Penghapusan Simpul (Vertex Deletion): Menghapus simpul dari graf.

- Penghapusan Sisi (Edge Deletion): - 

- Menghapus sisi yang menghubungkan dua simpul.

5. Pengertian Tree
Tree adalah jenis khusus dari graf yang merupakan graf tak berarah yang terhubung dan tidak mengandung siklus. Tree didefinisikan sebagai graf 
T=(V,E) dengan karakteristik berikut:

- Terhubung (Connected): Setiap pasangan simpul dalam tree terhubung oleh jalur unik.

- Acyclic: Tree tidak mengandung siklus.

6. Jenis-jenis Tree

- Binary Tree: Setiap simpul memiliki paling banyak dua anak.

- Binary Search Tree (BST): Binary tree di mana setiap simpul memiliki nilai yang lebih besar dari semua nilai di subpohon kiri dan lebih kecil dari semua nilai di subpohon kanan.

- AVL Tree: Binary search tree yang mempertahankan keseimbangan tinggi di setiap simpul.

- Heap: Tree yang memenuhi sifat heap, dimana nilai setiap simpul adalah lebih besar (max heap) atau lebih kecil (min heap) daripada nilai anak-anaknya.

7. Operasi pada Tree
Beberapa operasi dasar yang dapat dilakukan pada tree meliputi:

- Penelusuran Pre-order (Pre-order Traversal): Kunjungi akar, kemudian subpohon kiri, lalu subpohon kanan.

- Penelusuran In-order (In-order Traversal): Kunjungi subpohon kiri, kemudian akar, lalu subpohon kanan.

- Penelusuran Post-order (Post-order Traversal): Kunjungi subpohon kiri, kemudian subpohon kanan, lalu akar.

- Penelusuran Level-order (Level-order Traversal): Kunjungi simpul-simpul pada setiap tingkat secara berurutan.

8. Aplikasi Graf dan Tree
Graf dan tree memiliki banyak aplikasi dalam berbagai bidang seperti:

- Graf: Jaringan komputer, peta jalan, jaringan sosial, analisis jaringan, dan banyak lagi.

- Tree: Basis data (misalnya, indeks B-tree), pemrograman kompilasi (pohon parse), struktur data (heap, binary search tree), dan representasi hirarkis lainnya.

Graf dan tree merupakan struktur data yang fundamental dan sangat penting dalam ilmu komputer serta matematika terapan, yang digunakan untuk memecahkan berbagai masalah yang melibatkan hubungan dan hirarki antar objek.


## Guided 

### 1. [Program Graph]

```C++
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {"Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogjakarta"};
int busur[7][7] =
{
   {0, 7, 8, 0, 0, 0, 0},
   {0, 0, 5, 0, 0, 15, 0},
   {0, 6, 0, 0, 5, 0, 0},
   {0, 5, 0, 0, 2, 4, 0},
   {23, 0, 0, 10, 0, 0, 8},
   {0, 0, 0, 0, 7, 0, 3},
   {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph()
{
    for(int baris = 0; baris < 7; baris++){
        for(int kolom = 0; kolom < 7; kolom++){
            cout << setw(2) << busur[baris][kolom] << " ";
        }
        cout << endl;
    }
}

int main()
{
    tampilGraph();
    return 0;
}

```
#### Full code Screenshot:
![Screenshot 2024-06-09 003630](https://github.com/egirizkiyan/egi-telkom/assets/162097461/3daa0f64-2a25-4c90-be4c-6fd95c7a396e)

#### Output:
![Screenshot 2024-06-09 003746](https://github.com/egirizkiyan/egi-telkom/assets/162097461/df578ec4-60e0-44f7-9743-de1fc97b3960)


Kesimpulan dari kode tersebut adalah:
Graf ini merepresentasikan kota-kota di Jawa Barat dan sekitarnya dengan jarak yang dinyatakan dalam matriks adjacency. Struktur ini dapat digunakan untuk menganalisis rute optimal, konektivitas antar kota, dan berbagai masalah lainnya yang terkait dengan jaringan jalan atau transportasi di wilayah ini.

### 2. [Program three]

```C++
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

```
#### Full code Screenshot:
![Screenshot 2024-06-09 004334](https://github.com/egirizkiyan/egi-telkom/assets/162097461/c686722b-5b5d-4a5b-ac87-2463f0fa22e9)

#### Output:
![Screenshot 2024-06-09 004438](https://github.com/egirizkiyan/egi-telkom/assets/162097461/963a6a7f-ff8b-4784-89e0-bc0de2085939)

Kesimpulan dari kode tersebut adalah: 
Kode ini mendemonstrasikan dasar dari operasi pohon biner: inisialisasi, penambahan node (insert), dan pencarian node (search). Pohon biner ini adalah pohon biner pencarian (binary search tree), di mana setiap simpul kiri memiliki nilai lebih kecil dari induknya, dan setiap simpul kanan memiliki nilai lebih besar dari induknya. Implementasi ini juga mencakup pointer parent, meskipun tidak digunakan dalam operasi yang ada saat ini.

## Unguided 
### 1. [Soal]

```C++
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void displayMatrix(vector<vector<int>>& matrix, vector<string>& cities) {
    int V = cities.size();
    cout << setw(12) << " ";
    for (int i = 0; i < V; i++) {
        cout << setw(12) << cities[i];
    }
    cout << endl;

    for (int i = 0; i < V; i++) {
        cout << setw(12) << cities[i];
        for (int j = 0; j < V; j++) {
            cout << setw(12) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    
    cout << "NIM: 2311110042" << endl << endl;
    
    int V;
    cout << "Silakan masukan jumlah simpul: 2 ";
    cin >> V;

    vector<string> cities(V);
    cin.ignore(); 
    for (int i = 0; i < V; i++) {
        cout << "Silakan masukan nama simpul wangon" << i + 1 << ": ";
        getline(cin, cities[i]);
    }

    vector<vector<int>> matrix(V, vector<int>(V, 0));

    cout << "Silakan masukan bobot antar simpul\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << cities[i] << "--> " << cities[j] << " = ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nAdjacency Matrix:\n";
    displayMatrix(matrix, cities);

    return 0;
}
```
#### Output:
![Screenshot 2024-06-09 014411](https://github.com/egirizkiyan/egi-telkom/assets/162097461/0a91352d-515c-436f-96c2-00df16458bfd)


#### Full code Screenshot:
![Screenshot 2024-06-09 014128](https://github.com/egirizkiyan/egi-telkom/assets/162097461/5bcf3183-d746-427d-8bc6-5f337fac38d8)


Kode tersebut 
- Interaksi Pengguna: Program ini interaktif, di mana pengguna memasukkan jumlah simpul, nama simpul, dan bobot antar simpul.

- Representasi Graf: Kode ini membangun representasi graf dalam bentuk adjacency matrix, yang berguna untuk berbagai analisis graf seperti pencarian jalur terpendek, deteksi siklus, dll.

- Fleksibilitas: Program ini fleksibel dan dapat digunakan untuk berbagai ukuran graf sesuai dengan input pengguna.

Manfaat dari Program

Program ini memberikan cara yang sederhana dan efisien untuk membangun dan menampilkan representasi graf dalam bentuk adjacency matrix, yang merupakan dasar penting dalam banyak algoritma graf dan aplikasi dalam ilmu komputer serta matematika terapan.

## Unguided 
### 2. [Soal]

```C++
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

```
#### Output:
![Screenshot 2024-06-09 015043](https://github.com/egirizkiyan/egi-telkom/assets/162097461/4b9ec037-3be1-42c4-bb5f-d8bc58d2596e)



#### Full code Screenshot:
![Screenshot 2024-06-09 014850](https://github.com/egirizkiyan/egi-telkom/assets/162097461/89754ea0-4412-4d66-ae55-37b3144d9c3e)

## kode di atas
Program ini menyediakan cara interaktif untuk bekerja dengan pohon biner. Dengan menambahkan node, menampilkan anak-anak, dan menampilkan keturunan, pengguna dapat dengan mudah memahami dan mengelola struktur pohon biner. Program ini menggunakan penelusuran level-order untuk penambahan node dan penelusuran keturunan, yang memastikan bahwa node ditambahkan secara merata ke pohon.


## Kesimpulan
Kesimpulan dari Kode yang Diberikan
Program Adjacency Matrix

- Tujuan: Menampilkan adjacency matrix dari sebuah graf yang menggambarkan hubungan antar kota dengan bobot tertentu.

- Kesimpulan: Program ini berhasil menampilkan adjacency matrix yang menunjukkan bobot antar simpul dengan format yang rapi. Setiap simpul dan bobot antar simpul ditampilkan dengan jelas.

Program Binary Tree

- Tujuan: Membuat, menyisipkan, dan mencari node dalam sebuah pohon biner.

- Kesimpulan: Program ini berhasil membuat pohon biner, menambahkan node sesuai dengan aturan pohon biner, dan mencari node tertentu dalam pohon. Node yang ditemukan ditampilkan dengan pesan yang sesuai.
Program Interaktif Adjacency Matrix

- Tujuan: Mengizinkan pengguna untuk memasukkan jumlah simpul, nama simpul, dan bobot antar simpul untuk membentuk adjacency matrix secara interaktif.

- Kesimpulan: Program ini menyediakan antarmuka interaktif yang fleksibel untuk membuat adjacency matrix sesuai dengan input pengguna. Pengguna dapat memasukkan nama simpul dan bobot antar simpul, dan program akan menampilkan adjacency matrix berdasarkan input tersebut.

Program Binary Tree dengan Menu Interaktif

- Tujuan: Menyediakan antarmuka menu interaktif untuk menambah node, menampilkan anak-anak dari node tertentu, dan menampilkan keturunan dari node tertentu dalam pohon biner.

- Kesimpulan: Program ini berhasil menyediakan antarmuka interaktif untuk manipulasi pohon biner. Pengguna dapat menambah node baru, menampilkan anak-anak dari node tertentu, dan menampilkan keturunan dari node tertentu. Program ini mempermudah interaksi pengguna dengan pohon biner melalui menu yang jelas dan intuitif

## Referensi
[1] Novi Anisa. (2021). Penggunaan variabel array dalam pengolahan data. Digilib Unila. [PDF] penggunaan variabel array dalam pengolahan data - Digilib Unila
[2] "Introduction to Algorithms" oleh Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, dan Clifford Stein
Tahun Terbit: 1990 (Edisi Pertama)
[3] Novi Anisa(2020, September 18). Belajar Python: Mengenal Array pada Bahasa Pemrograman Python. DQLab.
[4]"The Art of Computer Programming" oleh Donald E. Knuth
Tahun Terbit: 1968 (Volume 1, Edisi Pertama)