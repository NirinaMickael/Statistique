#include <iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<cassert>
#include"projet.h"
using namespace std;
stat::stat(){

}
void stat:: message(){
 cin.clear();
 cin.ignore(255,'\n');
  int choix;
  cout<<"Taper 1 pour revenir au Menu Principale sinon... "<<endl;
  cin>>choix;
  if(choix==1){
    affiche_premier_plan();
  }
  else{
    system("exit");
  }
}
void stat::affiche_titre(){
   system("cls");
  cout<<setw(100)<<"+---------------------------------------------------------------+"<<endl;
  cout<<setw(100)<<"+                                                               +"<<endl;
  cout<<setw(100)<<"+               STATISTIQUE DESCRIPTIVE BIVARIEE                +"<<endl;
  cout<<setw(100)<<"+                                                               +"<<endl;
  cout<<setw(100)<<"+---------------------------------------------------------------+"<<endl;
}
void stat::affiche_premier_plan(){
   system("cls");
 unsigned int choix;
  //setw dia atao imanupilena affichage
  cout<<setfill(' ');
  cout<<setw(100)<<right<<"+---------------------------------------------------------------+"<<endl;
  cout<<setw(100)<<right<<"+                                                               +"<<endl;
  cout<<setw(100)<<right<<"+               STATISTIQUE DESCRIPTIVE BIVARIEE                +"<<endl;
  cout<<setw(100)<<right<<"+                                                               +"<<endl;
  cout<<setw(100)<<right<<"+---------------------------------------------------------------+"<<endl;
  cout<<setw(100)<<right<<"+              1-Entrer les valeur de xi et yi                  +"<<endl;
  cout<<setw(100)<<right<<"+              2-Tous sur la serie statistique Xi               +"<<endl;
  cout<<setw(100)<<right<<"+              3-Tous sur la serie statistique Yi               +"<<endl;
  cout<<setw(100)<<right<<"+              4-Etude sur les 2 serie                          +"<<endl;
  cout<<setw(100)<<right<<"+---------------------------------------------------------------+"<<endl;
  cout<<endl<<"Entrer votre  choix: ";
  cin>>choix;
  switch(choix){
    case 1:
      commencer_entrer();
    break;
    case 2:
      Etude_serie(Data.Xi,"Xi");
    break;
    case 3:
      Etude_serie(Data.Yi,"Yi");
    break;
    case 4:
       two_serie();
     break;
  }
  cout<<endl;
}
void stat::sous_affiche1(){
unsigned int i=0;
    cout<<setfill('-');
    cout<<setw(22)<<left<<'+';
     while(i<Data.Xi.size()){
      cout<<setw(10)<<left<<'+';
      i++;
     }
     cout<<'+'<<endl;
}
void stat::sous_affiche2(vector<float>dt,string type){
 unsigned int i=0;
    cout<<setfill(' ');
    cout<<"|"<<setw(19)<<"Serie Statistique"<<type;
     while(i<dt.size()){
        cout<<"|"<<setw(9)<<left<<dt[i];
        i++;
     }
     cout<<"|"<<endl;
}
void stat::affiche_tab(){
    cout<<endl<<"Voici le tableau"<<endl;
   if( Data.Xi.size() && Data.Yi.size() ){
     sous_affiche1();
     sous_affiche2(Data.Xi,"Xi");
     sous_affiche1();
     sous_affiche2(Data.Yi,"Yi");
     sous_affiche1();
   }
}
void stat::Entrer_X(){
  float dt;
  cout<<"Entrer un autre caractere que de chiffre"<<endl;
  cout<<"si vous ne voulez plus entrer de valeur Xi"<<endl;
  cout<<"Entrer valeur des Xi: ";
  while((cin>>dt)){
   cout<<setw(21)<<": ";
   Data.Xi.push_back(dt);
  }
}
void stat::Entrer_Y(){
  float dt;
  cout<<"Entrer un autre caractere que de chiffre"<<endl;
  cout<<"si vous ne voulez plus entrer de valeur Yi"<<endl;
  cout<<"Entrer valeur des Yi: ";
  while((cin>>dt)){
   cout<<setw(21)<<": ";
   Data.Yi.push_back(dt);
  }
}
void stat::saut(){
 cin.clear();
 cin.ignore(255,'\n');
}
void stat::commencer_entrer(){
   Entrer_X();
   saut();
   Entrer_Y();
   affiche_titre();
   affiche_tab();
   message();
}
/*Calcul*/
float stat::Variance(std::vector<float>dt,float Xbar){
   unsigned int i=0,n=dt.size();
   float somme, variance;
 while(i<n){
     somme=somme+pow(dt[i],2);
    i++;
 }
 somme=static_cast<float>(somme)/n;
 variance=somme-pow(Xbar,2);
  return variance;
}
float stat::Moyenne(std::vector<float>dt){
   unsigned int i=0,n=dt.size();
   float somme;
  while(i<n){
    somme=somme+dt[i];
    i++;
  }
  return static_cast<float>(somme)/n;
}
void stat::Etude_serie(std::vector<float>dt,string type){
 if(dt.empty()){
    cout<<"Tableau est vide"<<endl;
 }
 else{
  unsigned int n=dt.size();
  float p;//ordre de quantile
  int res;//resultat n*p
  float Xbar,Etendue,variance;
  vector<float>trie=dt;
  cout<<endl<<"      a-Moyenne empirique: "<<endl<<endl;
  Xbar=Moyenne(dt);
  cout<<" Moyenne  vaut: "<<Xbar<<endl;
  sort(begin(trie),end(trie));
  cout<<endl<<"      b-Mediane:"<<endl<<endl;
  cout<<" On trie cette serie puis on obtient: "<<endl;
  sous_affiche1();
  sous_affiche2(trie,type);
  sous_affiche1();
  if(dt.size()%2){
    cout<<" Mediane vaut: "<< trie[((n+1)/2)-1]<<endl;
  }
   else{
    cout<<" Mediane vaut: "<< (trie[(n/2)-1]+trie[((n/2)+1)-1])/2<<endl;
   }
  cout<<endl<<"     c-Quantile d'ordre:"<<endl<<endl;
  cout<<" On a "<<n<<" observation. "<<endl;
  p=0.25;
  res=p*n;
  if(res<p*n){
    res++;
    cout<<"Le premier quantile vaut: "<<trie[res-1]<<endl;
  }
  else{
    cout<<"Le premier quantile vaut: "<<(trie[(res/2)-1]+trie[((res/2)+1)-1])/2;
  }
    p=0.75;
  res=p*n;
  if(res<p*n){
    res++;
    cout<<"Le Troisieme quantile vaut: "<<trie[res-1]<<endl;
  }
  else{
    cout<<"Le Troisieme quantile vaut: "<<(trie[(res/2)-1]+trie[((res/2)+1)-1])/2<<endl;
  }
  cout<<endl<<"     d-Etendue"<<endl<<endl;
  Etendue=trie[n-1]-trie[0];
  cout<<"  l'etendue de cette serie vaut: "<<Etendue;
  cout<<endl<<endl<<"     d-Variance"<<endl<<endl;
  variance=Variance(dt,Xbar);
  cout<<"  la variance de cette serie vaut: "<<variance;
  cout<<" Et ecart type vaut : "<<sqrt(variance)<<endl;
 }
 message();
}
//covariance et coefficient de la corellation
float stat::covariance(){
    int i=0,n=Data.Xi.size();
    float somme=0,covariance;
    while(i<n){
        somme=somme+(Data.Xi[i]*Data.Yi[i]);
        i++;
    }
    somme=static_cast<float>(somme)/n;
    covariance=somme-(Moyenne(Data.Xi)*Moyenne(Data.Yi));
    return covariance;
}
void stat::two_serie(){
 float r=0;
  if(Data.Xi.size() == Data.Yi.size() &&(Data.Xi.size()!=0 && Data.Yi.size()!=0)){
    cout<<"Leur covariance  vaut : "<<covariance()<<endl;
    r=covariance()/(sqrt(Moyenne(Data.Xi))*sqrt(Moyenne(Data.Yi)));
    cout<<"et que la coefficient de correlation vaut r: "<<r<<endl;
    if(r<0){
        cout<<"Tous les point sont alignees le long d'une droite decroissant"<<endl;
    }
    else if(r>0){
        cout<<"Tous les point sont alignees le long d'une droite croissant"<<endl;
    }
    else{
        cout<<"Les points ne sont pas alignees"<<endl;
    }
    cout<<"on obtient une droite y=ax+b"<<endl;
    cout<<"avec a vaut : "<< covariance()/Variance(Data.Xi,Moyenne(Data.Xi));
    cout<<endl<<"et que b vaut "<<Moyenne(Data.Yi)-(covariance()/Variance(Data.Xi,Moyenne(Data.Xi))*Moyenne(Data.Xi))<<endl;
  }else{
   cout<<"il y a une erreur"<<endl;
   system("exit");
  }
  message();
}
