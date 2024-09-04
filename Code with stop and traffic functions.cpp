Psuedocode

//include statements to be added later
//Using OpenCV cascade classifiers for stop sign and traffic light detection, developed by Paul Viola and Michael Jones.


#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>


using namespace std;
using namespace cv;

CascadeClassifier stopSign_cascade;
CascadeClassifier trafficLight_cascade;

int main(){

    //Pretty basic proto code, not focusing on specific syntax, just general functionality.
   
    VideoCapture captureFunction();
    if(!captureFunction.isOpen()){
        std::cerr << "Error text stating camera could not be opened";
        return -1;
    }

    if(!stopSign_Cascade.load("stop_sign.xml")){
        cout << "Could not load stop sign cascade file." << endl;
        return -1;
    }

    CommandLineParser parser(argc, argv,
                                /*path to .xml files*/);
    
    String stopSign_cascade_name = directory::findFile(parser.get<String>("stopSign_cascade"));
    String eyes_cascade_name = directory::findFile(parser.get<String>("trafficLight_cascade"));

    Mat img;
    while (captureFunction.read(img)){
        if (img.empty()){
            break;
        }

    detectStopSign(img);
    //After detection, draw boxes around detected stop signs.
    for(size_t i = 0; i < stopSigns.size(); i++){
        rectangle(img, stopSigns[i], Scalar(0, 0, 255), 2);
        putText(img, "Stop Sign", Point(stopSigns[i].x, stopSigns[i].y - 15), FONT_ITALIC, 1.0, Scalar(0,0,255), 2);
    }

    detectTrafficLight(img);
    for(size_t i = 0; i < trafficLight.size(); i++){
        rectangle(img, trafficLight[i], Scalar(0, 0, 255), 2);
        putText(img, "Stop Sign", Point(trafficLight[i].x, trafficLight[i].y - 15), FONT_ITALIC, 1.0, Scalar(0,0,255), 2);
    }

    }

    cap.release();
    destroyAllWindows();
    
    return 0;
}

void detectStopSign(Mat img){
    //This function detects stop signs
    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    equalizeHist(img_gray, img_gray);

    std::vector<Rect> stopSign;
    stopSign_cascade.detectMultiScale(img_gray, stopSign);

    for(size_t = 0; i < stopSign.size(); i++){
        Point sign_center();

    }

    imshow("Stop sign detection", img);
}

void detectTrafficLight(Mat &img, CascadeClassifier &trafficLightCascade){
    //This function detects traffic lights
    vector<Rect> trafficLight;
    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    equalizeHist(img_gray, img_gray);

    trafficLightCascade.detectMultiScale(img_gray, trafficLight, 1.0, 3, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
    for(size_t i = 0; i < trafficLight.size(); i++){
        rectangle(img, trafficLight[i], Scalar(0, 255, 0), 2);
        putText(img, "Traffic Light", Point(trafficLight[i].x, trafficLight[i].y - 15), FONT_ITALIC, 1.0, Scalar(0, 255, 0), 2);

    }
}