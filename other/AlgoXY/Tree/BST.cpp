#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template <typename T> struct node {
  node(T x) : key(x), left(nullptr), right(nullptr) {}
  ~node() {
    delete left;
    delete right;
  }

  void insert(T key);

  node *left;
  node *right;
  node *parent;
  T key;
};

template <typename T, typename F> void in_order_walk(node<T> *t, F f) {
  if (t) {
    in_order_walk(t->left, f);
    f(t->key);
    in_order_walk(t->right, f);
  }
}

template <typename T> node<T> *insert(node<T> *tree, T key) {
  node<T> *root(tree);
  node<T> *x = new node<T>(key);
  node<T> *parent(nullptr);

  while (tree) {
    parent = tree;
    if (key < tree->key) {
      tree = tree->left;
    } else {
      tree = tree->right;
    }
  }
  x->parent = parent;
  if (parent == nullptr) {
    return x;
  } else if (key < parent->key) {
    parent->left = x;
  } else {
    parent->right = x;
  }
  return root;
}

template <typename T> node<T> *min(node<T> *tree) {
  while (tree && tree->left) {
    tree = tree->left;
  }
  return tree;
}

template <typename T> node<T> *max(node<T> *tree) {
  while (tree && tree->right) {
    tree = tree->right;
  }
  return tree;
}

template <typename T> node<T> *search(node<T> *tree, T key) {
  while (tree && tree->key != key) {
    if (key < tree->key) {
      tree = tree->left;
    } else {
      tree = tree->right;
    }
  }
  return tree;
}

template <typename T> node<T> *succ(node<T> *tree) {
  if (tree->right) {
    return min(tree->right);
  } else {
    node<T> *p = tree->parent;
    while (p && tree == p->right) {
      tree = p;
      p = p->parent;
    }
    return p;
  }
}

template <typename T> node<T> *pred(node<T> *tree) {
  if (tree->left) {
    return max(tree->left);
  } else {
    node<T> *p = tree->parent;
    while (p && tree == p->left) {
      tree = p;
      p = p->parent;
    }
    return p;
  }
}

template <typename T> node<T> *del(node<T> *tree, node<T> *x) {
  if (x == nullptr) {
    return tree;
  }

  node<T> *root = tree;
  node<T> *old_x = x;
  node<T> *parent = x->parent;

  if (old_x->left == nullptr) {
    x = old_x->right;
  } else if (old_x->right == nullptr) {
    x = old_x->left;
  }

  else {

    node<T> *y = min(x->right);
    x->key = y->key;

    if (y->parent != x) {
      y->parent->left = y->right;
    }

    else {
      x->right = y->right;
    }

    if (y->right) {
      y->right->parent = y->parent;
    }
    remove_node(y);
    return root;
  }

  if (x) {
    x->parent = parent;
  }
  if (parent == nullptr) {
    root = x;
  } else {
    if (parent->left == old_x) {
      parent->left = x;
    } else {
      parent->right = x;
    }
  }
  remove_node(old_x);
  return root;
}

template <typename T> void remove_node(node<T> *x) {
  if (x) {
    x->left = x->right = nullptr;
  }
  delete x;
}

void print(int key) { printf("%d\n", key); }

/**
              3
        1           5
           2     4
                      10
*/
int main() {
  node<int> tree(3);
  insert(&tree, 1);
  insert(&tree, 2);
  insert(&tree, 5);
  insert(&tree, 4);
  insert(&tree, 10);
  in_order_walk(&tree, print);
  printf("min: %d, max: %d\n", min(&tree)->key, max(&tree)->key);
  printf("search %d\n", search(&tree, 5)->key);
  printf("3's succ: %d\n", succ(&tree)->key);
  printf("3's pred: %d\n", pred(&tree)->key);

  del(&tree, tree.right);
  in_order_walk(&tree, print);
  return 0;
}
