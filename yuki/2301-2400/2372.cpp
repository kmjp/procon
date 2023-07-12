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

int N,K,Q;
deque<string> D;

void add(string a) {
	D.push_back(a);
	if(D.size()>N) D.pop_front();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>s;
			add(s);
		}
		else {
			int ok=0;
			string S[6];
			int T[6];
			FOR(i,6) cin>>S[i]>>T[i];
			
			int num=0,sum=0;
			FOR(i,6) {
				int t=T[i];
				FORR(q,D) if(q==S[i]) t=min(T[i],K);
				sum+=t;
				if(sum>60) break;
				num++;
			}
			cout<<num<<endl;
			FOR(i,num) add(S[i]);
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
