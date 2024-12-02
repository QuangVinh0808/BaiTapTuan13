#include <iostream>

using namespace std;

int listProduct[50]; // Giả sử có 50 sp

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
        listProduct[tmp->ID]++;
        cout << "Da thanh toan san pham co ID: " << tmp->ID << " voi gia: " << tmp->price << " VND\n";

        delete tmp;
    }
}


int main()
{
    Cashier* Vinh = new Cashier();

    //Các sản phẩm xếp hàng thanh toán 
    addProduct(Vinh, 0001, 200000);
    addProduct(Vinh, 0002, 150000);
    addProduct(Vinh, 0003, 300000);
    addProduct(Vinh, 0001, 50000);
    
    payMoney(Vinh);
    payMoney(Vinh);
    payMoney(Vinh);
    payMoney(Vinh);

    char a;
    do{
        cout << "Ban muon kiem tra so luong cua san pham nao ? Hay nhap ID !\n";
        int x;
        cin >> x;
        cout << "San pham co ID: " << x << " duoc ban voi so luong : " << listProduct[x] << '\n';
        cout << "Ban co muon kiem tra nua khong ?(Y/N)\n";
        cin >> a;
    }while(a == 'Y' || a == 'y');
}