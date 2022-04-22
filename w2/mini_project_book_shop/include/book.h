#pragma once
#include <vector>

class Book
{
private:
    // Attributes
    std::string title, author, publisher;
    float price{};
    int stock{};

public:
    // Functions
    Book();
    Book(std::string _title, std::string _author, std::string _publisher, float _price, int _stock);
    void printBook();
    void setTitle(std::string _title);
    void setAuthor(std::string _author);
    void setPublisher(std::string _publisher);
    void setPrice(float _price);
    void setStock(int _stock);
    std::string getTitle();
    std::string getAuthor();
    std::string getPublisher();
    float getPrice();
    int getStock();
};

int getElementPos(std::vector<Book> &book_vector, std::string _title, std::string _author);

void addBook(std::vector<Book> &book_vector);

int searchBook(std::vector<Book> &book_vector);

void buyBook(std::vector<Book> &book_vector);

void editBook(std::vector<Book> &book_vector);

int menuPrompt();

bool initLibrary(std::vector<Book> &book_vector);

bool saveLibrary(std::vector<Book> &book_vector);