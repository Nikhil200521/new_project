//------------------
#include<stdio.h>
#include<string.h>
#include<ctype.h>
//------------------

int main()
{
//----------------------------------------------------
    int  i,j=0,test,word_count=0,flag=0;
    char str[100],  words[100][100],temp[50][100];
//---------------------------------------------------------------

    printf("Enter the string\n");
    gets(str);
    printf("string length is %d\n", strlen(str));

//-----------------------------------------------------
    for (i=0;i<strlen(str);i++) {
        if((isblank(str[i]))||(str[i] == ',' && isblank(str[i+1]))||(str[i] == '.'))
        { word_count++; }
    }
//-------------------------------------------------
    for (i=0,j=0,test=0;j<strlen(str);j++)  {  //storing each word into an array
        if (((isblank(str[j]))&&(str[j] == ','))||(str[j] == '.')||(isblank(str[j]))||(str[j]==','))
        {
            words[i][test]='\0';
            i++;
            test=0; }
        else
             words[i][test++] = str[j];
    }
    test = 0;
//--------------------------------------
strcpy(temp[0],words[0]) ;
int count =1 ;
char tem[20];

for(i=0;i<word_count+1;i++) // storing each distinct value into an array.
{
    strcpy(tem,words[i]) ;

     for(j=0;j<count;j++){
        if(strcmp(tem,temp[j])!= 0)
             {   flag =1 ;
                 continue ;  }
          else if(strcmp(tem,temp[j])== 0)
              {    flag =0 ;
                   break ;   }
    }
      if(flag==1){

           strcpy(temp[count],tem) ;
           count++ ;         }

      flag =0 ;

}
int cnt =0 ;
//--------------------
   for (i = 0;i <count;i++)     //counting number of time each word repeat.
    {
        for (j = 0;j <= word_count;j++)
        {
            if (strcmp(temp[i],words[j]) == 0)
                cnt++;   }
        printf("no. of times wors %s repeated  is :%d\n", temp[i], cnt);
        cnt = 0;
    }
//------------------------------------------
 return 0 ;
}
