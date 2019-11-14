#include <stdio.h>
#include <conio.h>
#include <math.h>
// Definiciones
#define is_a_number (coordenates[i] > 47 && coordenates[i] < 58 || coordenates[i] == '.')
#define false 0
#define true 1
#define pcardinaly 0 // Punto cardinal en Y
#define pcardinalx 1 // punto cardinal en X
// #define ocardinaly 2 // El orden cardinal en Y
// #define ocardinalx 3 // orden cardinal en X
#define m 0  // Magnitud
#define a 1 // Angulo
#define x1 0 
#define y1 1
#define x2 2
#define y2 3

// Variables
char coordenates[100]; // La entrada de datos
char dir[4]; // Tiene cuatro posiciones, las dos primeras posiciones guardan el punto cardinal, las ultimas dos guardan el orden de los puntos cardinales.
float components[2]; // Guarda los componentes del vector
float number[4];
// Contadores
int c = 0; // Posicion del valor en el vector 'arreglo'
int j = 0; // Para saber si solo se entro una coordenada.
int flagnegativo = false; // Para saber si es un numero negativo.
// Concatenar
int pdecimal = false;
float corrido = 0.0;

void offset()
{
    int i;
    for (i = 0; i < 100; i++)
    {
        coordenates[i] = 0;
        if (i < 4)
        {
            dir[i] = 0;
            number[i] = 0;
            if (i < 2)
            {
                
                components[i] = 0;
            }
        }    
    }
    c = 0;
    j = 0;
}
void magnitud()
{
    components[m] = sqrt((pow((number[x1] - number[x2]), 2)) + (pow((number[y1] - number[y2]), 2)));
}
void evalX()
{
    if (number[x1] > number[x2])
    {
        dir[pcardinalx] = 'O';
    }
    else if (number[x1] == 0 && number[x2] == 0) // Es por si no tiene ninguna pendiente, osea, es solo horizontal.
    {
        dir[pcardinalx] = ' ';
    }
    else if (number[x2] > number[x1])
    {
        dir[pcardinalx] = 'E';
    }
}
void direccion()
{
    if (number[y1] == 0 && number[y2] ==0) // Es por si no tiene ninguna pendiente, osea, es solo horizontal.
    {
        dir[pcardinaly] = ' ';
        evalX(); 
    }
    else if (number[y1] > number[y2])
    {
        dir[pcardinaly] = 'S';
        evalX();
    }
    else  
    {
        dir[pcardinaly] = 'N';
        evalX();
    }
}
void angulo()
{
    components[a] = ((fabs(number[x1] - number[x2])) / (fabs(number[y1] - number[y2])));
    components[a] = (atan(components[a]) * (180.0/3.14159)); // La ultima parte convierte de grados a radianes.
}

float concatenar(float num)
{
    
    if (pdecimal == true) // Cuando esta encendido concatena los valores como decimales
    {
        corrido = corrido * 0.10;
        num -= '0';                              //Convercion de char a entero
        number[c] = ((num * corrido) + number[c]); //Concatenarlo como un numero decimal
    }
    else if (num != 46) // Si es un numero entero pasa por este proceso.
    {
        num -= '0'; //Convercion de char a entero
        number[c] = ((number[c] * 10) + num);
    }
    else // Cuando recibe el punto enciende el Pdecimal.
    {
        pdecimal = 1;
    }
    corrido = 1.0; // Resetea el corrido para el siguiente numero.
}

void cargarcoordenadas() // Para recibir la formula y el useresult
{
    int i = 0;
    while (coordenates[i] != '\0')
    {
        if (is_a_number)
        {
            concatenar(coordenates[i]);
        }
        else if (coordenates[i] == ',' || coordenates[i] == ')')
        {
            j++;
            pdecimal = 0;
            if (flagnegativo == true)
            {
                number[c] *= -1.0;
                flagnegativo = false;
            }
            c++;
        }
        else if (coordenates[i] == '(')
        {
            j++;
        }
        else if (coordenates[i] == '-')
        {
         flagnegativo = true;
        }
        else
        {
            printf("Por favor, verifique su entrada y marque de nuevo");
            coordenates[i] = '\0';
        }
        i++;
    }
    if (j < 6)
    {
        number[x2] = number[x1];
        number[y2] = number[y1];
        number[y1] = 0;
        number[x1] = 0; 
    } 
}
void DesplegarResultado()
{
    if (dir[pcardinaly] == 'N')
    {
        if (dir[pcardinalx] == 'E')
        {
            printf("El vector resultante es: %.2f %c %.2f* %c\n\n", components[m], dir[pcardinalx], components[a], dir[pcardinaly]);
        }
        else
        {
            printf("El vector resultante es: %.2f %c %.2f* %c\n\n", components[m], dir[pcardinaly], components[a], dir[pcardinalx]);
        }
    }
    else
    {
        if (dir[pcardinalx] == 'O')
        {
            printf("El vector resultante es: %.2f %c %.2f* %c\n\n", components[m], dir[pcardinalx], components[a], dir[pcardinaly]);
        }
        else
        {
            printf("El vector resultante es: %.2f %c %.2f* %c\n\n", components[m], dir[pcardinaly], components[a], dir[pcardinalx]);
        }
    } 
}

int main()
{
    while (1)
    {
        printf("Para introducir coordenadas debe seguir este formato\n(x1,y1)(x2,y2) y si decide solo introducir una coordenada, se considerara el origen como primera coordenada\n\n");
        scanf("%s", coordenates);
        cargarcoordenadas();
        magnitud();
        direccion();
        angulo();
        DesplegarResultado();
        offset();
    }
}