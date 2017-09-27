# 字典树

## 指针实现

```cpp
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int TRIEPOOLSIZE = 500050;

struct Node{
    char c;
    int num;
    int sum;    //子树上的单词数（包括自己）
    Node *son[26];  //可跟据字符集数量修改，若修改需要建立一个字符集到编号的映射表
};

Node pool[TRIEPOOLSIZE];
int pt;

Node *newNode(char c)
{
    pool[pt].c=c;
    pool[pt].num = pool[pt].sum = 0;
    memset(pool[pt].son,0,sizeof(pool[pt].son));
    return &pool[pt++];
}

Node *root;

void add(char *str, int n)  //将单词str加入trie，单词长度为n
{
    Node *t=root;
    for(int i=0;i<n;i++){
        t->sum++;
        int ch = str[i]-'a';
        if(t->son[ch]==NULL){
            t->son[ch] = newNode(str[i]);
        }
        t=t->son[ch];
    }
    t->num++;
    t->sum++;
}


int countNum(char *str, int n){
    Node *t=root;
    for(int i=0;i<n;i++){
        int ch = str[i]-'a';
        if(t->son[ch]==NULL)
            return 0;
        t=t->son[ch];
    }
    return t->num;
}

int countSum(char *str, int n){
    Node *t=root;
    for(int i=0;i<n;i++){
        int ch = str[i]-'a';
        if(t->son[ch]==NULL)
            return 0;
        t=t->son[ch];
    }
    return t->sum;
}

void init(){
    pt=0;
    root=newNode('*');
}
```

## 数组实现

字典树占空间较大，用数组模拟指针更节约空间（这段是复制的，已交题）

```cpp
#include <iostream>
#include <cstring>
using namespace std;
class trie
{
private:
    int next[500000][26], ans[500000];
    int root, l;
    int newnode()
    {
        memset(next[l], -1, sizeof(next[l]));
        ans[l++] = 0;
        return l - 1;
    }
public:
    trie()
    {
        l = 0;
        root = newnode();
    }
    void insert(char *buf)
    {
        int len = strlen(buf), now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][buf[i] - 'a'] == -1)
                next[now][buf[i] - 'a'] = newnode();
            now = next[now][buf[i] - 'a'];
            ans[now]++;
        }
    }
    int query(char *buf)
    {
        int len = strlen(buf), now = root;
        for (int i = 0; i < len; i++)
        {
            now = next[now][buf[i] - 'a'];
            if (now == -1)
                return 0;
        }
        return ans[now];
    }
};
```



