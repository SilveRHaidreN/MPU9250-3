/******************************************************************************
 These are the base functions for the MPU9250

 Copyright © 2019 eneus (http://eneus.gitub.io/)

 Feel free to do whatever you like with this code.

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 ******************************************************************************/


#include "../../MPU9250.c"

int file;

int main(int argc, const char * argv[]) {
	
  	printf ("Device is %d .\n", whoAmI(MPU9250_ADDRESS, WHO_AM_I));
  	printf ("Device is %d .\n", whoAmIAK8963());
	if (detectIMU()) {
		int init = initIMU();
		if (init < 0) {
			printf ("Init code: %d \n", init);
			printf ("ERROR \n");
			goto Exit;
		} else {
			printf ("Init code: %d \n", init);
			goto loop;
		}
	}
    
	loop:
	while(1){
		readSensor();
		printf("Accelerometer X (%d); \nAccelerometer Y (%d); \nAccelerometer Z (%d); \n\n\n", _axcounts, _aycounts, _azcounts);
		printf("Gyroscope X (%d); \nGyroscope Y (%d); \nGyroscope Z (%d); \n\n\n", _gxcounts, _gycounts, _gzcounts);
		printf("Magnetometer X (%d); \nMagnetometer Y (%d); \nMagnetometer Z (%d); \n\n\n", _hxcounts, _hycounts, _hzcounts);
		printf("Temperature C (%d); \n\n\n _____________________\n", _tcounts / 100);
		//Sleep for 0.25ms
		usleep(25000);
		
	}

	Exit:
	return 0;

}
