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

int N,Q;
int X[404040];
int S[30303],T[30303],P[30303];
priority_queue<int> PQ[1404];
priority_queue<int> add[1404];
const int DI=240;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>X[i];
	FOR(i,Q) {
		cin>>S[i]>>T[i]>>P[i];
		S[i]--;
	}
	
	FOR(i,30000/DI) {
		vector<int> Xs;
		Xs.push_back(0);
		Xs.push_back(N);
		for(j=i*DI;j<min(Q,i*DI+DI);j++) {
			Xs.push_back(S[j]);
			Xs.push_back(T[j]);
		}
		sort(ALL(Xs));
		Xs.erase(unique(ALL(Xs)),Xs.end());
		FOR(x,504) {
			while(PQ[x].size()) PQ[x].pop();
			while(add[x].size()) add[x].pop();
		}
		
		FOR(x,Xs.size()-1) {
			for(j=Xs[x];j<Xs[x+1];j++) PQ[x].push(X[j]);
		}
		for(j=i*DI;j<min(Q,i*DI+DI);j++) {
			x=lower_bound(ALL(Xs),S[j])-Xs.begin();
			y=lower_bound(ALL(Xs),T[j])-Xs.begin();
			int cur=P[j];
			while(x>=y&&x<Xs.size()-1) {
				PQ[x].push(cur);
				add[x].push(-cur);
				cur=PQ[x].top();
				PQ[x].pop();
				x++;
			}
			if(x==Xs.size()-1) x=0;
			while(x<y) {
				PQ[x].push(cur);
				add[x].push(-cur);
				cur=PQ[x].top();
				PQ[x].pop();
				x++;
			}
			cout<<cur<<endl;
		}
		FOR(x,Xs.size()-1) {
			for(j=Xs[x];j<Xs[x+1];j++) {
				add[x].push(-X[j]);
				X[j]=-add[x].top();
				add[x].pop();
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
