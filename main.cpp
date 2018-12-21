#include <iostream>
#include <memory>
#include <cstdlib>

#include "Figure.h"
#include "Vector.h"


using std::cin;
using std::cout;
using std::endl;

void menu();

int main() {
    int key;
    int a = 0;
    int b = 0;
    int c = 0;

    std::shared_ptr<Figure> tri;
    TLolVector<TLolVector <Figure> > *vector = new TLolVector<TLolVector <Figure> > (1);

    Rhombus *f = nullptr;
    Pentagon *r = nullptr;
    Trapeze *t = nullptr;
    do {
        menu();
        cin >> key;
        switch(key) {
            case 1:
                cout << "Enter sides of Trapeze, pls" << endl;
                cin >> a >> b >> c;
                t = new Trapeze(a, b, c);
                tri = std::shared_ptr<Figure>(t);
                vector->SubPush(tri);
                break;
            case 2:
                cout << "Enter sides of Pentagon, pls" << endl;
                cin >> a >> b;
                r = new Pentagon(a, b);
                tri = std::shared_ptr<Figure>(r);
                vector->SubPush(tri);
                break;
            case 3:
                cout << "Enter sides of Rhombus, pls" << endl;
                cin >> a;
                f = new Rhombus(a);
                tri = std::shared_ptr<Figure>(f);
                vector->SubPush(tri);
                break;
            case 4:
                if(vector->GetSize() > 0) {
                    int gg;
                    cout << "Delete by square(1) or type(2)?" << endl;
                    cin >> gg;
                    if(gg == 1) {
                        cout << "Enter square of figure for deleting: " << endl;
                        int s;
                        cin >> s;
                        vector->SDelete(s);
                    } else if(gg == 2) {
                        cout << "Enter type of figure  for deleting: Trapeze(2), Pentagon(1), Rhombus(3)" << endl;
                        int type;
                        cin >> type;
                        vector->TDelete(type);
                    } else {
                        cout << "Sorry, try later :(" << endl;
                    }
                } else {
                    cout << "Figure not found" << endl;
                }
                break;
            case 5:
                vector->~TLolVector();
                key = 0;
                break;
            case 6:
                cout << *vector;
                break;
            case 0:
                break;
            default:
                cout << "Unknown command" << endl;
                break;
        }
    } while(key);
    delete vector;
    return 0;
}

void menu() {
    cout << "Enter:" << endl;
    cout << "1)For add Trapeze." << endl;
    cout << "2)For add Pentagon." << endl;
    cout << "3)For add Rhombus." << endl;
    cout << "4)For delete figure." << endl;
    cout << "5)For delete all figures." << endl;
    cout << "6)Print vector." << endl;
    cout << "0)Exit" << endl;
}