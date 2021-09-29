#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "disemvowel.h"

bool isVowel(char letter){
  return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' ||letter == 'u' || letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U');
}

char *disemvowel(char *str) {
  int inlen = strlen(str);
  int outlen=0;
  for(int i=0; i<inlen; i++){
   if(!isVowel(str[i])){
	outlen++;	   
   }
  }
  char* output = (char*) calloc(outlen + 1, sizeof(char));
  int outpos = 0;
  for(int i=0; outpos < outlen; i++){
    if(!isVowel(str[i])){
      output[outpos++]=str[i];
    }
  }
  output[outlen] = '\0';
  
  return output;
}

