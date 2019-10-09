#include <iostream>
#include <fstream>

using namespace std;

int konvertuok(int b6, int b5, int b4, int b3, int b2, int b1, int b0, int kodoTipas, bool vienetas);
void programosAprasymas();

int const SEPTINTA = 64;
int const SESTA = 32;
int const PENKTA = 16;
int const KETVIRTA = 8;
int const TRECIA = 4;
int const ANTRA = 2;
int const PIRMA = 1;

int main()
{
    int desimtainis;
    bool b7, b6, b5, b4, b3, b2, b1, b0;
    ifstream read("duomenys.txt");

    if (!read) {
        return 1;
    }
    ofstream write("rez.txt");

    while(read>>b7>>b6>>b5>>b4>>b3>>b2>>b1>>b0){
        int kodoTipas = 1;
        bool vienetas = false;
        if (b7) {
            b6 = !b6;
            b5 = !b5;
            b4 = !b4;
            b3 = !b3;
            b2 = !b2;
            b1 = !b1;
            b0 = !b0;
            kodoTipas = -1;
            vienetas = true;
        }
        desimtainis = konvertuok(b6, b5, b4, b3, b2, b1, b0, kodoTipas, vienetas);
        write << desimtainis << "\n";
    }
    read.close();
    write.close();
    programosAprasymas();

    return 0;
}

int konvertuok(int b6, int b5, int b4, int b3, int b2, int b1, int b0, int kodoTipas, bool vienetas)
{
    int desimtaineReiksme;
    desimtaineReiksme = ((b6 * SEPTINTA + b5 * SESTA + b4 * PENKTA +
                    b3 * KETVIRTA + b2 * TRECIA + b1 * ANTRA + b0 * PIRMA) + vienetas) * kodoTipas;

    return desimtaineReiksme;
}

void programosAprasymas()
{
    cout << "*******************************************\n";
    cout << "**  Registro 8 bitu dvejataines reiksmes **\n"
            "**  konvertavimas i desimtaine reiksme   **\n";
    cout << "*******************************************\n";
    cout << "*******************************************\n";
    cout << "**        Ziureti 'rez.txt' faila        **\n";
    cout << "*******************************************" << endl;
}



