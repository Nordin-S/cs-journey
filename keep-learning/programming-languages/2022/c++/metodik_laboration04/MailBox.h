//
// Created by nordi on 12/7/2022.
//

#ifndef METODIK_LABORATION04_MAILBOX_H
#define METODIK_LABORATION04_MAILBOX_H

#include "Email.h"
#include <vector>
namespace metodik_laboration04 {

class MailBox {
public:
  // container type for storing Email objects
  using EmailContainer = std::vector<Email>;
  // default constructor
  MailBox() = default;
  explicit MailBox(const EmailContainer &emails);
  // constructor that takes a std::initializer_list of Email objects
  MailBox(std::initializer_list<Email> emails);
  // copy constructor
  MailBox(const MailBox &other);
  // move constructor
  MailBox(MailBox &&other);

  // methods for accessing and manipulating the emails container
  [[nodiscard]] size_t size() const;
  [[nodiscard]] bool empty() const;
  [[nodiscard]] const Email &at(size_t index) const;
  void push_back(const Email &email);
  void sortWho();
  void sortDate();
  void sortSubject();
private:
  // member container for storing Email objects
  EmailContainer m_emails;
};

} // namespace metodik_laboration04

#endif // METODIK_LABORATION04_MAILBOX_H
