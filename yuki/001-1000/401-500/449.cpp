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
int L[30];
int T;
string S[101010];
int ID[101010],Q[101010];
unordered_map<string,int> U;
ll sc[101010];
int cn[101010];

vector<pair<ll,int>> V;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;
int num[30];

int score(int A) {
	int B=++num[A];
	return (L[A]*50+(50*L[A])*10/(8+2*B));
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i];
	cin>>T;
	FOR(i,T) {
		cin>>S[i]>>s;
		if(s[0]=='?') Q[i]=-1;
		else Q[i]=s[0]-'A';
		
		if(U.count(S[i])==0) {
			x=U.size();
			U[S[i]]=x;
		}
		ID[i]=U[S[i]];
		
		if(Q[i]>=0) {
			sc[ID[i]]+=score(Q[i]);
			V.push_back({sc[ID[i]],-i});
		}
	}
	
	V.push_back({0,0});
	sort(ALL(V));
	
	ZERO(num);
	ZERO(sc);
	bt.add(0,U.size());
	
	FOR(i,T) {
		if(Q[i]>=0) {
			bt.add(cn[ID[i]],-1);
			sc[ID[i]]+=score(Q[i]);
			cn[ID[i]]=lower_bound(ALL(V),make_pair(sc[ID[i]],-i))-V.begin();
			bt.add(cn[ID[i]],1);
		}
		else {
			cout << bt(1<<19)-bt(cn[ID[i]])+1<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
