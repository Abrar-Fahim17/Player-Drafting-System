# Player Drafting System (C Project)

## 📸 Screenshots
![Screenshot 1](1.png)
![Screenshot 2](2.png)
![Screenshot 3](5.png)


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

*(From provided screenshot)*

    Enter username: admin
    Enter password: admin123

    Admin Menu:
    1. Create Team Account
    2. Delete Team Account
    3. List Team Accounts
    4. Add Player to Database
    5. Edit Player
    6. Delete Player
    7. View All Players
    8. View Player Info
    9. Save and Exit to Main Menu

### Team Account View

    Teams:
    FC Barcelona

### Team Menu

    Team Menu for FC Barcelona:
    1. View Team Roster
    2. View Player Info
    3. Draft Player and Assign Jersey Number
    4. Remove Player from Roster
    5. Rename Team
    6. Save and Exit to Main Menu

### Example Roster Output

    Roster:
    Lamine Yamal (Jersey: 10)
    Eric Garcia (Jersey: 23)

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