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

int P[202020];
int ask(int a,int b) {
	cout<<"? "<<a<<" "<<b<<endl;
	cin>>a;
	assert(a!=-1);
	return a;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		P[1]=0;
		set<int> S={1};
		int pre=0;
		for(i=2;i<N;i++) {
			if(S.count(1)) {
				if(ask(i,1)) {
					S.insert(i);
					P[i]=0;
				}
				else {
					S.insert(i);
					P[i]=1;
					S.erase(1);
				}
			}
			else {
				P[i]=-1;
				while(S.size()>1) {
					x=*S.begin();
					if(ask(x,i)==0) {
						S.erase(x);
						P[i]=x;
						S.insert(i);
						break;
					}
					S.erase(S.begin());
				}
				if(P[i]==-1) {
					assert(S.size()==1);
					x=*S.begin();
					S.erase(x);
					P[i]=x;
					S.insert(i);
				}
			}
		}
		cout<<"!";
		for(i=1;i<N;i++) cout<<" "<<P[i];
		cout<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
