#include <stdio.h>
#include <math.h>

double exponential(double x, double epsilon);

int main() {
    double x, e;
    
    printf("Bitte geben Sie x ein: ");
    scanf("%lf", &x);
    
    printf("Bitte geben Sie Epsilon ein: ");
    scanf("%lf", &e);
    
    printf("Ergebnis: %lf \nFehler: %lf\n",exponential(x,e), fabs(pow(M_E, x) - exponential(x,e)));
}

double exponential(double x, double epsilon) {
    int k;
    double curSum = 1;
    double nextSum = x;
    double erg = curSum;
     
    for(k=1;((nextSum > curSum)||(curSum > epsilon));k++) {
        curSum = nextSum;
        erg = erg + nextSum;
        nextSum = nextSum * (x / k);
    } 
return erg;
}
