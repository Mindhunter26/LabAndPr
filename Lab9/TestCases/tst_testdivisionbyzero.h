#ifndef TST_TESTDIVISIONBYZERO_H
#define TST_TESTDIVISIONBYZERO_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IKeypad.h>
#include <ILatch.h>
#include <lockcontroller.h>

using namespace testing;

class MockKeypad : public IKeypad
{
public:
    MOCK_METHOD(bool, isActive, (), (override));
    MOCK_METHOD(void, wait, (), (override));
    MOCK_METHOD(PasswordResponse, requestPassword, (), (override));
};

class MockLatch : public ILatch
{
public:
    MOCK_METHOD(bool, isActive, (), (override));
    MOCK_METHOD(DoorStatus, open, (), (override));
    MOCK_METHOD(DoorStatus, close, (), (override));
    MOCK_METHOD(DoorStatus, getDoorStatus, (), (override));
};

class LockControllerFixture : public Test
{
public:
    MockKeypad keypad;
    MockLatch latch;
    LockController* lc;

    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override
    {
        lc = new LockController(&keypad, &latch);
    }
    void TearDown() override
    {
        delete lc;
    };
};

// Test_1
TEST_F(LockControllerFixture, isWaiting)
{
    // Arrange
    EXPECT_CALL(keypad, wait())
            .Times(1)
            .WillOnce(Return());

    // Act
    lc->wait();

    // Assert
}

//Test_2
TEST_F(LockControllerFixture, ifDoorClosedCheckIsDoorOpen)
{
    // Arrange
    EXPECT_CALL(latch, getDoorStatus())
            .Times(1)
            .WillOnce(Return(DoorStatus::CLOSE));

    // Act
    bool res = lc->isDoorOpen();

    // Assert
    ASSERT_FALSE(res);
}

//Test_3
TEST_F(LockControllerFixture, ifDoorOpenCheckIsDoorOpen)
{
    // Arrange
    EXPECT_CALL(latch, getDoorStatus())
            .Times(1)
            .WillOnce(Return(DoorStatus::OPEN));

    //Act
    bool res = lc->isDoorOpen();

    // Assert
    ASSERT_TRUE(res);
}

//Test_4
TEST_F(LockControllerFixture, checkLockController)
{
   // Arrange
    EXPECT_CALL(latch, open())
            .Times(1)
            .WillOnce(Return(DoorStatus::OPEN));

   // Act
    auto res = lc->unlockDoor();

   // Assert
    ASSERT_EQ(res, DoorStatus::OPEN);
}

//Test_5
TEST_F(LockControllerFixture, checkLockController2)
{
    // Arrange
    EXPECT_CALL(latch, close())
            .Times(1)
            .WillOnce(Return(DoorStatus::CLOSE));
    // Act
    auto res = lc->lockDoor();

    // Assert
    ASSERT_EQ(res, DoorStatus::CLOSE);
}

//Test_6
TEST_F(LockControllerFixture, isHardWareWorks)
{
    // Arrange
    EXPECT_CALL(keypad, isActive())
            .Times(1)
            .WillOnce(Return(true));
    EXPECT_CALL(latch, isActive())
            .Times(1)
            .WillOnce(Return(true));

    // Act
    auto res = lc->hardWareCheck();

    // Assert
    ASSERT_EQ(res, HardWareStatus::OK);
}

//Test_7
TEST_F(LockControllerFixture, isHardWareNotWork)
{
    // Arrange
    delete lc;

    lc = new LockController(nullptr, &latch);

    EXPECT_CALL(keypad, isActive())
            .Times(AtLeast(0))
            .WillOnce(Return(true));
    EXPECT_CALL(latch, isActive())
            .Times(AtLeast(0))
            .WillOnce(Return(true));

    // Act
    auto res = lc->hardWareCheck();

    // Assert
    ASSERT_EQ(res, HardWareStatus::ERROR);
}

//Test_8
TEST_F(LockControllerFixture, isLatchNotWork)
{
    // Arrange
        EXPECT_CALL(keypad, isActive())
                .Times(AtLeast(0))
                .WillOnce(Return(true));
        EXPECT_CALL(latch, isActive())
                .Times(AtLeast(0))
                .WillOnce(Return(false));

        // Act
        auto res = lc->hardWareCheck();

        // Assert
        ASSERT_EQ(res, HardWareStatus::ERROR);
}


//Test_9
TEST_F(LockControllerFixture, isPasswordCorrect) {
    // Arrange
    PasswordResponse passResp;

    passResp.password = "0000";
    passResp.status = PasswordResponse::Status::OK;
    EXPECT_CALL(keypad, requestPassword())
            .Times(1)
            .WillOnce(Return(passResp));

    // Act
    auto res = lc->isCorrectPassword();

    // Assert
    ASSERT_TRUE(res);
}

//Test_10
TEST_F(LockControllerFixture, isPasswordIncorrect) {
    // Arrange
    PasswordResponse passResp;

    passResp.password = "1111";
    passResp.status = PasswordResponse::Status::OK;

    EXPECT_CALL(keypad, requestPassword())
            .Times(1)
            .WillOnce(Return(passResp));

    // Act
    auto res = lc->isCorrectPassword();

    // Assert
    ASSERT_FALSE(res);
}

//Test_11
TEST_F(LockControllerFixture, isPasswordChanging)
{
    // Arrange
       PasswordResponse passResp1;
       passResp1.password = "0000";
       passResp1.status = PasswordResponse::Status::OK;

       PasswordResponse passResp2;
       passResp2.password = "1111";
       passResp2.status = PasswordResponse::Status::OK;

       PasswordResponse passResp3;
       passResp3.password = "1111";
       passResp3.status = PasswordResponse::Status::OK;

       EXPECT_CALL(keypad, requestPassword())
               .Times(3)
               .WillOnce(Return(passResp1))
               .WillOnce(Return(passResp2))
               .WillOnce(Return(passResp3));

       // Act
       lc->resetPassword();
       auto res = lc->isCorrectPassword();

       // Assert
       ASSERT_TRUE(res);
}

//Test_12
TEST_F(LockControllerFixture, isPasswordChanging2)
{
    // Arrange
        PasswordResponse passResp1;
        passResp1.password = "0000";
        passResp1.status = PasswordResponse::Status::OK;

        PasswordResponse passResp2;
        passResp2.password = "9876";
        passResp2.status = PasswordResponse::Status::OK;

        PasswordResponse passResp3;
        passResp3.password = "9876";
        passResp3.status = PasswordResponse::Status::OK;

        PasswordResponse passResp4;
        passResp4.password = "1111";
        passResp4.status = PasswordResponse::Status::OK;

        PasswordResponse passResp5;
        passResp5.password = "1111";
        passResp5.status = PasswordResponse::Status::OK;

        EXPECT_CALL(keypad, requestPassword())
                .Times(5)
                .WillOnce(Return(passResp1))
                .WillOnce(Return(passResp2))
                .WillOnce(Return(passResp3))
                .WillOnce(Return(passResp4))
                .WillOnce(Return(passResp5));

        // Act
        lc->resetPassword();
        lc->resetPassword();
        auto res = lc->isCorrectPassword();

        // Assert
        ASSERT_TRUE(res);
}

#endif // TST_TESTDIVISIONBYZERO_H
