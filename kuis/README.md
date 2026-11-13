Nama : Billiam Agsa Tatema Hia
NIM : 251401110
KOM : B
Lab : Struktur data
Link yt : https://youtu.be/CJ1vek7XM_0 

Deskripsi Program
 1. Sistem Pengelolaan Nilai Mahasiswa (soal1.cpp)

Program untuk mengelola data mahasiswa yang terdiri dari NIM, nama, dan nilai.

Dynamic Array:menyimpan kumpulan nilai mahasiswa
Single Linked List:menyimpan data mahasiswa (NIM, nama, nilai)
- Insertion Sort mengurutkan nilai dari terkecil hingga terbesar
- Linear Search mencari mahasiswa berdasarkan NIM
-Binary Search mencari nilai tertentu setelah data diurutkan

2. Sistem Antrian dan Pengelolaan Buku Perpustakaan (2.cpp)

Program sederhana untuk membantu pengelolaan peminjaman dan pengembalian buku.

- Queue (FIFO)* mengatur antrian mahasiswa yang ingin meminjam buku
- Stack (LIFO) menyimpan riwayat pengembalian buku
- Binary Search Tree (BST) menyimpan ID buku
- Fitur pencarian ID buku sekaligus traversal Pre-Order, In-Order, dan Post-Order
- Menampilkan proses antrian, riwayat pengembalian, dan isi BST

3. Sistem Pencarian Rute di Lingkungan Kampus (3.cpp)

Program pencarian rute antar lokasi di lingkungan kampus menggunakan graph dengan enam vertex: A, B, C, D, E, dan F.

- Adjacency Matrix merepresentasikan hubungan antar lokasi beserta bobot jarak
- BFS dan DFS untuk menelusuri graf
- Dijkstra untuk mencari jarak terpendek dari vertex awal ke vertex tujuan
- Menampilkan rute yang dilalui beserta total jaraknya
- Pilihan vertex awal dan tujuan oleh pengguna

4. Sistem Pengelolaan Data Mahasiswa Menggunakan Hash Table (4.cpp)

Program penyimpanan data mahasiswa dengan NIM sebagai key dan nama sebagai value.

- Hash Table dengan ukuran tabel 20
- Metode penanganan collision: Double Hashing
- Fungsi hash:
  - Hash1(key) = key % 20
  - Hash2(key) = 19 - (key % 19)
- Fitur Insert, Search, Remove, dan Display
- Diuji dengan minimal belas data mahasiswa, mencakup kondisi collision dan penghapusan data

Struktur Folder
kuis/
├── README.md
├── 1.cpp
├── 1.exe
├── 2.cpp
├── 2.exe
├── 3.cpp
├── 3.exe
├── 4.cpp
└── 1.exe
