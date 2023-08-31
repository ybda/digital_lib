# digital_lib
Extremely lightweight, user-friendly, nice and simple shell program for playing with a SQLite3 database using primary and foreign keys.
This project serves as a practical demonstration of SQLite3 usage in C++.


## Features: 
- Add new records in such tables as books, authors, categories
- Retrieve and view all books, authors, and categories in the database.
- Efficiently select books based on specific categories.
- Establish relationships between records in tables using link tables: categories_books and authors_books.


## Example:
```
$ digital_lib
[00:18:15.071] [debug] Database opened
[00:18:15.388] [debug] Tables dropped
[00:18:15.696] [debug] Tables created
[00:18:18.254] [debug] Database filled

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
    10  print all books by part of author's name

Option choice (-1 for help): 2
Title: Beloved
Price: 255
Link to the file: example.org/103526

Option choice (-1 for help): 6
  List of books:
    1   Война и мир|324|example.org/176537585
    2   О дивный новый мир|100|example.org/275726856
    3   Happy Place|140|example.org/37667586
    4   The Housemaid|540|example.org/47674585
    5   Why are you running?|440|example.org/5836468
    6   Fourth Wing|640|example.org/66675748
    7   The Stand|800|example.org/74358563
    8   Carrie|500|example.org/8458563
    9   It|860|example.org/94358563
    10  Beloved|255|example.org/103526

Option choice (-1 for help): 9
  List of categories:
    1   Fiction
    2   Science
    3   Biology

Choice: 2
  List of books:
    2   О дивный новый мир|100|example.org/275726856
    4   The Housemaid|540|example.org/47674585
    5   Why are you running?|440|example.org/5836468
    8   Carrie|500|example.org/8458563

Option choice (-1 for help): 1
Full name: Toni Morrison

Option choice (-1 for help): 7
  List of authors:
    1   Stephen King
    2   Will Smith
    3   William Shakespeare
    4   Agatha Christie
    5   Barbara Cartland
    6   Toni Morrison

Option choice (-1 for help): 10
Part of author's full name: King
  List of books:
    7   The Stand|800|example.org/74358563
    8   Carrie|500|example.org/8458563
    9   It|860|example.org/94358563

Option choice (-1 for help): 0

[00:21:05.801] [debug] Database closed
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
- spdlog 
- fmt 
- sqlite3
