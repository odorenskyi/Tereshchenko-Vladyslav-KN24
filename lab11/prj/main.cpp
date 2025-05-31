#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct EducationInstitution {
    string code;
    string fullName;
    string shortName;
    string fullNameEng;
    string ownership;
    string governingBody;
    string headPosition;
    string headFullName;
    string address;
    string phoneFax;
    string email;
    string website;
    string ocCrimea;
    string ocDonbas;
    string militaryDepartment;
    int foundationYear;
};

void loadFromFile(vector<EducationInstitution>& list, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    EducationInstitution inst;
    while (getline(file, inst.code)) {
        getline(file, inst.fullName);
        getline(file, inst.shortName);
        getline(file, inst.fullNameEng);
        getline(file, inst.ownership);
        getline(file, inst.governingBody);
        getline(file, inst.headPosition);
        getline(file, inst.headFullName);
        getline(file, inst.address);
        getline(file, inst.phoneFax);
        getline(file, inst.email);
        getline(file, inst.website);
        getline(file, inst.ocCrimea);
        getline(file, inst.ocDonbas);
        getline(file, inst.militaryDepartment);
        file >> inst.foundationYear;
        file.ignore(); // перейти на наступний рядок
        list.push_back(inst);
    }
    file.close();
}

void saveToFile(const vector<EducationInstitution>& list, const string& filename) {
    ofstream file(filename);
    for (const auto& inst : list) {
        file << inst.code << "\n"
             << inst.fullName << "\n"
             << inst.shortName << "\n"
             << inst.fullNameEng << "\n"
             << inst.ownership << "\n"
             << inst.governingBody << "\n"
             << inst.headPosition << "\n"
             << inst.headFullName << "\n"
             << inst.address << "\n"
             << inst.phoneFax << "\n"
             << inst.email << "\n"
             << inst.website << "\n"
             << inst.ocCrimea << "\n"
             << inst.ocDonbas << "\n"
             << inst.militaryDepartment << "\n"
             << inst.foundationYear << "\n";
    }
    file.close();
}

void displayAll(const vector<EducationInstitution>& list) {
    for (const auto& inst : list) {
        cout << "Код: " << inst.code << "\n"
             << "Назва: " << inst.fullName << "\n"
             << "Коротка назва: " << inst.shortName << "\n"
             << "Назва англ.: " << inst.fullNameEng << "\n"
             << "Форма власності: " << inst.ownership << "\n"
             << "Орган: " << inst.governingBody << "\n"
             << "Посада керівника: " << inst.headPosition << "\n"
             << "ПІБ керівника: " << inst.headFullName << "\n"
             << "Адреса: " << inst.address << "\n"
             << "Тел./Факс: " << inst.phoneFax << "\n"
             << "Email: " << inst.email << "\n"
             << "Сайт: " << inst.website << "\n"
             << "ОЦ Крим: " << inst.ocCrimea << "\n"
             << "ОЦ Донбас: " << inst.ocDonbas << "\n"
             << "Військова кафедра: " << inst.militaryDepartment << "\n"
             << "Рік заснування: " << inst.foundationYear << "\n\n";
    }
}

void addInstitution(vector<EducationInstitution>& list) {
    EducationInstitution inst;
    cout << "\nВведіть дані нового закладу:\n";
    cout << "Код: "; getline(cin, inst.code);
    cout << "Повна назва: "; getline(cin, inst.fullName);
    cout << "Коротка назва: "; getline(cin, inst.shortName);
    cout << "Назва англ.: "; getline(cin, inst.fullNameEng);
    cout << "Форма власності: "; getline(cin, inst.ownership);
    cout << "Орган: "; getline(cin, inst.governingBody);
    cout << "Посада керівника: "; getline(cin, inst.headPosition);
    cout << "ПІБ керівника: "; getline(cin, inst.headFullName);
    cout << "Адреса: "; getline(cin, inst.address);
    cout << "Тел./Факс: "; getline(cin, inst.phoneFax);
    cout << "Email: "; getline(cin, inst.email);
    cout << "Сайт: "; getline(cin, inst.website);
    cout << "ОЦ Крим: "; getline(cin, inst.ocCrimea);
    cout << "ОЦ Донбас: "; getline(cin, inst.ocDonbas);
    cout << "Військова кафедра: "; getline(cin, inst.militaryDepartment);
    cout << "Рік заснування: "; cin >> inst.foundationYear;
    cin.ignore();
    list.push_back(inst);
}

void searchByCode(const vector<EducationInstitution>& list, const string& code) {
    for (const auto& inst : list) {
        if (inst.code == code) {
            cout << "Знайдено запис:\n";
            cout << "Назва: " << inst.fullName << "\n";
            return;
        }
    }
    cout << "Запис з кодом " << code << " не знайдено.\n";
}

void deleteByCode(vector<EducationInstitution>& list, const string& code) {
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (it->code == code) {
            list.erase(it);
            cout << "Запис видалено.\n";
            return;
        }
    }
    cout << "Запис не знайдено.\n";
}

int main() {
    vector<EducationInstitution> registry;
    string filename = "registry.txt";

    loadFromFile(registry, filename);

    int choice;
    do {
        cout << "\n1. Вивести реєстр\n2. Додати запис\n3. Пошук за кодом\n4. Видалити запис\n5. Завершити\nВаш вибір: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) displayAll(registry);
        else if (choice == 2) addInstitution(registry);
        else if (choice == 3) {
            string code;
            cout << "Введіть код: "; getline(cin, code);
            searchByCode(registry, code);
        }
        else if (choice == 4) {
            string code;
            cout << "Введіть код для видалення: "; getline(cin, code);
            deleteByCode(registry, code);
        }
    } while (choice != 5);

    saveToFile(registry, filename);
    cout << "Роботу завершено. Реєстр збережено.\n";
    return 0;
}