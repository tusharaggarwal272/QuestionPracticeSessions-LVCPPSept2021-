// ------------------------------------------------------------Diagonal Traversal-------------------------------------------------------------

#include<iostream>
using namespace std;

int main() {
	int m,n;
	cin>>m>>n;

	int arr[m][n];

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}

	int i=0,j=0;
	int count=0;
	while(i<m and j<n){
		if(count%2==0){
			cout<<arr[i][j]<<" ";
			while(i-1>=0 and j+1<n){
				i--;j++;
				cout<<arr[i][j]<<" ";
			}
			if(j+1<n){
				j++;
			}
			else{
				i++;
			}
		}else{
			cout<<arr[i][j]<<" ";
			while(i+1<m and j-1>=0){
				i++;j--;
				cout<<arr[i][j]<<" ";
			}
			if(i+1<m)i++;
			else j++;
		}
		count++;
	}

	
	return 0;
}

//-------------------------------------------------------------------Rotate Image!---------------------------------------------------------------
#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;

	int arr[n][n],temp[n][n];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			temp[j][i]=arr[i][j];
		}
	}

	int i=0,j=n-1;//to handle the first and the last row initialli and gradually it will be incremented and decremented.

	while(i<j){
		for(int k=0;k<n;k++){
			swap(temp[i][k],temp[j][k]);
		}
		i++,j--;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<temp[i][j]<<" ";
		}
		cout<<endl;
	}

	
	
	return 0;
}
//-------------------------------------------------------------------Maximum consecutive ones-3(Leetcode)---------------------------------------------
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       
        int count=0,maxi=INT_MIN;
        
        int i=0,j=0;//2 pointers here.
        
        
        int n=nums.size();
        
        while(i<n){
            if(nums[i]==0)count++;//keep the track about how many zeroes we have changed
            
            while(count>k){//if count >k means that you have reached beyond the limit for 0's.
                if(nums[j]==0){
                    count--;
                }
                j++;
            }
            
            maxi=max(maxi,i-j+1);
            
            i++;
        }
        
        return maxi;
        
    }
};


