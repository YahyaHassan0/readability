#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);

int count_words(string text1);

int count_sentences(string text2);


int main(void)
{
    string t = get_string("text: ");  // string entered by user

    int l = count_letters(t);  // counting letters function

    int w = count_words(t);  // counting words function

    int s = count_sentences(t);  // counting sentences function

    float d1 = ((float) l / (float) w) * 100;  // letters / words

    float d2 = ((float) s / (float) w) * 100;  // sentences / words

    int index = round(0.0588 * d1 - 0.296 * d2 - 15.8);  //formula


    if (index >= 1 && index <= 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }
}
int count_letters(string text)  // function counting letters
{
    int length = strlen(text) - 1;

    int counter = 0;

    for (int i = 0; i <= length; i++)
    {
        if (isalpha(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int count_words(string text1)
{
    int length = strlen(text1) - 1;

    int counter1 = 0;


    for (int j = 0; j <= length; j++)
    {
        if (isspace(text1[j]))
        {
            counter1++;
        }
    }
    if (isalpha(text1[length]) || text1[length] == (char) '.' || text1[length] == (char) '!'
        || text1[length] == (char) '?')  //checking last digit to count last word
    {
        counter1++;
    }

    return counter1;
}

int count_sentences(string text2)
{
    int length = strlen(text2) - 1;
    int counter2 = 0;

    for (int k = 0; k <= length; k++)
    {
        if (text2[k] == (char) '.' || text2[k] == (char) '!' || text2[k] == (char) '?')
        {
            counter2++;
        }
    }
    return counter2;


}
