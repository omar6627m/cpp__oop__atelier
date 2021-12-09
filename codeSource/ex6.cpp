#include <iostream>

using namespace std;

//Class Personne
class Personne {
    private:
    string nom;
    string prenom;
    string dateDeNaissance;
    public:
    Personne(string nm,string pr,string date);
    void Afficher();
};

Personne::Personne(string nm,string pr,string date){
    nom = nm;
    prenom = pr;
    dateDeNaissance = date;
}

void Personne::Afficher(){
    cout << "les données de personne: \n";
    cout << "nom: " << nom << endl;
    cout << "prenom: " << prenom << endl;
    cout << "date De Naissance: " << dateDeNaissance << endl;
}

// Class Employe 
class Employe : public Personne{
    public:
    int salaire;
    Employe(string nm,string pr,string date,int sal);
    void Afficher();
};

//constructor
Employe::Employe(string nm,string pr,string date,int sal):Personne(nm,pr,date){
    salaire = sal;
}

//redefinition de Afficher()
void Employe::Afficher(){
    Personne::Afficher();
    cout << "salaire: " << salaire << endl;
}

//class Chef

class Chef : public Employe{
    public:
    string service;
    Chef(string nm,string pr,string date,int sal,string serv);
    void Afficher();
};

// constructor
Chef::Chef(string nm,string pr,string date,int sal,string serv):Employe(nm,pr,date,sal){
    service = serv;
}

// redefinition de Afficher()
void Chef::Afficher(){
    Employe::Afficher();
    cout << "service: " << service << endl;
}

//class Directeur

class Directeur : public Chef{
    public:
    string societe;
    Directeur(string nm,string pr,string date,int sal,string serv,string soc);
    void Afficher();
};

// constructor
Directeur::Directeur(string nm,string pr,string date,int sal,string serv,string soc)
    :Chef(nm,pr,date,sal,serv){
    societe = soc;
}

// redefinition de Afficher()
void Directeur::Afficher(){
    Chef::Afficher();
    cout << "societe: " << societe << endl;
}

// fonction Main
int main(int argc, char const *argv[])
{
    // creation des instaces:
    Personne omarP = Personne("aharrar","omar","20/12/2001");
    Employe omarE = Employe("aharrar","omar E","20/12/2001",1000);
    Chef omarC = Chef("aharrar","omar C","20/12/2001",10000,"some service");
    Directeur omarD = Directeur("aharrar","omar D","20/12/2001",10000,"some service","la socite f.");

    //appeller de la methode Afucher;
    omarP.Afficher();
    cout << "=====================\n";
    omarE.Afficher();
    cout << "=====================\n";
    omarC.Afficher();
    cout << "=====================\n";
    omarD.Afficher();
    return 0;
}
