# MiniSQL++ – A Lightweight SQL Engine in C++

MiniSQL++ is a **lightweight relational database engine built from scratch in C++** to explore the internal workings of database systems.

It implements a simplified SQL-like query engine capable of parsing commands, storing relational data, executing queries, and optimizing lookups using **hash-based indexing**.

This project demonstrates core database concepts including:

* SQL command parsing
* Relational table storage
* Query execution engine
* Hash-based indexing
* Persistent storage
* Query planning

---

# 🚀 Features

## Core SQL Support

* `CREATE TABLE`
* `INSERT INTO`
* `SELECT`
* `WHERE` filtering
* Column projection (`SELECT name FROM table`)
* Multiple table support

---

## Query Modification

* `DELETE FROM table WHERE condition`
* `UPDATE table SET column=value WHERE condition`

---

## Indexing & Optimization

* Hash-based indexing
* `CREATE INDEX` support
* Automatic index updates on INSERT
* Optimized WHERE queries using indexes

---

## Query Planning

* `EXPLAIN` command to show query execution strategy

Example:

```
EXPLAIN SELECT * FROM students WHERE age = 19;
```

Output:

```
Query Plan:
Index Scan on students(age)
```

or

```
Query Plan:
Full Table Scan
```

---

## Persistent Storage

Tables are automatically saved to disk and loaded when the engine starts.

Example stored file:

```
students.table
```

File contents:

```
TABLE students
COLUMNS id name age
ROW 1 Moulik 19
ROW 2 Aryan 20
ROW 3 Ravi 19
```

---

# 🏗 Architecture

```
MiniSQLEngine/
 ├── main.cpp        → CLI interface and program entry
 ├── engine.*        → SQL command execution
 ├── parser.*        → Query tokenization
 ├── database.*      → Database manager
 ├── table.*         → Table structure and indexing
```

---

# 🧠 Internal Design

MiniSQL++ follows a simplified database architecture:

```
SQL Parser
      ↓
Query Execution Engine
      ↓
Storage Layer
      ↓
Disk Persistence
```

### Data Structures

Tables are stored using:

```
unordered_map<string, Table>
```

Each table contains:

* column metadata
* row storage (`vector<Row>`)
* hash indexes

Index structure:

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

This allows **O(1) average lookup time** for indexed queries.

---

# 🖥 Example Usage

```
CREATE TABLE students (id name age)

INSERT INTO students VALUES (1 Moulik 19)
INSERT INTO students VALUES (2 Aryan 20)
INSERT INTO students VALUES (3 Ravi 19)

SELECT * FROM students

SELECT name FROM students WHERE age = 19

DELETE FROM students WHERE age = 20

UPDATE students SET age = 21 WHERE id = 1
```

---

# 📊 Example Query Plan

```
CREATE INDEX ON students (age)

EXPLAIN SELECT * FROM students WHERE age = 19
```

Output:

```
Query Plan:
Index Scan on students(age)
```

---

# 🛠 Build Instructions

Compile using **C++17**:

```
g++ -std=c++17 main.cpp table.cpp database.cpp parser.cpp engine.cpp -o minisql
```

Run:

```
./minisql
```

---

# 📂 Project Goals

This project was built to learn:

* database engine architecture
* query parsing and execution
* indexing strategies
* persistent storage design
* systems programming in C++

---

# 📈 Future Improvements

Potential future extensions:

* JOIN queries
* ORDER BY
* query optimizer improvements
* transaction support
* binary storage format
* multi-column indexes

---

# 👨‍💻 Author

**Moulik Choudhary**
B.Tech CSE | Chandigarh University

Interests:

* Systems Programming
* Databases
* Distributed Systems
* Automation

---

# 📸 Demo

![Demo](minisql.png)

---

# ⭐ Project Status

Active learning project and portfolio demonstration of **database engine fundamentals in C++**.
