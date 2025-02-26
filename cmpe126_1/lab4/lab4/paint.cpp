#include <iostream>
using namespace std;

void print(int temp[20][20]);
void defaultPatternReset(int temp[20][20]);
void customPatternReset(int temp[20][20]);				//optional
void fillOne(int temp[20][20], int x, int y);
void fillZero(int temp[20][20], int x, int y);

void fillOne(int temp[20][20], int x, int y){
	//insert recursion code here to fill spaces of '0' with '1'
    if (temp[x][y]==0 && x > -1&& x <20&& y > -1&& y <20) {
        temp[x][y]=1;
        fillOne(temp, x-1, y);
        fillOne(temp, x+1, y);
        fillOne(temp, x, y-1);
        fillOne(temp, x, y+1);
        }
}

void fillZero(int temp[20][20], int x, int y){
	//insert recursion code here to fill spaces of '1' with '0'
    if (temp[x][y]==1 && x > -1&& x <20&& y > -1&& y <20) {
        temp[x][y]=0;
        fillZero(temp, x-1, y);
        fillZero(temp, x+1, y);
        fillZero(temp, x, y-1);
        fillZero(temp, x, y+1);
    }
}

void customPatternReset(int temp[20][20]){
	//optional
}

int main() {
	int screen[20][20] = { 0 };
	defaultPatternReset(screen);
	cout << "Initial conditions:" << endl;
	print(screen);
	while(true){
		int choice = -1, x = -1, y = -1;
        
        
        
		cout << "\nChoose one of the following options:" << endl;
		cout << "1) Fill 1 at/from a specified point." << endl;
		cout << "2) Fill 0 at/from a specified point." << endl;
		cout << "3) Reset to the default pattern." << endl;
		cout << "4) Reset to a custom pattern (optional)." << endl;
		cout << "5) Exit." << endl;
		cout << "\nYour choice: ";
		cin >> choice;
		if(choice == 5)
			break;
		else if(choice == 1 || choice == 2){
			cout << "X value: ";
			cin >> x;
			cout << "Y value: ";
			cin >> y;
			if(x > -1 && x < 20 && y > -1 && y < 20)
				choice == 1 ? fillOne(screen, x, y) : fillZero(screen, x, y);
			else{
				cout << "Error: This position is out of bounds." << endl;
				continue;
			}
		}
		else if(choice == 3)
			defaultPatternReset(screen);
		else if(choice == 4)
			customPatternReset(screen);
		if(choice > 0 && choice < 5)
			print(screen);
		else
			cout << "Invalid selection." << endl;
	}
	return 0;
}

void print(int temp[20][20]){
	cout << "\n    ";
	for(int i = 0; i < 20; i++)
		cout << i%10;
	cout << endl;
	for(int y = 0; y < 20; y++){
		cout << "\n" << y%10 << "   ";
		for(int x = 0; x < 20; x++)
			cout << temp[x][y];
	}
	cout << endl;
}

void defaultPatternReset(int temp[20][20]){
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			temp[i][j] = 0;
	for(int i = 0; i < 20; i++){
		temp[i][i] = 1;
		temp[i][19-i] = 1;
	}
	for(int i = 0; i < 2; i++){
		temp[i+9][7] = 1;
		temp[i+9][12] = 1;
		temp[7][i+9] = 1;
		temp[12][i+9] = 1;
	}
}
