#Conersión de Sistemas Numéricos
#Author: EduardoQSR
#GitHub: https://github.com/EduardoQSR

#If you have any doubts, send me a messague


#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <math.h>

#define n 13

typedef char string30 [30];

int pintaMenu(string30 m[]);

int main()
{
	int opc;
	
	string30 mnu[n]={"Binario a Octal", "Binario a Decimal", "Binario a Hexadecimal", "Octal a Binario", "Octal a Decimal", "Octal a Hexadecimal", "Decimal a Binario","Decimal a Octal","Decimal a Hexadecimal", "Hexadecimal a Binario", "Hexadecimal a Octal", "Hexadecimal a Decimal"};
	
	do
	{
		opc=pintaMenu(mnu);
		int hexadecimall, octal=0, decimal=0, aux=0, aux2=0, modulo=0, moduloOctal=0, moduloHexadecimal=0, bin[20], oct[20], hex[20], maxPos=0, potencia=0, suma_parcial=0, suma_octal=0, bandera=0;
		char hexadecimal[50], vector_auxiliar[50], cad_auxiliar[3], vec_aux[50], binario[50], octall[50];
		string30 aux_octal;
        
		fflush(stdin);
        switch(opc)
        {
            case 1://Binario a Octal
            
			//Bloque I: De Binario a Decimal
			printf("\n-------------------------------------------------\n");
			printf("--------------DE BINARIO A OCTAL-----------------");
            printf("\n-------------------------------------------------\n");
			printf("INGRESA UN NUMERO BINARIO: ");
			gets(binario);//Guardo el valor en la cadena "binario"
			maxPos=strlen(binario);
			potencia=maxPos-1;
				
			for(int j=0; j<=strlen(binario); j++)
			{
				int sumabinaria=0;
				sumabinaria=pow(2, potencia);
				if(binario[j]=='1')
				{
					suma_parcial=suma_parcial+sumabinaria;
				}
				potencia=potencia-1;
			}
			
			//Bloque II: De Decimal a Octal

			do
			{
				moduloOctal=suma_parcial%8;
				if(moduloOctal==0)
				{
					suma_parcial=suma_parcial/8;
					oct[aux2]=moduloOctal;
					aux2++;					
				}else
				{
					suma_parcial=(suma_parcial-moduloOctal)/8;
					oct[aux2]=moduloOctal;
					aux2++;
				}
			}while(suma_parcial!=0);
			
			//Bloque III: Muestro el valor
			printf("\nLA CONVERSION A OCTAL ES: ");
			for(int i=aux2-1; i>=0; i--)
			{
				printf("%d", oct[i]);
			}
			
				break;	
			
            case 2://Binario a Decimal   
			
			printf("\n-------------------------------------------------\n");
			printf("--------------DE BINARIO A DECIMAL---------------");
            printf("\n-------------------------------------------------\n");
			//Bloque I: De Binario a Decimal
			           	
            printf("INGRESA UN NUMERO BINARIO: ");
			gets(binario);
			maxPos=strlen(binario);
			potencia=maxPos-1;
				
			for(int j=0; j<=strlen(binario); j++)
			{
				int sumabinaria=0;
				sumabinaria=pow(2, potencia);
				if(binario[j]=='1')
				{
					suma_parcial=suma_parcial+sumabinaria;
				}
				potencia=potencia-1;
			}
			
			//Bloque II: Muestro el valor a Decimal
			
			printf("\nLA CONVERSION A DECIMAL ES: %d", suma_parcial);
				break;
                
            case 3://Binario a Hexadecimal            	
        	
        	printf("\n-------------------------------------------------\n");
			printf("------------DE BINARIO A HEXADECIMAL-------------");
            printf("\n-------------------------------------------------\n");
        	//Bloque I: De Binario a Decimal
        	
            printf("INGRESA UN NUMERO BINARIO: ");
			gets(binario);
			maxPos=strlen(binario);
			potencia=maxPos-1;
				
			for(int j=0; j<=strlen(binario); j++)
			{
				int sumabinaria=0;
				sumabinaria=pow(2, potencia);
				if(binario[j]=='1')
				{
					suma_parcial=suma_parcial+sumabinaria;
				}
				potencia=potencia-1;
			}

			//Bloque II: De Decimal a Hexadecimal y muestra del valor a Hexadecimal
			
			printf("\nLA CONVERSION A HEXADECIMAL ES: %x", suma_parcial);

			break;
            
			case 4://Octal a Binario
			
			//Bloque I: De Octal a Binario
			
			printf("\n-------------------------------------------------\n");
			printf("---------------DE OCTAL A BINARIO----------------");
            printf("\n-------------------------------------------------\n");
			
			printf("INGRESA UN NUMERO OCTAL: ");
			scanf("%o", &octal);
			do
			{
				modulo=octal%2;
				if(modulo==0)
				{
					octal=octal/2;
					bin[aux]=0;
					aux++;					
				}else
				{
					octal=(octal-1)/2;
					bin[aux]=1;
					aux++;
				}
			}while(octal!=0);
			
			//Bloque II: Muestro el valor a Binario
			
			printf("\nLA CONVERSION A BINARIO ES: ");
			for(int i=aux-1; i>=0; i--)
			{
				
				printf("%d", bin[i]);
			}       	
                break;
                
            case 5://Octal a Decimal           	
            
			//Bloque I: Pido el valor en Octal   
			
			printf("\n-------------------------------------------------\n");
			printf("---------------DE OCTAL A DECIMAL----------------");
            printf("\n-------------------------------------------------\n");
			
			printf("INGRESA UN NUMERO OCTAL: ");
			gets(octall);
			
			maxPos=strlen(octall);
			potencia=maxPos-1;
			
			//Bloque II: Reviso que la cantidad introcudica pertenece al conjunto de los numeros octales
			for(int i=0; i<=maxPos-1; i++)
			{
				if(octall[i]=='0' || octall[i]=='1' || octall[i]=='2' || octall[i]=='3' || octall[i]=='4' || octall[i]=='5' || octall[i]=='6' || octall[i]=='7')
				{
					
				}else
				{
					bandera++;
				}
			}
			//Bloque III: Evalua la cantidad introducida en base a la variable "bandera"
			if(bandera>0)//Si el valor introducido no corresponde a un valor octal, no hace nada
			{
				printf("\n\n     Error... El numero que ha ingresado no corresponde a un numero Octal");
			}else
			{
				
				if(bandera==0)//Si el valor introducido corresponde a un valor octal, hace las operaciones de conversion
				{
					for(int j=0; j<=strlen(octall); j++)
					{	
						switch(octall[j])
						{
							case '1':
								suma_octal=suma_octal+(1)*(pow(8, potencia));
									break;
							case '2':
								suma_octal=suma_octal+(2)*(pow(8, potencia));
									break;
							case '3':
								suma_octal=suma_octal+(3)*(pow(8, potencia));
									break;
							case '4':
								suma_octal=suma_octal+(4)*(pow(8, potencia));
									break;
							case '5':
								suma_octal=suma_octal+(5)*(pow(8, potencia));
									break;
							case '6':
								suma_octal=suma_octal+(6)*(pow(8, potencia));
									break;
							case '7':
								suma_octal=suma_octal+(7)*(pow(8, potencia));
									break;
						}
						potencia=potencia-1;
					}
					//Bloque IV: Muestro el valor a Decimal
					printf("\nLA CONVERSION A DECIMAL ES: %d", suma_octal);
				}
			}
			
			break;
            
			case 6: //Octal a Hexadecimal
			
			printf("\n-------------------------------------------------\n");
			printf("-------------DE OCTAL A HEXADECIMAL--------------");
            printf("\n-------------------------------------------------\n");
			
			//Bloque I: Pido el valor y lo guardo como octal con el código de formato "%o"
			
			printf("INGRESA UN NUMERO OCTAL: ");
			scanf("%o", &octal);
			
			//Bloque II: Muestro el valor en Hexadecimal con el código de formato "%x"
			
			printf("\nLA CONVERSION A HEXADECIMAL ES: %x", octal);
				break;
				
        	case 7://Decimal a Binario
        	
        	//Bloque I: De Decimal a Binario
        	
        	printf("\n-------------------------------------------------\n");
			printf("--------------DE DECIMAL A BINARIO---------------");
            printf("\n-------------------------------------------------\n");
        	
			printf("INGRESA UN NUMERO DECIMAL: ");
            scanf("%d", &decimal);
			do
			{
				modulo=decimal%2;
				if(modulo==0)
				{
					decimal=decimal/2;
					bin[aux]=0;
					aux++;					
				}else
				{
					decimal=(decimal-1)/2;
					bin[aux]=1;
					aux++;
				}
			}while(decimal!=0);
			
			//Bloque II: Muestro  el valor en Binario
			
			printf("\nLA CONVERSION A BINARIO ES: ");
			for(int i=aux-1; i>=0; i--)
			{
				
				printf("%d", bin[i]);
			}
			
			break;
			
            case 8://Decimal a Octal
            
            printf("\n-------------------------------------------------\n");
			printf("---------------DE DECIMAL A OCTAL----------------");
            printf("\n-------------------------------------------------\n");
            
            //Bloque I: Pido el valor en decimal y lo guardo con el código de formato "%d"
            
            printf("INGRESA UN NUMERO DECIMAL: ");
			scanf("%d", &decimal);
			
			//Bloque II: Muestro  el valor en Octal con el código de formato "%o"
			
			printf("\nLA CONVERSION A OCTAL ES: %o", decimal);
			
                break;
                
            case 9://Decimal a Hexadecimal
            
            printf("\n-------------------------------------------------\n");
			printf("------------DE DECIMAL A HEXADECIMAL-------------");
            printf("\n-------------------------------------------------\n");
            
            //Bloque I: Pido el valor en decimal y lo guardo con el código de formato "%d"
			
            printf("INGRESA UN NUMERO DECIMAL: ");
			scanf("%d", &decimal);
			
			//Bloque II: Muestro  el valor en Hexadecimal con el código de formato "%x"
			
			printf("\nLA CONVERSION A HEXADECIMAL ES: %x", decimal);
			
                break;            
            
			case 10://Hexadecimal a Binario
			
			printf("\n-------------------------------------------------\n");
			printf("------------DE HEXADECIMAL A BINARIO-------------");
            printf("\n-------------------------------------------------\n");
            
			//Bloque I: Pido el valor en Hexadecimal
			
			printf("INGRESA UN NUMERO HEXADECIMAL: ");
            gets(hexadecimal);
            strupr(hexadecimal);//Convierte la cadena a mayusculas
            
            //Bloque II: Comparo cada carácter con su respectiva equivalencia a binario y lo muestro
            
			printf("\nLA CONVERSION A BINARIO ES: ");
            for(int i=0; i<strlen(hexadecimal); i++)
            {
            	switch(hexadecimal[i])
            	{
            		case '0':
            			printf("0000");
            			break;
            		case '1':
            			printf("0001");
            			break;
	            	case '2':
	            		printf("0010");
	            		break;
	            	case '3':
	            		printf("0011");
	            		break;
	            	case '4':
	            		printf("0100");
	            		break;
	            	case '5':
	            		printf("0110");
	            		break;
	            	case '6':
	            		printf("0110");
	            		break;
	            	case '7':
	            		printf("0111");
	            		break;
	            	case '8':
	            		printf("1000");
	            		break;
	            	case 9:
	            		printf("1001");
	            		break;
	            	case 'A':
	            		printf("1010");
	            		break;
	            	case 'B':
	            		printf("1011");
	            		break;
	            	case 'C':
	            		printf("1100");
	            		break;
	            	case 'D':
	            		printf("1101");
	            		break;
	            	case 'E':
	            		printf("1110");
	            		break;
	            	case 'F':
	            		printf("1111");
	            		break;
				}
			}
			    break;
       
            case 11://Hexadecimal a Octal
            
            printf("\n-------------------------------------------------\n");
			printf("-------------DE HEXADECIMAL A OCTAL--------------");
            printf("\n-------------------------------------------------\n");
            
            //Bloque I: Pido el valor en Hexadecimal y lo guardo con el código de formato "%x"
			   
            printf("INGRESA UN NUMERO HEXADECIMAL: ");
            scanf("%x", &hexadecimall);
            
            //Bloque II: Muestro  el valor en Octal con el código de formato "%o"
            
            printf("\nLA CONVERSION A OCTAL ES: %o", hexadecimall);
				break; 
				
            case 12://Hexadecimal a Decimal
            
            printf("\n-------------------------------------------------\n");
			printf("------------DE HEXADECIMAL A DECIMAL-------------");
            printf("\n-------------------------------------------------\n");
            
            //Bloque I: Pido el valor en Hexadecimal y lo guardo con el código de formato "%x"
                
            printf("INGRESE UN NUMERO HEXADECIMAL: ");
            scanf("%x", &hexadecimall);
            
            //Bloque II: Muestro  el valor en Decimal con el código de formato "%d"
            
            printf("\nLA CONVERSION A DECIMAL ES: %d", hexadecimall);
            break;
            
			case 13://Opción para salir del programa
            	printf("\n\n\n\n\n\n                  saliendo del sistema");
            	break;
            	
            default: printf("\n\n\n\n\n      ERROR... Opcion Incorrecta");
        }
    	getch();
    }while(opc != n);
	
	
	getch();
}

//Función que muestra el Menu Principal
int pintaMenu(string30 m[])
{
    int o;
    
    system("cls");//limpia el texto que haya en ls pantalla.
    printf("------------- MENU ---------------");
    for(int i =0; i < n-1; i++)
    {
        printf("\n %d.- De %s",i+1,m[i]);
    }
    printf("\n 13.- Salir");
    printf("\n SELECCIONA UNA OPCION: ");
    printf("\n----------------------------------\n");
    scanf("%d", &o);
    system("cls");
    return o;
}
