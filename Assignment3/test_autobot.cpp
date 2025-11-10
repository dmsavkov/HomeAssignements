#include <gtest/gtest.h>
#include "autobot.h"

class AutobotTest : public ::testing::Test {
protected:
    Autobot* autobot;

    void SetUp() override {
        autobot = new Autobot("Bumblebee", 100, 75.0, "Car", Weapon("Stinger", 40), nullptr, 999);
    }

    void TearDown() override {
        delete autobot;
    }
};


TEST_F(AutobotTest, TestGetters) {
    EXPECT_EQ(autobot->getName(), "Bumblebee");
    EXPECT_EQ(autobot->getStrength(), 100);
    EXPECT_DOUBLE_EQ(autobot->getSpeed(), 75.0);
    EXPECT_EQ(autobot->getVehicleType(), "Car");
    EXPECT_EQ(autobot->getMainWeapon().getName(), "Stinger");
    EXPECT_EQ(autobot->getMainWeapon().getDamage(), 40);
    EXPECT_EQ(autobot->getCurrentMission(), nullptr);
}

TEST_F(AutobotTest, TestSetters) {
    autobot->setName("Bumblebee");
    autobot->setStrength(80);
    autobot->setSpeed(65.0);
    autobot->setVehicleType("Car");
    autobot->setMainWeapon(Weapon("Stinger", 40));
    autobot->setCurrentMission(new Mission("Rescue Mission", 3));
    autobot->setLoyalty(500);

    EXPECT_EQ(autobot->getName(), "Bumblebee");
    EXPECT_EQ(autobot->getStrength(), 80);
    EXPECT_DOUBLE_EQ(autobot->getSpeed(), 65.0);
    EXPECT_EQ(autobot->getVehicleType(), "Car");
    EXPECT_EQ(autobot->getMainWeapon().getName(), "Stinger");
    EXPECT_EQ(autobot->getMainWeapon().getDamage(), 40);
    EXPECT_EQ(autobot->getCurrentMission()->getDescription(), "Rescue Mission");
    EXPECT_EQ(autobot->getLoyalty(), 500);
}

TEST_F(AutobotTest, TestMethods) {
    autobot->transform();
    EXPECT_EQ(autobot->isTransformed(), true);
}

TEST_F(AutobotTest, TestStdout) {
    testing::internal::CaptureStdout();
    autobot->battleCry();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());

    testing::internal::CaptureStdout();
    autobot->displayStatus();
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Transformer: Bumblebee"), std::string::npos);
}