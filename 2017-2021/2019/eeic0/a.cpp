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
int X[101010],Y[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<double> V;
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		V.push_back(atan2(Y[i],X[i]));
		V.push_back(atan2(Y[i],X[i])+8*atan(1));
		V.push_back(atan2(Y[i],X[i])+16*atan(1));
	}
	sort(ALL(V));
	FOR(i,N) {
		if(V[i+N]-V[i+N-1]>4*atan(1)+1e-9) {
			cout<<1<<endl;
			return;
		}
	}
	cout<<2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
