
#pragma once
#include"libraries.h"
using namespace std;
class String {
public:
    string str;
    friend ostream& operator<<(ostream& stream, String& obj);
    friend istream& operator>>(istream& stream, String& obj);
    int length();
    String operator+(const String& obj2);
    bool operator>(const String& obj);
    String operator= (const String& obj2);
    
    void WriteToFile();
    String() 
    {
        this->str = '0';
    };
    String(string str)
    {
        this->str = str;
    };
    ~String() { }
    String(const String& other) { this->str = other.str; }
    
};