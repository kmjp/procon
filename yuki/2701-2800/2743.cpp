#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int H,W,N;
map<int,vector<int>> M;
int VR[201010],VC[201010];
ll ret[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>N;
	vector<pair<int,int>> Cs;
	FOR(i,N) {
		cin>>VR[i]>>VC[i];
		M[VC[i]].push_back(VR[i]);
		ret[i]=1LL<<60;
		Cs.push_back({VC[i],i});
	}
	FORR2(a,b,M) {
		sort(ALL(b));
		M[a]=b;
	}
	
	FOR(i,N) {
		auto it=lower_bound(ALL(M[VC[i]]),VR[i]);
		if(next(it)!=M[VC[i]].end()) ret[i]=min(ret[i],(ll)*next(it)-*it);
		if(it!=M[VC[i]].begin()) ret[i]=min(ret[i],(ll)*it-*prev(it));
		if(M.count(VC[i]-1)) ret[i]=min(ret[i],max((ll)VR[i],(ll)M[VC[i]-1][0]));
		if(M.count(VC[i]+1)) ret[i]=min(ret[i],max((ll)VR[i],(ll)M[VC[i]+1][0]));
	}
	sort(ALL(Cs));
	ll ma=1LL<<60;
	for(int L=0,R=0;R<N;R++) {
		while(Cs[L].first<=Cs[R].first-2) {
			ma=min(ma,(ll)VR[Cs[L].second]-VC[Cs[L].second]);
			L++;
		}
		x=Cs[R].second;
		ret[x]=min(ret[x],ma+VR[x]+VC[x]-2);
	}
	ma=1LL<<60;
	for(int L=N-1,R=N-1;L>=0;L--) {
		while(Cs[L].first+2<=Cs[R].first) {
			ma=min(ma,(ll)VR[Cs[R].second]+VC[Cs[R].second]);
			R--;
		}
		x=Cs[L].second;
		ret[x]=min(ret[x],ma+VR[x]-VC[x]-2);
	}
	
	FOR(i,N) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
