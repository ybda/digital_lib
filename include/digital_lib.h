#pragma once
#include <filesystem>

namespace digitalLib {
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

    void addBook(const std::string& title, const int price, const std::string& file);

    void addCategory(const std::string& name);

    void addAuthorsBooks(const int author_id, const int book_id);
    void addCategoriesBooks(const int category_id, const int book_id);
}
