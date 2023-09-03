#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stats
{
    int power;
    int speed;
}stats;

typedef struct player
{
    char username[300];
    int level;
}player;

typedef struct info
{
    player pemain;
    stats status;
}info;

info infoPlayer[100];
int players = 0;

// Functions
info addPlayer() {
    char username[300];
    int level, power, speed;

    printf("Create Username : ");
    scanf("%s", username); getchar();

    printf("Add Level : ");
    scanf("%d", &level); getchar();

    printf("Add Power : ");
    scanf("%d", &power); getchar();

    printf("Add Speed : ");
    scanf("%d", &speed); getchar();

    info newInfo = {{ "", level }, {power, speed}};
    strcpy(newInfo.pemain.username, username);

    return newInfo;
}

void playersStats() {
    for (int i = 0; i < players; i++)
    {
        info infoPlayers = infoPlayer[i];
        printf("%s's Stats\nLevel : %d\nPower : %d\nSpeed : %d\n\n", 
        infoPlayers.pemain.username, infoPlayers.pemain.level,
         infoPlayers.status.power, infoPlayers.status.speed);
    }
    
}

int main () {

    int input = 0;

    do
    {
        system("cls");
        printf("1. Add Player\n");
        printf("2. Players Stats\n");
        printf("3. Exit\n");
        scanf("%d", &input); getchar();
        switch (input)
        {
        case 1:
            infoPlayer[players++] = addPlayer();
            break;
        
        case 2:
            playersStats();
            getchar();
            break;
        }
    } while (input != 3);
    

    return 0;
}