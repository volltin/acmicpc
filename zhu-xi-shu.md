# 主席树

### 普通版本

先建好整棵树，再进行处理。配合离散化可解决大部分问题。

```cpp
const int SEGPOOLSIZE = 1e7;    //线段树节点个数，一般可按 4*(VERSIONSIZE*logn + nlogn) 作为上界估计
const int VERSIONSIZE = 100050;    //版本数

struct Node{
    int l,r;
    int value;
    Node *lson, *rson;
};

Node pool[SEGPOOLSIZE];
int pt = 0;

Node* newNode(int l, int r){
    pool[pt].l = l;
    pool[pt].r = r;
    pool[pt].lson = pool[pt].rson = NULL;
    pool[pt].value = 0;
    return &pool[pt++];
}

Node* root[VERSIONSIZE];
int rt=0;

inline void update(Node *t){    //根据子节点更新的方法
    t->value = t->lson->value + t->rson->value;
}

void build(Node *t = root[0]){
    if(t->l == t->r){
        t->value=0;  //这里设置value的初始值
        return;
    }
    int mid = (t->l + t->r) >> 1;
    t->lson = newNode(t->l, mid);
    t->rson = newNode(mid + 1 , t->r);
    build(t->lson);
    build(t->rson);
    update(t);
}

int query(Node *t, int ql, int qr){      //单版本的查询
    if(t->l == ql && t->r == qr)
    {
        return t->value;
    }
    int mid = (t->l + t->r)>>1;
    if(qr <= mid)
        return query(t->lson, ql, qr);
    else if(mid < ql)
        return query(t->rson, ql, qr);
    else{   //这个部分也要按照具体情况更改
        int v1 = query(t->lson, ql, mid);
        int v2 = query(t->rson, mid+1, qr);
        return v1 + v2;
    }
}

int query(Node *t, Node* u, int k){   //可以同时查询多个版本，这里查询的是树t - u 上的区间k大
    if(t->l == t->r){
        return t->l;
    }
    int leftSum = (t->lson->value - u->lson->value);
    if(leftSum >= k )
        return query(t->lson, u->lson, k);
    else
        return query(t->rson, u->rson, k-leftSum);
}

void change(Node *t, Node *old, int pos, int value){
    if(t->l == t->r){
        t->value += value;
        return;
    }
    int mid = (t->l + t->r) >> 1;
    if(pos <= mid){
        t->lson = newNode(t->l, mid);
        t->rson = old->rson;
        change(t->lson, old->lson, pos, value);
    }
    else{
        t->lson = old->lson;
        t->rson  = newNode(mid + 1, t->r);
        change(t->rson, old->rson, pos, value);
    }
    update(t);
}

int change(int pos,int value){    //方便调用的接口，返回的是修改完后的版本号
    root[rt]=newNode(root[rt-1]->l, root[rt-1]->r);
    change(root[rt], root[rt-1], pos, value);
    return rt++;
}

inline void init(int rangeST, int rangeED){  //每个数据先调用init，无需手动调用build
    pt=0;
    rt=0;
    root[rt++] = newNode(rangeST,rangeED);
    build();
}
```



