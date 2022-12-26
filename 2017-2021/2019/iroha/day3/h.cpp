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
int Q;
string C;
ll E;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>C>>E;
		if(E==0) {
			if(C=="a") cout<<"a"<<endl;
			else cout<<"aa"<<endl;
			continue;
		}
		set<string> S;
		FOR(i,60) {
			if(E%(1LL<<i)==0) {
				ll v=E>>i;
				if(v<=25) {
					string R;
					char cur='a';
					FOR(j,v) {
						if(C[0]==cur) cur++;
						R.push_back(cur++);
					}
					FOR(j,i) R.push_back(C[0]);
					sort(ALL(R));
					S.insert(R);
				}
			}
		}
		
		if(S.empty()) cout<<-1<<endl;
		else cout<<*S.begin()<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
