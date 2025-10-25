#include <iostream>
#include <vector>

int objects_counter = 0;

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
            objects_counter++;
        }

        Protein(string starting_id, string starting_name, string starting_sequence) : id(starting_id), name(starting_name)
        , sequence(starting_sequence)
        {
            print_construct_message();
            objects_counter++;
        }

        // destructor
        ~Protein()
        {
            cout << "Protein " << get_name() << " destroyed." << endl;
            objects_counter--;
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
        Gene() : id(""), name(""), chrom(""), start(0), end(0), strand(' ')
        {
            print_construct_message();
            objects_counter++;
        }

        Gene(string starting_id, string starting_name, string starting_chrom, int starting_start, int starting_end
            , char starting_strand) : id(starting_id), name(starting_name), chrom(starting_chrom), start(starting_start), end(starting_end),
            strand(starting_strand) 
        {
            print_construct_message();
            objects_counter++;
        }

        // destructor
        ~Gene()
        {
            cout << "Gene " << get_name() << " destroyed." << endl;
            objects_counter--;
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
            cout << "Gene " << get_id() << " (" << get_name() << ") on " << get_chrom() << ":" << get_start()
            << " (" << get_strand() << " strand)" << endl;
        }        
};

int main()
{
    Protein p1("P1", "Hemoglobin", "MQLVD...");
    Protein p2("P2", "Myosin", "MAGTR...");

    cout << "Objects in memory: " << objects_counter << endl;

    p1.describe();
    cout << "Length of sequence: " << p1.length() << endl;

    p2.describe();
    cout << "Length of sequence: " << p2.length() << endl;

    Gene g1("G1", "BRCA1", "chr17", 43044295, 43170245, '+');
    Gene g2("G2", "TP53", "chr17", 7668402, 7687550, '-');

    cout << "Objects in memory: " << objects_counter << endl;

    g1.describe();

    g2.describe();

    vector<string> protein_and_gene_names;
    protein_and_gene_names.push_back(p1.get_name());
    protein_and_gene_names.push_back(p2.get_name());
    protein_and_gene_names.push_back(g1.get_name());
    protein_and_gene_names.push_back(g2.get_name());

    cout << "Names in vector are: " << endl;
    for (string name : protein_and_gene_names)
    {
        cout << name << endl;
    }

    return 0;
}