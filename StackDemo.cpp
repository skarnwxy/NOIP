
#define StackDemo
#ifdef StackDemo

#include<iostream>
#include<cstdlib>

using namespace std;

// Demo2：---------------------------------
//#define n 100
// Push
void push(int s[], int *top, int *x)
{
   int n =100;
   if (*top==n){
   	    cout << "overflow" << endl;
   }
   else { 
   		(*top)++; 
   		s[*top]=*x; 
   }			  
}
// Pop
void pop(int s[], int *y, int *top)
{
   if (*top==0) {
   	    cout << "underflow" << endl;
   }  
   else { 
   		*y=s[*top];
		(*top)--; 
   }
}

// Eg1: ---------------------------------
// DataConvert
#define size 100
int a[size+1], n, d, i=0, j;

void DataConvert() {
	cout<<"Please enter a number(N) base 10:";
	cin>>n;
  	cout<<"please enter a number(d):";
 	cin>>d;
  	
  	// (1):
	do {
     	a[++i] = n%d;
    	n = n/d; 
  	} while(n!=0);
  	
	// (2): 	  
  	for(j=i; j>=1; j--) {
  	  	cout<<a[j];
	}
}

// Eg2: ---------------------------------
// Bracket
#define maxn 20
//char s[maxn+1];
char c[256];
int JudgeBracket(char c[256]) {
    // (1): 
	int top=0,i=0;
    while (c[i]!='@') 
    {
        if (c[i]=='(') {
       	    //s[top] = c[i];
        	top++;
        }
        if (c[i]==')') 
        {
           if (top>0){
 	  		    //s[top] = " ";
 	   	        top--;
		   } 
           else{
    	   		return 0;
		   } 
        }
        i++;
    }
    
    // (2): 
	if (top!=0) {
    	return 0;
	}
    else {
    	return 1;
	}	
}

// Eg3: ---------------------------------
// LastSuffix
char s[256];
int comp(char s[256])
{
    // (1): 
	const int N=300;
	long long int stack[N];
	
	// (2): 
	int top=0, ind=0;
    while(true)
	{
		if(s[ind]=='@') break;
		switch(s[ind])
		{
			case '+':
				 top--;
				 stack[top-1]=stack[top-1]+stack[top];break;
			case '-':
				 top--;
				 stack[top-1]=stack[top-1]-stack[top];break;
			case '*':
				 top--;
				 stack[top-1]=stack[top-1]*stack[top];break;
			case '/':
				 top--;
				 stack[top-1]=stack[top-1]/stack[top];break;
			default: 
			{
				long long int t=0;
				while(s[ind]!=' ')
				{
					t=10*t+(s[ind]-'0');
					ind++;
				}
				stack[top++]=t;
				break;
			}		
		}
		ind++;
	}
    return stack[0];
}

// Eg4: ---------------------------------
// CarDispatch
int CarDispatch()
{  	
	// (1): 
	const int N = 1010;
	int stack[N], a[N];   
	int top, n;	
	cout << "Please Input Car Number: ";
	cin >> n;
	
	// (2): 
	// a[i]为到达B站的车厢
	cout << "Please Input Car Sequence: ";
  	for (int i = 1;i <= n; ++i) {
  		cin >> a[i];	
	}
		
  	// (3): 
  	top = 0;
	// cur为需要进栈的车厢
	int cur = 1;
  	for (int i = 1; i <= n; ++i) 
  	{
	    // 进栈,到达A站；出栈,到达B站
	    while (cur <= a[i]){
 	        stack[++top] = cur++;	
	    } 		
		// 将a[i]弹出栈	
  		if (stack[top] == a[i]){
  		   	--top;
	    }	
  		else 
  		{
  			cout << "NO" << endl;
  			return 0;
  		}
  	}
  	cout << "YES" << endl;
  	return 0;
}

// ---------------------------------
int main() {
	// Demo1: ---------------------------------
	cout << "StackDemo" << endl;
	cout << endl;
	
	// Demo2: ---------------------------------
	// Push And Pop
	
	// Eg1: ---------------------------------
	// DataConvert
//	DataConvert();
//	cout << endl;
	
	// Eg2: ---------------------------------
	// JuageBracket
//	cout << "Please intput Char: ";
//	cin >> c;
//	if (JudgeBracket(c)){
//		cout << "YES" << endl;
//	}
//  	else {
//  		 cout << "NO" << endl;	
//    }
//	cout << endl;

	// Eg3: -----------------------------------
	// LastSuffix
//	cout << "input a string(@_over): ";
//	cin >> s;
//	int result = comp(s);
//	cout << "result is: " << result;
//	cout << endl;

	// Eg4: -----------------------------------
	// LastSuffix
	CarDispatch();
	
	
	return 0;
}

#endif