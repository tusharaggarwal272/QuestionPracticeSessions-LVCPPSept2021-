//postfix evaluation
class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    int precedence(char ch){
        if(ch=='^')return 3;
        else if (ch=='/' or ch=='*')return 2;
        
        else if(ch=='+' || ch=='-')return 1;
        
        return -1;
    }
   
    string infixToPostfix(string s)
    {
        // Your code here
            
            string res="";
            
            stack<char>st;
            
            for(int i=0;i<s.length();i++){
                char ch=s[i];
                if(ch>='a' and ch<='z' || ch>='A' and ch<='Z' || ch>='0' and ch<='9'){
                    res+=ch;
                }
                
                else if(ch=='('){
                    st.push(ch);
                }
                
                else if(ch==')'){
                    while(!st.empty() and st.top()!='('){
                        res+=st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    while(!st.empty() and precedence(s[i])<=precedence(st.top())){
                        res+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
            
            while(!st.empty()){
                res+=st.top();
                st.pop();
            }
            
            return res;
       
    }
};
//infix to postfix
class Solution
{
    public:
    //Function to convert an infix expression to a postfix expression.
    int precedence(char ch){
        if(ch=='^')return 3;
        else if (ch=='/' or ch=='*')return 2;
        
        else if(ch=='+' || ch=='-')return 1;
        
        return -1;
    }
   
    string infixToPostfix(string s)
    {
        // Your code here
            
            string res="";
            
            stack<char>st;
            
            for(int i=0;i<s.length();i++){
                char ch=s[i];
                if(ch>='a' and ch<='z' || ch>='A' and ch<='Z' || ch>='0' and ch<='9'){
                    res+=ch;
                }
                
                else if(ch=='('){
                    st.push(ch);
                }
                
                else if(ch==')'){
                    while(!st.empty() and st.top()!='('){
                        res+=st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else{
                    while(!st.empty() and precedence(s[i])<=precedence(st.top())){
                        res+=st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
            
            while(!st.empty()){
                res+=st.top();
                st.pop();
            }
            
            return res;
       
    }
};

//next greater element
#include <bits/stdc++.h> 
using namespace std; 

// Function to print Next Greater Element for each element of the array
void nextGreater(int arr[], int n) 
{ 
 // Write Code here

 stack<int>s;
 vector<int>res(n);


        for(int i=0;i<n;i++){
            
            while(!s.empty() and arr[i]>arr[s.top()]){
                res[s.top()]=arr[i];
                s.pop();
            }

            s.push(i);
        }

        while(!s.empty()){
            res[s.top()]=-1;
            s.pop();
        }
        
        for(int i=0;i<n;i++){
            cout<<arr[i]<<","<<res[i]<<endl;
        }


} 

// The Main Function
int main() 
{ 
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        nextGreater(arr, n); 
    }
	
	return 0; 
} 
//asteroid

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& v) {
        stack<int>s;
        int n=v.size();
        
        for(int i=0;i<n;i++){
            if(v[i]>0 || s.empty() ){
                s.push(v[i]);
            }
            
            else{
                while(!s.empty() and s.top()<abs(v[i]) and s.top()>0)s.pop();
                
                if(!s.empty() and s.top()==abs(v[i]))s.pop();
                
                else{
                    if(s.empty() or s.top()<0)s.push(v[i]);
                }
            }
        }
        
        
        
        vector<int>res(s.size());
        
        for(int i=int(s.size())-1;i>=0;i--){
            res[i]=s.top();
            s.pop();
        }
        
        return res;
        
        
        
        
    }
};
