#include <iostream>
using namespace std;

void firstfit(int blocksize[],int m,int process_size[],int n)
{
	int allocation[n];
	for(int i=0;i<n;i++)
		allocation[i]=-1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
        {
            if(blocksize[j]>=process_size[i])
            {
                allocation[i] = j;
                blocksize[j] = blocksize[j]-process_size[i];
                break;
            }
        }
    }


    //Print 
    cout<<"Process\t Process Size\t Block no.\n";
    for(int i=0;i<n;i++)
    {
        if(allocation[i]!=-1)
            cout<<i+1<<"\t"<<process_size[i]<<"\t"<<allocation[i]+1;
        else
            cout<<i+1<<"\t"<<process_size[i]<<"\t"<<"Not Allocated";
        cout<<endl;
    }
}

int main()
{
	int m,n;
	cout<<"Enter no. of blocks and processes";
	cin>>m>>n;
	
	int blocksize[m],process_size[n];
	cout<<"Enter the block size";
	for(int i=0;i<m;i++)
		cin>>blocksize[i];

	cout<<"Enter the process size";
	for(int i=0;i<n;i++)
		cin>>process_size[i];

	firstfit(blocksize,m,process_size,n);

	
	return 0;
}