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
int L[1<<18],R[1<<18];
vector<pair<int,int>> add[1<<18];
int ret[1<<18];

unsigned long long bitrev(unsigned long long x,int d=64) {
	x = (((x & 0xaaaaaaaaaaaaaaaaULL) >> 1) | ((x & 0x5555555555555555ULL) << 1));
	x = (((x & 0xccccccccccccccccULL) >> 2) | ((x & 0x3333333333333333ULL) << 2));
	x = (((x & 0xf0f0f0f0f0f0f0f0ULL) >> 4) | ((x & 0x0f0f0f0f0f0f0f0fULL) << 4));
	x = (((x & 0xff00ff00ff00ff00ULL) >> 8) | ((x & 0x00ff00ff00ff00ffULL) << 8));
	x = (((x & 0xffff0000ffff0000ULL) >>16) | ((x & 0x0000ffff0000ffffULL) <<16));
	x = ((x >> 32) | (x << 32));
	
	return x>>(64-d);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,1<<N) {
		cin>>x;
		if(x==0) L[i]=0,R[i]=(1<<N)-1;
		else L[i]=R[i]=x-1;
	}
	
	FOR(i,N) {
		FOR(x,1<<N) {
			if(x&(1<<i)) L[x]=max(L[x],L[x^(1<<i)]+1);
			else R[x]=min(R[x],R[x^(1<<i)]-1);
		}
	}
	
	FOR(i,1<<N) {
		if(L[i]>R[i]) return _P("NO\n");
		add[L[i]].push_back({R[i],i});
	}
	
	set<pair<int,int>> S;
	FOR(i,1<<N) {
		FORR(e,add[i]) S.insert(e);
		if(S.empty()) return _P("NO\n");
		auto a=*S.begin();
		S.erase(S.begin());
		if(a.first<i) return _P("NO\n");
		ret[a.second]=i+1;
	}
	
	cout<<"YES"<<endl;
	FOR(i,1<<N) cout<<ret[bitrev(i,N)]<<" ";
	cout<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
