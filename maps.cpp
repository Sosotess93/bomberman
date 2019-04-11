//
// maps.cpp for indie in /home/sivaku_v/rendu/Bomberman_v2
//
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
//
// Started on  Sat Jun  4 20:08:37 2016 Vituzan Sivakumaran
// Last update Sat Feb 11 07:10:48 2017 sofiane
//

#include "maps.hpp"

Maps::Maps()
{
}

Maps::~Maps()
{
}

int				Maps::create_map(Game *bomberman, irr::scene::IMetaTriangleSelector *meta, const std::string dir, const std::string map)
{
  irr::scene::ITriangleSelector	*triSelec;
  irr::scene::IMeshSceneNode	*carre;
  std::ifstream			fichier(map.c_str(), std::ios::in);
  int				x;
  int				y;
  int				l;
  char				c;

  x = -40;
  y = 0;
  l = 0;
  c = 0;
  if (!fichier)
    return (-1);
  while (l < 18)
    {
      while (c != '\n')
      	{
      	  fichier.get(c);
  	  if (c == '1' || c == '3')
  	    {
  	      carre = bomberman->_sceneManager->addCubeSceneNode(40, 0, -1, irr::core::vector3df(x, 0, y));
  	      carre->setMaterialType(irr::video::EMT_SOLID);
	      if (c == '1')
  	      	carre->setMaterialTexture(0, bomberman->_driver->getTexture((dir + "3.jpg").c_str()));
	      else
  	       	carre->setMaterialTexture(0, bomberman->_driver->getTexture((dir + "2.jpg").c_str()));
  	      triSelec = bomberman->_sceneManager->createTriangleSelectorFromBoundingBox(carre);
  	      meta->addTriangleSelector(triSelec);
  	    }
  	  x += 40;
      	}
      c = 0;
      l++;
      x = -40;
      y += 40;
    }
  fichier.close();
}

void				Maps::create_ground(Game *bomberman, irr::scene::IMetaTriangleSelector *meta, const std::string dir)
{
  irr::scene::ITriangleSelector	*triSelec;
  irr::scene::IMeshSceneNode	*carre;
  int				x;
  int				y;

  x = 0;
  y = 0;
  while (y < (18 * 40))
    {
      while (x < (19 * 40))
  	{
  	  carre = bomberman->_sceneManager->addCubeSceneNode(40, 0, -1, irr::core::vector3df(x, -40, y));
  	  carre->setMaterialTexture(0, bomberman->_driver->getTexture((dir + "1.jpg").c_str()));
  	  carre->setMaterialType(irr::video::EMT_SOLID);
  	  triSelec = bomberman->_sceneManager->createTriangleSelectorFromBoundingBox(carre);
	  carre->setTriangleSelector(triSelec);
	  triSelec->drop();
  	  meta->addTriangleSelector(carre->getTriangleSelector());
  	  x += 40;
  	}
      x = 0;
      y += 40;
    }
}

void		Maps::init_collision(Game *bomberman, irr::scene::IMetaTriangleSelector *meta, const int i)
{
  irr::scene::ISceneNodeAnimator* anim;

  anim = bomberman->_sceneManager->createCollisionResponseAnimator(meta, bomberman->_perso[i]->_perso,
								   irr::core::vector3df(-10, 10, -10),
								   irr::core::vector3df(0, -50.0f, 0),
								   irr::core::vector3df(0, 20, 0));
  bomberman->_perso[i]->_perso->addAnimator(anim);
  anim->drop();
}

void		Maps::gen_map(Game *bomberman)
{
  irr::scene::IMetaTriangleSelector *meta = bomberman->_sceneManager->createMetaTriangleSelector();
  int		i;
  std::string	dir;
  std::string	map;
  std::srand(std::time(0));
  int		nbr;

  i = 0;
  nbr = std::rand() % 3;
  dir = "Textures/" + std::to_string(nbr) + "/";
  map = "maps/" + std::to_string(nbr) + ".txt";
  create_ground(bomberman, meta, dir);
  create_map(bomberman, meta, dir, map);
  while (bomberman->_perso[i])
    {
      init_collision(bomberman, meta, i);
      i++;
    }
}
