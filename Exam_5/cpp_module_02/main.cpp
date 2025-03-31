#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "Fireball.hpp"
#include "TargetGenerator.hpp"

#if 0
int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);

  delete polymorph;
  delete fireball;
}
#endif

#define RED "\033[0;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[2;35m"
#define RESET "\033[0;0m"

void	printInColor(const std::string&  msg, std::string color){
	std::cout << color << msg << RESET << std::endl;
}


#if 1
int main(void)
{
	printInColor("<---------------constructor--------------->", GREEN);
	Warlock richard("Aang", "The Avatar");

	printInColor("\n<---------------Spells--------------->", GREEN);
	Polymorph *water = new Polymorph();
	Fireball *fire = new Fireball();
	Fwoosh *air = new Fwoosh();
	richard.learnSpell(water);
	richard.learnSpell(fire);
	richard.forgetSpell("Fwoosh");
	richard.learnSpell(air);
	richard.forgetSpell("Fwoosh");
	richard.forgetSpell("Fwoosh");
	richard.learnSpell(air);
  richard.printBook();

	printInColor("\n<---------------Targets--------------->", GREEN);
	Dummy *hay = new Dummy();
	BrickWall *earth = new BrickWall();

	TargetGenerator tarGen;
	tarGen.learnTargetType(hay);
	tarGen.learnTargetType(earth);
  	tarGen.printTargets();

	printInColor("\n<---------------Launch Spells(all)--------------->", GREEN);

	richard.launchSpell("Fwoosh", *tarGen.createTarget("Target Practice Dummy"));
	richard.launchSpell("Fireball", *tarGen.createTarget("Inconspicuous Red-brick Wall"));
	richard.launchSpell("Polymorph", *tarGen.createTarget("Target Practice Dummy"));

	printInColor("\n<---------------Forgotten \"Fwoosh\":--------------->", GREEN);

	richard.forgetSpell("Fwoosh");
	richard.launchSpell("Fwoosh", *tarGen.createTarget("Target Practice Dummy"));
	richard.launchSpell("Fireball", *tarGen.createTarget("Inconspicuous Red-brick Wall"));
	richard.launchSpell("Polymorph", *tarGen.createTarget("Target Practice Dummy"));

	printInColor("\n<---------------Relearn Fwoosh, then launch Spells--------------->", GREEN);
	richard.learnSpell(air);
	richard.launchSpell("Fwoosh", *tarGen.createTarget("Target Practice Dummy"));
	richard.launchSpell("Fireball", *tarGen.createTarget("Inconspicuous Red-brick Wall"));
	richard.launchSpell("Polymorph", *tarGen.createTarget("Target Practice Dummy"));

	printInColor("\n<---------------Non-existant spell:--------------->", GREEN);

	richard.launchSpell("ACID", *tarGen.createTarget("Inconspicuous Red-brick Wall"));
	richard.forgetSpell("ACID");
	richard.launchSpell("ACID", *tarGen.createTarget("Target Practice Dummy"));

	printInColor("\n<---------------Non existant target--------------->", GREEN);
	richard.launchSpell("Fwoosh", *tarGen.createTarget("I am not a target"));

	printInColor("\n<---------------Destructors::--------------->", GREEN);
	delete water;
	delete fire;
	delete air;
	delete hay;
	delete earth;
	return (0);
}
#endif
