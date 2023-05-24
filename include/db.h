#pragma once
#include <filesystem>

namespace db {
    /**
     * std::filesystem::path - full path to database (.sqlite file).
     * Opens existing database. And if there are no database, creates one.
     */
    void open(const std::filesystem::path& filePath);

    /**
     * Clean up, close database
     */
    void close();

    /**
     * Create all the necessary tables
     */
    void createTables();

    /**
     * Drop all tables
     */
    void dropTables();

    void addAuthor(const std::string& fullName);

    void addBook(const std::string& title, int price, const std::string& file);

    void addCategory(const std::string& name);

    void addAuthorsBooks(int author_id, int book_id);
    void addCategoriesBooks(int category_id, int book_id);

    void findAllBooks();
}
