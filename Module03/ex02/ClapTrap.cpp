/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:00:36 by romain            #+#    #+#             */
/*   Updated: 2023/11/15 21:52:16 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;

ClapTrap::ClapTrap(void) : _name("no name"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	cout << _name << "_ Default constructor called" << endl;
}

ClapTrap::ClapTrap(string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	cout << _name <<"_ Constructor called" << endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	this->_name = copy.getName();
	this->_hitPoints = copy.getHitPoints();
	this->_energyPoints = copy.getEnergyPoints();
	this->_attackDamage = copy.getAttackDamage();
	cout << _name << "_ Copy constructor called" << endl;
}

ClapTrap::~ClapTrap(void)
{
	cout << _name << "_ Destructor called" << endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &src)
{
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	cout << _name << "_ Assignation operator called" << endl;
	return *this;
}

void ClapTrap::attack(string const &target)
{
	if (_hitPoints > 0 &&  _energyPoints > 0)
	{
		cout << "ClapTrap " << _name << " attacks " << target << ", causing "
			<< _attackDamage << " points of damadge!" << endl;
		_energyPoints--;
	}
	else
		cout << "ClapTrap " << _name << " can't attack..." << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{

	cout << "ClapTrap " << _name << " takes " << amount << " points of damage !" << endl;
	_hitPoints -= amount;
}

void ClapTrap::beRepaired( unsigned int amount)
{
	if (_hitPoints > 0 && _energyPoints > 0)
	{
		cout << "ClapTrap " << _name << " recovers " << amount << " hit points." << endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else
		cout << "ClapTrap " << _name << " can't recover hit points..." << endl;

}

string const &ClapTrap::getName(void) const
{
	return _name;
}

int const &ClapTrap::getHitPoints(void) const
{
	return _hitPoints;
}

int const &ClapTrap::getEnergyPoints(void) const
{
	return _energyPoints;
}

int const &ClapTrap::getAttackDamage(void) const
{
	return _attackDamage;
}