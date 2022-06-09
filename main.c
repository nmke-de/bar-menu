#include "BarnabasBox/barnabas.h"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

static void print_list(char **list, int len, int selection, int offset){
	int row = 0, col = 0;
	bsize(&row, &col);
	--row;
	int start = max(0, selection-row+1+offset);
	int end = min(len, row+start);
	for(int i = start; i < end; i++){
		if (selection == i) fputc('>', stderr);
		else fputc(' ', stderr);
		bputs(list[i]);
		if (selection == i) fputc('<', stderr);
		else fputc(' ', stderr);
		fputc('\n', stderr);
	}
}

int main(int argc, char **argv){
	if (argc < 2) return 1;
	binit();
	char c;
	int selection = 0;
	char **list = argv+1;
	int len = argc - 1;
	int offset = 2;
	// Print list
	print_list(list, len, selection, offset);
	while((c = fgetc(stdin)) != '\n'){
		switch (c){
			case 'j':
				if (selection < len - 1) ++selection;
				break;
			case 'k':
				if (selection > 0) --selection;
				break;
			default:
				continue;
		}
		bwash();
		// Print list
		print_list(list, len, selection, offset);
	}
	bquit();
	fputs(list[selection], stdout);
	fputc('\n', stdout);
}
