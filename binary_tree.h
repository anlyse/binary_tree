//
// Created by dell on 2018/12/28.
//

#ifndef BINARY_TREE_CBTREE_H
#define BINARY_TREE_CBTREE_H

#include "tree_node.h"

template< typename T = int>
class CBinaryTree {
public:
	CBinaryTree();
	CBinaryTree(const CBinaryTree &bt);
	CBinaryTree(const T &element);
	~CBinaryTree();

	void insert(const T &element);
	void insert_norecurve(const T &element);
	bool remove(const T &element);
	void clear();
	CBTreeNode<T>* find(const T &element) const;
	CBTreeNode<T>* find_norecurve(const T &element) const;
	bool is_exit(const T &element) const;
	// 前序结点
	CBTreeNode<T>* pre_node(CBTreeNode<T> *tn);
	CBTreeNode<T>* post_node(CBTreeNode<T> *tn);
	void pre_order() const;
	void pre_order_norecurve() const;
	void in_order() const;
	void in_order_norecurve() const;
	void post_order () const;
	void post_order_norecurve() const;
	int depth() const;
	int node_num() const;
	int leaf_num() const;
	int node_num_level(const int &level);
	// 树最大结点
	CBTreeNode<T>* max();
	// 树下某个子节点的树的最大结点
	CBTreeNode<T>* max(CBTreeNode<T> *tn);
	// 树最小结点
	CBTreeNode<T>* min();
	// 树下某个子节点的树的最小结点
	CBTreeNode<T>* min(CBTreeNode<T> *tn);

private:
	CBTreeNode<T>* __clone(const CBTreeNode<T> *tn);
	void __insert(const T &element, CBTreeNode<T> * &tn, CBTreeNode<T> *parent);
	bool __remove(const T &element);
	void __clear(CBTreeNode<T> * &tn);
	CBTreeNode<T>* __find(const T &element, CBTreeNode<T> *tn) const;
	void __pre_order(CBTreeNode<T> *tn) const;
	void __in_order(CBTreeNode<T> *tn) const;
	void __post_order(CBTreeNode<T> *tn) const;
	int __depth(CBTreeNode<T> *tn) const;
	int __node_num(CBTreeNode<T> *tn) const;
	int __leaf_num(CBTreeNode<T> *tn) const;
	int __node_num_level(CBTreeNode<T> *tn, const int &level) const;

private:
	CBTreeNode<T> *m_root;
};


#endif //BINARY_TREE_CBTREE_H
