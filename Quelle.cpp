#include <stdio.h>
#include <string.h>

#define SIZE 255


int check_domain(char str[], char substr[]) {
	int count = 0;
	int seen = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == substr[count]) {
			count++;
		}
		else {
			count = 0;
			if ((str[i] == '@') &&  (i < strlen(str)-1)) {
				seen = 1;
				if (str[i + 1] != '.') {
					seen = 1;
				}
				else {
					seen = 0;
				}
			}
		}
		
		if ((count >= 3) && (seen == 1)) {
			return 1;+
		}
	}
	return 0;
}


int number_of_ats(char str[]) {
	int count = 0;
	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] == '@') {
			count++;
		}
	}
	return count;
}

int check_email(char str[]) {
	if ((number_of_ats(str) != 1) || (str[0] == '@') || (strlen(str) < 6)){
		return 0;
	}
	else {
		char substring[3] = { '.', 'a', 't' };

		return (check_domain(str, substring) == 1);
		
	}
}

int main(void) {
	char string[SIZE];

	printf("Geben Sie bitte eine gueltige EMail-Addresse ein:\n");
	gets_s(string, SIZE);

	printf("gueltig = 1, ungueltig = 0\n");
	printf("%d",check_email(string));
	
	return 0;
}