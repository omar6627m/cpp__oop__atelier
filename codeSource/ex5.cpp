#include <iostream>

using namespace std;

// definition de class Animal base
class Animal{
    public:
        string name;
        int age;
        void setValue(string n,int a);
};

// pour attribuer des valeur
void Animal::setValue(string n, int a){
    name = n;
    age = a;
}

// definition de class Zebra heritee de class Animal
class Zebra : public Animal{
    public:
        string location;
        void setValue(string n,int a,string loc);
        void displayInfo();
};

void Zebra::setValue(string n,int a,string loc){
    name = n;
    age = a;
    location = loc;
}

// definition de fonction displayInfo() pour la class Zebra
void Zebra::displayInfo(){
    cout << "l'age: " << age << "\nle nom: " << name 
         << "\nlieu d'origine: " << location << endl;
}

// definition de class Dolphin heritee de class Animal
class Dolphin : public Animal{
    public:
        string location;
        string food;
        void setValue(string n,int a,string loc,string fd);
        void displayInfo();
};

void Dolphin::setValue(string n,int a,string loc,string fd){
    name = n;
    age = a;
    location = loc;
    food = fd;
}

// definition de fonction displayInfo() pour la class Dolphin
void Dolphin::displayInfo(){
    cout << "l'age: " << age << "\nle nom: " << name
         << "\nlieu d'origine: " << location << "\nfood: " << food << endl;
}


int main(int argc, char const *argv[])
{
	// creation des instances de deux class
    Zebra zebra1;
    zebra1.setValue("juvi",4,"italy");

    Dolphin dol;
    dol.setValue("dolli",2,"sea","bread");

    // appeler a la methode displayInfo() pour les deux sous Class: 
    zebra1.displayInfo();
    dol.displayInfo();
  
    
    return 0;
}
