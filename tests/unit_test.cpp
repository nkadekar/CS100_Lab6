#include "gtest/gtest.h"
#include "../header/mult.hpp"
#include "../header/div.hpp"
#include "../header/sub.hpp"
#include "../header/add.hpp"
#include "../header/op.hpp"
#include "../header/rand.hpp"
#include "../header/pow.hpp"
#include "../header/ListContainer.hpp"
#include "../header/VectorContainer.hpp"
#include "../header/bubbleSort.hpp"
#include <string>
#include <sstream>

TEST(ListContainerTest, SwapTest){
	Op* seven = new Op(7);
	Op* six = new Op(6);
	Op* five = new Op(5);
	ListContainer* test = new ListContainer();
	
	test->add_element(seven);
	test->add_element(six);	
    test->add_element(five);

	test->swap(0, 2);

	ASSERT_EQ(test->size(), 3);
    EXPECT_EQ(test->at(0)->evaluate(), 5);
    EXPECT_EQ(test->at(1)->evaluate(), 6);
    EXPECT_EQ(test->at(2)->evaluate(), 7);	
}

TEST(ListContainerTest, TreeSizeTest) {
    Op* num1 = new Op(111);
    Op* num2 = new Op(222);
    Add* Tree = new Add(num1, num2);

    ListContainer* con = new ListContainer();
    con->add_element(Tree);

    EXPECT_EQ(con->size(), 1);
}

TEST(ListContainerTest, EmptyTest) {
    ListContainer* con = new ListContainer();
    ASSERT_EQ(con->size(), 0);
}








TEST(VectorContainerTest, add_at_size) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

	Op* ten = new Op(10);
    Op* six = new Op(6);
	Sub* TreeC = new Sub(ten, six);

	VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);
}

TEST(VectorContainerTest, EmptyContainer) {
	VectorContainer* container = new VectorContainer();
    ASSERT_EQ(container->size(), 0);
}

TEST(VectorContainerTest, Swap) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

	VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);

    ASSERT_EQ(container->size(), 2);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);

	container->swap(0, 1);
	
	ASSERT_EQ(container->size(), 2);
    EXPECT_EQ(container->at(0)->evaluate(), 5);
    EXPECT_EQ(container->at(1)->evaluate(), 28);
}

TEST(VectorContainerTest, Size1) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

	VectorContainer* container = new VectorContainer();
	container->add_element(TreeA); 

	EXPECT_EQ(container->size(), 1);
}

TEST(SortTestSet, BubbleSortTestVector) {
    Op* seven = new Op(7);
    Op* four = new Op(4);
    Mult* TreeA = new Mult(seven, four);

    Op* three = new Op(3);
    Op* two = new Op(2);
    Add* TreeB = new Add(three, two);

    Op* ten = new Op(10);
    Op* six = new Op(6);
    Sub* TreeC = new Sub(ten, six);

    VectorContainer* container = new VectorContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}

TEST(SortTestSet, BubbleSortEmptyVector) {
	VectorContainer* container = new VectorContainer();
	
	ASSERT_EQ(container->size(), 0);

	container->set_sort_function(new BubbleSort());
	container->sort();

	ASSERT_EQ(container->size(), 0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
