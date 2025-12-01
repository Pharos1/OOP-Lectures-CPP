# Проект: Беблиотека

## Компилация и изпълнение

Отворете терминал в директорията на проекта и изпълнете:

```bash
g++ -std=c++20 -Wall -Wextra -O2 main.cpp Author.cpp Book.cpp Member.cpp Loan.cpp Library.cpp -o main
```

След това
Linux:

```bash
./main
```

Windows:

```bash
main.exe
```

## Описание на класовете

### 1) `Author`

-   **Членове**: `string name`, `int birthYear`.
-   **Конструктори**:
    -   по подразбиране (`name = "Unknown"`, `birthYear = 1900`);
    -   параметризиран (използвайте _списък за инициализация_).
-   **Методи**:
    -   `string to_string() const;`
    -   getters (и `setBirthYear(int)` с валидиране: разумен диапазон, напр. 1850–2025).
-   **Добри практики**: `const`-коректност, `explicit` при едноаргументни конструктори (ако добавите такъв).

### 2) `Book`

-   **Членове**: `string title`, `Author author`, `int year`, `double price`, `string isbn`.
-   **Статични членове**: `static int totalBooks;` (брои живите инстанции).
-   **Конструктори**:
    -   по подразбиране;
    -   параметризиран (използвайте _списък за инициализация_);
    -   **копиращ** и **преместващ** конструктор (виж Rule of 5).
-   **Оператори (Rule of 5)**:

    -   копиращ оператор `operator=`;
    -   преместващ оператор `operator=`;
    -   **деструктор** (ако нямате ресурс – оставете `= default`, но все пак демонстрирайте Rule of 5).
    -   Забележка: ако нямате собствен ресурс, може да маркирате копиране/преместване като `= default`. Целта е да покажете, че знаете _кога_ да дефинирате/дефолтнете.

-   **Методи**:
    -   getters
    -   валидиране в setters (например цена ≥ 0; `year` да бъде в разумен диапазон);
    -   `string to_string() const;`
    -   `static int getTotalBooks();`
-   **Добри практики**: `explicit` при едноаргументен конструктор (ако имате), `const` методи, `= default`/`= delete` където е уместно.

### 3) `Member` (читател)

-   **Членове**: `string name`, `string memberId`, `int yearJoined`.
-   **Методи**:
    -   валидации (например `memberId` да не е празен);
    -   `string to_string() const;`
-   **Конструктори**: по подразбиране и параметризиран.

### 4) `Loan` (заем)

-   Представя заемане на книга от читател с дати.
-   **Членове**: `string isbn`, `string memberId`, `string startDate`, `string dueDate`, `bool returned`.
-   **Методи**:
    -   `void markReturned();`
    -   `bool isOverdue(const string& today) const;` _(проста лексикографска проверка YYYY-MM-DD е достатъчна за целта на задачата)_
    -   `string to_string() const;`
-   **Конструктор**: параметризиран (валидирайте, че `dueDate >= startDate`).

### 5) `Library`

-   **Членове**: `vector<Book> books;`, `vector<Member> members;`, `vector<Loan> loans;`
-   **Методи** (минимум):
    -   `void addBook(const Book& b);`
    -   `void addMember(const Member& m);`
    -   `bool hasBook(const string& isbn) const;`
    -   `bool isBookAvailable(const string& isbn) const;` _(няма активен неприключен заем)_
    -   `bool loanBook(const string& isbn, const string& memberId, const string& start, const string& due);`
    -   `bool returnBook(const string& isbn, const string& memberId);`
    -   `vector<Book> findByAuthor(const string& authorName) const;`
    -   `string to_string() const;` _(обобщена информация – брой книги/членове/активни заеми)_
-   **Добри практики**: максимално `const`-коректност, без „голи“ указатели, ясни инварианти.

---

## Примерен изход

```text
2 books | 1 members | 0 loans
Loan created.
Available ISBN-001? false
Available ISBN-001? true
```
