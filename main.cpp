#include <iostream>
#include "Houses.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
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
void mergePrice(vector<Houses>& vec, int left, int middle, int right)
{
    int leftS = middle - left + 1; // left size of the array
    int rightS = right - middle; // right size of the array

    vector<Houses> leftVec;
    vector<Houses> rightVec;

    for(int i = 0; i < leftS; i++)
    {
        leftVec.push_back(vec[left+i]); // it is copying the left side of the vec vector on the left vector
    }
    for(int j = 0; j < rightS; j++)
    {
        rightVec.push_back(vec[middle+j+1]); // it is copying the right side of the vec vector on the right vector
    }
    int leftIndex =0;
    int rightIndex = 0;
    int merge = left;

}
void mergeSortOnPrice(vector<Houses>& vec, int begin, int end){
    int mid = 0;
    int add = begin + end;
    if(begin < end) // it will end when they both equal each other
    {
        mid = add/2;
        mergeSortOnPrice(vec, begin, mid); // performs merge sort on the first half of the vector
        mergeSortOnPrice(vec, mid + 1, end); // performs merge sort on the second half of the vector
        mergePrice(vec, begin, mid, end);
    }

}
void mergeSortOnLocation()
{

}
void mergeLocation()
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
    cout << std::setw(32) << "Welcome to your Real Estate Ranker!" << std::setw(32) << endl;
    cout << "In this ranker, we will display your top 5 home option based on your priority" << endl;
    cout << "The priorities that you can select are either price or location nearest you" << endl;
    cout << setw(8) <<"ARE YOU READY?" << endl;
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
