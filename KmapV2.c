#include <stdio.h>
#include <string.h>
#include <math.h>

// Definiciones
#define EsUnNumero (num > 47 && num < 58)
#define DesplazarFilas  \
    fil = 1;            \
    fil <= (MAXFilCol[0]); \
    fil++
#define DesplazarColumnas \
    col = 1;              \
    col <= (MAXFilCol[1]);   \
    col++
#define true 1
#define false 0
#define SOP 1
#define POS 0
#define PrimeraFila Valor == 0 || Valor == 1 || Valor == 3 || Valor == 2
#define SegundaFila Valor == 4 || Valor == 5 || Valor == 7 || Valor == 6
#define TerceraFila Valor == 12 || Valor == 13 || Valor == 15 || Valor == 14
#define CuartaFila Valor == 8 || Valor == 9 || Valor == 11 || Valor == 10

// Variables
// Para el mapa
int Kmap[5][5];
int col = 0; //Guarda el numero de la columna en el mapa
int fil = 0; //Guarda el numero de la fila en el mapa
int NumVariables = 0; // Contador de las variables necesarias para el sistema.
int MAXFilCol[2]; // Determina el max de filas y columnas en funcion del numero de variables 0 = fil y 1= col
int g = 3;        // Para variar entre fil y col
int TipoSolucion;
int Valor = 0; // Guarda la posicion cuando es 1.
char Variables[4];
// Parser
char Entrada[50]; //Recibe las entradas.
int i = 0;        // Esta y las siguientes dos lineas funcionan como un offset para el parser
int EntreParentesisChk = true;
int SignoIgualChk = false; //flag de "="
int AvisoExcedidoChk = false; // Por si el usuario se excede ingresando variables, solo lo mencione una vez.
int f; // Para los for.

void Offset()
{
    g = 3;
    i = 0;
    EntreParentesisChk = true;
    AvisoExcedidoChk = false;
    NumVariables = 0;
    int q;
    for (f = 0; f < 30; f++)
        Entrada[f] = 0;
    for (f = 0; f < 4; f++)
        Variables[f] = 0;
    for (f = 0; f < 2; f++)
        MAXFilCol[f] = 0;
    for (f = 0; f < 6; f++)
        for (q = 0; q < 6; q++)
            Kmap[f][q] = 0;
}


void UbicarPosicion() // Establece donde debe ir un 1 antes de cambiar de valor
{
    switch (Valor)
    {
    // 1ra columna
    case 0:
    case 4:
    case 12:
    case 8:
        col = 1;
        break;
    // 2ra columna
    case 1:
    case 5:
    case 13:
    case 9:
        col = 2;
        break;
    // 3ra columna
    case 3:
    case 7:
    case 15:
    case 11:
        col = 3;
        if (NumVariables == 2)
            col = 2;
        break;
    // 4ra columna
    case 2:
    case 6:
    case 14:
    case 10:
        col = 4;
        if (NumVariables == 2)
            col = 1;
        break;
    }
    // Ubicar las filas
    if (PrimeraFila)
    {
        fil = 1;
        if (NumVariables == 2 && (Valor == 2 || Valor == 3))
            fil = 2;
    }
    else if (SegundaFila)
        fil = 2;
    else if (TerceraFila)
        fil = 3;
    else if (CuartaFila)
        fil = 4;
}

int EvaluarCaracter(int num) // Evalua si el caracter es una letra o un numero.
{
    if (EsUnNumero && SignoIgualChk == true && EntreParentesisChk == true) // Si es un numero lo convierte a entero y si es necesario lo concatena.
    {
        num -= '0'; //Convercion de char a entero
        Valor = ((Valor * 10) + num);
    }
    else if (EntreParentesisChk == true && SignoIgualChk == false)
    {
        if (NumVariables < 4)
        {
            NumVariables++; // Va acumulando la cantidad de variables para el sistema.
            Variables[(NumVariables - 1)] = Entrada[i];
            if (g == true) // Para alternar los maximos de filas y columnas
                g = false;
            else
                g = true;
            MAXFilCol[g] += 2;
        }
        else
        {
            if (AvisoExcedidoChk == false)
            {
                AvisoExcedidoChk = true;
                printf("Lo sentimos, ese Kmap solo trabaja con sistemas de 2, 4 variables o menos.\n");
            }
            
        }
    }
}
void EstablecerPosicion()
{
    UbicarPosicion();
    Kmap[fil][col] = 1;
    Valor = 0;
}

void parser()
{
    SignoIgualChk = false; // Sirve como offset.
    int FinEntradaChk = false; //flag del final de la entrada
    while (FinEntradaChk == false) //Checks flag for end of valor (if end then exit)
    {
        switch (Entrada[i]) //Evalua lo que ha sido ingresado caracter por caracter.
        {
        case '(':
            EntreParentesisChk = true;
            break;
        case ')':
            EntreParentesisChk = false;
            if (SignoIgualChk == true)
            {
                EstablecerPosicion();
                FinEntradaChk = true;
            }
            break;
        case '=':
            SignoIgualChk = true;
            break;
        case ',':
            if (SignoIgualChk == true && EntreParentesisChk == true)
                EstablecerPosicion();
            break;
        default:
            EvaluarCaracter(Entrada[i]);
            break;
        }
        i++;
    }
}

void PrintMapa()
{
    fil = 1;
    col = 1;
    printf("\n\t");
    for (DesplazarColumnas)
    {
        switch (NumVariables)
        {
        case 2:
            if (col == 1) // Primera variable de las columnas
                printf("%c'   ", Variables[0]);
            else
                printf("%c", Variables[0]);
            break;
        case 3:
        case 4:
            if (col <= 2) // Primera variable de las columnas
                printf("%c'", Variables[0]);
            else
                printf("%c", Variables[0]);
            // Segunda variable de las columnas
            if (col == 1 || col == 4)
                printf("%c' ", Variables[1]);
            else
                printf("%c ", Variables[1]);
            break;
        }
    }
    printf("\n");
    switch (NumVariables) // Para desplegar el primer conjunto de las filas
    {
    case 2:
        // Primera variable de las filas
        printf("%c'\t|", Variables[1]);
        break;
    case 3:
        // Primera variable de las filas
        printf("%c'\t|", Variables[2]);
        break;
    case 4:
        // Primera variable de las filas
        printf("%c'", Variables[2]);
        // Segunda variable de las filas
        printf("%c'\t|", Variables[3]);
        break;
    }
    while (fil < (MAXFilCol[0]+1))
    {
        for (DesplazarColumnas)
        {
            if (Kmap[fil][col] == 1)
            {
                if (TipoSolucion == SOP)
                    printf("1  |");
                else
                    printf("0  |");
            }
            else
            {
                if (TipoSolucion == POS)
                    printf("1  |");
                else
                    printf("0  |");
            }
        }
        fil++;
        col = 0;
        printf("\n");
        if (fil <= (MAXFilCol[0]))
        {
            switch (NumVariables)
            {
            case 2:
                // Primera variable de las filas
                printf("%c \t|", Variables[1]);
                break;
            case 3:
                // Primera variable de las filas
                printf("%c \t|", Variables[2]);
                break;
            case 4:
                // Primera variable de las filas
                if (fil <= 2)
                    printf("%c'", Variables[2]);
                else
                    printf("%c", Variables[2]);
                // Segunda variable de las filas
                if (fil == 1 || fil == 4)
                    printf("%c'\t|", Variables[3]);
                else
                    printf("%c \t|", Variables[3]);
                break;
            }
        }
    }
}

int main()
{
    printf("\t******************************\n");
    printf("\t*****Diagrama de Karnaugh*****\n");
    printf("\t******************************\n");
    while (1)
    {
        int TipoSolucionChk = false;
        // Interfaz
        printf("\n\t*****Tipo de solucion******\n");
        printf("Para suma de productos ingrese: 'SOP' o 'POS' para producto de sumas: ");
        while (TipoSolucionChk == false)
        {
            char TipoSolucionEntrada[3];
            scanf("%s", TipoSolucionEntrada);
            TipoSolucionChk = false;
            if ((strcmp(TipoSolucionEntrada, "SOP") == 0) || (strcmp(TipoSolucionEntrada, "Sop") == 0) || (strcmp(TipoSolucionEntrada, "sop") == 0))
            {
                TipoSolucion = SOP;
                TipoSolucionChk = true;
            }
            else if ((strcmp(TipoSolucionEntrada, "POS") == 0) || (strcmp(TipoSolucionEntrada, "Pos") == 0) || (strcmp(TipoSolucionEntrada, "pos") == 0))
            {
                TipoSolucion = POS;
                TipoSolucionChk = true;
            }
            else
            {
                printf("Este no es un tipo de solucion valido, por favor reintente: ");
            }
        }
        printf("\nIntroduzca su ecuacion como 'f([Variables] = E([Posiciones donde el valor es verdad])'\nEjemplo: f(a,b,c,d) = E(0,1,3,6,12)\n\n");
        printf("f(");
        fflush(stdin);
        scanf("%[^\n]", Entrada);
        parser();
        PrintMapa();
        printf("\n");
        Offset();
    }
}