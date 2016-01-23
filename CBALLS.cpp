//https://www.codechef.com/problems/CBALLS
//mandeep singh @msdeep14
#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
//int total=0;
void seive(int prime[])
{
	prime[0]=0;
	prime[1]=0;
	for(int i=2;i<=10000;i++)
	{
		prime[i]=1;
	}

	int lim=sqrt(10000);
	for(int i=2;i<=lim;i++)
	{
		for(int j=i*i;j<=10000;j+=i)
		{
			prime[j]=0;
		}
	}
}
/*
int  store(int prime[],int store_prime[])
{
	int j=0;
	for(int i=2;i<=10000;i++)
	{
		if(prime[i]==1)
		{
			store_prime[j]=i;
			j++;
		}
	}
	return j;
}

void make(int buckets[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		if(buckets[i+1]<buckets[i])
		{
			total+=buckets[i]-buckets[i+1];
			buckets[i+1]=buckets[i];
		}
	}
}

int main()
{
	int t,n;
	int buckets[10001];
	int prime[10001];
	int temp,temp1;
	int store_prime[10001];
	cin>>t;
	seive(prime);
	int size=store(prime,store_prime);
	while(t--)
	{
		cin>>n;
		int min=INT_MAX;
		int j;
		for(int i=0;i<n;i++)
		{
			cin>>buckets[i];
		}
		int sum=total;
		make(buckets,n);
		for(int i=0;store_prime[i]<=buckets[n-1];i++)
		{
			sum=total;
			if(buckets[0]%store_prime[i]!=0 && buckets[0]>store_prime[i])
			{
				temp=buckets[0] + store_prime[i]-(buckets[0]%store_prime[i]);
				sum+=temp-buckets[0];
			}
			else if(buckets[0]%store_prime[i]!=0)
			{
				temp=buckets[0] + (store_prime[i]-buckets[0]);
				sum+=(store_prime[i]-buckets[0]);
			}
			else
			{
				temp=buckets[0];
			}
			for(j=1;j<n;j++)
			{
				if(buckets[j]<temp)
				{
					temp1=temp;
					sum+=temp1-buckets[j];
				}
				if(buckets[j]%store_prime[i]!=0 && buckets[j]>store_prime[i])
				{
					temp1=buckets[j] + store_prime[i]-(buckets[j]%store_prime[i]);
					sum+=temp1-buckets[j];
				}
				else if(buckets[j]%store_prime[i]!=0)
				{
					temp1=buckets[j] + (store_prime[i]-buckets[j]);
					sum+=(store_prime[i]-buckets[j]);
				}
				else
				{
					temp1=buckets[j];
				}
			}
			temp=buckets[j];
			if(sum<min)
			{
				min=sum;
			}

		}
		cout<<min<<endl;
	}
	return 0;
}
*/

int calculate(int prime[] ,int arr[] ,int n)
{
	int ans=INT_MAX;
	int current,temp;
	for(int i=1;i<=10000;i++)
	{
		if(prime[i]==1)
		{
			current=0;
			temp=0;
			for(int j=1;j<=n;j++)
			{
				if(arr[j]>current)
				{
					current=((arr[j]+i-1)/i)*i;
				}
				temp+=current-arr[j];
			}
			ans=min(ans,temp);
		}
	}
	return ans;
}

int main()
{
	int t,n;
	int arr[10001];
	int prime[10001];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>arr[i];
		}
		seive(prime);
		int ans=calculate(prime,arr,n);
		cout<<ans<<endl;
	}
	return 0;
	
	
	
	
	
}
