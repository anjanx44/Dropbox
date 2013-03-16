/*
Shiakh Shiam Rahman 
UVa : 482 - Permutaion Array
*/
    #include<iostream>
    #include<algorithm>
    #include <string.h>
    #include <stdio.h>
    #define MAX 1000000
    using namespace std;

      int t,order[MAX];
      char text[MAX];
      char *token;
      char item[MAX/2][100];
    int main()
    {
        freopen("input.txt","r",stdin);

      cin.getline(text,MAX);
      t = atoi(text);
      while(t--)
      {
        cin.getline(text,MAX);
        cin.getline(text,MAX);
        token = strtok(text," ");
        for(int i=0; token != NULL; i++)
        {
          order[i] = atoi(token);
          token = strtok(NULL," ");
        }
        cin.getline(text,MAX);
        token = strtok(text," ");
        int i;
        for(i=0; token != NULL; i++)
        {
          strcpy(item[order[i]-1], token);
          token = strtok(NULL," ");
        }
        for(int j=0; j<i; j++)
          printf("%s\n",item[j]);
        if(t != 0)
          printf("\n");
      }
      return 0;
    }

