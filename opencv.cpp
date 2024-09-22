#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;

using namespace cv;

int main(int argc, char **argv)
{
	string filename;

	filename = argv[1];

	Mat img = imread(filename);

	Mat out;

	Canny(img, out, 30, 90);

	imwrite("outlines.png", out);
}
