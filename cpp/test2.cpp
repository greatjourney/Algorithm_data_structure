#include "BinaryTree.h"

// class MyBinaryTree : public ods::BinaryTree{
//   typedef ods::BTNode1 Node;
// public:
//   MyBinaryTree(ods::BTNode1* nil_, ods::BTNode1* r_) :ods::BinaryTree(nil_){
//     r = r_;
//   }
// };

int main(){
  Node *r = new Node();
  Node *n1 = new Node();
  Node *n2 = new Node();
  Node *n3 = new Node();
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
  // t.size2(r) -> 4
  std::cout << "t.size2(r)=" << t.size2(r) << std::endl;
  // t.size(n1) -> 1
  std::cout << "t.size2(n1)=" << t.size2(n1) << std::endl;
  // t.size(n2) -> 2
  std::cout << "t.size2(n2)=" << t.size2(n2) << std::endl;
  // t.size(n3) -> 1
  std::cout << "t.size2(n3)=" << t.size2(n3) << std::endl;
}