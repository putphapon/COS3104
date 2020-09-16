#include <iostream>
using namespace std;

void printout(char* title, int i, int j, int sum1, int sum2){
    cout << title       << endl;
    cout << "i = "      << i << endl;
    cout << "j = "      << j << endl;
    cout << "sum1 = "   << sum1 << endl;
    cout << "sum2 = "   << sum2 << endl << endl;
}

int fun(int *k) {
    *k += 4;
    return 3 * (*k) - 1;
}

int main()
{
    int i = 10, j = 10, sum1, sum2;
    printout("___PRE____",i,j,sum1,sum2);

    sum1 = (i/2) + fun(&i);
    sum2 = fun(&j) + (j/2);
    printout("___POST___",i,j,sum1,sum2);

    return 0;
}