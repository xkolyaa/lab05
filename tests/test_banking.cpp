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

TEST(Account, BasicMethods) {
    Account acc(1, 1000);
    EXPECT_EQ(acc.GetBalance(), 1000);
}

TEST(Transaction, Logic) {
    Transaction tr;
    Account a1(1, 1000), a2(2, 1000);
    
    // Тестируем только успешный перевод и нехватку средств
    EXPECT_TRUE(tr.Make(a1, a2, 200));
    EXPECT_FALSE(tr.Make(a1, a2, 2000));
}

TEST(Account, MockExample) {
    MockAccount m_acc(1, 100);
    EXPECT_CALL(m_acc, GetBalance()).WillOnce(testing::Return(100));
    EXPECT_EQ(m_acc.GetBalance(), 100);
}
