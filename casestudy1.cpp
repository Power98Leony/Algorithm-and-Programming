#include<stdio.h>
#include<string.h>

void reverse(char str[], int length) {
     for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void convert(char str[], int length) {
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
}

int main() {
    char str[101];
    scanf("%[^\n]", str);

    int length = strlen(str);
    reverse(str, length);
    convert(str, length);

    printf("%s\n", str);
    return 0;
}
