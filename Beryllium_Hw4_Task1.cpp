#include <iostream>
using namespace std;
/*  Structures/Constants */
class HouseInfo{
private:
    int streetNum;
    char streetName[30];
    double price;
public:
    HouseInfo():streetNum(0), streetName(""), price(0.0){}   //Empty Constructor
    HouseInfo(int sNum, char sName[30], double p): streetNum(sNum), streetName(sName), price(p){}
};

// Function prototypes
class HouseInfo InputHouse(void);
void PrintHouse(int houseNum, class HouseInfo h);
int ComparePrices(class HouseInfo h1, class HouseInfo h2);

/* Main Program */
int main(int argc, char* argv[])
{
    cout<<"Enter info for first house\n";
    class HouseInfo firstHouse = InputHouse();
    cout<<"\nEnter info for second house\n";
    class HouseInfo secondHouse = InputHouse();

    PrintHouse(1, firstHouse);
    printf("\n\n");
    PrintHouse(2, secondHouse);
    printf("\n\n");

    int comparison = ComparePrices(firstHouse, secondHouse);
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
    HouseInfo newHouse;
    cout << "Please enter the house number:" << endl;
    cin >> newHouse.streetNum;
    cout << "Please enter the street name:" << endl;
    cin >> newHouse.streetName;
    cout << "Please enter the price:" << endl;
    cin >> newHouse.price;

    return newHouse;
}

void PrintHouse(int houseNum, class HouseInfo h){
    cout << houseNum << " house at: " << h.streetNum << " " << h.streetName << " for $[" << h.price << "]";
}

int ComparePrices(class HouseInfo h1, class HouseInfo h2){
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
