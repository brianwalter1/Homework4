#include <iostream>
#include <string>
using namespace std;
/*  Structures/Constants */
class HouseInfo{
private:
    int streetNum;
    string streetName;
    double price;
public:
    HouseInfo():streetNum(0), streetName(""), price(0.0){}   //Empty Constructor
    HouseInfo(int sNum, string sName, double p): streetNum(sNum), streetName(sName), price(p){}
    void updateInfo(){
        cout << "Enter new house number: ";
        cin >> streetNum;
        cout << "Enter new street name: ";
        cin.ignore();
        getline(cin, streetName);
        cout << "Enter new price: ";
        cin >> price;
    }
};

// Function prototypes
class HouseInfo InputHouse(void);
void PrintHouse(int houseNum, class HouseInfo h);
int ComparePrices(HouseInfo h[3]);

/* Main Program */
int main(int argc, char* argv[])
{
    cout<<"Enter info for first house\n";
    class HouseInfo firstHouse = InputHouse();
    cout<<"\nEnter info for second house\n";
    class HouseInfo secondHouse = InputHouse();
    cout << "\nEnter info for third house\n";
    class HouseInfo thirdHouse = InputHouse();

    PrintHouse(1, firstHouse);
    printf("\n\n");
    PrintHouse(2, secondHouse);
    printf("\n\n");

    HouseInfo h[3] = {firstHouse, secondHouse, thirdHouse};

    int comparison = ComparePrices(h);
    switch(comparison){
        case 1 : cout << "The first house is cheaper."; break;
        case 2 : cout << "The two houses are equally expensive."; break;
        case 3 : cout << "The second house is cheaper."; break;
        default : cout << "Invalid comparison value"; break;
    }

    return 0;
}

/* Function Defenitions */
class HouseInfo InputHouse(void){
    int streetNum;
    string streetName;
    double price;
    
    cout << "Enter new house number: ";
    cin >> streetNum;
    cout << "Enter new street name: ";
    cin.ignore();
    getline(cin, streetName);
    cout << "Enter new price: ";
    cin >> price;

    HouseInfo newHouse(streetNum, streetName, price);

    return newHouse;
}

void PrintHouse(int houseNum, class HouseInfo h){
    cout << houseNum << " house at: " << h.streetNum << " " << h.streetName << " for $[" << h.price << "]";
}

int ComparePrices(HouseInfo h[3]){
    int comparison;
    if(h1.price < h2.price){
        comparison = 1;
    } else if(h1.price > h2.price){
        comparison = 3;
    } else{
        comparison = 2;
    }

    return comparison;
}
