#include <iostream>
#include <vector>

int proteins_counter = 0;
int genes_counter = 0;

using namespace std;

class Protein
{
    private:
        string id;
        string name;
        string sequence;

        void print_construct_message() const
        {
            cout << "Protein " << get_name() << " constructed." << endl;
        }

    public:

        // constructors
        Protein() : id(""), name(""), sequence("")
        {
            print_construct_message();
            proteins_counter++;
        }

        Protein(string starting_id, string starting_name, string starting_sequence) : id(starting_id), name(starting_name)
        , sequence(starting_sequence)
        {
            print_construct_message();
            proteins_counter++;
        }

        // destructor
        ~Protein()
        {
            cout << "Protein " << get_name() << " destroyed." << endl;
            proteins_counter--;
        }

        // setter functions
        // we won't use pass by reference yet. We will pass and copy by value

        void set_id(string new_id)
        {
            id = new_id;
        }

        void set_name(string new_name)
        {
            name = new_name;
        }

        void set_sequence(string new_sequence)
        {
            sequence = new_sequence;
        }

        // getter functions

        string get_id() const
        {
            return id;
        }

        string get_name() const
        {
            return name;
        }

        string get_sequence() const
        {
            return sequence;
        }

        size_t length() const
        {
            return sequence.length();
        }

        // describe function
        void describe() const
        {
            cout << "Protein " << get_id() << " (" << get_name() << "): " << get_sequence() << endl;
        }
};

class Gene
{
    private:
        const string organism;

        string id;
        string name;
        string chrom;
        int start;
        int end;
        char strand;

        void print_construct_message() const
        {
            cout << "Gene " << get_name() << " constructed." << endl;
        }

    public:

        // constructor
        Gene() : id(""), name(""), chrom(""), start(0), end(0), strand(' '), organism("")
        {
            print_construct_message();
            genes_counter++;
        }

        Gene(string starting_id, string starting_name, string starting_chrom, int starting_start, int starting_end,
            char starting_strand, string starting_organism) : id(starting_id), name(starting_name), chrom(starting_chrom),
            start(starting_start), end(starting_end), strand(starting_strand), organism(starting_organism)
        {
            print_construct_message();
            genes_counter++;
        }

        // destructor
        ~Gene()
        {
            cout << "Gene " << get_name() << " destroyed." << endl;
            genes_counter--;
        }

        // setter functions
        void set_id(string new_id)
        {
            id = new_id;
        }

        void set_name(string new_name)
        {
            name = new_name;
        }

        void set_chrom(string new_chrom)
        {
            chrom = new_chrom;
        }

        void set_start(int new_start)
        {
            start = new_start;
        }

        void set_end(int new_end)
        {
            end = new_end;
        }

        void set_strand(int new_strand)
        {
            strand = new_strand;
        }

        // getters

        string get_id() const
        {
            return id;
        }

        string get_name() const
        {
            return name;
        }

        string get_chrom() const
        {
            return chrom;
        }

        int get_start() const
        {
            return start;
        }

        int get_end() const
        {
            return end;
        }

        char get_strand() const
        {
            return strand;
        }

        // describe function
        void describe() const
        {
            cout << "Gene " << get_id() << " (" << get_chrom() << ":" << get_start() << "-" << get_end()
            << ", " << get_strand() << ")" << endl;
        }        
};


// This functions are only for learning. They are a bad practice
void display_protein_data(Protein protein)
{
    protein.describe();
    cout << "Length of sequence: " << protein.length() << endl;
}

// This functions are only for learning. They are a bad practice
Protein update_protein_name(Protein protein, string new_name)
{
    protein.set_name(new_name);
    return protein;
}

int main()
{
    Protein protein1("P1", "Hemoglobin", "MQLVD...");
    Protein* p_protein2 = new Protein("P2", "Myosin", "MAGTR...");

    cout << "Proteins in memory: " << proteins_counter << endl;

    protein1 = update_protein_name(protein1, "Green Goblin");

    display_protein_data(protein1);
    display_protein_data(*p_protein2);

    Gene gene1("G1", "BRCA1", "chr17", 43044295, 43170245, '+', "Homo sapiens");
    Gene* p_gene2 = new Gene("G2", "TP53", "chr17", 7668402, 7687550, '-', "Dog");

    cout << "Genes in memory: " << genes_counter << endl;

    gene1.describe();

    p_gene2->describe();

    vector<string> protein_and_gene_names;
    protein_and_gene_names.push_back(protein1.get_name());
    protein_and_gene_names.push_back(p_protein2->get_name());
    protein_and_gene_names.push_back(gene1.get_name());
    protein_and_gene_names.push_back(p_gene2->get_name());

    cout << "Names in vector are: " << endl;
    for (string name : protein_and_gene_names)
    {
        cout << name << endl;
    }

    cout << "Proteins in memory: " << proteins_counter << endl;
    delete p_protein2;
    cout << "Proteins in memory: " << proteins_counter << endl;

    cout << "Genes in memory: " << genes_counter << endl;
    delete p_gene2;
    cout << "Genes in memory: " << genes_counter << endl;

    return 0;
}