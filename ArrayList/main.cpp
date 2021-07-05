#include <iostream>


using namespace std;
template <class T>
class MyList{
public:
    T* tablica;
    size_t iloscMax;
    size_t actRozmiar;
    MyList(){
        tablica = new T[10];
        actRozmiar = 0;
        iloscMax = 10;
    }
    void add(T t){
        if(actRozmiar < iloscMax){
            tablica[actRozmiar] = t;
            actRozmiar++;
        }else{
            T* tmp = new T[iloscMax*2];
            memcpy(tmp, tablica, iloscMax*sizeof(T));
            delete tablica;
            tablica = tmp;
            iloscMax = iloscMax*2;
            add(e);
        }
    }
    size_t size(){
        return actRozmiar;
    }
    void show(){
        for (int i = 0; i < actRozmiar; i++){
            cout << tablica[i] << " ";
        }
        cout << endl;
    }
    void remove(int n){
        if(n < 1)
            return;
        n--;
        for (int i = n; i < actRozmiar-1; i++){
            tablica[i] = tablica[i+1];
        }
        actRozmiar--;
    }
    T get(int n){
        if (n < 1)
            return tablica[0];
        n--;
        if(n >= actRozmiar)
            return tablica[actRozmiar-1];
        return tablica[n];
    }
    MyList& operator++(){
        T* tmp = new T[iloscMax+1];
        memcpy(tmp, tablica, iloscMax*sizeof(T));
        delete tablica;
        tablica = tmp;
        iloscMax++;
        return *this;
    }
    MyList& operator+=(T e){
        add(e);
        return *this;
    }
    T operator[](int n){
        return get(n);
    }
    MyList& operator--(int){
        remove(actRozmiar);
    }
    ~MyList(){
        delete tablica;
    }
    MyList(const MyList &ml){
        tablica = new T[ml.iloscMax];
        iloscMax = ml.iloscMax;
        actRozmiar = ml.actRozmiar;
        memcpy(tablica, ml.tablica, iloscMax*sizeof(T));
    }
};
int main()
{

    MyList<int> list;
    MyList<double> ml;
    ml.add(3);
    //cout << ml.get(0);
    for (double i = 3; i < 15; i++){
       ml.add(i);
    }
    ml.show();
    ml.remove(4);
    ml.show();
    ml--;
    ml.show();
    cout << ml[2];
    ml+=15;
    ml.show();
    cout << ml.max << endl;
    ++ml;
    cout << ml.max << endl;
    MyList<double> kopia(ml);
    ml.show();
    kopia.show();

    return 0;
}
