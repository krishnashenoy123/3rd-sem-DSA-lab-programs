#include <stdio.h>
#include <string.h>

int main() {
	FILE *fin1, *fin2, *fin3, *fout1, *fout2, *fout3;
	char str1[100], str2[100];
	char ch1, ch2, ch3;

	fout1 = fopen("file1.txt", "w");
	fout2 = fopen("file2.txt", "w");

	if (fout1 == NULL || fout2 == NULL) {
		printf("Could not open file for input\n");
		return 0;
	}

	printf("Enter the string for the first file:\n");
	gets(str1);
	printf("Enter the string for the second file:\n");
	gets(str2);

	fprintf(fout1, "%s", str1);
	fprintf(fout2, "%s", str2);

	fclose(fout1);
	fclose(fout2);

	fin1 = fopen("file1.txt", "r");
	fin2 = fopen("file2.txt", "r");

	while ((ch1 = getc(fin1)) != EOF && (ch2 = getc(fin2)) != EOF && ch1 == ch2);
	if (ch1 == EOF)
		ch2 = getc(fin2);

	fout3 = fopen("file3.txt", "w");

	if (fout3 == NULL) {
		printf("Could not open file3\n");
		return 0;
	}

	if (ch2 == EOF) {
		printf("The two files are equal\n");
		return 0;
	}

	printf("Difference between files: ");

	fprintf(fout3, "%c", ch2);

	while ((ch3 = getc(fin2)) != EOF)
		fprintf(fout3, "%c", ch3);

	fclose(fout3);

	fin3 = fopen("file3.txt", "r");

	while ((ch3 = getc(fin3)) != EOF)
		printf("%c", ch3);

	printf("\n");

	return 0;
}