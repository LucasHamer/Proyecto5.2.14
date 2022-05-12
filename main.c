#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char sexo;
    float sueldo,sueldofinal,mayorsueldo;
    int legajomayor,cantm=0,cantf=0,legajo,antiguedad,categoria,cantm10,primero=1;

    do
    {
    printf("Ingrese el legajo: ");
    scanf("%d",&legajo);
    fflush(stdin);
    }while(legajo!=0&&legajo<1000||legajo>5000);

    while(legajo!=0)
    {
        do
        {
        printf("Ingrese el sueldo: ");
        scanf("%f",&sueldo);
        fflush(stdin);
        }while(sueldo<=1000);
        do
        {
        printf("Ingrese la antiguedad: ");
        scanf("%d",&antiguedad);
        fflush(stdin);
        }while(antiguedad<0);
        do
        {
        printf("Ingrese el sexo[M=Masculino o F=Femenino]: ");
        scanf("%c",&sexo);
        sexo=toupper(sexo);
        fflush(stdin);
        }while(sexo!='F'&&sexo!='M');
        do
        {
        printf("Ingrese la categoria: ");
        scanf("%d",&categoria);
        fflush(stdin);
        }while(categoria<1||categoria>5);
        sueldofinal=sueldo;

        switch(categoria)
        {
        case 2:
        case 3:
            sueldofinal+=500;
            break;
        case 4:
            sueldofinal+=sueldo*0.1;
            break;
        case 5:
            sueldofinal+=sueldo*0.3;
            break;
        }
        if(antiguedad>10)
        {
            sueldofinal+=sueldo*0.1;
            cantm10++;
        }
        if(primero==1||sueldofinal>mayorsueldo)
        {
            mayorsueldo=sueldofinal;
            legajomayor=legajo;
            primero=0;
        }
        if(sexo=='M')
        {
            cantm++;
        }
        else
        {
            cantf++;
        }
        printf("El sueldo es de: %.2f con legajo: %d\n",sueldofinal,legajo);
        printf("\n");
            do
            {
            printf("Ingrese el legajo: ");
            scanf("%d",&legajo);
            fflush(stdin);
            }while(legajo!=0&&legajo<1000||legajo>5000);
    }
    if(primero==0)
    {
        printf("La cantidad de empleados con mas de 10 anios es de: %d\n",cantm10);
        printf("El mayor sueldo es de %.2f con el legajo: %d\n",mayorsueldo,legajomayor);
        printf("La cantidad de Masculinos es de: %d, la cantidad de Femeninos es de: %d",cantm,cantf);
    }

    return 0;
}
