#include <iostream>

using namespace std ;


class ProgrammeCyber{
    protected: 
        string nom_code;
        int niveau_urgence;

    public:
        virtual ~ProgrammeCyber() = default;
        ProgrammeCyber(string nom , int niveau){
            nom_code = nom;
            niveau_urgence = niveau;
            cout << "Initialisation du programme :  "<< nom_code << "\n";
        }
        virtual void scannerReseau(){
            cout << nom_code << " effectue un scan des ports standard. \n";

        }
       virtual void executerMission() = 0;

};

class VerInformatique : public ProgrammeCyber {
    protected:
        string cible_ip;

    public:
        VerInformatique(string nom ,int niveau,string cible):ProgrammeCyber(nom,niveau){
            cible_ip = cible;
        }
        
        void scannerReseau() override {
            ProgrammeCyber :: scannerReseau();
            cout << "VerInformatique cherche des failles sur l'IP :" << cible_ip << "\n";
        }

        void executerMission() {
            cout << "!! ALERTE ROUGE : Propagation du ver depuis " << nom_code << "\n";
        }
};

class BouclierHeuristique : public ProgrammeCyber {

    protected:
        int ports_bloques;
    public:
        BouclierHeuristique(string nom,int niveau,int nbres_ports): ProgrammeCyber(nom,niveau){
            ports_bloques = nbres_ports;
        }
        void scannerReseau() override{
            cout << "Bouclier actif : Analyse profonde de la RAM en cours...\n";
        }
        void executerMission(){
            cout << "DEFENSE :" << nom_code <<" a verrouille " << ports_bloques <<"ports critiques.\n";
        }


};

int main(){

    ProgrammeCyber* ptr_Cyber[2];
    ptr_Cyber[0] = new VerInformatique("Stuxnet",5,"192.168.1.100");
    ptr_Cyber[1] = new BouclierHeuristique("Defender",1,80);

    for(int i = 0; i < 2;i++){
 
        ptr_Cyber[i]->scannerReseau();
        ptr_Cyber[i]->executerMission();
        cout << "----------------------\n";

    }
    delete ptr_Cyber[0];
    delete ptr_Cyber[1];



    return 0;
}