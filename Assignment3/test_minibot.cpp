
#include <gtest/gtest.h>
#include "minibot.h"

class MinibotTest : public ::testing::Test {
protected:
    Minibot* minibot;

    void SetUp() override {
        minibot = new Minibot("Scout", 100, 75.0, "Car", Weapon("Stinger", 40), nullptr, 999);
    }

    void TearDown() override {
        delete minibot;
    }
};

TEST_F(MinibotTest, TestGetters) {
    EXPECT_EQ(minibot->getName(), "Scout");
    EXPECT_EQ(minibot->getStrength(), 100);
    EXPECT_DOUBLE_EQ(minibot->getSpeed(), 75.0);
    EXPECT_EQ(minibot->getVehicleType(), "Car");
    EXPECT_EQ(minibot->getMainWeapon().getName(), "Stinger");
    EXPECT_EQ(minibot->getMainWeapon().getDamage(), 40);
    EXPECT_EQ(minibot->getCurrentMission(), nullptr);
}

TEST_F(MinibotTest, TestSetters) {
    minibot->setName("NewScout");
    minibot->setStrength(150);
    minibot->setSpeed(85.0);
    minibot->setVehicleType("NewCar");
    minibot->setMainWeapon(Weapon("NewStinger", 50));
    minibot->setCurrentMission(new Mission("NewMission", 5));
    minibot->setAgility(120.0);

    EXPECT_EQ(minibot->getName(), "NewScout");
    EXPECT_EQ(minibot->getStrength(), 150);
    EXPECT_DOUBLE_EQ(minibot->getSpeed(), 85.0);
    EXPECT_EQ(minibot->getVehicleType(), "NewCar");
    EXPECT_EQ(minibot->getMainWeapon().getName(), "NewStinger");
    EXPECT_EQ(minibot->getMainWeapon().getDamage(), 50);
    EXPECT_EQ(minibot->getCurrentMission()->getDescription(), "NewMission");
    EXPECT_DOUBLE_EQ(minibot->getAgility(), 120.0);
}

TEST_F(MinibotTest, TestMethods) {
    testing::internal::CaptureStdout();
    minibot->performRecon();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("is performing a reconnaissance mission"), std::string::npos);

    testing::internal::CaptureStdout();
    minibot->scout();
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("is scouting the area"), std::string::npos);
}
