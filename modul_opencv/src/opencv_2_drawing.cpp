// C++ program to demonstrate rectangle 
// over a self-formed background image 

#include <iostream> 
#include <opencv2/core/core.hpp> 

// Drawing shapes 
#include <opencv2/imgproc.hpp> 

#include <opencv2/highgui/highgui.hpp> 
using namespace cv; 
using namespace std; 

// Driver Code 
int main(int argc, char** argv) 
{ 
	// Creating a blank image with 
	// white background 
	Mat image(500, 500, CV_8UC3, 
			Scalar(255, 255, 255)); 

	// Check if the image is created 
	// successfully or not 
	if (!image.data) { 
		std::cout << "Could not open or "
				<< "find the image\n"; 

		return 0; 
	} 

	// Top Left Corner 
	Point p1(30, 30); 

	// Bottom Right Corner 
	Point p2(255, 255); 

	int thickness = 2; //ketebalan

	// Drawing the Rectangle 
	rectangle(image, p1, p2, 
			Scalar(255, 0, 0), 
			thickness, LINE_8); 

	// Show our image inside a window 
	imshow("Output", image); 
	waitKey(0); 

	return 0; 
} 
