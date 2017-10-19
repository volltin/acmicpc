zkw 费用流



```cpp
#include <bits/stdc++.h>
using namespace std;
struct mis{
    int st,ed,wt;
}ms[1100];
 
//===========================NetworkCostFlowZkw========
 
struct par
{
  int a, b;
  par(int _a = 0, int _b = 0) : a(_a), b(_b) {}
};
 
const int NCFSmaxn = 2005; //最大节点数
const int NCFSmaxm = 2000005; //最大边数
const int NCFSinf_ = 0x7f; //最大权值的两位 如(0x7f)
const int NCFSinf  = 0x7f7f7f7f; //最大权值必为NCFSinf_的满状态 如（0x7f7f7f7f)
 
struct NCFS_Line
{
  int fr, to, next, v, c, opt;
};
 
struct Network_Cost_Flow_Spfa
{
  NCFS_Line li[NCFSmaxm];
  int be[NCFSmaxn], l, s, t, n, dist[NCFSmaxn], fa[NCFSmaxn], b[NCFSmaxn];
  deque<int> q;
 
  void makeline(int fr, int to, int v, int c)
  {
    ++l;
    li[l].next = be[fr];
    be[fr] = l;
    li[l].fr = fr;
    li[l].to = to;
    li[l].v = v;
    li[l].c = c;
    li[l].opt = l + 1;
 
    ++l;
    li[l].next = be[to];
    be[to] = l;
    li[l].fr = to;
    li[l].to = fr;
    li[l].v = 0;
    li[l].c = -c;
    li[l].opt = l - 1;
  }
 
  void create(int N)
  {
    n = N;
  }
 
  void clear()
  {
    l = s = t = n = 0;
    memset(be, 0, sizeof(be));
  }
 
  bool spfa()
  {
    memset(dist, NCFSinf_, sizeof(dist));
    memset(fa, 0, sizeof(fa));
    dist[t] = 0;
    b[t] = 1;
    q.push_back(t);
    while (!q.empty())
    {
      int now = q.front();
      q.pop_front();
      for (int i = be[now]; i; i = li[i].next)
      {
        int to = li[i].to;
        if (!li[li[i].opt].v || dist[to] <= dist[now] - li[i].c) continue;
        dist[to] = dist[now] - li[i].c;
        fa[to] = i;
        if (!b[to])
        {
          b[to] = 1;
          if (!q.empty() && dist[to] < dist[q.front()]) q.push_front(to);
          else q.push_back(to);
        }
      }
      b[now] = 0;
    }
    return dist[s] != NCFSinf;
  }
  par query(int S, int T)
  {
    par ans;
    ans.a = ans.b = 0;
    s = S, t = T;
    int kase = 3;
    while (--kase && spfa())
    {
      int mi = NCFSinf;
      for (int i = s; i != t; i = li[fa[i]].fr)
        mi = min(mi, li[li[fa[i]].opt].v);
      for (int i = s; i != t; i = li[fa[i]].fr)
      {
        li[fa[i]].v += mi;
        li[li[fa[i]].opt].v -= mi;
        ans.b -= mi * li[fa[i]].c;
      }
      ans.a += mi;
    }
    return ans;
  }
} ac;
 
//===========================NetworkCostFlowZkw========
int main()
{
    int n,s,i,j,st,ed; 
    while(scanf("%d",&n) && n)
    { 
        ac.clear();
        s = 0;
        st = 2*n+1;
        ed = 2*n+2;
        for(i = 1;i <= n;i++)
            scanf("%d%d%d",&ms[i].st,&ms[i].ed,&ms[i].wt);  
        for(i = 1;i <= n;i++)
            for(j = 1;j <= n;j++)
                if(ms[i].ed < ms[j].st)
                    ac.makeline(i+n,j,1,0);
        ac.makeline(s,st,2,0);
        for(i = 1;i <= n;i++)
        {
            ac.makeline(i,i+n,1,-ms[i].wt);
            ac.makeline(st,i,1,0);
            ac.makeline(i+n,ed,1,0);
        }
        printf("%d\n",-ac.query(s,ed).b); 
    }
}
```



