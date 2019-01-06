//
// Created by dell on 2018/12/28.
//

#ifndef BINARY_TREE_TREE_NODE_H
#define BINARY_TREE_TREE_NODE_H

template <typename T>
class CBTreeNode {
public:
	CBTreeNode<T> *m_left;   //左子结点
	CBTreeNode<T> *m_right;  //右子结点
	CBTreeNode<T> *m_parent; //父结点
	T m_element;

	CBTreeNode(const T &ele, CBTreeNode *left, CBTreeNode *right, CBTreeNode *parent)
		: m_element(ele),
		  m_left(left),
		  m_right(right),
		  m_parent(parent)
	{

	};

	CBTreeNode(const T &ele)
		: m_element(ele),
		  m_left(nullptr),
		  m_right(nullptr),
		  m_parent(nullptr)
	{

	};

	CBTreeNode(const CBTreeNode *pBNode)
		: m_element(pBNode->m_element),
		  m_left(pBNode->m_left),
		  m_right(pBNode->m_right),
		  m_parent(pBNode->m_parent)
	{

	}
};

#endif //BINARY_TREE_TREE_NODE_H




