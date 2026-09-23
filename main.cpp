#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

struct studentas {

    std::string vardas, pavarde;
    std::vector<int> pazymys;
    int egzaminas;
};

void nuskaitymas(std::vector<studentas>&grupe, std::ifstream& failas){

    std::string eilute;
    std::getline(failas,eilute);
    while(std::getline(failas, eilute))
    {
        std::istringstream iss(eilute);
        studentas A;
        iss>>A.vardas;
        iss>>A.pavarde;
        std::vector<int> skaiciai;
        int skaicius;
        while(iss>>skaicius)
        {
            skaiciai.push_back(skaicius);
        }
        if (skaiciai.size() < 2)
        {
            std::cout<<"Klaidinga eilute: "<< eilute <<"\n";
            continue;
        }
        A.egzaminas=skaiciai.back();
        for(int i=0; i<skaiciai.size()-1;i++)
        {
            A.pazymys.push_back(skaiciai[i]);
        }
        grupe.push_back(A);
    }
}

int main()
{
   std::vector<studentas> grupe;
        int pasirinkimas;

        std::cout << "\nPasirinkite duomenu ivedimo buda:\n";
        std::cout << "1 Ivesti pazymius ranka\n";
        std::cout << "2 Generuoti pazymius atsitiktinai\n";
        std::cout << "3 Nuskaityti duomenis is failo\n";
        std::cout << "Pasirinkimas: ";
        std::cin >> pasirinkimas;
        while(pasirinkimas<1 || pasirinkimas>3)
        {
            std::cout<<"Neteisingas pasirinkimas\n";
            std::cout << "Naujas pasirinkimas: "; std::cin >> pasirinkimas;

        }

        if(pasirinkimas==1)
    {
        while(true)
        {
            studentas A;
        std::cout<<"Iveskite per tarpa studento varda ir pavarde: ";
        std::cin>>A.vardas>>A.pavarde;

        {
        while(true){
        int l; char klausimas;
        std::cout<<"Iveskite namu darbu pazymi : ";
        std::cin>>l;

        while (std::cin.fail() || l < 1 || l > 10) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Neteisingas pazymys. Iveskite skaiciu nuo 1 iki 10: ";
            std::cin >> l;
        }
        A.pazymys.push_back(l);

        std::cout<<"Ar studentas dar turi pazymiu? (t/n) "; std::cin>>klausimas;
        if (klausimas == 'n' || klausimas == 'N') {
            break;
            }
        }
        std::cout<<"Iveskite studento egzamino rezultata: "; std::cin>>A.egzaminas;

    } grupe.push_back(A);
    char klausimas;
    std::cout<<"Ar dar yra studentu? (t/n) "; std::cin>>klausimas;
    if(klausimas =='n' || klausimas=='N')
    {
        break;
        }
    }
}
    else if(pasirinkimas==2){
    while(true){
        studentas A;
        std::cout<<"Iveskite per tarpa studento varda ir pavarde: ";
        std::cin>>A.vardas>>A.pavarde;
        int skaicius;
        do{
            std::cout<<"Iveskite kiek studento pazymiu sugeneruoti: "; std::cin>>skaicius;
            if(skaicius<=0){
                std::cout << "Klaida. Turi buti sugeneruotas bent vienas pazymys.\n";
            }
        }
        while (skaicius <= 0);
        for(int i=0; i<skaicius; i++)
        {
            int pazymys;
            pazymys=std::rand()%10+1;
            A.pazymys.push_back(pazymys);
        }
        A.egzaminas=std::rand()%10+1;
        grupe.push_back(A);
        char klausimas;
        std::cout<<"Ar dar yra studentu (t/n) "; std::cin>>klausimas;
        if(klausimas=='n' || klausimas == 'N')
       {
           break;
       }
    }
}
    else if (pasirinkimas ==3)
    {
        std::ifstream failas("kursiokai.txt");
        if (!failas) {
        std::cout << "Nepavyko atidaryti failo\n";
        return 1;
        }
        nuskaitymas(grupe, failas);
        failas.close();
    }
    std::sort(grupe.begin(), grupe.end(), [] (const studentas&a, const studentas&b){return a.pavarde < b.pavarde;});
    std::cout << std::left<< std::setw(15) << "Pavarde"<< std::setw(15) << "Vardas" << std::setw(20) << "Galutinis (Vid.)" << std::setw(20) << "Galutinis (Med.)" << "\n";

    for(int i = 0; i < 70; i++) {
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

        double galutinism, galutinisv, bendras=0;
        galutinism=0.4*mediana+0.6*B.egzaminas;
        for (int pazymys : B.pazymys){bendras += pazymys;}
        galutinisv = 0.4 * (bendras / B.pazymys.size()) + 0.6 * B.egzaminas;

        std::cout << std::left << std::setw(15) << B.pavarde << std::setw(15)
        << B.vardas << std::fixed << std::setprecision(2) << std::setw(20) << galutinisv << std::setw(20) <<galutinism << "\n";
    }
}
