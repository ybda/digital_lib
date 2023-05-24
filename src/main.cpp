#include <iostream>
#include <filesystem>
#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <fmt/format.h>

#include "db.h"
#include "db_filler.h"
#include "util.h"


void configure_logger() {
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%H:%M:%S.%e] [%^%l%$] %v");
    spdlog::info("Logger configured");
}

void configure_encoding() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    setlocale(LC_ALL, "ru_RU.UTF-8");
}

std::filesystem::path getDbPath(const char *argv0) {
    std::filesystem::path exePath = std::filesystem::canonical(
            std::filesystem::path(argv0)).parent_path().parent_path();
    return exePath / "other" / "dl.sqlite";
}

void printBooks(const std::vector<db::Book> &books, const int spacesCount = 2) {
    const std::string spaces1(spacesCount, ' '), spaces2(spacesCount + 2, ' ');
    std::cout << spaces1 << "List of books:\n";
    for (const auto &book: books) {
        fmt::print("{}{}   {} {} {}\n", spaces2, book.id, book.title.c_str(), book.price, book.file.c_str());
    }
}

void printCategories(const std::vector<db::Category> &categories, const int spacesCount = 2) {
    const std::string spaces1(spacesCount, ' '), spaces2(spacesCount + 2, ' ');
    std::cout << spaces1 << "List of categories:\n";
    for (const auto &category: categories) {
        fmt::print("{}{}   {}\n", spaces2, category.id, category.name.c_str());
    }
}

void printAuthors(const std::vector<db::Author> &authors, const int spacesCount = 2) {
    const std::string spaces1(spacesCount, ' '), spaces2(spacesCount + 2, ' ');
    std::cout << spaces1 << "List of authors:\n";
    for (const auto &author: authors) {
        fmt::print("{}{}   {}\n", spaces2, author.id, author.fullName.c_str());
    }
}

void printHelp() {
    std::cout << "  Commands:\n"
                 "    0   complete\n"
                 "    1   add an author\n"
                 "    2   add a book\n"
                 "    3   add a category\n"
                 "    4   set book's categories\n"
                 "    5   set book's authors\n"
                 "    6   print all books\n"
                 "    7   print all authors\n"
                 "    8   print all categories\n"
                 "    9   print all books by a category\n";
}


void shell() {
    for (;;) {
        std::cout << "Option choice (-1 for help): ";
        int opt = util::getnum();

        if (opt == -1) {
            printHelp();

        } else if (opt == 0) {
            break;

        } else if (opt == 1) {
            std::cout << "Full name: ";
            std::string name;
            std::getline(std::cin, name);
            db::addAuthor(name);

        } else if (opt == 2) {
            std::string title, file;
            int price;

            std::cout << "Title: ";
            std::getline(std::cin, title);

            std::cout << "Price: ";
            price = util::getnum();

            std::cout << "Link to the file: ";
            std::getline(std::cin, file);

            db::addBook(title, price, file);

        } else if (opt == 3) {
            std::string name;
            std::cout << "Name: ";
            std::getline(std::cin, name);
            db::addCategory(name);

        } else if (opt == 4 || opt == 5) {
            auto books = db::findAllBooks();
            printBooks(books);
            std::cout << "\nChoice: ";
            int bId = util::getnum();

            if (opt == 4) {
                printCategories(db::findAllCategories());
                std::cout << "\nChoice: ";
                int cId = util::getnum();
                db::addCategoriesBooks(cId, bId);

            } else {
                printAuthors(db::findAllAuthors());
                std::cout << "\nChoice: ";
                int aId = util::getnum();
                db::addAuthorsBooks(aId, bId);

            }

        } else if (opt == 6) {  // Books
            printBooks(db::findAllBooks());

        } else if (opt == 7) {  // Authors
            printAuthors(db::findAllAuthors());

        } else if (opt == 8) {  // Categories
            printCategories(db::findAllCategories());

        } else if (opt == 9) {
            printCategories(db::findAllCategories());

            std::cout << "\nChoice: ";
            int cId = util::getnum();
            printBooks(db::findBooksByCategory(cId));
        }


        std::cout << "\n";
    }
}

int main(const int argc, const char **argv) {
    configure_encoding();
    configure_logger();

    db::open(getDbPath(argv[0]));
    db::dropTables();
    db::createTables();

    db_filler::fill();

    std::cout << '\n';
    shell();

    db::close();
}