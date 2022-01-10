#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main()
{
	// Set the webcam for camera input
	VideoCapture cap (0);
	Mat img;
	// Variable for cascade classifier
	CascadeClassifier faceCascade;

	// loading the XML file
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	vector <Rect> faces; // vector to store rectangle aroud faces


	while (true)
	{
		cap.read(img);

		// (image, storing_vector, scale_factor, minimum_neighbours)
		faceCascade.detectMultiScale(img, faces, 1.1, 10); // detecting faces

		// drawing rectangles around faces
		for (size_t i = 0; i < faces.size(); i++)
		{
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 2);
		}

		imshow("Detecting Faces", img); // name of the window, img

		waitKey(1); // wait for few milliseconds
	}

}