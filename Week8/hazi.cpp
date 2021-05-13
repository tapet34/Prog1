#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<typename T>
void print_val(T temp)
{
    for(auto lm : temp)
        cout<<lm<<" ";
        cout<<endl;
}


template<typename T>
void increase(T& temp, const int val)
{
    for(auto& lm : temp)
    {
        lm+=val;
    }
}


template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    for(Iter1 p = f1; p!= e1; p++)
    {
        *f2 = *p;
        f2++;
    }

    return f2;
}


int main()
{
    const int size=10;
    array<int, size> tomb = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vektor = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list <int> lista = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


    array<int, size> tomb2 = tomb;
    vector<int> vektor2 = vektor;
    list <int> lista2 = lista;


    cout<<"Array: ";
    increase(tomb, 2);
    print_val(tomb);
    cout<<"Vector: ";
    increase(vektor, 3);
    print_val(vektor);
    cout<<"List: ";
    increase(lista,5);
    print_val(lista);


    my_copy(tomb.begin(), tomb.end(), vektor.begin());
    my_copy(lista.begin(), lista.end(), tomb.begin());


    vector<int>::iterator vfind;
    vfind = std::find(vektor2.begin(), vektor2.end(), 3);
    if(vfind != vektor2.end())
    {
        cout<<distance(vektor2.begin(), vfind)<<endl;
    }
    else
    {
        cout<<"Nincs benne 3-as szám"<<endl;
    }


    list<int>::iterator lfind;
    lfind=std::find(lista2.begin(), lista2.end(), 27);
    if(lfind == lista2.end())
    {
        cout<<"Nincs benne 27-es szám"<<endl;
    }
    else
    {
        cout<<distance(lista2.begin(), lfind)<<endl;
    }


    return 0;
}