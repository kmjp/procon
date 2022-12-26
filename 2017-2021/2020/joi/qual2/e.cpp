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
string S;
string A;

const ll mo=1000000007;
int cur;

vector<ll> term();
vector<ll> factor();

vector<ll> expression() {
	auto A=term();
	while(cur<N && (S[cur]=='+' ||S[cur]=='-')) {
		vector<ll> V(3,0);
		if(S[cur]=='+') {
			cur++;
			auto B=term();
			V[0]=(A[0]*B[0]+A[0]*B[1]+A[1]*B[0])%mo;
			V[1]=(A[1]*B[1]+A[1]*B[2]+A[2]*B[1])%mo;
			V[2]=(A[2]*B[2]+A[2]*B[0]+A[0]*B[2])%mo;
		}
		else if(S[cur]=='-') {
			cur++;
			auto B=term();
			V[0]=(A[0]*B[0]+A[2]*B[0]+A[0]*B[2])%mo;
			V[1]=(A[1]*B[1]+A[0]*B[1]+A[1]*B[0])%mo;
			V[2]=(A[2]*B[2]+A[1]*B[2]+A[2]*B[1])%mo;
		}
		A=V;
	}
	return A;
}

vector<ll> term() {
	auto A=factor();
	while(cur<N && S[cur]=='*') {
		cur++;
		vector<ll> V(3,0);
		auto B=factor();
		V[0]=(A[0]*B[0]+A[2]*B[1]+A[1]*B[2])%mo;
		V[1]=(A[1]*B[1]+A[0]*B[2]+A[2]*B[0])%mo;
		V[2]=(A[2]*B[2]+A[1]*B[0]+A[0]*B[1])%mo;
		A=V;
	}
	return A;
}

vector<ll> factor() {
	vector<ll> V;
	
	if(S[cur]=='R') {
		cur++;
		V={1,0,0};
	}
	else if(S[cur]=='S') {
		cur++;
		V={0,1,0};
	}
	else if(S[cur]=='P') {
		cur++;
		V={0,0,1};
	}
	else if(S[cur]=='?') {
		cur++;
		V={1,1,1};
	}
	else if(S[cur]=='(') {
		cur++;
		V=expression();
		cur++;
	}
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>A;
	auto a=expression();
	if(A=="R") cout<<a[0]<<endl;
	if(A=="S") cout<<a[1]<<endl;
	if(A=="P") cout<<a[2]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
