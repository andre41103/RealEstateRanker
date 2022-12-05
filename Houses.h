
#ifndef REALESTATERANKER_HOUSES_H
#define REALESTATERANKER_HOUSES_H

#endif //REALESTATERANKER_HOUSES_H
#pragma once
#include <string>
using namespace std;
class Houses{
    string address;
    int price;
    int radius;
    int beds;
    int baths;
public:
    Houses(string _address, int _price, int _radius, int _beds, int _baths);

    string GetAddress();
    int GetPrice();
    int GetRadius();
    int GetBeds();
    int GetBaths();

};
Houses::Houses(string _address, int _price, int _radius, int _beds, int _baths){
    address = _address;
    price = _price;
    radius = _radius;
    beds = _beds;
    baths = _baths;
}
string Houses::GetAddress(){
    return address;
}
int Houses::GetPrice() {
    return price;
}
int Houses::GetRadius(){
    return radius;
}
int Houses::GetBeds() {
    return beds;
}
int Houses::GetBaths() {
    return baths;
}