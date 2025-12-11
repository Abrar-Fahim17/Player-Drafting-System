#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 100
#define MAX_TEAMS 10
#define ROSTER_SIZE 11
#define ADMIN_PASSWORD "admin123"

struct Player {
    char name[50];
    int age;
    char position[20];
    char nationality[20];
    int cost;
    int goals;
    int assists;
    int available; // 1 = available, 0 = drafted
    int jersey;
};
struct Team {
    char name[50];
    char password[20];
    struct Player roster[ROSTER_SIZE];
    int playerCount;
};

struct Player players[MAX_PLAYERS];
int playerCount = 0;

struct Team teams[MAX_TEAMS];
int teamCount = 0;

void loadData() {
    FILE *fp;
    fp = fopen("players.txt", "r");
    if (fp != NULL) {
        char line[200];
        playerCount = 0;
        while (fgets(line, sizeof(line), fp)) {
            char *token = strtok(line, "|");
            if (token) strcpy(players[playerCount].name, token);
            token = strtok(NULL, "|");
            if (token) players[playerCount].age = atoi(token);
            token = strtok(NULL, "|");
            if (token) strcpy(players[playerCount].position, token);
            token = strtok(NULL, "|");
            if (token) strcpy(players[playerCount].nationality, token);
            token = strtok(NULL, "|");
            if (token) players[playerCount].cost = atoi(token);
            token = strtok(NULL, "|");
            if (token) players[playerCount].goals = atoi(token);
            token = strtok(NULL, "|");
            if (token) players[playerCount].assists = atoi(token);
            token = strtok(NULL, "|");
            if (token) players[playerCount].available = atoi(token);
            token = strtok(NULL, "|");
            if (token) players[playerCount].jersey = atoi(token);
            playerCount++;
        }
        fclose(fp);
    }
    fp = fopen("teams.txt", "r");
    if (fp != NULL) {
        char line[200];
        teamCount = 0;
        while (fgets(line, sizeof(line), fp)) {
            char *token = strtok(line, "|");
            if (token) strcpy(teams[teamCount].name, token);
            token = strtok(NULL, "|");
            if (token) strcpy(teams[teamCount].password, token);
            token = strtok(NULL, "|");
            if (token) teams[teamCount].playerCount = atoi(token);
            for (int i = 0; i < teams[teamCount].playerCount; i++) {
                fgets(line, sizeof(line), fp);
                token = strtok(line, "|");
                if (token) strcpy(teams[teamCount].roster[i].name, token);
                token = strtok(NULL, "|");
                if (token) teams[teamCount].roster[i].age = atoi(token);
                token = strtok(NULL, "|");
                if (token) strcpy(teams[teamCount].roster[i].position, token);
                token = strtok(NULL, "|");
                if (token) strcpy(teams[teamCount].roster[i].nationality, token);
                token = strtok(NULL, "|");
                if (token) teams[teamCount].roster[i].cost = atoi(token);
                token = strtok(NULL, "|");
                if (token) teams[teamCount].roster[i].goals = atoi(token);
                token = strtok(NULL, "|");
                if (token) teams[teamCount].roster[i].assists = atoi(token);
                token = strtok(NULL, "|");
                if (token) teams[teamCount].roster[i].available = atoi(token);
                token = strtok(NULL, "|");
                if (token) teams[teamCount].roster[i].jersey = atoi(token);
            }
            teamCount++;
        }
        fclose(fp);
    }
}

void saveData() {
    FILE *fp;
    fp = fopen("players.txt", "w");
    for (int i = 0; i < playerCount; i++) {
        fprintf(fp, "%s|%d|%s|%s|%d|%d|%d|%d|%d\n", players[i].name, players[i].age, players[i].position, players[i].nationality, players[i].cost, players[i].goals, players[i].assists, players[i].available, players[i].jersey);
    }
    fclose(fp);
    fp = fopen("teams.txt", "w");
    for (int i = 0; i < teamCount; i++) {
        fprintf(fp, "%s|%s|%d\n", teams[i].name, teams[i].password, teams[i].playerCount);
        for (int j = 0; j < teams[i].playerCount; j++) {
            fprintf(fp, "%s|%d|%s|%s|%d|%d|%d|%d|%d\n", teams[i].roster[j].name, teams[i].roster[j].age, teams[i].roster[j].position, teams[i].roster[j].nationality, teams[i].roster[j].cost, teams[i].roster[j].goals, teams[i].roster[j].assists, teams[i].roster[j].available, teams[i].roster[j].jersey);
        }
    }
    fclose(fp);
}

int findPlayer(char *name) {
    for (int i = 0; i < playerCount; i++) {
        if (strcmp(players[i].name, name) == 0) return i;
    }
    return -1;
}

int findTeam(char *name) {
    for (int i = 0; i < teamCount; i++) {
        if (strcmp(teams[i].name, name) == 0) return i;
    }
    return -1;
}

void displayPlayer(struct Player p) {
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Position: %s\n", p.position);
    printf("Nationality: %s\n", p.nationality);
    printf("Cost: %d\n", p.cost);
    printf("Goals: %d\n", p.goals);
    printf("Assists: %d\n", p.assists);
    printf("Availability: %s\n", p.available ? "Available" : "Drafted");
    if (!p.available) printf("Jersey: %d\n", p.jersey);
}

void adminMenu() {
    int choice;
    while (1) {
        printf("\nAdmin Menu:\n");
        printf("1. Create Team Account\n");
        printf("2. Delete Team Account\n");
        printf("3. List Team Accounts\n");
        printf("4. Add Player to Database\n");
        printf("5. Edit Player\n");
        printf("6. Delete Player\n");
        printf("7. View All Players\n");
        printf("8. View Player Info\n");
        printf("9. Save and Exit to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline
        switch (choice) {
            case 1: {
                if (teamCount >= MAX_TEAMS) {
                    printf("Max teams reached.\n");
                    break;
                }
                char name[50], pass[20];
                printf("Enter team name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // remove newline
                if (findTeam(name) != -1) {
                    printf("Team already exists.\n");
                    break;
                }
                printf("Enter password: ");
                fgets(pass, sizeof(pass), stdin);
                pass[strcspn(pass, "\n")] = '\0';
                strcpy(teams[teamCount].name, name);
                strcpy(teams[teamCount].password, pass);
                teams[teamCount].playerCount = 0;
                teamCount++;
                printf("Team created.\n");
                break;
            }
            case 2: {
                char name[50];
                printf("Enter team name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int idx = findTeam(name);
                if (idx == -1) {
                    printf("Team not found.\n");
                    break;
                }
                for (int i = idx; i < teamCount - 1; i++) {
                    teams[i] = teams[i + 1];
                }
                teamCount--;
                printf("Team deleted.\n");
                break;
            }
            case 3: {
                printf("Teams:\n");
                for (int i = 0; i < teamCount; i++) {
                    printf("%s\n", teams[i].name);
                }
                break;
            }
            case 4: {
                if (playerCount >= MAX_PLAYERS) {
                    printf("Max players reached.\n");
                    break;
                }
                struct Player p;
                printf("Enter name: ");
                fgets(p.name, sizeof(p.name), stdin);
                p.name[strcspn(p.name, "\n")] = '\0';
                if (findPlayer(p.name) != -1) {
                    printf("Player already exists.\n");
                    break;
                }
                printf("Enter age: ");
                scanf("%d", &p.age);
                getchar();
                printf("Enter position: ");
                fgets(p.position, sizeof(p.position), stdin);
                p.position[strcspn(p.position, "\n")] = '\0';
                printf("Enter nationality: ");
                fgets(p.nationality, sizeof(p.nationality), stdin);
                p.nationality[strcspn(p.nationality, "\n")] = '\0';
                printf("Enter cost: ");
                scanf("%d", &p.cost);
                getchar();
                printf("Enter goals: ");
                scanf("%d", &p.goals);
                getchar();
                printf("Enter assists: ");
                scanf("%d", &p.assists);
                getchar();
                p.available = 1;
                p.jersey = 0;
                players[playerCount++] = p;
                printf("Player added.\n");
                break;
            }
            case 5: {
                char name[50];
                printf("Enter player name to edit: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int idx = findPlayer(name);
                if (idx == -1) {
                    printf("Player not found.\n");
                    break;
                }
                printf("Enter new age: ");
                scanf("%d", &players[idx].age);
                getchar();
                printf("Enter new position: ");
                fgets(players[idx].position, sizeof(players[idx].position), stdin);
                players[idx].position[strcspn(players[idx].position, "\n")] = '\0';
                printf("Enter new nationality: ");
                fgets(players[idx].nationality, sizeof(players[idx].nationality), stdin);
                players[idx].nationality[strcspn(players[idx].nationality, "\n")] = '\0';
                printf("Enter new cost: ");
                scanf("%d", &players[idx].cost);
                getchar();
                printf("Enter new goals: ");
                scanf("%d", &players[idx].goals);
                getchar();
                printf("Enter new assists: ");
                scanf("%d", &players[idx].assists);
                getchar();
                printf("Player edited.\n");
                break;
            }
            case 6: {
                char name[50];
                printf("Enter player name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int idx = findPlayer(name);
                if (idx == -1) {
                    printf("Player not found.\n");
                    break;
                }
                for (int i = idx; i < playerCount - 1; i++) {
                    players[i] = players[i + 1];
                }
                playerCount--;
                printf("Player deleted.\n");
                break;
            }
            case 7: {
                printf("All Players:\n");
                for (int i = 0; i < playerCount; i++) {
                    printf("%s\n", players[i].name);
                }
                break;
            }
            case 8: {
                char name[50];
                printf("Enter player name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int idx = findPlayer(name);
                if (idx == -1) {
                    printf("Player not found.\n");
                    break;
                }
                displayPlayer(players[idx]);
                break;
            }
            case 9: {
                saveData();
                return;
            }
            default: printf("Invalid choice.\n");
        }
    }
}

void teamMenu(int teamIdx) {
    int choice;
    while (1) {
        printf("\nTeam Menu for %s:\n", teams[teamIdx].name);
        printf("1. View Team Roster\n");
        printf("2. View Player Info\n");
        printf("3. Draft Player and Assign Jersey Number\n");
        printf("4. Remove Player from Roster\n");
        printf("5. Rename Team\n");
        printf("6. Save and Exit to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline
        switch (choice) {
            case 1: {
                printf("Roster:\n");
                for (int i = 0; i < teams[teamIdx].playerCount; i++) {
                    printf("%s (Jersey: %d)\n", teams[teamIdx].roster[i].name, teams[teamIdx].roster[i].jersey);
                }
                break;
            }
            case 2: {
                char name[50];
                printf("Enter player name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int idx = findPlayer(name);
                if (idx == -1) {
                    printf("Player not found.\n");
                    break;
                }
                displayPlayer(players[idx]);
                break;
            }
            case 3: {
                if (teams[teamIdx].playerCount >= ROSTER_SIZE) {
                    printf("Roster full.\n");
                    break;
                }
                char name[50];
                printf("Enter player name to draft: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int idx = findPlayer(name);
                if (idx == -1 || !players[idx].available) {
                    printf("Player not available.\n");
                    break;
                }
                int jersey;
                printf("Enter jersey number: ");
                scanf("%d", &jersey);
                getchar();
                // Check if jersey number is unique in roster
                int unique = 1;
                for (int i = 0; i < teams[teamIdx].playerCount; i++) {
                    if (teams[teamIdx].roster[i].jersey == jersey) {
                        unique = 0;
                        break;
                    }
                }
                if (!unique) {
                    printf("Jersey number already taken.\n");
                    break;
                }
                players[idx].available = 0;
                players[idx].jersey = jersey;
                teams[teamIdx].roster[teams[teamIdx].playerCount++] = players[idx];
                printf("Player drafted.\n");
                break;
            }
            case 4: {
                char name[50];
                printf("Enter player name to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                int found = -1;
                for (int i = 0; i < teams[teamIdx].playerCount; i++) {
                    if (strcmp(teams[teamIdx].roster[i].name, name) == 0) {
                        found = i;
                        break;
                    }
                }
                if (found == -1) {
                    printf("Player not in roster.\n");
                    break;
                }
                int pidx = findPlayer(name);
                if (pidx != -1) players[pidx].available = 1;
                for (int i = found; i < teams[teamIdx].playerCount - 1; i++) {
                    teams[teamIdx].roster[i] = teams[teamIdx].roster[i + 1];
                }
                teams[teamIdx].playerCount--;
                printf("Player removed.\n");
                break;
            }
            case 5: {
                char newname[50];
                printf("Enter new team name: ");
                fgets(newname, sizeof(newname), stdin);
                newname[strcspn(newname, "\n")] = '\0';
                if (findTeam(newname) != -1) {
                    printf("Name already taken.\n");
                    break;
                }
                strcpy(teams[teamIdx].name, newname);
                printf("Team renamed.\n");
                break;
            }
            case 6: {
                saveData();
                return;
            }
            default: printf("Invalid choice.\n");
        }
    }
}

int main() {
    loadData();
    char username[50], password[20];
    while (1) {
        printf("Enter username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = '\0';
        printf("Enter password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';
        if (strcmp(username, "admin") == 0 && strcmp(password, ADMIN_PASSWORD) == 0) {
            adminMenu();
        } else {
            int idx = findTeam(username);
            if (idx != -1 && strcmp(teams[idx].password, password) == 0) {
                teamMenu(idx);
            } else {
                printf("Invalid credentials.\n");
            }
        }
    }
    return 0;
}
