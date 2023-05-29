#include <iostream>
#include <fstream>
#include <string>

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
    cout << "Title: " << book.titlu << endl;
    cout << "Author: " << book.autor << endl;
    cout << "Year: " << book.an << endl;
    cout << "Language: " << book.limba << endl;
    cout << "Theme: " << book.tema << endl;
    cout << "Price: " << book.pret << endl;
    cout << "Copies: " << book.copii << endl;
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
    cin >> supplier.nume;

    cout << "Introdu adresa supplierului: ";
    cin >> supplier.adresa;

    cout << "Introdu numarul de telefon a supplierului: ";
    cin >> supplier.phone;

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



int main() {
    int optiunea;

    while(true){
    cout << "Menu: " << endl;
    cout << "1 - Pentru afisarea cartilor din fisierul Books.txt" << endl;
    cout << "2 - Pentru afisarea supplierurilor din fisierul Supplier.txt" << endl;
    cout << "3 - Pentru a adaoga o carte la fisier" << endl;
    cout << "4 - Pentru a adaoga un nou supplier" << endl;
    cout << "5 - Pentru a exclude datele unei carti din fisierul Books.txt" << endl;
    cout << "6 - Pentru a exclude datele unui supplier din fisierul Supplier.txt" << endl;

    cout << "Introdu optiunea: ";
    cin >> optiunea;

    switch(optiunea){

        case 1: arataBooks(); break;
        case 2: arataSuppliers(); break;
        case 3: adaogaBook(); break;
        case 4: adaogaSupplier(); break;
        case 5: excludeBook(); break;
        case 6: excludeSupplier(); break;


        default: cout<< "Nu exista asa optiune!";
    }
    }







    return 0;
}






