#ifndef WYMIERNA_H
#define WYMIERNA_H
#include<iostream>
#include<set>
using namespace std;

class wymierna
{
private:
    int licznik;
    int mianownik;
public:
    //wymierna();
    wymierna(int=0, int=1);
    ~wymierna();
    int l()const;
    int m()const;
    void setLicznik(int);
    void setMianownik(int);
    wymierna operator+(wymierna q2);
    wymierna operator-(wymierna q2);
    wymierna operator*(wymierna q2);
    wymierna operator/(wymierna q2);
    //bool operator<(wymierna q2);
    friend bool operator<(const wymierna &q1, const wymierna &q2);
    friend bool operator<(wymierna q, set<wymierna>S);
    friend bool operator==(const wymierna &q1, const wymierna &q2);
    friend ostream & operator<<(ostream &screen, const wymierna &q);
    friend istream & operator>>(istream &keyboard, wymierna &q);

};

#endif // WYMIERNA_H
