#include <stdio.h>

int isVowel(char ch)
{
    ch = (ch >= 'A' && ch <= 'Z') ? ch + 32 : ch;
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}

void replaceVowels(char arr[][20])
{
    char *p = &arr[0][0];

    int total = 3 * 20;

    for (int i = 0; i < total; i++)
    {
        if (isVowel(*(p + i)))
        {
            *(p + i) = '*';
        }
    }
}

void displayArray(char arr[][20])
{
    printf("\nUpdated Array:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", arr[i]);
    }
}

int main()
{
    char words[3][20] = {
        "hello world",
        "computer science",
        "pointers in c"
    };

    printf("Original Array:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", words[i]);
    }

    replaceVowels(words);

    displayArray(words);

    return 0;
}
