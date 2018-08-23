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
vector<int> X;
ll ret[101010];
vector<pair<int,int>> VV;

set<int> S;
set<pair<int,int>> cand;
int D[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	X.push_back(0);
	FOR(i,N) {
		cin>>x;
		if(X.back()==x) continue;
		if(X.size()>=2 && X[X.size()-2]<X.back() == X.back()<x) X.pop_back();
		X.push_back(x);
	}
	
	ll dif=0;
	if(X.size()>=2&&X[1]<0) {
		dif=-X[1];
		X.erase(X.begin());
		FORR(x,X) x+=dif;
	}
	
	FOR(i,X.size()) {
		S.insert(i);
		if(i) {
			D[i-1]=abs(X[i]-X[i-1]);
			dif+=D[i-1];
			cand.insert({D[i-1],i-1});
		}
	}
	
	FOR(i,Q) cin>>x, VV.push_back({x,i});
	sort(ALL(VV));
	int pre=0;
	FORR(v,VV) {
		
		while(cand.size() && cand.begin()->first<=v.first) {
			x=cand.begin()->second;
			cand.erase(cand.begin());
			dif-=D[x]-pre;
			y=*S.lower_bound(x+1);
			if(y<*S.rbegin()) {
				cand.erase({D[y],y});
				dif-=D[y]-pre;
			}
			S.erase(y);
			auto it=S.lower_bound(x+1);
			if(it==S.end()) continue;
			y=*it;
			assert(x%2==y%2);
			
			
			if((x%2==0 && X[y]>=X[x]) || (x%2==1 && X[y]<=X[x])) {
				if(y<*S.rbegin()) {
					cand.erase({D[y],y});
					dif-=D[y]-pre;
				}
				S.erase(y);
				
				it=S.lower_bound(x+1);
				if(it!=S.end()) {
					D[x]=abs(X[x]-X[*it]);
					cand.insert({D[x],x});
					dif+=D[x]-pre;
				}
			}
			else {
				S.erase(x);
				it=S.lower_bound(y);
				if(it==S.begin()) {
					dif+=abs(X[x]-X[y]);
				}
				else {
					x=*--it;
					cand.erase({D[x],x});
					dif-=D[x]-pre;
					D[x]=abs(X[x]-X[y]);
					cand.insert({D[x],x});
					dif+=D[x]-pre;
				}
			}
		}
		
		dif -= (v.first-pre)*cand.size();
		ret[v.second]=dif;
		pre=v.first;
		
	}
	
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
