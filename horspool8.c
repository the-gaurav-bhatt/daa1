#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int t[256]; // use for table
void shift(char patt[]) {
    int len = strlen(patt);
    for (int i = 0; i < 256; i++) {
        t[i] = len;
    }
    for (int i = 0; i < len - 1; i++) {
        t[patt[i]] = len - 1 - i;
    }
}

int horspool(char text[],char patt[]){
    int pl = strlen(patt);
    int tl = strlen(text);
    shift(patt);
    int x = pl - 1;
    while(x<tl){
        int k= 0;
        while(k<pl && patt[pl-1-k]==text[x-k] ){
            k++;
        }
        if(k ==pl){
            printf("Pattern Found");
            return x - pl+1;
        }else{
            x+=t[text[x]];
        }
        
    }return -1;
}
int main() {
    char text[100];
    char pattern[100];

    printf("Enter the text in which the pattern is to be searched:\n");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove the trailing newline character

    printf("Enter the pattern to be searched:\n");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0'; // Remove the trailing newline character

    int result = horspool(text, pattern);

    if (result >= 0) {
        printf("Found at position: %d\n", result);
    } else {
        printf("No match found\n");
    }

    return 0;
}
