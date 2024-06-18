#include <iostream>
using namespace std;

struct Node
{
    string nim;
    string nama;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void init()
{
    head = NULL;
    tail = NULL;
}

bool isEmpty()
{
    return head == NULL;
}

void insertDepan(string nama, string nim)
{
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

void insertBelakang(string nama, string nim)
{
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty())
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

int hitungList()
{
    Node *current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void insertTengah(string nama, string nim, int posisi)
{
    if (posisi < 1 || posisi > hitungList() + 1)
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        insertDepan(nama, nim);
    }
    else if (posisi == hitungList() + 1)
    {
        insertBelakang(nama, nim);
    }
    else
    {
        Node *baru = new Node();
        baru->nama = nama;
        baru->nim = nim;
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

void hapusDepan()
{
    if (!isEmpty())
    {
        Node *hapus = head;
        head = head->next;
        delete hapus;
        if (head == NULL)
            tail = NULL;
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void hapusBelakang()
{
    if (!isEmpty())
    {
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
        }
        else
        {
            Node *bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            delete tail;
            tail = bantu;
            tail->next = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void hapusTengah(int posisi)
{
    if (isEmpty() || posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan atau list kosong" << endl;
    }
    else if (posisi == 1)
    {
        hapusDepan();
    }
    else if (posisi == hitungList())
    {
        hapusBelakang();
    }
    else
    {
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; ++nomor)
        {
            bantu = bantu->next;
        }
        Node *hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

void clearList()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *hapus = current;
        current = current->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

void ubahDepan(string nama, string nim)
{
    if (!isEmpty())
    {
        head->nama = nama;
        head->nim = nim;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

void ubahTengah(string nama, string nim, int posisi)
{
    if (isEmpty() || posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan atau list kosong" << endl;
    }
    else
    {
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi; ++nomor)
        {
            bantu = bantu->next;
        }
        bantu->nama = nama;
        bantu->nim = nim;
    }
}

void ubahBelakang(string nama, string nim)
{
    if (!isEmpty())
    {
        tail->nama = nama;
        tail->nim = nim;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
void tampil()
{
    if (!isEmpty())
    {
        Node *current = head;
        cout << "\nDATA MAHASISWA\n\nNama\t\tNIM\n";
        while (current != NULL)
        {
            cout << current->nama << "\t\t" << current->nim << endl;
            current = current->next;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    while (true)
    {
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n\n";
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;

        int choice;
        cout << "\npilih Operasi : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string nama_2311102024;
            string nim_2311102024;
            cout << "\n<<< Tambah Depan >>>\n";
            cout << "Masukan Nama : ";
            cin >> nama_2311102024;
            cout << "Masukan Nim  : ";
            cin >> nim_2311102024;
            insertDepan(nama_2311102024, nim_2311102024);
            cout << "\nData telah ditambahkan " << endl;
            break;
        }
        case 2:
        {
            string nama_2311102024;
            string nim_2311102024;
            cout << "\n<<< Tambah Belakang >>>\n";
            cout << "Masukan Nama : ";
            cin >> nama_2311102024;
            cout << "Masukan Nim  : ";
            cin >> nim_2311102024;
            insertBelakang(nama_2311102024, nim_2311102024);
            cout << "\nData telah ditambahkan " << endl;
            break;
        }
        case 3:
        {
            string nama_2311102024;
            string nim_2311102024;
            int posisi_2311102024;
            cout << "\n<<< Tambah Tengah >>>\n";
            cout << "Masukan Nama   : ";
            cin >> nama_2311102024;
            cout << "Masukan Nim    : ";
            cin >> nim_2311102024;
            cout << "Masukan Posisi : ";
            cin >> posisi_2311102024;
            insertTengah(nama_2311102024, nim_2311102024, posisi_2311102024);
            cout << "\nData telah ditambahkan " << endl;
            break;
        }
        case 4:
        {
            string nama_2311102024;
            string nim_2311102024;
            cout << "\n<<< Ubah Depan >>>\n";
            cout << "Masukan Nama : ";
            cin >> nama_2311102024;
            cout << "Masukan Nim  : ";
            cin >> nim_2311102024;
            ubahDepan(nama_2311102024, nim_2311102024);
            cout << "\nData telah diubah " << endl;
            ;
            break;
        }
        case 5:
        {
            string nama_2311102024;
            string nim_2311102024;
            cout << "\n<<< Ubah Belakang >>>\n";
            cout << "Masukan Nama : ";
            cin >> nama_2311102024;
            cout << "Masukan Nim  : ";
            cin >> nim_2311102024;
            ubahBelakang(nama_2311102024, nim_2311102024);
            cout << "\nData telah diubah " << endl;
            break;
        }
        case 6:
        {
            string nama_2311102024;
            string nim_2311102024;
            int posisi_2311102024;
            cout << "\n<<< Ubah Tengah >>>\n";
            cout << "Masukan Nama   : ";
            cin >> nama_2311102024;
            cout << "Masukan Nim    : ";
            cin >> nim_2311102024;
            cout << "Masukan Posisi : ";
            cin >> posisi_2311102024;
            ubahTengah(nama_2311102024, nim_2311102024, posisi_2311102024);
            cout << "\nData telah diubah " << endl;
            break;
        }
        case 7:
            hapusDepan();
            cout << "Data Berhasil dihapus " << endl;
            break;
        case 8:
            hapusBelakang();
            cout << "Data Berhasil dihapus " << endl;
            break;
        case 9:
        {
            int posisi_2311102024;
            cout << "<<< Hapus Tengah >>>\n";
            cout << "Masukkan posisi : ";
            cin >> posisi_2311102024;
            hapusTengah(posisi_2311102024);
            cout << "Data Berhasil dihapus " << endl;
            break;
        }
        case 10:
            clearList();
            break;
        case 11:
            tampil();
            break;
        case 0:
            return 0;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    }
    return 0;
}