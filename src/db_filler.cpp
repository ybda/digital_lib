#include <spdlog/spdlog.h>
#include "db_filler.h"
#include "db.h"

namespace db_filler {
    static void addAuthors() {
        db::addAuthor("Stephen King");          // 1
        db::addAuthor("Will Smith");            // 2
        db::addAuthor("William Shakespeare");   // 3
        db::addAuthor("Agatha Christie");       // 4
        db::addAuthor("Barbara Cartland");      // 5
    }

    static void addCategories() {
        db::addCategory("Fiction");     // 1
        db::addCategory("Science");     // 2
        db::addCategory("Biology");     // 3
    }

    static void addBooks() {
        int book_id = 1;
        db::addBook("Война и мир", 324, "example.org/176537585");
        db::addAuthorsBooks(2, book_id);
        db::addAuthorsBooks(3, book_id);
        db::addCategoriesBooks(1, book_id);

        book_id++;  // 2
        db::addBook("О дивный новый мир", 100, "example.org/275726856");
        db::addAuthorsBooks(3, book_id);
        db::addAuthorsBooks(4, book_id);
        db::addAuthorsBooks(5, book_id);
        db::addCategoriesBooks(2, book_id);
        db::addCategoriesBooks(3, book_id);

        book_id++;  // 3
        db::addBook("Happy Place", 140, "example.org/37667586");
        db::addAuthorsBooks(3, book_id);
        db::addAuthorsBooks(4, book_id);
        db::addCategoriesBooks(3, book_id);

        book_id++;  // 4
        db::addBook("The Housemaid", 540, "example.org/47674585");
        db::addAuthorsBooks(4, book_id);
        db::addAuthorsBooks(5, book_id);
        db::addCategoriesBooks(1, book_id);
        db::addCategoriesBooks(2, book_id);

        book_id++;  // 5
        db::addBook("Why are you running?", 440, "example.org/5836468");
        db::addAuthorsBooks(5, book_id);
        db::addCategoriesBooks(2, book_id);
        db::addCategoriesBooks(3, book_id);

        book_id++;  // 6
        db::addBook("Fourth Wing", 640, "example.org/66675748");
        db::addAuthorsBooks(2, book_id);
        db::addCategoriesBooks(3, book_id);

        book_id++;  // 7
        db::addBook("The Stand", 800, "example.org/74358563");
        db::addAuthorsBooks(1, book_id);
        db::addCategoriesBooks(1, book_id);
        db::addCategoriesBooks(3, book_id);

        book_id++;  // 8
        db::addBook("Carrie", 500, "example.org/8458563");
        db::addAuthorsBooks(1, book_id);
        db::addCategoriesBooks(2, book_id);

        book_id++;  // 9
        db::addBook("It", 860, "example.org/94358563");
        db::addAuthorsBooks(1, book_id);
        db::addCategoriesBooks(1, book_id);
    }

    void fill() {
        addAuthors();
        addCategories();

        addBooks();
        spdlog::debug("Database filled");
    }
}