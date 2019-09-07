#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;


const char* keys = "{ video  | | Path to the input video file. Skip this argument to capture frames from a camera.}";


int main(int argc, char** argv){
  // Parse command line arguments
  CommandLineParser parser(argc,argv,keys);

  // Create a VideoCapture object and open the input file
  VideoCapture cap;
  if (parser.has("video")){
    cap.open(parser.get<String>("video"));
  }
  else
      cap.open(0);

  // Check if camera opened successfully
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }

  while(1) {
      cap >> frame;
      //convert to hsv
      Mat hsv_img;
      cvtColor(frame, hsv_img, COLOR_BGR2GRAY);
      cvtColor(hsv_img, hsv_img, COLOR_BGR2HSV);

      if (waitKey(10) == 27) {
          cout << " >> done Extract Color" << endl;
          break;
      }
  }
  // When everything done, release the video capture object
  cap.release();

  // Closes all the frames
  destroyAllWindows();

  return 0;
}
