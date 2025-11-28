#include <gtest/gtest.h>
#include "decepticon.h"

class DecepticonTest : public ::testing::Test {
protected:
    Decepticon* decepticon;

    void SetUp() override {
        decepticon = new Decepticon("Megatron", 100, 75.0, "Tank", Weapon("Fusion Cannon", 50), nullptr, 10);
    }

    void TearDown() override {
        delete decepticon;
    }
};


TEST_F(DecepticonTest, TestGetters) {
    EXPECT_EQ(decepticon->getName(), "Megatron");
    EXPECT_EQ(decepticon->getStrength(), 100);
    EXPECT_DOUBLE_EQ(decepticon->getSpeed(), 75.0);
    EXPECT_EQ(decepticon->getVehicleType(), "Tank");
    EXPECT_EQ(decepticon->getMainWeapon().getName(), "Fusion Cannon");
    EXPECT_EQ(decepticon->getMainWeapon().getDamage(), 50);
    EXPECT_EQ(decepticon->getCurrentMission(), nullptr);
    EXPECT_EQ(decepticon->getRuthlessness(), 10);
}

TEST_F(DecepticonTest, TestSetters) {
    decepticon->setName("Starscream");
    decepticon->setStrength(80);
    decepticon->setSpeed(90.0);
    decepticon->setVehicleType("Jet");
    decepticon->setMainWeapon(Weapon("Null Ray", 35));
    decepticon->setCurrentMission(new Mission("Destroy Autobot Base", 8));
    decepticon->setRuthlessness(15);

    EXPECT_EQ(decepticon->getName(), "Starscream");
    EXPECT_EQ(decepticon->getStrength(), 80);
    EXPECT_DOUBLE_EQ(decepticon->getSpeed(), 90.0);
    EXPECT_EQ(decepticon->getVehicleType(), "Jet");
    EXPECT_EQ(decepticon->getMainWeapon().getName(), "Null Ray");
    EXPECT_EQ(decepticon->getMainWeapon().getDamage(), 35);
    EXPECT_EQ(decepticon->getCurrentMission()->getDescription(), "Destroy Autobot Base");
    EXPECT_EQ(decepticon->getRuthlessness(), 15);
    
    delete decepticon->getCurrentMission();
}

TEST_F(DecepticonTest, TestMethods) {
    decepticon->transform();
    EXPECT_EQ(decepticon->isTransformed(), true);
    
    int initialRuthlessness = decepticon->getRuthlessness();
    decepticon->updateRuthlessness(5);
    EXPECT_EQ(decepticon->getRuthlessness(), initialRuthlessness + 5);
}

TEST_F(DecepticonTest, TestStdout) {
    testing::internal::CaptureStdout();
    decepticon->battleCry();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());

    testing::internal::CaptureStdout();
    decepticon->displayStatus();
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output2.find("Transformer: Megatron"), std::string::npos);
    
    testing::internal::CaptureStdout();
    decepticon->intimidate();
    std::string output3 = testing::internal::GetCapturedStdout();
    EXPECT_NE(output3.find("Megatron"), std::string::npos);
    EXPECT_NE(output3.find("intimidating"), std::string::npos);
}

TEST_F(DecepticonTest, TestOverloadingConstr) {
    Decepticon t1("Jazz", 90, 80.0, 100);
    EXPECT_EQ(t1.getName(), "Jazz");
    EXPECT_EQ(t1.getStrength(), 90);
    EXPECT_DOUBLE_EQ(t1.getSpeed(), 80.0);
    EXPECT_EQ(t1.getRuthlessness(), 100);
    EXPECT_EQ(t1.getVehicleType(), "Default Vehicle");
    EXPECT_EQ(t1.getMainWeapon().getName(), "Default Blaster");
    EXPECT_EQ(t1.getMainWeapon().getDamage(), 10);
    EXPECT_EQ(t1.getCurrentMission(), nullptr);
}