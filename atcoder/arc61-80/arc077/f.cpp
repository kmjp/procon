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

string S[3];
ll L,R;
ll cnt[103][28];
ll dif[103][28];


vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	return v;
}
string nex(string S) {
	vector<int> V=Zalgo(S);
	
	int l;
	for(l=S.size()/2-1;l>=0;l--) {
		if(V[S.size()-l]>=l) return S.substr(0,S.size()-l)+S.substr(0,S.size()-l);
	}
}
vector<ll> hoge(ll v) {
	vector<ll> ret(26,0);
	int i;
	FOR(i,26) ret[i] = v/S[0].size()*cnt[0][i];
	v%=S[0].size();
	FOR(i,v) ret[S[0][i]-'a']++;
	return ret;
}

vector<ll> hoge2(ll V) {
	vector<ll> ret(26,0);
	int i,j;
	for(i=99;i>=2;i--) {
		if(V>=cnt[i][26]) {
			FOR(j,26) ret[j]+=cnt[i][j]-cnt[i-2][j]/2;
			V-=cnt[i][26]-cnt[i-2][26]/2;
		}
	}
	FOR(i,V) ret[S[2][i]-'a']++;
	return ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S[0]>>L>>R;
	S[1]=nex(S[0]);
	S[2]=nex(S[1]);
	
	FORR(r,S[0]) cnt[0][r-'a']++;
	FORR(r,S[1]) cnt[1][r-'a']++;
	cnt[0][26]=S[0].size();
	cnt[1][26]=S[1].size();
	
	vector<ll> LL,RR;
	if(S[0].size()+S[2].size()==2*S[1].size()) {
		RR=hoge(R);
		LL=hoge(L-1);
	}
	else {
		for(i=2;i<=100;i++) {
			FOR(j,27) {
				cnt[i][j] = min(1LL<<60,cnt[i-1][j]+cnt[i-2][j]);
			}
		}
		RR=hoge2(R);
		LL=hoge2(L-1);
	}
	FOR(i,26) _P("%lld%c",RR[i]-LL[i],(i==25)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
