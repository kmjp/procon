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

int T,N,M;
string S;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> c,bt2,bt3;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>s;
		FOR(i,N+5) {
			bt2.add(i,-bt2(i));
			bt3.add(i,-bt3(i));
			c.add(i,-c(i));
		}
		FOR(i,N-1) {
			c.add(i+3,s[i+1]-s[i]+26);
		}
		FOR(i,N-1) if(s[i]==s[i+1]) bt2.add(i+3,1);
		FOR(i,N-2) if(s[i]==s[i+2]) bt3.add(i+4,1);
		while(M--) {
			int L,R;
			cin>>i>>L>>R;
			L++;
			R++;
			if(i==1) {
				cin>>x;
				x%=26;
				if((c(L)-c(L-1))%26==0) bt2.add(L,-1);
				if((c(L)-c(L-2))%26==0) bt3.add(L,-1);
				if(L!=R) if((c(L+1)-c(L-1))%26==0) bt3.add(L+1,-1);
				if((c(R+1)-c(R))%26==0) bt2.add(R+1,-1);
				if(L!=R) if((c(R+1)-c(R-1))%26==0) bt3.add(R+1,-1);
				if((c(R+2)-c(R))%26==0) bt3.add(R+2,-1);
				c.add(L,x);
				c.add(R+1,-x);
				if((c(L)-c(L-1))%26==0) bt2.add(L,1);
				if((c(L)-c(L-2))%26==0) bt3.add(L,1);
				if(L!=R) if((c(L+1)-c(L-1))%26==0) bt3.add(L+1,1);
				if((c(R+1)-c(R))%26==0) bt2.add(R+1,1);
				if(L!=R) if((c(R+1)-c(R-1))%26==0) bt3.add(R+1,1);
				if((c(R+2)-c(R))%26==0) bt3.add(R+2,1);
				
			}
			else {
				x=bt2(R)-bt2(L);
				x+=bt3(R)-bt3(L+1);
				if(x&&L<R) {
					cout<<"NO"<<endl;
				}
				else {
					cout<<"YES"<<endl;
				}
				
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
