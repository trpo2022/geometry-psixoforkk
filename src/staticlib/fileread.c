#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileread.h"
#include "geometryshapes.h"
#define kCircleArraySize 3
#define kTriangleArraySize 6

void FileRead() 
{
	FILE* input_file;
	input_file = fopen("input.txt", "r");
	if (!input_file) 
	{
		return;
	}
	int i = 0;
	float input_poz_circle[kCircleArraySize] = { 0 };
	float input_poz_triangle[kTriangleArraySize] = { 0 };
	while (!feof(input_file)) 
	{
		char input_k = 0;
		char input_line[127] = { 0 };
		while (input_k != '\n')
		{
			input_k = fgetc(input_file);
			if (input_k == -1) 
			{
				break;
			}
			input_line[i] = input_k;
			i++;
		}
		printf("\nYour shape: %s", input_line);
		if (input_line[0] == 't')
		{
			for (long unsigned int i = 0, d = 0; i <= strlen(input_line); i++) 
			{
				if (StrNumber(input_line[i])) 
				{
					if (input_line[i + 1] == '.') 
					{
						input_poz_triangle[d] = (input_line[i] - 0x30) + (0.1 * (input_line[i + 2] - 0x30));
						if (input_line[i - 1] == '-') 
						{
							input_poz_triangle[d] *= -1.0;
						}
						i += 2;
					}
					else 
					{
						input_poz_triangle[d] = (input_line[i] - 0x30);
						if (input_line[i - 1] == '-')
						{
							input_poz_triangle[d] *= -1.0;
						}
					}
					d++;
				}
			}
			printf("Triangle Function:\n");
			Triangle(input_poz_triangle);
		}
		if (input_line[0] == 'c')
		{
			for (long unsigned int i = 0, d = 0; i <= strlen(input_line); i++)
			{
				if (StrNumber(input_line[i])) 
				{
					if (input_line[i + 1] == '.') 
					{
						input_poz_circle[d] = (input_line[i] - 0x30) + (0.1 * (input_line[i + 2] - 0x30));
						if (input_line[i - 1] == '-') 
						{
							input_poz_circle[d] *= -1.0;
						}
						i += 2;
					}
					else 
					{
						input_poz_circle[d] = (input_line[i] - 0x30);
						if (input_line[i - 1] == '-') 
						{
							input_poz_circle[d] *= -1.0;
						}
					}
					d++;
				}
			}
			printf("Cirlce Function:\n");
			Circle(input_poz_circle);
		}
		for (int k = 0; k < kCircleArraySize; k++) 
		{
			input_poz_circle[k] = 0;
		}
		for (int k = 0; k < kTriangleArraySize; k++) 
		{
			input_poz_triangle[k] = 0;
		}
		i = 0;
	}
	fclose(input_file);
}

int StrNumber(char input_symbol) 
{
	if ((input_symbol - 0x30) >= 0 && (input_symbol - 0x30) <= 9) 
	{
		return 1;
	}
	else return 0;
}
