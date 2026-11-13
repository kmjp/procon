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

int T,N;
string S;

pair<string,int> hoge(int L,int R) {
	//ìKìñÇ…èÙÇﬁ
	string ret;
	int i;
	for(i=L;i<R;i+=2) {
		ret+=S[i];
		ret+="?";
		ret+=S[i+1];
		ret+=":";
	}
	ret+=S[R];
	
	int cur=S[R]-'0';
	for(i=R-2;i>=L;i-=2) {
		if(S[i]=='1') cur=S[i+1]-'0';
	}
	return {ret,cur};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	FOR(j,T) {
		cin>>N>>S;
		N=S.size();
		
		//äÔêîindexÇÃ0ÇÃëOÇ…ãÙêîindexÇÃ0Ç™óàÇÈ
		int pre=-1;
		FOR(i,N) {
			if(S[i]=='1'&&pre>=0&&i%2&&pre%2==0) {
				cout<<"Yes"<<endl;
				//xxxxxxxz10000001yyyyyy
				string a=hoge(pre+1,i).first; //0000001ÇÃïîï™
				//xxxxxxxz11yyyyyyyy
				//yyyyÇ™1Ç»ÇÁÇªÇÍÇ≈ÇÊÇ¢
				auto b=hoge(i+1,N-1);
				if(b.second) {
					string c=hoge(0,pre).first;
					cout<<"("+c+")?("+a+"):("+b.first+")"<<endl;
					break;
				}
				if(pre==0) {
					cout<<"1?("+a+"):("+b.first+")"<<endl;
					break;
				}
				//xxxxxxxz110
				auto d=hoge(0,pre-2);
				if(d.second==0) {
					//0z110 -> ((0z1)10)
					cout<<"("+d.first+")?"+S[pre-1]+":(1?("+a+"):("+b.first+"))"<<endl;
				}
				else {
					//1z110 -> (1(z11)0)
					cout<<"("+d.first+")?("+S[pre-1]+"?1:("+a+")):("+b.first+")"<<endl;
				}
				break;
				
			}
			
			if(S[i]=='1') pre=i;
		}
		if(i<N) continue;
		if(i==N&&S.back()=='1'&&S!="101") {
			cout<<"Yes"<<endl;
			if(S[0]=='0') {
				cout<<"0?("+hoge(1,N-2).first+"):1"<<endl;
			}
			else { //10....1
				string a=hoge(2,N-3).first;
				cout<<"(1?0:("+a+"))?"+S[N-2]+":1"<<endl;
			}
			continue;
		}
		cout<<"No"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
