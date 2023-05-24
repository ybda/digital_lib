# digital_lib
Extremely lightweight, user-friendly, nice and simple shell program for playing with a SQLite3 database using primary and foreign keys. 
The main goal of the project is to demonstrate working with SQLite3 in C++.
This project serves as a practical demonstration of SQLite3 usage in C++.


## Features: 
- Add new records in such tables as books, authors, categories
- Retrieve and view all books, authors, and categories in the database.
- Efficiently select books based on specific categories.
- Establish relationships between records in tables using link tables: categories_books and authors_books.


## Example:
```
[21:26:39.088] [debug] Logger configured
[21:26:39.088] [debug] Database opened
[21:26:39.344] [debug] Tables dropped
[21:26:39.594] [debug] Tables created
[21:26:41.510] [debug] Database filled

Option choice (-1 for help): -1
  Commands:
    0   finish
    1   add an author
    2   add a book
    3   add a category
    4   set book's categories
    5   set book's authors
    6   print all books
    7   print all authors
    8   print all categories
    9   print all books by a category

Option choice (-1 for help): 2
Title: Beloved
Price: 255
Link to the file: example.org/7

Option choice (-1 for help): 6
  List of books:
    1   Война и мир|324|example.org/1
    2   Why are u gae?|100|example.org/2
    3   Happy Place|140|example.org/3
    4   The Housemaid|540|example.org/4
    5   Why are you running?|440|example.org/5
    6   Fourth Wing|640|example.org/6
    7   Beloved|255|example.org/7

Option choice (-1 for help): 9
  List of categories:
    1   Fiction
    2   Science
    3   Biology

Choice: 2
  List of books:
    2   Why are u gae?|100|example.org/2
    5   Why are you running?|440|example.org/5
    4   The Housemaid|540|example.org/4

Option choice (-1 for help): 1
Full name: Toni Morrison

Option choice (-1 for help): 7
  List of authors:
    1   Fefan Feka Oihl
    2   Will Smith
    3   William Shakespeare
    4   Agatha Christie
    5   Barbara Cartland
    6   Toni Morrison

Option choice (-1 for help): 0
[21:30:20.266] [debug] Database closed
```


## Supported platforms
This project has been tested and verified on various Linux distributions. 
Although it should work on other POSIX-compliant systems, it has not been tested on Windows. 
Please note that on Windows problems with non-ASCII characters aren't ruled out.


## Contributions
Contributions to this project are welcome. If you encounter any issues, 
have suggestions for improvements, or would like to add new features, 
please feel free to open an issue or submit a pull request.


## Dependencies
spdlog, fmt, sqlite3


## License
This project is released under the MIT-License.