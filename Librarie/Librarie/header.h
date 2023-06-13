/* Va rog sa introduceti fara spatii, pentru ca in fisier spatiu se considera ca un delimitator */


#ifndef MYLIBRARYFUNCTIONS_H
#define MYLIBRARYFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
//#include <Windows.h>
#include <algorithm>



using namespace std;
struct Book {
    string titlu;
    string autor;
    int an;
    string limba;
    string tema;
    float pret;
    int copii;
    int supplier_id;
};

struct Supplier {
    int id;
    string nume;
    string adresa;
    string phone;
};


void arataBooks() {
    ifstream file("Books.txt");

    Book book;
    while (file >> book.titlu >> book.autor >> book.an >> book.limba >> book.tema >> book.pret >> book.copii >> book.supplier_id) {
    cout << "Titlu: " << book.titlu << endl;
    cout << "Autor: " << book.autor << endl;
    cout << "An: " << book.an << endl;
    cout << "Limba: " << book.limba << endl;
    cout << "Tema: " << book.tema << endl;
    cout << "Pret: " << book.pret << endl;
    cout << "Copii: " << book.copii << endl;
    cout << "Supplier ID: " << book.supplier_id << endl << endl;
    }

file.close();
}





void arataSuppliers() {
    ifstream fsup("Supplier.txt");


    Supplier supplier;

    while (fsup >> supplier.id >> supplier.nume >> supplier.adresa >> supplier.phone) {
    cout << "ID: " << supplier.id << endl;
    cout << "Nume: " << supplier.nume << endl;
    cout << "Adresa: " << supplier.adresa << endl;
    cout << "Phone: " << supplier.phone << endl;
    cout << endl;
    }

fsup.close();
}

void adaogaBook() {
    ofstream file("Books.txt", ios::app);

    Book book;
    cout << "Introdu titlul cartii (Va rog fara spatii, doar cu _ ): ";

    getline(cin, book.titlu);
    cout << "Introdu autorul cartii (Va rog fara spatii, doar cu _ ): ";

    getline(cin, book.autor);
    cout << "Adaoga anul publicarii cartii: ";

    cin >> book.an;
    cout << "Introdu in ce limba a fost scrisa cartea: ";

    cin.ignore();
    getline(cin, book.limba);
    cout << "Introdu tipul cartii: ";

    getline(cin, book.tema);
    cout << "Introdu pretul cartii: ";

    cin >> book.pret;
    cout << "Introdu numarul de copii: ";

    cin >> book.copii;
    cout << "Introdu supplier ID: ";

    cin >> book.supplier_id;
    file << book.titlu << " " << book.autor << " " << book.an << " " << book.limba << " " << book.tema << " " << book.pret << " " << book.copii << " " << book.supplier_id << endl;
    file.close();
}

void adaogaSupplier() {
    ofstream file("Supplier.txt", ios::app);
    Supplier supplier;

    cout << "Introdu id-ul supplierului: ";
    cin >> supplier.id;

    cout << "Introdu numele supplierului: ";
    cin.ignore();
    getline(cin, supplier.nume);

    cout << "Introdu adresa supplierului: ";
    getline(cin, supplier.adresa);

    cout << "Introdu numarul de telefon a supplierului: ";
    getline(cin, supplier.phone);

    file << supplier.id << " " << supplier.nume << " " << supplier.adresa << " " << supplier.phone << endl;
    file.close();
}

//Nustiu cum sa fac fara temporar
void excludeBook() {
    string titlu;

    cout << "Introdu titlul cartii pe care vrei sa-l excluzi: ";
    getline(cin, titlu);

    ifstream file("Books.txt");
    ofstream temp("temp.txt");

    Book book;
    bool gasit = false;
    while (file >> book.titlu >> book.autor >> book.an >> book.limba >> book.tema >> book.pret >> book.copii >> book.supplier_id) {

        if (book.titlu != titlu) {
            temp << book.titlu << " " << book.autor << " " << book.an << " " << book.limba << " " << book.tema
                 << " " << book.pret << " " << book.copii << " " << book.supplier_id << endl;
        } else {
            gasit = true;
        }

    }

    file.close();
    temp.close();

    if (!gasit) {
        cout << "Cartea nu a fost gasita!" << endl;
        remove("temp.txt");
        return;
    }

    ofstream outFile("Books.txt");
    ifstream tempFile("temp.txt");

    outFile << tempFile.rdbuf();
    outFile.close();
    tempFile.close();

    remove("temp.txt");
}


void excludeSupplier() {
    int id;

    cout << "Introud id-ul supplierului pe care vrei sa-l excluzi: ";
    cin >> id;

    ifstream file("Supplier.txt");
    ofstream temp("temp.txt");

    Supplier supplier;
    bool gasit = false;

    while (file >> supplier.id >> supplier.nume >> supplier.adresa >> supplier.phone) {

        if (supplier.id != id) {
            temp << supplier.id << " " << supplier.nume << " " << supplier.adresa << " " << supplier.phone << endl;
        } else {
            gasit = true;
        }

    }

    file.close();
    temp.close();

    if (!gasit) {
        cout << "Supplier nu a fost gasit!" << endl;
        remove("temp.txt");
        return;
    }

    ofstream outFile("Supplier.txt");
    ifstream tempFile("temp.txt");

    outFile << tempFile.rdbuf();

    outFile.close();
    tempFile.close();

    remove("temp.txt");
}


void updateBook() {
    string titlu;
    cout << "Introdu titlu cartii pe care vrei sa-i schimbi datele: ";
    getline(cin, titlu);

    ifstream file("Books.txt");
    ofstream temp("temp.txt");

    Book book;
    bool gasit = false;
    while (file >> book.titlu >> book.autor >> book.an >> book.limba >> book.tema >> book.pret >> book.copii >> book.supplier_id) {
        if (book.titlu == titlu) {
            gasit = true;
            cout << "Introdu noul autor a cartii: ";
            getline(cin, book.autor);
            cout << "Introdu noul an al cartii: ";
            cin >> book.an;
            cin.ignore();
            cout << "Introdu o noua limba a cartii: ";
            getline(cin, book.limba);
            cout << "Introdu tema noua a cartii: ";
            getline(cin, book.tema);
            cout << "Introdu noul pret al cartii: ";
            cin >> book.pret;
            cout << "Introdu numarul de copii a cartii: ";
            cin >> book.copii;
            cout << "Introdu noul supplier_id a cartii: ";
            cin >> book.supplier_id;
        }
        temp << book.titlu << " " << book.autor << " " << book.an << " " << book.limba << " " << book.tema << " " << book.pret << " " << book.copii << " " << book.supplier_id << endl;
    }
    file.close();
    temp.close();
    if (!gasit) {
        cout << "Cartea nu a fost gasita" << endl;
        remove("temp.txt");
        return;
    }
    ofstream outFile("Books.txt");
    ifstream tempFile("temp.txt");
    outFile << tempFile.rdbuf();
    outFile.close();
    tempFile.close();
    remove("temp.txt");
}

void updateSupplier() {
    int id;
    cout << "Introdu id-ul supplierului: ";
    cin >> id;
    cin.ignore();

    ifstream file("Supplier.txt");
    ofstream temp("temp.txt");

    Supplier supplier;
    bool gasit = false;
    while (file >> supplier.id >> supplier.nume >> supplier.adresa >> supplier.phone) {
        if (supplier.id == id) {
            gasit = true;
            cout << "Introdu numele nou al supplierului: ";
            getline(cin, supplier.nume);
            cout << "Introdu adresa noua al supplierului: ";
            getline(cin, supplier.adresa);
            cout << "Introdu noul numar de telefon al supplierului: ";
            getline(cin, supplier.phone);
        }
        temp << supplier.id << " " << supplier.nume << " " << supplier.adresa << " " << supplier.phone << endl;
    }
    file.close();
    temp.close();
    if (!gasit) {
        cout << "Supplierul nu a fost gasit: " << endl;
        remove("temp.txt");
        return;
    }
    ofstream outFile("Supplier.txt");
    ifstream tempFile("temp.txt");
    outFile << tempFile.rdbuf();
    outFile.close();
    tempFile.close();
    remove("temp.txt");
}

void creazaLivrare() {
    ifstream supplierFile("Supplier.txt");

    Supplier supplier;

    ofstream livrareFile("Livrare.txt");


    while (supplierFile >> supplier.id >> supplier.nume >> supplier.adresa >> supplier.phone) {
        bool cartiLipsite = true;

        ifstream bookFile("Books.txt");
        Book book;

        while (bookFile >> book.titlu >> book.autor >> book.an >> book.limba >> book.tema >> book.pret >> book.copii >> book.supplier_id) {
            if (book.supplier_id == supplier.id && book.copii > 0) {
                cartiLipsite = false;
                break;
            }
        }

        bookFile.close();
        if (cartiLipsite) {
            livrareFile << supplier.id << " " << supplier.nume << " " << supplier.adresa << " " << supplier.phone << endl;
        }
    }

    supplierFile.close();
    livrareFile.close();
}

void arataRoOrdBook() {
    ifstream bookFile("Books.txt");

    Book books[100];
    int count = 0;

    Book book;
    while (bookFile >> book.titlu >> book.autor >> book.an >> book.limba >> book.tema >> book.pret >> book.copii >> book.supplier_id) {
        if (book.limba == "romana" || book.limba == "Romana" || book.limba == "română" || book.limba == "Română") {
            books[count] = book;
            count++;
        }
    }
    bookFile.close();

    // Mewtoda insertiei
    for (int i = 1; i < count; i++) {
        Book key = books[i];
        int j = i - 1;
        while (j >= 0 && books[j].titlu > key.titlu) {
            books[j + 1] = books[j];
            j--;
        }
        books[j + 1] = key;
    }

    for (int i = 0; i < count; i++) {
        cout << books[i].titlu << " de " << books[i].autor << " (" << books[i].an << ") - " << books[i].tema << " - " << books[i].pret << " RON - " << books[i].copii << " copii" << endl;
    }
}




void arataNumarMaxCopii() {
    ifstream bookFile("Books.txt");


    Book maxCopiiCarte;
    int maxCopii = 0;
    Book book;

    while (bookFile >> book.titlu >> book.autor >> book.an >> book.limba >> book.tema >> book.pret >> book.copii >> book.supplier_id) {
        if (book.copii > maxCopii) {
            maxCopii = book.copii;
            maxCopiiCarte = book;
        }
    }

    bookFile.close();
    cout << "Cartea cu numarul maxim de copii (" << maxCopii << ") este:" << endl;
    bookFile.open("Books.txt");
    while (bookFile >> book.titlu >> book.autor >> book.an >> book.limba >> book.tema >> book.pret >> book.copii >> book.supplier_id) {
        if (book.copii == maxCopii) {
            cout << book.titlu << " de " << book.autor << " (" << book.an << ") - " << book.tema << " - " << book.pret << " RON - " << book.copii << " copii" ;
        }
    }
    bookFile.close();
}

void arataPretulMediu(int supplierId) {
    ifstream bookFile("Books.txt");

    float total = 0;
    int count = 0;
    Book book;
    while (bookFile >> book.titlu >> book.autor >> book.an >> book.limba >> book.tema >> book.pret >> book.copii >> book.supplier_id) {
        if (book.supplier_id == supplierId) {
            total += book.pret;
            count++;
        }
    }

    bookFile.close();
    if (count == 0) {
        cout << "Nu au fost gasit carti pentru supplierul cu id-ul: " << supplierId << endl;
    } else {
        float pretul_Mediu = total / count;
        cout << "Pretul mediu pentru supplier " << supplierId << " este " << pretul_Mediu << " RON" << endl;
    }
}








#endif // MYLIBRARYFUNCTIONS_H
