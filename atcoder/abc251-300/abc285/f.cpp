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

int N,Q;
string S;
set<int> NG;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt[26];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;

	NG.insert(N+1);
	NG.insert(-2);
	FOR(i,N-1) if(S[i]>S[i+1]) NG.insert(i);
	
	FOR(i,N) {
		bt[S[i]-'a'].add(i,1);
	}
	
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>i>>s;
			i--;
			bt[S[i]-'a'].add(i,-1);
			S[i]=s[0];
			bt[S[i]-'a'].add(i,1);
			
			NG.erase(i);
			NG.erase(i-1);
			if(i<N-1&&S[i]>S[i+1]) NG.insert(i);
			if(i&&S[i-1]>S[i]) NG.insert(i-1);
		}
		else {
			int L,R;
			cin>>L>>R;
			L--;
			
			if(L+1==R) {
				cout<<"Yes"<<endl;
				continue;
			}
			
			auto it=NG.lower_bound(L);
			if(*it<R-1) {
				cout<<"No"<<endl;
				continue;
			}
			x=S[L]-'a';
			y=S[R-1]-'a';
			for(i=x+1;i<y;i++) {
				if(bt[i](R-1)-bt[i](L-1)!=bt[i](N)) break;
			}
			if(x==y||i==y) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
			
		}
	}
		
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
