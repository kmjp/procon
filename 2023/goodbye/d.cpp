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

int T;
ll N;

map<string,vector<ll>> S[17];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(ll a=1;a<=400000;a++) {
		ll b=a*a;
		string V=to_string(b);
		sort(ALL(V));
		S[V.size()][V].push_back(b);
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		if(N<=11) {
			FORR2(a,b,S[N]) if(b.size()>=N) {
				FOR(i,N) cout<<b[i]<<endl;
				break;
			}
		}
		else if(N<=15){
			int lef=N;
			for(x=N-1;x>0;x-=2) if(lef) {
				string S=string(N,'0');
				S[0]='1';
				S[x]='9';
				S[x/2]='6';
				lef--;
				cout<<S<<endl;
			}
			string S="196"+string(N-3,'0');
			lef--;
			cout<<S<<endl;
			for(x=N-1;x>0;x-=2) if(lef) {
				string S=string(N,'0');
				S[0]='9';
				S[x]='1';
				S[x/2]='6';
				lef--;
				cout<<S<<endl;
			}
			assert(lef==0);
		}
		else {
			int lef=N;
			for(x=2;x<=N-2;x+=2) for(y=x+2;y<=N-2;y+=2) {
				if(lef==0) break;
				if(x*2==y) continue;
				string S=string(N,'0');
				S[0]=S[x]=S[y]='1';
				S[x/2]=S[y/2]=S[(x+y)/2]='2';
				cout<<S<<endl;
				lef--;
			}
			assert(lef==0);
		}
		
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
