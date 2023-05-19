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
	book_id INTEGER REFERENCES books(id),
	author_id INTEGER REFERENCES authors(id),
	PRIMARY KEY (book_id, author_id)
);

CREATE TABLE categories_books (
	book_id INTEGER REFERENCES books(id),
	category_id INTEGER REFERENCES categories(id),
	PRIMARY KEY (book_id, category_id)
);

