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
int Vbbchk;      
float Re;    
int Rechk = false;
float Vin;      
int Vinchk= false;
float Vout; 
int Voutchk = false;
float Vc;      
int Vcchk;     
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
//Utiles
float result;     // Almacena el resultado para despues desplegarlo
char entrada[30]; // Para recibir la entrada.
char resp;        // Para recibir la respuesta.
char name1;     //Variable para guardar el nombre del componente.
int number;     //Varible use to concatenate
int pdecimal = 0;
int corrido;
int fila_o_columna = 0; //flag for dermine if is a fila or column
int flag_igual_en_contrado = false; //flag of "=" find
int end_of_valor = false;          //flag of end of valor

void clearvariables() {
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
}

void Asignarnombre(){
    switch (name1)
    {
    case 'clear':
       clearvariables()
        break;
    case 'Vc':
        Vc = number; // Mete el valor introducido en la variable correspondiente.
        Vcchk = true; // Activa la variable como 'Ya ha sido introducida'.
        break;
    case 'vc':
        Vc = number;
        Vcchk = true;
        break;
    case 'Vb':
        Vb = number;
        Vbchk = true;
        break;
    case 'Ve':
        Ve = number;
        Vechk = true;
        break;
    case 'Ic':
        Ic = number;
        Icchk = true;
        break;
    case 'ic':
        Ic = number;
        Icchk = true;
        break;
    case 'Vbb':
        Vbb = number;
        Vbbchk = true;
        break;
    case 'Re':
        Re = number;
        Rechk = true;
        break;
    case 'Vin':
        Vin = number;
        Vinchk = true;
        break;
    case 'Vout':
        Vout = number;
        Voutchk = true;
        break;
    case 'Vc':
        Vc = number;
        Vcchk = true;
        break;
    case 'R1':
        R1 = number;
        R1chk = true;
        break;
    case 'R2':
        R2 = number;
        R2chk = true;
        break;
    case 'RL':
        RL = number;
        RLchk = true;
        break;
    case 'RC':
        Rc = number;
        Rcchk = true;
        break;
    case 'C1':
        C1 = number;
        C1chk = true;
        break;
    case 'C1':
        C2 = number;
        C2chk = true;
        break;
    case 'Ie':
        Ie = number;
        Iechk = true;
        break;
    default:
        printf ("El valor ingresado no es reconocido")
        break;
    }
} 

void evaluarbuscado(){
    switch (name1)
    {
    case 'Vc':
        if (Vbbchk == true) { //Evalua si los valores necesarios para encontrar a Vc han sido agregados
            if (Icchk == true){
                if (Rcchk == true)
                {
                    result = Vbb - (Ic*Rc); // Como todos los datos han sido agregados, hace la operacion
                    printf ("El valor de Vc es: %.2f", result);
                }
                else
                {
                    printf("Falta el valor de Ic");
                }
            }
            else {
                printf("Falta el valor de Ic"); // Si un valor no ha sido introducido, le dice al usuario que este valor falta
            }
        }
        else {
            printf ("Falta el valor de Vbb");
        }
        break;
    case 'Vb':
        if (Vechk == true){
            result= Ve + 0.6;
        }
        else 
        printf("Falta Ve");
        break;
    case 'Ve':
        if (Vbchk == true)
        {
            result = 0.6 - Ve;
        }
        else
            printf("Falta Vb");
        break;
    case 'Ic':
        
        break;
    case 'Vbb':

        break;
    case 'Re':

        break;
    case 'Vin':

        break;
    case 'Vout':

        break;
    case 'R1':
        if (R2chk == true)
        {
            if (Vbbchk == true)
            {
                if (Icchk == true)
                {
                    result = (Vbb / (10 * Ic / 100)) - R2;
                    printf("El valor de R1 es: %.2f", result);
                }
                else
                {
                    printf("Falta el valor de Ic");
                }
            }
            else
            {
                printf("Falta el valor de Vbb");
            }
        }
        else
        {
            printf("Falta el valor de R2");
        }
        break;
    case 'R2':
        if (R1chk == true)
        {
            if (Vbbchk == true)
            {
                    if (Icchk == true)
                    {
                        result = (Vbb / (10 * Ic / 100)) - R1;
                        printf("El valor de R2 es: %.2f", result);
                    }
                    else
                    {
                        printf("Falta el valor de Ic");
                    }
            }
            else
            {
                printf("Falta el valor de Vbb");
            }
            
        }
        else {
            printf ("Falta el valor de R1");
        }
        break;
    case 'RC':
        //No tengo la ecuacion
        break;
    case 'C1':
        //No tengo la ecuacion
        break;
    case 'C1':
        //No tengo la ecuacion
        break;
    case 'Ie':
        if (Icchk == true )
        {
            if (Ibchk == true)
            {
                result = (Ic + Ib);
                printf("El valor de Ie es: %.2f", result);
            }
            else
            {
                printf("Falta el valor de Ib");
            }
        }
        else
        {
            printf("Falta el valor de Ic");
        }
        break;
    default:
        break;
    }
}
/* Verified if the input is a number*/
int check_if_a_number(char num)
{
    if (is_a_number)
    concatenar(num);
}

float concatenar(float num)
{
    if (pdecimal == 1) // Cuando esta encendido concatena los valores como decimales
    {
        corrido = corrido * 0.1;
        num -= '0';                         //Convercion de char a entero
        return ((num * corrido) + number); //Concatenarlo como un numero decimal
    }
    else if (num != 46) // Si es un numero entero pasa por este proceso.
    {
        num -= '0'; //Convercion de char a entero
        return ((number * 10) + num);
    }
    else // Cuando recibe el punto enciende el Pdecimal.
    pdecimal = 1;
    corrido = 1.0; // Resetea el corrido para el siguiente numero.
    num = num1[n]; // Para que no haga un tollo, porque lo hace.
}

void parser(char entrada[])
{
    int i;

    while (end_of_valor == false) //Check flag for en of matrix if end exit
    {
        if (flag_igual_en_contrado == false) //if sing of '=' is found flag go true and don't execute
        {
            while (entrada[i] != '=') //Look for sing of '='
            {
                strcat(name1, entrada[i]); //Guarda el nombre de lo ingresado.
                i++;
            }
            i++;
            flag_igual_en_contrado = true;
        }
        i++;

        switch (entrada[i]) //look in array if we have "[k,mA] defult look if a number"
        {
        case 'K':
            // number *= 1000;
        case 'k':
            // number *= 1000;
        case 'm':
        case 'A':
            // number = number/100;
            break;
        case '?':
            resp = 'N';
            evaluarbuscado();
            break;
        default:
            check_if_a_number(entrada[i]);
            break;
        }
    }
}
int main(int argc, char const *argv[])
{
    printf("Introdusca el valor\n");
    while (resp != 'N'){
        scanf("%s", entrada);
        parser(entrada);
        Asignarnombre();
    }
    return 0;
}