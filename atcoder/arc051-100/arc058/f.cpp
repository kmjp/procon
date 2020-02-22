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

int N,K;
string S[2020];
string CS[2020];
int can[2020][10101];

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

pair<int,int> getmin(string& t,int a,int b,vector<int>& z,pair<int,int> L,pair<int,int> R) {
	
	//_P("%s : %d %d L:(%d:%d) R:(%d:%d)\n",t.c_str(),a,b,L.first,L.second,R.first,R.second);
	if(L.second==0) {
		int x=z[a+R.first];
		if(x>=a) return L;
		if(a+R.first+x==a+b) return R;
		if(t[x]<t[a+R.first+x]) return R;
		else return L;
	}
	else {
		if(L==R) return L;
		if(L.first>R.first) swap(L,R);
		int x=z[a+L.first];
		if(x>=a) return R;
		if(a+L.first+x==a+b) {
			int d=R.first-L.first;
			int y=z[d];
			if(y>=(a-d)) return R;
			if(t[d+y]<t[y]) return L;
			return R;
		}
		else {
			if(t[x]<t[a+L.first+x]) return L;
			else return R;
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>S[i];
	
	can[N][K]=1;
	for(i=N-1;i>=1;i--) {
		for(j=0;j<=K;j++) {
			can[i][j] |= can[i+1][j];
			if(j>=S[i].size()) can[i][j-S[i].size()] |= can[i+1][j];
		}
	}
	can[0][0]=1;
	
	FOR(i,N) {
		if(i>2) CS[i-2].clear();
		string T=S[i]+CS[i];
		vector<int> Z=Zalgo(T);
		
		pair<int,int> cur={CS[i].size(), 0};
		
		for(j=0;j<=K;j++) if(can[i][j] && j+S[i].size()<=K && can[i+1][j+S[i].size()]) {
			cur=getmin(T,S[i].size(),CS[i].size(),Z,cur,{j,1});
		}
		
		if(cur.second==0) {
			CS[i+1]=CS[i];
			FOR(j,K+1) can[i+1][j] &= can[i][j];
		}
		else {
			CS[i+1]=CS[i].substr(0,cur.first)+S[i];
			FOR(j,K+1) if(can[i+1][j]) {
				if(j>CS[i+1].size()) can[i+1][j]=0;
				if(j<CS[i+1].size()) {
					string tt="{";
					if(can[i][j]) tt=CS[i].substr(0,j);
					if(j>=S[i].size() && can[i][j-S[i].size()]) tt=min(tt,CS[i].substr(0,j-S[i].size())+S[i]);
					if(tt>CS[i+1]) can[i+1][j]=0;
				}
			}
		}
	}
	
	cout<<CS[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
