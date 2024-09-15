#include <stdio.h>
#include <string.h>

int isAccepted(char* str) {
    int state = 0; // Initial state

    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        switch (state) {
            case 0:
                if (c == '0') state = 1; // Move to state 1 if '0'
                else return 0; // Reject if first character is not '0'
                break;
            case 1:
                if (c == '1') state = 1; // Stay in state 1 if '1'
                else if (c == '0') state = 1; // Stay in state 1 for '0'
                break;
        }
    }
    return state == 1 && str[strlen(str)-1] == '1'; // Accept if ends with '1'
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (isAccepted(str)) printf("Accepted\n");
    else printf("Rejected\n");
    return 0;
}