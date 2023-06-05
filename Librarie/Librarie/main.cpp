#include "header.h"



int main() {
    cout << "ENTER...";

    int optiunea;
    cin.ignore();

    while(true){
    cout << endl;
    cout << "   M  E  N  U : \n" << endl;

    cout << "   1 - Afiseaza cartile din fisierul Books.txt" << endl;
    cout << "   2 - Afiseaza supplierii din fisierul Supplier.txt. " << endl;
    cout << "   3 - Adaoga o carte. " << endl;
    cout << "   4 - Adaoga un supplier. " << endl;
    cout << "   5 - Exclude o carte. " << endl;
    cout << "   6 - Exclude un supplier. " << endl;
    cout << "   7 - Actualizeaza info despre o carte. " << endl;
    cout << "   8 - Actualizeaza info despre un supplier. " << endl;
    cout << "   9 - Actualizarea fisierului Livrare.txt cu supplierii care au 0 de copii carti. " << endl;
    cout << "  10 - Afiseaza la ecran lista cartilor scrise in limba romana in ordine alfabetica. " << endl;
    cout << "  11 - Afiseaza la ecran informatia despre cartile cu numar maxim de exemplare. " << endl;
    cout << "  12 - Afiseaza la ecran pretul mediu a cartilor livrate de acelasi furnizor. " << endl;
    cout << "   0 - Pentru a iesi din program! \n" << endl ;


    cout << "Introdu optiunea: ";
    cin >> optiunea;
    cin.ignore();
    switch(optiunea){

        case 1: arataBooks(); break;
        case 2: arataSuppliers(); break;
        case 3: adaogaBook(); break;
        case 4: adaogaSupplier(); break;
        case 5: excludeBook(); break;
        case 6: excludeSupplier(); break;
        case 7: updateBook(); break;
        case 8: updateSupplier(); break;
        case 9: creazaLivrare(); break;
        case 10: arataRoOrdBook(); break;
        case 11: arataNumarMaxCopii(); break;
        case 12: int op_sup; cout << "Introdu id-ul supplierului: ";  cin >> op_sup; arataPretulMediu(op_sup); break;
        case 0:  exit(0); break;

        default: cout<< "Nu exista asa optiune!";
    }
    }






    return 0;
}






