#include <iostream>

using namespace std;

// definition de myClass
class myClass
{
public:
    string userString; //variable rempli par l'utilisateur
    myClass();
    myClass(string userInput);
    ~myClass();
};
// default constructor
myClass::myClass()
{
    cout << "default constructor invoked with default output\n";
}

//constructor with parameters
myClass::myClass(string userInput){
    userString = userInput;
    cout << userString << "\n";
}
//decostructor appele par tous les instances quand le programme termine
myClass::~myClass(){
    cout << userString << "\n";
}

int main(int argc, char const *argv[])
{
    // un instance utilisant la constrecteur par default
    myClass first = myClass();

    string temp;
    cout << "enter a string\n";
    getline(cin,temp);
    // un instance utilisant la constructeur parametre
    myClass second = myClass(temp);
    return 0;
}
