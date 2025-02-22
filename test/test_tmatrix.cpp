#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
	TDynamicMatrix<int> m(5);

	ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m1(5);
	m1[0][1] = 15;
	TDynamicMatrix<int> m2(m1);
	EXPECT_EQ(15, m2[0][1]);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(m1);
	m1[0][0] = 15;
	EXPECT_EQ(0, m2[0][0]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicVector<int> m1(5);
	EXPECT_EQ(5, m1.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m1(5);
	m1[0][0] = 20;
	EXPECT_EQ(20, m1[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m1(5);
	ASSERT_ANY_THROW(m1.at(-1, 0) = 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m1(5);
	ASSERT_ANY_THROW(m1.at(5, 0) = 1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	m1[0][0] = 5;
	m2 = m1;
	m1 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	m1[0][0] = 15;
	m2[0][1] = 20;
	m2 = m1;
	EXPECT_EQ(15, m2[0][0]);
	EXPECT_EQ(0, m2[0][1]);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(10);
	m2 = m1;
	EXPECT_EQ(m1.size(), m2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(10);
	m1[0][0] = 5;
	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	m1 = m2;
	EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m1(5);
	m1[0][0] = 5;
	EXPECT_TRUE(m1 == m1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(10);
	EXPECT_FALSE(m1 == m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	TDynamicMatrix<int> m3;
	m1[0][0] = 10;
	m2[0][0] = 5;
	m3 = m1 + m2;
	EXPECT_EQ(15, m3[0][0]);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(10);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	TDynamicMatrix<int> m3;
	m1[0][0] = 10;
	m2[0][0] = 5;
	m3 = m1 - m2;
	EXPECT_EQ(5, m3[0][0]);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(10);
	ASSERT_ANY_THROW(m1 - m2);
}

