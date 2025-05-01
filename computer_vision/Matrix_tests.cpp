// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

TEST(test_init_width_height) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 3, 4);
    ASSERT_EQUAL(Matrix_width(mat), 3);
    ASSERT_EQUAL(Matrix_height(mat), 4);
    Matrix_init(mat, 1, 2);
    ASSERT_EQUAL(Matrix_width(mat), 1);
    ASSERT_EQUAL(Matrix_height(mat), 2);
    delete mat;
}

TEST(test_at_print) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 2, 2);
    int value = 1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            *Matrix_at(mat, i, j) = value;
            value += 1;
        }
    }
    ostringstream s1;
    Matrix_print(mat, s1);
    ostringstream c1;
    c1 << "2 2\n1 2 \n3 4 \n";
    ASSERT_EQUAL(s1.str(), c1.str());
    
    *Matrix_at(mat, 0, 0) = 4;
    ostringstream s2;
    Matrix_print(mat, s2);
    ostringstream c2;
    c2 << "2 2\n4 2 \n3 4 \n";
    ASSERT_EQUAL(s2.str(), c2.str());
    
    delete mat;
}

TEST(test_row_column) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 2, 2);
    int value = 1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            *Matrix_at(mat, i, j) = value;
            value += 1;
        }
    }
    int *ptr1 = Matrix_at(mat, 1, 0);
    ASSERT_EQUAL(Matrix_row(mat, ptr1), 1);
    ASSERT_EQUAL(Matrix_column(mat, ptr1), 0);
    int *ptr2 = Matrix_at(mat, 0, 0);
    ASSERT_EQUAL(Matrix_row(mat, ptr2), 0);
    ASSERT_EQUAL(Matrix_column(mat, ptr2), 0);
    
    delete mat;
}

// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix

}

TEST(test_fill_edge) {
    Matrix *mat = new Matrix;
    const int width = 1;
    const int height = 1;
    const int value = 42;
    Matrix_init(mat, 1, 1);
    Matrix_fill(mat, value);

    for(int r = 0; r < height; ++r){
      for(int c = 0; c < width; ++c){
        ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
      }
    }
    
    delete mat;
}

TEST(test_fill_border_basic) {
    Matrix *mat = new Matrix;
    const int value = 42;
    const int height = 5;
    const int width = 3;
    Matrix_init(mat, 3, 5);
    Matrix_fill(mat, 0);
    Matrix_fill_border(mat, value);

    for (int i = 0; i < width; ++i) {
        ASSERT_EQUAL(*Matrix_at(mat, 0, i), 42);
        ASSERT_EQUAL(*Matrix_at(mat, height - 1, i), value);
    }
    for (int j = 0; j < height; ++j) {
        ASSERT_EQUAL(*Matrix_at(mat, j, 0), 42)
        ASSERT_EQUAL(*Matrix_at(mat, j, width - 1), value);
    }
    for (int k = 1; k < height - 1; ++k) {
        for (int l = 1; l < width - 1; ++l) {
            ASSERT_EQUAL(*Matrix_at(mat, k, l), 0);
        }
    }
    
    delete mat; // delete the Matrix
}

TEST(test_fill_border_edge) {
    Matrix *mat = new Matrix;
    const int width1 = 2;
    const int height1 = 2;
    const int value1 = 42;
    Matrix_init(mat, 2, 2);
    Matrix_fill(mat, 0);
    Matrix_fill_border(mat, value1);

    for(int r = 0; r < height1; ++r){
      for(int c = 0; c < width1; ++c){
        ASSERT_EQUAL(*Matrix_at(mat, r, c), value1);
      }
    }
    
    const int width2 = 1;
    const int height2 = 1;
    const int value2 = 4;
    Matrix_init(mat, 1, 1);
    Matrix_fill(mat, 0);
    Matrix_fill_border(mat, value2);
    
    for(int r = 0; r < height2; ++r){
      for(int c = 0; c < width2; ++c){
        ASSERT_EQUAL(*Matrix_at(mat, r, c), value2);
      }
    }
    
    delete mat;
    
}

TEST(test_max) {
    Matrix *mat = new Matrix;
    Matrix_init(mat, 2, 2);
    int value = 1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            *Matrix_at(mat, i, j) = value;
            value += 1;
        }
    }
    ASSERT_EQUAL(Matrix_max(mat), 4);
    *Matrix_at(mat, 0, 0) = 5;
    ASSERT_EQUAL(Matrix_max(mat), 5);
    delete mat;
}

TEST(test_column_of_min_value_in_row_basic) {
    Matrix *mat = new Matrix;
    int height = 3;
    int width = 3;
    Matrix_init(mat, 3, 3);
    int value = 1;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            *Matrix_at(mat, i, j) = value;
            value += 1;
        }
    }
    for (int i = 0; i < height; ++i) {
        ASSERT_EQUAL(Matrix_column_of_min_value_in_row
                     (mat, i, 0, width), 0);
    }
    delete mat;
}

TEST(test_column_of_min_value_in_row_edge) {
    Matrix *mat = new Matrix;
    const int height1 = 1;
    const int width1= 1;
    Matrix_init(mat, 1, 1);
    Matrix_fill(mat, 0);
    for (int i = 0; i < height1; ++i) {
        ASSERT_EQUAL(Matrix_column_of_min_value_in_row
                     (mat, i, 0, width1), 0);
    }
    
    const int height2 = 2;
    const int width2 = 2;
    Matrix_init(mat, 2, 2);
    Matrix_fill(mat, 0);
    for (int i = 0; i < height2; ++i) {
        ASSERT_EQUAL(Matrix_column_of_min_value_in_row
                     (mat, i, 0, width2), 0);
    }
    
    int height3 = 3;
    int width3 = 3;
    Matrix_init(mat, 3, 3);
    int value3 = 1;
    for (int i = 0; i < height3; ++i) {
        for (int j = 0; j < width3; ++j) {
            *Matrix_at(mat, i, j) = value3;
            value3 += 1;
        }
    }
    *Matrix_at(mat, 1, 2) = 0;
    *Matrix_at(mat, 1, 1) = 0;
    ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 1, 0, width3), 1);
    
    delete mat;
}

TEST(test_min_value_in_row_basic) {
    Matrix *mat = new Matrix;
    int height = 3;
    int width = 3;
    Matrix_init(mat, 3, 3);
    int value = 1;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            *Matrix_at(mat, i, j) = value;
            value += 1;
        }
    }
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, width), 1);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 1, 1, width), 5);
    ASSERT_EQUAL(Matrix_min_value_in_row(mat, 0, 0, width - 1), 1);
    
    delete mat;
}

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
