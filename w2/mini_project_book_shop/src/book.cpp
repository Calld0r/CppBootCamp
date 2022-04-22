#include <iostream>
#include "book.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

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

int getElementPos(vector<Book> &book_vector, string _title, string _author)
{
    int book_pos{};

    for (book_pos = 0; book_vector.size() > book_pos; book_pos++)
    {
        if (book_vector[book_pos].getTitle() == _title &&
            book_vector[book_pos].getAuthor() == _author)
        {
            return book_pos;
            break;
        }
    }
    return -1;
}

void addBook(vector<Book> &book_vector)
{
    string title, author, publisher;
    float price{};
    int stock{};

    cin.ignore();
    cout << "Enter Author Name: ";
    getline(cin, author);
    cout << "Enter Title Name: ";
    getline(cin, title);
    cout << "Enter Publisher Name: ";
    getline(cin, publisher);
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Number of Copies: ";
    cin >> stock;

    book_vector.push_back(Book(title, author, publisher, price, stock));
}

int searchBook(vector<Book> &book_vector)
{
    string title, author;
    int book_pos{};

    cin.ignore();
    cout << "Enter Title Of Book: ";
    getline(cin, title);
    cout << "Enter Author Of Book: ";
    getline(cin, author);

    book_pos = getElementPos(book_vector, title, author);

    return book_pos;
}

void buyBook(vector<Book> &book_vector)
{
    int book_pos{}, req_qty{}, yes{};
    book_pos = searchBook(book_vector);
    int av_stock = book_vector[book_pos].getStock();

    if (book_pos != -1)
    {
        cout << "Enter Number Of Books to buy: ";
        cin >> req_qty;
        if (req_qty <= av_stock)
        {
            book_vector[book_pos].setStock(av_stock - req_qty);
            cout << "Books Bought Sucessfully" << endl;
            cout << "Amount: $" << req_qty * book_vector[book_pos].getPrice() << endl;
        }
        else
        {
            cout << "Requested copies not in stock." << endl;
            cout << "Purchase Available Stock of " << av_stock << " instead, Y(1)/N(0) : ";
            cin >> yes;
            if (yes)
            {
                cout << book_vector[book_pos].getTitle()
                     << " By "
                     << book_vector[book_pos].getAuthor()
                     << " Was Removed From the Inventory List" << endl
                     << "Books Bought Sucessfully" << endl
                     << "Amount: $"
                     << av_stock * book_vector[book_pos].getPrice() << endl;
                book_vector.erase(book_vector.begin() + book_pos);
            }
        }
    }
    else
    {
        cout << "Book Not Found" << endl;
    }
}

void editBook(vector<Book> &book_vector)
{
    string title, author, publisher;
    int stock{}, book_pos{};
    float price{};
    book_pos = searchBook(book_vector);

    if (book_pos != -1)
    {
        cout << "Book Found Successfully" << endl;
        cout << "Enter Author Name: ";
        getline(cin, author);
        book_vector[book_pos].setAuthor(author);
        cout << "Enter Title Name: ";
        getline(cin, title);
        book_vector[book_pos].setTitle(title);
        cout << "Enter Publisher Name: ";
        getline(cin, publisher);
        book_vector[book_pos].setPublisher(publisher);
        cout << "Enter Price: ";
        cin >> price;
        book_vector[book_pos].setPrice(price);
        cout << "Enter Number of Copies: ";
        cin >> stock;
        book_vector[book_pos].setStock(stock);
    }
    else
    {
        cout << "Book Not Found" << endl;
    }
}

int menuPrompt()
{
    int choice;
    cout << endl
         << "MENU" << endl;
    cout << "1. Entry of New Book" << endl;
    cout << "2. Buy Book" << endl;
    cout << "3. Search For Book" << endl;
    cout << "4. Edit Details Of Book" << endl;
    cout << "5. Exit" << endl;
    cout << endl
         << "Enter your Choice: ";
    cin >> choice;
    cout << endl;

    return choice;
}

bool initLibrary(vector<Book> &book_vector)
{
    fstream fin;
    fin.open("library.csv", ios::in);

    if (fin.is_open())
    {
        while (fin.good())
        {
            string line, attributes[5];
            getline(fin, line);
            stringstream s(line);
            for (int i = 0; i < 5; i++)
            {
                getline(s, attributes[i], ',');
            }
            book_vector.push_back(Book(attributes[0], attributes[1], attributes[2], stof(attributes[3]), stoi(attributes[4])));
        }
        return true;
        fin.close();
    }
    else
    {
        return false;
    }
}

bool saveLibrary(vector<Book> &book_vector)
{
    fstream fout;
    fout.open("library.csv", ios::out);
    if (fout.is_open())
    {
        for (auto itr = book_vector.begin(); itr != book_vector.end(); itr++)
        {
            fout << itr->getTitle() << ',' << itr->getAuthor() << ',' << itr->getPublisher() << ',' << itr->getPrice() << ',' << itr->getStock() << endl;
        }
        fout.close();
        return true;
    }
    else
    {
        return false;
    }
}