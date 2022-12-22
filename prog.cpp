#include <iostream>
#include <stdio.h>
#include <string>
#include <bits/stdc++.h>
using namespace std;
#define N 9
long long  fact(long long  n) {
  if(n > 1)
    return n * fact(n - 1);
  else
    return 1;
}
long long  row[N], col[N], box[N];
bool sun = false;
long long  GC (long long  i, long long  j) { return i / 3 * 3 + j / 3; }
bool grey(long long  i, long long  j, long long  number)
{
    return !((row[i] >> number) & 1)
           && !((col[j] >> number) & 1)
           && !((box[GC (i, j)] >> number) & 1);
}
void setter(long long  arr[N][N])
{
for (long long  i = 0; i < N; i++)
        for (long long  j = 0; j < N; j++)
            row[i] |= 1 << arr[i][j],
                col[j] |= 1 << arr[i][j],
                box[GC  (i, j)] |= 1 << arr[i][j];
}
bool solving(long long  arr[N][N], long long  i, long long  j)
{
    // Set the initial values
    if (!sun)
        sun = true, setter(arr);
 
    if (i == N - 1 && j == N)
        return true;
    if (j == N)
j = 0, i++;
 
    if (arr[i][j])
        return solving(arr, i, j + 1);
 
    for (long long  nest = 1; nest <= N; nest++) {
        if (grey(i, j, nest)) {
            arr[i][j] = nest;
            row[i] |= 1 << nest;
            col[j] |= 1 << nest;
            box[GC  (i, j)] |= 1 << nest;
 
            if (solving(arr, i, j + 1))
                return true;
   row[i] &= ~(1 << nest);
            col[j] &= ~(1 << nest);
            box[GC  (i, j)] &= ~(1 << nest);
        }
 
        arr[i][j] = 0;
    }
 
    return false;
}
void print(long long  arr[N][N])
{
    for (long long  i = 0; i < N; i++, cout << '\n')
        for (long long  j = 0; j < N; j++)
            cout << arr[i][j] << ' ';
}
 int  main()
{
    long long arr[N][N];
    for(long long i=0;i<N;i++)
    {
      for(long long j=0;j<N;j++)
      {
cin>>arr[i][j];
      }
    }
 
    if (solving(arr, 0, 0))
        print(arr);
    else
        cout << "No solution exists\n";
 
    return 0;
}