#include <iostream>
#include <string>
#include <vector>
#include <cctype> //κλασικές συναρτήσεις χειρισμού χαρακτήρων toupper()
 
using namespace std;
 
/* ============================================================
   BASE CLASS: Sequence
   Περιέχει το κοινό data και κοινές λειτουργίες.
   Θα κληρονομηθεί από DNASequence, RNASequence, ProteinSequence.
   ============================================================ */
 
class Sequence {
protected:  //protected σημαίνει ότι τα derived classes έχουν πρόσβαση,     
        	//αλλά ο εξωτερικός χρήστης όχι.
	string data;          	// Η πραγματική βιολογική ακολουθία
	static int count;     	// Μετρητής ενεργών Sequence αντικειμένων
 
public:
	// Constructor
	Sequence(const string& d)
    	: data(d) {
    	++count;
    	cout << "Sequence created. Active sequences: " << count << endl;
	}
 
	// Destructor
	~Sequence() {
    	--count;
    	cout << "Sequence destroyed. Active sequences: " << count << endl;
	}
 
	size_t length() const {
    	return data.size();
	}
 
	// H βασική describe() (θα γίνει hiding από τις derived)
	void describe() const {
    	cout << "Generic sequence: " << data << endl;
	}
 
	static int getCount() {
    	return count;
	}
};
 
// Αρχικοποίηση static μέλους
int Sequence::count = 0;
 
 
/* ============================================================
   DERIVED CLASS: DNASequence
   ============================================================ */
 
class DNASequence : public Sequence {
public:
	//Ο constructor της base class καλείται ΠΑΝΤΑ πρώτος, πριν το σώμα
	// της derived.
	DNASequence(const string& d)
    	: Sequence(d) {
    	cout << "DNASequence created\n";
	}
 
	~DNASequence() {
    	cout << "DNASequence destroyed\n";
	}
 
	void describe() const {
    	cout << "DNA sequence: " << data << endl;
	}
 
	static bool isValidBase(char c) {
    	char u = toupper(static_cast<unsigned char>(c));
    	return (u=='A' || u=='C' || u=='G' || u=='T');
	}
 
	bool isValid() const {
    	for (char c : data) {
        	if (!isValidBase(c)) return false;
    	}
    	return true;
	}
};
 
 
/* ============================================================
   DERIVED CLASS: RNASequence
   ============================================================ */
 
class RNASequence : public Sequence {
public:
	RNASequence(const string& d)
    	: Sequence(d) {
    	cout << "RNASequence created\n";
	}
 
	~RNASequence() {
    	cout << "RNASequence destroyed\n";
	}
 
	void describe() const {
    	cout << "RNA sequence: " << data << endl;
	}
 
	static bool isValidBase(char c) {
    	char u = toupper(static_cast<unsigned char>(c));
    	return (u=='A' || u=='C' || u=='G' || u=='U');
	}
 
	bool isValid() const {
    	for (char c : data) {
        	if (!isValidBase(c)) return false;
    	}
    	return true;
	}
};
 
 
/* ============================================================
   DERIVED CLASS: ProteinSequence
   ============================================================ */
 
class ProteinSequence : public Sequence {
public:
	ProteinSequence(const string& d)
    	: Sequence(d) {
    	cout << "ProteinSequence created\n";
	}
 
	~ProteinSequence() {
    	cout << "ProteinSequence destroyed\n";
	}
 
	void describe() const {
    	cout << "Protein sequence: " << data << endl;
	}
 
	static bool isValidAA(char c) {
    	const string valid = "ACDEFGHIKLMNPQRSTVWY"; // Τα 20 αμινοξέα
    	char u = toupper(static_cast<unsigned char>(c));
    	return valid.find(u) != string::npos;
	}
 
	bool isValid() const {
    	for (char c : data) {
        	if (!isValidAA(c)) return false;
    	}
    	return true;
	}
};
 
 
/* ============================================================
   CLASS: Isoform (Composition με RNASequence)
   ============================================================ */
 
class Isoform {
private:
	string id;
	string name;
	RNASequence seq;  // Κάθε ισομορφή έχει το δικό της RNASequence
 
public:
	Isoform(const string& i, const string& n, const string& rna)
    	: id(i), name(n), seq(rna) {
    	cout << "Isoform created: " << name << endl;
 
    	if (!seq.isValid()) {
        	cout << "Warning: RNA sequence of " << name << " has invalid bases\n";
    	}
	}
 
	~Isoform() {
    	cout << "Isoform destroyed: " << name << endl;
	}
 
	void describe() const {
    	cout << "Isoform " << id << " (" << name << ")\n";
    	seq.describe();
    	cout << "Length: " << seq.length() << " bases\n";
	}
};
 
 
/* ============================================================
   CLASS: Gene (contains vector<Isoform>)
   ============================================================ */
 
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
	Gene(const string& gid,
     	const string& gname,
     	const string& chr,
     	int s,
     	int e,
     	char st)
     	: id(gid), name(gname), chrom(chr), start(s), end(e), strand(st) {
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
         	<< " (" << strand << " strand)\n";
 
    	cout << "Active sequences: " << Sequence::getCount() << endl;
 
    	if (isoforms.empty()) {
        	cout << "No isoforms\n";
        	return;
    	}
 
    	cout << "Isoforms:\n";
    	for (const auto& iso : isoforms) {
        	iso.describe();
    	}
	}
};
 
 
/* ============================================================
   MAIN
   ============================================================ */
 
int main() {
 
	cout << "--- Testing standalone sequences ---\n";
 
	DNASequence dna("ACGTACGT");
	dna.describe();
	cout << "Valid? " << (dna.isValid() ? "Yes" : "No") << endl;
 
	RNASequence rna("AUGCCAGGAU");
	rna.describe();
	cout << "Valid? " << (rna.isValid() ? "Yes" : "No") << endl;
 
	ProteinSequence prot("MTAKPL");
	prot.describe();
	cout << "Valid? " << (prot.isValid() ? "Yes" : "No") << endl;
 
	cout << "Active sequences now: " << Sequence::getCount() << endl;
 
 
	cout << "\n--- Gene with Isoforms ---\n";
 
	Gene g1("ENSG000001", "TP53", "chr17", 7668402, 7687550, '-');
 
	Isoform iso1("ENST0001", "TP53-201", "AUGGCCAUGGCGCCC");
	Isoform iso2("ENST0002", "TP53-202", "AUGCCUGAUGCUGUAG");
 
	g1.addIsoform(iso1);
	g1.addIsoform(iso2);
 
	cout << endl;
	g1.describe();
 
	cout << "\n--- End of main ---\n";
	return 0;
}