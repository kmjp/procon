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

ll Y,W;
ll N,M,D;
ll A[51],B[101010],C[101010];
vector<ll> CC[101010];
ll ret;
multiset<ll> MM;

void del(ll c) {
	auto it=MM.find(c);
	auto pr=it,ne=it;
	if(MM.count(c)==1) {
		ll le=*--pr;
		ll ri=*++ne;
		if(ri-le>D+1) {
			ret--;
			if(c-le<=D+1) ret-=c-le-1;
			if(ri-c<=D+1) ret-=ri-c-1;
		}
	}
	MM.erase(it);
}
void add(ll c) {
	auto it=MM.insert(c);
	auto pr=it,ne=it;
	ll le=*--pr;
	ll ri=*++ne;
	if(MM.count(c)==1) {
		if(ri-le>D+1) {
			ret++;
			if(c-le<=D+1) ret+=c-le-1;
			if(ri-c<=D+1) ret+=ri-c-1;
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Y>>W>>N>>M>>D;
	MM.insert(-1LL<<60);
	MM.insert(1LL<<60);
	
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		ret++;
		MM.insert(A[i]);
	}
	FOR(i,M) {
		cin>>B[i]>>C[i];
		B[i]--,C[i]--;
		CC[C[i]].push_back(B[i]*W+C[i]);
		if(MM.count(B[i]*W+C[i])==0) ret++;
		MM.insert(B[i]*W+C[i]);
	}
	auto it=MM.begin();
	auto it2=it;
	it2++;
	while(it2!=MM.end()) {
		if(*it2>*it && *it2-*it<=D+1) ret+=*it2-*it-1;
		it++;
		it2++;
	}
	FOR(i,W) {
		cout<<ret<<endl;
		//FORR(m,MM) cout<<m<<"  ";
		//cout<<endl;
		FOR(j,N) del(A[j]);
		FORR(c,CC[i]) del(c);
		FOR(j,N) add(++A[j]);
		FORR(c,CC[i]) add(c+W);
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
