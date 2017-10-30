分别输出排名为$$i$$的后缀的第一个字符在原串中的位置，排名为$$i$$和排名为$$i+1$$的后缀的最长公共前缀的长度。

```cpp
#include <bits/stdc++.h>
#define rep(i,f,t) for(int i=f; i<t; i++)
using namespace std;
const int MAXN = 100000;
int n;
char s[MAXN+10];
int sa[MAXN+10], Rank[MAXN+10], top[MAXN+10], tmp[MAXN+10], height[MAXN+10];
void build_sa()
{
    int m = 130;
    int *x=Rank, *y = tmp;
    rep(i,0,m) top[i]=0;
    rep(i,0,n) top[x[i]=s[i]]++;
    rep(i,1,m) top[i]+=top[i-1];
    for(int i=n-1; i>=0; i--) sa[--top[x[i]]] = i;
    for(int k=1; k<=n; k<<=1)
    {
        int p=0;
        rep(i,n-k,n) y[p++]=i;
        rep(i,0,n) if(sa[i]>=k) y[p++]=sa[i]-k;

        rep(i,0,m) top[i]=0;
        rep(i,0,n) top[x[i]]++;
        rep(i,1,m) top[i]+=top[i-1];
        for(int i=n-1; i>=0; i--) sa[--top[x[y[i]]]] = y[i];

        swap(x, y);

        p=1; x[sa[0]]=0;
        rep(i,1,n)
            x[sa[i]] = (y[sa[i]]==y[sa[i-1]] and y[sa[i]+k]==y[sa[i-1]+k]) ? p-1 : p++;
        m = p;
        if (p >= n) break;
    }
}

void build_height()
{
    int k=0;
    rep(i,0,n) Rank[sa[i]]=i;
    rep(i,0,n)
    {
        if (k) k--;
        if (Rank[i]-1<0) {k=0;continue;}
        int j=sa[Rank[i]-1];
        while(i+k < n and j+k < n and s[i+k]==s[j+k]) k++;
        height[Rank[i]]=k;
    }
}

int main()
{
   scanf("%s", s);
   n = (int)strlen(s)+1;
   build_sa();
   build_height();
   rep(i,1,n) printf(i==1?"%d":" %d", sa[i]+1); puts("");
   rep(i,2,n) printf(i==2?"%d":" %d", height[i]); puts("");
}
```



