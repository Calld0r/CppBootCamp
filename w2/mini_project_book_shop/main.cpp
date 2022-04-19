#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "include/book.h"

using namespace std;

int getElementPos(vector<Book> &book_vector, string _title, string _author);

void addBook(vector<Book> &book_vector);

int searchBook(vector<Book> &book_vector);

void buyBook(vector<Book> &book_vector);

void editBook(vector<Book> &book_vector);

int menuPrompt();

int main()
{
    vector<Book> book_vector;
    book_vector.push_back(Book("Lord of the Flies", "William Golding", "Penguin Books", 3.69, 18));
    book_vector.push_back(Book("Treasure Island", "Robert Louis Stevenson", "Simon & Schuster", 2.75, 24));
    book_vector.push_back(Book("Oliver Twist", "Charles Dickens", " Random House Books for Young R", 5.49, 41));
    book_vector.push_back(Book("Of Mice and Men", "John Steinbeck", "Penguin Classics", 2.32, 24));
    book_vector.push_back(Book("Fear and Loathing In Las Vegas", "Hunter S. Thompson", " Random House~trade", 5.47, 4));
    book_vector.push_back(Book("One Flew Over the Cuckoo's Nest", "Ken Kesey", " Berkley", 3.68, 6));

    enum options
    {
        new_book = 1,
        buy_book,
        search_book,
        edit_book,
        quit
    };

    bool loop = true;
    int book_pos{};

    while (loop)
    {
        switch (menuPrompt())
        {
        case new_book:
            addBook(book_vector);
            break;
        case buy_book:
            buyBook(book_vector);
            break;
        case search_book:
            book_pos = searchBook(book_vector);
            if (book_pos != -1)
            {
                cout << "Book Found Successfully" << endl;
                book_vector[book_pos].printBook();
            }
            else
            {
                cout << "Book Not Found" << endl;
            }
            break;
        case edit_book:
            editBook(book_vector);
            break;
        case quit:
            cout << "EXIT" << endl
                 << endl;
            loop = false;
            break;
        default:
            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
            }
            break;
        }
    }
    return 0;
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