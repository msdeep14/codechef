//http://www.codechef.com/LTIME25/problems/CHEFSTLT
//mandeep singh @msdeep14
#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,k,n,l1,l2,t,min,max;
	char str1[100],str2[100];
	scanf("%d",&t);
	while(t--)
	{
		min=0;
		max=0;
		scanf("%s",str1);
		scanf("%s",str2);
		l1=strlen(str1);
		l2=strlen(str2);
		for(i=0,j=0;i<l1,j<l2;i++,j++)
		{
			if(str1[i]=='?' || str2[j]=='?')
			{
				max++;
			}
			else if(str1[i]!=str2[j])
			{
				min++;
				max++;
			}
		}
		printf("%d %d",min,max);
		printf("\n");
		
	}
	return 0;
}
