# Player Drafting System (C Project)

This project is a **team and player management system** written in C.\
It allows an admin to manage a global player database and create team
accounts.\
Teams can draft players, manage rosters, and view player information.

------------------------------------------------------------------------

## 📌 Features

### 👤 Admin Panel

-   Create/Delete team accounts\
-   List all teams\
-   Add players to the global database\
-   Edit player information\
-   Delete players\
-   View all players\
-   View detailed player info\
-   Save all data to files (`players.txt`, `teams.txt`)

### ⚽ Team Panel

-   View roster\
-   View detailed info of any player\
-   Draft players (with unique jersey numbers)\
-   Remove players and free them back to the database\
-   Rename team\
-   Save and exit

------------------------------------------------------------------------

## 📄 Data Storage

All data is persistently stored using text files:

-   **players.txt**\
-   **teams.txt**

Data is loaded automatically when the program starts and saved when
exiting admin/team menus.

------------------------------------------------------------------------

## 🖼 Screenshots

### Admin Login & Menu

<img width="1478" height="751" alt="1" src="https://github.com/user-attachments/assets/c2635f53-7318-4b39-b82f-703827798149" />


### Team Account View

<img width="556" height="258" alt="4" src="https://github.com/user-attachments/assets/a6df6e16-339b-4a61-8e27-f47cbb926e42" />


### Team Menu

<img width="892" height="482" alt="5" src="https://github.com/user-attachments/assets/0febca24-b628-4394-bc5d-d5e284243381" />


### Example Roster Output

<img width="892" height="92" alt="5 - Copy" src="https://github.com/user-attachments/assets/fb2b17ae-dd9f-45f6-b33f-95523e5decb8" />


------------------------------------------------------------------------

## 🧩 Code Structure

The project consists of:

-   `struct Player` -- stores player data\
-   `struct Team` -- stores team name, password, and roster\
-   `loadData()` -- loads from text files\
-   `saveData()` -- saves to text files\
-   `adminMenu()` -- admin operations\
-   `teamMenu()` -- team operations\
-   `main()` -- login system connecting everything

------------------------------------------------------------------------

## 🚀 How to Run

1.  Compile:

    ``` sh
    gcc main.c -o draft_system
    ```

2.  Run:

    ``` sh
    ./draft_system
    ```

3.  Default admin login:

        username: admin
        password: admin123

------------------------------------------------------------------------

## 📁 Project File Requirements

Ensure the following files are in the same folder:

    main.c
    players.txt
    teams.txt

If the data files don't exist, the program will create them after
saving.

------------------------------------------------------------------------

## 🛠 Future Improvements (Optional Ideas)

-   Add transfer budget & salary system\
-   Add searching/filtering functionality\
-   Add sorting options for players\
-   Add match simulation features\
-   Add GUI (SDL/GTK/QT)

------------------------------------------------------------------------

## 📜 License

This project is free to use and modify for academic and personal use.
