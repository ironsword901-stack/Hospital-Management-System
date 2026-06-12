#include "../include/queue.h"
#include "../include/graph.h"
#include "../include/linked_list.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Prototype fungsi
void displayMainMenu();
void managePatientQueue(Queue& patientQueue);
void manageDeliveryRoute(Graph& deliveryGraph);
void manageMedicalHistory(LinkedList& medicalHistory);

int main() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║  🏥 HOSPITAL MANAGEMENT SYSTEM - INTEGRATED 🏥        ║" << endl;
    cout << "║                                                        ║" << endl;
    cout << "║  Struktur Data: Queue | Graph | Doubly Linked List    ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;
    cout << "\n";

    // Inisialisasi struktur data
    Queue patientQueue;
    Graph deliveryGraph;
    LinkedList medicalHistory;

    // Tambah beberapa departemen default
    deliveryGraph.addNode("Farmasi");
    deliveryGraph.addNode("Lab");
    deliveryGraph.addNode("Ruang ER");
    deliveryGraph.addNode("ICU");
    deliveryGraph.addNode("Poliklinik");
    
    // Tambah beberapa rute default
    deliveryGraph.addEdge("Farmasi", "Lab", 5);
    deliveryGraph.addEdge("Lab", "Ruang ER", 3);
    deliveryGraph.addEdge("Ruang ER", "ICU", 2);
    deliveryGraph.addEdge("Farmasi", "Poliklinik", 4);
    deliveryGraph.addEdge("Poliklinik", "ICU", 6);

    int choice;
    bool running = true;

    while (running) {
        displayMainMenu();
        
        cout << "Pilih menu (1-4): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";

        switch (choice) {
            case 1:
                managePatientQueue(patientQueue);
                break;
            case 2:
                manageDeliveryRoute(deliveryGraph);
                break;
            case 3:
                manageMedicalHistory(medicalHistory);
                break;
            case 4:
                running = false;
                cout << "\n✅ Terima kasih telah menggunakan Hospital Management System!" << endl;
                cout << "👋 Sampai jumpa lagi!\n" << endl;
                break;
            default:
                cout << "❌ Pilihan tidak valid! Silakan coba lagi.\n" << endl;
        }
    }

    return 0;
}

/**
 * displayMainMenu - Menampilkan menu utama
 */
void displayMainMenu() {
    cout << "\n╔════════════════════════════════════════════════════╗" << endl;
    cout << "║          MENU UTAMA SISTEM RUMAH SAKIT            ║" << endl;
    cout << "╠════════════════════════════════════════════════════╣" << endl;
    cout << "║ 1️⃣  Manajemen Antrian Pasien (QUEUE)              ║" << endl;
    cout << "║ 2️⃣  Peta Rute Pengiriman (GRAPH)                  ║" << endl;
    cout << "║ 3️⃣  Riwayat Pemeriksaan Pasien (LINKED LIST)      ║" << endl;
    cout << "║ 4️⃣  EXIT                                          ║" << endl;
    cout << "╚════════════════════════════════════════════════════╝" << endl;
}

/**
 * managePatientQueue - Sub-menu untuk manajemen antrian pasien
 * Struktur Data: QUEUE (FIFO)
 * Algoritma: Enqueue, Dequeue
 */
void managePatientQueue(Queue& patientQueue) {
    int subChoice;
    bool inQueueMenu = true;

    while (inQueueMenu) {
        cout << "\n┌─────────────────────────────────────────────────┐" << endl;
        cout << "│ 📋 MANAJEMEN ANTRIAN PASIEN (QUEUE - FIFO)     │" << endl;
        cout << "├─────────────────────────────────────────────────┤" << endl;
        cout << "│ 1️⃣  Tambah Pasien ke Antrian (ENQUEUE)         │" << endl;
        cout << "│ 2️⃣  Panggil Pasien Berikutnya (DEQUEUE)        │" << endl;
        cout << "│ 3️⃣  Lihat Pasien Paling Depan (PEEK)          │" << endl;
        cout << "│ 4️⃣  Tampilkan Semua Antrian                    │" << endl;
        cout << "│ 5️⃣  Kembali ke Menu Utama                      │" << endl;
        cout << "└─────────────────────────────────────────────────┘" << endl;

        cout << "Pilih menu (1-5): ";
        cin >> subChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";

        switch (subChoice) {
            case 1: {
                // ENQUEUE - Tambah pasien
                cout << "📝 TAMBAH PASIEN KE ANTRIAN" << endl;
                cout << "─────────────────────────────────────────────────" << endl;
                
                int id;
                string nama, keluhan, departemen;
                
                cout << "ID Pasien: ";
                cin >> id;
                cin.ignore();
                
                cout << "Nama Pasien: ";
                getline(cin, nama);
                
                cout << "Keluhan: ";
                getline(cin, keluhan);
                
                cout << "Departemen (cth: ER, Poliklinik): ";
                getline(cin, departemen);
                
                Pasien newPasien(id, nama, keluhan, departemen);
                patientQueue.enqueue(newPasien);
                break;
            }
            case 2: {
                // DEQUEUE - Panggil pasien
                cout << "📢 PANGGIL PASIEN BERIKUTNYA" << endl;
                cout << "─────────────────────────────────────────────────" << endl;
                
                Pasien calledPasien;
                patientQueue.dequeue(calledPasien);
                break;
            }
            case 3: {
                // PEEK - Lihat pasien depan
                cout << "👀 PASIEN PALING DEPAN" << endl;
                cout << "─────────────────────────────────────────────────" << endl;
                
                Pasien peekedPasien;
                if (patientQueue.peek(peekedPasien)) {
                    cout << "✓ ID: " << peekedPasien.id << endl;
                    cout << "✓ Nama: " << peekedPasien.nama << endl;
                    cout << "✓ Keluhan: " << peekedPasien.keluhan << endl;
                    cout << "✓ Departemen: " << peekedPasien.departemen << endl;
                }
                break;
            }
            case 4: {
                // DISPLAY - Tampilkan semua antrian
                patientQueue.display();
                break;
            }
            case 5: {
                inQueueMenu = false;
                cout << "⬅️  Kembali ke Menu Utama...\n" << endl;
                break;
            }
            default:
                cout << "❌ Pilihan tidak valid!\n" << endl;
        }
    }
}

/**
 * manageDeliveryRoute - Sub-menu untuk manajemen peta rute pengiriman
 * Struktur Data: GRAPH (Weighted, Directed)
 * Algoritma: Dijkstra Shortest Path
 */
void manageDeliveryRoute(Graph& deliveryGraph) {
    int subChoice;
    bool inGraphMenu = true;

    while (inGraphMenu) {
        cout << "\n┌─────────────────────────────────────────────────┐" << endl;
        cout << "│ 🚚 PETA RUTE PENGIRIMAN (GRAPH - DIJKSTRA)     │" << endl;
        cout << "├─────────────────────────────────────────────────┤" << endl;
        cout << "│ 1️⃣  Tambah Departemen (Node)                   │" << endl;
        cout << "│ 2️⃣  Tambah Rute (Edge)                         │" << endl;
        cout << "│ 3️⃣  Cari Rute Terdekat (Dijkstra)              │" << endl;
        cout << "│ 4️⃣  Tampilkan Semua Departemen                 │" << endl;
        cout << "│ 5️⃣  Tampilkan Semua Rute                       │" << endl;
        cout << "│ 6️⃣  Kembali ke Menu Utama                      │" << endl;
        cout << "└─────────────────────────────────────────────────┘" << endl;

        cout << "Pilih menu (1-6): ";
        cin >> subChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";

        switch (subChoice) {
            case 1: {
                // Tambah departemen (node)
                cout << "🏢 TAMBAH DEPARTEMEN" << endl;
                cout << "─────────────────────────────────────────────────" << endl;
                
                string deptName;
                cout << "Nama Departemen: ";
                getline(cin, deptName);
                
                deliveryGraph.addNode(deptName);
                break;
            }
            case 2: {
                // Tambah rute (edge)
                cout << "🛣️  TAMBAH RUTE ANTAR DEPARTEMEN" << endl;
                cout << "─────────────────────────────────────────────────" << endl;
                
                cout << "📍 Daftar Departemen Tersedia:" << endl;
                deliveryGraph.displayAllNodes();
                
                string from, to;
                int distance;
                
                cout << "\nDari Departemen: ";
                getline(cin, from);
                
                cout << "Ke Departemen: ";
                getline(cin, to);
                
                cout << "Jarak (km): ";
                cin >> distance;
                cin.ignore();
                
                deliveryGraph.addEdge(from, to, distance);
                break;
            }
            case 3: {
                // Cari rute terdekat (Dijkstra)
                cout << "🗺️  CARI RUTE TERDEKAT (ALGORITMA DIJKSTRA)" << endl;
                cout << "─────────────────────────────────────────────────" << endl;
                
                cout << "📍 Daftar Departemen Tersedia:" << endl;
                deliveryGraph.displayAllNodes();
                
                string start, end;
                
                cout << "\nDepartemen Awal: ";
                getline(cin, start);
                
                cout << "Departemen Tujuan: ";
                getline(cin, end);
                
                deliveryGraph.displayPath(start, end);
                break;
            }
            case 4: {
                // Tampilkan semua departemen
                deliveryGraph.displayAllNodes();
                break;
            }
            case 5: {
                // Tampilkan semua rute
                deliveryGraph.displayGraph();
                break;
            }
            case 6: {
                inGraphMenu = false;
                cout << "⬅️  Kembali ke Menu Utama...\n" << endl;
                break;
            }
            default:
                cout << "❌ Pilihan tidak valid!\n" << endl;
        }
    }
}

/**
 * manageMedicalHistory - Sub-menu untuk manajemen riwayat pemeriksaan
 * Struktur Data: DOUBLY LINKED LIST
 * Algoritma: Insert, Delete, Search, Traverse Forward/Backward
 */
void manageMedicalHistory(LinkedList& medicalHistory) {
    int subChoice;
    bool inHistoryMenu = true;
    static int nextId = 1;

    while (inHistoryMenu) {
        cout << "\n┌──────────────────────────────────────────────────┐" << endl;
        cout << "│ 📜 RIWAYAT PEMERIKSAAN PASIEN (LINKED LIST)      │" << endl;
        cout << "├──────────────────────────────────────────────────┤" << endl;
        cout << "│ 1️⃣  Tambah Pemeriksaan Baru (INSERT)             │" << endl;
        cout << "│ 2️⃣  Lihat Riwayat (Forward)                      │" << endl;
        cout << "│ 3️⃣  Lihat Riwayat (Backward)                     │" << endl;
        cout << "│ 4️⃣  Cari Berdasarkan Diagnosis                   │" << endl;
        cout << "│ 5️⃣  Cari Berdasarkan Nama Dokter                 │" << endl;
        cout << "│ 6️⃣  Hapus Pemeriksaan                            │" << endl;
        cout << "│ 7️⃣  Kembali ke Menu Utama                        │" << endl;
        cout << "└──────────────────────────────────────────────────┘" << endl;

        cout << "Pilih menu (1-7): ";
        cin >> subChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";

        switch (subChoice) {
            case 1: {
                // INSERT - Tambah pemeriksaan baru
                cout << "✏️  TAMBAH PEMERIKSAAN BARU" << endl;
                cout << "──────────────────────────────────────────────────" << endl;
                
                string tanggal, diagnosis, dokter, resep;
                
                cout << "Tanggal (DD/MM/YYYY): ";
                getline(cin, tanggal);
                
                cout << "Diagnosis: ";
                getline(cin, diagnosis);
                
                cout << "Nama Dokter: ";
                getline(cin, dokter);
                
                cout << "Resep: ";
                getline(cin, resep);
                
                Pemeriksaan newCheck(nextId++, tanggal, diagnosis, dokter, resep);
                medicalHistory.insertRiwayat(newCheck);
                break;
            }
            case 2: {
                // DISPLAY FORWARD
                medicalHistory.displayForward();
                break;
            }
            case 3: {
                // DISPLAY BACKWARD
                medicalHistory.displayBackward();
                break;
            }
            case 4: {
                // SEARCH by diagnosis
                cout << "🔍 PENCARIAN BERDASARKAN DIAGNOSIS" << endl;
                cout << "──────────────────────────────────────────────────" << endl;
                
                string keyword;
                cout << "Masukkan kata kunci: ";
                getline(cin, keyword);
                
                medicalHistory.searchByDiagnosis(keyword);
                break;
            }
            case 5: {
                // SEARCH by doctor
                cout << "👨‍⚕️  PENCARIAN BERDASARKAN NAMA DOKTER" << endl;
                cout << "──────────────────────────────────────────────────" << endl;
                
                string doctorName;
                cout << "Masukkan nama dokter: ";
                getline(cin, doctorName);
                
                medicalHistory.searchByDoctor(doctorName);
                break;
            }
            case 6: {
                // DELETE - Hapus pemeriksaan
                cout << "🗑️  HAPUS PEMERIKSAAN" << endl;
                cout << "──────────────────────────────────────────────────" << endl;
                
                int id;
                cout << "ID Pemeriksaan yang ingin dihapus: ";
                cin >> id;
                cin.ignore();
                
                medicalHistory.deleteRiwayat(id);
                break;
            }
            case 7: {
                inHistoryMenu = false;
                cout << "⬅️  Kembali ke Menu Utama...\n" << endl;
                break;
            }
            default:
                cout << "❌ Pilihan tidak valid!\n" << endl;
        }
    }
}
