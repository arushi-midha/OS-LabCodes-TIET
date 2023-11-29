/*
Instructions: The instructor is required to discuss the concept of memory management with
the students. Students have to implement following program.

Write a program using C/C++/Java to simulate the first fit, best fit and worst fit memory
allocation strategy. Assume memory chunk and initial requirement for memory block from
your side.

Example Program Flow
1. Initialize the program with an initial memory chunk of a specified size.
2. Display the menu for the user to choose an allocation strategy (First Fit, Best Fit, Worst
Fit) or to exit.
3. Prompt the user to request a memory block allocation, specifying the size.
4. Allocate memory based on the chosen strategy.
5. Display the updated state of the memory chunk.
6. Repeat steps 3 to 5 until the user chooses to exit.
*/

#include <iostream>
using namespace std;
void firstFit(int blockSize[], int m, int processSize[], int n){
	
    int allocation[n]={0};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(processSize[i]<=blockSize[j]){
                allocation[i]=j+1;
                blockSize[j]-=processSize[i];
                break;
            }
        }
    }
    cout<<"Process ID"<<"\tProcess Size"<<"\tMemory allocated\n";
    for(int i=0;i<n;i++){
        cout<<i<<"\t\t\t"<<processSize[i];
        if(allocation[i]==0){
            cout<<"\t\t\t"<<"Not Allocated\n";
        }
        else{
            cout<<"\t\t\t"<<allocation[i]<<"\n";
        }
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n){
	int allocation[n]={0};
	
	
	
	for(int i=0;i<n;i++){
		int min_index=-1;
		int min=100000;
		for(int j=0;j<m;j++){
			if(processSize[i]<=blockSize[j] && blockSize[j]<min){
				min_index=j;
				min=blockSize[j];
			}
		}
		if(min_index !=-1){
			allocation[i]=min_index+1;
		    blockSize[min_index]-=processSize[i];
		}
		
	}
	
	cout<<"Process ID"<<"\tProcess Size"<<"\tMemory allocated\n";
    for(int i=0;i<n;i++){
        cout<<i<<"\t\t"<<processSize[i];
        if(allocation[i]==0){
            cout<<"\t\t"<<"Not Allocated\n";
        }
        else{
            cout<<"\t\t"<<allocation[i]<<"\n";
        }
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n){
	int allocation[n]={0};
	
	for(int i=0;i<n;i++){
		int max=0;
		int max_index=-1;
		for(int j=0;j<m;j++){
			if(processSize[i]<=blockSize[j] && blockSize[j]>max){
				max=blockSize[j];
				max_index=j;
			}
			
		}
		if(max_index!=-1){
				allocation[i]=max_index+1;
				blockSize[max_index]-=processSize[i];
			}
	}
	
	cout<<"Process ID"<<"\tProcess Size"<<"\tMemory allocated\n";
    for(int i=0;i<n;i++){
        cout<<i<<"\t\t"<<processSize[i];
        if(allocation[i]==0){
            cout<<"\t\t"<<"Not Allocated\n";
        }
        else{
            cout<<"\t\t"<<allocation[i]<<"\n";
        }
    }
}
int main(){
    int blockSize[5]={100, 500, 200, 300, 600};
    int processSize[4]={212, 417, 112, 426};
    int m=sizeof(blockSize)/sizeof(blockSize[0]);
    int n=sizeof(processSize)/sizeof(processSize[0]);
    
    worstFit(blockSize, m, processSize, n);

    
    
    
}