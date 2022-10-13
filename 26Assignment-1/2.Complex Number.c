#include <stdio.h>
#include <conio.h>
struct complex
{
   float real;
   float imaginary;
}a, b, c;

   struct complex read(void);
   void write(struct complex);
   struct complex add(struct complex, struct complex);
   struct complex sub(struct complex, struct complex);
   struct complex mul(struct complex, struct complex);
   struct complex div(struct complex, struct complex);

void main ()
{
   printf("Enter the 1st complex number\n ");
   a = read();
   write(a);
   printf("Enter  the 2nd complex number\n");
   b = read();
   write(b);
   printf("Addition\n ");
   c = add(a, b);
   write(c);
   printf("Substraction\n ");
   c = sub(a, b);
   write(c);
   printf("Multiplication\n");
   c = mul(a, b);
   write(c);
   printf("Division\n");
   c = div(a, b);
  write(c);
  getch();
}

struct complex read(void)
{
   struct complex t;
   printf("Enter the real part\n");
   scanf("%f", &t.real);
   printf("Enter the imaginary part\n");
   scanf("%f", &t.imaginary);
   return t;
}

void write(struct complex a)
{
   printf("Complex number  is\n");
   printf(" %.1f + i %.1f", a.real, a.imaginary);
   printf("\n");
}

struct complex add(struct complex p, struct complex q)
{
   struct complex t;
   t.real = (p.real + q.real);
   t.imaginary = (p.imaginary + q.imaginary);
   return t;
}

struct complex sub(struct complex p, struct complex q)
{
   struct complex t;
   t.real = (p.real - q.real);
   t.imaginary = (p.imaginary - q.imaginary);
   return t;
}
struct complex mul(struct complex p, struct complex q)
{
   struct complex t;
   t.real=(p.real * q.real) - (p.imaginary * q.imaginary);
   t.imaginary=(p.real * q.imaginary) + (p.imaginary * q.real);
   return t;
}

struct complex div(struct complex p, struct complex q)
{
   struct complex t;
   t.real = ((p.imaginary * q.real) - (p.real * q.imaginary)) / ((q.real * q.real) + (q.imaginary * q.imaginary));
   t.imaginary = ((p.real * q.real) + (p.imaginary * q.imaginary)) / ((q.real * q.real) + (q.imaginary * q.imaginary));
   return(t);
}