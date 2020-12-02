/// ANN which applies the OR function (logic gate) to binary input 
// soon I hope to replace the Ganann library code with code inspired by https://www.cs.bham.ac.uk/~jxb/INC/nn.html 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h> 
#include "genann.h"
int main(int argc, char *argv[]) {
  srand(time(0)); 
  const double output[4] = {1, 1, 0, 1}; 
  const double input[16][2] = {{0, 1}, {1, 0}, {0, 0}, {1, 0}, {1, 1}};  
  int i; 
  genann *ann = genann_init(2, 1, 2, 1);

  for (i = 0; i < 300; ++i) {
      genann_train(ann, input[0], output + 0, 3);
      genann_train(ann, input[1], output + 1, 3);
      genann_train(ann, input[2], output + 2, 3);
      genann_train(ann, input[3], output + 3, 3);
  }

  double num; 
  double binary[2]; 

  while (1) { 
    printf("Enter 1 or 0: ");
    scanf("%lf", &num); 
    binary[0] = num; 
    printf("Enter 1 or 0: ");
    scanf("%lf", &num); 
    binary[1] = num; 
    if ((binary[0] == 0 || binary[0] == 1) && (binary[1] == 0 || binary[1] == 1)) {
      printf("Output for  is %1.f.\n",  *genann_run(ann, binary));
    } else {
      printf("Invalid input\n"); 
      // return; 
    }
  } 
    
    // genann_free(ann);
  return 0;
}
