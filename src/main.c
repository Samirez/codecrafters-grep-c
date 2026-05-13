#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool match_pattern(const char *input_line, const char *pattern)
{
    if (strlen(pattern) == 1)
    {
        return strchr(input_line, pattern[0]) != NULL;
    }
    else
    {
        fprintf(stderr, "Unhandled pattern %s\n", pattern);
        exit(1);
    }
}

bool match_digit(const char *input_line)
{
    for (int i = 0; input_line[i] != '\0'; i++)
    {
        if (input_line[i] >= '0' && input_line[i] <= '9')
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    // Disable output buffering
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    // You can use print statements as follows for debugging, they'll be visible when running tests.
    fprintf(stderr, "Logs from your program will appear here\n");

    if (argc != 3)
    {
        fprintf(stderr, "Expected two arguments\n");
        return 1;
    }

    const char *flag = argv[1];
    const char *pattern = argv[2];

    if (strcmp(flag, "-E") != 0)
    {
        fprintf(stderr, "Expected first argument to be '-E'\n");
        return 1;
    }

    // TODO: Uncomment the code below to pass the first stage
    //
    char input_line[1024];
    if (fgets(input_line, sizeof(input_line), stdin) == NULL)
    {
        return 1;
    }
    //
    // // Remove trailing newline
    input_line[strcspn(input_line, "\n")] = '\0';

    if (strcmp(pattern, "\\d") == 0)
    {
        // Check if the input line contains any digit
        if (match_digit(input_line))
        {
            printf("Match\n");
            return 0;
        }
        else
        {
            printf("No match\n");
            return 1;
        }
    }

    if (match_pattern(input_line, pattern))
    {
        printf("Match\n");
        return 0;
    }
    else
    {
        printf("No match\n");
        return 1;
    }
}
