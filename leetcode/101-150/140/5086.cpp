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


int mask[5050];

class Solution {
public:
    string smallestSubsequence(string text) {
        ZERO(mask);
        int i,j;
        for(i=text.size()-1;i>=0;i--) {
			mask[i]=mask[i+1];
			mask[i] |= 1<<(text[i]-'a');
		}
		
		int lef=mask[0];
		int cur=-1;
		string S;
		while(lef) {
			FOR(i,26) if(lef&(1<<i)) {
				for(j=cur+1;j<text.size();j++) if(text[j]=='a'+i && (mask[j]&lef)==lef) {
					cur=j;
					lef ^= 1<<i;
					S.push_back('a'+i);
					goto nex;
				}
			}
			nex:
			;
		}
		return S;
		
    }
};

