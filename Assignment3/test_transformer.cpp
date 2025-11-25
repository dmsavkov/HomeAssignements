#include <gtest/gtest.h>
#include "transformer.h"

class TransformerTest : public ::testing::Test {
protected:
    Transformer* transformer;

    void SetUp() override {
        transformer = new Transformer("Optimus Prime", 100, 75.0, "Truck", 
                                     Weapon("Ion Blaster", 50), 
                                     new Mission("Defend Earth", 5));
    }

    void TearDown() override {
        delete transformer->getCurrentMission(); // clean mission before
        delete transformer;
    }
}; 


TEST_F(TransformerTest, TestGetters) {
    EXPECT_EQ(transformer->getName(), "Optimus Prime");
    EXPECT_EQ(transformer->getStrength(), 100);
    EXPECT_DOUBLE_EQ(transformer->getSpeed(), 75.0);
    EXPECT_EQ(transformer->getVehicleType(), "Truck");

    EXPECT_EQ(transformer->getMainWeapon().getName(), "Ion Blaster");
    EXPECT_EQ(transformer->getMainWeapon().getDamage(), 50);

    EXPECT_EQ(transformer->getCurrentMission()->getDescription(), "Defend Earth");
    EXPECT_EQ(transformer->getCurrentMission()->getDifficulty(), 5);
}

TEST_F(TransformerTest, TestSetters) {
    transformer->setName("Bumblebee");
    transformer->setStrength(80);
    transformer->setSpeed(65.0);
    transformer->setVehicleType("Car");
    transformer->setMainWeapon(Weapon("Stinger", 40));
    transformer->setCurrentMission(new Mission("Rescue Mission", 3));

    EXPECT_EQ(transformer->getName(), "Bumblebee");
    EXPECT_EQ(transformer->getStrength(), 80);
    EXPECT_DOUBLE_EQ(transformer->getSpeed(), 65.0);
    EXPECT_EQ(transformer->getVehicleType(), "Car");
    EXPECT_EQ(transformer->getMainWeapon().getName(), "Stinger");
    EXPECT_EQ(transformer->getMainWeapon().getDamage(), 40);
    EXPECT_EQ(transformer->getCurrentMission()->getDescription(), "Rescue Mission");
}

TEST_F(TransformerTest, TestMethods) {
    transformer->transform();
    EXPECT_EQ(transformer->isTransformed(), true);
}

TEST_F(TransformerTest, TestStdout) {
    testing::internal::CaptureStdout();
    transformer->battleCry();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());

    testing::internal::CaptureStdout();
    transformer->displayStatus();
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Transformer: Optimus Prime"), std::string::npos);

    testing::internal::CaptureStdout();
    std::cout << *transformer;
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("I'm Optimus Prime!"), std::string::npos);
}

TEST_F(TransformerTest, TestWeaponStreamOperator) {
    Weapon weapon = transformer->getMainWeapon();
    
    testing::internal::CaptureStdout();
    std::cout << weapon;
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Weapon: Ion Blaster"), std::string::npos);
    EXPECT_NE(output.find("Damage: 50"), std::string::npos);
}

TEST_F(TransformerTest, TestMissionStreamOperator) {
    Mission* mission = transformer->getCurrentMission();
    ASSERT_NE(mission, nullptr);
    
    testing::internal::CaptureStdout();
    std::cout << *mission;
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Mission: Defend Earth"), std::string::npos);
    EXPECT_NE(output.find("Difficulty: 5"), std::string::npos);
}