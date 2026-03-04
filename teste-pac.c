#include <stdio.h>
#include <string.h>

int lerVetor(char v[][40], int max){

    int contadorStr = 0;
    printf("Digite a string de posição 1");
    fgets( v[0],40,stdin);

    while(contadorStr <= max || strcmp(v[contadorStr],"FIM") != 0)
    {
        contadorStr++;
        printf("Digite a string de posição %d", contadorStr + 1);
        fgets(v[contadorStr],40,stdin);
        //
    }

    return contadorStr;
}

void ordenar(char v[][40], int n){
    char aux[40];
    for (int i = 0; i < n - 1 ; i++)
    {
        for(int j =0 ; j < n - i -1; j++){

            if(strcmp(v[i],v[i+1])>0){
                strcpy(aux,v[i]);
                strcpy(v[i+1],v[i]);
                strcpy(v[i+1],aux);
            }
        } 
    }
}

int contarDistintos(char v[100][40], int n){
    int qtdDistintos = 0;

    ordenar(v,n);
    for(int i = 0; i < n - 1; i++){
        if(strcmp(v[i],v[i+1]) == 0){
            qtdDistintos++;
        }
    }
    return qtdDistintos;
}


int main(){

    int max = 100;
    char v[max][40];

    lerVetor(v,max);
    printf("Quantidade de strings distintas: %d", contarDistintos(v,max));

    return 0;   
}