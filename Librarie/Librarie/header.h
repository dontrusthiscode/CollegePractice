#ifndef MYLIBRARYFUNCTIONS_H
#define MYLIBRARYFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
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
    cin.ignore(); // add this line to consume the newline character
    getline(cin, supplier.nume);

    cout << "Introdu adresa supplierului: ";
    getline(cin, supplier.adresa);

    cout << "Introdu numarul de telefon a supplierului: ";
    getline(cin, supplier.phone);

    file << supplier.id << " " << supplier.nume << " " << supplier.adresa << " " << supplier.phone << endl;
    file.close();
}

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

    remove("Books.txt");
    rename("temp.txt", "Books.txt");

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

    remove("Supplier.txt");
    rename("temp.txt", "Supplier.txt");
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
    remove("Books.txt");
    rename("temp.txt", "Books.txt");
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

    remove("Supplier.txt");
    rename("temp.txt", "Supplier.txt");

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

bool comparaBook(Book book1, Book book2) {
    return (book1.titlu < book2.titlu);
}

void arataRoOrdBook() {
    ifstream bookFile("Books.txt");

    Book books[100];
    int count = 0;

    Book book;
    while (bookFile >> book.titlu >> book.autor >> book.an >> book.limba >> book.tema >> book.pret >> book.copii >> book.supplier_id) {
        if (book.limba == "romana" || "Romana" || "română" || "Română") {
            books[count] = book;
            count++;
        }
    }
    bookFile.close();
    sort(books, books + count, comparaBook);
    for (int i = 0; i < count; i++) {
        cout << books[i].titlu << " de " << books[i].autor << " (" << books[i].an << ") - " << books[i].tema << " - " << books[i].pret << " RON - " << books[i].copii << " copii" << endl;
    }
}






#endif // MYLIBRARYFUNCTIONS_H
