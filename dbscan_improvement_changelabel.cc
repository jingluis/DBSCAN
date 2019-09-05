#include <iostream>
#include <fstream> 
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <chrono>
#include <string>
using namespace std;

const int UNDEFINED = -1;
const int NOISE = -2;

struct Point{
	float x;
	float y;
	int index;
	int label;
	Point(float xx, float yy, int ii, int ll = UNDEFINED){
		x = xx;
		y = yy;
		index = ii;
		label = ll;
	}
};


vector <Point> points;
float eps;
int minpts;
int C = 0;
float eps2;
vector <string> colors;
string inputfile;
string outputfile;


bool check_distance(Point p1, Point p2){
	return ((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y)) <= eps2;
}

bool cmp(Point a, Point b){
	if(a.label < b.label) return true;
	else if(b.label < a.label) return false;
	return (a.x*a.x + a.y*a.y) <= (b.x*b.x + b.y*b.y);
}

//if b, we find all the neighbours except from the point itself that fits with the condition
void RangeQuery(Point p, vector <Point>& res, bool b){
	res.clear();
	if(b){
		for(int i = 0; i < points.size(); ++i){
			if(not(points[i].x == p.x and points[i].y == p.y) and check_distance(p,points[i])) res.push_back(points[i]);
		}
	}
	else{
		for(int i = 0; i < points.size(); ++i){
			if(check_distance(p,points[i])) res.push_back(points[i]);
		}
	}
}

void union_vector(vector <Point>& s, const vector <Point>& N){
	int n = s.size();
	//coste : n*m no me gusta
	for(int i = 0; i < N.size(); ++i){
		bool found = false;
		for(int j = 0; j < n; ++j){
			if(N[i].x == s[j].x and N[i].y == s[j].y) found = true;
		}
		if(not found) s.push_back(N[i]);		
	}
}

void DBSCAN(){
	for(int i = 0; i < points.size(); ++i){
		if(points[i].label != UNDEFINED) continue;
		vector <Point> Neighbours;
		RangeQuery(points[i], Neighbours, true);
		if(Neighbours.size() + 1 < minpts){
			points[i].label = NOISE;
			continue;
		}
		++C;
		points[i].label = C - 1;
		vector <Point> S = Neighbours;
		int n = S.size();
		for(int j = 0; j < n; ++j){
			if(S[j].label == NOISE){
				S[j].label = C - 1;
				points[S[j].index].label = C - 1;	
			}
			if(S[j].label != UNDEFINED) continue;
			S[j].label = C - 1;
			points[S[j].index].label = C - 1;
			RangeQuery(S[j], Neighbours, false);
			if(Neighbours.size() >= minpts){
				union_vector(S, Neighbours);
				n = S.size();
			}
		}
	}
}

void put_colors(){
	colors[0] = "black";
	colors[1] = "dark-grey";
	colors[2] = "red";
	colors[3] = "web-green";
	colors[4] = "web-blue";
	colors[5] = "dark-magenta";
	colors[6] = "dark-cyan";
	colors[7] = "dark-orange";
	colors[8] = "dark-yellow";
	colors[9] = "royalblue";
	colors[10] = "goldenrod";
	colors[11] = "dark-spring-green";
	colors[12] = "purple";
	colors[13] = "steelblue";
	colors[14] = "dark-red";
	colors[15] = "dark-chartreuse";
	colors[16] = "orchid";
	colors[17] = "aquamarine";
	colors[18] = "brown";
	colors[19] = "yellow";
	colors[20] = "turquoise";
	colors[21] = "grey";
	colors[22] = "grey80";
	colors[23] = "grey90";
	colors[24] = "grey100";
	colors[25] = "light-red";
	colors[26] = "light-green";
	colors[27] = "light-blue";
	colors[28] = "light-magenta";
	colors[29] = "light-cyan";
	colors[30] = "light-goldenrod";
	colors[31] = "light-pink";
	colors[32] = "light-turquoise";
	colors[33] = "gold";
	colors[34] = "green";
	colors[35] = "dark-green";
	colors[36] = "spring-green";
	colors[37] = "forest-green";
	colors[38] = "sea-green";
	colors[39] = "blue";
	colors[40] = "dark-blue";
	colors[41] = "midnight-blue";
	colors[42] = "navy";
	colors[43] = "medium-blue";
	colors[44] = "skyblue";
	colors[45] = "cyan";
	colors[46] = "magenta";
	colors[47] = "dark-turquoise";
	colors[48] = "dark-pink";
	colors[49] = "coral";
	colors[50] = "light-coral";
	colors[51] = "orange-red";
	colors[52] = "salmon";
	colors[53] = "dark-salmon";
	colors[54] = "khaki";
	colors[55] = "dark-khaki";
	colors[56] = "dark-goldenrod";
	colors[57] = "beige";
	colors[58] = "olive";
	colors[59] = "orange";
	colors[60] = "violet";
	colors[61] = "dark-violet";
	colors[62] = "plum";
	colors[63] = "dark-plum";
	colors[64] = "dark-olivegreen";
	colors[65] = "orangered4";
	colors[66] = "brown4";
	colors[67] = "sienna4";
	colors[68] = "orchid4";
	colors[69] = "mediumpurple3";
	colors[70] = "slateblue1";
	colors[71] = "yellow4";
	colors[72] = "sienna1";
	colors[73] = "tan1";
	colors[74] = "sandybrown";
	colors[75] = "light-salmon";
	colors[76] = "pink";
	colors[77] = "khaki1";
	colors[78] = "lemonchiffon";
	colors[79] = "bisque";
	colors[80] = "honeydew";
	colors[81] = "slategrey";
	colors[82] = "seagreen";
	colors[83] = "antiquewhite";
	colors[84] = "chartreuse";
	colors[85] = "greenyellow";
	colors[86] = "gray";
	colors[87] = "light-gray";
	colors[88] = "light-grey";
	colors[89] = "dark-gray";
	colors[90] = "slategray";

}

void read(){
	float x, y;
	int i = 0;
	ifstream infile;
	string file = "data/" + inputfile; 
	infile.open(file);
	while(infile >> x >> y ) points.push_back(Point(x,y,i++));
	
}

void write(){
	sort(points.begin(), points.end(), cmp);
	ofstream output (outputfile);
	int soroll = 0;
	vector <int> mida;
	if(points[points.size()-1].label >= 0){
		mida = vector <int> (points[points.size()-1].label + 1, 0);
		for(auto w : points) {
			output << w.x << " " << w.y << " " << w.label << endl;
			if(w.label == -2) ++soroll;
			else mida[w.label] ++;
		}
	}
	else soroll = points.size();
	cout << "Total dataset points: " << points.size() << endl;
	cout << "Epsilon: " << eps << endl;
	cout << "Minimum points: " << minpts << endl;
	cout << "Total clusters: " << C << endl;
	cout << "---------------------------" << endl;
	if(soroll != 0) cerr << "noise points: " << soroll << endl;
	if(points[points.size()-1].label >= 0){
		for(int i = 0; i < mida.size(); ++i) cerr << "cluster " << i << " size: " << mida[i] << endl;
	}
	ofstream outfile ("result.plt");
	
	outfile << "set xlabel \"x\"" << endl << "set ylabel \"y\"" << endl
			<< "set title \"DBSCAN Clustering\"" << endl << "set key outside " << endl << "set pointsize 1.5" << endl
			<< "plot \"" << outputfile << "\" using 1:(strcol(3) eq \"-2\"?$2:1/0) with points pt 2 lt rgb \"" 
			<< colors[0] << "\" title \"NOISE\", \\" << endl;
	for(int i = 1; i <= mida.size(); ++i){
		outfile << "\"\"using 1:(strcol(3) eq \"" << i-1 << "\"?$2:1/0) with points pt 7 lt rgb \"" 
				<< colors[i] << "\" title \"cluster " << i - 1 << "\"";
		if(i != mida.size()) outfile << ", \\";
		outfile << endl;
	}
	
	system("gnuplot -persistent result.plt");
}

int main(int argc, const char * argv[]){

	if(argc != 4){
		cerr << "You need to put epsilon,minimum point value, input dataset correctly" << endl;
		return 0;
	}
	colors = vector <string> (91);
	put_colors();
	eps = stof(argv[1]);
	minpts = stof(argv[2]);
	eps2 = eps * eps;
	outputfile = "res.out";
	inputfile = string(argv[3]);
	read();
	auto start = chrono::steady_clock::now();	
	DBSCAN();
	auto end = chrono::steady_clock::now();
	write();
	cout << "Elapsed time in milliseconds : " 
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;
} 