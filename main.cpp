#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

struct studentas {

    std::string vardas, pavarde;
    std::vector<int> pazymys;
    int egzaminas;
};

int main()
{
   std::vector<studentas> grupe;

   while(true){
        studentas A;

        std::cout<<"Iveskite per tarpa studento varda ir pavarde: ";
        std::cin>>A.vardas>>A.pavarde;

        while(true){
        int l; char klausimas;

        std::cout<<"Iveskite namu darbu pazymi :"; std::cin>>l;
        A.pazymys.push_back(l);

        std::cout<<"Ar studentas dar turi pazymiu? (t/n) "; std::cin>>klausimas;
        if (klausimas == 'n' || klausimas == 'N') {
            break;
        }
        }
        std::cout<<"Iveskite studento egzamino rezultata: "; std::cin>>A.egzaminas;

        grupe.push_back(A);

        char klausimas;
        std::cout<<"Ar dar yra studentu? (t/n) "; std::cin>>klausimas;
        if (klausimas == 'n' || klausimas == 'N') {
        break;
        }
   }

    char klausimas;
    std::cout<<"Skaiciuoti studento vidurki (t/n)?"; std::cin>>klausimas;

    std::cout << "" << std::left<< std::setw(10) << "Pavarde" <<""
    <<std::left<< std::setw(10) << "Vardas" << "";

    if (klausimas == 'n' || klausimas == 'N') {
        std::cout << std::right << std::setw(5) << "Galutinis (Med.)" << "\n";
    }
    else{
        std::cout << std::right << std::setw(5) << "Galutinis (Vid.)" << "\n";
    }
    for(int i = 0; i < 34; i++) {
    std::cout << "-";
    }
    std::cout << "\n";

   for(auto B: grupe){

        double mediana;
        std::sort(B.pazymys.begin(),B.pazymys.end());

        if (B.pazymys.size()%2==0){
            mediana=(B.pazymys[B.pazymys.size()/2-1]+B.pazymys[B.pazymys.size()/2])/2.0;
        }
        else{
            mediana=B.pazymys[B.pazymys.size()/2];
        }

        double galutinis;

        if(klausimas=='n' || klausimas=='N')
        {
            galutinis=0.4*mediana+0.6*B.egzaminas;
        }
        else {

            double bendras = 0;
            for (int pazymys : B.pazymys){bendras += pazymys;}
            galutinis = 0.4 * (bendras / B.pazymys.size()) + 0.6 * B.egzaminas;
        }

        std::cout << std::left << std::setw(10) << B.pavarde << std::setw(10)
        << B.vardas << std::fixed << std::setprecision(2) << galutinis << "\n";
    }
}
