//Link-Cut Tree
//
struct Tree {
	Tree* p;
    Tree* ch[2];
    bool rev; 
    int val, sum, siz;
    Tree() : p(nullptr), ch{nullptr, nullptr}, 
    	rev(false), val(0), sum(0), siz(1) {}
};

// pull 
void pull(Tree* t) {
    t->sum = (t->ch[0] ? t->ch[0]->sum : 0) + t->val + (t->ch[1] ? t->ch[1]->sum : 0);
}

// treefun
bool isroot(Tree* t) {
    return t->p == nullptr || (t->p->ch[0] != t && t->p->ch[1] != t); 
}

int pos(Tree* t) {
    return t->p->ch[1] == t;
}

// push
void reverse(Tree* t) {
    if (t) {
    	std::swap(t->ch[0], t->ch[1]);
    	t->rev ^= 1;
    }
}

void push(Tree* t) {
    if (t->rev) {
        reverse(t->ch[0]);
        reverse(t->ch[1]);
    }
    t->rev = false;
}

void pushAll(Tree* t) {
    if (!isroot(t)) {
        pushAll(t->p);
    }
    push(t);
}

// splay
void rotate(Tree* t) {
    Tree* q = t->p;
	int x = !pos(t);
    q->ch[!x] = t->ch[x];
    if (t->ch[x]) t->ch[x]->p = q;
    t->p = q->p;
    if (!isroot(q)) q->p->ch[pos(q)] = t;
    t->ch[x] = q;
    q->p = t;
    pull(q);
}

void splay(Tree* t) {
    pushAll(t);
    while (!isroot(t)) {
        if (!isroot(t->p)) {
            if (pos(t) == pos(t->p)) {
				rotate(t->p);
            } else {
                rotate(t);
            }
        }
        rotate(t);
    }
    pull(t);
}

Tree* access(Tree* t) {
	Tree* q = nullptr;
    for (Tree* i = t; i; q = i, i = i->p) {
        splay(i);
        i->ch[1] = q;
        pull(i); 
    }
    splay(t); 
    return q;
}

Tree* lca(Tree* u, Tree* v) {
    access(u);
    return access(v);
}

void makeroot(Tree* t) { 
    access(t);
    reverse(t);
}

Tree* findroot(Tree* t) {
	if (!t) return nullptr;
    access(t); 
	Tree* q = t;
	while (true) {
		push(q);
		if (!q->ch[0]) break;
		q = q->ch[0];
	}
	splay(q);
	return q;
}

void link(Tree* u, Tree* v) {
    makeroot(u);
    u->p = v; 
}

void split(Tree* u, Tree* v) {
    makeroot(u);
    access(v);
}

void cut(Tree* u, Tree* v) {
    split(u, v);
    u->p = v->ch[0] = nullptr;
    pull(v);
}

void cut(Tree* t) { 
    access(t);
    assert(t->ch[0]);
    t->ch[0]->p = nullptr;
    t->ch[0] = nullptr;
    pull(t);
}

