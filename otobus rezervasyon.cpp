#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
static int p = 0;
class Rezervasyon
{
 int OtobusN;
 char Sofor[10], Varis[5], Kalkis[5], Nereden[10], Nereye[10];
 int Koltuk[32];
 string ad[32];

 public:
 void Ekle();
 void rezervasyon();
 void empty();
 void Goster();
 void Hepsi();
}
bus[10];
void Rezervasyon::Ekle()
{
 cout<<"Otobus no: ";
 cin>>bus[p].OtobusN;
 cout<<"\n Sofor adi: ";
 cin>>bus[p].Sofor;
 cout<<"\nVaris saati: ";
 cin>>bus[p].Varis;
 cout<<"\nKalki saati: ";
 cin>>bus[p].Kalkis;
 cout<<"\nNereden: \t\t\t";
 cin>>bus[p].Nereden;
 cout<<"\nNereye: \t\t\t";
 cin>>bus[p].Nereye;
 bus[p].empty();
 p++;
}
void Rezervasyon::rezervasyon()
{
 int _Koltuk;
 int number;

 cout<<"Otobus no: ";
 cin>>number;
 int n;
 for(n=0;n<=p;n++)
 {
 if(bus[n].OtobusN == number)
 break;
 }
 while(n<=p)
 {
 cout<<"\nKoltuk No: ";
 cin>>_Koltuk;
 if(_Koltuk>32)
 {
 cout<<"\n Sadece 32 koltuk mevcttur";
 }
 else
 {
 if(bus[n].Koltuk[_Koltuk-1]==0)
 {
 cout<<"Yolcunun adi: ";
 cin>>bus[n].ad[_Koltuk-1];
 cout<< bus[n].Koltuk[_Koltuk-1];
 bus[n].Koltuk[_Koltuk-1]=-1;
 cout<< bus[n].Koltuk[_Koltuk-1];
 break;
 }
 else
 {cout<< bus[n].Koltuk[_Koltuk-1];
 cout<<"Bu koltuk onceden rezerv edilmistir.\n";
 }
 }
 }
 if(n>p)
 {
 cout<<"Otobus No yalnistir.\n";

 }
}
void Rezervasyon::empty()
{
 for (int i=0; i<32; i++)
 {
 bus[p].Koltuk[i]=0;
 }
}
void Rezervasyon::Goster()
{
 int n;
 int number;
 cout<<"Otobus no: ";
 cin>>number;
 for(n=0;n<=p;n++)
 {
 if(bus[n].OtobusN== number)
 break;
 }
while(n<=p)
{
 cout<<"**"<<endl;
 cout<<"Otobus no: \t"<<bus[n].OtobusN
 <<"\nSofor: \t"<<bus[n].Sofor<<"\t\tVaris saati: \t"
 <<bus[n].Varis<<"\tKalkis saati:"<<bus[n].Kalkis
 <<"\n Nereden: \t\t"<<bus[n].Nereden<<"\t\t Nereye: \t\t"<<
 bus[n].Nereye<<"\n";
 cout<<"**"<<endl;
 int a=1;
 for (int i=0; i<32; i++)
 {
 if(bus[n].Koltuk[i]== -1){
 a++;
 cout<<"\n Koltuk no "<<(a-1)<<" rezerv olmustur: "<<bus[n].ad[i]<<".";
 }
 else{
 a++;
 cout<<"\n Koltuk no "<<(a-1)<<" bostur.";
 }

 }
 break;
 }
 if(n>p)
 cout<<"Enter correct bus no: ";
}
void Rezervasyon::Hepsi()
{
 for(int n=0;n<p;n++)
 {
 cout<<"**"<<endl;
 cout<<"Bus no: \t"<<bus[n].OtobusN<<"\nSofor: \t"<<bus[n].Sofor
 <<"\t\tVaris time: \t"<<bus[n].Varis<<"\tKalkisure Time: \t"
 <<bus[n].Kalkis<<"\nNereden: \t\t"<<bus[n].Nereden<<"\t\tTo: \t\t\t"
 <<bus[n].Nereye<<"\n";
 cout<<"**"<<endl;
 }
}
int main()
{
int w;
while(1)
{
 cout<<"\n\n\n\n\n";
 cout<<"\t\t\t1.Ekle\n\t\t\t"
 <<"2.Rezervasyon\n\t\t\t"
 <<"3.Rapor \n\t\t\t"
 <<"4.Rapor tum otobuslar. \n\t\t\t"
 <<"5.cikis";
 cout<<"\n\t\t\t menu:-> ";
 cin>>w;
 switch(w)
 {
 case 1: bus[p].Ekle();
 break;
 case 2: bus[p].rezervasyon();
 break;
 case 3: bus[0].Goster();
 break;
 case 4: bus[0].Hepsi();
 break;
 case 5: exit(0);
 }
}
return 0;
}