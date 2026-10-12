#include <iostream>

using namespace std;




int main(){

    int min = 0;
    int max = 0;
    int moyenne = 0;
    

    cout << "Nous allons additionner deux nombres saisis directement sur le terminal "<< endl;
    cin >> min;
    cin >> max;
    moyenne = (min + max)/2;
    cout << "la valeur moyenne est " << moyenne << endl;   
    return 0;
}
