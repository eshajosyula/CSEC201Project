#include <stdio.h>
#include <string.h>

int main() {

	char inp[256];
	char fir[100];
	char sec[100];
	char thr[100];
	int i = 1;

	while (i != 0) {
		printf(">>");
		if (scanf("%[^\n]", inp) != 1) {		// %[^\n : reads everything till a newline is encountered (also spaces)
			break;
		}

		//	
		inp[strlen(inp)] = '\0';

		//	copy input into temp string 4 strtok
		char temp[256];
		strcpy(temp, inp);

		char* token = strtok(temp, " ");
		if (token == NULL) {
			continue;
		}
		strcpy(fir, token);

		//	quit
		if (strcmp(fir, "quit") == 0) {
			token = strtok(NULL, " ");
			if (token != NULL) {
				printf("Syntax error: 'quit' takes no parameters.\n");
			}
			else {
				printf("goodbye!\n");
				break;
			}
		}

		//	upload
		else if (strcmp(fir, "upload") == 0) {
			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("Syntax error: upload <local filename> <remote filename>");
				continue;
			}
			strcpy(sec, token);

			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("Syntax error: upload <local filename> <remote filename>");
				continue;
			}
			strcpy(thr, token);

			if (token != NULL) {
				printf("Syntax error: upload takes exactly two filenames");
			}
			else {
				printf("valid: upload %s %s\n", sec, thr);
			}
		}

		//	download
		else if (strcmp(fir, "download") == 0) {
			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("Syntax error: download <local filename> <remote filename>");
				continue;
			}
			strcpy(sec, token);

			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("Syntax error: download <local filename> <remote filename>");
				continue;
			}
			strcpy(thr, token);

			if (token != NULL) {
				printf("Syntax error: download takes exactly two filenames");
			}
			else {
				printf("valid: download %s %s\n", sec, thr);
			}
		}
		//	delete
		else if (strcmp(fir, "delete") == 0) {
			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("syntax error: delete <local|remote> <filename>");
				continue;
			}
			strcpy(sec, token);

			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("syntax error: delete <local|remote> <filename>");
				continue;
			}
			strcpy(thr, token);

			if (strcmp(sec, "local") != 0 && strcmp(sec, "remote") != 0) {
				printf("syntax error: delete takes exactly two parameters.\n");
			}
			else {
				printf("Valid: deleter %s %s\n", sec, thr);
			}
		}

		//	change
		else if (strcmp(fir, "change") == 0) {
			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("Syntax error: change <local|remote> <filepath>\n");
				continue;
			}
			strcpy(sec, token);

			if (token == NULL) {
				printf("Syntax error: change <local|remote> <filepath>\n");
				continue;
			}
			strcpy(thr, token);

			if (strcmp(sec, "local") != 0 && strcmp(sec, "remote") != 0) {
				printf("'%s' is not recognized. Valid options are 'local' and 'remote\n", sec);
				continue;
			}

			token = strtok(NULL, " ");
			if (token != NULL) {
				printf("syntax error: change takes exactly two parameters.\n");
			}
			else {
				printf("valid: change %s %s\n", sec, thr);
			}
		}

		//	history
		else if (strcmp(fir, "show") == 0) {
			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("Syntax error: show <local|remote> <path|files|folders>\n");
				continue;
			}
			strcpy(sec, token);

			token = strtok(NULL, " ");
			if (token == NULL) {
				printf("Syntax error: show <local|remote> <path|files|folders>\n");
				continue;
			}
			strcpy(thr, token);

			if (strcmp(thr, "path") != 0 && strcmp(thr, "files") != 0 && strcmp(thr, "folder") != 0) {
				printf("'%s' is not recognized. valid options are 'path', 'files', 'folders'.\n", thr);
				continue;
			}

			token = strtok(NULL, " ");
			if (token != NULL) {
				printf("syntax error: show takes exactly two parameters\n");
			}
			else {
				printf("valid: show %s %s\n", sec, thr);
			}

		}

		//history
		else if (strcmp(fir, "history") == 0) {
			token = strtok(NULL, " ");
			if (token != NULL) {
				printf("syntax error: 'history' takes no params\n");
			}
			else {
				printf("valid: history\n");
			}
		}

		// validate
		else if (strcmp(fir, "validate") == 0) {
			token = strtok(NULL, " ");
			if (token != NULL) {
				printf("syntax error: 'validate' takes no params\n");
			}
			else {
				printf("valid: validate\n"); 
			}
		}

		else {
			printf("%s is not a valid FML command\n", fir);
		}
	}
	return 0;
}