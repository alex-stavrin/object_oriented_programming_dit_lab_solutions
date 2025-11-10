// Gene generates Isoforms
// Isoform has different RNA. It can generate Proteins

#include <iostream>
#include <vector>

int proteins_counter = 0;
int genes_counter = 0;

using namespace std;

class Sequence
{
    private:
        string type;
        string data;

        void print_constructor_message()
        {
            cout << "Sequence " << type << "(" << data << ")" << " was created" << endl;
        }

    public:

        // constructors
        Sequence() : type(""), data("") { print_constructor_message(); };
        Sequence(string n_type, string n_data) : type(n_type), data(n_data) { print_constructor_message(); };

        // destructor
        ~Sequence() { cout << "Sequence " << type << "(" << data << ")" << " was destroyed" << endl;}; 

        void describe()
        {
            cout << "Type " << type << ": " << data << endl;
        }

        int length()
        {
            return data.length(); 
        }
};

class Isoform
{
    private:
        Sequence sequence;
        string id;
        string name;

    public:
        Isoform() : sequence(Sequence()), id(""), name("") {}; 
        Isoform(Sequence n_sequence, string n_id, string n_name) : sequence(n_sequence), id(n_id), name(n_name){};

        void desribe()
        {
            cout << "Isoform " << name << ": " << id << ". My sequence is: ";
            sequence.describe();
        }
};

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

        std::vector<Isoform> isoforms;

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
        void describe()
        {
            cout << "Gene " << get_id() << " (" << get_chrom() << ":" << get_start() << "-" << get_end()
            << ", " << get_strand() << ")" << endl;

            for(int i = 0; i < isoforms.size(); i++)
            {
                isoforms[i].desribe();
            }
        }

        void add_isoform(Isoform isoform)
        {
            isoforms.push_back(isoform);
        }
};

int main()
{
    Gene gene("G1", "Gene One", "chr17", 123124, 2323232, '+', "Homo Sapiens");

    Sequence sequence1("DNA", "DAWADWBAWDH");
    Sequence sequence2("RNA", "ADWJLADWJKW");

    Isoform isoform1(sequence1, "ISO1", "Isoform 1");
    Isoform isoform2(sequence2, "ISO2", "Isoform 2");

    gene.add_isoform(isoform1);
    gene.add_isoform(isoform2);

    gene.describe();

    return 0;
}