#include<stdio.h>
#include<time.h>
#include<malloc.h>

int fd(int* a,int k,int j);
void rsort(int* a,int k,int j);


int main()
{
    int len=500000;
	int i=0,a[len];
	
	FILE* fp=NULL;
	
	fp=fopen("data.txt","r");
	
	for(i=0;i<len;i++)
	if(fscanf(fp,"%*[^0-9]%d",&a[i])!=1)break;

	rsort(a,0,len-1);
	for(i=0;i<len;i++)
	   printf("%d ",a[i]);
 
    return 0; 
	
} 

int fd(int* a,int k,int j)
{
	int tmp=a[k];
	int i,l=0;
	if(k>=j) return 0;
	for(i=k;i<=j;i++)
	{
	if(a[i]<tmp)
	{
	l=i;
	return l-1;
    }
	tmp=a[i];
    }
   
    return l;
		
}

void rsort(int* a,int k,int j)
{
	int i,r=0,s=a[k],q=0,p=0,t=0,x=0,d=0;
	if(j<=k)return;

	int* b,*c;
	b=(int*)malloc((j-k+1)*sizeof(int));
	c=(int*)malloc((j-k+1)*sizeof(int));
	
	for(i=k;i<=j;i++)
	    if(a[i]<=s)
	    {
	    	s=a[i];
	    	b[r++]=i;
		}
	
	b=(int*)realloc(b,r*sizeof(int));

	for(q=r-1;q>=0;q--)
	{
		t=p;
		if(q!=0)
		{
		
		for(i=k;i<=j;i++)
		{
		if(a[i]>=a[b[q]]&&a[i]<a[b[q-1]])
		c[p++]=a[i];
	    }
	    if((d=fd(c,t,p-1))!=0)
	    {
	     t=d;
	    rsort(c,t,p-1);

	    }
	    }
	    else
	    {
	
	    for(i=k;i<=j;i++)
		{
		if(a[i]>=a[b[q]])
		c[p++]=a[i];
	    }
	    if((d=fd(c,t,p-1))!=0)
	    {
	     t=d;
         rsort(c,t,p-1);

	    }
	    }

	}  

	
	for(i=k,x=0;i<=j;i++)
	    a[i]=c[x++];

	
}
