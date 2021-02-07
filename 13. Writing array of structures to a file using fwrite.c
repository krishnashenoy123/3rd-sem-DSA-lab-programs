#include <stdio.h>

struct student {
	int regno;
	char name[20];
};

int main() {
	struct student students[20], temp;
	int n, i;
	FILE *fout, *fin;

	fout = fopen("student.txt", "w");

	if (fout == NULL) {
		printf("Could not open file\n");
		return 0;
	}

	printf("Enter the number of students: ");
	scanf("%d", &n);
	printf("\n");

	for (i = 0; i < n; i++) {
		printf("Enter details of student %d:\n", (i+1));
		printf("Enter name: ");
		scanf("%s", students[i].name);
		printf("Enter Register no: ");
		scanf("%d", &students[i].regno);
		printf("\n");
	}

	fwrite(students, sizeof(struct student), n, fout);

	fclose(fout);

	fin = fopen("student.txt", "r");

	if (fin == NULL) {
		printf("Could not open file\n");
		return 0;
	}

	printf("Data from file is as follows:\n");
	while (fread(&temp, sizeof(struct student), 1, fin)) {
		printf("Name: %s\n", temp.name);
		printf("Reg No: %d\n\n", temp.regno);
	}

	return 0;
}