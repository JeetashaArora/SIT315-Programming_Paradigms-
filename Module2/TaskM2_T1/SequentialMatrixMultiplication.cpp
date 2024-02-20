#include <chrono>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include<bits/stdc++.h>
using namespace std::chrono;
using namespace std;
#define SIZE 200
int r_mat[SIZE][SIZE];

void multiply (int mat1[][SIZE], int mat2[][SIZE],int R1,int C1,int R2, int C2)
{
  //Storing the start time
  auto start = high_resolution_clock::now();
  cout << "Multiplying the two given matrices" << endl;
  for (int i = 0; i < R1; i++)
	{
	  for (int j = 0; j < C2; j++)
		{
		  r_mat[i][j] =0;
		  for (int k = 0; k < R2; k++)
			{
			  r_mat[i][j] += mat1[i][k] * mat2[k][j];
			}
		 // cout << r_mat[i][j] << "\t";
		}
	//cout << endl;
	}
  //Storing the stop time
  auto stop = high_resolution_clock::now();

  //Calculating the time taken
  //by subtracting the start time from the stop time
  auto duration = duration_cast<milliseconds>(stop - start);

  //Printing the time taken in milliseconds
  cout << "Time taken by Sequential function :" << duration.count() << " milliseconds"
       << endl;
        //Writing the results in a file
  ofstream fout;
  fout.open("sample.txt");
  for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) 
        fout << r_mat[i][j] << " ";        
        fout << endl;
  }
  fout.close();
}

int main ()
{
  Menu:
  int R1=SIZE,R2=SIZE,C1=SIZE,C2=SIZE;
  
  int mat1[SIZE][SIZE];
  int mat2[SIZE][SIZE];
  
   for(int i=0;i<R1;i++)
  {
      for(int j=0;j<C1;j++)
      {
          mat1[i][j]=rand()%100;
      }
  }
  for(int i=0;i<R2;i++)
  {
      for(int j=0;j<C2;j++)
      {
          mat2[i][j]=rand()%2;
      }
  }
  for(int i=0;i<R2;i++)
  {
      for(int j=0;j<C2;j++)
      {
          mat2[i][j]=rand()%2;
      }
  }
  multiply (mat1, mat2,R1,C1,R2,C2);
 
  return 0;
}
