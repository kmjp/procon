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
    string robotWithString(string s) {
		int N=s.size();
		int C[26];
		int nex[N];
		int i,j;
		FOR(i,26) C[i]=N+1;
		for(i=N-1;i>=0;i--) {
			nex[i]=N;
			FOR(j,s[i]-'a') if(C[j]<N) {
				nex[i]=C[j];
				break;
			}
			C[s[i]-'a']=i;
		}
		
		string t,r;
		FOR(i,N) {
			if(nex[i]<N) {
				while(t.size()&&t.back()<=s[nex[i]]) {
					r+=t.back();
					t.pop_back();
				}
				
				
				for(j=i;j<nex[i];j++) {
					t.push_back(s[j]);
				}
				i=nex[i]-1;
			}
			else {
				while(t.size()&&t.back()<=s[i]) {
					r+=t.back();
					t.pop_back();
				}
				r+=s[i];
			}
		}
		while(t.size()) r+=t.back(),t.pop_back();
		
		return r;
        
    }
};
