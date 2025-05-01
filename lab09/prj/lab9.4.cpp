#include <iostream>
#include <bitset>
#include <string>

using namespace std;


void g() {
    double kilowats;
    double totalCost = 0.0;

    cout << "Введіть кількість спожитих кіловат-годин за місяць: ";
    cin >> kilowats;

    if (kilowats <= 150) {
        totalCost = kilowats * 0.3084;
    } else if (kilowats <= 800) {
        totalCost = 150 * 0.3084 + (kilowats - 150) * 0.4194;
    } else {
        totalCost = 150 * 0.3084 + (800 - 150) * 0.4194 + (kilowats - 800) * 1.3404;
    }

    cout << "Сума до сплати: " << totalCost << " грн" << endl;
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

void h() {
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
}


int task_9_3(int N) {
    if ((N >> 9) & 1) {
        bitset<32> bits(N);
        return 32 - bits.count();  
    } else {
        bitset<32> bits(N);
        return bits.count();       
    }
}

void j() {
    int N;
    cout << "Введіть число N от 0 до 500700: ";
    cin >> N;
    if (N >= 0 && N <= 500700) {
        cout << "Результат задачі 9.3: " << task_9_3(N) << endl;
    } else {
        cout << "Помилка" << endl;
    }
}

=
void s_calculation() {
    cout << "Визвана функція s_calculation()" << endl;
}

=
int main() {
    string input;
    while (true) {
        cout << "Введіть символ (d/g/h/j, k/к для вихода): ";
        getline(cin, input);
        if (input.empty()) continue;

        char cmd = tolower((unsigned char)input[0]);

        switch (cmd) {
            case 'd': s_calculation(); break;
            case 'g': g(); break;
            case 'h': h(); break;
            case 'j': j(); break;
            case 'k':
            case 'к':
                cout << "Вихід з програми." << endl;
                return 0;
            default:
                cout << "\aНе вірний ввод." << endl;
        }
    }
    return 0;
}
