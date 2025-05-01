#include <iostream>
using namespace std;

int getBeaufortScale(double wind) {
    if (wind < 0.3) return 0;
    if (wind < 1.6) return 1;
    if (wind < 3.4) return 2;
    if (wind < 5.5) return 3;
    if (wind < 8.0) return 4;
    if (wind < 10.8) return 5;
    if (wind < 13.9) return 6;
    if (wind < 17.2) return 7;
    if (wind < 20.8) return 8;
    if (wind < 24.5) return 9;
    if (wind < 28.5) return 10;
    if (wind < 32.7) return 11;
    return 12;
}

int main() {
    double wind;
    int minBeaufort = 12; 

    cout << "Введіть значення сили вітру (м/с) у 6 різних годинах:" << endl;

    for (int i = 0; i < 6; i++) {
        cin >> wind;
        int beaufort = getBeaufortScale(wind);

        if (beaufort < minBeaufort) {
            minBeaufort = beaufort;
        }
    }

    cout << "Найменший бал за шкалою Бофорта протягом доби: " << minBeaufort << endl;

    return 0;
}