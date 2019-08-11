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

class Solution {
	public:

    bool canConvert(string str1, string str2) {
		int mp[26]={};
		int i;
		int tar=0;
		int dif=0;
		
		FOR(i,str1.size()) {
			int x=str1[i]-'a';
			int y=str2[i]-'a';
			if(x!=y) dif++;
			tar|=1<<y;
			mp[x]|=1<<y;
		}
		
		int num=0;
		FOR(i,26) {
			if(__builtin_popcount(mp[i])>1) return 0;
			if(__builtin_popcount(mp[i])==1) num++;
		}
		
		if(num==26 && tar==(1<<26)-1 && dif) return 0;
		
		return 1;
        
    }
    


};

