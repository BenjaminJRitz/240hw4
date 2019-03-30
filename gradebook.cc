// Copyright 2019 <Benjamin Ritz>
#include "../hw4/gradebook.h"

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
  for (int i = 0; i < static_cast<int>(grades_.size()); ++i) {
    newGradeBook.Add(grades_[i]);
  }  // ending bracket for for loop
  newGradeBook.Add(rhs);
  return newGradeBook;
}  // ending bracket for method operator+ (gradebook + double)

const GradeBook GradeBook::operator+(const GradeBook& rhs) const {
  GradeBook newGradeBook;
  for (int i = 0; i < static_cast<int>(grades_.size()); ++i) {
    newGradeBook.Add(grades_[i]);
  }  // ending bracket for for loop
  for (int i = 0; i < static_cast<int>(rhs.GetSize()); ++i) {
    newGradeBook.Add(rhs.Get(i));
  }  // ending bracket for for loop
  return newGradeBook;
}  // ending bracket for method operator+ (gradebook + gradebook)

bool GradeBook::operator==(const GradeBook& rhs) const {
  double callingAve = 0;
    double paramAve = 0;
    bool ret;

    if ((static_cast<int>(grades_.size())) > 0) {
        for (int i = 0; i < (static_cast<int>(grades_.size())); ++i) {
            callingAve += grades_[i];
        }
        callingAve /= (static_cast<int>(grades_.size()));
    } else {
        callingAve = -INFINITY;
    }  // ending bracket of callingAve if/else

    if (rhs.GetGPA() == NAN) {
        paramAve = -INFINITY;
    } else {
        paramAve = rhs.GetGPA();
    }  // ending bracket of parameter average if/else

    if ( ((callingAve - paramAve) > (0.00001)) ||
        ((callingAve - paramAve) < (-0.00001))) {
            ret = false;
    } else {
        ret = true;
    }  // ending bracket for outside param if/else
    return ret;
}  // ending bracket for method operator == (gradebook == gradebook)

bool GradeBook::operator==(double rhs) const {
  double callingAve = 0;
  double paramAve = rhs;
  bool ret;

  if ((static_cast<int>(grades_.size())) > 0) {
    for (int i = 0; i < (static_cast<int>(grades_.size())); ++i) {
      callingAve += grades_[i];
    }
    callingAve /= (static_cast<int>(grades_.size()));
    } else {
      callingAve = -INFINITY;
    }  // ending bracket of callingAve if/else

    if ( ((callingAve - paramAve) > (0.00001)) ||
        ((callingAve - paramAve) < (-0.00001))) {
          ret = false;
    } else {
    ret = true;
  }  // ending bracket for outside param if/else
  return ret;
}  // ending bracket for method operator == (gradebook == double)

bool GradeBook::operator<(const GradeBook& rhs) const {
  double callingAve = 0;
  double paramAve = 0;
  double callingMax = 0;
  double paramMax = 0;
  bool ret;

  if ((static_cast<int>(grades_.size())) > 0) {
    for (int i = 0; i < (static_cast<int>(grades_.size())); ++i) {
      callingAve += grades_[i];
    }
    callingAve /= (static_cast<int>(grades_.size()));
    } else {
      callingAve = -INFINITY;
    }  // ending bracket of callingAve if/else

    if (rhs.GetGPA() == NAN) {
      paramAve = -INFINITY;
    } else {
      paramAve = rhs.GetGPA();
    }  // ending bracket of parameter average if/else

    if ( ((callingAve - paramAve) > (0.00001)) ||
       ((callingAve - paramAve) < (-0.00001))) {
          if (callingAve < paramAve) {
          ret = true;
    } else {
          ret = false;
    }  // ending bracket for if/else
    } else {
      paramMax = rhs.GetMax();
      for (int i = 0; i < (static_cast<int>(grades_.size())); ++i) {
        if (grades_[i] > callingMax) {
          callingMax = grades_[i];
        }  // ending bracket for inner if
      }  // ending bracket for for loop
      if (callingMax < paramMax) {
        ret = true;
      } else {
        ret = false;
      }  // ending bracket for inner if/else
  }  // ending bracket for outer if/else
  return ret;
}  // ending bracket for method operator < (gradebook < gradebook)

bool GradeBook::operator<(double rhs) const {
  bool ret = false;
  double callingAve = 0;
  if ((static_cast<int>(grades_.size())) > 0) {
    for (int i = 0; i < (static_cast<int>(grades_.size())); ++i) {
      callingAve += grades_[i];
    }
    callingAve /= (static_cast<int>(grades_.size()));
  } else {
    callingAve = -INFINITY;
  }  // ending bracket of callingAve if/else
  if (callingAve < rhs) {
    ret = true;
  }  // ending bracket for if
  return ret;
}  // ending bracket for method operator < (gradebook < double)

const GradeBook operator+(double lhs, const GradeBook& rhs) {
  GradeBook newGradeBook;
  for (int i = 0; i < rhs.GetSize(); ++i) {
    newGradeBook.Add(rhs.Get(i));
  }  // ending bracket for for loop
  newGradeBook.Add(lhs);
  return newGradeBook;
}  // ending bracket for function operator+ (double + gradebook)

bool operator==(double lhs, const GradeBook& rhs) {
  bool ret = true;
  double rhsAve = rhs.GetGPA();
  if ( ((lhs - rhsAve) > (0.00001)) ||
        ((lhs - rhsAve) < (-0.00001))) {
          ret = false;
  }  // ending bracekt for if
  return ret;
}  // ending bracket for function operator== (double == gradebook)

bool operator<(double lhs, const GradeBook& rhs) {
  bool ret = false;
  if (lhs < rhs.GetGPA()) {
    ret = true;
  }  // ending bracekt for if
  return ret;
}  // ending bracket for function operator< (double < gradebook)
