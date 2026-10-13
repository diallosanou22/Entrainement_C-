#include <iostream>


using namespace std;

class SmartCard{
    private : 
        int cle;
        bool verrou;
        int compt_alerte;
    
        public:
            SmartCard(int kley){
                cle = kley;
                verrou = true;
                compt_alerte = 0;

                cout << "Module initialisé avec clé personnalisé \n";
            }

            SmartCard (){
                cle = 9999;
                verrou = true;
                compt_alerte = 0;

                cout << "Module par défaut créé \n";
            }
            
            ~SmartCard(){
                cout << "Auto-destruction mémoire clé finale :" << cle << "\n";
            }

            void deverouillage(){
                verrou = false;
            }
            int retrait_cle(){
                if(verrou == false){
                    cout << "la clé est : " << cle << "\n";
                    return cle;
                }
                else{
                    compt_alerte = compt_alerte + 1;
                    cout << " ALERTE INTRUSION \n";
        
                

                if (compt_alerte == 3){
                    cle = 0;

                }
                return -1;
            }
            }



};

void attaqueHacker(SmartCard& module1){
    for (int i = 0; i < 3 ; i++){
        module1.retrait_cle();
    }
}

int main(){
    cout << "--- DEBUT DU TEST ---\n";
    {
        SmartCard card(777);
        attaqueHacker(card);

    }
    cout << " --- FIN DU TEST --- \n";
    return 0;
}