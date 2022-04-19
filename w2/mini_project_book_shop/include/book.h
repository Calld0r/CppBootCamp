#pragma once

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