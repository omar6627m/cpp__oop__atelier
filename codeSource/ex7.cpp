#include <iostream>
#include <math.h>

using namespace std;

class vecteur3d{
    public:
    float x,y,z;
    vecteur3d();
    vecteur3d(float xValue,float yValue,float zValue);
    void display();
    static vecteur3d sumOfTwo(vecteur3d v1,vecteur3d v2);
    static float produitScalaire(vecteur3d v1,vecteur3d v2);
    static bool isEqual(vecteur3d v1,vecteur3d v2);
    float norme();
    static vecteur3d normax(vecteur3d v1,vecteur3d v2,char v);
    static vecteur3d* normax(vecteur3d* v1,vecteur3d* v2);
    static vecteur3d& normax(vecteur3d& v1,vecteur3d& v2);

};

// un constructeur, avec des valeurs par défaut (0):
vecteur3d::vecteur3d(){
    x=0;
    y=0;
    z=0;
}

// constructeur
vecteur3d::vecteur3d(float xValue,float yValue,float zValue){
    x=xValue;
    y=yValue;
    z=zValue;
}

// methode d'ffichage:
void vecteur3d::display(){
    cout << "(x,y,z) = (" << x << "," << y << "," << z << ")\n";
}

// une fonction permettant d’obtenir la somme de 2 vecteurs:
vecteur3d vecteur3d::sumOfTwo(vecteur3d v1,vecteur3d v2){
    vecteur3d result = vecteur3d(v1.x + v2.x,v1.y + v2.y,v1.z + v2.z);
    return result;
}

// une fonction permettant d’obtenir le produit scalaire de 2 vecteurs.
float vecteur3d::produitScalaire(vecteur3d v1,vecteur3d v2){
    float result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    return result;
}

//une fonction coincide permettant de savoir si 2 vecteurs ont mêmes composantes:
bool vecteur3d::isEqual(vecteur3d v1,vecteur3d v2){
    if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
    {
        return true;
    }else{
        return false;
    }
    
}

//une fonction qui renvoie la norme du vecteur:
float vecteur3d::norme(){
    float result = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    return result;
}

// une fonction nommée normax permettant d’obtenir, parmi deux vecteurs, 
// celui qui a la plus grande norme.
//  1-par valeur:
vecteur3d vecteur3d::normax(vecteur3d v1,vecteur3d v2,char v){
    if (v1.norme() > v2.norme())
    {
        return v1;
    } else{
        return v2;
    }
}

//  2-par addresse:
vecteur3d* vecteur3d::normax(vecteur3d* v1,vecteur3d* v2){
    if (v1->norme() > v2->norme())
    {
        return v1;
    } else{
        return v2;
    }
}

//  3-par reference:
vecteur3d& vecteur3d::normax(vecteur3d& v1,vecteur3d& v2){
    if (v1.norme() > v2.norme())
    {
        return v1;
    } else{
        return v2;
    }
}

int main(int argc, char const *argv[])
{
    vecteur3d vect1 = vecteur3d(1,2,3);
    vecteur3d vect2 = vecteur3d(4,5,6);
    vecteur3d vect3 = vecteur3d(4,5,6);
    vecteur3d vect4 = vecteur3d();

    // display() , norme()
    vect1.display();
    cout << "norme:" << vect1.norme() << endl;
    vect2.display();
    cout << "norme:" << vect2.norme() << endl;
    vect3.display();
    cout << "norme:" << vect3.norme() << endl;
    vect4.display();
    cout << "norme:" << vect4.norme() << endl;

    // sumOfTwo(), produitScalaire(), isEqual()
    vect4 = vecteur3d::sumOfTwo(vect1,vect2);
    vect4.display();
    cout << "produit scalaire de vect1 et vect2: " 
         << vecteur3d::produitScalaire(vect1,vect2) << endl;
    cout << "vect1 == vect2 ? " << vecteur3d::isEqual(vect1,vect2) << endl; 
    cout << "vect3 == vect2 ? " << vecteur3d::isEqual(vect3,vect2) << endl; 

    // normax()
    vecteur3d* vect5 = vecteur3d::normax(&vect1,&vect2);
    vect5->display();
    vecteur3d& vect6 = vecteur3d::normax(vect1,vect2);
    vect6.display();
    vecteur3d vect7 = vecteur3d::normax(vect1,vect2,'v');
    vect7.display();
    
    return 0;
}
