#include <iostream>
#include <filesystem>
#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <fmt/format.h>

#include "digital_lib.h"


void configure_spdlog() {
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%H:%M:%S.%e] [%^%l%$] %v");
    spdlog::info("Logger configured");
}

void configure_encoding() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
}


std::filesystem::path getDbPath(const char* argv0) {
    std::filesystem::path exePath = std::filesystem::canonical(std::filesystem::path(argv0)).remove_filename().parent_path().parent_path().parent_path();
    return exePath / "other\\" / "dl.sqlite";
}

void addAuthors() {
    digitalLib::addAuthor("Fefan Feka Oihl");
    digitalLib::addAuthor("Will Smith");
    digitalLib::addAuthor("William Shakespeare");
    digitalLib::addAuthor("Agatha Christie");
    digitalLib::addAuthor("Barbara Cartland");
}

void addBooks() {
    digitalLib::addBook("How to make money", 324, "example.org/1");
    digitalLib::addBook("Why are u gae?", 100, "example.org/2");
    digitalLib::addBook("Happy Place", 140, "example.org/3");
    digitalLib::addBook("The Housemaid", 540, "example.org/4");
    digitalLib::addBook("Trigun Deluxe Edition", 440, "example.org/5");
    digitalLib::addBook("Fourth Wing", 640, "example.org/6");
}

void addCategories() {
    digitalLib::addCategory("Fiction");
    digitalLib::addCategory("Science");
    digitalLib::addCategory("Biology");
}

void addAuthorsBooks() {
    digitalLib::addAuthorsBooks(1, 1);
    digitalLib::addAuthorsBooks(2, 2);
    digitalLib::addAuthorsBooks(3, 3);
    digitalLib::addAuthorsBooks(4, 4);
    digitalLib::addAuthorsBooks(5, 5);
    digitalLib::addAuthorsBooks(1, 6);

    digitalLib::addAuthorsBooks(2, 1);
    digitalLib::addAuthorsBooks(3, 1);
}

void addCategoriesBooks() {
    digitalLib::addCategoriesBooks(1, 1);
    digitalLib::addCategoriesBooks(2, 2);
    digitalLib::addCategoriesBooks(3, 3);
    digitalLib::addCategoriesBooks(1, 4);
    digitalLib::addCategoriesBooks(2, 5);
    digitalLib::addCategoriesBooks(3, 6);

    digitalLib::addCategoriesBooks(3, 2);
    digitalLib::addCategoriesBooks(2, 4);

}

int main(const int argc, const char** argv) {
    configure_encoding();
    configure_spdlog();

    digitalLib::open(getDbPath(argv[0]));
    digitalLib::dropTables();
    digitalLib::createTables();

    addAuthors();
    addBooks();
    addCategories();
    addAuthorsBooks();
    addCategoriesBooks();

    digitalLib::close();

}