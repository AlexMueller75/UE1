#include <stdio.h>


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
    int j;
    double curSum = 1;
    double nextSum = 1;
    double erg = curSum;
     
    for(k=2;((nextSum > curSum)||(curSum > epsilon));k++) {
        erg=0;
        curSum=nextSum;
        for(j=1;j<k+1;j++) {
            nextSum=nextSum + pow(x,j)/tgamma(j+1);
        }
    }
    return erg;
}
