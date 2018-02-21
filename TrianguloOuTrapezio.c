#include <stdio.h>
double absoluto(double x);

void E_Triangulo(float a, float b, float c);


int main(){
  float a, b, c;
  scanf("%f %f %f", &a, &b, &c);

  E_Triangulo(a, b, c);

  
}
void E_Triangulo(float a, float b, float c){
  float area, perimetro;
  if (absoluto(b-c) < a && a < (b+c)){
    if (absoluto(a-c) < b && b < (a+c)){
      if (absoluto(a-b) < c && c < (a+b)){
        perimetro = a + b + c;
        printf("Perimetro = %.1f", perimetro);
      }
    }
  }
  else{
    area = ((a+b)*c)/2;
    printf("Area = %.1f", area);
  }

}

double absoluto(double x){
  if (x >= 0.0){
    return x;
  }
  else{
    return (x*-1);
  }
}