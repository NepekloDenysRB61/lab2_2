#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double num_comput_integral_l_re(double left_boundary_a,
                                double right_boundary_b,  unsigned int intervals);
double num_comput_integral_r_re(double left_boundary_a,
                                double right_boundary_b,  unsigned int intervals);
double num_comput_integral_trap(double left_boundary_a,
                                double right_boundary_b, unsigned int intervals);
double num_comput_integral_Simps (double left_boundary_a,
                                  double right_boundary_b, unsigned int intervals);
double integrand_expression( double x );

int main()
{
    double left_boundary_a=0, right_boundary_b=0;
    double measurement_error=0;
    unsigned int intervals, var;
    double integral_s=0;

while(1)
    {
    printf("\n\tEnter the left boundary \n  X(first)=");
    scanf("%lf", &left_boundary_a);
    printf("\n\tEnter the right boundary \n  X(last)=");
    scanf("%lf", &right_boundary_b);
     do{
      printf("\tEnter the number of partition intervals (N>0)\nN=");
      scanf("%u", &intervals);
      }while(intervals <= 0);

  printf("\n\tEnter the measurment error of integration\n  Measurment error=");
  scanf("%lf", &measurement_error);
 do
  {
          printf("\nChoose the method of calculating:\n");
printf("\t1. By Left Rectangles:\n");
printf("\t2. By Right Rectangles:\n");
printf("\t3. By Trapezoid method:\n");
printf("\t4. By Simpson's method:\n");
scanf("%u", &var);

if (var != 1 && var != 2 && var != 3 && var != 4)
    printf("\nYou are mistaken\n");

} while (var != 1 && var != 2 && var != 3 && var != 4);
 system("cls");
   switch(var)
         {
         case 1:
            {
                integral_s = num_comput_integral_l_re(left_boundary_a,
                                                      right_boundary_b, intervals);
                printf("\n\n\t*Left Rectangles method*\n");
                printf("\n\ta = %.2lf    \n\tb = %.2lf   \n\tIntegral = %.8lf   \n\tN = %u",
                       left_boundary_a, right_boundary_b,  integral_s, intervals);
            }
         break;

        case 2:
{
    integral_s = num_comput_integral_r_re(left_boundary_a,
                                          right_boundary_b, intervals);

    printf("\n\n\t======*Right Rectangles method*======\n");

    printf("\n\ta = %.2lf\n\tb = %.2lf\n\tIntegral = %.8lf\n\tN = %d",
           left_boundary_a, right_boundary_b, integral_s, intervals);
}
break;
         case 3:
{
    integral_s = num_comput_integral_trap(left_boundary_a,
                                          right_boundary_b, intervals);

    printf("\n\n\t======*Trapezoid method*======\n");

    printf("\n\ta = %.2lf\n\tb = %.2lf\n\tIntegral = %.8lf\n\tN = %d",
           left_boundary_a, right_boundary_b, integral_s, intervals);
}
break;

case 4:
{
    integral_s = num_comput_integral_Simps(left_boundary_a,
                                           right_boundary_b, intervals);

    printf("\n\n\t======*Simpson's method*======\n");

    printf("\n\ta = %.2lf\n\tb = %.2lf\n\tIntegral = %.8lf\n\tN = %d",
           left_boundary_a, right_boundary_b, integral_s, intervals);
}
break;
         }
}

    return 0;
}

// Опис функцій, які повинні реалізувати алгоритм обчислення визначеного
 // інтегралу відповідним методом.
// В якості прикладу, наводиться лише реалізація одного методу.
// Для інших методів представлено лише заголовки функцій.
// Опис функцій повинен бути виконаний студентом самостійно.

// Обчислення інтегралу методом лівих прямокутників
double num_comput_integral_l_re(double left_boundary_a,
                                double right_boundary_b,  unsigned int intervals)
{
    double integral_s=0, x=0, h;
    unsigned int i;
    h = ( right_boundary_b - left_boundary_a ) / intervals;
    x = left_boundary_a;

    for (i = 0;  i < intervals;  i++ ){
      integral_s += integrand_expression(x);
      x += h;
    }
    return integral_s*h;
}
// Обчислення інтегралу методом правих прямокутників
double num_comput_integral_r_re(double left_boundary_a,
                                double right_boundary_b,  unsigned int n)
{
   double integral_s = 0, x = 0, h;
    unsigned int i;

    h = (right_boundary_b - left_boundary_a) / n;
    x = left_boundary_a + h;

    for (i = 0; i < n; i++) {
        integral_s += integrand_expression(x);
        x += h;
    }

    return integral_s * h;
}

// Обчислення інтегралу методом Сімпсона
double num_comput_integral_Simps(double left_boundary_a,
                                 double right_boundary_b, unsigned int n)
{
    double integral_s = 0, x, h;
    unsigned int i;

    h = (right_boundary_b - left_boundary_a) / n;

    for (i = 1; i < n; i++) {
        x = left_boundary_a + i * h;

        if (i % 2 == 0)
            integral_s += 2 * integrand_expression(x);
        else
            integral_s += 4 * integrand_expression(x);
    }

    return h / 3 * (integrand_expression(left_boundary_a) +
                    integrand_expression(right_boundary_b) +
                    integral_s);
}
// Обчислення інтегралу методом трапецій
double num_comput_integral_trap(double left_boundary_a,
                                double right_boundary_b, unsigned int n)
{
    double integral_s = 0, x, h;
    unsigned int i;

    h = (right_boundary_b - left_boundary_a) / n;

    for (i = 1; i < n; i++) {
        x = left_boundary_a + i * h;
        integral_s += integrand_expression(x);
    }

    return h / 2 * (integrand_expression(left_boundary_a) +
                    integrand_expression(right_boundary_b) +
                    2 * integral_s);
}
// Підінтегральна функція для варіанту 10
double integrand_expression(double x)
{
    return pow(x, 2) * sin(x);
}
