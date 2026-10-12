#include <iostream>

using namespace std;

class CoeurNucleaire {
    private:
        double temperature;
        bool en_marche;
    public:
        double get_temperature(){
            return temperature;
        }
        bool get_enmarche(){
            return en_marche;
        }
        void modifierTemperature(double nouvelle_temp){
            if (nouvelle_temp < -237){
                nouvelle_temp = 0;
                cout << "la température ne peut etre en dessous de 273";
            }
            else if (nouvelle_temp > 1000){
                en_marche = false;
                temperature = 50;

            }
            else{
                temperature = nouvelle_temp;
            }
        }
        void stopper(){
            en_marche = false;
        }

        CoeurNucleaire(){
            en_marche = false;
            temperature = 20;

        }
        CoeurNucleaire(double temp, bool etat){
            modifierTemperature(temp);
            en_marche = etat;
        }
        ~CoeurNucleaire(){
            cout << "Demantelement du coeur temperature finale " << temperature << "\n";
        }
};

void arretUrgence(CoeurNucleaire& Coeur){
    Coeur.modifierTemperature(0);
    Coeur.stopper();

}
int main(){

    cout<< "---DEMARAAGE---\n";
    {
        CoeurNucleaire tchernobyl(800,true);
        tchernobyl.modifierTemperature(1500);
        arretUrgence(tchernobyl);

    }
    cout << "---FIN---\n";
    return 0;

}
