/* Adding the Modulus operator and provision for negative numbers
* Program is given the input in a single and and it print the output upon
* getting a \n character.
* For e.g:
*
* 10 10 + 100 + 2 *
*       240
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

/* reverse polish calculator */ 

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];
    double vettpila[MAXOP]; //vettore in cui viene salvata la pila 
    int i; //dichiarazione di un'indice 

    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
                case NUMBER:
                        push(atof(s));
                        vettpila[i] = atof(s);  //inserisco il valore
                        i++;
                        break;
                case '+':
                        push(pop()+pop());
                        break;
                case '*':
                        push(pop()*pop());
                        break;
                case '-':
                        op2 = pop();
                        push(pop()-op2);
                        break;
                case '/':
                        op2 = pop();
                        if(op2 != 0.0)
                            push(pop()/op2);
                        else
                            printf("error:zero divisor\n");
                        break;
                case '%':
                        op2 = pop();
                        if(op2 != 0.0)
                            push(fmod(pop(),op2));
                        else
                            printf("erro:zero divisor\n");
                        break;
                case '\n':
                        printf("\t%.8g\n",pop());
                        i = 0;  //imposto l'indice a 0, svuotando così il buffer
                        break;
                default:
                        printf("error: unknown command %s\n",s);
                        break;

        }
        if (i != 0)
        {
            printf("pila: \n");
            for (int j = i - 1; j >= 0; j--)    //ciclo che scorre la pila al contrario stampandone i valori
                printf("%g \n", vettpila[j]);
        }
    }
    return 0;
}


