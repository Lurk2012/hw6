#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>

void gen_file (const char *name, const int length, const int start) 
{
  char buff[length];
  int i = 0;
  
  for (i = 0; i < length; i++) {
  buff[i] = (char)(i + start);
  //printf("%c", buff[i]);
  }
  //printf("\n");
  std::ofstream put (name);  
  put << buff;// << "\n";
  put.close();
}

int meas_file (const char *name) 
{
std::ifstream meas(name);

char letter;
int i = 0;

  while (! meas.eof()) 
  {
    letter = meas.get();
    i++;
  }
  return i - 1;
}

void app_file(const char *name1, const int length1, const char *name2, const int length2, const char *name3)
{
  char buff [length1 + length2];
  char letter;
  int i = 0;
  std::ifstream merge1(name1);
  std::ifstream merge2(name2);
  
  for (i = 0; i < length1; i++)
  {
    buff[i] = merge1.get();
    //printf("%d %c\n", i, buff[i]);
  }

  for (i = length1; i < length1 + length2; i++)
  {
    buff[i] = merge2.get();
    //printf("%d %c\n", i, buff[i]);
  }
  
  std::ofstream put (name3);  
  put << buff;// << "\n";
  put.close();
    
}

int main (int argc, const char** argv) 
{
  gen_file ("6_1.txt", 50, 48);
  gen_file ("6_2.txt", 60, 48);
  app_file("6_1.txt", meas_file ("6_1.txt"), "6_2.txt", meas_file ("6_2.txt"), "6_3.txt");
  
  for (int i = 1; i < argc; i++)
    {
    printf("\n%s: \n ", argv[i]);
    } 
  return 0;
}
