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

int nex[55555][26];
int num[55555];

class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int N=s.size();
        int i,j;
        FOR(i,26) nex[N][i]=N;
        num[N]=0;
        for(i=N-1;i>=0;i--) {
			FOR(j,26) nex[i][j]=nex[i+1][j];
			nex[i][s[i]-'a']=i;
			num[i]=num[i+1];
			if(s[i]==letter) num[i]++;
		}
		
		string ret;
		int cur=0;
		int nu=0;
		while(ret.size()<k) {
			if(k-ret.size()==repetition-nu) {
				ret+=letter;
				nu++;
				continue;
			}
			FOR(i,26) {
				int ne=nex[cur][i];
				if(ne==N) continue;
				if(nu+num[ne]<repetition) continue;
				if(ret.size()+N-ne<k) continue;
				ret+='a'+i;
				cur=ne+1;
				if('a'+i==letter) nu++;
				break;
			}
		}
		return ret;
    }
};
