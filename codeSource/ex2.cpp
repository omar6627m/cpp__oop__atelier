#include <iostream>
using namespace std;

//definition de la class base Shape
class Shape
{
public:
    float largeur;
    float hauteur;
    Shape(float larg,float haut);
};

//la constrecteur de Shape 
Shape::Shape(float larg,float haut)
{
    // donner le valeur passe par l'utilisateur
    largeur = larg;
    hauteur = haut;
}

//class herite Triangle 
class Triangle : public Shape{
    public:
    Triangle(float larg, float haut);
    float area();
};

Triangle::Triangle(float larg, float haut):Shape(larg,haut){
}

//definition de fonction area qui calcule la surface 
float Triangle::area(){
    return (largeur * hauteur)/2;
}

//class herite Rectangle 
class Rectangle: public Shape{
    public:
    Rectangle(float larg, float haut);
    float area();
};

Rectangle::Rectangle(float larg, float haut):Shape(larg,haut){
}

//definition de fonction area qui calcule la surface pour la class Rectangle
float Rectangle::area(){
    return largeur * hauteur;
}

int main(int argc, char const *argv[])
{

    // demander de des dimension de l'utilisateur
    float tempLarg,tempHaut;
    cout << "entre les dimensions largeur\n";
    cin >>  tempLarg;
    cout << "entre les dimensions hauteur\n";
    cin >> tempHaut;

    //creation des instances
    Triangle tri(tempLarg,tempHaut);
    Rectangle rect(tempLarg,tempHaut);

    // utilisation de methode area()
    cout << "area of triangle: " << tri.area() << endl;
    cout << "area of rectangle: " << rect.area() << endl;

    return 0;
}
