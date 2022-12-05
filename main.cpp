#include <iostream>
#include "Houses.h"
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;

void GetData(string filepath, vector<Houses>& housesset)
{
    ifstream inFile(filepath);
    if(inFile.is_open())
    {
        string line;
        getline(inFile, line);
        while(getline(inFile, line))
        {
            istringstream stream(line);
            string address;
            int price;
            int radius;
            int beds;
            int baths;
            string firstParenthesis;
            string eliminateComma;
            string tempPrice;
            string tempRadius;
            string tempBeds;
            string tempBaths;
            getline(stream,firstParenthesis, '"');

            getline(stream, address, '"'); //ends at second parenthesis

            getline(stream, eliminateComma, ',');

            getline(stream, tempPrice, ',');
            price = stoi(tempPrice);

            getline(stream, tempRadius, ',');
            radius = stoi(tempRadius);

            getline(stream, tempBeds, ',');
            beds = stoi(tempBeds);

            getline(stream, tempBaths);
            baths = stoi(tempBaths);

            Houses set(address, price, radius, beds, baths);
            housesset.push_back(set);


        }
        inFile.close();
    }

}
void mergeSortOnPrice(){

}
void mergeSortOnLocation()
{

}
void mergeLocation()
{

}
void mergePrice()
{

}
void shellSortOnPrice()
{

}
void shellSortOnLocation()
{

}
int main() {
    vector<Houses> housesSet;
    GetData("HouseDetail.csv", housesSet);
    string ignore;
    int prioritySelection = 0;
    //ask for priority if either the user want prefers price or location
    cout << "Welcome to your Real Estate Ranker!" << endl;
    cout << "In this ranker, we will display your top 5 home option based on your priority" << endl;
    cout << "The priorities that you can select are either price or location nearest you" << endl;
    cout << "ARE YOU READY?" << endl;
    cin >> ignore;
    cout << "Which priority do you prefer? Price(insert 1) or Location(insert 2)" << endl;
    cin >> prioritySelection;

    //if the user picks price, we will perform shell and merge sort on the price values
    //if the user picks location, we will perform shell and merge sort on the radius values
    if(prioritySelection == 1)
    {
        //call merge and shell sort on price

    }


    return 0;
}
