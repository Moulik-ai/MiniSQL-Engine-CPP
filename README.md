# MiniSQL++ – A Lightweight SQL Engine in C++

MiniSQL++ is a **lightweight relational database engine built entirely from scratch in C++**.

The project implements a simplified SQL query processor capable of parsing commands, storing relational data, executing queries, and optimizing lookups using **hash-based indexing**.

This project was created to explore **how real database systems work internally**, including query parsing, execution pipelines, indexing, and disk persistence.

---

# 🚀 Features

## Core SQL Support

MiniSQL++ currently supports a subset of SQL operations:

- CREATE TABLE
- INSERT INTO
- SELECT
- WHERE filtering
- Column projection (`SELECT column FROM table`)
- Multiple tables support

Example:

```
CREATE TABLE students (id name age)

INSERT INTO students VALUES (1 Moulik 19)
INSERT INTO students VALUES (2 Aryan 20)

SELECT * FROM students
```

---

## Data Modification Queries

MiniSQL++ also supports modifying existing data.

Supported commands:

- UPDATE table SET column=value WHERE condition
- DELETE FROM table WHERE condition

Example:

```
UPDATE students SET age = 21 WHERE id = 1

DELETE FROM students WHERE age = 21
```

---

## Indexing & Query Optimization

MiniSQL++ includes **hash-based indexing** to accelerate queries.

Features:

- CREATE INDEX support
- Automatic index updates on INSERT
- Fast lookup for indexed columns
- Query plan detection

Example:

```
CREATE INDEX ON students (age)
```

Internal index structure:

```
age → {
  19 → [0,2]
  20 → [1]
}
```

This allows **O(1) average lookup time** for queries like:

```
SELECT * FROM students WHERE age = 19
```

---

## Query Planning (EXPLAIN)

MiniSQL++ includes a simple **query planner**.

The EXPLAIN command shows how the database will execute a query.

Example:

```
EXPLAIN SELECT * FROM students WHERE age = 19;
```

Output:

```
Query Plan:
Index Scan on students(age)
```

If no index exists:

```
Query Plan:
Full Table Scan
```

---

## Persistent Storage

Tables are automatically saved to disk and reloaded when the engine starts.

Example stored file:

```
students.table
```

Example contents:

```
TABLE students
COLUMNS id name age
ROW 1 Moulik 19
ROW 2 Aryan 20
ROW 3 Ravi 19
```

This allows the database to **retain data between program executions**.

---

## Interactive CLI Database Shell

MiniSQL++ includes a command-line database shell similar to SQLite.

Example session:

```
MiniSQL Database Engine
Connected to database.db

MiniSQL> CREATE TABLE learners (id name age)
MiniSQL> INSERT INTO learners VALUES (1 Moulik 18)
MiniSQL> INSERT INTO learners VALUES (2 Aryan 19)

MiniSQL> SELECT * FROM learners

id   name   age
1    Moulik 18
2    Aryan  19
```

---

## Built-in CLI Commands

MiniSQL++ also supports CLI meta commands:

```
.help    → show supported commands
.tables  → list all tables
.exit    → exit the database shell
```

Example:

```
MiniSQL> .tables
learners
students
```

---

# 🏗 System Architecture

MiniSQL++ follows a simplified database architecture.

```
           ┌─────────────────┐
           │   CLI Interface │
           └────────┬────────┘
                    │
                    ▼
           ┌─────────────────┐
           │   SQL Parser    │
           │ (Tokenization)  │
           └────────┬────────┘
                    │
                    ▼
           ┌─────────────────┐
           │ Query Execution │
           │     Engine      │
           └────────┬────────┘
                    │
                    ▼
           ┌─────────────────┐
           │  Index Manager  │
           │ (Hash Indexes)  │
           └────────┬────────┘
                    │
                    ▼
           ┌─────────────────┐
           │ Storage Engine  │
           │  (Tables/Rows)  │
           └────────┬────────┘
                    │
                    ▼
           ┌─────────────────┐
           │ Disk Persistence│
           │   (.table files)│
           └─────────────────┘
```

---

# 🧠 Internal Design

## Table Storage

Tables are stored using:

```
unordered_map<string, Table>
```

This provides **O(1) average table lookup**.

---

## Table Structure

Each table contains:

```
Table
 ├── tableName
 ├── columns (vector<string>)
 ├── rows (vector<Row>)
 └── indexes (unordered_map)
```

---

## Row Representation

Each row is stored as:

```
Row
 └── vector<string> values
```

Example row:

```
[1, Moulik, 19]
```

---

## Index Structure

Indexes use nested hash maps:

```
column_name → value → row_indexes
```

Example:

```
age → {
  19 → [0,2]
  20 → [1]
}
```

---

# 🖥 Example Usage

```
CREATE TABLE learners (id name age)

INSERT INTO learners VALUES (1 Moulik 18)
INSERT INTO learners VALUES (2 Aryan 19)
INSERT INTO learners VALUES (3 Ravi 19)

SELECT * FROM learners
```

Output:

```
id   name   age
1    Moulik 18
2    Aryan  19
3    Ravi   19
```

---

# 📊 Example Query Plan

```
CREATE INDEX ON learners (age)

EXPLAIN SELECT * FROM learners WHERE age = 19
```

Output:

```
Query Plan:
Index Scan on learners(age)
```

---

# 🛠 Build Instructions

Compile using **C++17**:

```
g++ -std=c++17 main.cpp table.cpp database.cpp parser.cpp engine.cpp -o minisql
```

Run:

```
./minisql database.db
```

Example:

```
./minisql mydatabase.db
```

---

# 📂 Project Structure

```
MiniSQLEngine/
│
├── main.cpp        → Program entry point & CLI interface
├── engine.cpp      → Query execution logic
├── engine.h
│
├── parser.cpp      → SQL tokenizer
├── parser.h
│
├── database.cpp    → Database manager
├── database.h
│
├── table.cpp       → Table storage & indexing
├── table.h
│
├── README.md
└── minisql.png     → Demo screenshot
```

---

# 📈 Future Improvements

Possible extensions for MiniSQL++:

- JOIN queries
- ORDER BY
- GROUP BY
- query optimizer improvements
- multi-column indexes
- binary storage engine
- transaction support
- concurrency control

---

# 🎯 Learning Goals

This project explores key concepts from **database systems and systems programming**, including:

- SQL query parsing
- relational storage models
- hash-based indexing
- query execution pipelines
- persistent storage design
- command-line database interfaces

---

# 👨‍💻 Author

**Moulik Choudhary**  
B.Tech CSE — Chandigarh University  

Interests:

- Systems Programming
- Database Systems
- Distributed Systems
- Backend Engineering
- Automation

---

# 📸 Demo

![Demo](minisql.png)

---

# ⭐ Project Status

MiniSQL++ is a **learning-oriented database engine** demonstrating the internal architecture of relational databases using C++.

It serves as a **portfolio project showcasing systems programming, database internals, and algorithmic design**.