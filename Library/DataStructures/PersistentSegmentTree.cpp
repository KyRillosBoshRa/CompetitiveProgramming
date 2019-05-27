struct Node {
  int sum;
  Node *lf, *rt;

  Node(int sum = 0) : sum(sum), lf(this), rt(this) {}

  Node(int sum, Node *lf, Node *rt) : sum(sum), lf(lf), rt(rt) {}
};

Node *empty = new Node;

Node *insert(int x, Node *cur, int l = -1e9, int r = 1e9) {
  if (x > r || x < l) return cur;
  if (l == r)  return new Node(cur->sum + 1);

  int mid = l + (r - l) / 2;
  Node *lf = insert(x, cur->lf, l, mid);
  Node *rt = insert(x, cur->rt, mid + 1, r);
  return new Node(cur->sum + 1, lf, rt);
}
// k-th number
int query(int k, Node *curR, Node *curL, int l = -1e9, int r = 1e9) {
  if (l == r) return r;
  int mid = l + (r - l) / 2;
  if (curR->lf->sum - curL->lf->sum < k)
    return query(k - (curR->lf->sum - curL->lf->sum), curR->rt, curL->rt, mid + 1, r);
  return query(k, curR->lf, curL->lf, l, mid);
}
// # elements <= k
int query(int k, Node *curR, Node *curL, int l = -1e9, int r = 1e9) {
  if(l == r) return curR->sum - curL->sum;
  int mid = l + (r - l) / 2;
  if (mid >= k) return query(k, curR->lf, curL->lf, l, mid);
  return curR->lf->sum - curL->lf->sum + query(k, curR->rt, curL->rt, mid + 1, r);
}

Node *root[N];
int n, q, a[N];
