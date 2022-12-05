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

            string tempPrice;
            string tempRadius;
            string tempBeds;
            string tempBaths;

            getline(stream, address, ',');

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
int main() {
    vector<Houses> housesSet;

    return 0;
}
