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

int N,M,Q;
string S;
char D[202020],F[202020];
int T[202020],P[202020];
vector<int> ev[202020];
int L[202020],R[202020];
int ret[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>M;
	L[0]=200000;R[0]=200000+N-1;
	FOR(i,M) {
		string a,b;
		cin>>a>>b;
		D[i]=a[0];
		F[i]=b[0];
		L[i+1]=L[i]-(D[i]=='L');
		R[i+1]=R[i]+(D[i]=='R');
	}
	
	deque<pair<char,int>> DQ;
	FOR(i,N) {
		if(i==0) {
			DQ.push_back({S[i],L[0]});
			if(S[i]=='B') bt.add(L[0],1);
		}
		else if(S[i]!=S[i-1]) {
			DQ.push_back({S[i],L[0]+i});
			bt.add(L[0]+i,1);
		}
	}
	
	cin>>Q;
	FOR(i,Q) {
		cin>>T[i]>>P[i];
		ev[T[i]].push_back(i);
	}
	
	FOR(i,M) {
		if(D[i]=='L') {
			if(F[i]==DQ.front().first) {
				if(F[i]=='B') bt.add(DQ.front().second,1);
				DQ.front().second--;
			}
			else if(DQ.size()==1) {
				if(F[i]=='B') bt.add(DQ.front().second,1);
				DQ.push_front({F[i],L[i+1]});
			}
			else {
				if(F[i]=='W') bt.add(DQ.front().second,1);
				DQ.pop_front();
				bt.add(DQ.front().second,1);
				DQ.front().second=L[i+1];
			}
			if(F[i]=='B') bt.add(L[i+1],1);
		}
		else {
			if(F[i]==DQ.back().first) {
				;
			}
			else if(DQ.size()==1) {
				DQ.push_back({F[i],R[i+1]});
				bt.add(R[i+1],1);
			}
			else {
				bt.add(DQ.back().second,1);
				DQ.pop_back();
			}
		}
		FORR(e,ev[i+1]) {
			ret[e]=bt(L[i+1]+P[e]-1)%2;
		}
	}
	FOR(i,Q) cout<<"WB"[ret[i]]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
