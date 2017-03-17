//Authors: Ben LaFeldt and Mattie Phillips
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Load array given with the letter frequencies for English from file LetFreq.txt
void readFreq(float given[], FILE * letFreq);
//Read the encoded text from an input file and accumulate the letter frequency
//data for the encoded text. Store the frequency data in array found
void calcFreq(float found[], FILE * datafile);
//Rotate the character in parameter ch down the alphabet for the number of
//positions as given in parameter num and return the resulting character
char rotate(char ch, int num);
//Compare the data in array found with the frequency data in array given, looking
//for a key that will give you the best match. To do this, try each of the 26 rotations,
//and remember which gives the smallest difference between the frequencies you
//observed and the frequencies given. Return the key
int findKey(float given[], float found[]);
//Decrypt the encoded text in the input file using the key and display the decoded text
void decrypt(int key, FILE *datafile);

int main(int argc, char* argv[])
{
	/**
	if(argc != 3)
	{
		printf("format: command encryptedfile decryptedfile\n");
		return 1;
	}
	printf("Passed files: %s %s\n", argv[1], argv[2]);
	char ch = 'g';
	printf("ch++: %c\n", ++ch);
	printf("End of program\n");
	*/
	FILE * letFreq = fopen("LetFreq.txt", "r");
	float frequencies[26];
	readFreq(frequencies, letFreq);
	fclose(letFreq);

	FILE * cyphertext = fopen(argv[1], "r+");
	float cipherfreq[26];
	calcFreq(cipherfreq, cyphertext);

	int cipherKey = findKey(frequencies,cipherfreq);
	printf("%d\n", cipherKey);

	decrypt(cipherKey, cyphertext); 

	fclose(cyphertext);
	//printf("a,3:\t%c\n",rotate('a',3));
	//printf("a,27:\t%c\n",rotate('a',27));
	//printf("A,3:\t%c\n",rotate('A',3));
	//printf("A,27:\t%c\n",rotate('A',27));

	return 0;	
}

void readFreq(float given[], FILE * letFreq)
{
	int count = 0;
	float freq;
	char tmp;
	while (!feof(letFreq))
	{
		fscanf(letFreq, "%c %f\n", &tmp, &freq);
		given[count++] = freq;
	}
}

void calcFreq(float found[], FILE * datafile)
{
	int * totals;
	totals = (int*)calloc(26, sizeof(int));
	int total = 0;
	char ch;
	while(!feof(datafile))
	{
		fscanf(datafile, "%c", &ch);
		if(isalpha(ch))
		{
			totals[tolower(ch)-97] += 1;
			total += 1;
		}
	}
	int i;
	int *a = totals;
	float *b = found;
	for(i = 0; i < 26; i++)
	{
		*b = ((float)*a/(float)total);
		b++;
		a++;
	}
}

char rotate(char ch, int num)
{
	if(isupper(ch)){
		return ((ch-65+num)%26)+65;
	} else {
		return ((ch-97+num)%26)+97;
	}
}

//Compare the data in array found with the frequency data in array given, looking
//for a key that will give you the best match. To do this, try each of the 26 rotations,
//and remember which gives the smallest difference between the frequencies you
//observed and the frequencies given. Return the key
int findKey(float given[], float found[])
{
	float bestsos = 0xFFFF;
	int bestkey = 0;
	int key;
	for(key = 0; key < 26; key++)
	{
		float sos = 0;
		int index;
		//float *g = given;
		//float *f = found + key;

		for(index = 0; index < 26; index++)
		{
			float diff = given[index]-found[(index+key)%26];
			sos += diff * diff;
		}

		if(sos < bestsos)
		{
			bestsos = sos;
			bestkey = key;
		}
	}
	return bestkey;
}

void decrypt(int key, FILE *datafile)
{
	int k = 26-key;
	fseek(datafile, 0, SEEK_SET);
	while(!feof(datafile))
	{
		char current = fgetc(datafile);
		if(isalpha(current))
		{
			fseek(datafile, ftell(datafile)-1, SEEK_SET);
			char replacement = rotate(current,k);
			fputc(replacement,datafile);
		}
	}
}
