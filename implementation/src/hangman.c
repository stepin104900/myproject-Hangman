
_Bool rand_called = 0;

void printBody(int mistakecnt, char* body)
{
	printf("\tMistakes :%d\n", mistakecnt);
	switch(mistakecnt)
    {
		case 6: body[6] = '\\'; break;
		case 5: body[5] = '/'; break;
		case 4: body[4] = '\\'; break;
		case 3: body[3] = '|'; break;
		case 2: body[2] = '/'; break;
		case 1: body[1] = ')', body[0] = '('; break;
		default: break;
	}

	printf("\t _________\n"
	       "\t|         |\n"
	       "\t|        %c %c\n"
	       "\t|        %c%c%c\n"
	       "\t|        %c %c\n"
	       "\t|             \n"
	       "\t|             ", body[0], body[1], body[2],body[3], body[4], body[5], body[6]);
}

void printWord(char* guess, int len)
{
	printf("\t");
	for (int i = 0; i < len; ++i)
	{
		printf("%c ", guess[i]);
	}
	printf("\n\n");
}

int i_rnd(int i)
{
    if (!rand_called)
    {
        srand(time(0) << 10);
        rand_called = 1;
    }
    return rand() % i;
}

char* decrypt(char* code)
{
	int hash = ((strlen(code) - 3) / 3) + 2;
	char* decrypt = malloc(hash);
	char* toFree = decrypt;
	char* word = code;
	for (int ch = *code; ch != '\0'; ch = *(++code))
	{
		if((code - word + 2) % 3  == 1){
			*(decrypt++) = ch - (word - code + 1) - hash;
		}
	}
	*decrypt = '\0';
	return toFree;
}
