#include <stdio.h>
#include <inttypes.h>
#include <math.h>

//Перевод вещественного числа в двоичный вид
void print_float_bin(float num)
{
    unsigned int* fi = (unsigned int*)&num;
    //~ unsigned int fi = num;//так не пойдет
    for(int i=31; i>=0; i--)
    {
        if(i==30 || i==22)
            putchar(' ');
        if(*fi & (1<<i))
            putchar('1');
        else
            putchar('0');
    }
    putchar('\n');
}
int main()
{
    /*
       тип float 4 байта
       S - знак числа 1 бит
       P - порядок 8 бит
       M - мантисса 23 бита
      */
    //~ float f=15.625;
    //~ print_float_bin(f);

    float one=1, one_error=0;
    print_float_bin(0.1);
    // 10 раз прибавляем 0.1
    for(int i=0; i<10; i++)
        one_error+=0.1;
    if ( one == one_error )
        printf("Yes\n");
    else
        printf("No\n");
    if (fabs(one-one_error) < 0.0000001)
        printf("Yes\n");
    else
        printf("No\n");
    printf("one = %f\n", one);
    printf("one_error = %f\n", one_error);
    print_float_bin(one);
    print_float_bin(one_error);

    return 0;
}
