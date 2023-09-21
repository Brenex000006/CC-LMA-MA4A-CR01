#include <stdio.h>
#include <string.h>

int main(){
  // Declaração de variáveis para armazenar os valores individuais dos dígitos
  int fortunas[15];
  long numero = 0;
  
  // Solicita um número do tipo long enquanto o que é inserido for um valor maior ou igual a 1
  do{
  	printf("Numero: ");
    scanf("%ld", &numero);
  }while(numero < 1);

  // Pegando do último ao primeiro dígito, pulando um por um e multiplicando por 2
  fortunas[14] = ((numero / 10) % 10) * 2;
  fortunas[12] = (((numero / 10) / 100) % 10) * 2;
  fortunas[10] = ((((numero / 10) / 100) / 100) % 10) * 2;
  fortunas[8] = (((((numero / 10) / 100) / 100) / 100) % 10) * 2;
  fortunas[6] = ((((((numero / 10) / 100) / 100) / 100) / 100) % 10) * 2;
  fortunas[4] = (((((((numero / 10) / 100) / 100) / 100) / 100) / 100) % 10) * 2;
  fortunas[2] = ((((((((numero / 10) / 100) / 100) / 100) / 100) / 100) / 100) % 10) * 2;
  fortunas[0] = (((((((((numero / 10) / 100) / 100) / 100) / 100) / 100) / 100) / 100) % 10) * 2;

  // Pegar os valores e somar (transformando os decimais em unidades)
  for(int i = 0; i <= 14; i += 2){
    fortunas[i] = ((fortunas[i] / 10) * 10) + (fortunas[i] % 10);
  }

  int primeiraSoma = valores[0] + fortunas[2] + fortunas[4] + fortunas[6] + fortunas[8] + fortunas[10] + fortunas[12] + fortunas[14];

  // Pegando os números que não foram somados
  fortunas[1] = numero % 10;
  fortunas[3] = (numero / 10000) % 10;
  fortunas[5] = (numero / 1000000) % 10;
  fortunas[7] = (numero / 100000000) % 10;
  fortunas[9] = (numero / 10000000000) % 10;
  fortunas[11] = (numero / 1000000000000) % 10;
  fortunas[13] = (numero / 100000000000000) % 10;
  fortunas[15] = (numero / 10000000000000000) % 10;


  int segundaSoma = fortunas[1] + fortunas[3] + fortunas[5] + fortunas[7] + fortunas[9] + fortunas[11] + fortunas[13] + fortunas[15];

  int somaTotal = primeiraSoma = segundaSoma;

  // Verificar se o cartão tem resto 0 após a soma
  if (somaTotal % 10 != 0) {
    printf("INVALIDO\n");
    printf("%d", somaTotal);
    return 0;
  }

  // Contador de dígitos do número
  int contador = 0;

  while (numero != 0) {
    numero /= 10; // dividindo o valor da variável numero por 10 e, em seguida,
    contador++;    // atribuindo o resultado de volta à variável numero
  }

  // Verificando a marca do cartão com base no número de dígitos e no primeiro dígito
  if(contador == 16 && ((fortunas[0] + fortunas[1]) >= 6 && (fortunas[0] + fortunas[1]) <= 10)){
    printf("MASTERCARD\n");
  }
  else if(contador == 15 && ((fortunas[0] + fortunas[1]) >= 7 && (fortunas[0] + fortunas[1]) <= 10)){
    printf("AMERICAN EXPRESS\n");
  }
  else if((contador == 13 || contador == 16) && (fortunas[0] == 4)){
    printf("VISA\n");
  }

  return 0;
}