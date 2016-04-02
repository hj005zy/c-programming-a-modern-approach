#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define LOCALE_LEN 10

int main(void)
{
    char locale[LOCALE_LEN + 1];
    struct lconv *locale_conv;

    printf("Enter the locale: ");
    scanf("%s", locale);

    if (setlocale(LC_ALL, locale) == NULL) {
        printf("Locale %s is invalid\n", locale);
        exit(EXIT_FAILURE);
    }

    locale_conv = localeconv();
    printf("decimal_point = \"%s\"\n", locale_conv->decimal_point);
    printf("thousands_sep = \"%s\"\n", locale_conv->thousands_sep);
    printf("grouping = %s\n", locale_conv->grouping);
    printf("mon_decimal_point = \"%s\"\n", locale_conv->mon_decimal_point);
    printf("mon_thousands_sep = \"%s\"\n", locale_conv->mon_thousands_sep);
    printf("mon_grouping = %s\n", locale_conv->mon_grouping);
    printf("positive_sign = \"%s\"\n", locale_conv->positive_sign);
    printf("negative_sign = \"%s\"\n", locale_conv->negative_sign);
    printf("currency_symbol = \"%s\"\n", locale_conv->currency_symbol);
    printf("frac_digits = %c\n", locale_conv->frac_digits);
    printf("p_cs_precedes = %c\n", locale_conv->p_cs_precedes);
    printf("n_cs_precedes = %c\n", locale_conv->n_cs_precedes);
    printf("p_sep_by_space = %c\n", locale_conv->p_sep_by_space);
    printf("n_sep_by_space = %c\n", locale_conv->n_sep_by_space);
    printf("p_sign_posn = %c\n", locale_conv->p_sign_posn);
    printf("n_sign_posn = %c\n", locale_conv->n_sign_posn);
    printf("int_curr_symbol = \"%s\"\n", locale_conv->int_curr_symbol);
    printf("int_frac_digits = %c\n", locale_conv->int_frac_digits);
    printf("int_p_cs_precedes = %c\n", locale_conv->int_p_cs_precedes);
    printf("int_n_cs_precedes = %c\n", locale_conv->int_n_cs_precedes);
    printf("int_p_sep_by_space = %c\n", locale_conv->int_p_sep_by_space);
    printf("int_n_sep_by_space = %c\n", locale_conv->int_n_sep_by_space);
    printf("int_p_sign_posn = %c\n", locale_conv->int_p_sign_posn);
    printf("int_n_sign_posn = %c\n", locale_conv->int_n_sign_posn);

    return 0;
}
