# 线段树

```cpp
const int MAXRANGE = 100050;    //范围[1,MAXRANGE]
int maxt[MAXRANGE*8];
int lazy[MAXRANGE*8];

inline void update(int t,int l,int r)    //push标记，注意push后子节点答案先更新，本节点答案不变
{
    lazy[t<<1]+=lazy[t];
    lazy[t<<1|1]+=lazy[t];
    maxt[t<<1]+=lazy[t];
    maxt[t<<1|1]+=lazy[t];
    lazy[t]=0;
}

void add(int t,int l,int r,int L,int R,int val)    //将[L,R] += val
{
    update(t,l,r);
    if(l==L&&r==R)
    {
        lazy[t]+=val;
        maxt[t]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(mid>=R)
        add(t<<1,l,mid,L,R,val);
    else if(mid<L)
        add(t<<1|1,mid+1,r,L,R,val);
    else
    {
        add(t<<1,l,mid,L,mid,val);
        add(t<<1|1,mid+1,r,mid+1,R,val);
    }
    maxt[t]=max(maxt[t<<1],maxt[t<<1|1]);
}

int query(int t,int l,int r,int L,int R)    //询问max[L,R]
{
    update(t,l,r);
    if(l==L&&r==R)
        return maxt[t];
    int mid=(l+r)>>1;
    if(mid>=R)
        return query(t<<1,l,mid,L,R);
    else if(mid<L)
        return query(t<<1|1,mid+1,r,L,R);
    else
    {
        return max(
            query(t<<1,l,mid,L,mid),
            query(t<<1|1,mid+1,r,mid+1,R)
        );
    }
}
```



