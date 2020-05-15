#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;


int HeroSkill;
int MonsterSkill;

class Character{
public:
  
  string name;
  string skillname;
  int skill;
  Character(string w){
    name=w;
  };
  void battle(){
    skill = rand()%3;
  };
  int GetSkill(){return skill;};
};

class Hero:public Character{
public:
  Hero(string h):Character("Hero"){};
  void HeroTurn(){
    if(skill == 0){
      skillname = "sword";
    }
    else if(skill == 1){
      skillname = "bow";
    }
    else{
      skillname = "lance";
    }
    cout << name << ":" << skillname << endl;
  };
};

class Monster:public Character{
public:
  Monster(string m):Character("Monster"){};
   void MonsterTurn(){
    if(skill == 0){
      skillname = "claw";
    }
    else if(skill == 1){
      skillname = "tail";
    }
    else{
      skillname = "fang";
    }
    cout << name << ":" << skillname << endl;
  };
  void SpecialSkill(){
    skill = (HeroSkill+1)%3;
    cout << "Monster:Special Skill!" << endl;
  }
    
};

class Judge{
public:
  
  
  void set(){
   
    int a = (HeroSkill-MonsterSkill+3)%3;
    if(a == 0){
    cout << "DRAW" << endl;
  }
  else if(a == 1){
    cout << "Hero WIN!"<< endl;
  }
  else{
    cout << "Monster WIN!"<< endl;
  }
  };
};


int main() {
  Hero newHero("Hero");
  Monster newMonster("Monster");
  Judge newJudge;
  Hero* phero = &newHero;
  Monster* pmonster = &newMonster;
  Judge* pjudge = &newJudge;

  srand((unsigned int)time(NULL));
  
  phero->battle();
  HeroSkill = phero->GetSkill();
  phero->HeroTurn();
  
  int s = rand()%1000;
  if(s == 0){
    pmonster->SpecialSkill();
  }
  else{
  rand(); rand(); rand(); rand(); rand();
  pmonster->battle();
  }
  MonsterSkill = pmonster->GetSkill();
  pmonster->MonsterTurn();
 
  pjudge->set();
  
      return 0;
}
