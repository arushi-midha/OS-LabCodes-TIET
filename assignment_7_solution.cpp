#include <iostream>
using namespace std;
int main(){
	
	int m=3; //Number of resources
	int n=5; //Number of processes
	
	int allocation[n][m]={{0,1,0},
						  {2,0,0},
						  {3,0,2},
						  {2,1,1},
						  {0,0,2},};
						  
	int max[n][m]={{7,5,3},{3,2,2},{9,0,2},{4,2,2},{5,3,3}};
	int total[m]={10,5,7};
	
	int need[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			need[i][j]=max[i][j]-allocation[i][j];
		}
	}
	
	/*for(int i=0;i<n;i++){
		cout<<"\n";
		for(int j=0;j<m;j++){
			cout<<need[i][j]<<"\t";
		}
	}*/
	
	int available[m];
	
	for(int j=0;j<m;j++){
		int sum=0;
		for(int i=0;i<n;i++){
			sum=sum+allocation[i][j];
		}
		available[j]=total[j]-sum;
	}
	cout<<"Available resources are:"<<endl;
	for(int i=0;i<m;i++){
		cout<<available[i]<<" ";
	}
	
	int count=0;
	int seq[n];
	bool finished[n]={0};
	while (count<n){
		bool found=false;
		
		for(int i=0;i<n;i++){
			int j;
			if (finished[i]==0){
				
			for(j=0;j<m;j++){
				
					if(need[i][j]>available[j]){
					break;
				}
			}
			
			if(j==m){
				seq[count]=i;
				count++;
				finished[i]=1;
				for(int k=0;k<m;k++){
					available[k]+=allocation[i][k];
				}
				found=true;
			}	
			}}
			
			if (found==false){
				cout<<"\nNot in a safe state";
				return false;
			}
		}
		
		for(int k=0;k<n;k++){
			cout<<"\n";
			cout<<seq[k]<<" ";
		}
	}

	
	
	
						  
