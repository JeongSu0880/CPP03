#include "ScavTrap.hpp"

int main() {
	ScavTrap scavTrap1("A");
    ScavTrap scavTrap2("B");

    // 공격 시도 -> 객체를 받는 게 아니기 때문에 실제 포인트가 줄지는 않는다..
    scavTrap1.attack("B");
    scavTrap2.attack("A");

    scavTrap1.takeDamage(10);
    scavTrap2.takeDamage(20);

    scavTrap1.beRepaired(15);
    scavTrap2.beRepaired(5);

    // 이미 데미지를 충분히 받아서 0인 경우
	scavTrap2.takeDamage(100);
	scavTrap2.takeDamage(100);

	scavTrap2.beRepaired(100);
	scavTrap1.beRepaired(1);

    scavTrap1.takeDamage(30);
    scavTrap2.takeDamage(50);

	scavTrap1.guardGate();

    return 0;
}