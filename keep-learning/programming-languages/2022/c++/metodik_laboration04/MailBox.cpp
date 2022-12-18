//
// Created by nordi on 12/7/2022.
//

#include "MailBox.h"
#include <algorithm>

namespace metodik_laboration04 {

MailBox::MailBox(const MailBox::EmailContainer &emails) : m_emails(emails) {}
// constructor that takes a std::initializer_list of Email objects
MailBox::MailBox(std::initializer_list<Email> emails) : m_emails(emails) {}
// copy constructor
MailBox::MailBox(const MailBox &other) : m_emails(other.m_emails) {}
// move constructor
MailBox::MailBox(MailBox &&other) : m_emails(std::move(other.m_emails)) {}

size_t MailBox::size() const { return m_emails.size(); }
bool MailBox::empty() const { return m_emails.empty(); }
const Email &MailBox::at(size_t index) const { return m_emails.at(index); }
void MailBox::push_back(const Email &email) { m_emails.push_back(email); }
void MailBox::sortWho() {
  std::sort(m_emails.begin(), m_emails.end(), CompWhoDateSubject());
}
void MailBox::sortDate() {
  std::sort(m_emails.begin(), m_emails.end(), CompDateWhoSubject());
}
void MailBox::sortSubject() {
  std::sort(m_emails.begin(), m_emails.end(), CompSubjectWhoDate());
}
} // namespace metodik_laboration04