#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define EQ "=\n"
#define GT ">\n"
#define GE ">=\n"
#define LT "<\n"
#define LE "<=\n"
//########    FONTS COLORS FG  ########//
#define ANSI_FOREGROUND_BLACK   "\e[30m"
#define ANSI_FOREGROUND_RED     "\e[31m"
#define ANSI_FOREGROUND_GREEN   "\e[32m"
#define ANSI_FOREGROUND_YELLOW  "\e[33m"
#define ANSI_FOREGROUND_BLUE    "\e[34m"
#define ANSI_FOREGROUND_MAGENTA "\e[35m"
#define ANSI_FOREGROUND_CYAN    "\e[36m"
#define ANSI_FOREGROUND_WHYTE   "\e[37m"

//########    FONTS COLORS BG  ########//
#define ANSI_BACKGROUND_BLACK   "\e[40m"
#define ANSI_BACKGROUND_RED     "\e[41m"
#define ANSI_BACKGROUND_GREEN   "\e[42m"
#define ANSI_BACKGROUND_YELLOW  "\e[43m"
#define ANSI_BACKGROUND_BLUE    "\e[44m"
#define ANSI_BACKGROUND_MAGENTA "\e[45m"
#define ANSI_BACKGROUND_CYAN    "\e[46m"
#define ANSI_BACKGROUND_WHITE   "\e[47m"

//########    FONTS EFFECTS    ########//
#define ANSI_EFFECT_RESET     "\e[0m"
#define ANSI_EFFECT_BOLD      "\e[1m"
#define ANSI_EFFECT_DIM       "\e[2m"
#define ANSI_EFFECT_ITALIC    "\e[3m"
#define ANSI_EFFECT_UNDERLINE "\e[4m"

long double binomial_distribution(long double n, long double x, long double p, long double q);
long long int factorial(long long int n);

int main() {
   long double n, x, p, q;
   long double bin_dis = 0;
   long double bin_dis_cumulative_le = 0, bin_dis_cumulative_lt = 0;
   long double bin_dis_cumulative_ge = 0, bin_dis_cumulative_gt = 0;
   int condition;
   printf("%s%sPlease input the vars:\n%s{n} Number of trials (e.g. 10) -> "ANSI_EFFECT_RESET, ANSI_EFFECT_BOLD, ANSI_FOREGROUND_GREEN, ANSI_FOREGROUND_BLUE);
   scanf("%Lf", &n);
   if (n > 20 || n < 1) {
      printf(ANSI_FOREGROUND_RED"The {n} Number of trials must be bigger or equal 1 and less or equal 20, because if you put a bigger value this will exceed long long int limit"ANSI_EFFECT_RESET);
      exit(0);
   }
   printf("%s%s{x} Number of success desired (e.g. 5) -> "ANSI_EFFECT_RESET, ANSI_EFFECT_BOLD, ANSI_FOREGROUND_BLUE);
   scanf("%Lf", &x);
   if (x > n || x < 0) {
      printf(ANSI_FOREGROUND_RED"The {x} Number of success desired must be less or equal {n} and bigger or equal zero"ANSI_EFFECT_RESET);
      exit(0);
   }
   printf("%s%s{p} Probability of getting success in one trial (e.g. 0.5) -> "ANSI_EFFECT_RESET, ANSI_EFFECT_BOLD, ANSI_FOREGROUND_BLUE);
   scanf("%Lf", &p);
   if (p < 0.0 || p > 1.0) {
      printf(ANSI_FOREGROUND_RED"The {p} Probability of getting success in one trial must be in interval [0,1]"ANSI_EFFECT_RESET);
      exit(0);
   }
   q = 1-p;
   printf("%s%s{q} Probability of getting a failure in one trial-> %Lf\n"ANSI_EFFECT_RESET, ANSI_EFFECT_BOLD, ANSI_FOREGROUND_BLUE, q);
   printf("\n%s%sChoose a condition [0 to = | 1 to <= | 2 to >= | -1 to \'all\'] (e.g. 0) \n-> "ANSI_EFFECT_RESET, ANSI_EFFECT_BOLD, ANSI_FOREGROUND_BLUE);
   scanf("%d", &condition);

   if (condition == -1) {
      // cummulative less
      for (long long int i = 0; i <= (long long int)x; i++) {
         bin_dis = binomial_distribution(n, (long double)i, p, q);
         bin_dis_cumulative_le += bin_dis;
         if (i != x) {
            bin_dis_cumulative_lt += bin_dis;
         }
      }
      for (long long int i = (long long int)x; i <= (long long int)n; i++) {
         bin_dis = binomial_distribution(n, (long double)i, p, q);
         bin_dis_cumulative_ge += bin_dis;
         if (i != x) {
            bin_dis_cumulative_gt += bin_dis;
         }
      }
      bin_dis = binomial_distribution(n, x, p, q);
   }

   if (condition == 0) {
      bin_dis = binomial_distribution(n, x, p, q);
   }
   if (condition == 1) {
      for (long long int i = 0; i <= (long long int)x; i++) {
         bin_dis += binomial_distribution(n, (long double)i, p, q);
      }
   }
   if (condition == 2) {
      for (long long int i = (long long int)x; i <= (long long int)n; i++) {
         bin_dis += binomial_distribution(n, (long double)i, p, q);
      }
   }

   if (condition != -1) {
      long double value = bin_dis*100.0;
      printf("\n%s%sP(x%s%Lf) = %Lf = %.2Lf%%\n\n-------------------------\n", ANSI_EFFECT_BOLD, ANSI_FOREGROUND_GREEN, condition == 1 ? "<=" : condition == 2 ? ">=" : "=", x, bin_dis, value);
      printf("- n: %Lf\n- x: %Lf\n- p: %Lf\n- q: %Lf\n"ANSI_EFFECT_RESET, n, x, p, q);
   }

   if (condition == -1) {
      long double value_bin_dis = bin_dis*100.0;
      long double value_bin_dis_cumulative_le = bin_dis_cumulative_le*100.0;
      long double value_bin_dis_cumulative_lt = bin_dis_cumulative_lt*100.0;
      long double value_bin_dis_cumulative_ge = bin_dis_cumulative_ge*100.0;
      long double value_bin_dis_cumulative_gt = bin_dis_cumulative_gt*100.0;
      printf("\n%s%sP(x=%Lf) = %Lf = %.2Lf%%\n", ANSI_EFFECT_BOLD, ANSI_FOREGROUND_GREEN, x, bin_dis, value_bin_dis);
      printf("P(x<=%Lf) = %Lf = %.2Lf%%\n", x, bin_dis_cumulative_le, value_bin_dis_cumulative_le);
      printf("P(x<%Lf) = %Lf = %.2Lf%%\n", x, bin_dis_cumulative_lt, value_bin_dis_cumulative_lt);
      printf("P(x>=%Lf) = %Lf = %.2Lf%%\n", x, bin_dis_cumulative_ge, value_bin_dis_cumulative_ge);
      printf("P(x>%Lf) = %Lf = %.2Lf%%\n\n-------------------------\n", x, bin_dis_cumulative_gt, value_bin_dis_cumulative_gt);
      printf("- n: %Lf\n- x: %Lf\n- p: %Lf\n- q: %Lf\n"ANSI_EFFECT_RESET, n, x, p, q);
   }
   return 0;
}

long long int factorial(long long int n) {
   if (n <= 0) {
      return 1;
   } else {
      return n*factorial(n-1);
   }
}

long double binomial_distribution(long double n, long double x, long double p, long double q) {
   return (factorial((long long int)n) / (factorial((long long int)(n-x))*factorial((long long int)x))) * powl(p, x) * powl(q, (n-x));
}
