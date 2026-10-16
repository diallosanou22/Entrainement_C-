#include <iostream>

using namespace std;

class Document {
    protected:
        string titre;
        int taille_octets;
    public:
        Document(string title,int taille){
            titre = title;
            taille_octets =taille;
        }
        virtual ~Document() = default;
        virtual void ouvrir () = 0;
        virtual void afficherMetadonnees() = 0;
};


class DocumentPublic : public Document {
    public:
        DocumentPublic(string title , int taille): Document(title,taille){};
        void ouvrir(){
            cout << "Lecture en clair du document : " << titre << "\n";
        }
        void afficherMetadonnees(){
            cout << "[PUBLIC] Titre : " << titre << "Taille : " << taille_octets << "Mo \n";
        }

};

class DocumentSecretDefense : public Document {
    protected:
        string mot_de_passe;
        int compt_acces;
    public:
        DocumentSecretDefense(string title,int taille,string cle) : Document(title,taille){
            mot_de_passe = cle;
            compt_acces = 0;
        }

        void ouvrir(){
            string mot_de_passe_test = "ALPHA123";
            if (mot_de_passe_test == mot_de_passe){
                compt_acces = compt_acces + 1;
                cout << "Dechiffrement AES-256 reussi. Lecture de " << titre << "\n";

            }
            else {
                cout << "ALERTE INTRUSION : Destruction automatique du document en cours... \n";
            }
        }

        void afficherMetadonnees(){
            cout << "[SECRET DEFENSE] Titre : " << titre << "Taille : " << taille_octets << "Mo" << " consulté : " << compt_acces << "fois \n";
        }

};

class CoffreFort{
    protected:
        Document* inventaire[5];
        int nb_documents;
    public:
        CoffreFort(){
            nb_documents = 0;
        }
        virtual ~CoffreFort(){
            for(int i = 0; i < nb_documents; i++){
                delete inventaire[i];
                
            }
            cout << "Coffre verrouille et memoire purgee. \n";
        }

        void ajouterDocument(Document* doc){
            if (nb_documents < 5 ){
                inventaire[nb_documents] = doc;
                nb_documents += 1;
                cout << "Document ajoute au coffre \n" ;

            }
            else {
                cout << "Erreur : Le coffre est plein. \n";
            }
        }

        void inspecterCoffre(){
            for(int i = 0 ; i < nb_documents; i++){
                inventaire[i]->afficherMetadonnees();
                inventaire[i]->ouvrir();
            }
        }

};

int main(){
    CoffreFort coffre;
    Document *ptr_doc_pub = new DocumentPublic("Rapport_Mairie",2);
    Document* ptr_doc_secret = new DocumentSecretDefense("Codes_Nucleaires",15,"ALPHA123");
    coffre.ajouterDocument(ptr_doc_pub);
    coffre.ajouterDocument(ptr_doc_secret);

    Document* ptr_doc_secret_def2 = new DocumentSecretDefense("Liste_Agents",5,"OMEGA99");
    coffre.ajouterDocument(ptr_doc_secret_def2);
    coffre.inspecterCoffre();

    return 0;
    
    
}
