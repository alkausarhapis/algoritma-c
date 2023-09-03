#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<conio.h>
#include<time.h>

typedef struct{
	char name[200];
	int damage;
	int maxHealth;
}classes;

typedef struct{
	char name[200];
	int damage;
	int maxHealth;
	int expGained;
	int goldGained;
}monster;

int isNew = false;

monster monsters[] =  {
					{
						"Goblin",
						5,
						20,
						10,
						5
					},
					{
						"Orc",
						10,
						25,
						12,
						9
					}
					,{
						"Wizard",
						15,
						15,
						15,
						15
					},
					{
						"Maou",
						50,
						500,
						100,
						300
					}
					};
					
classes _class[] =  {
					{
						"Warrior",
						5,
						150
					},
					{
						"Rogue",
						10,
						75
					}
					,{
						"Archer",
						7,
						100
					}
					};

typedef struct{
	char name[200];
	classes _class;		
	int exp;
	int level;
	int gold;
	int health;
}character;

character playerCharacter;

classes loadClass(char c[]){
	if(strcmp(c, "Warrior") == 0){
		playerCharacter._class = _class[0];
	}
	else if(strcmp(c, "Rogue") == 0){
		playerCharacter._class = _class[1];
	}
	else{ //Archer (default)
		playerCharacter._class = _class[2];
	}
	return playerCharacter._class;
}

void saveAccount(){
	FILE *fp;
	fp = fopen("account.txt", "w");
	fprintf(fp, "%s#%s#%d#%d#%d#%d#%d#%d#", 
			playerCharacter.name,
			playerCharacter._class.name,
			playerCharacter._class.maxHealth,
			playerCharacter._class.damage,
			playerCharacter.exp,
			playerCharacter.level,
			playerCharacter.gold,
			playerCharacter.health);
	fclose(fp);
}
// TODO fix save bug
void loadAccount(){
	FILE *fp;
	fp = fopen("account.txt", "r");
	char tempclass[200];
	
	if(fp == NULL){
		isNew = true;
		fclose(fp);
		return;
	}
	fscanf(fp, "%[^#]#%[^#]#%d#%d#%d#%d#", 
			playerCharacter.name,
			tempclass,
			&playerCharacter.exp,
			&playerCharacter.level,
			&playerCharacter.gold,
			&playerCharacter.health);
	fclose(fp);
	loadClass(tempclass);
}

void newGame(){
	char tempclass[200];
	
	printf("Input your character's name: ");
    scanf("%199[^\n]", playerCharacter.name);
    getchar(); 

    printf("Choose your class [Warrior|Rogue|Archer]: ");
    scanf("%199s", tempclass);
    getchar();

    while (strcmp(tempclass, "Warrior") != 0 &&
           strcmp(tempclass, "Rogue") != 0 &&
           strcmp(tempclass, "Archer") != 0)
    {
        printf("\n[WARNING] Type your class correctly e.g (Archer)\n");
        printf("Choose your class [Warrior|Rogue|Archer]: ");
        scanf("%199s", tempclass);
        getchar();
    }
	
	playerCharacter.exp = 0;
	playerCharacter.level = 1;
	playerCharacter.gold = 0;
	
	playerCharacter.health = loadClass(tempclass).maxHealth;
}

void firstMenu(){
	int input;
		
	do{
		printf("-WELCOME TO RPG KETIK-\n");
		printf("1. Start New Game\n");
		if(!isNew)
			printf("2. Continue Game\n");
			
		printf(">> ");
		scanf("%d", &input); getchar();
		switch(input){
			case 1:
				newGame();	
			break;
		}
	}while(input > (isNew == true ? 1 : 2) || input < 1);
}

void fight(monster m){
	int input;
	
	int exp = m.expGained;
	int gold = m.goldGained;
	int damage = m.damage;
	int health = m.maxHealth;
	char name[200];
	strcpy(name, m.name);
	
	do{
		system("cls");
		printf("%s\nHealth : %d\nDamage : %d\n\n", name, health, damage);
		printf("%s\nHealth : %d\nDamage : %d\n\n", playerCharacter.name,
													playerCharacter.health,
													playerCharacter._class.damage);
		printf("1. Attack\n");
		printf("2. Run\n");
		printf(">> ");
		
		scanf("%d", &input); getchar();
				
		switch(input){
			case 1:
				health -= playerCharacter._class.damage; 
				if(health <= 0){ //Player win
					playerCharacter.gold += gold;
					playerCharacter.exp += exp;
					printf("You won!\nYou gained %d gold(s) and %d exp(s)\n", gold, exp);
					if(playerCharacter.exp >= 100 && playerCharacter.level < 50){
						printf("You've leveled up!\n");
						playerCharacter.exp -= 100;
						playerCharacter.level += 1;
						playerCharacter._class.damage += 1 + playerCharacter.level;
						playerCharacter._class.maxHealth += .5 + playerCharacter.level;
						playerCharacter.health = playerCharacter._class.maxHealth;
					}
					printf("Press enter to continue...");
					getchar();
					return;
				}
				playerCharacter.health -= damage;
				if(playerCharacter.health <= 0){ //Player lose
					playerCharacter.gold = 0;
					playerCharacter.exp = 0;
					playerCharacter.health = playerCharacter._class.maxHealth;
					printf("You lose!\nYou lost all your golds and exps\nPress enter to continue...");
					getchar();
					return;
				}
			break;
			case 2:
				printf("You ran away!");
				getchar();
				return;
		}
	}while(true);
}

void fightMenu(){
	int input;
	do{
		system("cls");
		printf("Fight Menu\n==========\n");
		printf("1. Goblin\n");
		printf("2. Orc\n");
		printf("3. Wizard\n");
		printf("4. Maou\n");
		printf("5. Back\n");
		printf(">> ");
		
		scanf("%d", &input); getchar();
		
		switch(input){
			case 1:
				fight(monsters[0]);
			break;
			case 2:
				fight(monsters[1]);
			break;
			case 3:
				fight(monsters[2]);
			break;
			case 4:
				fight(monsters[3]);
			break;
		}
	}while(input != 5);
}

void heal(){
	int gold = playerCharacter.gold;
	int healPrice = 20;
	
	if(playerCharacter.health == playerCharacter._class.maxHealth){
		printf("You're already at max health!\n");
	}
	else if(gold >= healPrice){
		int input;
		do{
			printf("Do you want to heal yourself for %d golds ?\n", healPrice);
			printf("1. Yes\n2. No\n>> ");
			scanf("%d", &input); getchar();
		}while(input != 1 && input != 2);
		
		if(input == 2){
			printf("Press enter to continue...");
			getchar();
			return;
		}
		
		playerCharacter.health = playerCharacter._class.maxHealth;
		playerCharacter.gold -= healPrice;
		printf("Healed!!\n");
	}
	else
		printf("You don't have enough gold!\n");
		
	printf("Press enter to continue...");
	getchar();
}

void buySword() {
    int swordPrice = 35;
    
    if (playerCharacter._class.damage >= 200) {
        printf("You already bought this item\n");
        printf("Press enter to back...\n"); getchar();
        return;
    }
    
    if (playerCharacter.gold >= swordPrice) {
        printf("Do you want to buy sword for %d coins?\n", swordPrice);
        printf("1. Yes\n2. No\n>> ");
        int input;
        scanf("%d", &input); getchar();
        
        if (input == 1) {
            playerCharacter._class.damage += 200;
            playerCharacter.gold -= swordPrice;
        } else {
            printf("Press enter to back...");
            getchar();
        }
    } else {
        printf("You broke stoopid\n");
        printf("Press enter to back...");
        getchar();
    }
}

void buyArmor() {
    int armorPrice = 30;
    
    if (playerCharacter._class.maxHealth >= 200) {
        printf("You already bought this item\n");
        printf("Press enter to back...\n"); getchar();
        return;
    }
    
    if (playerCharacter.gold >= armorPrice) {
        printf("Do you want to buy armor for %d coins?\n", armorPrice);
        printf("1. Yes\n2. No\n>> ");
        int input;
        scanf("%d", &input); getchar();
        
        if (input == 1) {
            playerCharacter._class.maxHealth += 200;
            playerCharacter.gold -= armorPrice;
        } else {
            printf("Press enter to back...");
            getchar();
        }
    } else {
        printf("You broke stoopid\n");
        printf("Press enter to back...");
        getchar();
    }
}

void buy() {
    int input;
    
    do {
        system("cls");
        printf("Shop========\n");
        printf("1. Sword (+100 Damage)\n2. Armor (+200 Max Health)\n3. Back\n>> ");
        scanf("%d", &input); getchar();
        
        switch (input) {
            case 1:
                buySword();
                break;
            case 2:
                buyArmor();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice\n");
        }
    } while (input != 3);
}


/* void buy() {
	int gold = playerCharacter.gold;
	int swordPrice = 35;
	int armorPrice = 30;
	
	int input;
	do{
		system("cls");
		printf("Shop========\n");
		printf("1. Sword (%d Coins) \n2. Armor (%d Coins)\n3. Back\n>> ", swordPrice, armorPrice);
		scanf("%d", &input); getchar();

		if (input == 1)
		{
			int input;
			do{
				system("cls");
				printf("Shop========\n");
				printf("Sword (+200 damage)\n", swordPrice);

				if (playerCharacter._class.damage >= 200)
				{
					printf("\nYou already bought this item\n");
					printf("Press enter to back...");
					getchar();
					return buy();
				}
				else if (gold >= swordPrice)
				{
					printf("Do you want to buy sword for %d coins?\n", swordPrice);
					printf("1. Yes\n2. No\n>> ");
					scanf("%d", &input); getchar();

					if (input == 1)
					{
						playerCharacter._class.damage += 200;
						playerCharacter.gold -= swordPrice;
					} else {
						printf("Press enter to back...");
					getchar();
					return buy();
					}
						
				} else {
					printf("\nYou broke stoopid\n");
					printf("Press enter to back...");
					getchar();
					return buy();
				}
			}while(input != 1 && input != 2);

		} else if(input == 2) {
			int input;
			do{
				system("cls");
				printf("Shop========\n");
				printf("Armor (+200 max health)\n", armorPrice);

				if (playerCharacter._class.maxHealth >= 200)
				{
					printf("\nYou already bought this item\n");
					printf("Press enter to back...");
					getchar();
					return buy();
				}
				else if (gold >= armorPrice)
				{
					printf("Do you want to buy armor for %d coins?\n", armorPrice);
					printf("1. Yes\n2. No\n>> ");
					scanf("%d", &input); getchar();

					if (input == 1)
					{
						playerCharacter._class.maxHealth += 200;
						playerCharacter.gold -= armorPrice;
					} else {
						printf("Press enter to back...");
					getchar();
					return buy();
					}
						
				} else {
					printf("\nYou broke stoopid\n");
					printf("Press enter to back...");
					getchar();
					return buy();
				}
			}while(input != 1 && input != 2);
		} else if (input == 3)
		{
			return;
		}
		
}while(input != 1 && input != 2 && input != 3);
}
*/

void cit() {
	system("cls");
	playerCharacter.gold += 100;
	playerCharacter.exp = 100;
	printf("Berhasil ngecit\n");
	printf("Press enter to back...");
	getchar(); return;
}

int main(){
	
	loadAccount();
	int input;
	
	system("cls");
	firstMenu();

	do{
		system("cls");
		printf("%s's Status\n==========\n", playerCharacter.name);
		printf("Level %d\nClass : %s\nGold : %d\nExp : %d/100\nHealth : %d/%d\nDamage : %d\n", 
						playerCharacter.level,
						playerCharacter._class.name,
						playerCharacter.gold, playerCharacter.exp,
						playerCharacter.health, playerCharacter._class.maxHealth, playerCharacter._class.damage);
		printf("1. Fight\n");
		printf("2. Heal\n");
		printf("3. Shop\n");
		printf("4. Save\n");
		printf("5. Quit\n");
		printf(">> ");
		
		scanf("%d", &input); getchar();
		
		switch(input){
			case 1:
				fightMenu();
				break;
			case 2:
				heal();
				break;
			case 3:
				buy();
				break;
			case 4:
				saveAccount();
				printf("Saved Successfully!!\nPress enter to continue..."); 
				getchar();
				break;
			case 69:
				cit();
				break;
		}
	}while(input != 5);
	
	return 0;
}
