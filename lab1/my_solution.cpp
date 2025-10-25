#include <iostream>

// we won't use static char arrays, because we can't implement getters nicely
// we won't use dynamic char arrays, becuase we can't implement destructors that deallocate memory (We haven't learned destructors yet)
// So for simplicity sake. Lets just use std::string

using namespace std;

class Protein
{
    private:
        string id;
        string name;
        string sequence;

    public:

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

    public:

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
    cout << endl;

    Protein p1, p2;

    p1.set_id("P1");
    p1.set_name("Hemoglobin");
    p1.set_sequence("MQLVD...");
    p1.describe();
    cout << "Length of sequence: " << p1.length() << endl << endl;

    p2.set_id("P2");
    p2.set_name("Myosin");
    p2.set_sequence("MAGTR...");
    p2.describe();
    cout << "Length of sequence: " << p2.length() << endl << endl;

    Gene g1, g2;

    g1.set_id("G1");
    g1.set_name("BRCA1");
    g1.set_chrom("chr17");
    g1.set_start(43044295);
    g1.set_end(43170245);
    g1.set_strand('+');
    g1.describe();

    cout << endl;

    g2.set_id("G2");
    g2.set_name("TP53");
    g2.set_chrom("chr17");
    g2.set_start(7668402);
    g2.set_end(7687550);
    g2.set_strand('-');
    g2.describe();

    cout << endl;

    return 0;

}