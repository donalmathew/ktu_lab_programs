#include<stdio.h>

struct element
{
  int row;
  int column;
  int value;
}matrix1[100],matrix2[100],result[100];

int main()
{
  int n1,n2;
  printf("\nenter number of terms matrix1 and matrix2\n");
  scanf("%d",&n1);
  scanf("%d",&n2);
  
  matrix1[0].value=n1;
  matrix2[0].value=n2;  
  
  int i=1,j=1,k=1;
  printf("\nenter terms in matrix1\n");  
  while(i<=n1)
  {
    printf("\nenter row\n");
    scanf("%d",&matrix1[i].row);
    printf("\nenter column\n");
    scanf("%d",&matrix1[i].column);
    printf("\nenter value\n");
    scanf("%d",&matrix1[i].value);
    i++;
  }
  
  printf("\nenter terms in matrix2\n");  
  while(j<=n2)
  {
    printf("\nenter row\n");
    scanf("%d",&matrix2[j].row);
    printf("\nenter column\n");
    scanf("%d",&matrix2[j].column);
    printf("\nenter value\n");
    scanf("%d",&matrix2[j].value);
    j++;
  }
  
  i=1,j=1,k=1;
  while(i<n1 && j<n2)
  {
    if(matrix1[i].row==matrix2[i].row && matrix1[i].column==matrix2[i].column)
    {
      result[k].row=matrix1[i].row;
      result[k].column=matrix1[i].column;
      result[k].value=matrix1[i].value+matrix2[i].value;
      i++,j++,k++;
    }
    else if(matrix1[i].row < matrix2[j].row)
    {
      result[k].row=matrix1[i].row;
      result[k].column=matrix1[i].column;
      result[k].value=matrix1[i].value;
      i++,k++;
    }
    else if(matrix1[i].row > matrix2[j].row)
    {
      result[k].row=matrix1[i].row;
      result[k].column=matrix2[j].column;
      result[k].value=matrix2[j].value;
      j++,k++;
    }
    
    if(matrix1[i].row == matrix2[j].row)
    {
      if(matrix1[i].column < matrix2[j].column)
      {
        result[k].row=matrix1[i].row;
        result[k].column=matrix1[i].column;
        result[k].value=matrix1[i].value;
        i++,k++;
      }
      if(matrix1[i].column > matrix2[j].column)
      {
        result[k].row=matrix2[j].row;
        result[k].column=matrix2[j].column;
        result[k].value=matrix2[j].value;
        j++,k++;
      }
    }
  
    if(i>n1)
    {
      while(j<=n2)
      {
        result[k].row=matrix2[j].row;
        result[k].column=matrix2[j].column;
        result[k].value=matrix2[j].value;
        j++,k++;
      }
    }
    if(j>n2)
    {
      while(i<=n1)
      {
        result[k].row=matrix1[i].row;
        result[k].column=matrix1[i].column;
        result[k].value=matrix1[i].value;
        i++,k++;
      }
    }
  }  
   

  printf("the resultant is\n");
  while(k<=n1)
  {
    
    printf("%d\n",matrix1[k].value);
    k++;
  }
}  