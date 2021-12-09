#include <iostream>

using namespace std;

class Test{
    public:
    //variable static pour reserver la valeur
    static int callCounter;

    static void call(){
        callCounter++;
        cout << "combien de fois call a ete appelee " << callCounter << endl;
    }
};

// inisialisation de callCounter
int Test::callCounter = 0;

int main(int argc, char const *argv[])
{
    // appele de fonction call()
    Test::call();
    Test::call();
    Test::call();
    Test::call();
    return 0;
}
