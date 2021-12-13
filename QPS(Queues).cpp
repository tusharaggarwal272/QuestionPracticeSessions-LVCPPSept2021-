//Reverse first q elements of the queue.

queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    
    stack<int>s;
    
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        
    }
    
    
    for(int i=0;i<q.size()-k;i++){
        q.push(q.front());
        q.pop();
    }
    
    return q;
    
}

//hoodies at coding blocks
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;

	queue<int>q[5];

	int preference[5];

	for(int i=0;i<5;i++){
		preference[i]=-1;
	}
	preference[0]=0;

	while(n--){
		char ch;
		cin>>ch;

		if(ch=='E'){
			preference[0]++;
			int a,b;
			cin>>a>>b;

			if(preference[a]==-1){
				preference[a]=preference[0];
			}
			q[a].push(b);
		}else{
			int id=0;
			int mini=INT_MAX;

			for(int i=1;i<=4;i++){
				if(preference[i]!=-1 and preference[i]<mini){
					id=i;
					mini=preference[i];
				}
			}

			cout<<id<<" "<<q[id].front()<<endl;

			q[id].pop();
			if(q[id].empty()){
				preference[id]=-1;
			}
		}
	}
	return 0;
}

//first negstive in every window:
#include<bits/stdc++.h>
using namespace std;

void windownegative(int arr[],int n,int k){
	deque<int>q;

	for(int i=0;i<k;i++){
		if(arr[i]<0){
			q.push_back(i);
		}
	}

	for(int i=k;i<n;i++){
		if(!q.empty())cout<<arr[q.front()]<<" ";
		else{
			cout<<0<<" ";
		}

		while(!q.empty() and q.front()<=i-k){
			q.pop_front();
		}

		if(arr[i]<0){
			q.push_back(i);
		}
	}
	if(!q.empty())cout<<arr[q.front()]<<" ";
		else{
			cout<<0<<" ";
		}

}

int main() {
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;

		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		windownegative(arr,n,k);

		cout<<endl;
	}
	return 0;
}