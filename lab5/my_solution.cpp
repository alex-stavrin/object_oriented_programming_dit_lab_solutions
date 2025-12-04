#include <iostream>
#include <vector>
#include <iomanip>

int proteins_counter = 0;
int genes_counter = 0;

using namespace std;

class Sequence
{
    private:
        static int count;

        void print_constructor_message()
        {
            cout << "Sequence " << "(" << data << ")" << " was created" << endl;
        }

    protected:
        string data;

    public:

        
        // constructors
        Sequence() : data("")
        { 
            print_constructor_message(); 
            count++;
        }
        Sequence(string n_data) : data(n_data)
        { 
            print_constructor_message();
            count++;
        }

        // destructor
        virtual ~Sequence() 
        {
            cout << "Sequence " << "(" << data << ")" << " was destroyed" << endl;
            count--;
        }; 

        // pure virtual functions make the class abstract
        virtual void describe() = 0;
        virtual bool isValid() = 0;

        int length()
        {
            return data.length(); 
        }

        static int getCount()
        {
            return count;
        }
};

int Sequence::count = 0;

class DNASequence : public Sequence
{
    public:
        DNASequence(string n_data) : Sequence(n_data) 
        {
            std::cout << "DNA Sequence created" << std::endl;
        }

        virtual void describe() override
        {
            std::cout << "DNA Sequence: " << data << std::endl;
        }

        virtual bool isValid() override
        {
            for(char character : data)
            {
                if(character != 'A' && character != 'C' && character != 'G' && character != 'T')
                {
                    return false;
                }
            }

            return true;
        }
};

class RNASequence : public Sequence
{
    private:
        void print_contructor_message()
        {
            std::cout << "RNA Sequence created" << std::endl;
        }

    public:
        RNASequence() : Sequence()
        {
            print_contructor_message();
        }
        RNASequence(string n_data) : Sequence(n_data) 
        {
            print_contructor_message();
        }

        virtual void describe() override
        {
            std::cout << "RNA Sequence: " << data << std::endl;
        }

        virtual bool isValid() override
        {
            for(char character : data)
            {
                if(character != 'A' && character != 'C' && character != 'G' && character != 'U')
                {
                    return false;
                }
            }
            return true;
        }
};

class ProteinSequence : public Sequence
{
    public:
        ProteinSequence(string n_data) : Sequence(n_data)
        {
            std::cout << "Protein Sequence created" << std::endl;
        }

        virtual void describe() override
        { 
            std::cout << "Protein Sequence: " << data << std::endl;
        }

        virtual bool isValid() override
        {
            for(char character : data)
            {
                // B,J, O, U, X, Z. Letters that are not part of protein sequence
                if(character == 'B' || character == 'J' || character == 'O' || character == 'U' || character == 'X' || character == 'Z')
                {
                    return false;
                }
            }

            return true;
        }
};

class Isoform
{
    private:
        RNASequence sequence;
        string id;
        string name;

    public:
        Isoform() : sequence(), id(""), name("") {}; 
        Isoform(RNASequence n_sequence, string n_id, string n_name) : sequence(n_sequence), id(n_id), name(n_name){};

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
    vector<Sequence*> sequences;

    DNASequence* dna_sequence =  new DNASequence("ACGT");
    RNASequence* rna_sequence = new RNASequence("ACGU");
    ProteinSequence* protein_sequence = new ProteinSequence("MVLSEGEWQLVLHVWAKVEADVAGHGQ");

    sequences.push_back(dna_sequence);
    sequences.push_back(rna_sequence);
    sequences.push_back(protein_sequence);

    // make 0 and 1 be printed as false and true respectively
    std::cout << std::boolalpha;

    std::cout << "---Vector---" << std::endl;

    for(Sequence* sequence : sequences)
    {
        sequence->describe();
        std::cout << "Length: " << sequence->length() << std::endl;;
        std::cout << "Valid: " << sequence->isValid() << std::endl;
        std::cout << "---" << std::endl;
    }

    for(Sequence* sequence : sequences)
    {
        delete sequence;
    }

    RNASequence rSequence1("ACGGCGC");
    Isoform i1(rSequence1, "I1", "Isoform 1");
    Gene gene("G1", "Gene One", "chr17", 123124, 2323232, '+', "Homo Sapiens");

    gene.add_isoform(i1);
    gene.describe();

    return 0;
}