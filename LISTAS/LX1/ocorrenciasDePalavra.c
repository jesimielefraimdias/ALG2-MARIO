#include <stdio.h>
#define N 10000

int main(int argc) {
int i, j, t;
char a[N], p[N];
        scanf("%s", a);
        scanf("%s", p);

        for (i = 0; a[i] != '\0'; i++) {
                for (j = 0; p[j] != '\0'; j++){
                        if (a[i+j] != p[j]) break;}
                if (p[j] == '\0') printf("%d ", i);
        }
        printf("\n");
        return 0;
}
