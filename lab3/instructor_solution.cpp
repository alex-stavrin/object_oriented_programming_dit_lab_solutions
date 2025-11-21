#include <iostream>
#include <string>
#include <vector>
using namespace std;

// -------------------------------------------------------------
// Κλάση Sequence – Αναπαριστά DNA ή RNA αλληλουχία
// -------------------------------------------------------------
class Sequence {
private:
    string type;   // DNA ή RNA
    string data;   // η αλληλουχία

public:
    Sequence(const string& t, const string& d)
        : type(t), data(d) {
        cout << "Sequence created (" << type << ")" << endl;
    }

    ~Sequence() {
        cout << "Sequence destroyed (" << type << ")" << endl;
    }

    void describe() const {
        cout << "Sequence (" << type << "): " << data << endl;
    }

    size_t length() const {
        return data.size();
    }
};

// -------------------------------------------------------------
// Κλάση Isoform – Περιέχει Sequence (composition)
// -------------------------------------------------------------
class Isoform {
private:
    string id;
    string name;
    Sequence seq;  // κάθε Isoform έχει ένα Sequence

public:
    Isoform(const string& i, const string& n, const string& t, const string& d)
        : id(i), name(n), seq(t, d) {
        cout << "Isoform created: " << name << endl;
    }

    ~Isoform() {
        cout << "Isoform destroyed: " << name << endl;
    }

    void describe() const {
        cout << "Isoform " << id << " (" << name << ")" << endl;
        seq.describe();
        cout << "Length: " << seq.length() << " bases" << endl;
    }
};

// -------------------------------------------------------------
// Κλάση Gene – Περιέχει πολλές Isoforms (vector<Isoform>)
// -------------------------------------------------------------
class Gene {
private:
    string id;
    string name;
    string chrom;
    int start;
    int end;
    char strand;
    vector<Isoform> isoforms;

public:
    Gene(const string& newId, const string& newName,
         const string& newChrom, int s, int e, char str)
        : id(newId), name(newName), chrom(newChrom),
          start(s), end(e), strand(str) {
        cout << "Gene created: " << name << endl;
    }

    ~Gene() {
        cout << "Gene destroyed: " << name << endl;
    }

    void addIsoform(const Isoform& iso) {
        isoforms.push_back(iso);
    }

    void describe() const {
        cout << "Gene " << id << " (" << name << ") on "
             << chrom << ":" << start << "-" << end
             << " (" << strand << " strand)" << endl;

        if (isoforms.empty()) {
            cout << "No isoforms available." << endl;
        } else {
            cout << "Contains " << isoforms.size() << " isoforms:\n";
            for (const auto& iso : isoforms)
                iso.describe();
        }
    }
};

// -------------------------------------------------------------
// Συνάρτηση main()
// -------------------------------------------------------------
int main() {
    cout << "--- Creating Gene and Isoforms ---" << endl;

    Gene g1("ENSG000001", "TP53", "chr17", 7668402, 7687550, '-');

    Isoform i1("ENST0001", "TP53-201", "mRNA", "AUGGCCAUGGCGCCC...");
    Isoform i2("ENST0002", "TP53-202", "mRNA", "AUGCCUGAUGCUGUAG...");

    g1.addIsoform(i1);
    g1.addIsoform(i2);

    cout << endl;
    g1.describe();

    cout << "\n--- End of main ---" << endl;
    return 0;
}
