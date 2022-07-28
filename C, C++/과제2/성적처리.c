#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
	char name[15];//이름
	int id;//학번
	int score;//점수
	char grade;//등급
} Student;

void evaGrade(Student s[], int size)
{//학점계산
	int index[100];
	int sub[100];
	int gradeA = size * 30 / 100;
	int gradeB = size * 65 / 100;
	int gradeC = size * 90 / 100;

	for (int i = 0; i < size; i++)
	{
		index[i] = i;
		sub[i] = s[i].score;
	}

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (sub[i] < sub[j])
			{
				int temp = index[i];
				int temp2 = sub[i];

				index[i] = index[j];
				index[j] = temp;

				sub[i] = sub[j];
				sub[j] = temp2;
			}
		}
	}

	for (int i = gradeA; i < size; i++)
	{
		if (sub[gradeA - 1] == sub[i]) gradeA += 1;
	}
	for (int i = gradeB; i < size; i++)
	{
		if (sub[gradeB - 1] == sub[i]) gradeB += 1;
	}
	for (int i = gradeC; i < size; i++)
	{
		if (sub[gradeC - 1] == sub[i]) gradeC += 1;
	}

	for (int i = 0; i < size; i++)
	{
		if (i < gradeA)
		{
      s[index[i]].grade  = 'A';
		}
		else if (i < gradeB)
		{
      s[index[i]].grade = 'B';
    }
		else if (i < gradeC)
		{
      s[index[i]].grade = 'C';
    }
		else
		{
      s[index[i]].grade = 'D';
    }
	}
}

void printResult(Student s[], int size)
{
	int index[100];
	int sub[100];

	for (int i = 0; i < size; i++)
	{
		index[i] = i;
		sub[i] = s[i].id;
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (sub[i] > sub[j])
			{
				int temp = index[i];
				int temp2 = sub[i];

				index[i] = index[j];
				index[j] = temp;

				sub[i] = sub[j];
				sub[j] = temp2;
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		printf("%d %s %d %c\n", s[index[i]].id, s[index[i]].name, s[index[i]].score, s[index[i]].grade);
	}
}

int main()
{
	int size;
	Student* s;

	scanf("%d", &size);
	s = (Student*)malloc(sizeof(Student) * size);

	for (int i = 0; i < size; i++)
	{
		scanf("%d %s %d", &(s[i].id), s[i].name, &(s[i].score));
	}
	printf("\n");

	evaGrade(s, size);
	printResult(s, size);

	free(s);
}