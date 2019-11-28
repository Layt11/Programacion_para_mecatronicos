#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

// Definiciones
#define is_a_number (num > 47 && num < 58 || num == '.' || num == '-')
#define true 1
#define false 0
#define real 0
#define imaginaria 1

// Declaracion de variables
float Angulo;
int Angulochk = false;
float W;
int Wchk = false;
float C;
int Cchk = false;
float J;
int Jchk = false;
float L;
int Lchk = false;
float f;
int fchk = false;
float V;
int Vchk = false;
float VL;
int VLchk = false;
float VR;
int VRchk = false;
float Vc;
int Vcchk = false;
float PL;
int PLchk = false;
float PR;
int PRchk = false;
float PC;
int PCchk = false;
float QL;
int QLchk = false;
float QR;
int QRchk = false;
float QC;
int QCchk = false;
float ZT;
int ZTchk = false;
float Z;
int Zchk = false;
float I;
int Ichk = false;
float CosP;
int CosPchk = false;
float XL;
int XLchk = false;
float XC;
int XCchk = false;
float S;
int Schk = false;
float P;
int Pchk = false;
float Q;
int Qchk = false;
float R;
int Rchk = false;
int pztchk = false;
//Variables utiles
float result;     // Almacena el resultado para despues desplegarlo
char entrada[30]; // Para recibir la entrada.
char name[30];    //Variable para guardar el nombre del componente.
float number;     //Varible use to concatenate
int pdecimal = 0;
float corrido;
int flag_igual_encontrado = false; //flag of "=" find

// Estos vectores numeran las variables que ya hay para usar una formula o no.
int pZt[2]; // Las partes de zt; 0 = Real y 1 = Imaginario.
int Zformula[2];
float CosPformula[2];
float XLformula[2];
//-------------------//
int end_of_valor = false; //flag of end of valor
int snegativo = false;
int pluschk = false; // Para notar cuando se divide Zt

int clearvariables()
{
    int o;
    C = 0;
    f = 0;
    R = 0;
    ZT = 0;
    Z = 0;
    V = 0;
    VL = 0;
    VR = 0;
    Vc = 0;
    I = 0;
    PC = 0;
    PR = 0;
    PL = 0;
    QL = 0;
    QR = 0;
    QC = 0;
    XL = 0;
    XC = 0;
    S = 0;
    P = 0;
    Q = 0;
    CosP = 0;
    Angulochk = false;
    W = 0;
    Wchk = false;
    Cchk = false;
    J = 0;
    Jchk = false;
    L =0;
    pluschk = false;
    Lchk = false;
    fchk = false;
    Vchk = false;
    VLchk = false;
    VRchk = false;
    Vcchk = false;
    PLchk = false;
    PRchk = false;
    PCchk = false;
    QLchk = false;
    QRchk = false;
    QCchk = false;
    ZTchk = false;
    Zchk = false;
    Ichk = false;
    CosPchk = false;
    XLchk = false;
    XCchk = false;
    Schk = false;
    Pchk = false;
    pztchk = false;
    Q = 0;
    Qchk = false;
    R = 0;
    Rchk = false;
    for (o = 0; o < 2; o++)
    {
        pZt[o];
        Zformula[o];
        CosPformula[o];
        XLformula[o];
    }
}

void analiceZT()
{
    while (ZTchk == false) //Evalua si los valores necesarios para encontrar a Ve han sido agregados
    {
        // Si un valor no ha sido introducido, le dice al usuario que este valor falta
        printf("El valor de 'ZT' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceZ()
{
    while (Zchk == false)
    {
        printf("El valor de Z es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceV()
{
    while (Vchk == false)
    {
        printf("El valor de 'V' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceI()
{
    while (Ichk == false)
    {
        printf("El valor de 'I' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceR()
{
    while (Rchk == false)
    {
        printf("El valor de 'R' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceVL()
{
    while (VLchk == false)
    {
        printf("El valor de 'VL' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceVR()
{
    while (VRchk == false)
    {
        printf("El valor de 'VR' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceVC()
{
    while (Vcchk == false)
    {
        printf("El valor de 'Vc' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analicePC()
{
    while (PCchk == false)
    {
        printf("El valor de 'Pc' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analicePR()
{
    while (PRchk == false)
    {
        printf("El valor de 'Pr' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analicePL()
{
    while (PLchk == false)
    {
        printf("El valor de 'Pl' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceQL()
{
    while (QLchk == false)
    {
        printf("El valor de 'Ql' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceQR()
{
    while (QRchk == false)
    {
        printf("El valor de 'Qr' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceQC()
{
    while (QCchk == false)
    {
        printf("El valor de 'Qc' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceXC()
{
    while (XCchk == false)
    {
        printf("El valor de 'Xc' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceXL()
{
    while (XLchk == false)
    {
        printf("El valor de 'XL' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceS()
{
    while (Schk == false)
    {
        printf("El valor de 'S' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceP()
{
    while (Pchk == false)
    {
        printf("El valor de 'P' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceQ()
{
    while (Qchk == false)
    {
        printf("El valor de 'Q' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceCosP()
{
    while (CosPchk == false)
    {
        printf("El valor de 'CosP' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analicef()
{
    while (fchk == false)
    {
        printf("El valor de 'f' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analicepZt()
{
    while (pztchk == false)
    {
        printf("La parte imaginaria de Zt es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceL()
{
    while (Lchk == false)
    {
        printf("El valor de 'L' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceW()
{
    while (Wchk == false)
    {
        printf("El valor de 'W' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceJ()
{
    while (Jchk == false)
    {
        printf("El valor de 'J' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceC()
{
    while (Cchk == false)
    {
        printf("El valor de 'C' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}
void analiceAngulo()
{
    while (Angulochk == false)
    {
        printf("El valor del 'Angulo' es faltante, por favor intruzca su valor.\n");
        scanf("%s", entrada);
        parser();
    }
}

float concatenar(float num)
{
    if (pdecimal == true) // Cuando esta encendido concatena los valores como decimales
    {
        corrido *= 0.1;
        num -= '0';                  //Convercion de char a entero
        number += ((num * corrido)); //Concatenarlo como un numero decimal
    }
    else if (num != 46) // Si es un numero entero pasa por este proceso.
    {
        num -= '0'; //Convercion de char a entero
        number = ((number * 10) + num);
        if (snegativo == true)
        {
            number *= -1;
        }
    }
    else if (num == '-')
    {
        snegativo = true;
    }
    else // Cuando recibe el punto enciende el Pdecimal.
    {
        pdecimal = true;
        corrido = 1.0;
    }
    // Resetea el corrido para el siguiente numero.
}

void Asignarnombre()
{
    if ((strcmp(name, "R") == 0) || (strcmp(name, "r") == 0))
    {
        R = number;       // Mete el valor introducido en la variable correspondiente.
        Rchk = true;      // Activa la variable como 'Ya ha sido introducida'.
        Zformula[1] += 1; // aumenta el conteo de variables para esa formula. UNA VARIABLE PUEDE ESTAR EN DOS FORMULAS
    }
    else if ((strcmp(name, "ZT") == 0) || (strcmp(name, "ZT") == 0))
    {
        ZT = number;
        ZTchk = true;
        if (Rchk == false)
        {
            R = pZt[0];
            Rchk = true;
        }
        
    }
    else if ((strcmp(name, "Z") == 0) || (strcmp(name, "z") == 0))
    {
        Z = number;
        Zchk = true;
    }
    else if ((strcmp(name, "v") == 0) || (strcmp(name, "V") == 0))
    {
        V = number;
        Vchk = true;
        Zformula[0] += 1;
    }
    else if ((strcmp(name, "I") == 0) || (strcmp(name, "i") == 0))
    {
        I= number;
        Ichk = true;
        Zformula[0] += 1;
        CosPformula[1] += 1;
    }
    else if ((strcmp(name, "VL") == 0) || (strcmp(name, "Vl") == 0))
    {
        VL = number;
        VLchk = true;
    }
    else if ((strcmp(name, "VC") == 0) || (strcmp(name, "Vc") == 0))
    {
        Vc = number;
        Vcchk = true;
    }
    else if ((strcmp(name, "VR") == 0) || (strcmp(name, "Vr") == 0))
    {
        VR = number;
        VRchk = true;
    }
    else if ((strcmp(name, "R") == 0) || (strcmp(name, "r") == 0))
    {
        R = number;
        Rchk = true;
        Zformula[1] += 1;
    }
    else if ((strcmp(name, "PL") == 0) || (strcmp(name, "Pl") == 0))
    {
        PL = number;
        PLchk = true;
    }
    else if ((strcmp(name, "PR") == 0) || (strcmp(name, "Pr") == 0))
    {
        PR = number;
        PRchk = true;
    }
    else if ((strcmp(name, "PC") == 0) || (strcmp(name, "Pc") == 0))
    {
        PC = number;
        PCchk = true;
    }
    else if ((strcmp(name, "QL") == 0) || (strcmp(name, "Ql") == 0))
    {
        QL = number;
        QLchk = true;
    }
    else if ((strcmp(name, "QC") == 0) || (strcmp(name, "Qc") == 0))
    {
        QC = number;
        QCchk = true;
    }
    else if ((strcmp(name, "QR") == 0) || (strcmp(name, "Qr") == 0))
    {
        QR = number;
        QRchk = true;
    }
    else if ((strcmp(name, "XL") == 0) || (strcmp(name, "Xl") == 0))
    {
        XL = number;
        XLchk = true;
    }
    else if ((strcmp(name, "XC") == 0) || (strcmp(name, "Xc") == 0))
    {
        XC = number;
        XCchk = true;
    }
    else if ((strcmp(name, "S") == 0) || (strcmp(name, "s") == 0))
    {
        S = number;
        Schk = true;
        CosPformula[0] += 0.5;
    }
    else if ((strcmp(name, "P") == 0) || (strcmp(name, "p") == 0))
    {
        P = number;
        Pchk = true;
        CosPformula[0] += 0.5;
    }
    else if ((strcmp(name, "Q") == 0) || (strcmp(name, "q") == 0))
    {
        Q = number;
        Qchk = true;
    }
    else if ((strcmp(name, "Cosp") == 0) || (strcmp(name, "cosp") == 0))
    {
        CosP = number;
        CosPchk = true;
    }
    else if ((strcmp(name, "W") == 0) || (strcmp(name, "w") == 0))
    {
        W = number;
        Wchk = true;
        XLformula[0] += 1;
    }
    else if ((strcmp(name, "F") == 0) || (strcmp(name, "f") == 0))
    {
        f = number;
        fchk = true;
        XLformula[1] += 1;
    }
    else if ((strcmp(name, "L") == 0) || (strcmp(name, "l") == 0))
    {
        L = number;
        Lchk = true;
        XLformula[0] += 1;
        XLformula[1] += 1;
    }
    else if ((strcmp(name, "J") == 0) || (strcmp(name, "j") == 0))
    {
        J = number;
        Jchk = true;
        XLformula[0] += 1;
        XLformula[1] += 1;
    }
    else if ((strcmp(name, "C") == 0) || (strcmp(name, "c") == 0))
    {
        C = number;
        Cchk = true;
    }
    else if ((strcmp(name, "Angulo") == 0) || (strcmp(name, "angulo") == 0))
    {
        Angulo = number;
        Angulochk = true;
        CosPformula[0] += 1;
        CosPformula[1] += 1;
    }
}

void evaluarbuscado()
{

    if ((strcmp(name, "Zt") == 0) || (strcmp(name, "zt") == 0))
    {
        analiceR;
        analiceXL;
        analiceXC;
        result = (fabs(XL)) - (fabs(XC));
        printf("Zt = %.2f + %.2fj Ohms\n", R, result);
    }
    else if ((strcmp(name, "Z") == 0) || (strcmp(name, "Z") == 0))
    {
        if ((Zformula[0] > Zformula[1]))
        {
        analiceV();
        analiceI();
        result = (V/I);
        }
        else
        {
            analiceR();
            analiceXL();
            analiceXC();
            result = (sqrt((pow(R, 2)) + (pow((XL - XC), 2))));
        }
        printf("Z = %.2f Ohm\n", result);
    }
    else if ((strcmp(name, "I") == 0) || (strcmp(name, "i") == 0))
    {
        analiceV();
        analiceZ();
        result = V/Z;
        printf("I = %.2f amperes\n", result);
    }
    else if ((strcmp(name, "S") == 0) || (strcmp(name, "s") == 0))
    {
        analiceV();
        analiceI();
        result = fabs(V) * fabs(I);
        printf("S = %.2f vA\n", result);
    }
    else if ((strcmp(name, "R") == 0) || (strcmp(name, "r") == 0))
    {
        analiceVR();
        analiceI();
        result = (VR / I);
        printf("R = %.2f\n", result);
    }
    else if ((strcmp(name, "VR") == 0) || (strcmp(name, "Vr") == 0))
    {
        analiceR();
        analiceI();
        result = (R * I);
        printf("Vr = %.2f\n", result);
    }
    else if ((strcmp(name, "VC") == 0) || (strcmp(name, "Vc") == 0))
    {
        analiceXC();
        analiceI();
        result = (XC * I);
        printf("Vc = %.2f\n", result);
    }
    else if ((strcmp(name, "VL") == 0) || (strcmp(name, "Vl") == 0))
    {
        analiceXL();
        analiceI();
        result = (XL * I);
        printf("Vl = %.2f\n", result);
    }
    else if ((strcmp(name, "V") == 0) || (strcmp(name, "v") == 0))
    {
        analiceZ();
        analiceI();
        result = (Z * I);
        printf("V = %.2f\n", result);
    }
    else if ((strcmp(name, "Xl") == 0) || (strcmp(name, "xl") == 0))
    {
        if (XLformula[0] > XLformula[1])
        {
            analiceW();
            analiceL();
            analiceJ();
            result = (W * J * L);
        }
        else
        {
            analiceL();
            analicef();
            analiceJ();
            result = (2*3.14159* f * L * C);
        }
        printf("XL = %.2f Ohm\n", result);
    }
    else if ((strcmp(name, "xc") == 0) || (strcmp(name, "Xc") == 0))
    {
        analiceW();
        analiceC();
        analiceJ();
        result = ((J * -1) / (2 * 3.14159 * f * C));
        printf("XC = %.2f Ohm\n", result);
    }
    else if ((strcmp(name, "P") == 0) || (strcmp(name, "p") == 0))
    {
        analiceR();
        analiceI();
        result = R * (pow(I, 2));
        printf("P = %.2f \n", result);
    }
    else if ((strcmp(name, "Q") == 0) || (strcmp(name, "q") == 0))
    {
        analicepZt();
        analiceI();
        result = pZt[imaginaria] * (pow(I, 2));
        printf("Q = %.2f \n", result);
    }
    else if ((strcmp(name, "Q") == 0) || (strcmp(name, "q") == 0))
    {
        analicepZt();
        analiceI();
        result = pZt[imaginaria] * (pow(I, 2));
        printf("Q = %.2f \n", result);
    }
    else if ((strcmp(name, "CosP") == 0) || (strcmp(name, "Cosp") == 0))
    {
        if (CosPformula[0] > CosPformula[1])
        {
        analiceP();
        analiceS();
        result = P/S;
        }
        else
        {
            analiceI();
            result = cos(I);
        }
        printf("CosP = %.2f \n", result);
    }
    else if ((strcmp(name, "Angulo") == 0) || (strcmp(name, "angulo") == 0))
    {
        analiceXL();
        analiceXC();
        analiceR();
        result = atan((XL - XC)/R);
        printf("El angulo es = %.2f \n", result);
    }
}
/* Verifica si la entrada es un numero*/
int check_if_a_number(char num)
{
    if (is_a_number)
        concatenar(num);
}
void parser()
{
    int f;
    for (f = 0; f < 30; f++)
        name[f] = 0;
    int i = 0; // Esta y las siguientes dos lineas funcionan como un offset para el parser
    number = 0;
    end_of_valor = false;
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
        switch (entrada[i])
        {
        case ' ':
            break;
        case '+': // Divide a Zt en dos, real e imaginaria.
            pZt[real] = number;
            number = 0;
            pluschk = true;
            break;
        case '?':
            evaluarbuscado();
            end_of_valor = true;
            break;
        case '\0':
            pdecimal = false;
            end_of_valor = true;
            pZt[imaginaria] = number;
            pztchk = true;
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
    printf("Calculadora de circuito en RLC\n");
    printf("Es preferible que ingrese la primera letra siempre en mayuscula y no use espacios.\n");
    while (1)
    {
        scanf("%s", entrada);
        if ((strcmp(entrada, "clear") == 0) || (strcmp(entrada, "Clear") == 0))
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