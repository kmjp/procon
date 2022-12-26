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

int N,D;
ll X[1010],Y[1010];
int from[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(from);
	from[0]=0;
	
	cin>>N>>D;
	FOR(i,N) cin>>X[i]>>Y[i];
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FOR(i,N) if(from[i]==-1 && (X[i]-X[x])*(X[i]-X[x])+(Y[i]-Y[x])*(Y[i]-Y[x])<=D*D) {
			from[i]=x;
			Q.push(i);
		}
	}
	
	vector<int> V;
	V.push_back(N-1);
	while(V.back()!=0) V.push_back(from[V.back()]);
	reverse(ALL(V));
	FORR(v,V) cout<<v+1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
