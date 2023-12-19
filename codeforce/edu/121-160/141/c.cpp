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

int T,N,M,A[505050];
int win[505050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		vector<pair<int,int>> V;
		FOR(i,N) {
			cin>>A[i];
			win[i]=i+1;
			V.push_back({A[i],-i});
		}
		//¬‚³‚¢‡‚Éí‚¤
		int w=0;
		int ret=0;
		sort(ALL(V));
		int lef=M;
		FORR2(v,i,V) if(lef>=v) {
			w++;
			win[-i]--;
			lef-=v;
		}
		vector<int> T;
		V.clear();
		FOR(i,N) {
			if(win[i]>w) ret++;
			if(win[i]==w+1&&win[i]==i+1) T.push_back(i);
			else V.push_back({A[i],-i});
		}
		sort(ALL(V));
		w=0;
		FOR(i,N) win[i]=i+1;
		FORR(t,T) {
			M-=A[t];
			w++;
			win[t]--;
		}
		if(M>=0) {
			int lef=M;
			FORR2(v,i,V) if(lef>=v) {
				w++;
				win[-i]--;
				lef-=v;
			}
			int ret2=0;
			FOR(i,N) {
				if(win[i]>w) ret2++;
			}
			ret=min(ret,ret2);
		}
		
		
		
		cout<<ret+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
