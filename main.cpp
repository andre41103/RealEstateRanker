#include <iostream>
#include "Houses.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <chrono>
using namespace std::chrono;
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
            getline(stream,firstParenthesis, '"'); //since the file has the addresses with parenthesis, this gets rid of the first one

            getline(stream, address, '"'); //ends at second parenthesis

            getline(stream, eliminateComma, ','); // removes the comma

            getline(stream, tempPrice, ','); // saves the price
            price = stoi(tempPrice);

            getline(stream, tempRadius, ','); // saves the radius
            radius = stoi(tempRadius);

            getline(stream, tempBeds, ','); // saves the beds
            beds = stoi(tempBeds);

            getline(stream, tempBaths); //saves the baths
            baths = stoi(tempBaths);

            Houses set(address, price, radius, beds, baths); //makes a house object with all these features
            housesset.push_back(set);


        }
        inFile.close();
    }

}
void PrintData(vector<Houses>& housesSet)
{
    cout << "Size of Data: " << housesSet.size() << endl;
    for(int i = 0; i < housesSet.size(); i++)
    {
        
        cout << "Address: " <<  housesSet[i].GetAddress() << " :: Price: " << housesSet[i].GetPrice() << endl;
    }
}
void mergePrice(vector<Houses>& vec, int left, int middle, int right) // reference pseudocode from sorting discussion slides
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
    while(leftIndex < leftS && rightIndex < rightS) //checking indexes
    {
        if(leftVec[leftIndex].GetPrice() <= rightVec[rightIndex].GetPrice())
        {
            vec[merge++] = leftVec[leftIndex++];
        }
        else if (leftVec[leftIndex].GetPrice() > rightVec[rightIndex].GetPrice()){
            vec[merge++] = rightVec[rightIndex++];
        }
    }
    while(leftIndex < leftS) //checking and inserting the leftovers
    {
        vec[merge++] = leftVec[leftIndex++];
    }
    while(rightIndex < rightS)
    {
        vec[merge++] = rightVec[rightIndex++];
    }
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

void mergeLocation(vector<Houses>& vec, int left, int middle, int right)
{
    int leftS = middle - left + 1; // left size of the array
    int rightS = right - middle; // right size of the array

    vector<Houses> leftVec; //makes left vector
    vector<Houses> rightVec; //makes right vector

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
    while(leftIndex < leftS && rightIndex < rightS) //checking indexes
    {
        if(leftVec[leftIndex].GetRadius() <= rightVec[rightIndex].GetRadius()) //merging them 
        {
            vec[merge++] = leftVec[leftIndex++];
        }
        else if (leftVec[leftIndex].GetRadius() > rightVec[rightIndex].GetRadius()){
            vec[merge++] = rightVec[rightIndex++];
        }
    }
    while(leftIndex < leftS) //checks the leftovers
    {
        vec[merge++] = leftVec[leftIndex++];
    }
    while(rightIndex < rightS) //checks the leftovers
    {
        vec[merge++] = rightVec[rightIndex++];
    }
}

void mergeSortOnLocation(vector<Houses>& vec, int begin, int end)
{
    int mid = 0;
    int add = begin + end;
    if(begin < end) // it will end when they both equal each other
    {
        mid = add/2; //getting the middle
        mergeSortOnLocation(vec, begin, mid); // performs merge sort on the first half of the vector
        mergeSortOnLocation(vec, mid + 1, end); // performs merge sort on the second half of the vector
        mergeLocation(vec, begin, mid, end);
    }
}


void shellSortOnPrice(vector<Houses>& houses) //reference to sorting discussion slides
{
    
    int newLoc = 0;
    for(int gap = houses.size()/2; gap > 0; gap /= 2){ // lowers the gap
        for(int i = gap; i < houses.size(); i++){ //performs the insertion sort
            Houses temp = houses[i];
            newLoc = 0;

            for(newLoc = i; newLoc >= gap && houses[newLoc - gap].GetPrice() > temp.GetPrice(); newLoc -= gap){ //move sorted elements to correct position
                houses[newLoc] = houses[newLoc - gap];
            }

            houses[newLoc]= temp; // puts the element in the correct position
        }
    }
}
void shellSortOnLocation(vector<Houses>& houses) 
{
    int newLoc = 0;
    for(int gap = houses.size()/2; gap > 0; gap /= 2){ // lowers the gap
        for(int i = gap; i < houses.size(); i++){ //performs the insertion sort
            Houses temp = houses[i];
            newLoc = 0;

            for(newLoc = i; newLoc >= gap && houses[newLoc - gap].GetRadius() > temp.GetRadius(); newLoc -= gap){
                houses[newLoc] = houses[newLoc - gap];
            }

            houses[newLoc] = temp; // puts the element in the correct position
        }
    }
}
int main() {
    vector<Houses> housesSet;
    GetData("HouseDetails.csv", housesSet);
    string ignore;
    int prioritySelection = 0;
    //ask for priority if either the user want prefers price or location
    cout << "Welcome to your Real Estate Ranker!" << endl;
    cout << "------------------------" << endl;
    cout << "In this ranker, we will display your top 10 home option based on your priority" << endl;
    cout << "The priorities that you can select are either price or location nearest you" << endl;
    cout << "ARE YOU READY?" << endl;
    cin >> ignore;
    string city;
    cout << "Where do you live?" << endl;
    cin >> city;
    cout << "Which priority do you prefer? Price(insert 1) or Location(insert 2)" << endl;
    cin >> prioritySelection;

    //if the user picks price, we will perform shell and merge sort on the price values
    //if the user picks location, we will perform shell and merge sort on the radius values
    if(prioritySelection == 1)
    {
        int sortSelection = 0;
        cout << "Select: " << endl;
        cout << "1. Ranking using Merge Sort" << endl;
        cout << "2. Ranking using Shell Sort" << endl;
        cin >> sortSelection;
        //call merge and shell sort on price
        if(sortSelection == 1)
        {
            cout << "City: " << city << endl;
            cout << "----------" << endl;
            int j = 1;
            //will include chronos clock to calcualte how fast the function takes to execute
            auto start = high_resolution_clock::now();
            mergeSortOnPrice(housesSet, 0, housesSet.size()-1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Elapsed Time: " << duration.count() << " microseconds" << endl;
            for(int i = 0; i < 10; i++) //prints out the top 10 houses
            {
                cout << j << ". " <<"Address: " <<housesSet[i].GetAddress() << endl;
                cout << "Price: " << housesSet[i].GetPrice() << endl;
                cout << "Radius: " << housesSet[i].GetRadius() << endl;
                cout << "Beds: " <<  housesSet[i].GetBeds() << endl;
                cout << "Baths: " << housesSet[i].GetBaths() << endl;
                cout << endl;
                ++j;
            }
        }
        else if(sortSelection == 2)
        {
            cout << "City: " << city << endl;
            cout << "----------" << endl;
            int k = 1;
            //will include chronos clock to calculate how fast the function takes to execute
            auto start = high_resolution_clock::now();
            shellSortOnPrice(housesSet);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Elapsed Time: " << duration.count() << " microseconds" << endl;
            for(int i = 0; i < 10; i++) //prints out the top 10 houses
            {
                cout << k << ". " <<"Address: " <<housesSet[i].GetAddress() << endl;
                cout << "Price: " << housesSet[i].GetPrice() << endl;
                cout << "Radius: " << housesSet[i].GetRadius() << endl;
                cout << "Beds: " <<  housesSet[i].GetBeds() << endl;
                cout << "Baths: " << housesSet[i].GetBaths() << endl;
                cout << endl;

                ++k;
            }
        }

    }
    else if(prioritySelection == 2) //selected location as priority
    {
        int sort = 0;
        cout << "Select: " << endl;
        cout << "1. Ranking using Merge Sort" << endl;
        cout << "2. Ranking using Shell Sort" << endl;
        cin >> sort;
        if(sort == 1) //using merge sort on location
        {
            int j = 1;
            cout << "City: " << city << endl;
            cout << "----------" << endl;
            //will include chronos clock to calcualte how fast the function takes to execute
            auto start = high_resolution_clock::now();
            mergeSortOnLocation(housesSet, 0, housesSet.size()-1);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Elapsed Time: " << duration.count() << " microseconds" << endl;
            for(int i = 0; i < 10; i++)
            {
                cout << j << ". " << "Address: " <<housesSet[i].GetAddress() << endl;
                cout << "Price: " << housesSet[i].GetPrice() << endl;
                cout << "Radius: " << housesSet[i].GetRadius() << endl;
                cout << "Beds: " <<  housesSet[i].GetBeds() << endl;
                cout << "Baths: " << housesSet[i].GetBaths() << endl;
                cout << endl;

                ++j;
            }
        }
        else if(sort == 2) //using shell sort on location 
        {
            int k = 1;
            cout << "City: " << city << endl;
            cout << "----------" << endl;

            //will include chronos clock to calcualte how fast the function takes to execute
            auto start = high_resolution_clock::now();
            shellSortOnLocation(housesSet);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Elapsed Time: " << duration.count() << " microseconds" << endl;
            for(int i = 0; i < 10; i++)
            {
                cout << k << ". " << "Address: " <<housesSet[i].GetAddress() << endl;
                cout << "Price: " << housesSet[i].GetPrice() << endl;
                cout << "Radius: " << housesSet[i].GetRadius() << endl;
                cout << "Beds: " <<  housesSet[i].GetBeds() << endl;
                cout << "Baths: " << housesSet[i].GetBaths() << endl;
                cout << endl;

                ++k;
            }
        }
    }

    return 0;
}
