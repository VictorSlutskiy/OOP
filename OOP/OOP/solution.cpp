#include"libraries.h"
const int LENGTH = 100;                                                         
Tile* arrmodels = new Tile[LENGTH];
static int num = 0;
void Tile::WriteToFile()
{
    ofstream out("File.txt", ios::app);
    if (out.is_open())
        for (int i = 0; i < num; i++) {
            {
                out << "Tile brand: " << arrmodels[i].brand << endl
                    << "Length X Width: " << arrmodels[i].length << " X " << arrmodels[i].width << endl
                    << "Price: " << arrmodels[i].price << endl
                    << "Quantity: " << arrmodels[i].quantity << endl << endl;
            }
        }
    out.close();
}
Tile::~Tile() {
    delete[] arrmodels; }
void Tile::displayInfo()
{
    for (int i = 0; i < num; i++)
        cout << endl << "Brand: " << arrmodels[i].brand << endl
        << "length X width : " << arrmodels[i].length << "X" << arrmodels[i].width << endl
        << "Price:" << arrmodels[i].price << "$" << endl
        << "Quantity:" << arrmodels[i].quantity << endl << endl;
}
void Tile::SearchfullPrice()
{
    int i = 0;
    float fullPrice = 0;
    for (int i = 0; i < num; i++)
    {
        fullPrice = fullPrice + arrmodels[i].price;
    }

    cout << endl << "Total cost of tiles stored in the warehouse - "
        << fullPrice <<"$" << endl << endl;
}
void Tile::putInfo() {

    cout << "Enter tile brand:" << endl;
   
    getline(cin , arrmodels[num].brand);
    cout << "Enter size:length X width:" << endl;
    cin>> arrmodels[num].length>> arrmodels[num].width;

    cout << "Enter price:" << endl;
    cin >> arrmodels[num].price;

    cout << "Enter quantity:" << endl;
    cin >> arrmodels[num].quantity;
    system("cls");
    num++;
}
int main()
{
    
    Tile Keramika;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char choice = '\0';
    do
    {
        cout << "1 - Ввести информацию о плитке" << endl;
        cout << "2 - Посмотреть информацию" << endl;
        cout << "3 - Total cost of tiles" << endl;
        cout << "4 - Quit from programm" << endl << endl;
        cout << "Enter your choice" << endl;
        string str, choice_s;
        str = getchar();
        getline(cin, choice_s);
        if (str != "\n")
            choice_s.insert(0, str);
        if (choice_s.size() > 2)
        {
            cout<< "WRONG CHOICE!" << endl;
         
        }
        else
        {
            choice = choice_s[0];
            system("cls");
            switch (choice)
            {
            case '1': {
                Keramika.putInfo();
                break; }
            case '2': {
                Keramika.displayInfo();
                break; }
            case '3':
            { Keramika.SearchfullPrice();
            break; }
            case '4':
            {
                Keramika.WriteToFile();
                return 0;
            }
            default:  cout << "WRONG CHOICE!" << endl;
                break;
            }
        }
     
    } while (choice != '4');
    return 0;
} 
