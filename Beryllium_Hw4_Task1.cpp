#include <iostream>
using namespace std;
/*  Structures/Constants */
struct house
{
    int streetNum;
    char streetName[30];
    double price;
};

// Function prototypes
struct house InputHouse(void);
void PrintHouse(int houseNum, struct house h);
int ComparePrices(struct house h1, struct house h2);

/* Main Program */
int main(int argc, char* argv[])
{
    cout<<"Enter info for first house\n";
    struct house firstHouse = InputHouse();
    cout<<"\nEnter info for second house\n";
    struct house secondHouse = InputHouse();

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
struct house InputHouse(void){
    house newHouse;
    cout << "Please enter the house number:" << endl;
    cin >> newHouse.streetNum;
    cout << "Please enter the street name:" << endl;
    cin >> newHouse.streetName;
    cout << "Please enter the price:" << endl;
    cin >> newHouse.price;

    return newHouse;
}

void PrintHouse(int houseNum, struct house h){
    cout << houseNum << " house at: " << h.streetNum << " " << h.streetName << " for $[" << h.price << "]";
}

int ComparePrices(struct house h1, struct house h2){
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
