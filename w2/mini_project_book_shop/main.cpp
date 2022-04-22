#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "book.h"

using namespace std;

int main()
{
    vector<Book> book_vector;

    if (initLibrary(book_vector))
    {
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
                if (saveLibrary(book_vector))
                {
                    cout << "Library Saved" << endl;
                }
                else
                {
                    cout << "Library could not be saved" << endl;
                }
                cout << "EXIT" << endl << endl;
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
    }
    else 
    {
        cout << "COULD NOT INITIALIZE LIBRARY" << endl;
    }
    return 0;
}