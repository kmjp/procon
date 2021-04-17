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


int T;
int N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		int C[2]={};
		FORR(c,S) C[c-'a']++;
		
		if(C[1]==0||C[0]==0) {
			cout<<S<<endl;
			continue;
		}
		
		if(S.back()=='a') {
			vector<int> V;
			int cur=0;
			int sum=0,single=0;
			FORR(c,S) {
				if(c=='a') {
					cur++;
				}
				else {
					if(cur>1) sum+=cur-2;
					else if(cur==1) single^=1;
					cur=0;
				}
			}
			sum+=cur-single;
			cout<<string(C[1],'b')+string(sum,'a')<<endl;
		}
		else {
			string ret=S;
			
			FOR(k,2) {
				vector<pair<char,int>> V;
				FORR(c,S) {
					if(V.empty()||V.back().first!=c) V.push_back({c,0});
					V.back().second++;
				}
				x=-1;
				for(i=V.size()-1;i>=0;i--) if(V[i].first=='a') {
						if(k==0){
							if(x==-1) x=i;
							else if(V[i].second>1) {
								V[x].second+=V[i].second-2;
								V[i].second=0;
							}
						}
						else {
							if(V[i].second>1) {
								if(x==-1) x=i;
								else {
									V[x].second+=V[i].second-2;
									V[i].second=0;
								}
							}
						}
					}
				}
				x=-1;
				FOR(i,V.size()) if(V[i].first=='a'&&V[i].second==1) {
					if(x==-1) x=i;
					else V[i].second=V[x].second=0,x--;
				}
				if(x>=0) FOR(i,V.size()) if(V[i].first=='a'&&V[i].second>1) V[i].second--,V[x].second--,x=-1;
				string G;
				FORR(v,V) G+=string(v.second,v.first);
				ret=max(ret,G);
				FOR(i,G.size()) if(G[i]=='a') {
					int len=0;
					FOR(len,G.size()) if(G[i+len]!='a') break;
					
					ret=max(ret,string(i,'b')+string(len%2,'a')+string(G.size()-len-i,'b'));
					
					if(i) {
						string G2=G;
						G2.pop_back();
						G2.erase(G2.begin()+i-1);
						reverse(G2.begin()+i-1,G2.end());
						ret=max(ret,G2);
					}
					break;
				}
			}
			cout<<ret<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
