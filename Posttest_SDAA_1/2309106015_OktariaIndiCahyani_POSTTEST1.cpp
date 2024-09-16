#include <iostream>
using namespace std;

void hanoitower(int jmlpiringan, char menaraasal, char menaratujuan, char menarasementara){
    if (jmlpiringan == 0){
        return;
    }

    if (jmlpiringan == 1){
        cout << "Pindahkan piringan 1 dari " << menaraasal << " ke " << menaratujuan << endl;
        return;
    }

    hanoitower(jmlpiringan - 1, menaraasal,menarasementara, menaratujuan);
    cout << "Pindahkan piringan " << jmlpiringan << " dari " << menaraasal << " ke " << menaratujuan << endl;

    hanoitower(jmlpiringan - 1, menarasementara, menaratujuan, menaraasal);

}

int main() {
    int jmlpiringan;
    cout << "Masukan jumlah piringan: ";
    cin >> jmlpiringan;

    hanoitower(jmlpiringan, 'A', 'C', 'B');

    return 0;
}