#include <stdio.h>
#include <math.h>

#define MAX_ITER 15
#define HATA 0.0004

// f(x)
double f(double x) {
    return 0.85 * x * x - 2.5 * x - 4;
}

// f'(x)
double f_deriv(double x) {
    return 2 * 0.85 * x - 2.5;
}

int main() {
    double nr_x[16], nr_e[16];
    double bi_x[16], bi_e[16];
    double rf_x[16], rf_e[16];
    int i;

    double a = 3.5, b = 11.0;
    double x;

    int nr_iter = 0, bi_iter = 0, rf_iter = 0;

    // Newton-Raphson
    double x0 = a;
    for (i = 1; i <= MAX_ITER; i++) {
        double x1 = x0 - f(x0) / f_deriv(x0);
        nr_x[i] = x1;
        nr_e[i] = fabs(x1 - x0);
        if (nr_iter == 0 && nr_e[i] < HATA) nr_iter = i;
        x0 = x1;
    }

    // Bisection
    double ba = a, bb = b;
    for (i = 1; i <= MAX_ITER; i++) {
        double c = (ba + bb) / 2.0;
        bi_x[i] = c;
        bi_e[i] = (bb - ba) / pow(2, i);
        if (bi_iter == 0 && bi_e[i] < HATA) bi_iter = i;
        if (f(ba) * f(c) < 0) {
            bb = c;
        } else {
            ba = c;
        }
    }

    // Regula Falsi
    double ra = a, rb = b, xr = a;
    for (i = 1; i <= MAX_ITER; i++) {
        double fxr = f(rb) - f(ra);
		if (fxr == 0.0) fxr = 1e-10; // belrsizligi engellemek icin
        x = rb - (f(rb) * (rb - ra)) / fxr;
        rf_x[i] = x;
        rf_e[i] = fabs(x - xr);
        if (rf_iter == 0 && rf_e[i] < HATA) rf_iter = i;
        xr = x;
        if (f(ra) * f(x) < 0) {
            rb = x;
        } else {
            ra = x;
        }
    }

    
    printf("\nF(x)=0.85x^2 - 2.5x - 4;   fonksiyonu icin\n\n");
    printf("# (iterasyon)    Newton Raphson Metodu             |      Ikiye Bolme Metodu             |   Dogrusal Interpolasyon Metodu\n");
    printf("                   Kok         error               |        Kok        error             |       Kok         error\n");
    printf("------------------------------------------------------------------------------------------------------------------------------\n");

    for (i = 1; i <= MAX_ITER; i++) {
        printf("%2d              %10.6lf   %10.6lf            |  %10.6lf   %10.6lf            |  %10.6lf   %10.6lf\n",
               i, nr_x[i], nr_e[i], bi_x[i], bi_e[i], rf_x[i], rf_e[i]);
    }

    printf("\n");

    if (nr_iter > 0)
        printf("Newton Raphson Metodu ile 0.0004'ten kucuk hata degerine %2d. adimda ulasildi.\n", nr_iter);


    if (bi_iter > 0)
        printf("Ikiye Bolme Metodu ile 0.0004'ten kucuk hata degerine %2d. adimda ulasildi.\n", bi_iter);
 
    if (rf_iter > 0)
        printf("Dogrusal Interpolasyon Metodu ile 0.0004'ten kucuk hata degerine %2d. adimda ulasildi.\n", rf_iter);

    return 0;
}
