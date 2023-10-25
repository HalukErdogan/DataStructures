#include "ds/vector.hpp"

#include <gtest/gtest.h>

TEST(VectorTest, DefaultConstructor) {
    ds::Vector<int> v;
    EXPECT_EQ(v.Size(), 0);
    EXPECT_EQ(v.Capacity(), 1);
}

TEST(VectorTest, PushBack) {
    ds::Vector<int> v;
    v.PushBack(1);
    EXPECT_EQ(v.Size(), 1);
    EXPECT_EQ(v.At(0), 1);
}

TEST(VectorTest, PopBack) {
    ds::Vector<int> v;
    v.PushBack(1);
    v.PopBack();
    EXPECT_EQ(v.Size(), 0);
}

TEST(VectorTest, At) {
    ds::Vector<int> v;
    v.PushBack(1);
    EXPECT_EQ(v.At(0), 1);
}

TEST(VectorTest, Size) {
    ds::Vector<int> v;
    v.PushBack(1);
    EXPECT_EQ(v.Size(), 1);
}

TEST(VectorTest, Capacity) {
    ds::Vector<int> v;
    EXPECT_EQ(v.Capacity(), 1);
    v.PushBack(1);
    EXPECT_EQ(v.Capacity(), 1);
    v.PushBack(2);
    EXPECT_EQ(v.Capacity(), 2);
}

TEST(VectorTest, OperatorEqual) {
    ds::Vector<int> v1;
    ds::Vector<int> v2;
    v1.PushBack(1);
    v2.PushBack(1);
    EXPECT_TRUE(v1 == v2);
}

TEST(VectorTest, CopyConstructor) {
    ds::Vector<int> v1;
    v1.PushBack(1);
    ds::Vector<int> v2 = v1;
    EXPECT_TRUE(v1 == v2);
}

TEST(VectorTest, MoveConstructor) {
    ds::Vector<int> v1;
    v1.PushBack(1);
    ds::Vector<int> v2 = std::move(v1);
    EXPECT_EQ(v2.At(0), 1);
}

TEST(VectorTest, CopyAssignmentOperator) {
    ds::Vector<int> v1;
    v1.PushBack(1);
    ds::Vector<int> v2;
    v2 = v1;
    EXPECT_TRUE(v1 == v2);
}

TEST(VectorTest, MoveAssignmentOperator) {
    ds::Vector<int> v1;
    v1.PushBack(1);
    ds::Vector<int> v2;
    v2 = std::move(v1);
    EXPECT_EQ(v2.At(0), 1);
}

TEST(VectorTest, Erase) {
    ds::Vector<int> v;
    v.PushBack(1);
    v.PushBack(2);
    v.PushBack(3);
    v.Erase(1);
    EXPECT_EQ(v.Size(), 2);
    EXPECT_EQ(v.At(0), 1);
    EXPECT_EQ(v.At(1), 3);
}

TEST(VectorTest, Insert) {
    ds::Vector<int> v;
    v.PushBack(1);
    v.PushBack(3);
    v.Insert(1, 2);
    EXPECT_EQ(v.Size(), 3);
    EXPECT_EQ(v.At(0), 1);
    EXPECT_EQ(v.At(1), 2);
    EXPECT_EQ(v.At(2), 3);
}