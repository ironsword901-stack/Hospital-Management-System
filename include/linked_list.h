#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include <iostream>
#include <ctime>
using namespace std;

// Struktur untuk menyimpan data Pemeriksaan Pasien
struct Pemeriksaan {
    int id;
    string tanggal;
    string diagnosis;
    string dokter;
    string resep;

    Pemeriksaan() : id(0), tanggal(""), diagnosis(""), dokter(""), resep("") {}
    
    Pemeriksaan(int id, string tanggal, string diagnosis, string dokter, string resep)
        : id(id), tanggal(tanggal), diagnosis(diagnosis), dokter(dokter), resep(resep) {}
};

// Struktur Node untuk Doubly Linked List
struct Node {
    Pemeriksaan data;
    Node* next;
    Node* prev;

    Node(const Pemeriksaan& pemeriksaan) 
        : data(pemeriksaan), next(nullptr), prev(nullptr) {}
};

// Class Doubly Linked List untuk riwayat pemeriksaan
class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    // Constructor
    LinkedList();

    // Operasi Linked List
    bool insertRiwayat(const Pemeriksaan& pemeriksaan);
    bool deleteRiwayat(int id);
    bool searchByDiagnosis(const string& keyword) const;
    bool searchByDoctor(const string& doctorName) const;
    bool isEmpty() const;
    int getSize() const;

    // Display
    void displayForward() const;
    void displayBackward() const;
    void display() const;

    // Utility
    void clear();
    Node* getHead() const;
    Node* getTail() const;

    // Destructor
    ~LinkedList();

private:
    // Helper function
    Node* findNodeById(int id);
};

#endif // LINKED_LIST_H
