#include<stdio.h>



int x(int n);

int main(){

        int n;

        scanf("%d",&n);

        printf("%d\n",x(n));

return 0;
}




int x(int n) {
if (n == 1 || n == 2) return n;
else return x(n-1) + n * x(n-2);
}
