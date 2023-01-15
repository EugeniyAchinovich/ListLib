#pragma once

#include <cstddef>
#include <iostream>

// Класс, описывающий книги
class Book
{
private:
    int year;
    int pages;
    std::string tittle;
    std::string author;

public:
    Book();
    Book(std::string, std::string, int, int);
    ~Book();

    std::string GetTittle();

    void PrintInfo();
};

Book::Book()
{
    this->year = 0;
    this->pages = 0;
    this->tittle = "";
    this->author = "";
}

Book::Book(std::string tittle, std::string author, int year, int pages)
{
    this->year = year;
    this->pages = pages;
    this->tittle = tittle;
    this->author = author;
}

Book::~Book()
{

}

std::string Book::GetTittle()
{
    return this->tittle;
}

// Вывод данных об объекте на экран
void Book::PrintInfo()
{
    std::cout << "\nTittle : " << tittle;
    std::cout << "\nAuthor : " << author;
    std::cout << "\nPages  : " << pages;
    std::cout << "\nYear   : " << year << std::endl;
}

// Узел списка, содержащий данные типа Book - книги
struct Node
{
    Node* next;
    Node* prev;
    Book book;

    Node()
    {
        next = NULL;
        prev = NULL;
    }

    Node(Book book)
    {
        this->book = book;
        next = NULL;
        prev = NULL;
    }

    std::string GetBookTittle()
    {
        return this->book.GetTittle();
    }
};

// Класс двусвязного списка
class DLList
{
private:
    int size;

    Node* head;
    Node* tail;

public:
    DLList();
    ~DLList();

    void push_back(Book);
    void push_front(Book);
    void pop_back();
    void pop_front();
    void print();
    int list_size();

    std::string GetBookTittle(const int);
    const Book operator[](const int index);
};

DLList::DLList()
{
    size = 0;
    head = NULL;
    tail = NULL;
}

DLList::~DLList()
{
    while (size)
        pop_back();
}

// Добавление элемента в конец списка
void DLList::push_back(Book book)
{
    Node* created = new Node(book);

    if (size == 0)
        head = created;
    else if (size == 1) {
        tail = created;
        head->next = tail;
        tail->prev = head;
    }
    else {
        Node* temp = tail;

        tail = created;
        tail->prev = temp;
        temp->next = tail;
    }

    size++;
}

// Добавление элемента в начало списка
void DLList::push_front(Book book)
{
    Node* created = new Node(book);

    if (size == 0)
        head = created;
    else if (size == 1) {
        tail = head;
        head = created;

        head->next = tail;
        tail->prev = head;
    }
    else {
        Node* temp = head;

        head = created;
        head->next = temp;
        temp->prev = head;
    }

    size++;
}

// Удаление элемента с конца
void DLList::pop_back()
{
    if (size == 0)
        return;
    if (size == 1)
        delete head;
    if (size == 2) {
        head->next = NULL;
        delete tail;
    }
    if (size > 2) {
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;

        delete temp->next;
    }

    size--;
}

// Удаление элемента с головы
void DLList::pop_front()
{
    if (size == 0)
        return;
    if (size == 1)
        delete head;
    if (size == 2) {
        tail->prev = NULL;
        head = tail;
        delete tail->prev;
    }
    if (size > 2) {
        Node* temp = head->next;
        temp->prev = NULL;
        head = temp;

        delete temp->prev;
    }

    size--;
}


// Вывод всего списка на экран
void DLList::print()
{
    if (size == 0)
        return;

    std::cout << "\nКниги: \n" << std::endl;

    Node* ptr = head;
    while (ptr) {
        ptr->book.PrintInfo();
        ptr = ptr->next;
    }
}

// Инкапсуляция, возврат размера списка
int DLList::list_size()
{
    return size;
}

// Оператор [] перегружен для возможности удобной индексации в списке как в обычном массиве
const Book DLList::operator[](const int index)
{
    Node* ptr = head;
    for (int i = 0; ptr && i < index; i++)
        ptr = ptr->next;

    if (index < 0 || index > size - 1) {
        std::cout << "\nError: The book list does not contain book[" << index << "]" << std::endl;
        const Book b;
        return b;
    }

    return ptr->book;
}

std::string DLList::GetBookTittle(const int index)
{
    Node* ptr = head;
    for (int i = 0; ptr && i < index; i++)
        ptr = ptr->next;

    if (index < 0 || index > size - 1) {
        std::cout << "\nError: The book list does not contain book[" << index << "]" << std::endl;
        return "";
    }

    return ptr->book.GetTittle();
}
