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
int ask(vector<int> V) {
	cout<<"? "<<V.size()<<endl;
	int i;
	FOR(i,V.size()) {
		cout<<V[i]+1;
		if(i<V.size()-1) cout<<" ";
	}
	cout<<endl;
	cin>>i;
	return i;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> out;
	FOR(i,N) {
		vector<int> V;
		FOR(j,N) if(i!=j) V.push_back(j);
		if(ask(V)==0) out.push_back(i+1);
	}
	
	cout<<"! "<<out.size()<<endl;
	FORR(v,out) cout<<v<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
