#include <iostream>
#include <cstring>
#include <vector>


using namespace std;
class Osoba {
        public:
        char* imie;
        int wiek;

        Osoba(char * imie, int wiek) {
            this->imie = imie;
            this->wiek = wiek;
        }

        ~Osoba() {
            delete[] imie;
        }
        Osoba();

        void toString() {
            cout << imie << " " << wiek << endl;
        }


};

class Rachunek {
public:
    double stan_konta;
    Osoba* wlasciciel;

    Rachunek(Osoba* wlasciciel, double stan_konta) {
        this->wlasciciel = wlasciciel;
        this->stan_konta = stan_konta;
    }
    ~Rachunek() {
        delete wlasciciel;

    }


};

class Bank {
public:
    vector < Rachunek >dane;
    Bank(){
        this->dane;
    }
    Bank otworzNowyrachunek(Osoba* o, double stan) {
        Rachunek b(o, stan);
        dane.push_back(b);
        cout<<"utworzono ";
        show(o, stan);
        return Bank();


    }
    Bank zmienWlasciela(int i, Osoba* b) {
        dane[i-1].wlasciciel=b;
        /*Rachunek &element = dane[i];
        dane.erase(dane.begin() + i-1);
        Rachunek c(b, element.stan_konta);
        dane.push_back(c);*/
        cout<<"zmieniono wlasciela ";
        show(i-1);
        return Bank();
    }
    Bank usunrachunek(int i) {
        dane.erase(dane.begin() + i-1);
        cout<<"usunieto ";
        show(i-1);
        return Bank();
    }
    ~Bank() {

    }
    void show(int i){
        std::cout <<dane[i].wlasciciel->imie<<" "<< dane[i].stan_konta<< std::endl;
    }

void show(Osoba* o, double stan){
    std::cout <<o->imie<<" "<< stan<< std::endl;
}
void show(){
    for(int i = 0; i < dane.size();i++){
        std::cout <<dane[i].wlasciciel->imie<<" "<< dane[i].stan_konta<< std::endl;
    }
}
};


int main()
{

   Bank bank;
    char imie2[] = "Ala";
    Osoba Ala(imie2, 20);
    char imie[] = "Tomek";
    Osoba  Tomek(imie, 21);
    //Osoba  Tomek(imie, 21);
    bank.otworzNowyrachunek(&Tomek, 100.0);
    bank.otworzNowyrachunek(&Tomek, 100.0);
    bank.otworzNowyrachunek(&Tomek, 100.0);
    bank.zmienWlasciela(2, &Ala);
    //bank.usunrachunek(3);
    //cout<<bank.size()<<endl;
    //bank.show();
    cout << "dziala" << endl;
    //bank.zmienWlasciela(1, &Tomek);

    bank.usunrachunek(1);
    return 0;

}
