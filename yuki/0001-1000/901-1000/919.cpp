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
int A[10101];
map<int,int> T[101010];
vector<pair<int,int>> E[101];

multiset<int> X,Y;
void add(int v) {
	X.insert(v);
	Y.insert(*X.rbegin());
	X.erase(X.find(*X.rbegin()));
	X.insert(*Y.begin());
	Y.erase(Y.begin());
	if(X.size()>Y.size()+1) {
		Y.insert(*X.rbegin());
		X.erase(X.find(*X.rbegin()));
	}
}

void del(int v) {
	if(X.count(v)) {
		X.erase(X.find(v));
		if(X.size()<Y.size()) {
			X.insert(*Y.begin());
			Y.erase(Y.begin());
		}
	}
	else {
		Y.erase(Y.find(v));
		if(X.size()>Y.size()+1) {
			Y.insert(*X.rbegin());
			X.erase(X.find(*X.rbegin()));
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	for(l=1;l<=N;l++) {
		for(x=0;x+l<=N;x+=l) E[x/100].push_back({x+l,x});
		for(x=N-l;x>=0;x-=l) E[x/100].push_back({x+l,x});
	}
	FOR(i,100) {
		sort(ALL(E[i]));
		int L=i*100,R=i*100;
		X.clear(),Y.clear();
		
		FORR(e,E[i]) {
			while(e.second<L) add(A[--L]);
			while(R<e.first) add(A[R++]);
			while(L<e.second) del(A[L++]);
			while(e.first<R) del(A[--R]);
			
			assert(X.size()==Y.size() || X.size()==Y.size()+1);
			T[e.second][e.first]=*X.rbegin();
		}
	}
	
	ll ret=0;
	for(l=1;l<=N;l++) {
		vector<ll> R;
		R.push_back(0);
		ll sum=0,ma=0;
		for(x=N-l;x>=0;x-=l) {
			sum+=T[x][x+l];
			ma=max(ma,sum);
			R.push_back(ma);
		}
		reverse(ALL(R));
		ret=max(ret,l*R[0]);
		sum=0;
		for(x=0;x+l<=N;x+=l) {
			sum+=T[x][x+l];
			ret=max(ret,l*(sum+R[x/l+1]));
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
