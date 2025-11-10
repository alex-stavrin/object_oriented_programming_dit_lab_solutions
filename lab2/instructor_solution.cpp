#include <iostream>
#include <string>
using namespace std;

// ==========================
// Κλάση Protein
// ==========================
class Protein {
private:
    string id;
    string name;
    string sequence;

public:
    // Default constructor
    Protein()
        : id("UNKNOWN"), name("UNNAMED"), sequence("") {
        cout << "[Constructor] Protein created (default)" << endl;
    }

    // Constructor με λίστα αρχικοποίησης
    Protein(string i, string n, string seq)
        : id(i), name(n), sequence(seq) {
        cout << "[Constructor] Protein " << name << " created." << endl;
    }

    // Destructor
    ~Protein() {
        cout << "[Destructor] Protein " << name << " destroyed." << endl;
    }

    // Μέθοδος περιγραφής
    void describe() const {
        cout << "Protein " << id << " (" << name << "): " << sequence << endl;
    }

    // Μέθοδος που επιστρέφει μήκος
    int length() const {
        return sequence.size();
    }
};

// ==========================
// Κλάση Gene
// ==========================
class Gene {
private:
    const string organism;  
// const μέλος – απαιτείται αρχικοποίηση μέσω λίστας αρχικοποίησης

    string id;
    string name;
    string chrom;
    int start;
    int end;
    char strand;

public:
    // Default constructor με λίστα αρχικοποίησης
    Gene()
        : organism("Unknown"), id("NA"), name("NA"), chrom("NA"),
          start(0), end(0), strand('+') {
        cout << "[Constructor] Gene created (default)" << endl;
    }

    // Constructor με τιμές
    Gene(string i, string n, string ch, int s, int e, char str, string org)
        : organism(org), id(i), name(n), chrom(ch),
          start(s), end(e), strand(str) {
        cout << "[Constructor] Gene " << name << " from " << organism << " created." << endl;
    }

    // Destructor
    ~Gene() {
        cout << "[Destructor] Gene " << name << " destroyed." << endl;
    }

    // Περιγραφή
    void describe() const {
        cout << "Gene " << id << " (" << name << ") on "
             << chrom << ":" << start << "-" << end
             << " (" << strand << " strand) [" << organism << "]" << endl;
    }

    // Getter για οργανισμό (const member)
    const string& getOrganism() const {
        return organism;
    }
};

// ==========================
// Συνάρτηση main()
// ==========================
int main() {
    cout << "===== Δημιουργία αντικειμένων στο Stack =====" << endl;
    Protein p1("P001", "BRCA1_protein", "MNAAATARATLL");
    p1.describe();
    cout << "Sequence length: " << p1.length() << endl << endl;

    Gene g1("G001", "BRCA1", "chr17", 43044295, 43170245, '+', "Homo sapiens");
    g1.describe();
    cout << "Organism: " << g1.getOrganism() << endl << endl;

    cout << "===== Δημιουργία αντικειμένων στο Heap =====" << endl;
    Protein* p2 = new Protein("P002", "TP53_protein", "MKSVLLVVVAA");
    p2->describe();

    Gene* g2 = new Gene("G002", "TP53", "chr17", 7668402, 7687550, '-', "Homo sapiens");
    g2->describe();

    cout << "\n===== Καταστροφή αντικειμένων στο Heap =====" << endl;
    delete p2;  // καλείται και ο destructor
    delete g2;  // καλείται και ο destructor

    cout << "\n===== Τέλος εκτέλεσης του σώματος της main() =====" << endl;
    return 0;
}