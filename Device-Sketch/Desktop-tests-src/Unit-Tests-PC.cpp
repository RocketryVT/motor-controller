/**
 * Contains "main()" method to run Unit Tests on Desktop computer
 * In order to compile on a Windows Desktop, create a Visual Studio
 * Project and link all the folders in the "Device-Sketch" folder,
 * then, only have "stdafx.h" and "stdafx.cpp" in the Visual Studio
 * folder.
 */

#include "stdafx.h"
#include "Assert.h"
#include "Test_all.h"
#include "Arduino.h"

int main()
{
	run_tests(0);
	print(Test::resstr);
    return 0;
}

