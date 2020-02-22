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

int N;
ll L;
ll X[303030];
ll T[303030];
int P[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	X[N+1]=L;
	for(i=1;i<=N;i++) cin>>X[i];
	
	ll num=0;
	
	deque<int> C[3];
	int lastadd=-1,lastpair=-1,last3=-1;;
	for(i=1;i<=N;i++) {
		cin>>T[i];
		num += T[i]/(2*L);
		T[i]%=2*L;
		
		P[i]|=2*((T[i]==0)||(T[i]>2*(L-X[i])));
		P[i]|=(T[i]==0)||(T[i]>2*X[i]);
		if(P[i]==3) {
			num+=T[i]!=0;
			last3=max(last3,i);
		}
		else if(P[i]==1) {
			if(C[0].size()) {
				num++;
				lastadd=max(lastadd,C[0].front());
				lastpair=max(lastpair,i);
				C[0].pop_front();
			}
			else {
				C[1].push_back(i);
			}
		}
		else if(P[i]==0) {
			if(C[2].size()) {
				num++;
				lastadd=max(lastadd,C[2].front());
				lastpair=max(lastpair,i);
				C[2].pop_front();
			}
			else {
				C[0].push_back(i);
			}
		}
		else {
			C[2].push_back(i);
		}
	}
	
	
	while(C[0].size()>=2) {
		num++;
		lastadd=max(lastadd,C[0].front());
		lastpair=max(lastpair,C[0].back());
		C[0].pop_front();
		C[0].pop_back();
	}
	num+=C[0].size()+C[1].size()+C[2].size();
	if(C[2].size()) {
		num++;
	}
	else {
		x=-1;
		if(C[0].size()) x=max(x,C[0].back());
		if(C[1].size()) x=max(x,C[1].back());
		if(x<lastadd || (last3>lastadd&&last3>lastpair)) num++;
	}
	
	cout<<num*2*L<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
