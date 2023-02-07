#include "vector.h"
#include <vector>
#include <gtest/gtest.h>


TEST(VectorTest, DefaultConstructor) {
s21::vector<int> v;
EXPECT_EQ(v.size(), 0);
EXPECT_EQ(v.capacity(), 0);
}

TEST(VectorTest, InitializerListConstructor) {
s21::vector<int> v = {1, 2, 3};
EXPECT_EQ(v.size(), 3);
EXPECT_EQ(v.capacity(), 3);
EXPECT_EQ(v[0], 1);
EXPECT_EQ(v[1], 2);
EXPECT_EQ(v[2], 3);
}

TEST(VectorTest, CopyConstructor) {
s21::vector<int> v1 = {1, 2, 3};
s21::vector<int> v2 = v1;
EXPECT_EQ(v1.size(), v2.size());
EXPECT_EQ(v1.capacity(), v2.capacity());
EXPECT_EQ(v1[0], v2[0]);
EXPECT_EQ(v1[1], v2[1]);
EXPECT_EQ(v1[2], v2[2]);
}

TEST(VectorTest, MoveConstructor) {
s21::vector<int> v1 = {1, 2, 3};
s21::vector<int> v2 = std::move(v1);
EXPECT_EQ(v1.size(), 0);
EXPECT_EQ(v1.capacity(), 0);
EXPECT_EQ(v2.size(), 3);
EXPECT_EQ(v2.capacity(), 3);
EXPECT_EQ(v2[0], 1);
EXPECT_EQ(v2[1], 2);
EXPECT_EQ(v2[2], 3);
}

TEST(VectorTest, CopyAssignment) {
s21::vector<int> v1 = {1, 2, 3};
s21::vector<int> v2;
v2 = v1;
EXPECT_EQ(v1.size(), v2.size());
EXPECT_EQ(v1.capacity(), v2.capacity());
EXPECT_EQ(v1[0], v2[0]);
EXPECT_EQ(v1[1], v2[1]);
EXPECT_EQ(v1[2], v2[2]);
}

TEST(VectorTest, MoveAssignment) {
s21::vector<int> v1 = {1, 2, 3};
s21::vector<int> v2;
v2 = std::move(v1);
EXPECT_EQ(v1.size(), 0);
EXPECT_EQ(v1.capacity(), 0);
EXPECT_EQ(v2.size(), 3);
EXPECT_EQ(v2.capacity(), 3);
EXPECT_EQ(v2[0], 1);
}

TEST(VectorTest, InsertIntoArray) {
s21::vector<int> vec;
vec.insert(vec.begin(), 5);
vec.insert(vec.end(), 10);
vec.insert(vec.begin() + 1, 8);
EXPECT_EQ(vec[0], 5);
EXPECT_EQ(vec[1], 8);
EXPECT_EQ(vec[2], 10);
}

TEST(VectorTest, EraseElements) {
s21::vector<int> vec{5, 8, 10};
vec.erase(vec.begin());
vec.erase(vec.begin() + 1);
EXPECT_EQ(vec.size(), 1);
EXPECT_EQ(vec[0], 8);
}

TEST(VectorTest, PushBackElements) {
s21::vector<int> vec;
vec.push_back(5);
vec.push_back(8);
vec.push_back(10);
EXPECT_EQ(vec.size(), 3);
EXPECT_EQ(vec[0], 5);
EXPECT_EQ(vec[1], 8);
EXPECT_EQ(vec[2], 10);
}

TEST(VectorTest, ClearVector) {
s21::vector<int> vec{5, 8, 10};
vec.clear();
EXPECT_EQ(vec.size(), 0);
}

TEST(VectorTest, Access) {
// Test operator[]
s21::vector<int> s_vec{1, 2, 3, 4, 5};
std::vector<int> std_vec{1, 2, 3, 4, 5};

// Check if both vectors have the same size
EXPECT_EQ(s_vec.size(), std_vec.size());

// Check if both vectors have the same values
for (int i = 0; i < 5; i++) {
EXPECT_EQ(s_vec[i], std_vec[i]);
}
}

TEST(VectorTest, AccessElementsOutOfRange) {
s21::vector<int> vec{5, 8, 10};
EXPECT_THROW(vec.at(5), std::out_of_range);
}


TEST(VectorTests, ConstructorTests) {
s21::vector<int> s21v1;
std::vector<int> stdv1;
EXPECT_EQ(s21v1.size(), stdv1.size());
EXPECT_EQ(s21v1.empty(), stdv1.empty());
}

TEST(VectorTests, PushBackTests) {
s21::vector<int> s21v;
std::vector<int> stdv;
for (int i = 0; i < 10; i++) {
s21v.push_back(i);
stdv.push_back(i);
EXPECT_EQ(s21v[i], stdv[i]);
}
EXPECT_EQ(s21v.size(), stdv.size());

}

TEST(VectorTest, PushBack) {
// Test push_back() with int values
s21::vector<int> s_vec;
std::vector<int> std_vec;
for (int i = 0; i < 5; i++) {
s_vec.push_back(i);
std_vec.push_back(i);
}

// Check if both vectors have the same size
EXPECT_EQ(s_vec.size(), std_vec.size());

// Check if both vectors have the same values
for (int i = 0; i < 5; i++) {
EXPECT_EQ(s_vec[i], std_vec[i]);
}
}

TEST(VectorTests, AccessTests) {
s21::vector<int> s21v({1, 2, 3, 4});
std::vector<int> stdv({1, 2, 3, 4});
for (int i = 0; i < 4; i++) {
EXPECT_EQ(s21v[i], stdv[i]);
}
}

TEST(VectorTests, IteratorTests) {
s21::vector<int> s21v({1, 2, 3, 4});
std::vector<int> stdv({1, 2, 3, 4});
s21::vector<int>::iterator s21it = s21v.begin();
std::vector<int>::iterator stdit = stdv.begin();
while (s21it != s21v.end()) {
EXPECT_EQ(*s21it, *stdit);
s21it++;
stdit++;
}
}

TEST(VectorTests, ClearTests) {
s21::vector<int> s21v({1, 2, 3, 4});
std::vector<int> stdv({1, 2, 3, 4});
s21v.clear();
stdv.clear();
EXPECT_EQ(s21v.size(), stdv.size());
EXPECT_EQ(s21v.empty(), stdv.empty());
}

//TEST(VectorTest, EmplaceBack) {
//// Test emplace_back() with string values
//s21::vector<std::string> s_vec;
//std::vector<std::string> std_vec;
//s_vec.emplace_back("one");
//std_vec.emplace_back("one");
//s_vec.emplace_back("two");
//std_vec.emplace_back("two");
//s_vec.emplace_back("three");
//std_vec.emplace_back("three");
//
//// Check if both vectors have the same size
//EXPECT_EQ(s_vec.size(), std_vec.size());
//
//// Check if both vectors have the same values
//for (int i = 0; i < 3; i++) {
//EXPECT_EQ(s_vec[i], std_vec[i]);
//}
//}

// Test if s21::vector behaves like std::vector when it comes to size and capacity
TEST(S21VectorTest, SizeAndCapacity) {
// Create instances of s21::vector and std::vector with initial size of 3
s21::vector<int> s21_vec(3);
std::vector<int> std_vec(3);

// Check if the sizes of both containers are equal
EXPECT_EQ(s21_vec.size(), std_vec.size());
EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());

// Push an element to both containers
s21_vec.push_back(10);
std_vec.push_back(10);

// Check if the sizes of both containers are equal after pushing an element
EXPECT_EQ(s21_vec.size(), std_vec.size());
EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());

// Reserve a larger capacity for both containers
s21_vec.reserve(10);
std_vec.reserve(10);

// Check if the capacities of both containers are equal after reserving
EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
}

TEST(S21VectorTest, ElementAccess) {
// Create instances of s21::vector and std::vector with initial values
s21::vector<int> s21_vec({1, 2, 3});
std::vector<int> std_vec({1, 2, 3});

// Check if the elements of both containers are equal
EXPECT_EQ(s21_vec[0], std_vec[0]);
EXPECT_EQ(s21_vec[1], std_vec[1]);
EXPECT_EQ(s21_vec[2], std_vec[2]);

// Check if the front and back elements of both containers are equal
EXPECT_EQ(s21_vec.front(), std_vec.front());
EXPECT_EQ(s21_vec.back(), std_vec.back());

// Modify the first element of both containers
s21_vec[0] = 10;
std_vec[0] = 10;

// Check if the first elements of both containers are equal after modification
EXPECT_EQ(s21_vec[0], std_vec[0]);
}

TEST(VectorTest, TestPushBack) {
s21::vector<int> s21_vec;
std::vector<int> std_vec;
int num = 5;

for (int i = 0; i < num; ++i) {
s21_vec.push_back(i);
std_vec.push_back(i);
}

EXPECT_EQ(s21_vec.size(), std_vec.size());
for (int i = 0; i < num; ++i) {
EXPECT_EQ(s21_vec[i], std_vec[i]);
}
}

TEST(VectorTest, TestPopBack) {
s21::vector<int> s21_vec;
std::vector<int> std_vec;
int num = 5;

for (int i = 0; i < num; ++i) {
s21_vec.push_back(i);
std_vec.push_back(i);
}

for (int i = 0; i < num; ++i) {
s21_vec.pop_back();
std_vec.pop_back();
}

EXPECT_EQ(s21_vec.size(), std_vec.size());
}

TEST(VectorTest, TestInsert) {
s21::vector<int> s21_vec;
std::vector<int> std_vec;
int num = 5;

for (int i = 0; i < num; ++i) {
s21_vec.push_back(i);
std_vec.push_back(i);
}

s21::vector<int>::iterator s21_it = s21_vec.begin();
std::vector<int>::iterator std_it = std_vec.begin();
s21_vec.insert(s21_it + 2, 100);
std_vec.insert(std_it + 2, 100);

EXPECT_EQ(s21_vec.size(), std_vec.size());
for (int i = 0; i < s21_vec.size(); ++i) {
EXPECT_EQ(s21_vec[i], std_vec[i]);
}
}

TEST(s21VectorTest, TestDataFunction) {
s21::vector<int> s21v = {1, 2, 3, 4};
std::vector<int> stdv = {1, 2, 3, 4};

// Test data() function
EXPECT_EQ(s21v.data(), s21v.data());
EXPECT_EQ(stdv.data(), stdv.data());
}

TEST(s21VectorTest, TestShrinkToFitFunction) {
s21::vector<int> s21v = {1, 2, 3, 4};
std::vector<int> stdv = {1, 2, 3, 4};

// Test shrink_to_fit() function
s21v.shrink_to_fit();
stdv.shrink_to_fit();
EXPECT_EQ(s21v.capacity(), s21v.size());
EXPECT_EQ(stdv.capacity(), stdv.size());
}

TEST(s21VectorTest, TestSwapFunction) {
s21::vector<int> s21v1 = {1, 2, 3, 4};
s21::vector<int> s21v2 = {5, 6, 7, 8};
std::vector<int> stdv1 = {1, 2, 3, 4};
std::vector<int> stdv2 = {5, 6, 7, 8};

// Test swap() function
s21v1.swap(s21v2);
stdv1.swap(stdv2);
for (int i = 0; i < s21v1.size(); ++i) {
EXPECT_EQ(s21v1[i], stdv1[i]);
EXPECT_EQ(s21v2[i], stdv2[i]);
}
}

TEST(VectorString, PushBack) {
// Test push_back for s21::vector
s21::vector<std::string> s21_vec;
s21_vec.push_back("hello");
s21_vec.push_back("world");
EXPECT_EQ(s21_vec.size(), 2);
EXPECT_EQ(s21_vec[0], "hello");
EXPECT_EQ(s21_vec[1], "world");

// Test push_back for std::vector
std::vector<std::string> std_vec;
std_vec.push_back("hello");
std_vec.push_back("world");
EXPECT_EQ(std_vec.size(), 2);
EXPECT_EQ(std_vec[0], "hello");
EXPECT_EQ(std_vec[1], "world");
}

TEST(VectorString, AccessOperator) {
// Test access operator for s21::vector
s21::vector<std::string> s21_vec({"hello", "world"});
EXPECT_EQ(s21_vec[0], "hello");
EXPECT_EQ(s21_vec[1], "world");

// Test access operator for std::vector
std::vector<std::string> std_vec({"hello", "world"});
EXPECT_EQ(std_vec[0], "hello");
EXPECT_EQ(std_vec[1], "world");
}

TEST(VectorString, Iterators) {
// Test iterators for s21::vector
s21::vector<std::string> s21_vec({"hello", "world"});
auto s21_it = s21_vec.begin();
EXPECT_EQ(*s21_it, "hello");
++s21_it;
EXPECT_EQ(*s21_it, "world");

// Test iterators for std::vector
std::vector<std::string> std_vec({"hello", "world"});
auto std_it = std_vec.begin();
EXPECT_EQ(*std_it, "hello");
++std_it;
EXPECT_EQ(*std_it, "world");
}

TEST(S21VectorString, BasicOperations) {
s21::vector<std::string> s21_vec;
std::vector<std::string> std_vec;

s21_vec.push_back("Hello");
std_vec.push_back("Hello");
EXPECT_EQ(s21_vec[0], std_vec[0]);

s21_vec.push_back("world");
std_vec.push_back("world");
EXPECT_EQ(s21_vec[1], std_vec[1]);

s21_vec.pop_back();
std_vec.pop_back();
EXPECT_EQ(s21_vec.size(), std_vec.size());

s21_vec.clear();
std_vec.clear();
EXPECT_EQ(s21_vec.empty(), std_vec.empty());
}

TEST(S21VectorString, Iterators) {
s21::vector<std::string> s21_vec = {"Hello", "world"};
std::vector<std::string> std_vec = {"Hello", "world"};

EXPECT_EQ(*s21_vec.begin(), *std_vec.begin());
EXPECT_EQ(*(s21_vec.end() - 1), *(std_vec.end() - 1));

s21::vector<std::string>::iterator s21_it = s21_vec.begin();
std::vector<std::string>::iterator std_it = std_vec.begin();

EXPECT_EQ(*s21_it, *std_it);
s21_it++;
std_it++;
EXPECT_EQ(*s21_it, *std_it);
}

TEST(S21VectorString, Capacity) {
s21::vector<std::string> s21_vec;
std::vector<std::string> std_vec;

EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());

s21_vec.reserve(100);
std_vec.reserve(100);
EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());

s21_vec.shrink_to_fit();
std_vec.shrink_to_fit();
EXPECT_EQ(s21_vec.capacity(), std_vec.capacity());
}