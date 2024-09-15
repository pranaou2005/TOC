#include <stdio.h>
#include <string.h>

int isAccepted(char* str) {
    int state = 0; // Initial state

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        switch (state) {
            case 0:
                if (c == 'a') state = 1; // Move to state 1 if 'a'
                else return 0; // Reject if first character is not 'a'
                break;
            case 1:
                if (c == 'a') state = 1; // Stay in state 1 if 'a'
                else if (c == 'b') state = 1; // Stay in state 1 for 'b'
                break;
        }
    }
    return state == 1 && str[strlen(str)-1] == 'a'; // Accept if ends with 'a'
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isAccepted(str)) printf("Accepted\n");
    else printf("Rejected\n");
    return 0;
}
