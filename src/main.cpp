#include <iostream>
#include <filesystem>
#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <fmt/format.h>

#include "db.h"
#include "db_filler.h"


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

std::filesystem::path getDbPath(const char* argv0) {
    std::filesystem::path exePath = std::filesystem::canonical(std::filesystem::path(argv0)).parent_path().parent_path();
    return exePath / "other" / "dl.sqlite";
}

int main(const int argc, const char** argv) {
    configure_encoding();
    configure_logger();

    db::open(getDbPath(argv[0]));
    db::dropTables();
    db::createTables();

    db_filler::fill();

    db::findAllBooks();

    db::close();

}