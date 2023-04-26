#include"libraries.h"
int String::length() { return str.length(); }
void String::WriteToFile()
{
    ofstream out("File.txt", ios::app);
    if (out.is_open())
                out << endl;       
    out.close();
}
String String::operator=(const String& obj2)
{
    if(this != &obj2) {
        this->str = obj2.str;
    }
    return *this;
}
ostream& operator<<(ostream& stream, String& obj)
{
    stream << obj.str;
    return stream;
}
istream& operator>>(istream& stream, String& obj)
{
    getline(stream, obj.str);
    return stream;
}
 String String::operator+(const String& obj2)
{
     return String{ str + obj2.str };
}
 bool String::operator>(const String& obj)  {
     return this->str.length() > obj.str.length();
 }
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string inputStr1, inputStr2;
    String obj1;
    String obj2;
    cout << "������� ������ ������: " << endl;;
    cin >> obj1;
     cout << "������� ������ ������: "<<endl;
    cin >> obj2;
    
    String s{obj1+obj2};
    String temp;
    char choice = '\0';
    do
    {
        cout << endl<<"�������� ����������:" << endl;
        cout << "1 - ���������� (=) " << endl;
        cout << "2 - ������� (+=) " << endl;
        cout << "3 - �������� (>) " << endl;
        cout << "4 - ����� �� ���������" << endl << endl;
        string str, choice_s;
        str = getchar();
        getline(cin, choice_s);
        if (str != "\n")
            choice_s.insert(0, str);
        if (choice_s.size() > 2)
        {
            cout << "������������ �����!" << endl;

        }
        else
        {

            choice = choice_s[0];
            system("cls");
            switch (choice)
            {
            case '1':
            {
                cout << "����������:" << endl;
                temp = obj1;
                obj1 = obj2;
                cout << "������ 1: " << endl << obj1 << endl;
                cout << "������ 2: " << endl << obj2 << endl;
                obj1 = temp;
                break;
            }
            case '2':
            {
                
                cout << "��������:" << endl;
                s = obj1 + obj2;
                cout << s<<endl;
                
                break;
            }
            case '3':
            {
                cout << "���������:" << endl;
                if (obj1 > obj2)
                    cout << "������ ������ ������� ������" << endl;
                else
                    cout << "������ ������ ������� ������" << endl;
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "������������ �����" << endl;
                break;
            }
            }
        }
    } while (choice != '4');
            return 0;
    
}