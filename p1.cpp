//============================================================================
// Name        : a4.cpp
// Author      : zaynab
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include <assert.h>
using namespace std;
template < class queueElementType >
class queue
{
    public:
        queue();
       void enqueue(queueElementType e);
       queueElementType dequeue();
       void view(int arr2[],int l2,int arr3[],int l3);
       bool searching_in_arr(queueElementType &e,int arr2[],int l2,bool wait);
       void re_implement_D(queueElementType &e,int arr2[],int l2,int indexx);
       int getting_min_index(int arry4[],int size,int &min);
       bool isEmpty();
       void function1(int  arry[],int arry2[],int  window_size,int  intialseq,int index_intial,int size,int&size2,int maxsize);
       void function2(int arry2[],int arry3[],int  window_size,int max,int  intialseq,int index_intial,int &sizearr2,int &size3,int maxsize);
    private:
        struct Node;
        typedef Node * nodePtr;
        struct Node
        {
           queueElementType data;
            nodePtr next;
        };
        nodePtr f;
        nodePtr r;
        int EX;
};
template < class queueElementType >
queue < queueElementType >::queue()
 {
  f = NULL;
  r = NULL;
  EX=0;
 }
template < class queueElementType >
void queue < queueElementType > ::enqueue(queueElementType e)
 {
     nodePtr n(new Node);
     assert(n);
     n->next = 0;
     n->data = e;
     if (f == 0 )
     {
         n->next = f;
         f = n;
         r = n;
     }
    else
     {
          nodePtr pred = f;
          while((pred ->next != NULL))
          {
           pred = pred ->next;
          }
          n ->next = pred ->next;
          pred ->next = n;
          r = n;
     }
 }
template < class queueElementType >queueElementType
queue < queueElementType >::dequeue()
  {
      assert(f);
      nodePtr n(f);
      queueElementType frontElement(f->data);
      f = f->next;
      delete n;
      if (f == 0)
      r = 0;
      return frontElement;
   }
template < class queueElementType > bool
queue < queueElementType >::isEmpty()
 {
   return bool(f == 0);
 }
template < class queueElementType >
void queue < queueElementType >::function1(int  arry[],int arry2[],int  window_size,int  intialseq,int index_intial,int size,int&size2,int maxsize)
 {
   EX=intialseq;
   int i=index_intial+1;
   int k=0;
   bool kok=false;
	   while(i<size)
	   {
			 if((arry[i] == EX ))
			 {
				enqueue(arry[i]);
				if(searching_in_arr(arry[i], arry2,k,kok))
				{
					 re_implement_D(arry[i],arry2,k,-100);
					 k--;
				     arry2[k]=arry[i];
					 k++;
				}
				 EX++;
				 if(EX>maxsize)
				 {
					 EX=0;
				 }
			 }
			 else
			 {
				arry2[k]=arry[i];
				k++;
			 }
			 i++;
	   }
    size2=k;
 }
template < class queueElementType >
void queue < queueElementType >::function2(int arry2[],int arry3[],int  window_size,int max,int  intialseq,int index_intial,int &sizearr2,int &size3,int maxsize)
 {
	int t=0;
	int fake=0;
	int arry4[35];
    bool flag=false;
    int index=-100;
	while(searching_in_arr(EX, arry2,sizearr2,false))
	{
	  enqueue(EX);
	  re_implement_D(EX,arry2,sizearr2,index);
	  sizearr2--;
	  EX++;
	  if(EX>maxsize)
	 	 {
		 	 EX=0;
	 	 }
	}
	////array window
	int arry_win[window_size];
	int wow=EX;
	for(int y=0;y<window_size;y++)
	{
		arry_win[y]=wow;
		wow++;
		if(wow==(max+1))
		{
			wow=0;
		}
	}
	for(int i=0;i<sizearr2;i++)
	{
		for(int y=1;y<window_size;y++)
		{
			if(arry2[i]==arry_win[y])
			{
				bool wait=true;
				if( !(searching_in_arr(arry2[i], arry4,fake,wait)) )
				{
					flag=true;
					arry4[fake]=arry2[i];
					fake++;
					arry4[fake]=y;//index in winArry
					fake++;
					re_implement_D(arry2[i],arry2,sizearr2,index);
					sizearr2--;
					i--;
				}
			}
			if(i==-1)
			{
				break;
			}
		}
	}
	int min_index_in_arr,Min_index_in_win;
	while(fake>0)
	{
		min_index_in_arr=getting_min_index(arry4,fake,Min_index_in_win);
		if (flag==true)
		{
			arry3[t]=arry_win[Min_index_in_win];
			re_implement_D(arry4[min_index_in_arr],arry4,fake,min_index_in_arr);
			fake--;
			re_implement_D(arry4[min_index_in_arr-1],arry4,fake,min_index_in_arr-1);
			fake--;
			t++;
		}
	}
    size3=t;
 }
template < class queueElementType >
void queue < queueElementType >:: view(int arr2[],int l2,int arr3[],int l3)
{
	cout<<"R ";
	nodePtr LOL =f;
	while(LOL != NULL)
	{
		cout<<LOL->data<<" ";
		LOL = LOL->next;
	}
	while(!isEmpty() )
	{
		dequeue();
	}
	cout<<"E "<<EX<<" ";
	cout<<"W ";
	for(int k=0;k<l3;k++)
	{
		cout<<arr3[k]<<" ";
	}
	cout<<"D ";
	for(int k=0;k<l2;k++)
	{
		cout<<arr2[k]<<" ";
	}
	cout<<endl;
}
template <class queueElementType>
void queue<queueElementType>::re_implement_D(queueElementType &e,int arr2[],int l2,int indexx)
{
	int j;
	if(indexx==-100)
	{
		for( j =0;j<l2;j++)
		{
			if(arr2[j]==e)
			{
				break;
			}
		}
		for (int i = j; i < l2; i++)
		{
			arr2[i] = arr2[i + 1];
		}
	}
	else
	{
		for( j =0;j<l2;j++)
		{
			if(arr2[j]==e && (j==indexx))
			{
				break;
			}
		}
		for (int i = j; i < l2; i++)
		{
			arr2[i] = arr2[i + 1];
		}
	}
}
template <class queueElementType>
bool queue<queueElementType>::searching_in_arr(queueElementType &e,int arr2[],int l2,bool wait)
{
	if(wait==false)
	{
		for(int j =0;j<l2;j++)
		{
			if(arr2[j]==e)
			{
				return true;
			}
		}
	}
	else
	{
		for(int j =0;j<l2;j++)
		{
			if(arr2[j]==e && (j%2==0))
			{
				return true;
			}
		}
	}
	return false;
}
template <class queueElementType>
int queue<queueElementType>:: getting_min_index(int arry4[],int size,int&min)
{
	int index;
	min=arry4[1];
	index=1;
	for(int i=1;i<size;i+=2)
	{
		if(arry4[i]<min)
		{
		  min=arry4[i];
		  index=i;
		}
	}
 return index;
}
template class queue<int>;
int main(int argc, char *argv[])
{
	 int windowsize,maxsize,intial_seq,actualWinSize;
	 queue<int> qu;
	 int index_intial,size_arr,size__arr2,size_arr3;
	 maxsize = ( pow( 2,atoi(argv[1]) ) )-1;
	 actualWinSize= pow( 2,atoi(argv[1])-1 );
	 windowsize = atoi(argv[2]);
	 int arr[70],arr2[35],arr3[35];
	 bool seq=false,win=false,intial=false,packet=false,k1=false,k2=false,k3=false,arg=false;
	 if(argc<=4)
	 {
		cout<<"Invalid number of arguments"<<" ";
		arg=true;
	 }
	 for (int i=1;i<argc;i++)
	 {
         unsigned int H=strlen(argv[i]);

		 for(unsigned int j=0;j<H;j++)
		 {
			 if(( ( (argv[i][j]>=65) && (argv[i][j]<=122) )||(atoi(argv[i])==0) ) && (i==1) )
			 {
				seq=true;
			 }
			 if(((argv[i][j]==43) || (argv[i][j]==45)) &&(i==1))
			 {
				 seq=true;
			 }
			 if(( ((argv[i][j]>=65) && (argv[i][j]<=122))||(atoi(argv[i])==0) )&& (i==2))
			 {
				 win=true;
			 }
			 if(((argv[i][j]==43) || (argv[i][j]==45)) &&(i==2))
			 {
				 win=true;
			 }
			 if( ((argv[i][j]>=65) && (argv[i][j]<=122)) && (i==3))
			 {
				 intial=true;
			 }
			 if(((argv[i][j]==43) || (argv[i][j]==45)) &&(i==3))
			 {
				 intial=true;
			 }
			 if( (argv[i][j]>=65) && (argv[i][j]<=122) && ((i>3)&&(i<argc)) )
			 {
				 packet=true;

			 }
		 }

	 }
//////////checking on numbers ////////////////
	 for (int i=1;i<argc;i++)
	 {
         unsigned int H=strlen(argv[i]);
		 for(unsigned int j=0;j<H;j++)
		 {
			 if(( ( (argv[i][j]>=48) && (argv[i][j]<=57) )&&atoi(argv[i])>actualWinSize ) && (i==2) )
			 {
				 if(seq==true)
				  {
					 k3=false;
				  }
				 else
				 {
					 k3=true;
				 }
			 }
			 if( (((argv[i][j]>=48) && (argv[i][j]<=57) )&& atoi(argv[i])>maxsize )&& (i==3))
			 {
				 if(seq==true)
				  {
					 k1=false;
				  }
				 else
				 {
					 k1=true;
				 }
			 }
			 if( (((argv[i][j]>=48) && (argv[i][j]<=57) )&&( atoi(argv[i])>maxsize && maxsize>0 ) )&& (i>3))
			 {
				 k2=true;
			 }
		 }
	 }
	 bool Q=(k1 || k2 || k3||arg);
	 bool P=(seq||win||intial||packet);
	 if(Q||P)
	 {
		if(seq==true)
		{
			 cout<<"Invalid seqNumBits"<<" ";
		}
		if(win==true || k3==true)
		{
			cout<<"Invalid winSize"<<" ";
		}
		if(intial==true || k1==true)
		{
			cout<<"Invalid initSeq"<<" ";
		}
		if(packet==true || k2==true)
		{
			cout<<"Invalid packet ID"<<" ";
		}
		   cout<<endl;
		 return 0;
	 }
	 int p;
	 for (p=1;p<argc;p++)
	 {
		arr[p-1]=atoi(argv[p]);
	 }
	   size_arr=p-1;
	   intial_seq=atoi(argv[3]);
	   index_intial=2;
	   qu.function1(arr,arr2,windowsize,intial_seq,index_intial,size_arr,size__arr2,maxsize);
	   int g=size__arr2;
	   qu.function2(arr2,arr3,windowsize,maxsize,intial_seq,index_intial,g,size_arr3,maxsize);
	   int z=size_arr3;
	   int y=g;
	   qu.view(arr2,y,arr3,z);
	 return 0;
}
