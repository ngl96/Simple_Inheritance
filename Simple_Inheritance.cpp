//  Created by Nathanael Leyton on 11/1/18.

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class PrintedMaterial {
    friend ostream& operator<<(ostream& os, const PrintedMaterial& material){
        os << material.numOfPages << endl;
        return os;
    }
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
    virtual void displayNumPages() const = 0; // { cout << numOfPages << endl; }
protected:
private:
    unsigned numOfPages;
    
};

void PrintedMaterial::displayNumPages() const { cout << numOfPages << endl; }

class Magazine : public PrintedMaterial {
public:
    void displayNumPages() const { PrintedMaterial::displayNumPages(); }

    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
protected:
private:
};

class Book : public PrintedMaterial {
public:

    Book(unsigned numPages) : PrintedMaterial(numPages) {}
protected:
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned indexPages) : Book(numPages), numOfIndexPages(indexPages) {}
    void displayNumPages() const {
        cout << "Pages:";
        PrintedMaterial::displayNumPages(); // You can call the base classes display.
        cout << "Index Pages:"  << numOfIndexPages << endl;
    }
protected:
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    void displayNumPages() const { PrintedMaterial::displayNumPages(); }
    Novel(unsigned numPages) : Book(numPages) {}
protected:
private:
};
void displayNumberOfPages(const PrintedMaterial& printed){
    printed.displayNumPages();
}

int main()
{
    vector<PrintedMaterial*> materialsv2;
    TextBook t(5430, 23);
    Novel n(213);
    Magazine m(6);
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();
    cout << endl;
    
    cout << t;
    cout << n;
    cout << m;

    cout << endl;
    
    PrintedMaterial* pmPtr;
    pmPtr = &t;
    pmPtr->displayNumPages();
    cout << endl;
    
    displayNumberOfPages(t);
    displayNumberOfPages(n);
    displayNumberOfPages(m);
    cout << endl;
    materialsv2.push_back(&t);
    materialsv2.push_back(&n);
    materialsv2.push_back(&m);

    for (PrintedMaterial* pmPtr : materialsv2){
        pmPtr->displayNumPages();
    }


}
