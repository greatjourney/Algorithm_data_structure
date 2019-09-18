#include "BinaryTree.h"

class MyBinaryTree : public ods::BinaryTree<ods::BTNode1>{
  typedef ods::BTNode1 Node;
public:
  MyBinaryTree(ods::BTNode1* nil_, ods::BTNode1* r_) :ods::BinaryTree<ods::BTNode1>(nil_){
    r = r_;
  }
  void traverse(){
    traverse(r);
  }
  void traverse(Node* u){
    if (u == nil) return;
    std::cout << u << std::endl;
    traverse(u->left);
    traverse(u->right);
  }
  void traverse2() {
    Node *u = r, *prev = nil, *next;
    while (u != nil) {
      std::cout << u << std::endl;
      if (prev == u->parent) {
        if (u->left != nil) next = u->left;
        else if (u->right != nil) next = u->right;
        else next = u->parent;
      } else if (prev == u->left) {
        if (u->right != nil) next = u->right;
        else next = u->parent;
      } else {
        next = u->parent;
      }
      prev = u;
      u = next;
    }
  }
  void bfTraverse() {
    ods::ArrayDeque<Node*> q;
    if (r != nil) q.add(q.size(),r);
    while (q.size() > 0) {
      Node *u = q.remove(0);
      std::cout << u << std::endl;
      if (u->left != nil) q.add(q.size(),u->left);
      if (u->right != nil) q.add(q.size(),u->right);
    }
  }
};

int main(){
  ods::BTNode1 *r = new ods::BTNode1();
  ods::BTNode1 *n1 = new ods::BTNode1();
  ods::BTNode1 *n2 = new ods::BTNode1();
  ods::BTNode1 *n3 = new ods::BTNode1();
  std::cout << "r = " << r << ",n1=" << n1 << ",n2=" << n2 << ",n3=" << n3 << std::endl;
  r->left = n1; n1->parent = r;
  r->right = n2; n2->parent = r;
  n2->left = n3; n3->parent = n2;
  /*
                r
               / \ 
              n1  n2
                 /
                n3
  */
  MyBinaryTree t(0, r);
  // t.height2(r) -> 2
  std::cout << "t.height2(r)=" << t.height2(r) << std::endl;
  // t.height2(n1) -> 0
  std::cout << "t.height2(n1)=" << t.height2(n1) << std::endl;
  // t.height2(n2) -> 1
  std::cout << "t.height2(n2)=" << t.height2(n2) << std::endl;
  // t.height2(n3) -> 0
  std::cout << "t.height2(n3)=" << t.height2(n3) << std::endl;
}