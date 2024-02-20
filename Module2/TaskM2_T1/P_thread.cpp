#include <chrono>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include<bits/stdc++.h>
using namespace std::chrono;
using namespace std;
#define SIZE 200
#define MAX_THREADS 4
int thread_no=0;
int r_mat[SIZE][SIZE];
int mat1[SIZE][SIZE];
int mat2[SIZE][SIZE];
int task = SIZE/MAX_THREADS;
void* multiply(void *arg)
{
    int threadNo= thread_no++;
    for(int i=task*threadNo;i<(threadNo+1)*task;++i)
    {
        for(int j=0;j<SIZE;j++)
        {
            //r_mat[i][j] = 0;
            for(int k=0;k<SIZE;k++)
            {
                r_mat[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
}

int main ()
{
  Menu:
  int R1=SIZE,R2=SIZE,C1=SIZE,C2=SIZE;
  for(int i=0;i<R1;i++)
  {
      for(int j=0;j<C1;j++)
      {
          mat1[i][j]=rand()%2;
      }
  }
  for(int i=0;i<R2;i++)
  {
      for(int j=0;j<C2;j++)
      {
          mat2[i][j]=rand()%2;
      }
  }

  pthread_t threads[MAX_THREADS];
  //Storing the start time
  auto start = high_resolution_clock::now();
  for(int i=0;i<MAX_THREADS;i++)
  {
      int *p;
      pthread_create(&threads[i],NULL,multiply,(void*)(p));
  }
  for(int i=0;i<MAX_THREADS;i++)
  {
      pthread_join(threads[i],NULL);
  }
  //Storing the stop time
  auto stop = high_resolution_clock::now();
  //Calculating the time taken
  //by subtracting the start time from the stop time
  auto duration = duration_cast<milliseconds>(stop - start);

  //Printing the time taken in milliseconds
  cout << "Time taken by Parallel function :" << duration.count() << " milliseconds"
      << endl;
  ofstream fout;
  fout.open("Pthread.txt");
  for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) 
        fout << r_mat[i][j] << " ";        
        fout << endl;
  }
  fout.close();
  return 0;
}




