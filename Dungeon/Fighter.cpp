#include "Fighter.h"

Fighter::Fighter(const std::string& name, int hp, int attackPower)
    : name(name), hp(hp), attackPower(attackPower) {}

std::string Fighter::getName() const {
    return name;
}

int Fighter::getHp() const {
    return hp;
}

int Fighter::getAttackPower() const {
    return attackPower;
}

bool Fighter::isAlive() const {
    return hp > 0;
}

void Fighter::takeDamage(int amount) {
    hp -= amount;
    if (hp < 0) {
        hp = 0;
    }
}

void Fighter::heal(int amount) {
    hp += amount;
}