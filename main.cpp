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

   std::cout<<"Pavarde " << " Vardas " << " Galutinis (Vid.)"<< std::endl;
   //std::cout<<"-"*;
   float galutinis;
   galutinis = 0.4*(bendras/A.pazymys.size()) + 0.6*A.egzaminas;
   std::cout<<A.pavarde<<A.vardas<<galutinis;



}
