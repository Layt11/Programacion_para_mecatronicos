#include <stdio.h>
#include <conio.h>
#include <string.h>
// Definiciones
#define is_a_number (num > 47 && num < 58 || num == '.')
#define true 1
#define false 0
// Declaracion de variables
float Vb; 
int Vbchk = false;
float Ve;
int Vechk = false;
float Vbb;
int Vbbchk = false;
float Re;    
int Rechk = false;
float Vin;      
int Vinchk= false;
float Vout; 
int Voutchk = false;
float Vc;
int Vcchk = false;
float Ic;      
int Icchk = false;
float R1;       
int R1chk = false;
float C1;
int C1chk = false;
float C2;
int C2chk = false;
float RL;
int RLchk = false;
float R2; 
int R2chk = false;
float Rc;
int Rcchk = false;
float Ie;
int Iechk = false;
float Ib;
int Ibchk = false;
float Vg;
//Variables utiles
float result;     // Almacena el resultado para despues desplegarlo
char entrada[30]; // Para recibir la entrada.
char name[30];        //Variable para guardar el nombre del componente.
char resp;        // Para recibir la respuesta.
int number;     //Varible use to concatenate
int pdecimal = 0;
int corrido;
int flag_igual_encontrado = false; //flag of "=" find
float formula[3]; // Este vector numera las variables que ya hay para usar una formula o no.
int end_of_valor = false;          //flag of end of valor

int clearvariables(f) 
{
    Vb = 0;
    Ve =0;
    Vbb = 0;
    Re = 0;
    Vin = 0;
    Vout = 0;
    Vc = 0;
    Ic = 0;
    R1 = 0;
    C1 = 0;
    C2 = 0;
    RL = 0;
    R2 = 0;
    Rc = 0;
    Ie = 0;
    Ib = 0;
    Vg = 0;
    for (f = 0; f < 3; f++)
        formula[f] = 0;
}

void analiceVb()
{
    while (Vbchk == false) //Evalua si los valores necesarios para encontrar a Ve han sido agregados
    {
        // Si un valor no ha sido introducido, le dice al usuario que este valor falta
        printf("El valor de 'Vb' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceIe(){
    while (Iechk == false)
    {
        printf("El valor de 'Ie' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceIc()
{
    while (Icchk == false)
    {
        printf("El valor de 'Ic' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceIb()
{
    while (Ibchk == false)
    {
        printf("El valor de 'Ib' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceVout()
{
    while (Voutchk == false)
    {
        printf("El valor de 'Vout' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceRc()
{
    while (Rcchk == false)
    {
        printf("El valor de 'Rc' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceVbb()
{
    while (Vbbchk == false)
    {
        printf("El valor de 'Vbb' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceVc()
{
    while (Vcchk == false)
    {
        printf("El valor de 'Vc' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceRe()
{
    while (Rechk == false)
    {
        printf("El valor de 'Re' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceR1()
{
    while (R1chk == false)
    {
        printf("El valor de 'R1' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceR2()
{
    while (R2chk == false)
    {
        printf("El valor de 'R2' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceVe()
{
    while (Vechk == false)
    {
        printf("El valor de Vb es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void DesplegarIc() // Esto lo convirte en mA de nuevo y lo despliega
{ 
    result *= 100;
    printf("Ic = %.2fmA\n", result);
}

float concatenar(float num)
{
    if (pdecimal == 1) // Cuando esta encendido concatena los valores como decimales
    {
        corrido = corrido * 0.1;
        num -= '0';                          //Convercion de char a entero
        number = ((num * corrido) + number); //Concatenarlo como un numero decimal
    }
    else if (num != 46) // Si es un numero entero pasa por este proceso.
    {
        num -= '0'; //Convercion de char a entero
        number = ((number * 10) + num);
    }
    else // Cuando recibe el punto enciende el Pdecimal.
    {
        pdecimal = 1;
    }
    corrido = 1.0; // Resetea el corrido para el siguiente numero.
}

void Asignarnombre(){

    if ((strcmp(name, "Vc") == 0) || (strcmp(name, "vc") == 0))
    {
        Vc = number;  // Mete el valor introducido en la variable correspondiente.
        Vcchk = true; // Activa la variable como 'Ya ha sido introducida'.
        formula[1] = formula[1] + 1; // aumenta el conteo de variables para esa formula. UNA VARIABLE PUEDE ESTAR EN DOS FORMULAS
    }
    else if ((strcmp(name, "Vb") == 0) || (strcmp(name, "vb") == 0))
    {
        Vb = number;  
        Vbchk = true; 
    }
    else if ((strcmp(name, "Ve") == 0) || (strcmp(name, "ve") == 0))
    {
        Ve = number;
        Vechk = true;
    }
    else if ((strcmp(name, "Ic") == 0) || (strcmp(name, "ic") == 0))
    {
        Ic = number;
        Icchk = true;
        formula[2] = formula[2] + 1.5;
        formula[1] = formula[1] + 1;
    }
    else if ((strcmp(name, "Vbb") == 0) || (strcmp(name, "vbb") == 0))
    {
        Vbb = number;
        Vbbchk = true;
        formula[1] = formula[1] + 1;
    }
    else if ((strcmp(name, "Re") == 0) || (strcmp(name, "re") == 0))
    {
        Re = number;
        Rechk = true;
    }
    else if ((strcmp(name, "Vin") == 0) || (strcmp(name, "vin") == 0))
    {
        Vin = number;
        Vinchk = true;
    }
    else if ((strcmp(name, "Vout") == 0) || (strcmp(name, "vout") == 0))
    {
        Vout = number;
        Voutchk = true;
        formula[2] = formula[2] + 1.5;
    }
    else if ((strcmp(name, "R1") == 0) || (strcmp(name, "r1") == 0))
    {
        R1 = number;
        R1chk = true;
    }
    else if ((strcmp(name, "R2") == 0) || (strcmp(name, "r2") == 0))
    {
        R2 = number;
        R2chk = true;
    }
    else if ((strcmp(name, "RL") == 0) || (strcmp(name, "rl") == 0))
    {
        RL = number;
        RLchk = true;
    }
    else if ((strcmp(name, "Rc") == 0) || (strcmp(name, "rc") == 0))
    {
        Rc = number;
        Rcchk = true;
        formula[2] = formula[2] + 1.5; // Como la formula 3 tiene 3 variables debe contarlas por 1.5
        formula[1] = formula[1] + 1; // Como la formula 2 tiene 2 variables debe contarlas por 1
    }
    else if ((strcmp(name, "C1") == 0) || (strcmp(name, "c1") == 0))
    {
        C1 = number;
        C1chk = true;
    }
    else if ((strcmp(name, "Ie") == 0) || (strcmp(name, "ie") == 0))
    {
        Ie = number;
        Iechk = true;
        formula[0] = formula[0] + 1.5;
    }
    else if ((strcmp(name, "Ib") == 0) || (strcmp(name, "ib") == 0))
    {
        Ib = number;
        Ibchk = true;
        formula[0] = formula[0] + 1.5;
    }
    else
    {
        printf("El valor ingresado no es reconocido");
    }  
} 

void evaluarbuscado(){

    if ((strcmp(name, "Ve") == 0) || (strcmp(name, "ve") == 0))
    {
        analiceVb();
        result = Vb - 0.6; // Como todos los datos han sido agregados, hace la operacion
        printf("Ve = %.2f\n", result);
    }
    else if ((strcmp(name, "Vb") == 0) || (strcmp(name, "vb") == 0))
    {
        analiceVe();
        result = Ve + 0.6;
        printf("Vb = %.2f\n", result);
    }
    else if ((strcmp(name, "Vc") == 0) || (strcmp(name, "vc") == 0))
    {
        analiceVbb();
        analiceRc();
        analiceIc();
        result = Vbb - (Ic * Rc);
        printf("Vc = %.2f\n", result);
    }
    else if ((strcmp(name, "R1") == 0) || (strcmp(name, "r1") == 0))
    {
        analiceR2();
        analiceVbb();
        analiceIc();
        result = (Vbb / (10 * Ic / 100)) - R2;
        printf("R1 = %.2f\n", result);
    }
    else if ((strcmp(name, "R2") == 0) || (strcmp(name, "r2") == 0))
    {
        analiceVbb();
        analiceR1();
        analiceIc();
        result = (Vbb / (10 * Ic / 100)) - R1;
        printf("R2 = %.2f\n", result);
    }
    else if ((strcmp(name, "Ie") == 0) || (strcmp(name, "ie") == 0))
    {
        analiceIb();
        analiceIc();
        result = (Ic + Ib);
        printf("Ie = %.2f\n", result);
    }
    else if ((strcmp(name, "Ic") == 0) || (strcmp(name, "ic") == 0))
    {
        if ((formula[0] > formula[1]) && formula[0] > formula[2])
        {
            analiceIe();
            analiceIb();
            result = (Ie - Ib);
            DesplegarIc();
        }
        else if (formula[1] > formula[2])
        {
            analiceVbb();
            analiceVc();
            analiceRc();
            result = ((Vbb - Vc) / Rc);
            DesplegarIc();
        }
        else if (formula[2] > formula[1])
        {
            analiceVout();
            analiceRc();
            result = (Vout / Rc);
            DesplegarIc();
        }
        else
        {
            analiceIe();
            analiceIb();
            result = (Ie - Ib);
            DesplegarIc();
        }           
    }
    else if ((strcmp(name, "Ib") == 0) || (strcmp(name, "ib") == 0))
    {
        analiceIe();
        analiceIc();
        result = (Ie - Ic);
        printf("Ib = %.2f\n", result);
    }
    else if ((strcmp(name, "Vbb") == 0) || (strcmp(name, "vbb") == 0))
    {
        analiceVc();
        analiceIc();
        analiceRc();
        result = Vc + (Ic*Rc);
        printf("Vbb = %.2f\n", result);
    }
    else if ((strcmp(name, "Rc") == 0) || (strcmp(name, "rc") == 0))
    {
        if (formula[1] > formula[2])
        {
            analiceVc();
            analiceIc();
            analiceVbb();
            result = (Vbb - Vc) / Ic;
            printf("Rc = %.2f\n", result);
        }
        else if (formula[2] > formula[1])
        {
            analiceVout();
            analiceIc();
            result = (Vout / Ic);
            printf("Rc = %.2f\n", result);
        }
        else
        {
            analiceVout();
            analiceIc();
            result = (Vout / Ic);
            printf("Rc = %.2f\n", result);
        }       
    }
    else if ((strcmp(name, "Vg") == 0) || (strcmp(name, "vg") == 0))
    {
        analiceRc();
        analiceRe();
        result = (-Rc / Re);
        printf("Ganacia de voltaje = %.2f\n", result);
    }
    else if ((strcmp(name, "Vout") == 0) || (strcmp(name, "vout") == 0))
    {
        analiceIc();
        analiceRc();
        result = (Ic * Rc);
        printf("Vout = %.2f\n", result);
    }
    // else if ((strcmp(name, "Re") == 0) || (strcmp(name, "re") == 0))
    // {
    //     //No tengo la ecuacion
    // }
    // else if ((strcmp(name, "Vin") == 0) || (strcmp(name, "vin") == 0))
    // {
    //     //No tengo la ecuacion
    // }
    // else if ((strcmp(name, "C1") == 0) || (strcmp(name, "c1") == 0))
    // {
    //     //No tengo la ecuacion
    // }
}
/* Verifies if the input is a number*/
int check_if_a_number(char num)
{
    if (is_a_number)
    concatenar(num);
}
void parser(f)
{
    for (f = 0; f < 30; f++)
        name[f] = 0;
    int i=0; // Esta y las siguientes dos lineas funcionan como un offset para el parser
    number = 0;
    end_of_valor= false; 
    flag_igual_encontrado = false;
    while (end_of_valor == false) //Checks flag for end of valor (if end then exit)
    {
        if (flag_igual_encontrado == false) //if sing of '=' is found flag go true and don't execute
        {
            while (entrada[i] != '=') //Look for sing of '='
            {
                name[i] = entrada[i]; //Guarda el nombre de lo ingresado.
                i++;
            }
            flag_igual_encontrado = true;
        }
        i++;
        switch (entrada[i]) //look in array if we have "[k,mA] defult look if a number"
        {
        case 'K':
        case 'k':
            number *= 1000;
            break;
        case ' ':
            break;
        case 'm':
            break;
        case 'A':
            number = number/100;
            break;
        case '?':
            evaluarbuscado();
            end_of_valor = true;
            break;
        case '\0':
            end_of_valor = true;
            break;
        default:
            check_if_a_number(entrada[i]);
            break;
        }
    }
    Asignarnombre();
}
int main(int argc, char const *argv[])
{
    printf("Introduzca el valor\n");
    while (resp != 'N')
    {
        scanf("%s", entrada);
        if ((strcmp(entrada, "clear") == 0) || (strcmp(name, "Clear") == 0))
        {
            clearvariables(); //Limpia todas las variables
        }
        else
        {
            parser(entrada);
        }        
    }
    return 0;
}