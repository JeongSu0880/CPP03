#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:

public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &original);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &original);

	ClapTrap &operator=(const ClapTrap &original);

	void attack(const std:: string& target);
	void guardGate();
};

#endif