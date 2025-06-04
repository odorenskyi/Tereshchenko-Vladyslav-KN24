#include "struct_type_project_9.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

EducationalInstitution* deleteRecord(EducationalInstitution* head, int code) {
    if (head == nullptr) {
        cout << "����� �������! ���� �� ��������." << endl;
        return nullptr;
    }

    EducationalInstitution* current = head;
    EducationalInstitution* previous = nullptr;

    // ����� �������� ��� ���������
    while (current != nullptr && current->edeboCode != code) {
        previous = current;
        current = current->next;
    }

    // ���� ������� �� ��������
    if (current == nullptr) {
        cout << "����� � ����� ����� " << code << " �� �������� � �����." << endl;
        return head;
    }

    // �������� ���������� ��� �����, ���� ���� ��������
    cout << "\n=== �������� ����� ��� ��������� ===" << endl;
    cout << "��� �����: " << current->edeboCode << endl;
    cout << "�����: " << current->fullName << endl;
    cout << "������� �����: " << current->shortName << endl;

    // ϳ����������� ���������
    char confirmation;
    cout << "\n�� ����� ������ �������� ��� �����? (y/n): ";
    cin >> confirmation;

    if (confirmation != 'y' && confirmation != 'Y') {
        cout << "��������� ���������." << endl;
        return head;
    }

    // ��������� ��������
    if (previous == nullptr) {
        // ��������� ������ �������
        head = current->next;
    } else {
        // ��������� ������� � �������� ��� ����
        previous->next = current->next;
    }

    delete current;
    cout << "����� ������ �������� � ������!" << endl;

    return head;
}

void saveToFile(EducationalInstitution* head, const string& filename) {
    ofstream file(filename, ios::binary | ios::trunc);

    if (!file.is_open()) {
        cout << "������� ��������� ����� " << filename << " ��� ����������!" << endl;
        return;
    }

    if (head == nullptr) {
        cout << "����� �������. �������� ������� ���� " << filename << endl;
        file.close();
        return;
    }

    cout << "���������� ������ � ���� " << filename << "..." << endl;

    EducationalInstitution* current = head;
    int count = 0;

    // ������� ��� ������ ����� � ������� ����
    auto writeString = [&file](const string& str) {
        size_t length = str.length();
        file.write(reinterpret_cast<const char*>(&length), sizeof(size_t));
        file.write(str.c_str(), length);
    };

    while (current != nullptr) {
        // ����� �������� �����
        file.write(reinterpret_cast<const char*>(&current->edeboCode), sizeof(int));

        // ����� ��� �������� ����
        writeString(current->fullName);
        writeString(current->shortName);
        writeString(current->fullNameEng);
        writeString(current->ownershipForm);
        writeString(current->managementBody);
        writeString(current->headPosition);
        writeString(current->headFullName);
        writeString(current->address);
        writeString(current->phone);
        writeString(current->email);
        writeString(current->website);

        // ����� ������� �������
        file.write(reinterpret_cast<const char*>(&current->crimUkraine), sizeof(bool));
        file.write(reinterpret_cast<const char*>(&current->donbasUkraine), sizeof(bool));
        file.write(reinterpret_cast<const char*>(&current->militaryDepartment), sizeof(bool));

        // ����� ���� ����������
        file.write(reinterpret_cast<const char*>(&current->foundationYear), sizeof(int));

        current = current->next;
        count++;
    }

    file.close();

    if (file.fail()) {
        cout << "������� ��� ����� � ����!" << endl;
    } else {
        cout << "����� ������ ���������!" << endl;
        cout << "��������� " << count << " ������ � ���� " << filename << endl;
    }
}

EducationalInstitution* interactiveDelete(EducationalInstitution* head) {
    int code;
    char choice;

    do {
        if (head == nullptr) {
            cout << "����� �������! ���� �� ��������." << endl;
            break;
        }

        cout << "\n=== ��������� ������ � �Ū���� ===" << endl;
        cout << "������ ��� ����� ������ ��� ���������: ";

        while (!(cin >> code) || code <= 0) {
            cout << "�������! ������ ��������� ��� (���� ������� �����): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        head = deleteRecord(head, code);

        if (head != nullptr) {
            cout << "\n�������� �� ���� �����? (y/n): ";
            cin >> choice;
        } else {
            cout << "����� ����� �������." << endl;
            break;
        }

    } while (choice == 'y' || choice == 'Y');

    return head;
}

void autoSave(EducationalInstitution* head, const string& filename) {
    cout << "\n=== ����������� ���������� ===" << endl;
    saveToFile(head, filename);
}

void createBackup(EducationalInstitution* head, const string& backupFilename) {
    cout << "��������� �������� ��ﳿ..." << endl;
    saveToFile(head, backupFilename);
    cout << "�������� ���� ��������: " << backupFilename << endl;
}

bool validateDataIntegrity(EducationalInstitution* head) {
    if (head == nullptr) {
        return true; // ������� ������ ��������� �������
    }

    EducationalInstitution* current = head;
    int count = 0;

    while (current != nullptr) {
        // �������� ����'������� ����
        if (current->edeboCode <= 0) {
            cout << "�������: ����������� ��� ����� � ����� �" << (count + 1) << endl;
            return false;
        }

        if (current->fullName.empty()) {
            cout << "�������: ������� ����� � ����� �" << (count + 1) << endl;
            return false;
        }

        if (current->foundationYear < 1000 || current->foundationYear > 2024) {
            cout << "�������: ����������� �� ���������� � ����� �" << (count + 1) << endl;
            return false;
        }

        current = current->next;
        count++;
    }

    cout << "�������� �������� ������� ������. ������: " << count << endl;
    return true;
}
