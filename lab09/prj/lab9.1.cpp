#include <iostream>
using namespace std;

int main() {
    double kilowats;
    double totalCost = 0.0;

    cout << "Enter the number of kilowatt-hours consumed per month: ";
    cin >> kilowats;

    if (kilowats <= 150) {
        totalCost = kilowats * 0.3084;
    } else if (kilowats <= 800) {
        totalCost = 150 * 0.3084 + (kilowats - 150) * 0.4194;
    } else {
        totalCost = 150 * 0.3084 + (800 - 150) * 0.4194 + (kilowats - 800) * 1.3404;
    }

    cout << "Amount due: " << totalCost << " grn" << endl;

    return 0;
}