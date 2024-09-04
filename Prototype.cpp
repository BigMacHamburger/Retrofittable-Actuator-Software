Psuedocode

//include statements to be added later
CascadeClassifier stopSign_cascade;
CascadeClassifier trafficLight_cascade;

int main(){

    //Pretty basic proto code, not focusing on specific syntax, just general functionality.
    //Using OpenCV cascade classifiers for stop sign and traffic light detection, developed by Paul Viola and Michael Jones.

    VideoCapture captureFunction();
    if(!captureFunction.isOpen()){
        std::cerr << "Error text stating camera could not be opened";
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

    detect(img);

    }
    return 0;
}

void detect(Mat img){
    Mat img_gray;
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    equalizeHist(img_gray, img_gray);

    std::vector<Rect> stopSign;
    stopSign_cascade.detectMultiScale(img_gray, stopSign);

    for(size_t = 0; i < stopSign.size(); i++){
        
    }
}