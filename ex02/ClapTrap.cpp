#include "ClapTrap.hpp"

/*OCCF 구현부*/
ClapTrap::ClapTrap() : name("No name"), maxHit(100), maxEnergy(100), damage(30){
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;

	this->hitPoint = maxHit;
	this->energyPoint = maxEnergy;
	this->attackDamage = damage;
}

ClapTrap::ClapTrap(const std::string &name, long long maxHit, long long maxEnergy, long long damage) : name(name), maxHit(maxHit), maxEnergy(maxEnergy), damage(damage) {
	std::cout << "ClapTrap " << name << " has been created!" << std::endl;
	
	this->hitPoint = maxHit;
	this->energyPoint = maxEnergy;
	this->attackDamage = damage;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original) {
	std::cout << "ClapTrap " << name << " has been copied!" << std::endl;
	*this = original;
}

ClapTrap &ClapTrap::operator=(const ClapTrap& original) {
	if (this != &original) {
		this->name = original.getName();
		this->hitPoint = original.getHitPoint();
		this->energyPoint = original.getEnergyPoint();
		this->attackDamage = original.getAttackDamage();
	}

	return *this;	
}

/*subject 요구 함수 구현부*/
void ClapTrap::attack(const std:: string& target) {
	if (this->energyPoint <= MIN) {
		std::cout << name << " has failed to attack. " << "Out of energy!" << std::endl;
		return;
	}

	--(this->energyPoint);

	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	//더 감소할 damage가 안남았을때는 그냥 return
	if (this->hitPoint == MIN) {
		return;
	}

	long long tmpPoint = this->hitPoint - amount;
	this->hitPoint = (tmpPoint <= MIN) ? MIN : tmpPoint;

	std::cout << name << " takes " << amount << " damage! " << name << " has " << this->hitPoint << " hit points remaining." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energyPoint <= MIN) {
		std::cout << name << " has failed to repair. " << "Out of energy!" << std::endl;
		return;
	}

	if (this->hitPoint == maxHit) {
		return;
	}

	long long tmpPoint = this->hitPoint + amount;
	this->hitPoint = (tmpPoint >= maxHit) ? maxHit : tmpPoint;

	--(this->energyPoint);

	std::cout << name << " has repaired " << amount << "! " << name << " has " << this->hitPoint << " hit points remaining." << std::endl;
}

/*getter, setter 구현부*/
const std::string &ClapTrap::getName() const {
	return this->name;
}

long long ClapTrap::getHitPoint() const {
	return this->hitPoint;
}

long long ClapTrap::getEnergyPoint() const {
	return this->energyPoint;
}

long long ClapTrap::getAttackDamage() const {
	return this->attackDamage;
}

void	ClapTrap::setName(std::string name) {
	this->name = name;
}

void	ClapTrap::setHitPoint(unsigned int point) {
	this->hitPoint = point;
}

void	ClapTrap::setEnergyPoint(unsigned int point) {
	this->energyPoint = point;
}

void	ClapTrap::setAttackDamage(unsigned int damage) {
	this->attackDamage = damage;
}