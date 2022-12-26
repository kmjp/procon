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

ll N,L,R;
ll S[60];
vector<pair<ll,ll>> C;

ll hoge(ll step) {
	ll cur=0,pos=0;
	while(pos<N) {
		if(pos+1==step || cur==0) {
			pos++;
			cur+=pos;
		}
		else if(cur>=pos+1) {
			pos++;
			cur-=pos;
		}
		else {
			ll npos=pos+2*cur;
			ll stop=min(N,npos);
			
			if(pos<step&&step<=npos) stop=step-1;
			cur-=(stop-pos)/2;
			if((stop-pos)%2) cur+=stop;
			pos=stop;
		}
	}
	return cur;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	ll CN=N;
	FOR(i,20) if(CN>0) {
		C.push_back({CN,1});
		CN--;
	}
	ll cand=CN;
	FOR(i,39) {
		S[i+1]=3*(S[i]+1);
		if(S[i]<CN && i>=3) {
			if(S[i+1]-4<=CN) C.push_back({S[i+1]-4,1}), cand--;
			if(S[i+1]-2<=CN) C.push_back({S[i+1]-2,1}), cand--;
			if(S[i+1]-0<=CN) C.push_back({S[i+1]-0,1}), cand--;
			ll num=0;
			if(CN>=S[i+1]-4) num=((S[i+1]-4)-(S[i]+3))/2;
			else if(CN>=S[i]+3) num=1+(CN-(S[i]+3))/2;
			if(num) {
				C.push_back({S[i]+3,num});
				cand-=num;
			}
		}
	}
	for(j=1;j<=min(S[3],CN);j++) C.push_back({j,1}), cand--;
	
	C.push_back({-2,cand});
	ll ret=0;
	FORR(c,C) {
		ll v=hoge(c.first);
		if(L<=v && v<=R) ret+=c.second;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
