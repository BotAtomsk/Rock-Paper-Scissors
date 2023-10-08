#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
float random_float(const float min, const float max)
{
    if (max == min) return min;
    else if (min < max) return (max - min) * ((float)rand() / RAND_MAX) + min;

    // return 0 if min > max
    return 0;
}
// piedra gana tijera, tijera gana papel, y papel gana piedra
// piedra 1 
// papel 2
// tijera 3
int result(int input, int x) {
  if (input == x) {
    return 0; // EMPATE
  } else if (input == 1 && x == 2) {
    return -1; // tu piedra vs su papel, PIERDES 
  } else if (input == 1 && x == 3) {
    return 1; // tu piedra vs su tijera, GANAS
  } else if (input == 2 && x == 1) {
    return 1; // tu papel vs su piedra, GANAS
  } else if (input == 2 && x == 3) {
    return -1; // tu papel vs su tijera, PIERDES
  } else if (input == 3 && x == 1) {
    return -1; // tu tijera vs su piedra, PIERDES
  } else if (input == 3 && x == 2) {
    return 1; // tu tijera vs su papel, GANAS
  }
}

int main() {
  int input; 
  int countHuman = 0;
  int countAI = 0;
  char *AI = malloc(256);

  while(input != 999) {
    printf("Elige un numero para p p o t\n");
    scanf("%d", &input);
    float z = random_float(1, 4);
    int x = (int) floor(z);
    printf("%d\n", x);
    switch(x) {
      case 1: strcpy(AI, "Piedra");
      break;
      case 2: strcpy(AI, "Papel");
      break;
      case 3: strcpy(AI, "Tijera");
      break;
    }
    printf("%s\n", AI);


    switch (input) {
      case 1: printf("Has elegido piedra\n"); 
        if (result(input, x) > 0) {
          countHuman++;
        } else if (result(input, x) < 0) {
          countAI++;
        }
        
        printf("Tu piedra VS %s, por lo que el resultado es\nTu: %d\nAI: %d\n", AI, countHuman, countAI);
        break;
      case 2: printf("Has elegido papel\n"); 
        if (result(input, x) > 0) {
          countHuman++;
        } else if (result(input, x) < 0) {
          countAI++;
        }
        printf("Tu papel VS %s, por lo que el resultado es\nTu: %d\nAI: %d\n", AI, countHuman, countAI);
        break;
      case 3: printf("Has elegido tijera\n"); 
        if (result(input, x) > 0) {
          countHuman++;
        } else if (result(input, x) < 0) {
          countAI++;
        }
        printf("Tu tijera VS %s, por lo que el resultado es\nTu: %d\nAI: %d\n", AI, countHuman, countAI);
        break;
      case 999: printf("Te has salido\n"); 
        break;

      default: printf("unknown operation\n");  // ¿porqué entra en bucle?
        break;
    }
  }
}