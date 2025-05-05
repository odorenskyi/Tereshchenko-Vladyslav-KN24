#include <iostream>
#include <bitset>
#include <string>
#include <cctype>

using namespace std;

double calculateElectricityBill(double kilowatts) {
    if (kilowatts <= 150) {
        return kilowatts * 0.3084;
    } else if (kilowatts <= 800) {
        return 150 * 0.3084 + (kilowatts - 150) * 0.4194;
    } else {
        return 150 * 0.3084 + (800 - 150) * 0.4194 + (kilowatts - 800) * 1.3404;
    }
}

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

// ===== Задача 9.2 =====
int getMinBeaufortScale(const double windSpeeds[], int size) {
    int minBeaufort = 12;
    for (int i = 0; i < size; ++i) {
        int beaufort = getBeaufortScale(windSpeeds[i]);
        if (beaufort < minBeaufort) {
            minBeaufort = beaufort;
        }
    }
    return minBeaufort;
}

int analyzeBinary(int N) {
    bitset<32> bits(N);
    return ((N >> 9) & 1) ? 32 - bits.count() : bits.count();
}

void s_calculation() {
    cout << "Виклик функції s_calculation()" << endl;
}
