#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef char str[100];

void tirageDes(int *score, str *UN, str *DEUX, str *TROIS, str *QUATRE, str *CINQ, str *SIX);
void pariDeDes(str *nom1, str *nom2, str *UN, str *DEUX, str *TROIS, str *QUATRE, str *CINQ, str *SIX);
void batailleDeDes(str *nom1, str *nom2, str *UN, str *DEUX, str *TROIS, str *QUATRE, str *CINQ, str *SIX);

int main()
{
	srand(time(NULL));
	str UN = " -------\n|       |\n|   *   |\n|       |\n -------\n";
	str DEUX = " -------\n| *     |\n|       |\n|     * |\n -------\n";
	str TROIS = " -------\n| *     |\n|   *   |\n|     * |\n -------\n";
	str QUATRE = " -------\n| *   * |\n|       |\n| *   * |\n -------\n";
	str CINQ = " -------\n| *   * |\n|   *   |\n| *   * |\n -------\n";
	str SIX = " -------\n| *   * |\n| *   * |\n| *   * |\n -------\n";
	str nom1, nom2;
	int cont = 1, R;
	printf("entrer le nom du joueur 1 puis du joueur 2 :\n\n");
	scanf("%s", nom1);
	scanf("%s", nom2);
	while (cont != 0)
	{
		printf("\nmenu :\n0-quitter\n1-bataille\n2-pari\n\n");
		scanf("%d", &R);
		switch (R)
		{
		case 0:
			printf("bye bye les bgs\n");
			cont = 0;
			break;
		case 1:
			batailleDeDes(&nom1, &nom2, &UN, &DEUX, &TROIS, &QUATRE, &CINQ, &SIX);
			break;
		case 2:
			pariDeDes(&nom1, &nom2, &UN, &DEUX, &TROIS, &QUATRE, &CINQ, &SIX);
			break;
		default:
			printf("pas dans le menu\n\n");
			break;
		}
	}
	return 0;
}

void tirageDes(int *score, str *UN, str *DEUX, str *TROIS, str *QUATRE, str *CINQ, str *SIX)
{
	int de1, de2;
	de1 = (rand() % (6 - 1 + 1)) + 1;
	switch (de1)
	{
	case 1:
		printf("%s", *UN);
		break;
	case 2:
		printf("%s", *DEUX);
		break;
	case 3:
		printf("%s", *TROIS);
		break;
	case 4:
		printf("%s", *QUATRE);
		break;
	case 5:
		printf("%s", *CINQ);
		break;
	case 6:
		printf("%s", *SIX);
		break;
	default:
		printf("oopsie ça marche pas\n");
		break;
	}
	de2 = (rand() % (6 - 1 + 1)) + 1;
	switch (de2)
	{
	case 1:
		printf("%s", *UN);
		break;
	case 2:
		printf("%s", *DEUX);
		break;
	case 3:
		printf("%s", *TROIS);
		break;
	case 4:
		printf("%s", *QUATRE);
		break;
	case 5:
		printf("%s", *CINQ);
		break;
	case 6:
		printf("%s", *SIX);
		break;
	default:
		printf("oopsie ça marche pas\n");
		break;
	}
	*score = de1 + de2;
}

void pariDeDes(str *nom1, str *nom2, str *UN, str *DEUX, str *TROIS, str *QUATRE, str *CINQ, str *SIX)
{
	int score1, score2, pari1, pari2;
	while (1)
	{
		while (pari1 < 1 || pari1 > 12)
		{
			printf("%s parie un nombre entre 2 et 12 :\n", *nom1);
			scanf("%d", &pari1);
		}
		while (pari2 < 1 || pari2 > 12)
		{
			printf("%s parie un nombre entre 2 et 12 :\n", *nom2);
			scanf("%d", &pari2);
		}
		sleep(1);
		printf("dés de %s :\n", *nom1);
		tirageDes(&score1, &*UN, &*DEUX, &*TROIS, &*QUATRE, &*CINQ, &*SIX);
		sleep(1);
		printf("dés de %s :\n", *nom2);
		tirageDes(&score2, &*UN, &*DEUX, &*TROIS, &*QUATRE, &*CINQ, &*SIX);
		if (score1 == pari1)
		{
			printf("\n%s gagne son pari\n\n", *nom1);
			break;
		}
		else if (score2 == pari2)
		{
			printf("\n%s gagne son pari\n\n", *nom2);
			break;
		}
	}
}

void batailleDeDes(str *nom1, str *nom2, str *UN, str *DEUX, str *TROIS, str *QUATRE, str *CINQ, str *SIX)
{
	int score1, score2;
	printf("dés de %s :\n", *nom1);
	tirageDes(&score1, &*UN, &*DEUX, &*TROIS, &*QUATRE, &*CINQ, &*SIX);
	sleep(1);
	printf("dés de %s :\n", *nom2);
	tirageDes(&score2, &*UN, &*DEUX, &*TROIS, &*QUATRE, &*CINQ, &*SIX);
	if (score1 > score2)
	{
		printf("\n%s à gagné\n\n", *nom1);
	}
	else if (score1 < score2)
	{
		printf("\n%s à gagné\n\n", *nom2);
	}
	else
	{
		printf("\négalité\n\n");
	}
}
