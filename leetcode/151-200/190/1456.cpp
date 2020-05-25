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



int num[101010];
class Solution {
public:
    int maxVowels(string s, int k) {
		int cur=0;
		int ma=0;
		int i;
		ZERO(num);
		FOR(i,s.size()) {
			if(s[i]=='a') cur++;
			if(s[i]=='i') cur++;
			if(s[i]=='u') cur++;
			if(s[i]=='e') cur++;
			if(s[i]=='o') cur++;
			num[i+1]=cur;
			if((i+1)>=k) ma=max(ma,num[i+1]-num[i+1-k]);
			
		}
		return ma;
        
    }
};
