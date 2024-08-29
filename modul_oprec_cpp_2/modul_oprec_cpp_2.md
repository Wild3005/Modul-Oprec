# Dasar Pemograman C++ OOP (Part2)
### -> Struc
**struc** dalam C++ adalah sebuah kata kunci yang digunakan untuk mendefinisikan sebuah struktur data yang dapat mengelompokkan beberapa variabel di bawah satu nama. Variabel-variabel tersebut, yang disebut sebagai anggota atau member dari struktur, bisa memiliki tipe data yang berbeda-beda.

contoh penggunaan:
```C++
#include <iostream>
using namespace std;

// Definisi struct
struct Mahasiswa {
    string nama;
    int umur;
    float IPK;
};

int main() {
    // Deklarasi variabel bertipe struct Mahasiswa
    Mahasiswa mhs;

    // Mengisi nilai ke dalam anggota struct
    mhs.nama = "Budi";
    mhs.umur = 20;
    mhs.IPK = 3.75;

    // Mengakses dan menampilkan nilai dari anggota struct
    cout << "Nama: " << mhs.nama << endl;
    cout << "Umur: " << mhs.umur << endl;
    cout << "IPK: " << mhs.IPK << endl;

    return 0;
}
```
### -> Class OOP
**class** dalam C++ adalah sebuah blueprint atau cetak biru untuk membuat objek dalam pemrograman berorientasi objek (OOP). class memungkinkan Anda untuk mendefinisikan tipe data yang kompleks dengan menggabungkan data (atribut) dan fungsi (metode) di dalamnya.

sederhananya, jika Anda hanya perlu mengelompokkan beberapa variabel bersama-sama, gunakan **struct**. Jika Anda perlu membuat tipe data yang lebih kompleks dengan logika dan kontrol akses, gunakan **class**.

Didalam class terdapat:
**public**, **private**, dan **protected** ketiganya disebut access specifiers atau spesifikator akses.
##### Public
jika anda membuat fungsi atau variabel yang dapat diakses dari luar class maka anda harus mengguakan **public**
berikut adalah contoh penggunaannya:
```C++
#include <iostream>
using namespace std;

// Definisi class
class Mahasiswa {
public:
    string nama;
    int umur;
    float IPK;

    // Metode untuk menampilkan informasi
    void tampilkanInfo() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << endl;
        cout << "IPK: " << IPK << endl;
    }
};

int main() {
    // Membuat objek dari class Mahasiswa
    Mahasiswa mhs;

    // Mengisi nilai ke dalam atribut
    mhs.nama = "Budi";
    mhs.umur = 20;
    mhs.IPK = 3.75;

    // Memanggil metode untuk menampilkan informasi
    mhs.tampilkanInfo();

    return 0;
}
```
##### Public dan Private
jika anda tidak ingin fungsi atau variabel yang ada dalam class tidak ingin diakses dari luar class maka anda dapat menggunakan **private**
berikut contoh penggunaannya:
```C++
#include <iostream>
using namespace std;

// Definisi class
class Mahasiswa {
private:
    // Atribut bersifat private, hanya bisa diakses dari dalam class
    string nama;
    int umur;
    float IPK;

public:
    // Metode untuk mengisi nilai atribut, dapat diakses dari luar class
    void setNama(string n) {
        nama = n;
    }

    void setUmur(int u) {
        umur = u;
    }

    void setIPK(float i) {
        IPK = i;
    }

    // Metode untuk menampilkan informasi, dapat diakses dari luar class
    void tampilkanInfo() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << endl;
        cout << "IPK: " << IPK << endl;
    }
};

int main() {
    // Membuat objek dari class Mahasiswa
    Mahasiswa mhs;

    // Mengisi nilai ke dalam atribut melalui metode public
    mhs.setNama("Budi");
    mhs.setUmur(20);
    mhs.setIPK(3.75);

    // Memanggil metode untuk menampilkan informasi
    mhs.tampilkanInfo();

    return 0;
}
```
##### Protected
Penggunaan **protected** memberikan akses yang lebih luas daripada private, tetapi masih membatasi akses dibandingkan dengan public. protected sering digunakan dalam konteks pewarisan untuk memberikan akses kepada class turunan tetapi tetap menjaga keamanan dari akses langsung dari luar class
berikut contoh penggunaannya:
```C++
#include <iostream>
using namespace std;

// Definisi class dasar
class Mahasiswa {
private:
    // Atribut bersifat private, hanya bisa diakses dari dalam class ini
    string nama;

protected:
    // Atribut bersifat protected, bisa diakses dari dalam class ini dan class turunan
    int umur;

public:
    // Atribut bersifat public, dapat diakses dari luar class
    float IPK;

    // Metode untuk mengisi nilai atribut nama, hanya bisa diakses melalui metode ini
    void setNama(string n) {
        nama = n;
    }

    // Metode untuk menampilkan nama, umur, dan IPK
    void tampilkanInfo() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << endl;
        cout << "IPK: " << IPK << endl;
    }
};

// Definisi class turunan
class MahasiswaLulus : public Mahasiswa {
private:
    string tahunLulus;

public:
    // Metode untuk mengisi tahun lulus
    void setTahunLulus(string tahun) {
        tahunLulus = tahun;
    }

    // Metode untuk menampilkan informasi kelulusan
    void tampilkanInfoLulus() {
        // Dapat mengakses umur karena umur adalah protected di class dasar
        cout << "Umur saat lulus: " << umur << endl;
        cout << "Tahun Lulus: " << tahunLulus << endl;
    }
};

int main() {
    // Membuat objek dari class MahasiswaLulus
    MahasiswaLulus mhs;

    // Mengisi nilai ke dalam atribut melalui metode public
    mhs.setNama("Budi");
    mhs.umur = 22; // Atribut umur dapat diakses karena protected dan ini adalah class turunan
    mhs.IPK = 3.75;
    mhs.setTahunLulus("2024");

    // Menampilkan informasi mahasiswa
    mhs.tampilkanInfo();
    mhs.tampilkanInfoLulus();

    return 0;
}
```
##### Constructor

```C++
#include <iostream>
using namespace std;

// Definisi class
class Mahasiswa {
public:
    string nama;
    int umur;
    float IPK;

    // Constructor tanpa parameter (default constructor)
    Mahasiswa() {
        nama = "Tidak diketahui";
        umur = -1;
        IPK = -1.0;
    }

    // Constructor dengan satu parameter (nama saja)
    Mahasiswa(string n) {
        nama = n;
        umur = -1;
        IPK = -1.0;
    }

    // Constructor dengan tiga parameter (nama, umur, IPK)
    Mahasiswa(string n, int u, float i) {
        nama = n;
        umur = u;
        IPK = i;
    }

    // Metode untuk menampilkan informasi
    void tampilkanInfo() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << (umur == -1 ? "Tidak diketahui" : to_string(umur)) << endl;
        cout << "IPK: " << (IPK == -1.0 ? "Tidak diketahui" : to_string(IPK)) << endl;
    }
};

int main() {
    // Membuat objek dengan constructor tanpa parameter
    Mahasiswa mhs1;
    mhs1.tampilkanInfo();

    cout << endl;

    // Membuat objek dengan constructor yang hanya menerima nama
    Mahasiswa mhs2("Budi");
    mhs2.tampilkanInfo();

    cout << endl;

    // Membuat objek dengan constructor yang menerima nama, umur, dan IPK
    Mahasiswa mhs3("Ani", 22, 3.90);
    mhs3.tampilkanInfo();

    return 0;
}
```
##### Inheritance
Inheritance sederhananya ada class turunan yang mewarisi atribut dari class sebelumnya.
pada contoh dinawah ini ada **Base Clas** yaitu *Mahasiswa* dan **derived class** yaitu *MahasiswaLulus*.
Berikut contohnya:
```C++
#include <iostream>
using namespace std;

// Definisi class Mahasiswa (Base Class)
class Mahasiswa {
public:
    string nama;
    int umur;
    float IPK;

    // Constructor untuk menginisialisasi data mahasiswa
    Mahasiswa(string n, int u, float i) : nama(n), umur(u), IPK(i) {}

    // Metode untuk menampilkan informasi
    void tampilkanInfo() {
        cout << "Nama: " << nama << endl;
        cout << "Umur: " << umur << endl;
        cout << "IPK: " << IPK << endl;
    }
};

// Definisi class MahasiswaLulus (Derived Class)
class MahasiswaLulus : public Mahasiswa {
public:
    string tahunLulus;

    // Constructor untuk menginisialisasi data mahasiswa lulus
    MahasiswaLulus(string n, int u, float i, string t) : Mahasiswa(n, u, i), tahunLulus(t) {}

    // Metode untuk menampilkan informasi mahasiswa lulus
    void tampilkanInfoLulus() {
        tampilkanInfo();  // Memanggil metode dari class Mahasiswa
        cout << "Tahun Lulus: " << tahunLulus << endl;
    }
};

int main() {
    // Membuat objek dari class MahasiswaLulus
    MahasiswaLulus mhs("Budi", 22, 3.75, "2024");

    // Memanggil metode untuk menampilkan informasi mahasiswa lulus
    mhs.tampilkanInfoLulus();

    return 0;
}
```
### -> (Tambahan) Membuat File Header
Anda sekarang bisa membuat Header sendiri yeaaay :D
ikutlah langkah langkah dibawah
> Buatlah file header (.hpp): aspek penting yang harus ada seperti:
```C++
#ifndef OPERASI_HPP
#define OPERASI_HPP
(disini class)
#endif
```
> pada source file (.cpp): anda tambah alamat file header diatas menggunakan include, contohnya
```C++
#include"(direktori file header kalian).hpp"
#include<iostream>
using namespace std;
(program seperti biasanya)
```
setelah itu karena dalm kasus tertentu cara mengompile menggunakan terminal maka tuliskan:
```sh
g++ (namafile).cpp -o (nama keluaran)
```
terkadang tidak bisa gunakan perintah
```sh
g++ -I(direktori header kalian).hpp (direktori file program kalian).cpp -o (nama keluaran)
```
selengkapnya anda liat pada folder include sebagai menyimpan file header dan src atau source sebagai penyimpan file program anda:D

![Meme Cuy](meme.png)


