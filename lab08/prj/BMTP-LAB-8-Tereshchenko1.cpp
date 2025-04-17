#include iostream
#include cmath

using namespace std;

int main() {
    double x, y, z, S;

    cout  Vvedit' x, y, z ;
    cin  x  y  z;

    if (sin(z) == 0) {
        cout  Pomilka ln(sin(z)) ne viznacheno.  endl;
        return 1;
    }

    S = (1.0  2)  pow(x, 2) - sqrt(pow(y + z, 2) - pow(x, 5)) - log(abs(sin(z)));

    cout  S =   S  endl;

    return 0;
}