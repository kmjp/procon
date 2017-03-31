#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

int a;
int b;
int c;
int d;
int e;
int main(int argc,char** argv){
	b++;
	b++;
	b++;
	c++;
	c++;
	c++;
	c++;
	c++;
	
	cin>>d;
	while(d--) {
		e++;
		if(e%b&&e%c) cout<<e<<endl;
		else if(e%b) cout<<"Buzz"<<endl;
		else if(e%c) cout<<"Fizz"<<endl;
		else cout<<"FizzBuzz"<<endl;
	}
	
	
}
