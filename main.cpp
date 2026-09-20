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
   int b=0;
   while(true){
    int n; char klausimas;
    std::cout<<"Iveskite namu darbu pazymi :"; std::cin>>n;
    A.pazymys.push_back(n);
    b+=n;
    std::cout<<"Ar studentas dar turi pazymiu? (t/n) "; std::cin>>klausimas;
    if (klausimas == 'n' || klausimas == 'N') {
    break;
    }

   }
   std::cout<<"Iveskite studento egzamino rezultata: "; std::cin>>A.egzaminas;
   std::cout<<b;


}
