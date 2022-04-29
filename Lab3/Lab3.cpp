#include "Person.h";
#include "employer.h";
#include "Client.h";
#include "Pesel.h";

#include <iostream>

int main()
{
    try {
        using namespace std;
        cout << "Dziedziczenie\n";
        nw::person p1("Sebastian", "Sobik");
        cout << p1.ToString() << endl;

        nw::employer e1(Pesel("00221705933"), p1);
        cout << e1.ToString() << endl;
        nw::Client c1(NIP("987654"), p1);
        cout << c1.ToString() << endl;
        //nw::Client c2(NIP("177766"), "Kamil", "Nowak");
        //cout << c2.ToString() << endl;
    }
        catch (const std::exception& e) {
            std::cout << " error " << e.what() << std::endl;
        }
    
}
