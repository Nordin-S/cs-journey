//
// Created by nordi on 12/6/2022.
//

#ifndef METODIK_LABORATION04_EMAIL_H
#define METODIK_LABORATION04_EMAIL_H

#include <ostream>
#include <string>
namespace metodik_laboration04 {
class Email {
private:
  std::string who;
  std::string date;
  std::string subject;

public:
  Email() = default;
  Email(const std::string &who, const std::string &date,
        const std::string &subject);

  friend std::ostream &operator<<(std::ostream &os, const Email &email);
  friend struct CompWhoDateSubject;
  friend struct CompDateWhoSubject;
  friend struct CompSubjectWhoDate;
};
struct CompWhoDateSubject {
  bool operator()(const Email &lhs, const Email &rhs) const;
};

struct CompDateWhoSubject {
  bool operator()(const Email &lhs, const Email &rhs) const;
};

struct CompSubjectWhoDate {
  bool operator()(const Email &lhs, const Email &rhs) const;
};
} // namespace metodik_laboration04

#endif // METODIK_LABORATION04_EMAIL_H
