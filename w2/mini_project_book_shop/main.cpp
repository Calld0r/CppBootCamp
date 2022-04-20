#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "book.h"

using namespace std;

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