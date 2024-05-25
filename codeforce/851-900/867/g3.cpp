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
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll ret=0;
		M.clear();
		FOR(i,N) {
			cin>>x;
			ret+=3LL*M[x]*(M[x]-1);
			M[x]++;
		}
		vector<pair<int,int>> C;
		FORR2(a,b,M) C.push_back({a,b});
		sort(ALL(C));
		FOR(i,C.size()) {
			int a=C[i].first,b=C[i].second;
			
			if(a<=1000) {
				for(j=i+1;j<C.size();j++) {
					ll d=C[j].first/a;
					if(a>1000000000/(d*d)) break;
					if(C[j].first%a) continue;
					if(M.count(a*d*d)) ret+=1LL*b*C[j].second*M[a*d*d];
				}
			}
			else {
				for(x=2;x<=20000&&1LL*a*x<=1000000000;x++) {
					if(a<=1000*x) break;
					if(M.count(a*x)&&M.count(a/x)&&a%x==0) {
						ret+=1LL*b*M[a/x]*M[a*x];
					}
				}
			}
			
		}
		
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
