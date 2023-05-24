#include <sqlite3.h>
#include <iostream>
#include <stdexcept>
#include <spdlog/spdlog.h>
#include <string>
#include <sstream>

#include "db.h"

namespace db {
    static sqlite3 *m_db;

    void open(const std::filesystem::path &filePath) {
        int result = sqlite3_open(filePath.string().c_str(), &m_db);

        if (result != SQLITE_OK) {
            spdlog::error("ERR opening database: {}", sqlite3_errmsg(m_db));
            throw std::runtime_error("");
        } else {
            spdlog::debug("Database opened");
        }
    }

    void close() {
        sqlite3_close(m_db);
    }

    void createTables() {
        const char *query = R"(
CREATE TABLE authors (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	full_name TEXT NOT NULL
);

CREATE TABLE books (
	isbn INTEGER PRIMARY KEY AUTOINCREMENT,
	title TEXT NOT NULL,
	price INTEGER NOT NULL,
	file TEXT NOT NULL
);

CREATE TABLE categories (
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	name TEXT NOT NULL
);

CREATE TABLE authors_books (
	book_id INTEGER REFERENCES books(id) ON DELETE CASCADE,
	author_id INTEGER REFERENCES authors(id) ON DELETE CASCADE,
	PRIMARY KEY (book_id, author_id)
);

CREATE TABLE categories_books (
	book_id INTEGER REFERENCES books(id) ON DELETE CASCADE,
	category_id INTEGER REFERENCES categories(id) ON DELETE CASCADE,
	PRIMARY KEY (book_id, category_id)
);
)";
        char *errMsg;
        int result = sqlite3_exec(m_db, query, nullptr, nullptr, &errMsg);

        if (result != SQLITE_OK) {
            spdlog::error("ERR creating tables: {}", errMsg);
            sqlite3_free(errMsg);
            throw std::runtime_error("");
        } else {
            spdlog::debug("Tables created");
        }
    }

    void dropTables() {
        const char *query = R"(
DROP TABLE IF EXISTS authors;
DROP TABLE IF EXISTS books;
DROP TABLE IF EXISTS categories;
DROP TABLE IF EXISTS authors_books;
DROP TABLE IF EXISTS categories_books;
)";
        char *errMsg;
        int result = sqlite3_exec(m_db, query, nullptr, nullptr, &errMsg);

        if (result != SQLITE_OK) {
            spdlog::error("ERR dropping tables: {}", errMsg);
            sqlite3_free(errMsg);
            throw std::runtime_error("");
        } else {
            spdlog::debug("Tables dropped");
        }
    }

    void addAuthor(const std::string &fullName) {
        const char *query = "INSERT INTO authors (full_name) VALUES (?);";

        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(m_db, query, -1, &stmt, nullptr);

        sqlite3_bind_text(stmt, 1, fullName.c_str(), -1, SQLITE_STATIC);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    void addBook(const std::string &title, const int price, const std::string &file) {
        const char *query = "INSERT INTO books (title, price, file) VALUES (?, ?, ?);";

        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(m_db, query, -1, &stmt, nullptr);

        sqlite3_bind_text(stmt, 1, title.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, price);
        sqlite3_bind_text(stmt, 3, file.c_str(), -1, SQLITE_STATIC);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    void addCategory(const std::string &name) {
        const char *query = "INSERT INTO categories (name) VALUES (?);";

        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(m_db, query, -1, &stmt, nullptr);

        sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    void addAuthorsBooks(const int author_id, const int book_id) {
        const char *query = "INSERT INTO authors_books (author_id, book_id) VALUES (?, ?);";

        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(m_db, query, -1, &stmt, nullptr);

        sqlite3_bind_int(stmt, 1, author_id);
        sqlite3_bind_int(stmt, 2, book_id);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    void addCategoriesBooks(const int category_id, const int book_id) {
        const char *query = "INSERT INTO categories_books (category_id, book_id) VALUES (?, ?);";

        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(m_db, query, -1, &stmt, nullptr);

        sqlite3_bind_int(stmt, 1, category_id);
        sqlite3_bind_int(stmt, 2, book_id);

        sqlite3_step(stmt);
        sqlite3_finalize(stmt);
    }

    void findAllBooks() {
        const char *query = "SELECT * FROM books;";
        sqlite3_stmt *stmt;
        sqlite3_prepare_v2(m_db, query, -1, &stmt, nullptr);

        std::stringstream ss;
        ss << "All books:";
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char* title = sqlite3_column_text(stmt, 1);
            int price = sqlite3_column_int(stmt, 2);
            const unsigned char* file = sqlite3_column_text(stmt, 3);
            ss << fmt::format("\nid: {}\ntitle: {}\nprice: {}\nfile: {}\n", id, title, price, file);
        }
        sqlite3_finalize(stmt);

        spdlog::info(ss.str());
    }
}