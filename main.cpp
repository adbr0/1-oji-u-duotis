#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
struct studentas {
    std::string vardas, pavarde;
    std::vector<int> pazymys;
    int egzaminas;
};
int main()
{
   studentas A;
   std::cout<<"Iveskite studento varda: "; std::cin>>A.vardas;
   std::cout<<"Iveskite studento pavarde: "; std::cin>>A.pavarde;
   int bendras=0;
   while(true){
    int l; char klausimas;
    std::cout<<"Iveskite namu darbu pazymi :"; std::cin>>l;
    A.pazymys.push_back(l);
    bendras+=l;
    std::cout<<"Ar studentas dar turi pazymiu? (t/n) "; std::cin>>klausimas;
    if (klausimas == 'n' || klausimas == 'N') {
    break;
    }

   }
   std::cout<<"Iveskite studento egzamino rezultata: "; std::cin>>A.egzaminas;
   std::cout << "" << std::left<< std::setw(10) << "Pavarde" <<""<<std::left<< std::setw(10) << "Vardas" << "";
   std::cout << std::right << std::setw(5) << "Galutinis (Vid.)" << "\n";
   for(int i = 0; i < 34; i++) {
    std::cout << "-";
    }
    std::cout << "\n";
    float galutinis;
    galutinis = 0.4 * (bendras / A.pazymys.size()) + 0.6 * A.egzaminas;
    std::cout << "" << std::left<< std::setw(10)<< A.pavarde <<""<<std::left<< std::setw(10) << A.vardas <<"";
    std::cout << std::right <<std::setw(5) << std::fixed << std::setprecision(2) << galutinis <<"";



}
