Splay

eg.给出n个整数，每个数在long long范围内，把这些数升序排序后，从1开始编号，相同的数编同一个号。然后按输入顺序输出这些数的编号。

```cpp
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
typedef long long LL;
#define MAXN 100000
struct Node
{
    LL key; //关键字
    int cnt; //个数
    int sz;  //当前树节点数
 
    Node* ch[2]; //左右儿子
    Node* fa;
 
    Node(){}
 
    Node(LL i, int j, int k)
    {
        key = i; cnt = j; sz = k;
    }
 
    void Update()
    {
        sz = cnt + ch[0]->sz + ch[1]->sz;
    }
 
    int cmp(const LL v)
    {
        if (key == v) return -1;
        return v < key ? 0 : 1;
    }
};
Node nil(0, 0, 0), *NIL = &nil;
struct Splay_Tree
{
    Node* root; //树根
    Node* n_cnt; //节点内存开始地址
    Node data[MAXN+10]; //节点数据
 
    //动静结合申请新节点
    Node* NewNode(LL i = 0, int j = 1, int k = 1)
    {
        Node *p = ++n_cnt;
        p->key = i; p->cnt = j; p->sz = k;
        p->ch[0] = p->ch[1] = p->fa = NIL;
        return p;
    }
 
    void init(const int argc)
    {
        n_cnt = data;
        root = NIL;
        root->ch[0] = root->ch[1] = NIL;
    }
 
    //d=0:左旋 ZAG  d=1:右旋 ZIG
    void Rotate(Node* x, int d)
    {
        Node* y = x->fa;
        y->ch[!d] = x->ch[d];
        if (x->ch[d] != NIL) x->ch[d]->fa = y;
        x->fa = y->fa;
        if (y->fa != NIL) y->fa->ch[y->fa->ch[1] == y] = x;
        x->ch[d] = y;
        y->fa = x;
        if (y == root) root = x;
        y->Update();
        x->Update();
    }
 
    //把x伸展到rt之下
    void splay(Node* x, const Node *target)
    {
        Node *y, *z;
        while (x->fa != target)
        {
            y = x->fa;
            z = y->fa;
            if (z == target)
            {
                if (x == y->ch[0]) Rotate(x, 1);
                else Rotate(x, 0);
            }
            else
            {
                if (y == z->ch[0])
                    if (x == y->ch[0])
                        Rotate(y, 1), Rotate(x, 1);
                    else
                        Rotate(x, 0), Rotate(x, 1);
                else
                    if (x == y->ch[0])
                        Rotate(x, 1), Rotate(x, 0);
                    else Rotate(y, 0), Rotate(x, 0);
            }
            x->Update();
        }
    }
 
    //插入值为val的结点
    void insert(Node * &target, const LL val, Node *F)
    {
        if (target == NIL)
        {
            target = NewNode();
            target->key = val;
            target->fa = F;
            //splay(target, NIL);
            return ;
        }
        int d = target->cmp(val);
        if (d == -1)
        {
            target->cnt++;
            target->sz++;
            target->Update();
            //splay(target, NIL);
            return ;
        }
        target->sz++;
        insert(target->ch[d], val, target);
    }
 
    Node* Find_key(Node *target, LL key)
    {
        if (target == NIL) return NIL;
        if (key == target->key)
        {
            //splay(target, NIL);
            return target;
        }
        if (key > target->key) return Find_key(target->ch[1], key);
        else return Find_key(target->ch[0], key);
    }
 
    //Node* Find_d(Node* &x, int d)
    //{
    //
    //    while (x->ch[d] != NIL ) x = x->ch[d];
    //    return x;
    //}
 
    void Del(const LL key)
    {
        if (root == NIL) return ;
        Node* x = Find_key(root, key);
        if (x == NIL) return ;
        if (x->cnt > 1)
        {
            x->cnt--;
            x->sz--;
            splay(x, NIL);
            return ;
        }
        x->sz = 0;
        while (x->ch[0] != NIL || x->ch[1] != NIL)
        {
            if (x->ch[0] != NIL) splay(x->ch[0], x->fa);
            if (x->ch[1] != NIL) splay(x->ch[1], x->fa);
            //if (x->ch[0] == NIL && x->ch[1] == NIL) break;
        }
        if (x == root)
        {
            root = NIL;
            return ;
        }
        x->fa->Update();
        //if (x->fa->ch[0] == x) x->fa->ch[0] = NIL;
        //if (x->fa->ch[1] == x) x->fa->ch[1] = NIL;
        x->fa->ch[x->fa->ch[1] == x] = NIL;
        splay(x->fa, NIL);
    }
 
    int Find_rank(Node* target, const LL key)
    {
        if (target == NIL) return 0;
        if (key == target->key)
            return 1 + target->ch[0]->sz;
        if (key < target->key)
            return Find_rank(target->ch[0], key);
        if (key > target->key)
            return target->ch[0]->sz + target->cnt + Find_rank(target->ch[1], key);
        return 0;
    }
 
    LL Find_kth(Node* target, const LL k, int left)
    {
        if (target == NIL) return -1;
        if (left + target->ch[0]->sz >= k)
            return Find_kth(target->ch[0], k, left);
        if (left + target->cnt + target->ch[0]->sz >= k)
            return target->key;
        if (left + target->ch[0]->sz + target->cnt < k)
            return Find_kth(target->ch[1], k, left + target->ch[0]->sz + target->cnt);
        return -1;
    }
 
    void dfs(Node *rt)
    {
        if (rt == NIL) return ;
        dfs(rt->ch[0]);
        for (int i = 1; i<= rt->cnt; i++)
            printf("%I64d\n", rt->key);
        dfs(rt->ch[1]);
    }
 
    /** public functions **/
 
    void init()
    {
        init(0);
    }
 
    //插入一个值为val的节点
    void insert(const LL val)
    {
        insert(root, val, NIL);
    }
 
    //给定一个值，删除这个节点
    void erase(const LL key)
    {
        Del(key);
    }
 
    //给定一个排名，返回它的值
    LL Find_kth(const int k)
    {
        return Find_kth(root, k, 0);
    }
 
    //给定一个值，返回它的排名
    int Find_rank(const LL key)
    {
        return Find_rank(root, key);
    }
 
    //给定一个值，返回它的指针
    Node* Find_key(LL key)
    {
        return Find_key(root, key);
    }
 
    int Find_prev(const LL key)
    {
        insert(key);
        int k = Find_rank(key);
        int ret = Find_kth(k-1);
        erase(key);
        return ret;
    }
 
    int Find_next(const LL key)
    {
        insert(key);
        Node* p = Find_key(key);
        int k = Find_rank(key);
        int ret = Find_kth(k + p->cnt);
        erase(key);
        return ret;
    }
 
    //调试
    void debug()
    {
        #ifndef ONLINE_JUDGE
        printf("\n==SPLAY DEBUG==\n");
        dfs(root);
        printf("\n===============\n");
        #endif
    }
};
 
Splay_Tree sp;
 
inline void GET(int& a)
{
    scanf("%d", &a);
}
 
inline void PUT(const int a)
{
    printf("%d\n", a);
}
 
LL A[MAXN+10];
 
void GET(LL&);
 
void work()
{
    sp.init();
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        GET(A[i]);
        if (NIL == sp.Find_key(A[i]))
            sp.insert(A[i]);
    }
    sp.debug();
    for (int i=1; i<=n; i++)
    {
        printf("%d\n", sp.Find_rank(A[i]));
    }
}
 
int main()
{
    sp.init();
    work();
}
 
bool flag;
char c;
 
void GET(LL& ret)
{
    ret = 0;
    flag=false;
    for(;c=getchar(),c<'0'||c>'9';)
        if(c=='-')
            flag=true;
    for(ret=c-'0';c=getchar(),c>='0'&&c<='9';)
        ret=ret*10+c-'0';
    if(flag)
        ret=-ret;
    ungetc(c,stdin);
}
```



