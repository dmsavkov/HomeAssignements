#include <gtest/gtest.h>
#include "transformer.h"
#include "autobot.h"
#include "decepticon.h"
#include "minibot.h"

void testVirtualAttack(Transformer* transformer, std::string className) {
    testing::internal::CaptureStdout();
    transformer->attack();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find(className + " " + transformer->getName() + " attacking!"), std::string::npos);
}

void testVirtualSpecialAbility(Transformer* transformer, std::string className) {
    testing::internal::CaptureStdout();
    transformer->specialAbility();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find(className + " " + transformer->getName() + " uses special ability"), std::string::npos);
}

TEST(VirtualMethodsTest, TestPolymorphism) {
    Transformer* t;

    Autobot autobot("Bumblebee", 80, 65.0, 100);
    t = &autobot;
    testVirtualAttack(t, "Autobot");
    testVirtualSpecialAbility(t, "Autobot");

    Decepticon decepticon("Megatron", 100, 80.0, 150);
    t = &decepticon;
    testVirtualAttack(t, "Decepticon");
    testVirtualSpecialAbility(t, "Decepticon");

    Minibot minibot("Cliffjumper", 70, 90.0, 85.0);
    t = &minibot;
    testVirtualAttack(t, "Minibot");
    testVirtualSpecialAbility(t, "Minibot");
}

TEST(WeaponTest, StreamOperator) {
    Weapon weapon("Ion Blaster", 50);
    
    testing::internal::CaptureStdout();
    std::cout << weapon;
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Weapon: Ion Blaster"), std::string::npos);
    EXPECT_NE(output.find("Damage: 50"), std::string::npos);
}

TEST(MissionTest, StreamOperator) {
    Mission mission("Defend Earth", 5);
    
    testing::internal::CaptureStdout();
    std::cout << mission;
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("Mission: Defend Earth"), std::string::npos);
    EXPECT_NE(output.find("Difficulty: 5"), std::string::npos);
}