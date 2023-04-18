%{
#include <stdio.h>
int vowel_count = 0;
int consonant_count = 0;
int sentence_count = 0;
%}

%%

[AEIOUaeiou] {vowel_count++;}
[B-DF-HJ-NP-TV-Zb-df-hj-np-tv-z] {consonant_count++;}
[.!?] {sentence_count++;}

%%

int main()
{
    yylex();
    printf("Total number of vowels: %d\n", vowel_count);
    printf("Total number of consonants: %d\n", consonant_count);
    printf("Total number of sentences: %d\n", sentence_count);
    return 0;
}
