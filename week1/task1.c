#include <stdio.h>

int
main(void)
{
    double x, y;
    int result = 0;
    scanf("%lf\n%lf", &x, &y);
    if ((x >= 2 && x <= 5) && (y >= 1 && y <= 7) && (x <= y + 2)) {
        result = 1;
    }
    printf("%d", result);
    return 0;
}
