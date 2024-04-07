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

int T,N;
vector<int> E[202020];

ll tree_normalize(vector<ll> T) {
	static ll momo[2]={1000000007,1000000021};
	
	sort(ALL(T));
	int id=0,id2=1;
	ll a=1,b=1;
	FORR(r,T) {
		ll h=r>>32, l=r-(h<<32);
		(a*=h+1)%=momo[0];
		(b*=l+1)%=momo[1];
	}
	return (a<<32)+b;
}

ll dfs(int cur,int pre) {
	vector<ll> h={1};
	FORR(e,E[cur]) if(e!=pre) h.push_back(dfs(e,cur));
	return tree_normalize(h);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		
		int pre=-1;
		int cur=0;
		int ok=1;
		while(1) {
			vector<int> C;
			FORR(c,E[cur]) if(c!=pre) C.push_back(c);
			
			if(C.empty()) break;
			if(C.size()==1) {
				pre=cur;
				cur=C[0];
			}
			else {
				
				map<ll,int> H;
				FORR(e,E[cur]) if(e!=pre) {
					auto h=dfs(e,cur);
					if(H.count(h)) {
						H.erase(h);
					}
					else {
						H[h]=e;
					}
				}
				if(H.size()==0) {
					break;
				}
				if(H.size()>1) {
					ok=0;
					break;
				}
				pre=cur;
				cur=H.begin()->second;
			}
		}
		if(ok) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
