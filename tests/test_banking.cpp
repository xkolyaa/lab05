#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Account.h"
#include "Transaction.h"

class MockAccount : public Account {
public:
    MockAccount(int id, int balance) : Account(id, balance) {}
    MOCK_CONST_METHOD0(GetBalance, int());
    MOCK_METHOD0(Lock, void());
    MOCK_METHOD0(Unlock, void());
};

TEST(Account, Methods) {
    Account acc(1, 1000);
    EXPECT_EQ(acc.GetBalance(), 1000);
    acc.Lock();
    EXPECT_THROW(acc.ChangeBalance(100), std::runtime_error);
    acc.Unlock();
    acc.ChangeBalance(100);
    EXPECT_EQ(acc.GetBalance(), 1100);
}

TEST(Transaction, Logic) {
    Transaction tr;
    Account a1(1, 1000), a2(2, 1000);
    EXPECT_TRUE(tr.Make(a1, a2, 200));
    EXPECT_EQ(a1.GetBalance(), 800);
    EXPECT_EQ(a2.GetBalance(), 1200);
    EXPECT_FALSE(tr.Make(a1, a2, 5000));
}

TEST(Account, Mock) {
    MockAccount m_acc(1, 100);
    EXPECT_CALL(m_acc, GetBalance()).WillOnce(testing::Return(100));
    EXPECT_EQ(m_acc.GetBalance(), 100);
}
