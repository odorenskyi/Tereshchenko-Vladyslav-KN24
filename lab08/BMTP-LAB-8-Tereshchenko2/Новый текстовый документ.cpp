#include iostream
#include iomanip

using namespace std;

void printDeveloperInfo() {
    cout  Tereshchenko V.n;
}

int logicalExpression(char a, char b) {
    return (a + 1 = b)  1  0;
}

void s_calculation(int x, int y, int z) {
    cout  Desyatkoviy x =   x  , y =   y  , z =   z  endl;
    cout  hex  uppercase;
    cout  Shistnadciatkoviy x =   x  , y =   y  , z =   z  endl;
}

int main() {
    int x, y, z;
    char a, b;

    cout  Enter x, y, z ;
    cin  x  y  z;
    
    cout  VVedit' a , b ;
    cin  a  b;
    printDeveloperInfo();
    cout  Rezultat logichnogo virazu   logicalExpression(a, b)  endl;
    s_calculation(x, y, z);

    return 0;
}
