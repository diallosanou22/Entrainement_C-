#include <iostream>

using namespace std;

/*class Machine {
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
*/




class Vehicule {
    protected:
        int nb_roues;
        string marque;
    public:
        Vehicule(int r , string m){
            nb_roues = r;
            marque = m;
            cout << "Fabrication d'un vehicule " << marque << "a " << nb_roues << " roues. \n";

        }
        virtual ~Vehicule() = default; // Destructeur virtuel par défaut
        virtual void faireLePlein(){
            cout << "Je mets du carburant dans le reservoir";
        }

};


class Moto : public Vehicule {
    public:
        Moto(string m) : Vehicule(2,m){
            cout << "la moto est assemblee \n";
        }

};


class Camion : public Vehicule {
    private : 
        int charges_max;
    public:
        Camion(string m , int charge) : Vehicule(6,m){
            charges_max = charge;
            cout << "Le camion est pret. Capacite : " << charges_max << " tonnes. \n";
        }
        void faireLePlein() override {
           // Vehicule ::faireLePlein();
            cout << " Et je remplis aussi la citerne arriere ! \n";
        }

};
/*


class Animal {
public:
    virtual void parler() {
        cout << "L'animal fait un bruit\n";
    }
};

class Chien : public Animal {
public:
    void parler() {
        cout << "Le chien aboie : wouf !\n";
    }
};

class Chat : public Animal {
public:
    void parler() {
        cout << "Le chat miaule : miaou !\n";
    }
};
*/



int main(){

    /*Ordinateur mon_pc;
    mon_pc.afficherEtat();
    mon_pc.appuyerBoutonPower();
    mon_pc.afficherEtat();
    */

    Vehicule* mon_ptr_camion = new Camion("Volvo",40);
    mon_ptr_camion->faireLePlein();
    /*
    Moto moto("Yamaha");
    Camion camion("Volvo",40);
    

    Camion camion("BMW",150);
    camion.faireLePlein();
    */

  
     /*Chien rex;
    Chat felix;

    rex.parler();
    felix.parler();
    

    Animal *animal = &rex;
    animal->parler();

   */
    delete mon_ptr_camion;
    return 0;
}