#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void choiceLevel()
{
	int level = 0, min = 0, max = 0;

	printf("Choisissez une niveau:\n\t1: Entre 0 et 100\n\t2: Entre 100 et 1000\n\t3: Entre 1000 et 10 000\n");
	scanf("%d", &level);
	
	generateNumber(level, min, max, level);
}

void generateNumber(int choice, int min, int max,int level)
{
	int number = 0;

	switch(choice)
	{
		case 1:
			min = 0;
			max = 100;
			srand(time(NULL));
			number = (rand() % (max - min + 1)) + 1;
			break;
		case 2:
			min = 100;
			max = 1000;
			srand(time(NULL));
			number = (rand() % (max - min + 1)) + 1;
			break;
		case 3:
			min = 1000;
			max = 10000;
			srand(time(NULL));
			number = (rand() % (max - min + 1)) + 1;
			break;
		default:
			printf("Le niveau selectionne n'existe pas\n");

	}

	game(number, min, max, level);
}

void game(int mysteryNumber, int min, int max, int level)
{
    int enterNumber = 0, strokes = 0, startAgain = 1, *pStartAgain = &startAgain, *pStrokes = &strokes;

    do
	{
		printf("Saisissez un nombre entre %d et %d\n", min, max);
		scanf("%d", &enterNumber);

		if (enterNumber < mysteryNumber)
		{
			printf("C'est plus!\n\n");
			strokesCount(pStrokes);
		}
		else if (enterNumber > mysteryNumber)
		{
			printf("C'est moins!\n\n");
			strokesCount(pStrokes);
		}
		else
		{
			printf("Bravo vous avez trouve le nombre mystere en %d coups!\n\n", strokes + 1);
			checkRecord(strokes, level);
			goon(pStartAgain);
			if (startAgain == 1)
			{
				choiceLevel();
			}
		}
		
	} while (enterNumber != mysteryNumber && startAgain == 1);
}

int strokesCount(int *strokes)
{
	*strokes += 1;
	return *strokes;
}

void checkRecord(int strokes, int level)
{
	FILE *file = NULL;
	int record = 0;

	switch(level)
	{
		case 1:
			file = fopen("record.rd", "r");

			if(file != NULL)
			{
				fscanf(file, "%i", &record);
				if (strokes < record)
				{
					printf("Felicitations! Vous venez de battre votre record\n");
					record = strokes + 1;
					saveRecord(&record, level);
				}
				else
					printf("Vous n'avez pas battu votre precedent record de %i coups\n", record);
			}
			else 
				printf("Impossible d'ouvrir le fichier\n");

			fclose(file);
			break;

			case 2:
				file = fopen("recordlvl2.rd", "r");

				if(file != NULL)
				{
					fscanf(file, "%i", &record);
					if (strokes < record)
					{
						printf("Felicitations! Vous venez de battre votre record\n");
						record = strokes + 1;
						saveRecord(&record, level);
					}
					else
						printf("Vous n'avez pas battu votre precedent record de %i coups\n", record);
				}
				else 
					printf("Impossible d'ouvrir le fichier\n");

				fclose(file);
				break;

			case 3:
				file = fopen("recordlvl3.rd", "r");

				if(file != NULL)
				{
					fscanf(file, "%i", &record, level);
					if (strokes < record)
					{
						printf("Felicitations! Vous venez de battre votre record\n");
						record = strokes + 1;
						saveRecord(&record, level);
					}
					else
						printf("Vous n'avez pas battu votre precedent record de %i coups\n", record);
				}
				else 
					printf("Impossible d'ouvrir le fichier\n");
				fclose(file);
	}
}

void saveRecord(int *record, int level)
{
	FILE *file = NULL;

	switch(level)
	{
		case 1:
			file = fopen("record.rd", "w");
	
			if(file != NULL)
			{
				fprintf(file, "%d" , *record);
				printf("Le record a bien ete enregistre\n\n");
			}
			else
			{
				printf("Impossible de charger le fichier");
			}

			fclose(file);
			break;

		case 2:
			file = fopen("recordlvl2.rd", "w");
	
			if(file != NULL)
			{
				fprintf(file, "%d" , *record);
				printf("Le record a bien ete enregistre\n\n");
			}
			else
			{
				printf("Impossible de charger le fichier");
			}

			fclose(file);
			break;

		case 3:
			file = fopen("recordlvl3.rd", "w");
	
			if(file != NULL)
			{
				fprintf(file, "%d" , *record);
				printf("Le record a bien ete enregistre\n\n");
			}
			else
			{
				printf("Impossible de charger le fichier");
			}

			fclose(file);
			break;
	}
}

int goon(int *startAgain)
{
	int choice = 0;

	printf("Voulez-vous recommencer le jeu?\n\t1: Oui\n\t2: Non\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			*startAgain = 1;
			return *startAgain;
			break;
		case 2:
			*startAgain = 0;
			return *startAgain;
			break;
		default: 
			printf("La valeur saisie est inconnue\n");
			choiceLevel();
			break;
	}
}
