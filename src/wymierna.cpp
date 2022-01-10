#include "wymierna.h"
#include<iostream>
using namespace std;
int obliczNWD(int a, int b){
    int tmp;
    if(a==0) return 1;
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(a<b){
        tmp=a;
        a=b;
        b=tmp;
    }
    while(a%b!=0){
        tmp=b;
        b=a%b;
        a=tmp;
    }
    return b;
}
//wymierna::wymierna(){
    //cout<<"konstruktor bezparametrowy klasy wymierna\n";
//}
void skroc_ulamek(wymierna &q){
    int nwd=obliczNWD(q.l(), q.m());
    if(nwd>1){
        q.setLicznik(q.l()/nwd);
        q.setMianownik(q.m()/nwd);
    }
    if(q.m()<0){
        q.setLicznik(-q.l());
        q.setMianownik(-q.m());
    }
}
wymierna::wymierna(int l, int m){
if(m<0){
    m=-m;
    l=-l;
}


    if(m!=0){
    if(obliczNWD(l,m)==1){
    this->licznik=l;
    this->mianownik=m;}
    else{
        this->licznik=l/obliczNWD(l,m);
        this->mianownik=m/obliczNWD(l,m);
    }
    }
    else {
        cout<<"Podano mianownik 0, przypisano wartosc 1\n";
        this->licznik=l;
        this->mianownik=1;
    }
}

wymierna::~wymierna(){
    //cout<<"Destruktor klasy wymierna\n";
}
void wymierna::setLicznik(int l){
    this->licznik=l;
}
void wymierna::setMianownik(int m){
    if(m<0){
        m=-m;
        this->licznik*=-1;
    }
    if(m!=0)
    this->mianownik=m;
    else {
        cout<<"Podano mianownik 0, przypisano wartosc 1\n";
        this->mianownik=1;
    }
}
int wymierna:: l()const {
    return this->licznik;
}
int wymierna::m() const {
    return this->mianownik;
}
wymierna wymierna::operator+(wymierna q2){
    wymierna w(licznik*q2.mianownik+q2.licznik*mianownik, mianownik*q2.mianownik);
    return w;
}
wymierna wymierna::operator-(wymierna q2){
    wymierna w(licznik*q2.mianownik-q2.licznik*mianownik, mianownik*q2.mianownik);
    return w;
}
wymierna wymierna::operator*(wymierna q2){
    wymierna w(licznik*q2.licznik, mianownik*q2.mianownik);
    return w;
}
wymierna wymierna::operator/(wymierna q2){
        wymierna w(licznik*q2.mianownik, mianownik*q2.licznik);
        return w;
}
bool operator<(const wymierna &q1, const wymierna &q2){
    float w1=(float)q1.licznik/q1.mianownik;
    float w2=(float)q2.licznik/q2.mianownik;
    return w1<w2;

}
bool operator==(const wymierna &q1, const wymierna &q2){
    wymierna p1=q1;
    wymierna p2=q2;
    skroc_ulamek(p1);
    skroc_ulamek(p2);
    return (p1.licznik==p2.licznik && p1.mianownik==p2.mianownik);
}
bool operator<(wymierna q, set<wymierna>S){
    const wymierna p=q;
    bool wynik=false;
    for(auto x:S){
        if(x==p) wynik=true;
    }
    return wynik;
}
ostream &operator<<(ostream & screen, const wymierna &q1){
    wymierna q=q1;
    if (q.m()==1) screen<<q.l();
    else screen<<q.l()<<"/"<<q.m();
    return screen;
}
istream &operator>>(istream & keyboard, wymierna &q){
    keyboard>>q.licznik;
    int ch=getchar();
    if (ch=='/'){
    keyboard>>q.mianownik;
    skroc_ulamek(q);}
    return keyboard;

}
