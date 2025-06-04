#include "struct_type_project_9.h"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>

using namespace std;

// Глобальні конфігураційні параметри
static const string CONFIG_DATA_FILE   = "institution_registry.dat";
static const string CONFIG_BACKUP_FILE = "institution_backup.dat";

// Прототипи службових функцій
void renderMenu();
int  captureUserInput();
void holdScreen();
void printApplicationBanner();
void printClosingMessage();
void clearScreen();

int main() {
    // Конфігурація системи
    system("chcp 65001");
    clearScreen();

    EducationalInstitution* registryList = nullptr;
    int menuOption;
    bool applicationActive = true;

    // Вітальна заставка
    printApplicationBanner();

    cout << "\n=== ПІДСИСТЕМА ІНІЦІАЛІЗАЦІЇ ===" << endl;
    cout << "▸ Завантаження бази даних..." << endl;

    registryList = loadFromFile(CONFIG_DATA_FILE);

    cout << "▸ Готово! Система активована." << endl;
    holdScreen();

    // Головний робочий цикл
    while (applicationActive) {
        clearScreen();
        printApplicationBanner();
        renderMenu();

        menuOption = captureUserInput();

        switch (menuOption) {
            case 1: {
                cout << endl;
                cout << "==========================================" << endl;
                cout << "=           ВІДОБРАЖЕННЯ РЕЄСТРУ         =" << endl;
                cout << "==========================================" << endl;
                displayRegistry(registryList);
                holdScreen();
                break;
            }

            case 2: {
                cout << endl;
                cout << "==========================================" << endl;
                cout << "=            ЕКСПОРТ РЕЄСТРУ             =" << endl;
                cout << "==========================================" << endl;

                string outputFile;
                cout << "▸ Задайте ім'я вихідного файлу: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, outputFile);

                if (outputFile.empty()) {
                    outputFile = "institution_report.txt";
                    cout << "▸ Автоматично обрано: " << outputFile << endl;
                }

                displayRegistry(registryList, outputFile);
                holdScreen();
                break;
            }

            case 3: {
                cout << endl;
                cout << "==========================================" << endl;
                cout << "=         РЕЄСТРАЦІЯ НОВОГО ЗАКЛАДУ      =" << endl;
                cout << "==========================================" << endl;
                registryList = addRecord(registryList);
                holdScreen();
                break;
            }

            case 4: {
                cout << endl;
                cout << "==========================================" << endl;
                cout << "=              ПОШУКОВА СИСТЕМА          =" << endl;
                cout << "==========================================" << endl;

                int targetCode;
                cout << "▸ Код ЄДЕБО для пошуку: ";
                while (!(cin >> targetCode) || targetCode <= 0) {
                    cout << "▸ ПОМИЛКА! Введіть коректний код: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                searchByCode(registryList, targetCode);
                holdScreen();
                break;
            }

            case 5: {
                cout << endl;
                cout << "==========================================" << endl;
                cout << "=            ВИДАЛЕННЯ ЗАПИСУ            =" << endl;
                cout << "==========================================" << endl;

                int removeCode;
                cout << "▸ Код ЄДЕБО для видалення: ";
                while (!(cin >> removeCode) || removeCode <= 0) {
                    cout << "▸ ПОМИЛКА! Введіть коректний код: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                char confirmation;
                cout << "▸ Підтвердити видалення (Y/N)? ";
                cin >> confirmation;
                if (confirmation == 'Y' || confirmation == 'y') {
                    registryList = deleteRecord(registryList, removeCode);
                } else {
                    cout << "▸ Операцію скасовано." << endl;
                }
                holdScreen();
                break;
            }

            case 6: {
                cout << endl;
                cout << "==========================================" << endl;
                cout << "=              ЗБЕРЕЖЕННЯ ДАНИХ          =" << endl;
                cout << "==========================================" << endl;

                if (validateDataIntegrity(registryList)) {
                    saveToFile(registryList, CONFIG_DATA_FILE);

                    char backupChoice;
                    cout << "▸ Створити резервну копію (Y/N)? ";
                    cin >> backupChoice;
                    if (backupChoice == 'Y' || backupChoice == 'y') {
                        createBackup(registryList, CONFIG_BACKUP_FILE);
                    }
                } else {
                    cout << "▸ УВАГА: Збереження неможливе через помилки!" << endl;
                }
                holdScreen();
                break;
            }

            case 7: {
                cout << endl;
                cout << "==========================================" << endl;
                cout << "=           АНАЛІТИЧНИЙ ЗВІТ             =" << endl;
                cout << "==========================================" << endl;

                int totalEntries = getRegistrySize(registryList);
                cout << "\n▸ ЗАГАЛЬНА КІЛЬКІСТЬ ЗАПИСІВ: " << totalEntries << endl;

                if (totalEntries > 0) {
                    int publicCount  = 0;
                    int privateCount = 0;
                    int militaryCount= 0;
                    int crimCount    = 0;
                    int donbasCount  = 0;

                    EducationalInstitution* iterator = registryList;
                    while (iterator != nullptr) {
                        if (iterator->ownershipForm.find("Державна") != string::npos) {
                            publicCount++;
                        } else if (iterator->ownershipForm.find("Приватна") != string::npos) {
                            privateCount++;
                        }

                        if (iterator->militaryDepartment) militaryCount++;
                        if (iterator->crimUkraine)      crimCount++;
                        if (iterator->donbasUkraine)    donbasCount++;

                        iterator = iterator->next;
                    }

                    cout << "\n▸ РОЗПОДІЛ ЗА КАТЕГОРІЯМИ:" << endl;
                    cout << "  ├─ Державні заклади........ " << publicCount  << endl;
                    cout << "  ├─ Приватні заклади........ " << privateCount << endl;
                    cout << "  ├─ З військовою кафедрою.... " << militaryCount << endl;
                    cout << "  ├─ ОЦ 'Крим-Україна'....... "   << crimCount     << endl;
                    cout << "  └─ ОЦ 'Донбас-Україна'..... "   << donbasCount   << endl;
                }
                holdScreen();
                break;
            }

            case 0: {
                cout << endl;
                cout << "==========================================" << endl;
                cout << "=            ЗАВЕРШЕННЯ СЕАНСУ           =" << endl;
                cout << "==========================================" << endl;

                cout << "▸ Процедура автозбереження..." << endl;
                if (validateDataIntegrity(registryList)) {
                    autoSave(registryList, CONFIG_DATA_FILE);
                    cout << "▸ Дані успішно збережено!" << endl;
                } else {
                    cout << "▸ КРИТИЧНА ПОМИЛКА: Неконсистентні дані!" << endl;
                    char forceChoice;
                    cout << "▸ Форсувати збереження (Y/N)? ";
                    cin >> forceChoice;
                    if (forceChoice == 'Y' || forceChoice == 'y') {
                        saveToFile(registryList, CONFIG_DATA_FILE);
                    }
                }

                cout << "▸ Звільнення ресурсів..." << endl;
                clearRegistry(registryList);

                printClosingMessage();
                applicationActive = false;
                break;
            }

            default: {
                cout << "▸ НЕКОРЕКТНИЙ ВИБІР! Повторіть спробу." << endl;
                holdScreen();
                break;
            }
        }

    }

    return 0;
}

void renderMenu() {
    cout << endl;
    cout << "==============================================================" << endl;
    cout << "=                      ПАНЕЛЬ УПРАВЛІННЯ                     =" << endl;
    cout << "==============================================================" << endl;
    cout << "=  [1] → Відобразити весь реєстр на екрані                   =" << endl;
    cout << "=  [2] → Експортувати реєстр у текстовий файл                =" << endl;
    cout << "=  [3] → Зареєструвати новий навчальний заклад               =" << endl;
    cout << "=  [4] → Пошук закладу за кодом ЄДЕБО                        =" << endl;
    cout << "=  [5] → Видалити заклад з реєстру                           =" << endl;
    cout << "=  [6] → Зберегти реєстр на диск                             =" << endl;
    cout << "=  [7] → Переглянути аналітичну статистику                   =" << endl;
    cout << "=  [0] → Вихід з програми                                    =" << endl;
    cout << "==============================================================" << endl;
}

/**
 * Захоплення та валідація введення користувача
 */
int captureUserInput() {
    int userInput;
    cout << "▸ Оберіть дію: ";

    while (!(cin >> userInput)) {
        cout << "▸ НЕПРАВИЛЬНИЙ ФОРМАТ! Введіть число: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return userInput;
}

/**
 * Призупинення виконання програми
 */
void holdScreen() {
    cout << "\n▸ Натисніть Enter щоб продовжити...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

/**
 * Відображення банера програми
 */
void printApplicationBanner() {
    cout << "============================================================================" << endl;
    cout << "=                                                                          =" << endl;
    cout << "=        КОМП'ЮТЕРНА СИСТЕМА УПРАВЛІННЯ ОСВІТНІМИ ЗАКЛАДАМИ                =" << endl;
    cout << "=                     ДЕРЖАВНИЙ РЕЄСТР УНІВЕРСИТЕТІВ                       =" << endl;
    cout << "=                              ВАРІАНТ #9                                  =" << endl;
    cout << "=                                                                          =" << endl;
    cout << "============================================================================" << endl;
    cout << "= Авторський колектив: Авраменко, Ковальчук, Терещенко                     =" << endl;
    cout << "= Академічна дисципліна: Базові методології та технології програмування    =" << endl;
    cout << "============================================================================" << endl;
}

/**
 * Заключне повідомлення програми
 */
void printClosingMessage() {
    cout << endl;
    cout << "================================================================" << endl;
    cout << "=                                                              =" << endl;
    cout << "=                   СЕАНС РОБОТИ ЗАВЕРШЕНО                     =" << endl;
    cout << "=                                                              =" << endl;
    cout << "=          Дякуємо за використання нашої системи!              =" << endl;
    cout << "=                                                              =" << endl;
    cout << "=          Творці: Авраменко, Ковальчук, Терещенко             =" << endl;
    cout << "=                                                              =" << endl;
    cout << "================================================================" << endl;
}

/**
 * Очищення екрану консолі
 */
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

/**
 * Звільнення всієї пам'яті, зайнятої реєстром
 */
void clearRegistry(EducationalInstitution* head) {
    while (head != nullptr) {
        EducationalInstitution* temp = head;
        head = head->next;
        delete temp;
    }
}

/**
 * Підрахунок загальної довжини реєстру
 */
int getRegistrySize(EducationalInstitution* head) {
    int recordCount = 0;
    EducationalInstitution* current = head;
    while (current != nullptr) {
        recordCount++;
        current = current->next;
    }
    return recordCount;
}

/**
 * Валідація коректності вхідних параметрів
 */
bool validateInput(int code, const string& name) {
    if (code <= 0) {
        cout << "▸ ПОМИЛКА: Код ЄДЕБО повинен бути позитивним числом!" << endl;
        return false;
    }
    if (name.empty()) {
        cout << "▸ ПОМИЛКА: Назва закладу не може бути пустою!" << endl;
        return false;
    }
    return true;
}
