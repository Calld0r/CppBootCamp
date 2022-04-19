#include <iostream>
#include "book.h"
using namespace std;

// Functions
Book::Book() = default;
Book::Book(string _title, string _author, string _publisher, float _price, int _stock)
{
    this->title = _title;
    this->author = _author;
    this->publisher = _publisher;
    this->price = _price;
    this->stock = _stock;
}
void Book::printBook()
{
    cout << "Author Name: " << this->author << endl;
    cout << "Title Name: " << this->title << endl;
    cout << "Publisher Name: " << this->publisher << endl;
    cout << "Price: " << this->price << endl;
    cout << "Number of Copies: " << this->stock << endl
         << endl;
}
void Book::setTitle(string _title)
{
    this->title = _title;
}
void Book::setAuthor(string _author)
{
    this->author = _author;
}
void Book::setPublisher(string _publisher)
{
    this->publisher = _publisher;
}
void Book::setPrice(float _price)
{
    this->price = _price;
}
void Book::setStock(int _stock)
{
    this->stock = _stock;
}
string Book::getTitle()
{
    return this->title;
}
string Book::getAuthor()
{
    return this->author;
}
string Book::getPublisher()
{
    return this->publisher;
}
float Book::getPrice()
{
    return this->price;
}
int Book::getStock()
{
    return this->stock;
}