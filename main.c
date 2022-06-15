#include <string.h>
#include "BarnabasBox/barnabas.h"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

static void print_list(char **list, int len, int selection, int offset, char *query, int *visibility){
	int row = 0, col = 0;
	bsize(&row, &col);
	--row;
	int start = max(0, selection-row+1+offset);
	int end = min(len, row+start-1);
	if (selection == -1) bputc('>');
	else bputc(' ');
	bputs(query);
	if (selection == -1) bputc('<');
	else bputc(' ');
	bputc('\n');
	for(int i = start; i < end; i++){
		if (selection == i) bputc('>');
		else bputc(' ');
		bputs(list[visibility[i]]);
		if (selection == i) bputc('<');
		else bputc(' ');
		bputc('\n');
	}
}

int main(int argc, char **argv){
	if (argc < 2) return 1;
	binit();
	char c;
	int selection = -1;
	char **list = argv+1;
	char query[64];
	for(int i = 0; i < 64; i++) query[i] = 0;
	int len = argc - 1;
	int vislen = len;
	int visibility[len];
	for(int i = 0; i < len; i++) visibility[i] = i;
	int offset = 2;
	// Print list
	print_list(list, vislen, selection, offset, query, visibility);
	while((c = fgetc(stdin)) != '\n'){
		switch (c){
			case '/':
				bread(query, 64, "Filter: ");
				vislen = 0;
				for(int i = 0; i < len; i++) if(strstr(list[i], query) != NULL) visibility[vislen++] = i;
				selection = 0;
				break;
			case 'j':
				if (selection < vislen - 1) ++selection;
				break;
			case 'k':
				if (selection > -1) --selection;
				break;
			case 'q':
				bquit();
				return 2;
			default:
				continue;
		}
		bwash();
		// Print list
		print_list(list, vislen, selection, offset, query, visibility);
	}
	bquit();
	if(selection == -1) fputs(query, stdout);
	else fputs(list[visibility[selection]], stdout);
	fputc('\n', stdout);
}
