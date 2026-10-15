#include <iostream>
using namespace std;

class AlgorithmeCrypto {
    public:
        virtual ~AlgorithmeCrypto() = default;
        virtual void chiffrer(string message) = 0;
};

class AES256 : public AlgorithmeCrypto{
    public:
        void chiffrer(string message) override {
            cout << "[AES-256] Chiffrement symetrique du message : " << message << "\n";
        }

};

class RSA4096 : public AlgorithmeCrypto{
    public:
        void chiffrer(string message) override {
            cout << "[RSA-4096] Chiffrement asymetrique du message : " << message << "\n";
        }

};

int main(){

    
    AlgorithmeCrypto* algo = new AES256();
    algo->chiffrer("MOT_DE_PASSE") ;
    delete algo;

    return 0;
}