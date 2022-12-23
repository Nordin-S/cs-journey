//
// Created by nordi on 12/6/2022.
//

#include "Email.h"

namespace metodik_laboration04 {
Email::Email(const std::string &who, const std::string &date,
             const std::string &subject)
    : who(who), date(date), subject(subject) {}

std::ostream &operator<<(std::ostream &os, const Email &email) {
  os << "who: " << email.who << " date: " << email.date
     << " subject: " << email.subject;
  return os;
}
bool CompWhoDateSubject::operator()(const Email &lhs, const Email &rhs) const {
  if (lhs.who != rhs.who)
    return lhs.who < rhs.who;
  if (lhs.date != rhs.date)
    return lhs.date < rhs.date;
  return lhs.subject < rhs.subject;
}

bool CompDateWhoSubject::operator()(const Email &lhs, const Email &rhs) const {
  if (lhs.date != rhs.date)
    return lhs.date < rhs.date;
  if (lhs.who != rhs.who)
    return lhs.who < rhs.who;
  return lhs.subject < rhs.subject;
}

bool CompSubjectWhoDate::operator()(const Email &lhs, const Email &rhs) const {
  if (lhs.subject != rhs.subject)
    return lhs.subject < rhs.subject;
  if (lhs.who != rhs.who)
    return lhs.who < rhs.who;
  return lhs.date < rhs.date;
}
} // namespace metodik_laboration04