#include <iostream>

using namespace std;

// definition de class
class Complex
{
public:
    float real;
    float imaginary;
    void setValue(float re,float im);
};

// fonction pur changer les variable real,imaginaire 
void Complex::setValue(float re,float im)
{
    real = re;
    imaginary = im;
}
//fonction prend deux parametre de type (class) Complex
// et retourne un variable de meme type Complex
Complex arithmetics(Complex first,Complex second){
    Complex result; // pour stocker la resultat 
    float tempRe,tempIm;
    char operation ;
    //on montre les operations possible a l'utilisateur
    cout << "Operation: \n";
    cout << "1: +\n";
    cout << "2: -\n";
    cout << "3: *\n";
    cout << "4: /\n";
    cin >> operation;

    // on applique directement les regle des operation des nombres complex
    // selon l'operation choisi par l'utilisateur 
    switch (operation)
    {
    case '1':
         result.setValue(first.real + second.real,first.imaginary + second.imaginary);
        break;
     case '2':
         result.setValue(first.real - second.real,first.imaginary - second.imaginary);
        break;
     case '3':
        tempRe = first.real * second.real - first.imaginary * second.imaginary;
        tempIm = first.real * second.imaginary + first.imaginary * second.real;
        result.setValue(tempRe,tempIm);
        break;
     case '4':
        tempRe = (first.real * second.real + first.imaginary * second.imaginary) /
                (second.real * second.real + second.imaginary * second.imaginary);
        tempIm = (first.imaginary * second.real - first.real * second.imaginary) /
                (second.real * second.real + second.imaginary * second.imaginary);
        result.setValue(tempRe,tempIm);
        break;
    }

    return result;
    
}

int main(int argc, char const *argv[])
{
    float tempRe,tempIm;

    // creation de deux nombre complex
    Complex z1,z2;
    
    // on demande des valeur 
    cout << "entre la valeur reel: " << endl;
    cin >> tempRe;
    cout << "entre la valeur imaginaire: " << endl;
    cin >> tempIm;
    z1.setValue(tempRe,tempIm);

    cout << "entre la valeur reel: " << endl;
    cin >> tempRe;
    cout << "entre la valeur imaginaire: " << endl;
    cin >> tempIm;
    z2.setValue(tempRe,tempIm);

    // appele de la fonction
    cout << "le Nombre z1: " << z1.real << " + " << z1.imaginary << "i \n";
    cout << "le Nombre z2: " << z2.real << " + " << z2.imaginary << "i \n";
    Complex result = arithmetics(z1,z2);

    // affichage de la resultat de l'operation
    cout << "la resultat est: " << result.real << " + " << result.imaginary << "i \n";

    return 0;
}

