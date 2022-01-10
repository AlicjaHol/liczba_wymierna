#include <iostream>
#include<algorithm>
#include<vector>
#include<set>
#include "wymierna.h"
using namespace std;

int main()
{
    wymierna w1(5,8), w2(7), w3, w4(12,2);
     cout << "w1 = " << w1 <<
        "\nw2 = " << w2 <<
        "\nw3 = " << w3 <<
        "\nw4 = " << w4 << "\n";
     cout << "Licznik liczby " << w1 << " to " << w1.l() <<
        ", natomiast jej mianownik to " << w1.m() << "\n";

     cout << wymierna(5,3) << " + " << wymierna(3,12) << " = " <<
         wymierna(5,3) + wymierna(3,12) << "\n";
     cout << wymierna(5,3) << " * " << wymierna(3,12) << " = " <<
         wymierna(5,3) * wymierna(3,12) << "\n";

    wymierna w5;
     cout << "w5 = "; cin >> w5; // u¿ytkownik wprowadza napis: -25/10
     cout << "zapisane: w5 = " << w5 << "\n";
     wymierna w6;
     cout << "w6 = "; cin >> w6; // u¿ytkownik wprowadza napis: 10;
     cout << "zapisane: w6 = " << w6 << "\n";
     vector<wymierna> A = { wymierna(3,5), wymierna(5,6), wymierna(-2,5),
          wymierna(5,12) };
     cout << "************************\n";
     for (auto x: A) {
          cout << x << " ";
     }
     cout << "\n";
     cout << "************************\n";
     sort(A.begin(), A.end());
     cout << "************************\n";
     for (auto x: A) {
          cout << x << " ";
     }
     cout << "\n";
    cout << "************************\n";
     set<wymierna> S = {wymierna(4,5), wymierna(-8,2), wymierna(16,-4)};
     for (auto x: S) {
          cout << x << " ";
     }
     cout << "\n";
     set<wymierna> T = {wymierna(4,5), -4};
     if (T==S)
          cout << "zbiory identyczne\n";
     else
          cout << "zbiory nie sa identyczne\n";
    set<wymierna> V = {wymierna(4,5), -4, 5};
     if (V<T)
          cout << "V zawarty w T\n";
     if (T<V)
          cout << "T zawarty w V\n";
          wymierna x(4,5);
     if (x < T)
          cout << "liczba " << x << " jest w tym zbiorze\n";
    else
          cout << "liczby " << x << " nie ma w tym zbiorze \n";
    x = wymierna(7,15);
    if (x < T)
          cout << "liczba " << x << " jest w tym zbiorze\n";
    else
          cout << "liczby " << x << " nie ma w tym zbiorze \n";
    return 0;
}
