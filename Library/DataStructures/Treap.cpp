random_device Rd;
mt19937 rd(Rd());
uniform_int_distribution<> rnd(1, INT_MAX);
struct node{
  int key, priority, cnt;
  long long sum, val, lazy;
  node *l, *r;
  node(int _key = 0, long long _val = 0, int _priority = 0): key(_key), val(_val), priority(_priority){
    l = r = NULL;
    lazy = 0; cnt = 1; sum = val;
  }
  ~node(){ delete l; delete r;}
} *root;
struct Treap{
  Treap(){root = NULL;}
  ~Treap(){clear();}
  void clear(node*& t = root){ delete t; t = NULL;}
  void push_down(node* t){
    if(!t || !t->lazy) return;
    if(t->l) t->l->lazy += t->lazy, upd_sum(t->l);
    if(t->r) t->r->lazy += t->lazy, upd_sum(t->r);
    t->val += t->lazy;
    t->lazy = 0;
  }
  long long get_sum(node* t){
    return t ? t->sum: 0;
  }
  int get_cnt(node* t){
    return t ? t->cnt: 0;
  }
  void upd_sum(node* t){
    if(t) t->sum = t->val + get_sum(t->l) + get_sum(t->r) + t->lazy * get_cnt(t);
  }
  void upd_cnt(node* t){
    if(t) t->cnt = 1 + get_cnt(t->l) + get_cnt(t->r);
  }
  void split(node*& l, node*& r, int key, node* t = root){
    if(!t) return void(l = r = NULL);
    push_down(t);
    if(t->key > key) split(l, t->l, key, t->l), r = t;
    else split(t->r, r, key, t->r), l = t;
    upd_cnt(t);
    upd_sum(t);
  }
  void merge(node* l, node* r, node*& t = root){
    if (!l || !r) return void(t = (l ? l : r));
    push_down(l);
    push_down(r);
    if (l->priority > r->priority) merge(l->r, r, l->r), t = l;
    else merge(l, r->l, r->l), t = r;
    upd_cnt(t);
    upd_sum(t);
  }
  void insert(node* it, node*& t = root){
    if(!t) return void(t = it);
    push_down(t);
    if(t->priority < it->priority) split(it->l, it->r, it->key, t), t = it;
    else insert(it, t->key >= it->key? t->l: t->r);
    upd_cnt(t);
    upd_sum(t);
  }
  long long query(int l, int r){
    node *a, *b, *c, *d;
    split(a, b, l - 1);
    split(c, d, r, b);
    long long res = get_sum(c);
    merge(c, d, b);
    merge(a, b);
    return res;
  }
  void add_lazy(int l, int r, int val){
    node *a, *b, *c, *d;
    split(a, b, l - 1);
    split(c, d, r, b);
    c->lazy += val;
    upd_sum(c);
    merge(c, d, b);
    merge(a, b);
  }
} tr;
