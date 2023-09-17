

#include <iostream>
#include <fstream>

using namespace std;


/* Sarcina 1
struct Nod {
    int valoare;
    Nod* urmator;
};

void adaugaLaSfarsit(Nod*& cap, int valoare) {
    Nod* nodNou = new Nod;
    nodNou->valoare = valoare;
    nodNou->urmator = nullptr;

    if (cap == nullptr) {
        cap = nodNou;
    } else {
        Nod* nodCurent = cap;
        while (nodCurent->urmator != nullptr) {
            nodCurent = nodCurent->urmator;
        }
        nodCurent->urmator = nodNou;
    }
}

void stergePrimulNod(Nod*& cap) {
    if (cap != nullptr) {
        Nod* nodDeSters = cap;
        cap = cap->urmator;
        delete nodDeSters;
    }
}

void permutaStanga(Nod*& cap, int k) {
    for (int i = 0; i < k; i++) {
        adaugaLaSfarsit(cap, cap->valoare);
        stergePrimulNod(cap);
    }
}

void afiseazaLista(Nod* cap) {
    Nod* nodCurent = cap;
    while (nodCurent != nullptr) {
        cout << nodCurent->valoare << " ";
        nodCurent = nodCurent->urmator;
    }
    cout << endl;
}

int main() {
    ifstream fisier("date.in");
    int k;
    fisier >> k;

    Nod* cap = nullptr;
    int valoare;
    while (fisier >> valoare) {
        adaugaLaSfarsit(cap, valoare);
    }

    permutaStanga(cap, k);
    afiseazaLista(cap);

    return 0;
}

*/


/* Sarcina 2




struct Nod {
    int cheie;
    Nod* urmator;
};

void adaugaLaSfarsit(Nod*& cap, int valoare) {
    Nod* nodNou = new Nod;
    nodNou->cheie = valoare;
    nodNou->urmator = nullptr;

    if (cap == nullptr) {
        cap = nodNou;
    } else {
        Nod* nodCurent = cap;
        while (nodCurent->urmator != nullptr) {
            nodCurent = nodCurent->urmator;
        }
        nodCurent->urmator = nodNou;
    }
}

void ordoneazaLista(Nod* cap) {
    if (cap == nullptr || cap->urmator == nullptr) {
        return;
    }

    Nod* nodCurent = cap;
    while (nodCurent != nullptr) {
        Nod* nodMinim = nodCurent;
        Nod* nodCautare = nodCurent->urmator;

        while (nodCautare != nullptr) {
            if (nodCautare->cheie < nodMinim->cheie) {
                nodMinim = nodCautare;
            }
            nodCautare = nodCautare->urmator;
        }

        // Schimbarea valorilor
        int temp = nodCurent->cheie;
        nodCurent->cheie = nodMinim->cheie;
        nodMinim->cheie = temp;

        nodCurent = nodCurent->urmator;
    }
}

void afiseazaLista(Nod* cap) {
    Nod* nodCurent = cap;
    while (nodCurent != nullptr) {
        cout << nodCurent->cheie << " ";
        nodCurent = nodCurent->urmator;
    }
    cout << endl;
}

void elibereazaLista(Nod* cap) {
    Nod* nodCurent = cap;
    while (nodCurent != nullptr) {
        Nod* nodDeSters = nodCurent;
        nodCurent = nodCurent->urmator;
        delete nodDeSters;
    }
}

int main() {
    // Exemplu de utilizare
    Nod* cap = nullptr;

    adaugaLaSfarsit(cap, 5);
    adaugaLaSfarsit(cap, 2);
    adaugaLaSfarsit(cap, 8);
    adaugaLaSfarsit(cap, 1);

    cout << "Lista initiala: ";
    afiseazaLista(cap);

    ordoneazaLista(cap);

    cout << "Lista ordonata: ";
    afiseazaLista(cap);

    elibereazaLista(cap);

    return 0;
}

*/


/* Sarcina 3


struct Nod {
    int valoare;
    Nod* urmator;
};

void adaugaLaSfarsit(Nod*& cap, int valoare) {
    Nod* nodNou = new Nod;
    nodNou->valoare = valoare;
    nodNou->urmator = nullptr;

    if (cap == nullptr) {
        cap = nodNou;
    } else {
        Nod* nodCurent = cap;
        while (nodCurent->urmator != nullptr) {
            nodCurent = nodCurent->urmator;
        }
        nodCurent->urmator = nodNou;
    }
}

void afiseazaLista(Nod* cap) {
    Nod* nodCurent = cap;
    while (nodCurent != nullptr) {
        cout << nodCurent->valoare << " ";
        nodCurent = nodCurent->urmator;
    }
    cout << endl;
}

void elibereazaLista(Nod* cap) {
    Nod* nodCurent = cap;
    while (nodCurent != nullptr) {
        Nod* nodDeSters = nodCurent;
        nodCurent = nodCurent->urmator;
        delete nodDeSters;
    }
}

void creeazaListePareSiImpare(ifstream& fisier, Nod*& listaPare, Nod*& listaImpare) {
    int valoare;
    while (fisier >> valoare) {
        if (valoare % 2 == 0) {
            adaugaLaSfarsit(listaPare, valoare);
        } else {
            adaugaLaSfarsit(listaImpare, valoare);
        }
    }
}

void adaugaListaLaSfarsit(Nod*& listaDestinatie, Nod* listaSursa) {
    if (listaDestinatie == nullptr) {
        listaDestinatie = listaSursa;
    } else {
        Nod* nodCurent = listaDestinatie;
        while (nodCurent->urmator != nullptr) {
            nodCurent = nodCurent->urmator;
        }
        nodCurent->urmator = listaSursa;
    }
}

int main() {
    ifstream fisier("date.in");

    Nod* listaPare = nullptr;
    Nod* listaImpare = nullptr;

    creeazaListePareSiImpare(fisier, listaPare, listaImpare);

    adaugaListaLaSfarsit(listaPare, listaImpare);

    cout << "Lista cu elemente pare: ";
    afiseazaLista(listaPare);

    elibereazaLista(listaPare);

    return 0;
}
*/

/* Sarcina 4 */



struct Nod {
    int valoare;
    Nod* urmator;
};

void adaugaLaSfarsit(Nod*& cap, int valoare) {
    Nod* nodNou = new Nod;
    nodNou->valoare = valoare;
    nodNou->urmator = nullptr;

    if (cap == nullptr) {
        cap = nodNou;
    } else {
        Nod* nodCurent = cap;
        while (nodCurent->urmator != nullptr) {
            nodCurent = nodCurent->urmator;
        }
        nodCurent->urmator = nodNou;
    }
}

void stergePrimulNod(Nod*& cap, int valoare) {
    if (cap == nullptr) {
        return;
    }

    if (cap->valoare == valoare) {
        Nod* nodDeSters = cap;
        cap = cap->urmator;
        delete nodDeSters;
        return;
    }

    Nod* nodCurent = cap;
    while (nodCurent->urmator != nullptr) {
        if (nodCurent->urmator->valoare == valoare) {
            Nod* nodDeSters = nodCurent->urmator;
            nodCurent->urmator = nodCurent->urmator->urmator;
            delete nodDeSters;
            return;
        }
        nodCurent = nodCurent->urmator;
    }
}

void afiseazaLista(Nod* cap) {
    Nod* nodCurent = cap;
    while (nodCurent != nullptr) {
        cout << nodCurent->valoare << " ";
        nodCurent = nodCurent->urmator;
    }
    cout << endl;
}



int main() {
    ifstream fisier("date.in");

    Nod* cap = nullptr;
    int valoare;

    while (fisier >> valoare) {
        adaugaLaSfarsit(cap, valoare);
    }

    cout << "Lista initiala: ";
    afiseazaLista(cap);

    cout << "Introduceti valoarea x: ";
    cin >> valoare;

    stergePrimulNod(cap, valoare);

    cout << "Lista dupa stergerea primului nod cu valoarea " << valoare << ": ";
    afiseazaLista(cap);


    return 0;
}



