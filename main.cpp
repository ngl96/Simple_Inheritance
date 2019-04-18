//  Created by Nathanael Leyton on 11/1/18.
//  rec09

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// If there are no pure methods, the class is called concrete and youa re allowed to initialize instances of it.
class PrintedMaterial {// If you make a methoid pure inside this class, the class becomes abstracs, and will not allow any instances of it to be created.
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
// Remember when a method is pure virtual, you have to define it outside the class.

class Magazine : public PrintedMaterial {
public:
    void displayNumPages() const { PrintedMaterial::displayNumPages(); }
    //using PrintedMaterial::PrintedMaterial; // This give the class access to any function in the base class with the name PrintedMaterial.
    //or
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
    // you dont have to have using.... displauNumPages.
protected:
private:
};

class Book : public PrintedMaterial {
public:
    // Unless we redefine displayNumPages, Book is also a abstract class.
//    void displayNumPages() const { PrintedMaterial::displayNumPages(); }
    //using PrintedMaterial::PrintedMaterial;
    //or
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
protected:
private:
    // unsigned numOfPages; This is not needed here bc it is already defined in the parent class, so the textBook and novel classes have access to it because book is derived from printed material.
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned indexPages) : Book(numPages), numOfIndexPages(indexPages) {}
    void displayNumPages() const {
        cout << "Pages:";
        PrintedMaterial::displayNumPages(); // You can call the base classes display.
        cout << "Index Pages:"  << numOfIndexPages << endl;
    }
    //using Book::PrintedMaterials; Doesnt work either.
    //using PrintedMaterial::PrintedMaterial; Besause the base class is Book, and not PrintedMaterial, this is not allowed.
protected:
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    void displayNumPages() const { PrintedMaterial::displayNumPages(); }
    //using Book::PrintedMaterials; Doesnt work either.
    Novel(unsigned numPages) : Book(numPages) {}
    //using PrintedMaterial::PrintedMaterial; Besause the base class is Book, and not PrintedMaterial, this is not allowed.
protected:
private:
};
void displayNumberOfPages(const PrintedMaterial& printed){
    printed.displayNumPages();
    // Because this the function is passing a reference to the printedmaterial, virtual works, the same as in pointers
}

// tester/modeler code
int main()
{
    vector<PrintedMaterial*> materialsv2;
    TextBook t(5430, 23);
    Novel n(213);
    Magazine m(6);
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();
    
//    PrintedMaterial pm(4536);
//    PrintedMaterial p = t;
    cout << endl;
    
    cout << t;
    cout << n;
    cout << m;
    
    cout << endl;
    
//    p.displayNumPages();
//    pm.displayNumPages();
//    pm = t;
//    p.displayNumPages();

    cout << endl;
    
    PrintedMaterial* pmPtr;
    pmPtr = &t;
    pmPtr->displayNumPages();
    // Because the base mathod of displayNumPages is virtual, it will access the method associated to the address of the derived class. To use this properly, -> is used.
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
