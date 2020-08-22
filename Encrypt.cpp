#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include <fstream>
using namespace std;

struct{
     char pass[200], _hash[200], note[100000], codeno[20];
     int y=0, z=0, scode=0, len=0, slen=0; string name, exten;
}cry;

void encrypt()
{
        int i=0, j=0, e=0, N=0;
        system("cls");
        std::cout<<"\n\t Create Secret Code ID : ";
        std::cin.getline(cry.codeno, 20);
        system("cls");
        std::cout<<"\n\t Enter lines : ";
        std::cin.getline(cry.note, 100000);
        cry.len = strlen(cry.note);
        cry.note[cry.len]='\0';
        ofstream put("put.txt",ios::app);
        put<<cry.codeno<<endl;
        cout<<"\n\n\t Encrypting. . . ";
        for(i=j=0; i<=cry.len; i++)
        {
          if(cry.note[i]!=' ' && i<cry.len)
          {
               cry.pass[j] = cry.note[i];
               j++;
          }
          else{
              cry.scode=strlen(cry.pass);
              cry.pass[cry.scode]='\0';
              if(cry.scode<50)
              {
                cry.z=((cry.scode)*3);
                cry._hash[cry.z]='\0';
                      for(int i=0; i<cry.scode+1; i++)
                         {
                         for(int j=(i*3); j<=(i*3+2); j++)
                            {
                                N = rand() % 5 + 1;
                                if(e==0)
                                {
                                    cry._hash[j]=cry.pass[i]+(cry.scode-5); e++;
                                }
                                else if(e==1)
                                {
                                    cry._hash[j]=cry.pass[i]+(cry.scode-N); e++;
                                }
                                else
                                {
                                    cry._hash[j]=cry.pass[i]+(cry.scode-N); e=0;
                                }
                              }
                            }
                          }
                          else{
                              cerr<<"\n\tPut less then 50 word length\n";
                          }

                    if (!put.is_open())
                    {
                         std::cerr<<"\n"<<"\t could not open file\n";
                    }
                    for(int i=0; i<strlen(cry._hash); i++)
                    {
                         cry.pass[i] = cry._hash[i];
                    }
                    cry.pass[cry.z]='\0';
                    cout<<". ";
                    put<<cry.pass<<" ";

               j=0;
               for(int k=0; k<200; k++)
               {
                    cry.pass[k]='\0';
               }
          }
     }
     put <<"lend"<<endl;
     put.close();
     std::cout<<"\n\n\n\n";
}
int decrypt()
{
          string codeno, match; int word=0;
          system("cls");
          ifstream take("put.txt", ios::in);
          std::cout<<"\n\t Enter Code ID : ";
          std::cin>>codeno; system("cls");
          std::cout<<"\n\n\t  Decrypted lines : ";

          while(!take.eof())
           {
            take>>match;
            if(codeno==match)
            {
             while(!take.eof())
             {
              take>>cry._hash;
              cry.scode=strlen(cry._hash);
               if(cry._hash[0]=='l' &&cry._hash[1]=='e' && cry._hash[2]=='n' && cry._hash[3]=='d')
               {
                    std::cout<<"\n\n\n\n";
                    getch();
                    return 0;
               }
               if(cry.scode<200)
                {
                    cry.z=((cry.scode)/3);
                    cry.pass[cry.z]='\0';
                    for(int i=0; i<cry.z; i++)
                    {
                         cry.pass[i] = cry._hash[i*3] - (cry.z-5);
                    }
                    cout<<cry.pass<<" ";
                }
                word++;
                if(word%15 == 0)
                  {
                    cout<<"\n\t\t\t    ";
                  }
              }
            }
          }
          std::cout<<"\n\n\n\n";
    return 0;
}

int main()
{
  while(1)
  {
     system("cls");
     std::cout<<"\n\n\n\n\n\t\t\t  W| WRITE encrypt note"
              <<"\n\t\t\t  R| READ encrypt note\t";
     char choice=getch();
     switch(choice){
        case 'W':
        case 'w':
                encrypt(); system("cls");
                std::cout<<"\n\n\t  Encrypted Successfully....\n\n";
                system("pause");
                break;
        case 'R':
        case 'r':
                decrypt();
                break;
     }
   }
   return 1;
}
