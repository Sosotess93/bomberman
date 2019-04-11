//
// TestGui.cpp for  in /home/charra_s/game_b/map
//
// Made by Charrad Sofiane
// Login   <charra_s@epitech.net>
//
// Started on  Fri Jun  3 16:21:08 2016 Charrad Sofiane
// Last update Mon Jun  6 18:08:09 2016 Charrad Sofiane
//

#include <irr/irrlicht.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif


int main()
{
  int	i;

  i = -1;
  const char* const  tab[] = {
    "./splash_ass/swar.jpg",
    "./splash_ass/Splash_1.PNG",
    "./splash_ass/Splash_2.jpg",
    "./splash_ass/Splash_3.PNG",
    "./splash_ass/Splash_4.PNG"

  };
  irr::video::E_DRIVER_TYPE driverType = irr::video::EDT_OPENGL;
  irr::IrrlichtDevice * device = irr::createDevice(driverType, irr::core::dimension2d<irr::u32>(1024, 768));
  device->setResizable(true);
  irr::video::IVideoDriver* driver = device->getVideoDriver();
  irr::gui::IGUIEnvironment *gui = device->getGUIEnvironment();
  irr::video::ITexture* tex;
  irr::gui::IGUIImage* img;
  img = gui->addImage(irr::core::rect<irr::s32>(0, 0, 1024,768));
  if (device == 0)
    {
      std::cerr << "device filed to charge" << std::endl;
      return 1;
    }
  while (device->run() && driver)
    {
      sleep(2);
      while (++i <= 4)
	{
	  tex = driver->getTexture(tab[i]);
	  img = gui->addImage(irr::core::rect<irr::s32>(0, 0, 1024,768));
	  img->setImage(tex);
	  img->setScaleImage(true);
	  driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
	  gui->drawAll();
	  driver->removeTexture(tex);
	  driver->endScene();
	  sleep(2);
	}
      device->closeDevice();
    }
  device->drop();
  return 0;
}
