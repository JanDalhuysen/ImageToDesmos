#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	string filename;

	// cout << "Please enter the name of the file that you want to convert" << endl;
	// cout << "Remember to add the file extension to the name, for example: test.png or example.jpg" << endl;
	// cin >> filename;

	filename = argv[1];

	// system("cmake . -G \"MinGW Makefiles\"");
	system("cmake .");

	// system("mingw32-make");
	system("make");

	// system(("opencv.exe " + filename).c_str());
	system(("./opencv " + filename).c_str());

	system("convert outlines.png pnmoutlines.pnm");

	system("potrace pnmoutlines.pnm -s -o output.svg");

	system("java -jar svgeq-release.jar output.svg --transform=\"rotate(180) scale(-1,1) scale(0.0025) translate(-2400,-1600)\"");

	string output_filename;
	output_filename = filename + ".html";
	ofstream file;
	file.open(output_filename);
	file.close();

	fstream svgfile;

	fstream index;

	index.open(output_filename);

	index << "<script src=\"https://www.desmos.com/api/v1.3/calculator.js?apiKey=dcb31709b452b1cf9dc26972add0fda6\"></script>" << endl;
	index << "<html lang='en'>" << endl;
	index << "<head>" << endl;
	index << "<title>Desmos | Graphing Calculator</title>" << endl;
	index << "<link rel='icon' href='calc_thumb.png'>" << endl;
	index << "</head>" << endl;
	index << "<div id=\"calculator\" style=\"width: 100%; height: 100%;\"></div>" << endl;
	index << "<script>" << endl;
	index << "var options = {" << endl;
	index << "showXAxis: \"false\"," << endl;
	index << "showYAxis: \"false\"," << endl;
	index << "};" << endl;
	index << "var elt = document.getElementById('calculator');" << endl;
	index << "var calculator = Desmos.GraphingCalculator(elt, options);" << endl;

	svgfile.open("output-output.txt", ios::in);
	if (svgfile.is_open())
	{
		string tp;
		while (getline(svgfile, tp))
		{
			index << "calculator.setExpression({ latex: '" + tp + "', color: '#2464b4' });" << endl;
		}
		svgfile.close();
	}
	index << "</script>" << endl;
	index << "</html>" << endl;

	index.close();

	system((output_filename).c_str());
}
