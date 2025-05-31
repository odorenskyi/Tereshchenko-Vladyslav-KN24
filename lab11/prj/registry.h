#ifndef REGISTRY_H
#define REGISTRY_H

#include string
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

struct Node {
    EducationInstitution data;
    Node next;
};

 Функції
void loadFromFile(Node& head, const string& filename);
void saveToFile(const Node head, const string& filename);
void displayAll(const Node head);
void addInstitution(Node& head);
void searchByCode(const Node head, const string& code);
void deleteByCode(Node& head, const string& code);
void freeList(Node& head);

#endif  REGISTRY_H
