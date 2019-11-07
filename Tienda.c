#include <stdio.h>
#include <conio.h>

// Definiciones
#define A 0
#define B 1
#define C 2
#define D 3
#define E 4
#define F 5
// Variables utiles
char carrito[100];
char product[100];
int cont[6]; // Contar para conocer cuantos productos van y se pueda reiniciar.
int contE; // Contador para el excedente de Es
int cant[6];     // Obviamente el precio.
float precio[6]; // Obviamente el precio.
float itbis[6]; // Obviamente el itbis.
int flag[2]; // Indica cuando hay una c o una d en el carrito. 1 = c, 0 = d.

void offset()
{
    contE = 0;
    int i;
    for (i = 0; i < 100; i++)
    {
        carrito[i] = 0;
        product[i] = 0;
    }
    for (i = 0; i < 6; i++)
    {
        cont[i] = 0;
        cant[i] = 0;
        precio[i] = 0;
        itbis[i] = 0;
    }
    for (i = 0; i < 2; i++)
    {
        flag[i] = 0;
    }  
}

void productA()
{
    cant[A]++;
    cont[A]++;
    precio[A] += 25;
    if (cant[A] == 2)
    {
        precio[A] -= 25;
        cont[A] = 0;
    }
}
void productB()
{
    cant[B]++;
    cont[B]++;
    precio[B] += 30;
    if (cont[B] == 2)
    {
        precio[B] -= (30/2);
        cont[B] = 0;
    }
}
void productC()
{
    cant[C]++;
    precio[C] += 35;
    flag[1] = 1;
    if (flag[1] == 1 && flag[0] == 1)
    {
        flag[1] = 0;
        flag[0] = 0;
        precio[B] -= (30 * 0.25);
    }
}
void productD()
{
    cant[D]++;
    precio[D] += 40;
    flag[0] = 1;
    if (flag[1] == 1 && flag[0] == 1)
    {
        flag[1] = 0;
        flag[0] = 0;
        precio[B] -= (30 * 0.25);
    }
}
void productE()
{
    cont[E]++;
    if (cont[E] <= 4 )
    {
    cant[E]++;
    precio[E]+=45;
    }
}
void productF()
{

    cant[F]++;
    precio[F] += 50;
    if (cont[E] >= 4)
    {
        cont[E] -= 4;
        cant[E]+=cont[E];
        precio[E] += 45;
    }
}
void ImprimirFactura()
{
    printf("\nESTA ES SU FACTURA\n");
    printf("CANT   PRODUCT    PRECIO    ITBIS        TOTAL\n");

    if (cant[A] > 0)
    {
        itbis[A] = (precio[A] * 0.18);
        printf("%i       A          %.2f      %.2f       %.2f\n", cant[A], precio[A], itbis[A], (precio[A] + itbis[A]));
}
if (cant[B] > 0)
{
    itbis[B] = (precio[B] * 0.18);
    printf("%i       B          %.2f      %.2f       %.2f\n", cant[B], precio[B], itbis[B], (precio[B] + itbis[B]));
}
if (cant[C] > 0)
{
    itbis[C] = (precio[C] * 0.18);
    printf("%i       C          %.2f      %.2f       %.2f\n", cant[C], precio[C], itbis[C], (precio[C] + itbis[C]));
}
if (cant[D] > 0)
{
    itbis[D] = (precio[D] * 0.18);
    printf("%i       D          %.2f      %.2f       %.2f\n", cant[D], precio[D], itbis[D], (precio[D] + itbis[D]));
}
if (cant[E] > 0)
{
    itbis[E] = (precio[E] * 0.18);
    printf("%i       E          %.2f      %.2f       %.2f\n", cant[E], precio[E], itbis[E], (precio[E] + itbis[E]));
}
if (cant[F] > 0)
{
    printf("%i       F          %.2f      0       %.2f\n", cant[F], precio[F], precio[F]);
}
printf("Monto Total: %.2f\n\n", ((precio[A] + itbis[A]) + (precio[B] + itbis[B]) + (precio[C] + itbis[C]) + (precio[D] + itbis[D]) + (precio[E] + itbis[E]) + (precio[F] + itbis[F])));
}
void DeterminarProduct()
{
    int i = 0;
    while (carrito[i] != 0) //Checks flag for end of valor (if end then exit)
    {
        switch (carrito[i])
        {
        case 'a':
            productA();
            break;
        case 'A':
            productA();
            break;
        case 'b':
            productB();
            break;
        case 'B':
            productB();
            break;
        case 'c':
            productC();
            break;
        case 'C':
            productC();
            break;
        case 'd':
            productD();
            break;
        case 'D':
            productD();
            break;
        case 'e':
            productE();
            break;
        case 'E':
            productE();
            break;
        case 'f':
            productF();
            break;
        case 'F':
            productF();
            break;
        default:
            printf("No tenemos de este producto %c\n", carrito[i]);
            break;
        }
        i++;
    }
}

int main()
{
    while (1)
    {
        offset();
        printf("Productos en disponibles: A B C D F E\nQue desea comprar?\n");
        scanf("%s", carrito);
        DeterminarProduct();
        ImprimirFactura();
    }
}