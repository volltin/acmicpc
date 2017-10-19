莫队算法  
如果我们已知\[l,r\]的答案，能在O\(1\)时间得到\[l+1,r\]的答案以及\[l,r-1\]的答案，即可使用莫队算法。时间复杂度为O\(n^1.5\)。如果只能在logn的时间移动区间，则时间复杂度是O\(n^1.5\*log n\)。  
其实就是找一个数据结构支持插入、删除时维护当前答案。

这道题的话我们很容易用数组来实现，做到O\(1\)的从\[l,r\]转移到\[l,r+1\]与\[l+1,r\]。

那么莫队算法怎么做呢？以下都是在转移为O\(1\)的基础下讨论的时间复杂度。另外由于n与m同阶，就统一写n。  
如果已知\[l,r\]的答案，要求\[l’,r’\]的答案，我们很容易通过\|l – l’\|+\|r – r’\|次转移内求得。  
将n个数分成sqrt\(n\)块。  
按区间排序，以左端点所在块内为第一关键字，右端点为第二关键字，进行排序，也就是以\(pos \[l\]，r\)排序  
然后按这个排序直接暴力，复杂度分析是这样的：  
1、i与i+1在同一块内，r单调递增，所以r是O\(n\)的。由于有n^0.5块,所以这一部分时间复杂度是n^1.5。  
2、i与i+1跨越一块，r最多变化n，由于有n^0.5块，所以这一部分时间复杂度是n^1.5  
3、i与i+1在同一块内时l变化不超过n^0.5，跨越一块也不会超过n^0.5，忽略\*2。由于有m次询问（和n同级），所以时间复杂度是n^1.5  
于是就是O\(n^1.5\)了

```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define N 50001
#define ll long long
using namespace std;
int n,m,pos[N],c[N];
ll s[N],ans;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
ll sqr(ll x){return x*x;}
struct data{int l,r,id;ll a,b;}a[N];
bool cmp(data a,data b)
{
	if(pos[a.l]==pos[b.l])return a.r<b.r;
	return a.l<b.l;
}
bool cmp_id(data a,data b)
{return a.id<b.id;}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	    scanf("%d",&c[i]);
	int block=int(sqrt(n));
	for(int i=1;i<=n;i++)
	   pos[i]=(i-1)/block+1;
	for(int i=1;i<=m;i++)
	{
	    scanf("%d%d",&a[i].l,&a[i].r);
	    a[i].id=i;
	    }
}
void update(int p,int add)
{
	ans-=sqr(s[c[p]]);
	s[c[p]]+=add;
	ans+=sqr(s[c[p]]);
}
void solve()
{
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		for(;r<a[i].r;r++)
			update(r+1,1);
		for(;r>a[i].r;r--)
		    update(r,-1);
		for(;l<a[i].l;l++)
		    update(l,-1);
		for(;l>a[i].l;l--)
		    update(l-1,1);
		if(a[i].l==a[i].r)
		{
			a[i].a=0;a[i].b=1;
			continue;
		}
		a[i].a=ans-(a[i].r-a[i].l+1);
		a[i].b=(ll)(a[i].r-a[i].l+1)*(a[i].r-a[i].l);
		ll k=gcd(a[i].a,a[i].b);
		a[i].a/=k;a[i].b/=k;
	}
}
int main()
{
	init();
	sort(a+1,a+m+1,cmp);
	solve();
	sort(a+1,a+m+1,cmp_id);
	for(int i=1;i<=m;i++)
	    printf("%lld/%lld\n",a[i].a,a[i].b);
	return 0;
}
```



