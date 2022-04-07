#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
    private:
        // Attributes
        string title, author, publisher;
        float price{};
        int stock{};
    public:
        Book() = default;
        Book(string _title, string _author, string _publisher, float _price, int _stock) {
            this->title = _title;
            this->author = _author;
            this->publisher = _publisher;
            this->price = _price;
            this->stock = _stock;
        }
        // Functions
        void printBook() {
            cout << "Author Name: " << this->author << endl;
            cout << "Title Name: " << this->title << endl;
            cout << "Publisher Name: " << this->publisher << endl;
            cout << "Price: " << this->price << endl;
            cout << "Number of Copies: " << this->stock << endl << endl;
        }
        void setTitle(string _title) {this->title = _title;}
        void setAuthor(string _author) {this->author = _author;}
        void setPublisher(string _publisher) {this->publisher = _publisher;}
        void setPrice(float _price) {this->price = _price;}
        void setStock(int _stock) {this->stock = _stock;}
        string getTitle() {return this->title;}
        string getAuthor() {return this->author;}
        string getPublisher() {return this->publisher;}
        float getPrice() {return this->price;}
        int getStock() {return this->stock;}
};

int getElementPos (vector<Book> &book_vector, string _title, string _author) {
    int book_pos{};

    for (book_pos = 0; book_vector.size() > book_pos; book_pos++) {
        if (book_vector[book_pos].getTitle() == _title &&
            book_vector[book_pos].getAuthor() == _author) {
            return book_pos;
            break;
        }
    }
    return -1;
}

void addBook(vector<Book> &book_vector) {
    string title, author, publisher;
    float price{};
    int stock{};

    cin.ignore();
    cout << "Enter Author Name: "; getline (cin, author);
    cout << "Enter Title Name: "; getline (cin, title);
    cout << "Enter Publisher Name: "; getline (cin, publisher);
    cout << "Enter Price: "; cin >> price;
    cout << "Enter Number of Copies: "; cin >> stock;

    book_vector.push_back(Book (title, author, publisher, price, stock));
}

int searchBook (vector<Book> &book_vector) {
    string title, author;
    int book_pos{};
    
    cin.ignore();
    cout << "Enter Title Of Book: ";
    getline (cin, title);
    cout << "Enter Author Of Book: ";
    getline (cin, author);

    book_pos = getElementPos(book_vector, title, author);

    return book_pos;
}

void buyBook(vector<Book> &book_vector) {
    int book_pos{}, req_qty{}, yes{};
    book_pos = searchBook(book_vector);
    int av_stock = book_vector[book_pos].getStock();

    if (book_pos != -1) {
        cout << "Enter Number Of Books to buy: "; cin >> req_qty;
        if (req_qty <= av_stock) {
            book_vector[book_pos].setStock(av_stock - req_qty);
            cout << "Books Bought Sucessfully" << endl;
            cout << "Amount: $" << req_qty * book_vector[book_pos].getPrice() << endl;
        } else { 
            cout << "Required copies not in stock." << endl;
            cout << "Purchase Available Stock of " << av_stock << " instead, Y(1)/N(0) : ";
            cin >> yes;
            if (yes) {
                book_vector.erase(book_vector.begin() + book_pos);
                cout << book_vector[book_pos].getTitle()
                     << " By "
                     << book_vector[book_pos].getAuthor() 
                     << " Was Removed From the Inventory List" << endl
                     << "Books Bought Sucessfully" << endl
                     << "Amount: $" 
                     << av_stock * book_vector[book_pos].getPrice() << endl;
                }
          }
    } else {cout << "Book Not Found" << endl;}
}

void editBook(vector<Book> &book_vector) {
    string title, author, publisher;
    int stock{}, book_pos{};
    float price{};
    book_pos = searchBook(book_vector);

    if (book_pos != -1) {
        cout << "Book Found Successfully" << endl;
        cout << "Enter Author Name: "; getline (cin, author);
        book_vector[book_pos].setAuthor(author);
        cout << "Enter Title Name: "; getline (cin, title);
        book_vector[book_pos].setTitle(title);
        cout << "Enter Publisher Name: "; getline (cin, publisher);
        book_vector[book_pos].setPublisher(publisher);
        cout << "Enter Price: "; cin >> price;
        book_vector[book_pos].setPrice(price);
        cout << "Enter Number of Copies: "; cin >> stock;       
        book_vector[book_pos].setStock(stock);
    } else {cout << "Book Not Found" << endl;}
}

int menuPrompt() {
    int choice;
    cout << endl << "MENU" << endl;
    cout << "1. Entry of New Book" << endl;
    cout << "2. Buy Book" << endl;
    cout << "3. Search For Book" << endl;
    cout << "4. Edit Details Of Book" << endl;
    cout << "5. Exit" << endl;
    cout << endl << "Enter your Choice: ";
    cin >> choice; cout << endl;

    return choice;
}

int main () {
    vector<Book> book_vector;
    book_vector.push_back(Book ("title1", "author1", "publisher1", 101, 1));
    book_vector.push_back(Book ("title2", "author2", "publisher2", 102, 2));
    book_vector.push_back(Book ("title3", "author3", "publisher3", 103, 3));
    book_vector.push_back(Book ("title4", "author4", "publisher4", 104, 4));
    book_vector.push_back(Book ("title5", "author5", "publisher5", 105, 5));
    book_vector.push_back(Book ("title6", "author6", "publisher6", 106, 6));

    enum options {new_book = 1, buy_book, search_book, edit_book, exit};
    bool loop = true;
    int book_pos{};

    while(loop) {
        switch (menuPrompt()) {
            case new_book:
                addBook(book_vector);
                break;
            case buy_book:
                buyBook(book_vector);
                break;
            case search_book:
                book_pos = searchBook(book_vector);
                if (book_pos != -1) {
                    cout << "Book Found Successfully" << endl;
                    book_vector[book_pos].printBook();
                } else {cout << "Book Not Found" << endl;}
                break;
            case edit_book:
                editBook(book_vector);
                break;
            case exit:
                cout << "SAVE AND EXIT" << endl << endl;
                loop = false;
                break;
            default:
                if (cin.fail()) {cin.clear(); cin.ignore();}
                break;
        }
    }
    return 0;
}