#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_redir(char *str)
{
    int i;
    i = 0;
    char temp;
    while ((str[i] != '>' && str[i] != '<') && str[i])
        i++;;
    if (!str[i])
        return (2);
    if (str[i] == '<' || str[i] == '>')
    {
        temp = str[i++];
        if (str[i] == temp)
            i++;
        else if (str[i] == '<' || str[i] == '>')
            printf("error <>\n");
    }
    if (!str[i])
        return (1);
    else
        return (0);
}

int redir_type(char *str)
{
    if (strncmp(str, ">>", 2) == 0)
        return (1);
    else if (strncmp(str, ">", 1) == 0)
        return (2);
    else if (strncmp(str, "<<", 2) == 0)
        return (3);
    else
        return (4);
}

int main()
{
    char *str = strdup("ls>1 >> 2 <3 <<4");
	char* tmp = strtok(str, " ");
	int j = 0;
	char** mass;
	mass = (char **)malloc(sizeof(char*) * 5);
	mass[j] = tmp;
	j++;
	while (j < 5)
	{
		tmp = strtok(NULL, " ");
		mass[j] = tmp;
	    j++;
	}
	for (int i = 0; i < 5; i++)
	    printf("%s\n", mass[i]);
	j = 0;
	while (j < 5)
	{
	    int check = check_redir(mass[j]);
	    //printf("%s %d\n", mass[j], check_redir(mass[j]));
	    if (check == 1)
	    {
	        int type = redir_type(mass[j]);
	        if (mass[j + 1])
	            create_files(mass[j + 1], type);
	        else
	            printf("error end of massive\n");
	    }
	    j++;
	}
}
