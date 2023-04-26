
#pragma once
#include"libraries.h"
using namespace std;
class Tile {
private:
    string brand;
    float length, width;
    float price;
    int quantity;
    float fullPrice;
public:
    void displayInfo();
    void SearchfullPrice();
    void putInfo();
    void WriteToFile();
    Tile()
    {
        this->brand = '0';
        this->length = 0;
        this->width = 0;
        this->price = 0;
        this->quantity = 0;
        this->fullPrice = 0;
    }
    Tile(string brand, float length, float  width, float price, int quantity)
    {
        this->brand = brand;
        this->length = length;
        this->width = width;
        this->price = price;
        this->quantity = quantity;
    }

    ~Tile();
    Tile(const Tile& Keramika)
    {
        brand = Keramika.brand;
        length = Keramika.length;
        width = Keramika.width;
        price = Keramika.price;
        quantity = Keramika.quantity;
    }
};