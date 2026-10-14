#include <iostream>

using namespace std;

class Machine {
    protected :
        bool allumee = false;
    
    public:
        void afficherEtat(){
            if (allumee){
                cout << "La machine est allumee \n";
                
                }
            else{
                cout << "la machine est eteinte \n";
                }
            }

};


class Ordinateur : public Machine {
    public:
        void appuyerBoutonPower(){
            allumee = true;
        }

};

int main(){

    Ordinateur mon_pc;
    mon_pc.afficherEtat();
    mon_pc.appuyerBoutonPower();
    mon_pc.afficherEtat();

    return 0;
}