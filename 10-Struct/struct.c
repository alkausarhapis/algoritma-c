#include <stdio.h>

// Struct adalah tempat penyimpanan variabel

struct stats
{
    int power;
    int speed;
};

typedef struct player
{
    char username[300];
    int level;
}player;

typedef struct info
{
    // typedef
    player pemain;
    // struct biasa
    struct stats status;
}info;

int main () {
    info infoPlayer = {{ "Wanpip", 80 }, {1000, 700}};

    printf("%s's Stats\nLevel : %d\nPower : %d\nSpeed : %d", 
    infoPlayer.pemain.username, infoPlayer.pemain.level, infoPlayer.status.power, infoPlayer.status.speed);
    return 0;
}