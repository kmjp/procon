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


int T,N;
pair<int,int> P[30303];
ll tmp[303030];

ll myhash(int a,int b) {
	return ((ll)a<<32)+b;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> xs;
		FOR(i,N) cin>>P[i].first>>P[i].second, xs.insert(P[i].first);
		int ret=xs.size();
		sort(P,P+N);
		
		if(N<=810) {
			unordered_map<ll,vector<int>> did;
			FOR(y,N) FOR(x,y) {
				if(P[x].first==P[y].first) continue;
				int a=P[y].second-P[x].second;
				int b=P[y].first-P[x].first;
				
				int g=__gcd(a,b);
				did[myhash(a/g,b/g)].push_back(y);
			}
			
			FORR(r,did) {
				sort(ALL(r.second));
				r.second.erase(unique(ALL(r.second)),r.second.end());
				ret=min(ret,N-(int)r.second.size());
			}
			
		}
		else {
			vector<pair<int,int>> cand;
			FOR(y,800) FOR(x,y) {
				int a=P[x].second-P[y].second;
				int b=P[x].first-P[y].first;
				if(b==0) continue;
				int g=__gcd(a,b);
				cand.push_back({a/g,b/g});
			}
			sort(ALL(cand));
			cand.push_back({0,0});
			
			int prev=-1;
			for(i=1;i<cand.size();i++) if(cand[i]!=cand[i-1]) {
				int num=(i-1)-prev;
				if(num>=400) {
					ll a=cand[i-1].first, b=cand[i-1].second;
					FOR(j,N) tmp[j]=P[j].second*b-a*P[j].first;
					sort(tmp,tmp+N);
					x=unique(tmp,tmp+N)-tmp;
					ret=min(ret,x);
				}
				prev=i-1;
			}
		}
		cout<<ret<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
