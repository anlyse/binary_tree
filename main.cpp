#include <iostream>
#include "binary_tree.hpp"

using namespace std;

int main()
{
	CBinaryTree<int> bt;
	bt.insert(5);
	bt.insert(3);
	bt.insert(1);
	bt.insert(9);
	bt.insert(7);
	bt.insert(11);
	bt.insert(6);
	bt.insert(2);
	bt.insert(4);
	bt.insert(8);
	bt.insert(10);

	cout << "pre_order" << endl;
	bt.pre_order();
	bt.pre_order_norecurve();
	cout << "in_order" << endl;
	bt.in_order();
	bt.in_order_norecurve();
	cout << "post_order" << endl;
	bt.post_order();
	bt.post_order_norecurve();
	cout << "bt1" << endl;
	CBinaryTree<int> bt1(bt);
	bt1.pre_order();

	cout << "find" << endl;
	cout << bt.find(9) << endl;
	cout << bt.find_norecurve(9) << endl;
	cout << bt.find(20) << endl;
	cout << bt.find_norecurve(20) << endl;
	cout << "max :" << bt.max()->m_element << endl;
	cout << "min :" << bt.min()->m_element << endl;
	cout <<bt.pre_node(bt.find(9))->m_element << endl;
	cout <<bt.pre_node(bt.find(10))->m_element << endl;
	cout <<bt.post_node(bt.find(9))->m_element << endl;
	cout <<bt.post_node(bt.find(10))->m_element << endl;
	cout <<bt.post_node(bt.find(8))->m_element << endl;

	cout << "depth :" << bt.depth() << endl;
	cout << "node_num :" << bt.node_num() << endl;
	cout << "leaf_num :" << bt.leaf_num() << endl;
	cout << "node_num_level :" << bt.node_num_level(bt.depth()) << endl;
	bt.remove(3);
	cout << "remove(3)" << endl;
	bt.pre_order();
	cout << "remove(11)" << endl;
	bt.remove(11);
	bt.pre_order();
	cout << "depth :" << bt.depth() << endl;
	cout << "node_num :" << bt.node_num() << endl;
	cout << "leaf_num :" << bt.leaf_num() << endl;
	cout << "node_num_level :" << bt.node_num_level(bt.depth()) << endl;
	bt.remove(7);
	cout << "remove(7)" << endl;
	bt.pre_order();
	bt.remove(8);
	cout << "remove(8)" << endl;
	bt.pre_order();
	cout << "depth :" << bt.depth() << endl;
	cout << "node_num :" << bt.node_num() << endl;
	cout << "leaf_num :" << bt.leaf_num() << endl;
	cout << "node_num_level :" << bt.node_num_level(10) << endl;

	return 0;
}