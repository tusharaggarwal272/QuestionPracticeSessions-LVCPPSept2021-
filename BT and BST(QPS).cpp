#include<bits/stdc++.h>
using namespace std;

//leaf nodes
class node{
	public:
	node*left;
	node*right;
	int data;

	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};

node* createtree( ){

	node*head=NULL;
	int d;
	cin>>d;
	head=new node(d);
	queue<node*>q;
	q.push(head);

	while(!q.empty()){
		node*f=q.front();
		q.pop();

		int a,b;
		cin>>a>>b;

		if(a!=-1){
			f->left=new node(a);
			q.push(f->left);
		}
		if(b!=-1){
			f->right=new node(b);

			q.push(f->right);
		}
	}

	return head;

}

void printleafnodes(node*head){
	if(head==NULL)return;

	if(head->left==NULL and head->right==NULL){
		cout<<head->data<<" ";
		return;
	}

	printleafnodes(head->left);
	printleafnodes(head->right);
}


int main() {

	node*head=createtree();

	printleafnodes(head);

	return 0;
}

//structurally identical
#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	node*left;
	node*right;
	int data;

	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};

node* createtree(string s){
	if(s=="true"){
		int d;
		cin>>d;

		node*head=new node(d);
		string l;
		cin>>l;

		head->left=createtree(l);
		string r;
		cin>>r;

		head->right=createtree(r);

		return head;
	}
	return NULL;
}

bool structurallyidentical(node*head1,node*head2){
	if(head1==NULL and head2==NULL)return true;

	if(head1==NULL or head2==NULL)return false;

	return structurallyidentical(head1->left,head2->left) and structurallyidentical(head1->right,head2->right);
}
int main() {

	node*head1=createtree("true");
	node*head2=createtree("true");

	cout<<boolalpha<<structurallyidentical(head1,head2);

	return 0;
}

//sibling

#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	node*left;
	node*right;
	int data;

	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};

node* createtree(string s){
	if(s=="true"){
		int d;
		cin>>d;

		node*head=new node(d);
		string l;
		cin>>l;

		head->left=createtree(l);
		string r;
		cin>>r;

		head->right=createtree(r);

		return head;
	}
	return NULL;
}

void sibling(node*head){
	if(head==NULL)return;


	if(head->left==NULL and head->right)cout<<head->right->data<<" ";
	if(head->left and !head->right)cout<<head->left->data<<" ";

	sibling(head->left);
	sibling(head->right);
}
int main(){
	node*head=createtree("true");
	sibling(head);
}

//kth largest in BST
#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	node*left;
	node*right;
	int data;

	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};

void createtree(node*&head,int data){

	if(head==NULL){
		head=new node(data);
		return;
	}

	if(data<head->data){
		createtree(head->left,data);
	}

	else{
		createtree(head->right,data);
	}
}

vector<int>v;

void inorder(node*head){
	if(head==NULL)return;


	inorder(head->left);
	v.push_back(head->data);
	inorder(head->right);
}



int main(){
	node*head=NULL;

	int n;
	cin>>n;
	int m=n;
	while(n--){
		int d;
		cin>>d;
		createtree(head,d);
	}
	int k;
	cin>>k;

	inorder(head);

	cout<<v[m-k];

}
//Root to Leaf

#include<bits/stdc++.h>
using namespace std;
class node{
	public:
	node*left;
	node*right;
	int data;

	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};

node* createtree(string s){
	if(s=="true"){
		int d;
		cin>>d;

		node*head=new node(d);
		string l;
		cin>>l;

		head->left=createtree(l);
		string r;
		cin>>r;

		head->right=createtree(r);

		return head;
	}
	return NULL;
}

vector<int>v;

void roottoleafsum(node*head,int k,int sum){
	if(head==NULL)return;
	if(head->left==NULL and head->right==NULL and sum+head->data==k){
		v.push_back(head->data);
		for(auto x:v)cout<<x<<" ";//for each loop
		return;
	}

	

	v.push_back(head->data);
	roottoleafsum(head->left,k,sum+head->data);
	roottoleafsum(head->right,k,sum+head->data);

}

int main(){
	node*head=createtree("true");
	int k;
	cin>>k;

	roottoleafsum(head,k,0);
}

//replace with sum
#include<iostream>
using namespace std;
class node{
	public:
	node*left;
	node*right;
	int data;
	node(int data){
		this->left=NULL;
		this->right=NULL;
		this->data=data;
	}
};
void createtree(node*&head,int data){
	if(head==NULL){
		head=new node(data);
		return ;
	}


	if(data<head->data){
		 createtree(head->left,data);
		
	}
	else{
		 createtree(head->right,data);
	}
	
}

int sum=0;

void sumtree(node*head){
	if(head==NULL)return;


	sumtree(head->right);
	int d=head->data;
	head->data=sum;
	sum+=d;
	sumtree(head->left);
}


void print(node*head){
	if(head==NULL)return;


	if(head->left!=NULL){
		cout<<head->left->data<<" => ";
	}
	else{
		cout<<"END"<<" => ";
	}

	cout<<head->data;

	if(head->right!=NULL){
		cout<<" <= "<<head->right->data;
	}
	else{
		cout<<" <= "<<"END";
	}

	cout<<endl;

	print(head->left);
	print(head->right);


}
	

int main () {
	int n;
	cin>>n;
	node*head=NULL;
	for(int i=0;i<n;i++){
		int d;
		cin>>d;

		createtree(head,d);
	}

	sumtree(head);
	print(head);


	return 0;
}