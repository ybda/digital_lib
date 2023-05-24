#include "db_filler.h"
#include "db.h"

namespace db_filler {
    static void addAuthors() {
        db::addAuthor("Fefan Feka Oihl");
        db::addAuthor("Will Smith");
        db::addAuthor("William Shakespeare");
        db::addAuthor("Agatha Christie");
        db::addAuthor("Barbara Cartland");
    }

    static void addBooks() {
        db::addBook("How to make деньги?", 324, "example.org/1");
        db::addBook("Why are u gae?", 100, "example.org/2");
        db::addBook("Happy Place", 140, "example.org/3");
        db::addBook("The Housemaid", 540, "example.org/4");
        db::addBook("Trigun Deluxe Edition", 440, "example.org/5");
        db::addBook("Fourth Wing", 640, "example.org/6");
    }

    static void addCategories() {
        db::addCategory("Fiction");
        db::addCategory("Science");
        db::addCategory("Biology");
    }

    static void addAuthorsBooks() {
        db::addAuthorsBooks(1, 1);
        db::addAuthorsBooks(2, 2);
        db::addAuthorsBooks(3, 3);
        db::addAuthorsBooks(4, 4);
        db::addAuthorsBooks(5, 5);
        db::addAuthorsBooks(1, 6);

        db::addAuthorsBooks(2, 1);
        db::addAuthorsBooks(3, 1);
        db::addAuthorsBooks(4, 2);
        db::addAuthorsBooks(1, 2);
        db::addAuthorsBooks(4, 2);
    }

    static void addCategoriesBooks() {
        db::addCategoriesBooks(1, 1);
        db::addCategoriesBooks(2, 2);
        db::addCategoriesBooks(3, 3);
        db::addCategoriesBooks(1, 4);
        db::addCategoriesBooks(2, 5);
        db::addCategoriesBooks(3, 6);

        db::addCategoriesBooks(3, 2);
        db::addCategoriesBooks(2, 4);

    }

    void fill() {
        addAuthors();
        addBooks();
        addCategories();
        addAuthorsBooks();
        addCategoriesBooks();
    }
}