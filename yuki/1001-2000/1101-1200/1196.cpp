#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
double P,Q,R;
string S,T;
char* C;


double expression();

double exp2() {
	if(*C=='Y') {
		C++;
		return 1;
	}
	if(*C=='N') {
		C++;
		return 0;
	}
	if(*C=='(') {
		C++;
		double A=expression();
		C++;
		return A;
	}
	
	C++;
	double A=expression();
	double B=expression();
	C++;
	return A*B*P+(1-A)*(1-B)*Q;
}

double exp1() {
	double A=exp2();
	while(*C=='A') {
		C++;
		double B=exp1();
		A=A*B;
		A=R*A+(1-R)*(1-A);
	}
	return A;
}
double expression() {
	double A=exp1();
	while(*C=='O') {
		C++;
		double B=exp1();
		A=1-(1-A)*(1-B);
		A=R*A+(1-R)*(1-A);
	}
	return A;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>P>>Q>>R;
	cin>>S;
	FOR(i,N) {
		if(S[i]=='Y') T+='Y';
		else if(S[i]=='N') T+='N';
		else if(S[i]=='(') T+="(";
		else if(S[i]==')') T+=")";
		if(S[i]=='a') {
			T+='A';
			i+=2;
		}
		else if(S[i]=='o') {
			T+='O';
			i+=1;
		}
		else if(S[i]=='r') {
			T+='R';
			i+=6;
		}
	}
	C=&T[0];
	_P("%.12lf\n",floor(expression()*100));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
