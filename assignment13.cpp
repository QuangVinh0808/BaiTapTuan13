#include <iostream>

using namespace std;


struct Product{
    int ID; // ID san pham
    int price; // Gia san pham
    Product* next;

    Product(int _ID, int _price){
        ID = _ID;
        price = _price;
        next = NULL;
    }
};

struct Cashier{ // coi queue la 1 bàn thu ngân
    int total;
    Product* F;
    Product* R;

    Cashier() {
        total = 0;
        F = NULL;
        R = NULL;
    }
};

int isEmpty(Cashier* s){
    if(s->F == nullptr) return 1;
    return 0;
}

void addProduct(Cashier* q, int _ID, int _price){
    Product* tmp = new Product(_ID, _price);
    if(isEmpty(q))
    {
        q->F = q->R = tmp;
    }
    else{
        q->R->next = tmp;
        q->R = tmp;
    }
}

void payMoney(Cashier* q){
    if(isEmpty(q)){
        cout << "Da thanh toan het !\n";
    }
    else{
        Product* tmp = q->F;
        q->F = q->F->next;
        if(q->F == NULL) q->R = NULL;

        q->total += tmp->price;

        delete tmp;
    }
}

int main()
{

}