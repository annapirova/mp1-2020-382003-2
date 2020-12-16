#include "locale.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

#define MAX_BUF 1000
#define str_buf 60

char* strDel(char* str, int n) {
	char *strCopy = (char*)malloc(MAX_BUF * sizeof(char));
	int j = 0;
	for (int i = n; i <= strlen(str); i++) {
		strCopy[j++] = str[i];
	}
	for (int i = 0; i < n - 1; i++) {
		printf_s("%c", str[i]);
	}
	printf_s("\n");
	return strCopy;
}

char* strCut(char* str) {
	bool flag = false;
	for (int i = 0; i < str_buf, i < strlen(str); i++) {
		if (str[i] == '$') {
			flag = true;
			str = strDel(str, i + 1);
			break;
		}
	}
	if (!flag && str_buf <= strlen(str)) {
		str = strDel(str, str_buf + 1);
	}
	else if (!flag && str_buf > strlen(str)) {
		str = strDel(str, strlen(str));
	}
	return str;
}


void main() {
	setlocale(LC_ALL, "Russian");
	char *str = (char*)malloc(MAX_BUF * sizeof(char));
	strcpy_s(str, MAX_BUF, "DDDDDDDDDDDDDDD$DDDDDDDDDDDDDDDD$DDDDDDDDDDDDDDDDDDD   DDDDDDDDDDDDDDDDDDDDD DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD");
	while (strlen(str) > 0) {
		str = strCut(str);
	}
	printf("%s", str);
	system("pause");
}