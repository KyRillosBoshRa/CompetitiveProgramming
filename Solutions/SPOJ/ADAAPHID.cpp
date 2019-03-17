/*
	unclear problem statement.
	The task is: for the i-th aphid with input (A[i], V[i]) after xor, the first part of the ID is A[i],
	the second part of the ID is equal to sum(V[k] for k <= i and A[k] <= A[i]).
	the size of array is very large so I can't use bit instead I decided to use implicit treap
	but the problem is I can't find the initial key of the node to be inserted now so i used policy based ds
	to count elements less than or equal the key I want to insert.
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

long long n, a, b;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set<pair<long long, int>> st;
random_device Rd; // obtain a random number from hardware
mt19937 rd(Rd()); // seed the generator
uniform_int_distribution<> rnd(1, INT_MAX); // define the range
struct node{
  int priority, cnt;
  long long sum, val;
  node *l, *r;
  node(long long _val = 0, int _priority = 0): val(_val), priority(_priority){
    l = r = NULL;
    cnt = 1; sum = val;
  }
  ~node(){ delete l; delete r;}
} *root;
struct Treap{
  Treap(){root = NULL;}
  ~Treap(){clear();}
  void clear(node*& t = root){ delete t; t = NULL;}

  int get_cnt(node* t){
    return t ? t->cnt: 0;
  }
  void upd_cnt(node* t){
    if(t) t->cnt = 1 + get_cnt(t->l) + get_cnt(t->r);
  }
  int get_sum(node* t){
    return t ? t->sum: 0;
  }
  void upd_sum(node* t){
    if(t) t->sum = t->val + get_sum(t->l) + get_sum(t->r);
  }
  void split(node*& l, node*& r, int key, node* t = root, int add = 0){
    if(!t) return void(l = r = NULL);
    int cur_key = add + get_cnt(t->l);
    if(cur_key > key) split(l, t->l, key, t->l, add), r = t;
    else split(t->r, r, key, t->r, cur_key + 1), l = t;
    upd_cnt(t);
    upd_sum(t);
  }
  void merge(node* l, node* r, node*& t = root){
    if (!l || !r) return void(t = (l ? l : r));
    if (l->priority > r->priority) merge(l->r, r, l->r), t = l;
    else merge(l, r->l, r->l), t = r;
    upd_cnt(t);
    upd_sum(t);
  }
  void insert(node* it, int key){
    if(!root) return void(root = it);
    node *a, *b, *c, *d;
    split(a, b, key - 1);
    merge(a, it, a);
    merge(a, b);
  }
  long long query(int l){
    node *a, *b;
    split(a, b, l - 1);
    long long res = get_sum(a);
    merge(a, b);
    return res;
  }
} tr;
int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
  cin >> n;
  long long o = 0, lb = 0;
  for(int i = 0; i < n; ++i){
    cin >> a >> b;
    a ^= lb; b ^= lb;
    st.insert({a, o++});
    tr.insert(new node(b, rnd(rd)), st.order_of_key({a, o - 1}));
    cout << a << ' ' << (lb = tr.query(st.order_of_key({a, o}))) << '\n';
  }
  return 0;
}
