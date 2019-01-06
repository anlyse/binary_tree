//
// Created by dell on 2018/12/28.
//

#include "binary_tree.h"
#include <iostream>
#include<stack>
using namespace std;

template <typename T>
CBinaryTree<T>::CBinaryTree() {
	m_root = nullptr;
}

template <typename T>
CBinaryTree<T>::CBinaryTree(const CBinaryTree &bt)
{
	if( nullptr != bt.m_root ) {
		this->m_root = __clone(bt.m_root);
	} else {
		m_root = nullptr;
	}
};

template <typename T>
CBinaryTree<T>::CBinaryTree(const T &element)
{
	m_root = new CBTreeNode<T>(element);
}


template <typename T>
CBinaryTree<T>::~CBinaryTree()
{
	clear();
};

template <typename T>
void CBinaryTree<T>::insert(const T &element)
{
	CBTreeNode<T> *parent = nullptr;
	if (nullptr != m_root)
		parent = m_root->m_parent;
	__insert(element, m_root, parent);
}

template <typename T>
void CBinaryTree<T>::insert_norecurve(const T &element)
{
	CBTreeNode<T> *temp = m_root;
	CBTreeNode<T> *parent = nullptr;
	while(nullptr != temp) {
		parent = temp;
		if (temp->m_element < element )
			temp = temp->m_right;
		else
			temp = temp->m_left;
	}
	temp = new CBTreeNode<T>(element);
	if (nullptr == parent) {
		m_root = temp;
		return;
	}

	temp->m_parent = parent;
	if (parent->m_element < element)
		parent->m_right = temp;
	else
		parent->m_left = temp;
}


template <typename T>
bool CBinaryTree<T>::remove(const T &element)
{
	return __remove(element);
}

template <typename T>
void CBinaryTree<T>::clear()
{
	if (nullptr != m_root) {
		__clear(m_root);
	}
}

template <typename T>
CBTreeNode<T>* CBinaryTree<T>::find(const T &element) const
{
	return __find(element, m_root);
}

template <typename T>
CBTreeNode<T>* CBinaryTree<T>::find_norecurve(const T &element) const
{
	CBTreeNode<T> *temp = m_root;
	while ((nullptr != temp) && (temp->m_element != element)) {
		if (temp->m_element < element)
			temp = temp->m_right;
		else
			temp = temp->m_left;
	}

	return temp;
}

template <typename T>
bool CBinaryTree<T>::is_exit(const T &element) const
{
	CBTreeNode<T> *temp = find_norecurve(element);
	if (nullptr == temp)
		return false;
	return true;
}

template <typename T>
CBTreeNode<T>* CBinaryTree<T>::pre_node(CBTreeNode<T> *tn)
{
	// 查找前驱步骤：
	// 1) 先判断节点x是否有左子树，如果有左子树则其左子树的最大节点即是x的前驱；
	// 2) 如果没有左子树，但是该节点是其父节点的右孩子，那么父节点就是该节点的前驱结点；
	// 3) 如果没有左子树，但是该节点是其父节点的左孩子，那么需要沿着其父亲节点一直向树
	//    的顶端寻找，直到找到一个节点P，P节点是其父节点Q的右边孩子，那么Q就是该节点的前驱节点。
	if (nullptr == tn)
		return nullptr;
	if (tn->m_left)
		return max(tn->m_left);
	if (nullptr == tn->m_parent)
		return nullptr;
	if (tn->m_parent->m_right == tn)
		return tn->m_parent;
	// tn->m_parent->m_left == tn
	CBTreeNode<T> *temp = tn->m_parent;
	CBTreeNode<T> *temp2 = tn;
	while ((temp->m_parent != nullptr) && (temp2 == temp->m_left)) {
		temp2 = temp;
		temp = temp->m_parent;
	}
	return temp;
}

template <typename T>
CBTreeNode<T>* CBinaryTree<T>::post_node(CBTreeNode<T> *tn)
{
	// 查找后继节点的步骤：
    // 1) 先判断节点x是否有右子树，如果有右子树则其右子树的最小节点即是x的后继结点；
	// 2) 如果没有右子树，但是该节点是其父节点的左孩子，那么父节点就是该节点的后继结点；
    // 3) 如果没有右子树，但是该节点是其父节点的右孩子，那么需要沿着其父亲节点一直向树的顶
	// 端寻找，直到找到一个节点P，P节点是其父节点Q的左边孩子，那么Q就是该节点的后继节点。
	if (nullptr == tn)
		return nullptr;
	if (tn->m_right)
		return min(tn->m_right);
	if (nullptr == tn->m_parent)
		return nullptr;
	if (tn->m_parent->m_left == tn)
		return tn->m_parent;
	CBTreeNode<T> *temp = tn->m_parent;
	CBTreeNode<T> *temp2 = tn;
	while ((temp->m_parent != nullptr) && (temp2 == temp->m_right)) {
		temp2 = temp;
		temp = temp->m_parent;
	}
	return temp;
}

template <typename T>
void CBinaryTree<T>::pre_order() const
{
	__pre_order(m_root);
	cout << endl;
}

template <typename T>
void CBinaryTree<T>::pre_order_norecurve() const
{
	CBTreeNode<T> *temp = m_root;
	std::stack<CBTreeNode<T> *> nodes;
	while (temp != nullptr || !nodes.empty()) {
		if (nullptr != temp) {
			cout << temp->m_element << " ";
			nodes.push(temp);
			temp = temp->m_left;
		} else {
			temp = nodes.top();
			nodes.pop();
			temp = temp->m_right; //访问右子树
		}
	}
	cout << endl;
}

template <typename T>
void CBinaryTree<T>::in_order() const
{
	__in_order(m_root);
	cout << endl;
}

template <typename T>
void CBinaryTree<T>::in_order_norecurve() const
{
	CBTreeNode<T> *temp = m_root;
	std::stack<CBTreeNode<T> *> nodes;
	while (temp != nullptr || !nodes.empty()) {
		if (nullptr != temp) {
			nodes.push(temp);
			temp = temp->m_left;
		} else {
			temp = nodes.top();
			cout << temp->m_element << " ";
			nodes.pop();
			temp = temp->m_right;
		}
	}
	cout << endl;
}

template <typename T>
void CBinaryTree<T>::post_order() const
{
	__post_order(m_root);
	cout << endl;
}

template <typename T>
void CBinaryTree<T>::post_order_norecurve() const
{
	std::stack<CBTreeNode<T> *> nodes, output;
	if (nullptr == m_root)
		return;

	nodes.push(m_root);
	while (!nodes.empty()) {
		CBTreeNode<T> *temp = nodes.top();
		output.push(temp);
		nodes.pop();
		if (temp->m_left)
			nodes.push(temp->m_left);
		if (temp->m_right)
			nodes.push(temp->m_right);
	}

	while (!output.empty()) {
		cout << output.top()->m_element << " ";
		output.pop();
	}

	cout << endl;
}

template <typename T>
int CBinaryTree<T>::depth() const
{
	return __depth(m_root);
}

template <typename T>
int CBinaryTree<T>::node_num() const
{
	return __node_num(m_root);
}

template <typename T>
int CBinaryTree<T>::leaf_num() const
{
	return __leaf_num(m_root);
}

template <typename T>
int CBinaryTree<T>::node_num_level(const int &level)
{
	return __node_num_level(m_root, level);
}

template <typename T>
CBTreeNode<T>* CBinaryTree<T>::max()
{
	if (nullptr == m_root)
		return nullptr;
	CBTreeNode<T>* temp = m_root;
	return max(temp);
}

template <typename T>
CBTreeNode<T>* CBinaryTree<T>::max(CBTreeNode<T> *tn)
{
	if (nullptr == tn)
		return nullptr;
	CBTreeNode<T>* temp = tn;
	while (temp->m_right != nullptr)
		temp = temp->m_right;

	return temp;
}

template <typename T>
CBTreeNode<T>* CBinaryTree<T>::min()
{
	if (nullptr == m_root)
		return nullptr;
	CBTreeNode<T>* temp = m_root;
	return min(temp);
}

template <typename T>
CBTreeNode<T>* CBinaryTree<T>::min(CBTreeNode<T> *tn)
{
	if (nullptr == tn)
		return nullptr;
	CBTreeNode<T>* temp = tn;
	while (temp->m_left != nullptr)
		temp = temp->m_left;

	return temp;
}

template <typename T>
CBTreeNode<T>* CBinaryTree<T>::__clone(const CBTreeNode<T> *tn)
{
	if ( nullptr == tn ) {
		return nullptr;
	} else {
		return new CBTreeNode<T>(tn->m_element,
		                         __clone(tn->m_left),
		                         __clone(tn->m_right),
		                         tn->m_parent);
	}
}

template <typename T>
void CBinaryTree<T>::__insert(const T &element,
                              CBTreeNode<T> * &tn,
                              CBTreeNode<T> *parent)
{
	if (nullptr == tn) {
		tn = new CBTreeNode<T>(element);
		tn->m_parent = parent;
	} else if (element < tn->m_element) {
		__insert(element, tn->m_left, tn);
	} else {
		__insert(element, tn->m_right, tn);
	}
}

template <typename T>
bool CBinaryTree<T>::__remove(const T &element)
{
	// 找到要删除的节点
	CBTreeNode<T> *pFind = find_norecurve(element);
	if (nullptr == pFind) {
		return false;
	}

	CBTreeNode<T> *pDel = nullptr;
	if (nullptr == pFind->m_left && nullptr == pFind->m_right) {
		// 要删除的结点z为叶子结点，这是最简单的一种情况，直接修改其父节点相应指针为NULL。
		if (nullptr != pFind->m_parent) {
			pFind->m_parent = nullptr;
			pDel = pFind;
		}
	} else if (nullptr != pFind->m_left && nullptr != pFind->m_right) { // 有2个子节点
		// 要删除的结点z为有两个子树，则先找到z的后继结点y，y肯定是没有左子树的
		// (如果y还有左子树，那么y就肯定不是z的后继结点)，所以现在可以按照上面
		// 两种情况删除y结点，最后用y的值代替z的值。
		CBTreeNode<T> *pNode = post_node(pFind); // 后续节点
		pFind->m_element = pNode->m_element;
		if (pNode->m_parent->m_right == pNode)
			pNode->m_parent->m_right = pNode->m_right;
		else
			pNode->m_parent->m_left = pNode->m_right;
		pDel = pNode;
	} else {
		// 要删除的结点z为只有一个子树，让z的子树与z的父亲节点相连，删除z即可
		pDel = pFind; // 记住当前节点用以delete,不然会tn->m_parent->m_right会更改tn
		CBTreeNode<T> *tn_child = pFind->m_right == nullptr
				? pFind->m_left : pFind->m_right;
		if (pFind->m_parent->m_right == pFind)
			pFind->m_parent->m_right = tn_child;
		else
			pFind->m_parent->m_left = tn_child;
		tn_child->m_parent = pFind->m_parent;
	}

	delete pDel;
	pDel = nullptr;
	return true;
}

template <typename T>
void CBinaryTree<T>::__clear(CBTreeNode<T> * &tn)
{
	if (nullptr != tn) {
		__clear(tn->m_left);
		__clear(tn->m_right);
		cout << "delete: " << tn->m_element << endl;
		delete tn;
		tn = nullptr;
	}
}

template <typename T>
CBTreeNode<T>* CBinaryTree<T>::__find(const T &element, CBTreeNode<T> * tn) const
{
	if (nullptr == tn) {
		return nullptr;
	}
	if (element == tn->m_element) {
		return tn;
	}
	else if (element < tn->m_element) {
		__find(element, tn->m_left);
	} else {
		__find(element, tn->m_right);
	}
}

template <typename T>
void CBinaryTree<T>::__pre_order(CBTreeNode<T> *tn) const
{
	if( nullptr != tn ) {
		std::cout << tn->m_element << " ";
		__pre_order(tn->m_left);
		__pre_order(tn->m_right);
	}
}

template <typename T>
void CBinaryTree<T>::__in_order(CBTreeNode<T> *tn) const
{
	if( nullptr != tn ) {
		__in_order(tn->m_left);
		std::cout << tn->m_element << " ";
		__in_order(tn->m_right);
	}
}

template <typename T>
void CBinaryTree<T>::__post_order(CBTreeNode<T> *tn) const
{
	if( nullptr != tn ) {
		__post_order(tn->m_left);
		__post_order(tn->m_right);
		std::cout << tn->m_element << " ";
	}
}

template <typename T>
int CBinaryTree<T>::__depth(CBTreeNode<T> *tn) const
{
	if( nullptr == tn ) {
		return 0;
	}
	int ileft = __depth(tn->m_left);
	int iright = __depth(tn->m_right);

	return (ileft > iright ? ileft:iright) + 1;
}

template <typename T>
int CBinaryTree<T>::__node_num(CBTreeNode<T> *tn) const
{
	if (nullptr == tn) {
		return 0;
	}

	int ileft = __node_num(tn->m_left);
	int iright = __node_num(tn->m_right);

	return ileft + iright + 1;
}

template <typename T>
int CBinaryTree<T>::__leaf_num(CBTreeNode<T> *tn) const
{
	if (nullptr == tn) {
		return 0;
	}
	if (nullptr == tn->m_left && nullptr == tn->m_right) {
		return 1;
	}

	return __leaf_num(tn->m_left) + __leaf_num(tn->m_right);
}

template <typename T>
int CBinaryTree<T>::__node_num_level(CBTreeNode<T> *tn, const int &level) const
{
	if (nullptr == tn || level < 1) {
		return 0;
	}
	if (1 == level) {
		return 1;
	}
	int ileft = __node_num_level(tn->m_left, level-1);
	int iright = __node_num_level(tn->m_right, level-1);

	return ileft + iright;
}