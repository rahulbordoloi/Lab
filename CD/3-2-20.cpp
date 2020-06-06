#include<iostream>
#include<string.h>
#define sp "\t"
#define f(i,a,b) for(i=a;i<b;i++)

using namespace std;

int i;

main()
{
    char str[20],f='a';
    cout<<"\nInput your String:\n";
    cin>>str;
    //int state=0,flag=0;
    int len=strlen(str);
    //flag=1;
    //cout<<len<<sp<<flag;

    //string starts with 101

    /*f(i,0,len)
    {
      switch(f)
      {
      case 'a': if(str[i]=='1') 
                {
                  f='b';
                  break;
                }
                else
                { 
                  f='x';
                  //flag=1;
                  break;
                }
      case 'b': if(str[i]=='0') 
                {
                  f='c';
                  break;
                }
                else
                { 
                  f='x';
                  //flag=1;
                  break;
                }
      case 'c': if(str[i]=='1')
                { 
                  f='d';
                  break;
                }
                else
                { 
                  f='x';
                  //flag=1;
                  break;
                }
      case 'd': if(str[i]=='0' || str[i]=='1')
                 {
                    f='d';
                    break;
                 }
                 else
                 {
                    //flag=0;
                    f='x';
                    break;
                 }
      case 'x': if(str[i]=='0' || str[i]=='1')
                 {
                    f='x';
                    //flag=0;
                    break;   
                 }
     }
    }
    if(f == 'd') //&& flag==1) 
       cout<<"\nString Accepted!\n";
    else //&& flag==0)
       cout<<"\nString NOT Accepted!\n"; */
       
    
    //string ends with 101

    /*f(i,0,len)
    {
      switch(f)
      {
      case 'a': if(str[i]=='0' || str[i]=='1')
                 {
                    f='a';
                    break;
                 }
                 else
                 {
                    //flag=0;
                    f='x';
                    break;
                 }
      case 'b': if(str[i]=='1') 
                {
                  f='c';
                  break;
                }
                else
                { 
                  f='x';
                  //flag=1;
                  break;
                }
      case 'c': if(str[i]=='0') 
                {
                  f='d';
                  break;
                }
                else
                { 
                  f='x';
                  //flag=1;
                  break;
                }
      case 'd': if(str[i]=='1')
                { 
                  f='e';
                  break;
                }
                else
                { 
                  f='x';
                  //flag=1;
                  break;
                }
      case 'x': if(str[i]=='0' || str[i]=='1')
                 {
                    f='x';
                    //flag=0;
                    break;   
                 }
     }
    }
    if(f == 'd') //&& flag==1) 
       cout<<"\nString Accepted!\n";
    else //&& flag==0)
       cout<<"\nString NOT Accepted!\n";*/


    //string containing 101
    /*f(i,0,len)
    {
      if(str[i]=='1')
      {
        if(str[i+1]=='0' && str[i+2]=='1')
        {
          f='d';
        }
      }
    }
    if(f == 'd') //&& flag==1) 
       cout<<"\nString Accepted!\n";
    else //&& flag==0)
       cout<<"\nString NOT Accepted!\n"; */

  //starts and ends with same symbol
  
  if(str[0] == str[len-1])
     cout<<"\nSame Symbol\n";
  else
  {
      cout<<"\nNot Same Symbol\n";
  }
  
    
}
