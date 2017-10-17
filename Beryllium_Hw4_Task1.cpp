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
    void printHouse(int houseNum){
        cout << houseNum << " house at: " << streetNum << " " << streetName << " for $[" << price << "]\n";
    }
    double getPrice(){
        return price;
    }
};

// Function prototypes
class HouseInfo InputHouse(void);
void ComparePrices(HouseInfo h[3]);

/* Main Program */
int main(int argc, char* argv[])
{
    cout<<"Enter info for first house\n";
    class HouseInfo firstHouse = InputHouse();
    cout<<"\nEnter info for second house\n";
    class HouseInfo secondHouse = InputHouse();
    cout << "\nEnter info for third house\n";
    class HouseInfo thirdHouse = InputHouse();
    cout << "\n";

    HouseInfo h[3] = {firstHouse, secondHouse, thirdHouse};

    ComparePrices(h);

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

void ComparePrices(HouseInfo h[3]){
    double h1price, h2price, h3price;
    h1price = h[0].getPrice();
    h2price = h[1].getPrice();
    h3price = h[2].getPrice();

    //Use this to discover which house is the least expensive
    //Start with the assumption that the first house is the least expensive
    double comparison = h1price;
    if(h2price < comparison){
        comparison = h2price;
    }
    if(h3price < comparison){
        comparison = h3price;
    }

    h[0].printHouse(1);
    h[1].printHouse(2);
    h[2].printHouse(3);

    cout << "\nYou should buy: ";

    if(h1price == comparison){
        cout << "House Number 1\n";
    }
    if(h2price == comparison){
        cout << "House Number 2\n";
    }
    if(h3price == comparison){
        cout << "House Number 3\n";
    }

    return;
}
