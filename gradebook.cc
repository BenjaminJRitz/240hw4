#include "gradebook.h"


int GradeBook::GetSize() const {
  return grades_.size();
}

void GradeBook::Add(double grade) {
  grades_.push_back(grade);
}
double GradeBook::Get(size_t index) const {
  return index < grades_.size() ? grades_[index] : NAN;
}

double GradeBook::GetGPA() const {
  double ret;
  double sum = 0;
  if ((static_cast<int>(grades_.size())) == 0) {
    ret = NAN;
  } else {
    for (int i = 0; i < (static_cast<int>(grades_.size())); ++i) {
      sum += grades_[i];
    }  // ending bracket for for loop
    ret = sum / (static_cast<int>(grades_.size()));
  }  // ending bracket for if else
  return ret;
}  // ending bracket for method GradeBook

double GradeBook::GetMax() const {
  double ret = 0;
  if ((static_cast<int>(grades_.size())) == 0) {
    ret = NAN;
  } else {
    for (int i = 0; i < (static_cast<int>(grades_.size())); ++i) {
      if (grades_[i] > ret) {
        ret = grades_[i];
      }  // ending bracket for inner if
    }  // ending bracket for for loop
  }  // ending bracket for if else
  return ret;
}  // ending bracket for method GetMax 

const GradeBook GradeBook::operator+(double rhs) const {
  GradeBook newGradeBook;
  for (int i = 0; i < grades_.size(); ++i) {
    newGradeBook.Add(grades_[i]);
  }  // ending bracket for for loop
  newGradeBook.Add(rhs);
  return newGradeBook;
}  // ending bracket for method operator+ (gradebook + double)

const GradeBook GradeBook::operator+(const GradeBook& rhs) const {
  GradeBook newGradeBook;
  //int count;
  for (int i = 0; i < grades_.size(); ++i) {
    newGradeBook.Add(grades_[i]);
  }  // ending bracket for for loop
  //count = newGradeBook.GetSize();
  for (int i = 0; i < rhs.GetSize(); ++i) {
    newGradeBook.Add(rhs.Get(i));
  }  // ending bracket for for loop
  return newGradeBook;
}  // ending bracket for method operator+ (gradebook + gradebook)