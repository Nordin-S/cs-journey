#include <iostream>
#include "MailBox.h"
#include "Email.h"
using namespace metodik_laboration04;

//template <typename MailBox>
void Show(const MailBox &mailbox) {
  // print the number of emails in the mailbox
  std::cout << "Number of emails: " << mailbox.size() << "\n";

  // print each email in the mailbox
  for (size_t i = 0; i < mailbox.size(); ++i) {
    std::cout << "Email " << i << ": " << mailbox.at(i) << "\n";
  }
}

int main() {
  // create a Mailbox object using the default constructor
  MailBox mailbox1;

  // add some Email objects to mailbox1
  mailbox1.push_back(Email("Alice", "2021-01-01", "Meeting tomorrow"));
  mailbox1.push_back(Email("Charlie", "2022-01-03", "Meeting location changed"));
  mailbox1.push_back(Email("Bob", "2020-01-02", "Meeting postponed"));

  Show(mailbox1);

  // create a Mailbox object using the initializer_list constructor
  MailBox mailbox2 = {
      Email("Alice", "2022-01-01", "Meeting tomorrow"),
      Email("Charlie", "2021-01-03", "Meeting location changed"),
      Email("Bob", "2022-01-02", "Meeting postponed")
  };
  Show(mailbox2);

  // create a Mailbox object using the copy constructor
  MailBox mailbox3(mailbox1);
  mailbox3.sortDate();
  Show(mailbox3);

  // create a Mailbox object using the move constructor
  MailBox mailbox4(std::move(mailbox1));
  Show(mailbox4);
  return 0;
}
