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

int Q;
long double A;

vector<int> hoge(long double A) {
	int T2=A/8;
	vector<pair<long double,vector<int>>> C;
	int i;
	while(C.size()<100) {
		int x=rand()%(T2*T2);
		long double B=A/8-sqrt(x);
		int c[2]={(int)(B*B),(int)(B*B)+1};
		FOR(i,2) if(abs(A/8-(sqrt(x)+sqrt(c[i])))<5e-5) C.push_back({sqrt(x)+sqrt(c[i]),{x,c[i]}});
	}
	long double T=A/4, eps=5e-7;
	FOR(i,3) {
		vector<pair<long double,vector<int>>> C2;
		FORR(a,C) FORR(b,C) if(abs(T-(a.first+b.first))<eps) {
			vector<int> V=a.second;
			FORR(v,b.second) V.push_back(v);
			C2.push_back({a.first+b.first,V});
		}
		C=C2;
		T*=2;
		eps *= 1e-2;
	}
	if(C.size()) return C[0].second;
	return vector<int>();
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	srand(time(NULL));
	cin>>Q;
	while(Q--) {
		cin>>A;
		vector<int> V;
		while(1) {
			V=hoge(A);
			if(V.size()) break;
		}
		cout<<V.size();
		FORR(v,V) cout<<" "<<v;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
