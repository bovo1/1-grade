#include <stdio.h>

void bubble(int n, int arr[]) // 버블정렬 함수
{
   int i, j, temp;

   for (i = 0; i < n; i++)
   {
      for (j = i + 1; j < n; j++)
      {
         if (arr[i] > arr[j])
         {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
         }
      }
   }
}

void set(int anum, int bnum, int a_arr[], int b_arr[])
{
   int set_arr[2000];
   int i = 0, temp = 0, k = 1, temp1=0,a=0;
   int size = anum + bnum;
   int j = size;
   
   for (i = 0; i < anum; i++)
   {
      set_arr[i] = a_arr[i];
   }
   for (i = anum; i < anum + bnum; i++)
   {
      set_arr[i] = b_arr[i - anum];
   }
   
   bubble(size, set_arr);

   /*printf("%d", size);
   printf("\n");

   for (i = 0; i < size; i++)
   {
      printf("%d ", set_arr[i]);
   }
   printf("\n");

   for (i = 0; i < size; i++)
   {
      if (set_arr[i] == set_arr[i + 1])
      {
         temp = set_arr[i + 1];
         set_arr[i + 1] = set_arr[j - 1];
         set_arr[j - 1] = temp;
         size--; j--;
      }
   }
   printf("%d", size);
   printf("\n");

   for (i = 0; i < size; i++)
   {
      printf("%d ", set_arr[i]);
   }
   printf("\n");

   for (i = 0; i < size; i++)
   {
      for (k = 1; k < size; k++)
      {
         if (set_arr[i] == set_arr[k])
         {
            temp1 = set_arr[k];
            set_arr[k] = set_arr[j - 1];
            set_arr[j - 1] = temp1;
            size--; j--;
         }
      }
   }*/

   for (i = 0; i < size; i++) {
      for (k = i + 1; k < size; k++) {
         if (set_arr[i] == set_arr[k]) {
            for (a = k; a < size; a++) {
               set_arr[a] = set_arr[a + 1];
            }
            size--; j--;
         }
      }
   }

   /*printf("%d", size);
   printf("\n");

   for (i = 0; i < size; i++)
   {
      printf("%d ", set_arr[i]);
   }
   printf("\n");*/

   bubble(size, set_arr);

   printf("%d", size);
   printf("\n");

   for (i = 0; i < size; i++)
   {
      printf("%d ", set_arr[i]);
   }
}


int main()
{
   int a_arr[1000];
   int b_arr[1000];
   int anum, bnum,i=0;

   scanf("%d", &anum);
   for (i = 0; i < anum; i++)
   {
      scanf("%d", &a_arr[i]);
   }

   scanf("%d", &bnum);
   for (i = 0; i < bnum; i++)
   {
      scanf("%d", &b_arr[i]);
   }

   set(anum, bnum, a_arr, b_arr);


   return 0;
}