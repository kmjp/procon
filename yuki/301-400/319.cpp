#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

string decdec(string A) {
	for(int i=A.size()-1;i>=0;i--) {
		if(A[i]--!='0') break;
		A[i]='9';
	}
	return A.substr(A[0]=='0');
}

string A,B;
ll p10[20];
ll memo[20][2][2];

ll inc(int d,string &s, int lead,int one) {
	if(d>=s.size()) return 0;
	if(memo[d][lead][one]>=0) return memo[d][lead][one];
	ll ret=0;
	int i,ma=lead?(s[d]-'0'):10;
	
	FOR(i,ma) {
		if(i==2 && one) ret += p10[s.size()-1-d];
		ret += inc(d+1,s,0,i==1);
	}
	if(lead) {
		if(s[d]=='2' && one) ret += atoll(s.substr(d+1).c_str())+1;
		ret += inc(d+1,s,1,(s[d]=='1'));
	}
	
	return memo[d][lead][one]=ret;
}


ll con(string a) {
	if(a.size()<2) return a[0]>='2';
	
	int low=(a.back()-'0');
	a.pop_back();
	if(low<2) a=decdec(a);
	
	ll ret=1;
	int i;
	FOR(i,a.size()) {
		if(i || a[0]>'2') ret += p10[a.size()-1-i];
		else if(a[i]=='2') ret += atoll(a.substr(1).c_str())+1;
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,18) p10[i+1]=p10[i]*10;
	
	cin>>A>>B;
	int c=(A.back()=='2' && A[0]=='2');
	
	MINUS(memo);
	ll ret=con(B)+inc(0,B,1,0);
	MINUS(memo);
	A=decdec(A);
	ret -= con(A)+inc(0,A,1,0);
	
	cout<<(ret-c)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
