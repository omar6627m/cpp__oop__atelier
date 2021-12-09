#include <iostream>
using namespace std;

// definition de class Mere base
class Mere {
public:
	void display(){
		cout << "display de mere\n";
	}
};

// definition de class Fille heritee de class Mere
class Fille : public Mere{
public:
	// faire un "override" de la fonction display()
	void display(){
		cout << "display de fille\n";
	}
};

int main(int argc, char const *argv[])
{
	// creation des instances de deux class
	Mere mere1 ;
	mere1.display(); // display() de Mere
	Fille fille1;
	fille1.display(); // display() de Fille
	return 0;
}