#include "suD0ku.h"

void readFile(char *input, info **LinkRow, info **LinkCol, info **LinkCell, int *difficulty, int *hint)
{
	FILE * f = fopen(input, "rt");
	if (f != NULL)
	{
		int i, j;
		*LinkRow = (info*)malloc(10 * sizeof(info));
		*LinkCol = (info*)malloc(9 * sizeof(info));
		*LinkCell = (info*)malloc(9 * sizeof(info));

		ref tmp = CreateNode(9, 0);
		(*LinkRow + 9)->head = tmp;

		for (i = 0; i < 9; i++)
		{
			(*LinkRow + i)->head = NULL;
			(*LinkCol + i)->head = NULL;
			(*LinkCell + i)->head = NULL;
		}
		int n;
		ref p;
		for (i = 0; i < 9; i++)
		{ 
			for (j = 0; j < 9; j++)
			{
				p = CreateNode(i, j);
				fscanf(f, "%d", &n);
				if (n > 0 && n <= 9)
				{
					p->key = n;
					p->is_stable = true;

				}
				else
				{
					p->is_stable = false;
					if (n > 9 || n == 0)
					{
						p->key = n / 10;
						p->is_error = false;
					}
					else if (n < 0)
					{
						p->key = -n;
						p->is_error = true;
					}
				}
				AddNode(&(*LinkRow + i)->head, p, a_row);

				AddNode(&(*LinkCol + j)->head, p, a_col);

				int tmp = 3 * (i / 3) + (j / 3);
				AddNode(&(*LinkCell + tmp)->head, p, a_cell);
			}
		}
		fscanf(f, "%d", &n);
		*difficulty = n;
		fscanf(f, "%d", &n);
		*hint = n;
		fclose(f);
	}
	else
		printf("Khong doc duoc");
}

void writeFile(char* output, info *LinkRow, int difficulty, int hint)
{
	FILE* f = fopen(output, "wt");
	if (f != NULL)
	{
		for (int i = 0; i < 9; i++)
		{
			//fprintf(f, "%d\t", ROW[i].head->key);
			ref p = LinkRow[i].head;
			do
			{
				if (p->is_stable)
					fprintf(f, "%d\t", p->key);
				else
				{
					if (p->is_error)
						fprintf(f, "%d\t", -(p->key));
					else
						fprintf(f, "%d\t", (p->key) * 10);
				}
				p = p->next_row;
			} while (p != LinkRow[i].head);
			fprintf(f, "\n");
		}
		fprintf(f, "%d	%d", difficulty, hint);
	}
	fclose(f);
}