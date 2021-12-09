#include <iostream>

using namespace std;

//class base Media
class Media{
    public:
    string titre;
    Media(string t);
    virtual void imprimer();
    char* id();
};

// constructeur de Media
Media::Media(string t):titre(t){}

// fonction imprimer()
void Media::imprimer(){
    cout << "titre: " << titre << endl;
}

//des class heritee: Audio, Livre et Presse
class Audio : public Media{
    public:
    int longeur;
    bool paused;
    Audio(string t,int lon);
    virtual void imprimer();
    void pausePlay();
};

// constructeur
Audio::Audio(string t,int lon):Media(t),longeur(lon),paused(true){}
// les methodes
void Audio::imprimer(){
    Media::imprimer();
    cout << "longeur: " << longeur << endl;
    cout << "paused: " << paused << endl;
}
void Audio::pausePlay(){
    paused = !paused;
}
// Heritee de Audio
class Cassete :  public Audio{
    public:
    int itemsNumber;
    Cassete(string t,int lon,int num);
};
Cassete::Cassete(string t,int lon,int num):Audio(t,lon),itemsNumber(num){}

class Cd :  public Audio{
    public:
    int itemsNumber;
    Cd(string t,int lon,int num);
};
Cd::Cd(string t,int lon,int num):Audio(t,lon),itemsNumber(num){}

class Disk :  public Audio{
    public:
    int itemsNumber;
    Disk(string t,int lon,int num);
};
Disk::Disk(string t,int lon,int num):Audio(t,lon),itemsNumber(num){}

// ==============
class Livre : public Media{
    public:
    int page;
    Livre(string t,int p);
    virtual void imprimer();
    void tournerPage();
};

// constructeur
Livre::Livre(string t,int p):Media(t),page(p){}
// les methodes
void Livre::imprimer(){
    Media::imprimer();
    cout << "page: " << page << endl;
}
void Livre::tournerPage(){
    page++;
}
// ==============
class Presse : public Media{
    public:
    string editeur;
    Presse(string t,string ed);
    virtual void imprimer();
};

// constructeur
Presse::Presse(string t,string ed):Media(t),editeur(ed){}
// les methodes
void Presse::imprimer(){
    Media::imprimer();
    cout << "editeur: " << editeur << endl;
}
// Heritee de Presse
class Revue :  public Presse{
    public:
    Revue(string t,string ed);
};
Revue::Revue(string t,string ed):Presse(t,ed){}

class Journal :  public Presse{
    public:
    Journal(string t,string ed);
};
Journal::Journal(string t,string ed):Presse(t,ed){}

class Magazine :  public Presse{
    public:
    Magazine(string t,string ed);
};
Magazine::Magazine(string t,string ed):Presse(t,ed){}

int main(int argc, char const *argv[])
{
    Media* ptr;
    ptr = new Media("FSTT MEDIA CENTER");
    ptr->imprimer();
    delete ptr;

    cout << "=========\n";

    ptr = new Audio("FSTT Audio",30);
    ptr->imprimer();
    delete ptr;
    
    cout << "=========\n";

    ptr = new Livre("FSTT Books",300);
    ptr->imprimer();
    
    return 0;
}