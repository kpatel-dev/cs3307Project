#ifndef FILELOAD_H_
#define FILELOAD_H_

#include "FileLoader.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

 /**
   * @brief File loader class
   * 
   * Loads in all functions possible as long as already has not been defined
   * @author Fahreen Bushra
   * @date November 27, 2019
   */
class FileLoader{

//Constructors and destructors
public:
	FileLoader();
	FileLoader(std:: string fileName,  char type);
	~FileLoader();
};
#endif
