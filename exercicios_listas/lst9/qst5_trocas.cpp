/*
 * Escrever um algoritmo que leia um vetor A[20] de caracteres. Mostrar o vetor lido.
 * Trocar a seguir o 1º elemento com o 11º, o 2º com o 12º e, assim, sucessivamente 
 * até o 10º com o 20º. Mostrar o vetor modificado.
*/

#include <iostream>

int main(void)
{
  setlocale(LC_ALL, "Portuguese");

  char a[20], aux;
  for (int i = 0; i < 20; i++)
    {
      std::cout << "Informe o caractere " << i << ": ";
      std::cin >> a[i];
    }
  std::cout << std::endl << "{\n";
  for (int i = 0; i < 20; i++)
    {
      std::cout << "\"" << a[i] << "\", ";
      if ((i+1) % 5 == 0) std::cout << std::endl;
    }
  std::cout << "}\n\n";

  for (int i = 0; i < 10; i++)
    {
      aux = a[i];
      a[i] = a[i+10];
      a[i+10] = aux;
    }
  for (int i = 0; i < 20; i++) std::cout << "A[" << i << "] ~> " << a[i] << std::endl;
  
  return 0;
}
