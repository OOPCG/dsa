// chaining without replacement.

#include<iostream>

#include<stdlib.h>
#define MAX 10
using namespace std;
class WO_chain
{
  private:
  int a[MAX][2];
  public:
  WO_chain();
  int create(int);
  void chain(int,int),
  void display();
};

//The constructor defined

WO_chain::WO_chain()
{
 int i;
 for(i=0;i<MAX;i++)
 {
  a[i][0]=-1;
  a[i][1]=-1;
 }
}


//The create function is for generating the hash key
int WO_chain::create(int num)
{
 int key;
 key=num%10;
 return key;
}

//The chain function handles the collision without replacement of numbers
void WO_chain::chain(int key,int num)
{
  int flag,i,count=0,ch;
  flag=0;
  //checking full condition
  i=0;
  while(i<MAX)
  {
    if(a[i][0]!=-1)
       count++;
    i++;
  }
  if(count==MAX)
  {
    cout<<"\nHash Table Is Full";
    display();
    exit(1);
  }


  //placing number otherwise
  if(a[key][0]==-1)             //no collision case
      a[key][0]=num;
 
  else                        //if collision occurs
  {
     ch=a[key][1];//taking the chain
     //If only one number in hash table with current obtained key
     if(ch==-1)
     {
         for(i=key+1;i<MAX;i++)//performing linear probing
          {
              if(a[i][0]==-1)     //at immediate empty slot
              {
                 a[i][0]=num;     //placiing number
                 a[key][1]=i;     //setting the chain
                 flag=1;
                 break;
              }
          }
     }
    
    else    //if many numbers are already in the hash table thrn find the next empty slot to place number
     {
          while((a[ch][0]!=-1)&&(a[ch][1]!=-1))           //traversing thro chain till empty slot is found
                      ch=a[ch][1];
          for(i=ch+1;i<MAX;i++)
          {
               if(a[i][0]==-1)
               {
                   a[i][0]=num;          
                   a[ch][1]=i;             //setting chain
                   flag=1;
                   break;
               }
          }
    }


   //If the numbers are occupied somewhere from middle and are stored upto the MAX then we will search for the empty slot upper half of the array
   if(flag!=1)
   {
       if(ch==-1)
       {
            for(i=0;i<key;i++)//performing linear probing
            {
                if(a[i][0]==-1) //at immediate empty slot
                 {
                     a[i][0]=num;        //placiing number
                     a[key][1]=i; //setting the chain
                     flag=1;
                     break;
                 }
            }
       }
  //if many numbers are already in the hash table we will find the next empty slot to place number
  else
  {
     //traversing thro chain till empty slot is found
     while((a[ch][0]!=-1)&&(a[ch][1]!=-1))
          ch=a[ch][1];
     for(i=ch+1;i<key;i++)
     {
          if(a[i][0]==-1)
          {
            a[i][0]=num;//placing the number
            a[ch][1]=i; //setting chain
            flag=1;
            break;
          }
     }
   }
 }
}
}



//The display function displays the hash table and chain table
void WO_chain::display()
{
 int i;
 cout<<"\n The Hash Table is...\n";
 for(i=0;i<MAX;i++)
  cout<<"\n  "<<i<<" "<<a[i][0]<<" "<<a[i][1];
}

int main()
{

 int num,key,i;
 char ans;
 int n;
 WO_chain h;
 
 cout<<"\nChaining Without Replacement";
 cout<<"\n Enter total keys to be inserted :";
 cin>>n;
 for(int i=0;i<n;i++)
 {
  cout<<"\n Enter The Number";
  cin>>num;
  key=h.create(num);
  h.chain(key,num);
 }
 h.display();
 
}
