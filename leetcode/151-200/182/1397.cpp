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


int stt[52][26];
const char base='a';
void CreateSTT(string& pat) {
	int x,y,z,l;
	ZERO(stt);
	l=pat.size();
	FOR(x,l) {
		FOR(y,26) {
			if(base+y == pat[x]) stt[x][y]=x+1;
			else {
				string pre=pat.substr(0,x)+(char)(base+y);
				for(z=1;z<=x;z++) if(pre.substr(pre.size()-z) == pat.substr(0,z)) stt[x][y]=z;
			}
		}
	}
	FOR(y,26) stt[l][y]=l;
}

int N;
ll dp[505][52][2][2];
const ll mod=1000000007;
string S1,S2,E;

class Solution {
public:
	ll hoge(int cur,int ev,int mo,int le) {
		if(cur==N) return (ev<E.size());
		ll& ret=dp[cur][ev][mo][le];
		if(ret>=0) return ret;
		ret=0;
		int i;
		FOR(i,26) {
			if(mo==0 && i<S1[cur]-'a') continue;
			if(le==0 && i>S2[cur]-'a') continue;
			int nmo=mo | (i>S1[cur]-'a');
			int nle=le | (i<S2[cur]-'a');
			int nev=stt[ev][i];
			ret+=hoge(cur+1,nev,nmo,nle);
		}
		ret%=mod;
		return ret;
	}
	
    int findGoodStrings(int n, string s1, string s2, string evil) {
		MINUS(dp);
		CreateSTT(evil);
		S1=s1;
		S2=s2;
		E=evil;
		N=n;
		return hoge(0,0,0,0);
        
    }
};
