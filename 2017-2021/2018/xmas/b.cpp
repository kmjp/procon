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

int pow(int a,int b) {
	if(a==1) return a;
	ll r=1;
	while(b && r<=1<<30) {
		r=r*a;
		b--;
	}
	if(r>1<<30) r=1<<30;
	return r;
}

int ok(vector<int> V,int val) {
	if(V.empty()) return val==1;
	
	int A=0;
	int N=V.size();
	for(int a=1;a<=N-1;a++) {
		A=A*10+V[N-a];
		if(V[N-1]==0 || V[N-a-1]==0 || val%A) continue;
		int B=0;
		for(int b=1;a+b<=N;b++) {
			B=B*10+V[N-a-b];
			int c=pow(A,B);
			if(c>val) break;
			if(val%c==0) {
				vector<int> W=V;
				W.resize(N-a-b);
				if(ok(W,val/c)) return 1;
			}
		}
	}
	
	
	return 0;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=20181224;i++) {
		vector<int> V;
		x=i;
		while(x) {
			V.push_back(x%10);
			x/=10;
		}
		int cur=0;
		x=1;
		while(V.size()) {
			cur+=x*V[0];
			x*=10;
			V.erase(V.begin());
			if(cur && i%cur==0 && V.size()>=2 && ok(V,i/cur)) cout<<i<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
