#include "struct_type_project_9.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

EducationalInstitution* searchByCode(EducationalInstitution* head, int code) {
    if (head == nullptr) {
        cout << "����� �������!" << endl;
        return nullptr;
    }

    EducationalInstitution* current = head;

    while (current != nullptr) {
        if (current->edeboCode == code) {
            cout << "\n=== �������� ����� ===" << endl;
            displaySingleRecord(current);
            return current;
        }
        current = current->next;
    }

    cout << "����� � ����� ����� " << code << " �� �������� � �����." << endl;
    return nullptr;
}

void displayRegistry(EducationalInstitution* head, const string& outputFile) {
    if (head == nullptr) {
        string message = "����� �������!";
        if (outputFile.empty()) {
            cout << message << endl;
        } else {
            ofstream file(outputFile);
            if (file.is_open()) {
                file << message << endl;
                file.close();
                cout << "����������� �������� � ���� " << outputFile << endl;
            } else {
                cout << "������� ��������� ����� " << outputFile << endl;
            }
        }
        return;
    }

    if (outputFile.empty()) {
        // ��������� �� �����
        cout << "\n" << string(80, '=') << endl;
        cout << "           �Ū��� ���'��Ҳ� ��²���ί Ĳ������Ҳ" << endl;
        cout << "                    ������� ���ί ��²��" << endl;
        cout << string(80, '=') << endl;

        EducationalInstitution* current = head;
        int count = 1;

        while (current != nullptr) {
            cout << "\n--- ����� � " << count << " ---" << endl;
            displaySingleRecord(current);
            current = current->next;
            count++;
        }

        cout << "\n������ ������ � �����: " << (count - 1) << endl;
        cout << string(80, '=') << endl;
    } else {
        // ��������� � ����
        ofstream file(outputFile);
        if (!file.is_open()) {
            cout << "������� ��������� ����� " << outputFile << endl;
            return;
        }

        file << string(80, '=') << endl;
        file << "           �Ū��� ���'��Ҳ� ��²���ί Ĳ������Ҳ" << endl;
        file << "                    ������� ���ί ��²��" << endl;
        file << string(80, '=') << endl;

        EducationalInstitution* current = head;
        int count = 1;

        while (current != nullptr) {
            file << "\n--- ����� � " << count << " ---" << endl;
            displaySingleRecordToFile(current, file);
            current = current->next;
            count++;
        }

        file << "\n������ ������ � �����: " << (count - 1) << endl;
        file << string(80, '=') << endl;

        file.close();
        cout << "����� ������ ������������ � ���� " << outputFile << endl;
        cout << "�������� " << (count - 1) << " ������." << endl;
    }
}

void displaySingleRecord(EducationalInstitution* institution) {
    if (institution == nullptr) return;

    cout << "��� ������� � �����: " << institution->edeboCode << endl;
    cout << "����� ������������: " << institution->fullName << endl;
    cout << "������� �����: " << institution->shortName << endl;
    cout << "����� ������������ (����.): " << institution->fullNameEng << endl;
    cout << "����� ��������: " << institution->ownershipForm << endl;
    cout << "����� ���������: " << institution->managementBody << endl;
    cout << "������ ��������: " << institution->headPosition << endl;
    cout << "ϲ� ��������: " << institution->headFullName << endl;
    cout << "�������� ������: " << institution->address << endl;
    cout << "�������/����: " << institution->phone << endl;
    cout << "���������� �����: " << institution->email << endl;
    cout << "���-����: " << institution->website << endl;
    cout << "�� '����-������': " << (institution->crimUkraine ? "���" : "ͳ") << endl;
    cout << "�� '������-������': " << (institution->donbasUkraine ? "���" : "ͳ") << endl;
    cout << "³������� �������: " << (institution->militaryDepartment ? "���" : "ͳ") << endl;
    cout << "г� ����������: " << institution->foundationYear << endl;
}

void displaySingleRecordToFile(EducationalInstitution* institution, ofstream& file) {
    if (institution == nullptr) return;

    file << "��� ������� � �����: " << institution->edeboCode << endl;
    file << "����� ������������: " << institution->fullName << endl;
    file << "������� �����: " << institution->shortName << endl;
    file << "����� ������������ (����.): " << institution->fullNameEng << endl;
    file << "����� ��������: " << institution->ownershipForm << endl;
    file << "����� ���������: " << institution->managementBody << endl;
    file << "������ ��������: " << institution->headPosition << endl;
    file << "ϲ� ��������: " << institution->headFullName << endl;
    file << "�������� ������: " << institution->address << endl;
    file << "�������/����: " << institution->phone << endl;
    file << "���������� �����: " << institution->email << endl;
    file << "���-����: " << institution->website << endl;
    file << "�� '����-������': " << (institution->crimUkraine ? "���" : "ͳ") << endl;
    file << "�� '������-������': " << (institution->donbasUkraine ? "���" : "ͳ") << endl;
    file << "³������� �������: " << (institution->militaryDepartment ? "���" : "ͳ") << endl;
    file << "г� ����������: " << institution->foundationYear << endl;
}

void interactiveSearch(EducationalInstitution* head) {
    int code;
    char choice;

    do {
        cout << "\n=== ����� ������� �� ����� ����� ===" << endl;
        cout << "������ ��� ����� ��� ������: ";

        while (!(cin >> code) || code <= 0) {
            cout << "�������! ������ ��������� ��� (���� ������� �����): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        searchByCode(head, code);

        cout << "\n�������� �� ���� �����? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');
}
