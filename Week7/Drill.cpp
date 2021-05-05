#include <iostream>
#include <vector>

using namespace std;

template<typename T>
struct S
{
    private:
    T val;

    public:
    explicit S(T v=0) : val{v} {};

    const T& get();

    //void set(T ertek);

    S& operator= (const T& val2);
};

template<typename T>
const T& S<T>::get()
{
    return val;
}

template<typename T>
S<T>& S<T>::operator= (const T& val2)
{
    val=val2;
    return *this;
}

/*
template<typename T>
void S<T>::set(T ertek)
{
    val=ertek;
}
*/

template<typename T>
void read_val(T& olvas_ertek)
{
    cin>>olvas_ertek;
}


int main()
{
    int szam_olvas;
    read_val(szam_olvas);
    char karakter_olvas;
    read_val(karakter_olvas);
    double tort_olvas;
    read_val(tort_olvas);
    string szoveg_olvas;
    read_val(szoveg_olvas);

    S<int> szam(7);
    S<char> karakter('q');
    S<double> tort(49.54);
    S<string> szoveg("vicces referencia.");
    S<vector <int>> vektor(vector <int>{1, 7, 15, 21});

    szam=szam_olvas;
    karakter=karakter_olvas;
    tort=tort_olvas;
    szoveg=szoveg_olvas;

    /*szam.set(szam_olvas);
    karakter.set(karakter_olvas);
    tort.set(tort_olvas);
    szoveg.set(szoveg_olvas);*/

    cout<<szam.get()<<endl;
    cout<<karakter.get()<<endl;
    cout<<tort.get()<<endl;
    cout<<szoveg.get()<<endl;
}