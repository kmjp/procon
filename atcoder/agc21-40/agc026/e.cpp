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
string S;

string hoge(string S) {
	int cnt[6030]={};
	int vis[6030]={};
	vector<int> As,Bs;
	
	int a=0,b=0,i,j;
	FOR(i,S.size()) {
		if(S[i]=='a') {
			cnt[i]=a++;
			As.push_back(i);
		}
		else {
			cnt[i]=b++;
			Bs.push_back(i);
		}
	}
	
	string R;
	
	if(S[0]=='a') {
		FOR(i,S.size()) {
			if(vis[i]==0) {
				R+=S[i];
				if(S[i]=='a') {
					for(int j=i+1;j<Bs[cnt[i]];j++) vis[j]=vis[Bs[cnt[j]]]=1;
				}
			}
		}
	}
	else {
		FOR(i,S.size()/2) {
			string T;
			FOR(j,S.size()) {
				if(cnt[j]>=i) T+=S[j];
			}
			R=max(R,T);
		}
	}
	return R;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	string T;
	vector<string> V;
	
	x=0;
	FORR(c,S) {
		T+=c;
		if(c=='a') x++;
		else x--;
		if(x==0) {
			string P=hoge(T);
			
			while(V.size() && P > V.back()+P) V.pop_back();
			V.push_back(P);
			T="";
		}
	}
	
	FORR(c,V) cout<<c;
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
