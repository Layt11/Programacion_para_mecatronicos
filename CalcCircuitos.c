#include <stdio.h>
#include <stdlib.h>
// Definiciones
#define is_a_number (Crt[i] > 47 && Crt[i] < 58 || Crt[i] == '.')
#define NoEsUnNumero (Crt[i] < 47 || Crt[i] < 58 && Crt[i] != '.')
#define paralelo (nodo[0] == nodo[2] && nodo[1] == nodo[3])
#define true 1
#define false 0
// Declaración de variables
// float Rt[2]; // Resistencia total o resultado. 0 = Serial - 1 = Paralelas. 
char Crt[30]; // Entrada del circuito.
float valor[2]; // Valores de los ciruitos. Valor[0] tambien es el valor a desplegar.
// Variables utiles
int i = 0; // para el vector de la entrada.
int n = 0; // Para el vector del nodo
int v = 0; // Para el vector del valor
int FinValor = false;
int pdecimal = false;
float corrido;
char nodo[4];

float concatenar(float num)
{
    if (pdecimal == true) // Cuando esta encendido concatena los valores como decimales
    {
        corrido = corrido * 0.1;
        num -= '0';                          //Convercion de char a entero
        valor[v] = ((num * corrido) + valor[v]); //Concatenarlo como un numero decimal
    }
    else if (num != 46) // Si es un numero entero pasa por este proceso.
    {
        num -= '0'; //Convercion de char a entero
        valor[v] = ((valor[v] * 10) + num);
    }
    else // Cuando recibe el punto enciende el Pdecimal.
    {
        pdecimal = 1;
    }
    corrido = 1.0; // Resetea el corrido para el siguiente numero.
}

// void Resistenciatotal()
// {
//     if (paralelo)
//     {
//         Rt[1] = 1 / ((1 / Rt[0]) + (1 / Rt[1]));
//     }
//     else
//     {
//         Rt[0] = Rt[0] + Rt[1];
//     }
// }

void Corrernodo(){ // Un simple offset para cuando entre el siguiente valor y sus nodos.
    nodo[0] = nodo[2];
    nodo[1] = nodo[3];
    nodo[2] = '\0';
    nodo[3] = '\0';
    n = 2;
    valor[1] = '\0';
    v = 0;
}

void CalcRt()
{
if (paralelo)
{
    valor[0] = 1 / ((1 / valor[0]) + (1 / valor[1]));
    Corrernodo();
}
else
{
    valor[0] = valor[0] + valor[1];
    Corrernodo();
}
}

void parser()
{
    // int f = 0;
    // for (f = 0; f < 30; f++) // Esta y las siguientes dos lineas funcionan como un offset para el parser
    //     Crt[f] = 0;
    i = 0;    
    FinValor = false; //Fin offset
    while (FinValor == false) //Checks flag for end of valor (if end then exit)
    {
        if (NoEsUnNumero && valor[0] != '\0' && nodo[2] != '\0')
        {
            v = 1;
        }                // DEBO ENCONTRAR DONDE PONER ESTO.
        if (is_a_number) //Si es un numero ira a concatenarlo.
        {
            concatenar(Crt[i]);
        }
        else if (Crt[i] == 'K' || Crt[i] == 'k')
        {
             valor[v] *= 1000;  
        }
        else if (Crt[i] == '\0')
        {
            FinValor = true;
            // Resistenciatotal();
            if (valor[0] >= 1000)
                valor[0] = valor[0] / 1000;
        }
        else
        {
           nodo[n] = Crt[i];
           n++;
           if (nodo[3] != '\0') //Si el ultimo nodo tiene valor entonces opera la formula.
           {
               CalcRt();
           }
        }
        i++;
    }
}

int main()
{
    printf("*****Ingrese el circuito*****\n\n");
    while (1)
    {
        scanf("%s", Crt);
        parser();
        printf("Rt = %.2fK\n", valor[0]);
        valor[0];
    }
return 0;
}