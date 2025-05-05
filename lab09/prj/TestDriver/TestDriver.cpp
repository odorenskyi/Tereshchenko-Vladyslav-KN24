#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Прототипи функцій
double calculateElectricityBill(double kilowatts);
int getBeaufortScale(double wind);
int getMinBeaufortScale(const double windSpeeds[], int size);
int analyzeBinary(int N);
void s_calculation();

// === Test Driver ===
int main() {
    cout << fixed << setprecision(2);

    // --- Тест 1: Тестуємо calculateElectricityBill ---
    cout << "Тест 1: Розрахунок рахунку за електроенергію:\n";
    double kW[] = {100, 200, 1000};
    for (double val : kW) {
        cout << "  " << val << " кВт: " << calculateElectricityBill(val) << " грн\n";
    }

    // --- Тест 2: Тестуємо getBeaufortScale ---
    cout << "\nТест 2: Шкала Бофорта для одиничних значень вітру:\n";
    double windSpeedsTest[] = {0.1, 2.0, 5.0, 12.0, 25.0, 40.0};
    for (double wind : windSpeedsTest) {
        cout << "  " << wind << " м/с: ступінь " << getBeaufortScale(wind) << "\n";
    }

    // --- Тест 3: Тестуємо getMinBeaufortScale ---
    cout << "\nТест 3: Мінімальна шкала Бофорта в масиві:\n";
    double windArr[] = {3.5, 6.2, 1.4, 10.0, 2.5};
    int minScale = getMinBeaufortScale(windArr, 5);
    cout << "  Мінімальна шкала Бофорта: " << minScale << "\n";

    // --- Тест 4: Тестуємо analyzeBinary ---
    cout << "\nТест 4: Аналіз бітів у числі:\n";
    vector<int> testNums = {256, 511, 512, 1023, 1024};
    for (int num : testNums) {
        cout << "  Число: " << num << ", результат: " << analyzeBinary(num) << "\n";
    }

    // --- Тест 5: s_calculation ---
    cout << "\nТест 5: Виклик функції s_calculation():\n";
    s_calculation();

    return 0;
}
