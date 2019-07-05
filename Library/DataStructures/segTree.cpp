class segTree {
 private:
  struct node {
    long long x, lz;
    node(long long a = 0, long long b = 0) : x(a), lz(b) {}
  };
  node combine(const node& a, const node& b) { return node(a.x + b.x); }

  void upd(int idx, int l, int r, long long val) {
    sg[idx].lz += val;
    sg[idx].x += val * (r - l + 1);
  }
  void push_down(int idx, int l, int r, int m) {
    if (sg[idx].lz) {
      upd(2 * idx + 1, l, m, sg[idx].lz);
      upd(2 * idx + 2, m + 1, r, sg[idx].lz);
      sg[idx].lz = 0;
    }
  }

  vector<node> sg;
  int x;

 public:
  segTree(int n) {
    x = n;
    sg.assign(4 * n, 0);
  }
  node build(int idx = 0, int l = 0, int r = n - 1) {
    if (l > r) return node();
    if (l == r) {
      sg[idx] = node(a[l]);
      return sg[idx];
    }
    int m = l + ((r - l) >> 1);
    node prt1 = build(2 * idx + 1, l, m);
    node prt2 = build(2 * idx + 2, m + 1, r);
    return sg[idx] = combine(prt1, prt2);
  }
  void update_range(int st, int ed, long long val, int idx = 0, int l = 0,
                    int r = n - 1) {
    if (l > r) return;
    if (ed < l || st > r) return;
    if (l >= st && r <= ed) {
      upd(idx, l, r, val);
      return;
    }
    int m = l + ((r - l) >> 1);

    push_down(idx, l, r, m);

    update_range(st, ed, val, 2 * idx + 1, l, m);
    update_range(st, ed, val, 2 * idx + 2, m + 1, r);

    sg[idx] = combine(sg[2 * idx + 1], sg[2 * idx + 2]);
  }

  node query(int st, int ed, int idx = 0, int l = 0, int r = n - 1) {
    if (ed < l || st > r) return node();
    if (l >= st && r <= ed) return sg[idx];
    int m = l + ((r - l) >> 1);

    push_down(idx, l, r, m);

    node prt1 = query(st, ed, 2 * idx + 1, l, m);
    node prt2 = query(st, ed, 2 * idx + 2, m + 1, r);
    return combine(prt1, prt2);
  }
};